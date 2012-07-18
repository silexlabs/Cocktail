/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layer;

import cocktail.core.dom.Document;
import cocktail.core.dom.Node;
import cocktail.core.dom.NodeBase;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.ScrollBar;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.style.StyleData;
import cocktail.core.geom.Matrix;
import cocktail.port.DrawingManager;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import haxe.Log;

/**
 * Each ElementRenderer belongs to a LayerRenderer representing
 * its position in the document in the z axis. LayerRenderer
 * are instantiated by ElementRenderer establishing new stacking
 * context
 * 
 * The created LayerRenderers form the LayerRenderer tree,
 * paralleling the rendering tree, although not all ElementRenderers
 * create their own LayerRenderer, in most cases they use the one of
 * their parent. Wether an ElementRenderer creates a new LayerRenderer
 * is determined by its createNewStackingContext() method.
 * 
 * For instance, positioned elements create new layers in most cases as
 * they are likely to be displayed on top of other elements
 * 
 * LayerRenderer are also responsible of hit testing and can return 
 * the top ElementRenderer at a given coordinate
 * 
 * @author Yannick DOMINGUEZ
 */
class LayerRenderer extends NodeBase<LayerRenderer>
{
	/**
	 * A reference to the ElementRenderer which
	 * created the LayerRenderer
	 */
	public var rootElementRenderer(default, null):ElementRenderer;
	
	/**
	 * Holds a reference to all of the children of the root ElementRenderer
	 * which also create which have a z-index computed value of 0 or auto,
	 * which means that they are rendered in tree
	 * order of the DOM tree. Also, children with a z-index of 'auto' don't actually
	 * create new LayerRenderer, although they are rendered as if they did.
	 * 
	 * That's why this array stores ElementRenderer instead of LayerRenderer, as some
	 * of the ElementRenderer don't actually have their own LayerRenderer
	 */
	private var _zeroAndAutoZIndexChildElementRenderers:Array<ElementRenderer>;
	
	/**
	 * Holds a reference to all of the child LayerRenderer which have a computed z-index
	 * superior to 0. They are ordered in this array from least positive to most positive,
	 * which is the order which they must use to be renderered
	 */
	private var _positiveZIndexChildLayerRenderers:Array<LayerRenderer>;
	
	/**
	 * same as above for child LayerRenderer with a negative computed z-index. The array is
	 * ordered form most negative to least negative
	 */
	private var _negativeZIndexChildLayerRenderers:Array<LayerRenderer>;
	
	/**
	 * The graphics context onto which all the ElementRenderers
	 * belonging to this LayerRenderer are painted onto
	 */
	private var _graphicsContext:DrawingManager;
	
	/**
	 * class constructor. init class attributes
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super();
		
		this.rootElementRenderer = rootElementRenderer;
		
		_zeroAndAutoZIndexChildElementRenderers = new Array<ElementRenderer>();
		_positiveZIndexChildLayerRenderers = new Array<LayerRenderer>();
		_negativeZIndexChildLayerRenderers = new Array<LayerRenderer>();
		
		_graphicsContext = new DrawingManager(2000, 1500);
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Overriden as when a child LayerRenderer is added
	 * to this LayerRenderer, this LayerRenderer stores its
	 * child LayerRenderer or its root ElementRenderer in one of its child element
	 * renderer array based on its z-index style
	 */ 
	override public function appendChild(newChild:LayerRenderer):LayerRenderer
	{
		super.appendChild(newChild);

		//check the computed z-index of the ElementRenderer which
		//instantiated the child LayerRenderer
		switch(newChild.rootElementRenderer.coreStyle.computedStyle.zIndex)
		{
			case ZIndex.cssAuto:
				//the z-index is 'auto'
				_zeroAndAutoZIndexChildElementRenderers.push(newChild.rootElementRenderer);
				
			case ZIndex.integer(value):
				if (value == 0)
				{
					_zeroAndAutoZIndexChildElementRenderers.push(newChild.rootElementRenderer);
				}
				else if (value > 0)
				{
					insertPositiveZIndexChildRenderer(newChild, value);
				}
				else if (value < 0)
				{
					insertNegativeZIndexChildRenderer(newChild, value);
				}
		}
		
		return newChild;
	}
	
