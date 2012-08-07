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
import cocktail.core.style.computer.VisualEffectStylesComputer;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.geom.Matrix;
import cocktail.port.DrawingManager;
import cocktail.port.GraphicsContext;
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
	 * Holds a reference to all of the child LayerRender which have a z-index computed 
	 * value of 0 or auto, which means that they are rendered in tree
	 * order of the DOM tree.
	 */
	private var _zeroAndAutoZIndexChildLayerRenderers:Array<LayerRenderer>;
	
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
	public var graphicsContext(default, null):GraphicsContext;
	
	/**
	 * Store the current width of the window. Used to check if the window
	 * changed size in between renderings
	 */
	private var _windowWidth:Int;
	
	/**
	 * Same as windowWidth for height
	 */
	private var _windowHeight:Int;
	
	/**
	 * A flag determining wether this LayerRenderer has its own
	 * GraphicsContext or use the one of its parent. It helps
	 * to determine if this LayerRenderer is responsible to perform
	 * oparation such as clearing its graphics context when rendering
	 */
	public var hasOwnGraphicsContext(default, null):Bool;
	
	/**
	 * class constructor. init class attributes
	 */
	public function new(rootElementRenderer:ElementRenderer) 
	{
		super();
		
		this.rootElementRenderer = rootElementRenderer;
		
		_zeroAndAutoZIndexChildLayerRenderers = new Array<LayerRenderer>();
		_positiveZIndexChildLayerRenderers = new Array<LayerRenderer>();
		_negativeZIndexChildLayerRenderers = new Array<LayerRenderer>();
		
		hasOwnGraphicsContext = false;
		
		_windowWidth = 0;
		_windowHeight = 0;
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
		
		newChild.attach();
		
		//check the computed z-index of the ElementRenderer which
		//instantiated the child LayerRenderer
		switch(newChild.rootElementRenderer.coreStyle.computedStyle.zIndex)
		{
			case ZIndex.cssAuto:
				//the z-index is 'auto'
				_zeroAndAutoZIndexChildLayerRenderers.push(newChild);
				
			case ZIndex.integer(value):
				if (value == 0)
				{
					_zeroAndAutoZIndexChildLayerRenderers.push(newChild);
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
		removed = _zeroAndAutoZIndexChildLayerRenderers.remove(oldChild);
		
		if (removed == false)
		{
			removed = _positiveZIndexChildLayerRenderers.remove(oldChild);
			
			if (removed == false)
			{
				 _negativeZIndexChildLayerRenderers.remove(oldChild);
			}
		}
		
		oldChild.detach();
		
		super.removeChild(oldChild);
	
		return oldChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * For a LayerRenderer, attach is used to 
	 * get a reference to a GraphicsContext to
	 * paint onto
	 */
	public function attach():Void
	{
		attachGraphicsContext();
		
		//attach all its children recursively
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:LayerRenderer = childNodes[i];
			child.attach();
		}
	}
	
	/**
	 * For a LayerRenderer, detach is used
	 * to dereference the GraphicsContext
	 */
	public function detach():Void
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			var child:LayerRenderer = childNodes[i];
			child.detach();
		}
		
		detachGraphicsContext();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ATTACHEMENT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attach a graphics context if necessary
	 */
	private function attachGraphicsContext():Void
	{
		if (graphicsContext == null)
		{
			if (parentNode != null)
			{
				if (parentNode.graphicsContext != null)
				{
					createGraphicsContext(parentNode.graphicsContext);
				}
			}
		}
	}
	
	/**
	 * Detach the GraphicContext
	 */
	private function detachGraphicsContext():Void 
	{
		//if this LayerRenderer instantiated its own
		//GraphicContext, it is responsible for disposing of it
		if (hasOwnGraphicsContext == true)
		{
			parentNode.graphicsContext.removeChild(graphicsContext);
			graphicsContext.dispose();
			hasOwnGraphicsContext = false;
		}
		
		graphicsContext = null;
	}
	
	/**
	 * Create a new GraphicsContext for this LayerRenderer
	 * or use the one of its parent
	 */
	private function createGraphicsContext(parentGraphicsContext:GraphicsContext):Void
	{
		if (establishesNewGraphicsContext() == true)
		{
			graphicsContext = new GraphicsContext(this);
			parentGraphicsContext.appendChild(graphicsContext);
			hasOwnGraphicsContext = true;
		}
		else
		{
			graphicsContext = parentGraphicsContext;
		}
	}
	
	/**
	 * Wether this LayerRenderer should create its
	 * own GraphicsContext
	 */
	private function establishesNewGraphicsContext():Bool
	{
		return false;
	}
	
	/////////////////////////////////
	// PUBLIC RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Starts the rendering of this LayerRenderer.
	 * Render all its child layers and its root ElementRenderer
	 * 
	 * @param windowWidth the current width of the window
	 * @param windowHeight the current height of the window
	 */
	public function render(windowWidth:Int, windowHeight:Int ):Void
	{
		//update the dimension of the bitmap data if the window size changed
		//since last rendering
		if (windowWidth != _windowWidth || windowHeight != _windowHeight)
		{
			//only update the GraphicContext if it was created
			//by this LayerRenderer
			if (hasOwnGraphicsContext == true)
			{
				graphicsContext.initBitmapData(windowWidth, windowHeight);
			}
			_windowWidth = windowWidth;
			_windowHeight = windowHeight;
		}
	
		//only clear the bitmaps if the GraphicsContext
		//was created by this LayerRenderer
		if (hasOwnGraphicsContext == true)
		{
			//reset the bitmap
			graphicsContext.clear();
		}
		
		//render first negative z-index child LayerRenderer from most
		//negative to least negative
		for (i in 0..._negativeZIndexChildLayerRenderers.length)
		{
			_negativeZIndexChildLayerRenderers[i].render(windowWidth, windowHeight);
		}
		
		//init transparency on the graphicContext if the element is transparent. Everything
		//painted with the element will have an alpha equal to the opacity style
		if (rootElementRenderer.isTransparent() == true)
		{
			graphicsContext.beginTransparency(rootElementRenderer.coreStyle.computedStyle.opacity);
		}
		
		//render the rootElementRenderer itself which will also
		//render all ElementRenderer belonging to this LayerRenderer
		rootElementRenderer.render(graphicsContext);
		
		//stop transparency so that subsequent painted element won't be transparent
		//if they don't themselves have an opacity
		if (rootElementRenderer.isTransparent() == true)
		{
			graphicsContext.endTransparency();
		}
		
		
		//render zero and auto z-index child LayerRenderer, in tree order
		for (i in 0..._zeroAndAutoZIndexChildLayerRenderers.length)
		{
			_zeroAndAutoZIndexChildLayerRenderers[i].render(windowWidth, windowHeight);
		}
		
		//render all the positive LayerRenderer from least positive to 
		//most positive
		for (i in 0..._positiveZIndexChildLayerRenderers.length)
		{
			_positiveZIndexChildLayerRenderers[i].render(windowWidth, windowHeight);
		}
		
		//scrollbars are always rendered last as they should always be the top
		//element of their layer
		rootElementRenderer.renderScrollBars(graphicsContext, windowWidth, windowHeight);
		
		//apply transformations to the layer if needed
		if (rootElementRenderer.isTransformed() == true)
		{
			//TODO 2 : should already be computed at this point
			VisualEffectStylesComputer.compute(rootElementRenderer.coreStyle);
			graphicsContext.transform(getTransformationMatrix(graphicsContext));
		}
	}
	
	/////////////////////////////////
	// PRIVATE RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Compute all the transformation that should be applied to this LayerRenderer
	 * and return it as a transformation matrix
	 */
	private function getTransformationMatrix(graphicContext:GraphicsContext):Matrix
	{
		var relativeOffset:PointData = getRelativeOffset();
		var concatenatedMatrix:Matrix = getConcatenatedMatrix(rootElementRenderer.coreStyle.computedStyle.transform, relativeOffset);
		
		//apply relative positioning as well
		concatenatedMatrix.translate(relativeOffset.x, relativeOffset.y);
		
		return concatenatedMatrix;
	}
	
	/**
	 * Concatenate the transformation matrix obtained with the
	 * transform and transform-origin styles with the current
	 * transformations applied to the root element renderer, such as for 
	 * instance its position in the global space
	 */
	private function getConcatenatedMatrix(matrix:Matrix, relativeOffset:PointData):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		var globalBounds:RectangleData = rootElementRenderer.globalBounds;
		
		//translate to the coordinate system of the root element renderer
		currentMatrix.translate(globalBounds.x + relativeOffset.x, globalBounds.y + relativeOffset.y);
		
		currentMatrix.concatenate(matrix);
		
		//translate back from the coordinate system of the root element renderer
		currentMatrix.translate((globalBounds.x + relativeOffset.x) * -1, (globalBounds.y + relativeOffset.y) * -1);
		return currentMatrix;
	}
	
	/**
	 * Return the relative offset applied to the root element renderer
	 * when rendering. Only relatively positioned root element renderer
	 * have this offset
	 */
	private function getRelativeOffset():PointData
	{
		var relativeOffset:PointData = { x:0.0, y:0.0 };
		
		//only relatively positioned ElementRenderer can have
		//an offset
		if (rootElementRenderer.isRelativePositioned() == true)
		{
			var coreStyle:CoreStyle = rootElementRenderer.coreStyle;
			
			//first try to apply the left offset of the ElementRenderer if it is
			//not auto
			if (coreStyle.left != PositionOffset.cssAuto)
			{
				relativeOffset.x += coreStyle.computedStyle.left;
			}
			//else the right offset,
			else if (coreStyle.right != PositionOffset.cssAuto)
			{
				relativeOffset.x -= coreStyle.computedStyle.right;
			}
			
			//if both left and right offset are auto, then the ElementRenderer uses its static
			//position (its normal position in the flow) and no relative offset needs to
			//be applied
		
			//same for vertical offset
			if (coreStyle.top != PositionOffset.cssAuto)
			{
				relativeOffset.y += coreStyle.computedStyle.top; 
			}
			else if (coreStyle.bottom != PositionOffset.cssAuto)
			{
				relativeOffset.y -= coreStyle.computedStyle.bottom; 
			}
		}
		
		return relativeOffset;
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
		for (i in 0..._zeroAndAutoZIndexChildLayerRenderers.length)
		{
			var childRenderer:LayerRenderer = _zeroAndAutoZIndexChildLayerRenderers[i];
			childRenderers.push(childRenderer.rootElementRenderer);
		}
		for (i in 0..._positiveZIndexChildLayerRenderers.length)
		{
			var childRenderer:LayerRenderer = _positiveZIndexChildLayerRenderers[i];
			childRenderers.push(childRenderer.rootElementRenderer);
		}
		
		return childRenderers;
	}
}