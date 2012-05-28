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
		_zeroOrAutoZIndexChildRenderers = new Array<ElementRenderer>();
		_positiveZIndexChildRenderers = new Array<ElementRenderer>();
		_negativeZIndexChildRenderers = new Array<ElementRenderer>();
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
	
	
	
	//TODO 1 : shouldn't be called for scrollbars children but is it here that it should be checked for
	//scrollbar or in scrollbar renderer ?
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
	
	
	public function renderPositiveChildLayer(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		renderChildLayer(_positiveZIndexChildRenderers, graphicContext, relativeOffset);
	}
	
	public function renderTreeOrderChildLayer(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		renderChildLayer(_zeroOrAutoZIndexChildRenderers, graphicContext, relativeOffset);
	}
	
	public function renderNegativeChildLayer(graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		renderChildLayer(_negativeZIndexChildRenderers, graphicContext, relativeOffset);
	}
	
	/**
	 * Render all the children LayerRenderer of this LayerRenderer
	 * and return an array of NativeElements from it
	 */
	private function renderChildLayer(layers:Array<ElementRenderer>, graphicContext:NativeElement, relativeOffset:PointData):Void
	{
		for (i in 0...layers.length)
		{
			layers[i].render(graphicContext, relativeOffset);
		}
	}
	
	/**
	 * Retrieve all the children LayerRenderer of this LayerRenderer by traversing
	 * recursively the rendering tree.
	 * 
	 * TODO 1 : should return concatenated child root renderer array
	 * if kept
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
	

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
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