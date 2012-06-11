/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.ScrollBar;
import cocktail.core.style.StyleData;
import cocktail.core.geom.Matrix;
import cocktail.core.NativeElement;
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
 * The LayerRenderer keeps a reference to each of its ElementRenderer
 * creating themselves stacking context, as they need to be retrieved
 * efficiently
 * 
 * LayerRenderer are also responsible of hit testing and can return 
 * the ElementRenderer at a given coordinate
 * 
 * @author Yannick DOMINGUEZ
 */
class LayerRenderer extends Node
{
	/**
	 * A reference to the ElementRenderer which
	 * created the LayerRenderer
	 */
	private var _rootElementRenderer:ElementRenderer;
	public var rootElementRenderer(get_rootElementRenderer, never):ElementRenderer;
	
	/**
	 * Holds a reference to all of the children of the root ElementRenderer
	 * which also create a new LayerRenderer, and which have a z-index
	 * computed value of 0 or auto, which means that they are rendered in tree
	 * order of the DOM tree. Also, children with a z-index of 'auto' don't actually
	 * create new LayerRenderer, although they are rendered as if they did
	 */
	private var _zeroAndAutoZIndexChildRenderers:Array<ElementRenderer>;
	
	/**
	 * Holds a reference to all of the children of the root ElementRenderer
	 * which also create a new LayerRenderer, and which have a computed z-index
	 * superior to 0. They are ordered in this array from least positive to most positive,
	 * which is the order which they must use to be renderered
	 */
	private var _positiveZIndexChildRenderers:Array<ElementRenderer>;
	
	/**
	 * same as above for children with a negative computed z-index. The array is
	 * ordered form most negative to least negative
	 */
	private var _negativeZIndexChildRenderers:Array<ElementRenderer>;
	
	/**
	 * class constructor. init class attributes
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super();
		
		_rootElementRenderer = rootElementRenderer;
		_zeroAndAutoZIndexChildRenderers = new Array<ElementRenderer>();
		_positiveZIndexChildRenderers = new Array<ElementRenderer>();
		_negativeZIndexChildRenderers = new Array<ElementRenderer>();
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Overriden as when a child LayerRenderer is added
	 * to this LayerRenderer, this LayerRenderer stores its
	 * root ElementRenderer in one of its chile element
	 * renderer array based on its z-index style
	 */ 
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		var childLayer:LayerRenderer = cast(newChild);
		
		//check the computed z-index of the ElementRenderer which
		//instantiated the child LayerRenderer
		switch(childLayer.rootElementRenderer.computedStyle.zIndex)
		{
			case ZIndex.cssAuto:
				//the z-index is 'auto'
				_zeroAndAutoZIndexChildRenderers.push(childLayer.rootElementRenderer);
				
			case ZIndex.integer(value):
				if (value == 0)
				{
					_zeroAndAutoZIndexChildRenderers.push(childLayer.rootElementRenderer);
				}
				else if (value > 0)
				{
					insertPositiveZIndexChildRenderer(childLayer.rootElementRenderer, value);
				}
				else if (value < 0)
				{
					insertNegativeZIndexChildRenderer(childLayer.rootElementRenderer, value);
				}
		}
		