	/**
	 * When removing a child LayerRenderer from the LayerRenderer
	 * tree, its reference must also be removed from the right
	 * child LayerRenderer array
	 */
	override public function removeChild(oldChild:LayerRenderer):LayerRenderer
	{
		var removed:Bool = false;
		
		//try each of the array, stop if an element was actually removed from them
		removed = _zeroAndAutoZIndexChildElementRenderers.remove(oldChild.rootElementRenderer);
		
		if (removed == false)
		{
			removed = _positiveZIndexChildLayerRenderers.remove(oldChild);
			
			if (removed == false)
			{
				 _negativeZIndexChildLayerRenderers.remove(oldChild);
			}
		}
		
		super.removeChild(oldChild);
	
		return oldChild;
	}
	
	/////////////////////////////////
	// PUBLIC RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Starts the rendering of this LayerRenderer.
	 * Render all its child layers and its root ElementRenderer
	 * 
	 * @param	parentGraphicsContext the graphics context of the parent
	 * LayerRenderer onto which the graphics context of this LayerRenderer
	 * is painted
	 */
	public function render(parentGraphicsContext:DrawingManager):Void
	{
		//reset the bitmap
		_graphicsContext.clear();
		
		//render first negative z-index child LayerRenderer from most
		//negative to least negative
		for (i in 0..._negativeZIndexChildLayerRenderers.length)
		{
			_negativeZIndexChildLayerRenderers[i].render(_graphicsContext);
		}
		
		//render the rootElementRenderer itself which will also
		//render all ElementRenderer belonging to this LayerRenderer
		rootElementRenderer.render(_graphicsContext);
		
		//render zero and auto z-index ElementRenderer
		for (i in 0..._zeroAndAutoZIndexChildElementRenderers.length)
		{
			//must check if the ElementRenderer establish a new stacking context (create a new layer)
			//as if it does not, it is the ElementRenderer which must be rendered, not its LayerRenderer
			//which was already renderered
			//
			//this applies for instance to ElementRenderer with a z-index of auto
			if (_zeroAndAutoZIndexChildElementRenderers[i].establishesNewStackingContext() == true)
			{
				_zeroAndAutoZIndexChildElementRenderers[i].layerRenderer.render(_graphicsContext);
			}
			else
			{
				_zeroAndAutoZIndexChildElementRenderers[i].render(_graphicsContext);
			}
		}
		
		//render all the positive LayerRenderer from least positive to 
		//most positive
		for (i in 0..._positiveZIndexChildLayerRenderers.length)
		{
			_positiveZIndexChildLayerRenderers[i].render(_graphicsContext);
		}
		
		//paint the LayerRenderer's graphics context onto its parent's
		parentGraphicsContext.copyPixels(_graphicsContext.nativeBitmapData, { x:0.0, y:0.0, width:2000.0, height:1500.0 }, { x:0.0, y:0.0 } );
	}
	
	/////////////////////////////////
	// PUBLIC LAYER TREE METHODS
	////////////////////////////////
	
	/**
	 * Utils method used by ElementRenderer to register themselves when they have a z-index of
	 * 'auto'. Stores them in the zero and auto child root ElementRenderer array.
	 * As those ElementRenderer don't create LayerRenderer for themselves, they are not registered
	 * when their LayerRenderer is appended to is parent
	 */
	public function insertAutoZIndexChildElementRenderer(elementRenderer:ElementRenderer):Void
	{
		_zeroAndAutoZIndexChildElementRenderers.push(elementRenderer);
	}
	
	/**
	 * Utils method to unregister ElementRenderer with a z-index of 'auto'
	 */ 
	public function removeAutoZIndexChildElementRenderer(elementRenderer:ElementRenderer):Void
	{
		_zeroAndAutoZIndexChildElementRenderers.remove(elementRenderer);
	}
	
	/////////////////////////////////
	// PRIVATE LAYER TREE METHODS
	////////////////////////////////
	
