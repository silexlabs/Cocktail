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
import flash.display.Sprite;
import flash.geom.Rectangle;
import haxe.Log;

/**
 * 
 * A LayerRenderer is in charge of executing the rendering
 * steps in a defined order starting from the root ElementRenderer
 * which created the LayerRenderer.
 * 
 * The created LayerRenderers form the LayerRenderer tree,
 * paralleling the rendering tree, although not all ElementRenderers
 * create their own LayerRenderer, in most cases they use the one of
 * their parent. Wether an ElementRenderer creates a new LayerRenderer
 * is determined by its createNewStackingContext() method.
 * 
 * When a LayerRenderer is rendering it also renders all of its children
 * LayerRenderer, thus rendering recursively all the rendering tree
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
	 * A graphic context object onto which the rendered ElementRenderers
	 * are painted
	 */
	private var _graphicsContext:NativeElement;
	
	/**
	 * A graphic context only used for the scrollbars as they must always
	 * be displayed on top of other rendered ElementRenderers
	 */
	private var _scrollBarsGraphicContext:NativeElement;
	
	/**
	 * Holds a reference to all of the children of the root ElementRenderer
	 * which also create a new LayerRenderer, and which have a z-index
	 * computed value of 0 or auto, which means that they are rendered in tree
	 * order of the DOM tree. Also, children with a z-index of 'auto' don't actually
	 * create new LayerRenderer, although they are rendered as if they did
	 */
	private var _zeroOrAutoZIndexChildRenderers:Array<ElementRenderer>;
	
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
		_graphicsContext = new Sprite();
		_scrollBarsGraphicContext = new Sprite();
		
		_zeroOrAutoZIndexChildRenderers = new Array<ElementRenderer>();
		_positiveZIndexChildRenderers = new Array<ElementRenderer>();
		_negativeZIndexChildRenderers = new Array<ElementRenderer>();
	}
	
	/////////////////////////////////
	// PUBLIC RENDERING METHODS
	////////////////////////////////
	
	/**
	 * Main rendering method. Starts from the root renderer which created this
	 * LayerRenderer and apply the rendering phases defined here : 
	 * http://www.w3.org/TR/CSS2/zindex.html
	 */
	public function render(rootElementRenderer:ElementRenderer, parentGraphicsContext:NativeElement, parentRelativeOffset:PointData):Void
	{
		if (rootElementRenderer.establishesNewStackingContext() == true)
		{
			detach();
		}
		
		var relativeOffset:PointData = rootElementRenderer.getRelativeOffset();
		relativeOffset.x += parentRelativeOffset.x;
		relativeOffset.y += parentRelativeOffset.y;
		
		//here the root renderer is a block box renderer. It can be an inline level
		//which establishes an inline formatting context : an inline-block
		if (rootElementRenderer.isReplaced() == false && rootElementRenderer.isInlineLevel() == false || 
		rootElementRenderer.establishesNewFormattingContext() == true)
		{
			var blockBoxrootElementRenderer:BlockBoxRenderer = cast(rootElementRenderer);
		
			//TODO 1 : block box background should not scroll with the rest of the children
			//render the ElementRenderer which created this layer
			blockBoxrootElementRenderer.render(_graphicsContext, relativeOffset);
			
			if (rootElementRenderer.establishesNewStackingContext() == true)
			{
				renderChildLayer(_negativeZIndexChildRenderers, _graphicsContext, relativeOffset);
			}
			
			//render all the block container children belonging to this layer
			blockBoxrootElementRenderer.renderBlockContainerChildren(_graphicsContext, relativeOffset);
			
			//TODO 5 : render non-positioned float
			
			//render all the replaced (embedded) children displayed as blocks
			blockBoxrootElementRenderer.renderBlockReplacedChildren(_graphicsContext, relativeOffset);
	
			//render all the line boxes belonging to this layer
			blockBoxrootElementRenderer.renderLineBoxes(_graphicsContext, relativeOffset);
			
			
			
			//TODO 2 : doc, this fix is here to prevent inlineBlock from rendering their
			//child layers, maybe add a new "if(inlineblock)" instead but should also
			//work for float -> now can use if establishesNewStackingContext
			if (rootElementRenderer.establishesNewStackingContext() == true)
			{	
				//render all the child layers with a z-index of 0
				renderChildLayer(_zeroOrAutoZIndexChildRenderers, _graphicsContext, relativeOffset);
				renderChildLayer(_positiveZIndexChildRenderers, _graphicsContext, relativeOffset);
			}
			
			clip(blockBoxrootElementRenderer);
			//TODO 2 : scrollbar shouldn't need their own graphic context, should not be scrolled,
			//like the fixed elements
			blockBoxrootElementRenderer.renderScrollBars(_scrollBarsGraphicContext, relativeOffset);
			
		}
		
		//here the root renderer is an inline box renderer which doesn't establish a formatting context
		else if (rootElementRenderer.isReplaced() == false && rootElementRenderer.isInlineLevel() == true)
		{
			if (rootElementRenderer.establishesNewStackingContext() == true)
			{
				renderChildLayer(_negativeZIndexChildRenderers, _graphicsContext, relativeOffset);
			}
			
			rootElementRenderer.render(_graphicsContext, relativeOffset);
			
			if (rootElementRenderer.establishesNewStackingContext() == true)
			{
				
				renderChildLayer(_zeroOrAutoZIndexChildRenderers, _graphicsContext, relativeOffset);
				renderChildLayer(_positiveZIndexChildRenderers, _graphicsContext, relativeOffset);
			}
		}
		
		//here the root renderer is a replaced element
		else
		{
			//render the replaced element, render its background and asset
			rootElementRenderer.render(_graphicsContext, relativeOffset);
		}
		
		if (rootElementRenderer.establishesNewStackingContext() == true)
		{
			parentGraphicsContext.addChild(_graphicsContext);
			parentGraphicsContext.addChild(_scrollBarsGraphicContext);
		}
	}
	
	/////////////////////////////////
	// PRIVATE RENDERING METHODS
	////////////////////////////////
	
	private function renderBlockBoxRootRenderer(rootRenderer:BlockBoxRenderer, graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		
	}
	
	private function renderInlineBoxRootRenderer(rootRenderer:InlineBoxRenderer, graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		
	}
	
	private function renderEmbeddedBoxRootRenderer(rootRenderer:EmbeddedBoxRenderer, graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		
	}
	
	/////////////////////////////////
	// PUBLIC VISUAL EFFECT METHODS
	////////////////////////////////
	
	public function clip(blockBoxrootElementRenderer:BlockBoxRenderer):Void
	{
		//TODO 1 : this logic should go into BlockBoxRenderer ? should call layerRenderer.clip ?
			
		#if (flash9 || nme)
		
			if (blockBoxrootElementRenderer.isXAxisClipped() == true && blockBoxrootElementRenderer.isYAxisClipped() == true)
			{
				_graphicsContext.x = _rootElementRenderer.globalBounds.x;
				_graphicsContext.y = _rootElementRenderer.globalBounds.y;
				_graphicsContext.scrollRect = new Rectangle(0 , 0, _rootElementRenderer.globalBounds.width, _rootElementRenderer.globalBounds.height);

			}
			else if (blockBoxrootElementRenderer.isXAxisClipped() == true)
			{
				_graphicsContext.x = _rootElementRenderer.globalBounds.x;
				_graphicsContext.y = _rootElementRenderer.globalBounds.y;
				//TODO 2 : how to prevent clipping in one direction ? 10000 might not be enougn for scrollable content
				_graphicsContext.scrollRect = new Rectangle(0 , 0, _rootElementRenderer.globalBounds.width, 10000);
		
			}
			else if (blockBoxrootElementRenderer.isYAxisClipped() == true)
			{
				_graphicsContext.x = _rootElementRenderer.globalBounds.x;
				_graphicsContext.y = _rootElementRenderer.globalBounds.y;
				//TODO 2 : how to prevent clipping in one direction ? 10000 might not be enougn for scrollable content
				_graphicsContext.scrollRect = new Rectangle(0 , 0, 10000, _rootElementRenderer.globalBounds.height);
			}
			else
			{
				_graphicsContext.scrollRect = null;
			}
			
		#end	
	}
	
	public function scroll(x:Float, y:Float, rootElementRenderer:ElementRenderer = null, startedScroll:Bool = true):Void
	{
		if (rootElementRenderer == null)
		{
			rootElementRenderer = _rootElementRenderer;
		}
		
		//TODO 1 IMPORTANT: big hack but will do for now
		//TODO 1 : doesn't work for zindex auto positioned elements, as they don't
		//have a graphic context of their own
		//TODO 2 : should be applied to every positioned element whose
		//containing block is a parent of the root renderer.
		//Add a public method on ElementRenderer ?
		if (rootElementRenderer.computedStyle.position == fixed)
		{
			#if (flash9 || nme)
			_graphicsContext.y = y;
			_graphicsContext.x = x;
			#end
		}
		
		if (startedScroll == false)
		{
			return;
		}
		
		
		for (i in 0..._zeroOrAutoZIndexChildRenderers.length)
		{
			_zeroOrAutoZIndexChildRenderers[i].layerRenderer.scroll(x, y,_zeroOrAutoZIndexChildRenderers[i], false);
		}
		
		for (i in 0..._positiveZIndexChildRenderers.length)
		{
			_positiveZIndexChildRenderers[i].layerRenderer.scroll(x, y,_positiveZIndexChildRenderers[i], false);
		}
		
		for (i in 0..._negativeZIndexChildRenderers.length)
		{
			_negativeZIndexChildRenderers[i].layerRenderer.scroll(x, y,_negativeZIndexChildRenderers[i], false);
		}
		
		#if (flash9 || nme)
		
		_graphicsContext.x = _rootElementRenderer.globalBounds.x;
		_graphicsContext.y = _rootElementRenderer.globalBounds.y;
		
		var width:Float;
		var height:Float;
		
		if (_graphicsContext.scrollRect != null)
		{
			width = _graphicsContext.scrollRect.width;
			height = _graphicsContext.scrollRect.height;
		}
		else
		{
			width =  _rootElementRenderer.globalBounds.width;
			height = _rootElementRenderer.globalBounds.height;
		}
		
		_graphicsContext.scrollRect = new Rectangle(x + _rootElementRenderer.globalBounds.x, y + _rootElementRenderer.globalBounds.y, width, height);
		#end
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		var childLayer:LayerRenderer = cast(newChild);

		switch(childLayer.rootElementRenderer.computedStyle.zIndex)
		{
			case ZIndex.cssAuto:
				_zeroOrAutoZIndexChildRenderers.push(childLayer.rootElementRenderer);
				
			case ZIndex.integer(value):
				if (value == 0)
				{
					//TODO 1 : might not put in the right order after DOM manipulation, use "insertBefore" ?
					_zeroOrAutoZIndexChildRenderers.push(childLayer.rootElementRenderer);
				}
				else if (value > 0)
				{
					insertPositiveOrderChildLayer(childLayer.rootElementRenderer, value);
				}
				else if (value < 0)
				{
					insertNegativeOrderChildLayer(childLayer.rootElementRenderer, value);
				}
				
		}
		
		return newChild;
	}
	
	override public function removeChild(oldChild:Node):Node
	{
		var childLayer:LayerRenderer = cast(oldChild);

		//TODO 2 : shouldn't have ot try in each ?
		_zeroOrAutoZIndexChildRenderers.remove(childLayer.rootElementRenderer);
		_positiveZIndexChildRenderers.remove(childLayer.rootElementRenderer);
		_negativeZIndexChildRenderers.remove(childLayer.rootElementRenderer);
		
		super.removeChild(oldChild);
	
		return oldChild;
	}
	
	/////////////////////////////////
	// PUBLIC LAYER TREE METHODS
	////////////////////////////////
	
	//TODO 3 : should have an attach method ?
	//TODO 2 : this detach method is not coherent with what does the
	//ElementRenderer detach method
	public function detach():Void
	{
		for (i in 0..._childNodes.length)
		{
			var child:LayerRenderer = cast(_childNodes[i]);
			child.detach();
		}
		#if (flash9 || nme)
		//TODO 1 : quick fix, should be abstracted
			for (i in 0..._graphicsContext.numChildren)
			{
				_graphicsContext.removeChildAt(0);
			}
			
			for (i in 0..._scrollBarsGraphicContext.numChildren)
			{
				_scrollBarsGraphicContext.removeChildAt(0);
			}
		#end	
	}
	
	public function insertTreeOrderChildElementRenderer(elementRenderer:ElementRenderer):Void
	{
		_zeroOrAutoZIndexChildRenderers.push(elementRenderer);
	}
	
	public function removeTreeOrderChildElementRenderer(elementRenderer:ElementRenderer):Void
	{
		_zeroOrAutoZIndexChildRenderers.remove(elementRenderer);
	}
	
	/////////////////////////////////
	// PRIVATE LAYER TREE METHODS
	////////////////////////////////
	
	private function insertPositiveOrderChildLayer(childLayer:ElementRenderer, childLayerZIndex:Int):Void
	{
		var newPositiveChildLayers:Array<ElementRenderer> = new Array<ElementRenderer>();

		
		var isInserted:Bool = false;
		
		for (i in 0..._positiveZIndexChildRenderers.length)
		{
			
			
			var currentLayerZIndex:Int = 0;
			
			switch( _positiveZIndexChildRenderers[i].computedStyle.zIndex)
			{
				case ZIndex.integer(value):
					currentLayerZIndex = value;
					
				default:	
			}
			
			if (childLayerZIndex < currentLayerZIndex && isInserted == false)
			{
				newPositiveChildLayers.push(childLayer);
				isInserted = true;

			}
			
			newPositiveChildLayers.push(_positiveZIndexChildRenderers[i]);
			
		}
		
		if (isInserted == false)
		{
			newPositiveChildLayers.push(childLayer);
		}
		_positiveZIndexChildRenderers = newPositiveChildLayers;

	}
	
	private function insertNegativeOrderChildLayer(childLayer:ElementRenderer, childLayerZIndex:Int):Void
	{
		var newNegativeChildLayers:Array<ElementRenderer> = new Array<ElementRenderer>();

		var isInserted:Bool = false;
		
		for (i in 0..._negativeZIndexChildRenderers.length)
		{
			var currentLayerZIndex:Int = 0;
			
			switch(_negativeZIndexChildRenderers[i].computedStyle.zIndex)
			{
				case ZIndex.integer(value):
					currentLayerZIndex = value;
					
				default:	
			}
			
			if (currentLayerZIndex  > childLayerZIndex && isInserted == false)
			{
				newNegativeChildLayers.push(childLayer);
				isInserted = true;
			}
			
			newNegativeChildLayers.push(_negativeZIndexChildRenderers[i]);
		}
		
		if (isInserted == false)
		{
			newNegativeChildLayers.push(childLayer);
		}
		
		_negativeZIndexChildRenderers = newNegativeChildLayers;
		
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
			var childLayers:Array<LayerRenderer> = getChildLayers();
			
			
			var elementRenderersAtPointInChildLayers:Array<ElementRenderer> = getElementRenderersAtPointInChildLayers(point, childLayers, scrollX, scrollY);
			
			for (i in 0...elementRenderersAtPointInChildLayers.length)
			{
				elementRenderersAtPoint.push(elementRenderersAtPointInChildLayers[i]);
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
	
	private function getElementRenderersAtPointInChildLayers(point:PointData, childLayers:Array<LayerRenderer>, scrollX:Float, scrollY:Float):Array<ElementRenderer>
	{
		var elementRenderersAtPointInChildLayers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0...childLayers.length)
		{
			
			var elementRenderersAtPointInChildLayer:Array<ElementRenderer> = [];
			//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
			if (childLayers[i].rootElementRenderer.isScrollBar() == true)
			{
				elementRenderersAtPointInChildLayer = childLayers[i].getElementRenderersAtPoint(point, scrollX, scrollY);
			}
			//TODO 1 : messy, ElementRenderer should be aware of their scrollBounds
			else if (childLayers[i].rootElementRenderer.coreStyle.position == fixed)
			{
				elementRenderersAtPointInChildLayer = childLayers[i].getElementRenderersAtPoint(point, scrollX , scrollY);
		
			}
			else
			{
				
				elementRenderersAtPointInChildLayer = childLayers[i].getElementRenderersAtPoint(point, scrollX + _rootElementRenderer.scrollLeft, scrollY + _rootElementRenderer.scrollTop);
			
			}
				
			for (j in 0...elementRenderersAtPointInChildLayer.length)
			{
				elementRenderersAtPointInChildLayers.push(elementRenderersAtPointInChildLayer[j]);
			}
		}
		
		
		return elementRenderersAtPointInChildLayers;
	}
	
	private function isWithinBounds(point:PointData, bounds:RectangleData):Bool
	{
		return point.x >= bounds.x && (point.x <= bounds.x + bounds.width) && point.y >= bounds.y && (point.y <= bounds.y + bounds.height);	
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	
	/**
	 * Render all the children LayerRenderer of this LayerRenderer
	 * and return an array of NativeElements from it
	 */
	private function renderChildLayer(layers:Array<ElementRenderer>, graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		for (i in 0...layers.length)
		{
			layers[i].layerRenderer.render(layers[i], graphicContext, relativeOffset);
		}
	}
	
	/**
	 * Retrieve all the children LayerRenderer of this LayerRenderer by traversing
	 * recursively the rendering tree.
	 */
	private function getChildLayers():Array<LayerRenderer>
	{
		var childLayers:Array<LayerRenderer> = new Array<LayerRenderer>();
		
		for (i in 0..._childNodes.length)
		{
			var childLayer:LayerRenderer = cast(_childNodes[i]);
			childLayers.push(childLayer);
		}
		
		return childLayers;
	}
	

	
	
	
	//TODO 4 : implement layer renderer transformation
	
	/**
	 * when the matrix is set, update also
	 * the values of the native flash matrix of the
	 * native DisplayObject
	 * 
	 * 
	 * @param	matrix
	 */
	public function setNativeMatrix(matrix:Matrix):Void
	{
		/**
		//concenate the new matrix with the base matrix of the HTMLElement
		var concatenatedMatrix:Matrix = getConcatenatedMatrix(matrix);
		
		//get the data of the abstract matrix
		var matrixData:MatrixData = concatenatedMatrix.data;
		
		//create a native flash matrix with the abstract matrix data
		var nativeTransformMatrix:flash.geom.Matrix  = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
	
		//apply the native flash matrix to the native flash DisplayObject
		_htmlElement.nativeElement.transform.matrix = nativeTransformMatrix;
		
	//	super.setNativeMatrix(concatenatedMatrix);
		*/
	}
	
	/**
	 * When concatenating the base Matrix of an embedded element, it must also
	 * be scaled using the intrinsic width and height of the HTMLElement as reference
	 * 
	 */
	private function getConcatenatedMatrix(matrix:Matrix):Matrix
	{
		
		var currentMatrix:Matrix = new Matrix();
		//
		//var embeddedHTMLElement:EmbeddedHTMLElement = cast(this._htmlElement);
		//
		//currentMatrix.concatenate(matrix);
		//currentMatrix.translate(this._nativeX, this._nativeY);
		//
		//currentMatrix.scale(this._nativeWidth / embeddedHTMLElement.intrinsicWidth, this._nativeHeight / embeddedHTMLElement.intrinsicHeight, { x:0.0, y:0.0} );
		//
		return currentMatrix;
	}
	
	/**
	 * Concatenate the new matrix with the "base" matrix of the HTMLElement
	 * where only translations (the x and y of the HTMLElement) and scales
	 * (the width and height of the HTMLElement) are applied.
	 * It is neccessary in flash to do so to prevent losing the x, y, width
	 * and height applied during layout
	 * 
	 */
	private function getConcatenatedMatrix2(matrix:Matrix):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		//currentMatrix.concatenate(matrix);
		//currentMatrix.translate(this._nativeX, this._nativeY);
		return currentMatrix;
	}
	
	private function get_rootElementRenderer():ElementRenderer
	{
		return _rootElementRenderer;
	}
}