		return newChild;
	}
	
	/**
	 * When removing a child LayerRenderer from the LayerRenderer
	 * tree, th reference of its root ElementRenderer must also
	 * be removed from the right child root ElementRenderer array
	 */
	override public function removeChild(oldChild:Node):Node
	{
		var childLayer:LayerRenderer = cast(oldChild);

		//TODO 2 : shouldn't have ot try in each ? might switch the z-index, but it might
		//have changed which have caused the removal in the first place
		_zeroAndAutoZIndexChildRenderers.remove(childLayer.rootElementRenderer);
		_positiveZIndexChildRenderers.remove(childLayer.rootElementRenderer);
		_negativeZIndexChildRenderers.remove(childLayer.rootElementRenderer);
		
		super.removeChild(oldChild);
	
		return oldChild;
	}
	
	/////////////////////////////////
	// PUBLIC RENDERING METHODS
	////////////////////////////////
	
	/**
	 * start the rendering of the positive z-index children
	 */ 
	public function renderPositiveChildElementRenderers(graphicContext:NativeElement):Void
	{
		renderChildElementRenderers(_positiveZIndexChildRenderers, graphicContext);
	}
	
	/**
	 * start the rendering of the zero and auto z-index children
	 */ 
	public function renderZeroAndAutoChildElementRenderers(graphicContext:NativeElement):Void
	{
		renderChildElementRenderers(_zeroAndAutoZIndexChildRenderers, graphicContext);
	}
	
	/**
	 * start the rendering of the negative z-index children
	 */
	public function renderNegativeChildElementRenderers(graphicContext:NativeElement):Void
	{
		renderChildElementRenderers(_negativeZIndexChildRenderers, graphicContext);
	}
	
	/////////////////////////////////
	// PRIVATE RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Utils method to start the rendering of an array of child root
	 * ElementRenderer
	 */
	private function renderChildElementRenderers(rootElementRenderers:Array<ElementRenderer>, graphicContext:NativeElement):Void
	{
		for (i in 0...rootElementRenderers.length)
		{
			//the child element renderer is attached to its parent graphic context
			//
			//TODO 1 : this cause a z-index bug as if the parent is a child of the formatting
			//context root, the child element renderer is not displayed on top of the in-flow elements
			var parentElementRenderer:ElementRenderer = cast(rootElementRenderers[i].parentNode);
			rootElementRenderers[i].render(parentElementRenderer.graphicsContext);
		}
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
		_zeroAndAutoZIndexChildRenderers.push(elementRenderer);
	}
	
	/**
	 * Utils method to unregister ElementRenderer with a z-index of 'auto'
	 */ 
	public function removeAutoZIndexChildElementRenderer(elementRenderer:ElementRenderer):Void
	{
		_zeroAndAutoZIndexChildRenderers.remove(elementRenderer);
	}
	
	/////////////////////////////////
	// PRIVATE LAYER TREE METHODS
	////////////////////////////////
	
	/**
	 * When inserting a new root ElementRenderer in the positive z-index
	 * child renderer array, it must be inserted at the right index so that
	 * the array is ordered from least positive to most positive
	 */
	private function insertPositiveZIndexChildRenderer(rootElementRenderer:ElementRenderer, rootElementRendererZIndex:Int):Void
	{
		//the array of positive child renderer will be reconstructed
		var newPositiveZIndexChildRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		//flag checking if the root ElementRenderer was already inserted
		//in the array
		var isInserted:Bool = false;
		
		//loop in all the positive z-index array
		for (i in 0..._positiveZIndexChildRenderers.length)
		{
			//get the z-index of the child at the current index
			var currentRendererZIndex:Int = 0;
			switch( _positiveZIndexChildRenderers[i].computedStyle.zIndex)
			{
				case ZIndex.integer(value):
					currentRendererZIndex = value;
					
				default:	
			}
			
			//if the new root ElementRenderer has a least positive z-index than the current
			//child it is inserted at this index
			//also check that it is only inserted the first time this happens, else it will be
			//inserted at each subsequent index
			if (rootElementRendererZIndex < currentRendererZIndex && isInserted == false)
			{
				newPositiveZIndexChildRenderers.push(rootElementRenderer);
				isInserted = true;

			}
			
			//push the current child in the new array
			newPositiveZIndexChildRenderers.push(_positiveZIndexChildRenderers[i]);
			
		}
		
		//if the new root ElementRenderer wasn't inserted, either
		//it is the first item in the array or it has the most positive
		//z-index
		if (isInserted == false)
		{
			newPositiveZIndexChildRenderers.push(rootElementRenderer);
		}
		
		//replace the current array with the new one
		_positiveZIndexChildRenderers = newPositiveZIndexChildRenderers;

	}
	
	/**
	 * Follows the same logic as the method above for the negative z-index child
	 * array. The array must be ordered from most negative to least negative
	 */ 
	private function insertNegativeZIndexChildRenderer(rootElementRenderer:ElementRenderer, rootElementRendererZIndex:Int):Void
	{
		var newNegativeZIndexChildRenderers:Array<ElementRenderer> = new Array<ElementRenderer>();

		var isInserted:Bool = false;
		
		for (i in 0..._negativeZIndexChildRenderers.length)
		{
			var currentRendererZIndex:Int = 0;
			
			switch(_negativeZIndexChildRenderers[i].computedStyle.zIndex)
			{
				case ZIndex.integer(value):
					currentRendererZIndex = value;
					
				default:	
			}
			
			if (currentRendererZIndex  > rootElementRendererZIndex && isInserted == false)
			{
				newNegativeZIndexChildRenderers.push(rootElementRenderer);
				isInserted = true;
			}
			
			newNegativeZIndexChildRenderers.push(_negativeZIndexChildRenderers[i]);
		}
		
		if (isInserted == false)
		{
			newNegativeZIndexChildRenderers.push(rootElementRenderer);
		}
		
		_negativeZIndexChildRenderers = newNegativeZIndexChildRenderers;
		
	}
	

	/////////////////////////////////
	// PUBLIC HIT-TESTING METHODS
	////////////////////////////////
	
	//TODO 2 : for now traverse all tree, but should instead return as soon as an ElementRenderer
	//is found
	public function getTopMostElementRendererAtPoint(point:PointData, scrollX:Float, scrollY:Float):ElementRenderer
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = getElementRenderersAtPoint(point, scrollX, scrollY);
		
		return elementRenderersAtPoint[elementRenderersAtPoint.length - 1];
	}
	
	public function getElementRenderersAtPoint(point:PointData, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = getElementRenderersAtPointInLayer(_rootElementRenderer, point, scrollX, scrollY);

		if (_rootElementRenderer.hasChildNodes() == true)
		{
			var childRenderers:Array<ElementRenderer> = getChildRenderers();
			
			var elementRenderersAtPointInChildRenderers:Array<ElementRenderer> = getElementRenderersAtPointInChildRenderers(point, childRenderers, scrollX, scrollY);
			
			for (i in 0...elementRenderersAtPointInChildRenderers.length)
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
		
		
		
		for (i in 0...renderer.childNodes.length)
		{
			var child:ElementRenderer = cast(renderer.childNodes[i]);
			
			if (child.layerRenderer == this)
			{
				if (child.hasChildNodes() == true)
				{
					
					var childElementRenderersAtPointInLayer:Array<ElementRenderer> = getElementRenderersAtPointInLayer(child, point, scrollX, scrollY);
					
					for (j in 0...childElementRenderersAtPointInLayer.length)
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
		
		for (i in 0...childRenderers.length)
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
					elementRenderersAtPointInChildRenderer = childRenderers[i].layerRenderer.getElementRenderersAtPoint(point, scrollX + _rootElementRenderer.scrollLeft, scrollY + _rootElementRenderer.scrollTop);
				}
			}
		
				
			for (j in 0...elementRenderersAtPointInChildRenderer.length)
			{
				elementRenderersAtPointInChildRenderers.push(elementRenderersAtPointInChildRenderer[j]);
			}
		}
		
		
		return elementRenderersAtPointInChildRenderers;
	}
	
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
		
		for (i in 0..._negativeZIndexChildRenderers.length)
		{
			var childRenderer:ElementRenderer = cast(_negativeZIndexChildRenderers[i]);
			childRenderers.push(childRenderer);
		}
		for (i in 0..._zeroAndAutoZIndexChildRenderers.length)
		{
			var childRenderer:ElementRenderer = cast(_zeroAndAutoZIndexChildRenderers[i]);
			childRenderers.push(childRenderer);
		}
		for (i in 0..._positiveZIndexChildRenderers.length)
		{
			var childRenderer:ElementRenderer = cast(_positiveZIndexChildRenderers[i]);
			childRenderers.push(childRenderer);
		}
		
		return childRenderers;
	}
	
	/////////////////////////////////
	// GETTER
	////////////////////////////////
	
	private function get_rootElementRenderer():ElementRenderer
	{
		return _rootElementRenderer;
	}
}