	/**
	 * When inserting a new child LayerRenderer in the positive z-index
	 * child LayerRenderer array, it must be inserted at the right index so that
	 * the array is ordered from least positive to most positive
	 */
	private function insertPositiveZIndexChildRenderer(childLayerRenderer:LayerRenderer, rootElementRendererZIndex:Int):Void
	{
		//the array of positive child LayerRenderer will be reconstructed
		var newPositiveZIndexChildRenderers:Array<LayerRenderer> = new Array<LayerRenderer>();
		
		//flag checking if the LayerRenderer was already inserted
		//in the array
		var isInserted:Bool = false;
		
		//loop in all the positive z-index array
		var length:Int = _positiveZIndexChildLayerRenderers.length;
		for (i in 0...length)
		{
			//get the z-index of the child LayerRenderer at the current index
			var currentRendererZIndex:Int = 0;
			switch( _positiveZIndexChildLayerRenderers[i].rootElementRenderer.coreStyle.computedStyle.zIndex)
			{
				case ZIndex.integer(value):
					currentRendererZIndex = value;
					
				default:	
			}
			
			//if the new LayerRenderer has a least positive z-index than the current
			//child it is inserted at this index
			//also check that it is only inserted the first time this happens, else it will be
			//inserted at each subsequent index
			if (rootElementRendererZIndex < currentRendererZIndex && isInserted == false)
			{
				newPositiveZIndexChildRenderers.push(childLayerRenderer);
				isInserted = true;

			}
			
			//push the current child in the new array
			newPositiveZIndexChildRenderers.push(_positiveZIndexChildLayerRenderers[i]);
			
		}
		
		//if the new LayerRenderer wasn't inserted, either
		//it is the first item in the array or it has the most positive
		//z-index
		if (isInserted == false)
		{
			newPositiveZIndexChildRenderers.push(childLayerRenderer);
		}
		
		//replace the current array with the new one
		_positiveZIndexChildLayerRenderers = newPositiveZIndexChildRenderers;

	}
	
	/**
	 * Follows the same logic as the method above for the negative z-index child
	 * array. The array must be ordered from most negative to least negative
	 */ 
	private function insertNegativeZIndexChildRenderer(childLayerRenderer:LayerRenderer, rootElementRendererZIndex:Int):Void
	{
		var newNegativeZIndexChildRenderers:Array<LayerRenderer> = new Array<LayerRenderer>();

		var isInserted:Bool = false;
		
		var length:Int = _negativeZIndexChildLayerRenderers.length;
		for (i in 0...length)
		{
			var currentRendererZIndex:Int = 0;
			
			switch(_negativeZIndexChildLayerRenderers[i].rootElementRenderer.coreStyle.computedStyle.zIndex)
			{
				case ZIndex.integer(value):
					currentRendererZIndex = value;
					
				default:	
			}
			
			if (currentRendererZIndex  > rootElementRendererZIndex && isInserted == false)
			{
				newNegativeZIndexChildRenderers.push(childLayerRenderer);
				isInserted = true;
			}
			
			newNegativeZIndexChildRenderers.push(_negativeZIndexChildLayerRenderers[i]);
		}
		
		if (isInserted == false)
		{
			newNegativeZIndexChildRenderers.push(childLayerRenderer);
		}
		
		_negativeZIndexChildLayerRenderers = newNegativeZIndexChildRenderers;
		
	}
	

	/////////////////////////////////
	// PUBLIC HIT-TESTING METHODS
	////////////////////////////////
	
	//TODO 2 : for now traverse all tree, but should instead return as soon as an ElementRenderer
	//is found
	public function getTopMostElementRendererAtPoint(point:PointData, scrollX:Float, scrollY:Float):ElementRenderer
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = getElementRenderersAtPoint(point, scrollX, scrollY);
		
		var topMostElementRenderer:ElementRenderer = elementRenderersAtPoint[elementRenderersAtPoint.length - 1];
		
