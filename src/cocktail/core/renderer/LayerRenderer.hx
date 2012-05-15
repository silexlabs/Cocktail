/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.style.StyleData;
import cocktail.core.geom.Matrix;
import cocktail.core.NativeElement;
import cocktail.core.geom.GeomData;
import flash.display.Sprite;
import flash.geom.Rectangle;
import haxe.Log;

/**
 * A LayerRenderer is in charge of rendering 
 * one or many ElementRenderers. The LayerRenders
 * of the document are rendered on top of each
 * other in a defined order.
 * 
 * LayerRenderers are created by ElementRenderers
 * which can either create new LayerRenderer or 
 * use the one of their parent
 * 
 * All the LayerRenderers are rendered recursively
 * starting from the LayerRenderer generated by 
 * the BodyHTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class LayerRenderer extends Node
{
	/**
	 * A reference to the ElementRenderer which
	 * created the LayerRenderer
	 */
	private var _rootRenderer:ElementRenderer;
	
	private var _graphicsContext:NativeElement;
	
	private var _scrollBarsGraphicContext:NativeElement;
	
	private var _treeOrderChildLayers:Array<LayerRenderer>;
	
	private var _positiveOrderChildLayers:Array<LayerRenderer>;
	
	private var _negativeOrderChildLayers:Array<LayerRenderer>;
	
	public var zIndex(get_zIndex, never):ZIndex;

	/**
	 * class constructor
	 */
	public function new(rootRenderer:ElementRenderer) 
	{
		super();
		_rootRenderer = rootRenderer;
		_graphicsContext = new Sprite();
		_scrollBarsGraphicContext = new Sprite();
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////

	
	/**
	 * Render all the ElementRenderers belonging to this LayerRenderer
	 * in a defined order
	 */
	public function render(parentGraphicsContext:NativeElement, parentRelativeOffset:PointData, rootRenderer:ElementRenderer = null, renderChildLayers:Bool = true):Void
	{
		if (renderChildLayers == true)
		{
			detach();
		}
		
		
		if (rootRenderer == null)
		{
			rootRenderer = _rootRenderer;
		}

		var relativeOffset:PointData = getRelativeOffset(rootRenderer);
		relativeOffset.x += parentRelativeOffset.x;
		relativeOffset.y += parentRelativeOffset.y;

		
		//here the root renderer is a block box renderer. It can be an inline level
		//which establishes an inline formatting context : an inline-block
		if (rootRenderer.isReplaced() == false && rootRenderer.isInlineLevel() == false || 
		rootRenderer.establishesNewFormattingContext() == true)
		{
			
			var blockBoxRootRenderer:BlockBoxRenderer = cast(rootRenderer);
		
			//render the ElementRenderer which created this layer
			blockBoxRootRenderer.render(_graphicsContext, relativeOffset);
		
			
			//TODO here : render children with negative z-index
			
			//render all the block container children belonging to this layer
			blockBoxRootRenderer.renderBlockContainerChildren(_graphicsContext, relativeOffset);
			
			//TODO here : render non-positioned float
			
			//TODO :  doc
			//TODO : relative offset is no longer applied
			blockBoxRootRenderer.renderBlockReplacedChildren(_graphicsContext, relativeOffset);
	
			//render all the line boxes belonging to this layer
			blockBoxRootRenderer.renderLineBoxes(_graphicsContext, relativeOffset);
			
			//TODO : doc, this fix is here to prevent inlineBlock from rendering their
			//child layers, maybe add a new "if(inlineblock)" instead but should also
			//work for float
			if (renderChildLayers == true)
			{
				//render all the child layers with a z-index of 0
				renderChildLayer(_graphicsContext, relativeOffset);
			}
			
			//TODO here : render children with positive z-index
			
			//TODO : this logic should go into BlockBoxRenderer ? should call layerRenderer.clip ?
			
			if (blockBoxRootRenderer.isXAxisClipped() == true && blockBoxRootRenderer.isYAxisClipped() == true)
			{
				_graphicsContext.x = _rootRenderer.globalBounds.x;
				_graphicsContext.y = _rootRenderer.globalBounds.y;
				_graphicsContext.scrollRect = new Rectangle(0 , 0, _rootRenderer.globalBounds.width, _rootRenderer.globalBounds.height);
			}
			else if (blockBoxRootRenderer.isXAxisClipped() == true)
			{
				_graphicsContext.x = _rootRenderer.globalBounds.x;
				_graphicsContext.y = _rootRenderer.globalBounds.y;
				//TODO : how to prevent clipping in one direction ? 10000 might not be enougn for scrollable content
				_graphicsContext.scrollRect = new Rectangle(0 , 0, _rootRenderer.globalBounds.width, 10000);
			}
			else if (blockBoxRootRenderer.isYAxisClipped() == true)
			{
				_graphicsContext.x = _rootRenderer.globalBounds.x;
				_graphicsContext.y = _rootRenderer.globalBounds.y;
				//TODO : how to prevent clipping in one direction ? 10000 might not be enougn for scrollable content
				_graphicsContext.scrollRect = new Rectangle(0 , 0, 10000, _rootRenderer.globalBounds.height);
			}
			
			
			//_graphicsContext.x = rootRenderer.globalBounds.x;
			//_graphicsContext.y = rootRenderer.globalBounds.y;
		//	_graphicsContext.scrollRect = new Rectangle(0, 0, rootRenderer.globalBounds.width, rootRenderer.globalBounds.height);
		
			blockBoxRootRenderer.renderScrollBars(_scrollBarsGraphicContext, relativeOffset);
			
		}
		
		//here the root renderer is an inline box renderer which doesn't establish a formatting context
		else if (rootRenderer.isReplaced() == false && rootRenderer.isInlineLevel() == true)
		{
			//TODO : render child layers
			rootRenderer.render(_graphicsContext, relativeOffset);
		}
		
		//here the root renderer is a replaced element
		else
		{
			//render the replaced element, render its background and asset
			rootRenderer.render(_graphicsContext, relativeOffset);
		}
		
		if (renderChildLayers == true)
		{
			parentGraphicsContext.addChild(_graphicsContext);
			parentGraphicsContext.addChild(_scrollBarsGraphicContext);
		}
	}
	
	public function scroll(x:Float, y:Float, startedScroll:Bool = true):Void
	{
		//TODO IMPORTANT: big hack but will do for now
		//TODO : should be applied to every positioned element whose
		//containing block is a parent of the root renderer.
		//Add a public method on ElementRenderer ?
		//TODO : might be trouble for hit test -> maybe not as done at ElementRenderer
		//level, they now if they are subject to scroll or not
		if (_rootRenderer.computedStyle.position == fixed)
		{
			_graphicsContext.y = y;
			_graphicsContext.x = x;
			return;
		}
		
		if (startedScroll == false)
		{
			return;
		}
		
		var childLayers:Array<LayerRenderer> = getChildLayers();
		
		
		for (i in 0...childLayers.length)
		{
			childLayers[i].scroll(x, y, false);
		}
		
		_graphicsContext.x = _rootRenderer.globalBounds.x;
		_graphicsContext.y = _rootRenderer.globalBounds.y;
		
		
		var width:Float;
		var height:Float;
		
		if (_graphicsContext.scrollRect != null)
		{
			width = _graphicsContext.scrollRect.width;
			height = _graphicsContext.scrollRect.height;
		}
		else
		{
			width =  _rootRenderer.globalBounds.width;
			height = _rootRenderer.globalBounds.height;
		}
	
		_graphicsContext.scrollRect = new Rectangle(x , y, width, height);
	}
	

	public function detach():Void
	{
		//TODO : quick fix, should be abstracted
			for (i in 0..._graphicsContext.numChildren)
			{
				_graphicsContext.removeChildAt(0);
			}
			
			for (i in 0..._scrollBarsGraphicContext.numChildren)
			{
				_scrollBarsGraphicContext.removeChildAt(0);
			}
	}
	
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		//TODO : re-implement
		/**
		var childLayer:LayerRenderer = cast(newChild);
		switch(childLayer.zIndex)
		{
			case ZIndex.cssAuto:
				_treeOrderChildLayers.push(childLayer);
				
			case ZIndex.integer(value):
				if (value == 0)
				{
					//TODO : might not put in the right order after DOM manipulation, use "insertBefore" ?
					_treeOrderChildLayers.push(childLayer);
				}
				else if (value > 0)
				{
					insertPositiveOrderChildLayer(childLayer, value);
				}
				else if (value < 0)
				{
					insertNegativeOrderChildLayer(childLayer, value);
				}
				
		}
		*/
		return newChild;
	}
	
	private function insertPositiveOrderChildLayer(childLayer:LayerRenderer, childLayerZIndex:Int):Void
	{
		var newPositiveChildLayers:Array<LayerRenderer> = new Array<LayerRenderer>();
		
		for (i in 0..._positiveOrderChildLayers.length)
		{
			newPositiveChildLayers.push(_positiveOrderChildLayers[i]);
			
			var currentLayerZIndex:Int = 0;
			
			switch( _positiveOrderChildLayers[i].zIndex)
			{
				case ZIndex.integer(value):
					currentLayerZIndex = value;
					
				default:	
			}
			
			if (currentLayerZIndex <= childLayerZIndex)
			{
				newPositiveChildLayers.push(childLayer);
			}
		}
		
		_positiveOrderChildLayers = newPositiveChildLayers;
	}
	
	private function insertNegativeOrderChildLayer(childLayer:LayerRenderer, childLayerZIndex:Int):Void
	{
		var newNegativeChildLayers:Array<LayerRenderer> = new Array<LayerRenderer>();
		
		for (i in 0..._negativeOrderChildLayers.length)
		{
			var currentLayerZIndex:Int = 0;
			
			switch( _positiveOrderChildLayers[i].zIndex)
			{
				case ZIndex.integer(value):
					currentLayerZIndex = value;
					
				default:	
			}
			
			if (currentLayerZIndex  > childLayerZIndex)
			{
				newNegativeChildLayers.push(childLayer);
			}
			
			newNegativeChildLayers.push(_negativeOrderChildLayers[i]);
		}
		
		_negativeOrderChildLayers = newNegativeChildLayers;
	}
	
	//TODO : doc
	private function getRelativeOffset(rootRenderer:ElementRenderer):PointData
	{
		var relativeOffset:PointData = { x:0.0, y:0.0 };
		//if the root renderer is relatively positioned,
		//then its offset must be applied to all of 
		//its children
		if (rootRenderer.isRelativePositioned() == true)
		{
			//first try to apply the left offset of the root renderer if it is
			//not auto
			if (rootRenderer.coreStyle.left != PositionOffset.cssAuto)
			{
				relativeOffset.x += rootRenderer.coreStyle.computedStyle.left;
			}
			//else the right offset,
			else if (rootRenderer.coreStyle.right != PositionOffset.cssAuto)
			{
				relativeOffset.x -= rootRenderer.coreStyle.computedStyle.right;
			}
			
			//if both left and right offset is auto, then the root renderer uses its static
			//position (its normal position in the flow) and no offset needs to be applied
			//to its children
		
			//same for vertical offset
			if (rootRenderer.coreStyle.top != PositionOffset.cssAuto)
			{
				relativeOffset.y += rootRenderer.coreStyle.computedStyle.top; 
			}
			else if (rootRenderer.coreStyle.bottom != PositionOffset.cssAuto)
			{
				relativeOffset.y -= rootRenderer.coreStyle.computedStyle.bottom; 
			}
		}
		
		return relativeOffset;
	}
	
	public function getElementRenderersAtPoint(point:PointData):Array<ElementRenderer>
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = getElementRenderersAtPointInLayer(_rootRenderer, point);

		if (_rootRenderer.hasChildNodes() == true)
		{
			var childLayers:Array<LayerRenderer> = getChildLayers();
		
			var elementRenderersAtPointInChildLayers:Array<ElementRenderer> = getElementRenderersAtPointInChildLayers(point, childLayers);
			
			for (i in 0...elementRenderersAtPointInChildLayers.length)
			{
				elementRenderersAtPoint.push(elementRenderersAtPointInChildLayers[i]);
			}
		}
		
		
		return elementRenderersAtPoint;
	}
	
	private function getElementRenderersAtPointInLayer(renderer:ElementRenderer, point:PointData):Array<ElementRenderer>
	{
		var elementRenderersAtPointInLayer:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		if (isWithinBounds(point, renderer.globalBounds) == true)
		{
			elementRenderersAtPointInLayer.push(renderer);
		}
		
		for (i in 0...renderer.childNodes.length)
		{
			var child:ElementRenderer = cast(renderer.childNodes[i]);
			
			if (child.layerRenderer == this)
			{
				if (child.hasChildNodes() == true)
				{
					var childElementRenderersAtPointInLayer:Array<ElementRenderer> = getElementRenderersAtPointInLayer(child, point);
					
					for (j in 0...childElementRenderersAtPointInLayer.length)
					{
						elementRenderersAtPointInLayer.push(childElementRenderersAtPointInLayer[j]);
					}
				}
				else
				{
					if (isWithinBounds(point, child.globalBounds) == true)
					{
						elementRenderersAtPointInLayer.push(child);
					}
				}
			}
		}
		
		return elementRenderersAtPointInLayer;
	}
	
	private function getElementRenderersAtPointInChildLayers(point:PointData, childLayers:Array<LayerRenderer>):Array<ElementRenderer>
	{
		var elementRenderersAtPointInChildLayers:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0...childLayers.length)
		{
			var elementRenderersAtPointInChildLayer:Array<ElementRenderer> = childLayers[i].getElementRenderersAtPoint(point);
			
			for (j in 0...elementRenderersAtPointInChildLayer.length)
			{
				elementRenderersAtPointInChildLayers.push(elementRenderersAtPointInChildLayer[j]);
			}
		}
		
		
		return elementRenderersAtPointInChildLayers;
	}
	
	private function isWithinBounds(point:PointData, bounds:RectangleData):Bool
	{
		return point.x > bounds.x && (point.x < bounds.x + bounds.width) && point.y > bounds.y && (point.y < bounds.y + bounds.height);	
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	
	/**
	 * Render all the children LayerRenderer of this LayerRenderer
	 * and return an array of NativeElements from it
	 */
	private function renderChildLayer(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		var childLayers:Array<LayerRenderer> = getChildLayers();
		
		for (i in 0...childLayers.length)
		{
			childLayers[i].render(graphicContext, relativeOffset);
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
	
	
	private function get_zIndex():ZIndex
	{
		return _rootRenderer.computedStyle.zIndex;
	}

	
	
	
	//TODO : implement layer renderer transformation
	
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
}