		return topMostElementRenderer;
	}
	
	private function getElementRenderersAtPoint(point:PointData, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = getElementRenderersAtPointInLayer(rootElementRenderer, point, scrollX, scrollY);

		if (rootElementRenderer.hasChildNodes() == true)
		{
			var childRenderers:Array<ElementRenderer> = getChildRenderers();
			
			var elementRenderersAtPointInChildRenderers:Array<ElementRenderer> = getElementRenderersAtPointInChildRenderers(point, childRenderers, scrollX, scrollY);
			var length:Int = elementRenderersAtPointInChildRenderers.length;
			for (i in 0...length)
			{
				elementRenderersAtPoint.push(elementRenderersAtPointInChildRenderers[i]);
			}
		}
	
		return elementRenderersAtPoint;
	}
	
	/////////////////////////////////
	// PRIVATE HIT-TESTING METHODS
	////////////////////////////////
	
	private function getElementRenderersAtPointInLayer(renderer:ElementRenderer, point:PointData, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPointInLayer:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		var scrolledPoint:PointData = {
			x:point.x + scrollX,
			y:point.y + scrollY
		}
		
		if (isWithinBounds(scrolledPoint, renderer.globalBounds) == true)
		{
			elementRenderersAtPointInLayer.push(renderer);
		}
		
		scrollX += renderer.scrollLeft;
		scrollY += renderer.scrollTop;
		
		
		var length:Int = renderer.childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = renderer.childNodes[i];
			
			if (child.layerRenderer == this)
			{
				if (child.hasChildNodes() == true)
				{
					
					var childElementRenderersAtPointInLayer:Array<ElementRenderer> = getElementRenderersAtPointInLayer(child, point, scrollX, scrollY);
					var childLength:Int = childElementRenderersAtPointInLayer.length;
					for (j in 0...childLength)
					{
						elementRenderersAtPointInLayer.push(childElementRenderersAtPointInLayer[j]);
					}
				}
				else
				{
					var scrolledPoint:PointData = {
						x:point.x + scrollX,
						y:point.y + scrollY
					}
					
					if (isWithinBounds(scrolledPoint, child.globalBounds) == true)
					{
						elementRenderersAtPointInLayer.push(child);
					}
				}
			}
		}
		
		return elementRenderersAtPointInLayer;
	}
	
	private function getElementRenderersAtPointInChildRenderers(point:PointData, childRenderers:Array<ElementRenderer>, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPointInChildRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		var length:Int = childRenderers.length;
		for (i in 0...length)
		{
			
			var elementRenderersAtPointInChildRenderer:Array<ElementRenderer> = [];
			if (childRenderers[i].establishesNewStackingContext() == true)
			{
				//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
				if (childRenderers[i].isScrollBar() == true)
				{
					elementRenderersAtPointInChildRenderer = childRenderers[i].layerRenderer.getElementRenderersAtPoint(point, scrollX, scrollY);
				}
				//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
				else if (childRenderers[i].coreStyle.position == fixed)
				{
					elementRenderersAtPointInChildRenderer = childRenderers[i].layerRenderer.getElementRenderersAtPoint(point, scrollX , scrollY);
				}
				else
				{
					elementRenderersAtPointInChildRenderer = childRenderers[i].layerRenderer.getElementRenderersAtPoint(point, scrollX + rootElementRenderer.scrollLeft, scrollY + rootElementRenderer.scrollTop);
				}
			}
		
			var childLength:Int = elementRenderersAtPointInChildRenderer.length;
			for (j in 0...childLength)
			{
				elementRenderersAtPointInChildRenderers.push(elementRenderersAtPointInChildRenderer[j]);
			}
		}
		
		
		return elementRenderersAtPointInChildRenderers;
	}
	
	/**
	 * Utils method determining if a given point is within
	 * a given recrtangle
	 */
	private function isWithinBounds(point:PointData, bounds:RectangleData):Bool
	{
		return point.x >= bounds.x && (point.x <= bounds.x + bounds.width) && point.y >= bounds.y && (point.y <= bounds.y + bounds.height);	
	}
	
	/**
	 * Concatenate all the child element renderers of this
	 * LayerRenderer
	 */
	private function getChildRenderers():Array<ElementRenderer>
	{
		var childRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0..._negativeZIndexChildLayerRenderers.length)
		{
			var childRenderer:LayerRenderer = _negativeZIndexChildLayerRenderers[i];
			childRenderers.push(childRenderer.rootElementRenderer);
		}
		for (i in 0..._zeroAndAutoZIndexChildElementRenderers.length)
		{
			var childRenderer:ElementRenderer = _zeroAndAutoZIndexChildElementRenderers[i];
			childRenderers.push(childRenderer);
		}
		for (i in 0..._positiveZIndexChildLayerRenderers.length)
		{
			var childRenderer:LayerRenderer = _positiveZIndexChildLayerRenderers[i];
			childRenderers.push(childRenderer.rootElementRenderer);
		}
		
		return childRenderers;
	}
}