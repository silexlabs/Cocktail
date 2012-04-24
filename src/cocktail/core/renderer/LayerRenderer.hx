package cocktail.core.renderer;
import cocktail.core.geom.Matrix;
import cocktail.core.NativeElement;
import haxe.Log;
/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
import cocktail.core.style.StyleData;

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
class LayerRenderer 
{
	/**
	 * A reference to the ElementRenderer which
	 * created the LayerRenderer
	 */
	private var _rootRenderer:ElementRenderer;
	public var rootRenderer(get_rootRenderer, never):ElementRenderer;

	/**
	 * class constructor
	 */
	public function new(rootRenderer:ElementRenderer) 
	{
		_rootRenderer = rootRenderer;
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////
	
	public function dispose():Void
	{
		_rootRenderer = null;
	}
	
	/**
	 * Render all the ElementRenderers belonging to this LayerRenderer
	 * in a defined order
	 */
	public function render():Array<NativeElement>
	{
		var nativeElements:Array<NativeElement> = new Array<NativeElement>();

		//here the root renderer is a block box renderer. It can be an inline level
		//which establishes an inline formatting context : an inline-block
		if (_rootRenderer.canHaveChildren() == true && _rootRenderer.isInlineLevel() == false || 
		_rootRenderer.establishesNewFormattingContext() == true)
		{
			//render the ElementRenderer which created this layer
			var rootRendererElements:Array<NativeElement> = _rootRenderer.render();
			
			for (i in 0...rootRendererElements.length)
			{
				nativeElements.push(rootRendererElements[i]);
			}
			
			//TODO here : render children with negative z-index
			
			//render all the block container children belonging to this layer
			var blockContainerChildren:Array<NativeElement> = renderBlockContainerChildren();	
				
			for (i in 0...blockContainerChildren.length)
			{
				nativeElements.push(blockContainerChildren[i]);
			}
			
			//TODO here : render non-positioned float
			
			//TODO here : render block-level replaced elements
			
			//render all the line boxes belonging to this layer
			var lineBoxesChildren:Array<NativeElement> = renderLineBoxes();
			
			for (i in 0...lineBoxesChildren.length)
			{
				nativeElements.push(lineBoxesChildren[i]);
			}
			
			//render all the child layers with a z-index of 0
			var childLayers:Array<NativeElement> = renderChildLayer();

			for (i in 0...childLayers.length)
			{
				nativeElements.push(childLayers[i]);
			}
			
			#if (flash9 || nme)
			
			//if the root renderer establishes a new formatting context, then
			//its bounds must be added to all of its children to transform
			//them to the space of this layer
			if (_rootRenderer.establishesNewFormattingContext() == true)
			{
				for (i in 0...nativeElements.length)
				{
					nativeElements[i].x += _rootRenderer.bounds.x;
					nativeElements[i].y += _rootRenderer.bounds.y;
				}
				
				//TODO : hack to place back the background of the root layer renderer
				//as it is already placed when the background is created.
				for (i in 0...rootRendererElements.length)
				{
					rootRendererElements[i].x -= _rootRenderer.bounds.x;
					rootRendererElements[i].y -= _rootRenderer.bounds.y; 
				}
			}
		}
		
		//here the root renderer is an inline box renderer which doesn't establish a formatting context
		else if (_rootRenderer.canHaveChildren() == true && _rootRenderer.isInlineLevel() == true)
		{
			//TODO
			var lineBoxesChildren:Array<NativeElement> = renderInlineBoxRenderer();
			for (i in 0...lineBoxesChildren.length)
			{
				nativeElements.push(lineBoxesChildren[i]);
			}
		}
		
		//here the root renderer is a replaced element
		else
		{
			//render the replaced element, render its background and asset
			
			var rootRendererElements:Array<NativeElement> = _rootRenderer.render();
			for (i in 0...rootRendererElements.length)
			{
				nativeElements.push(rootRendererElements[i]);
			}
		}
		
		//TODO : Test here if layer is fixed too ? In which case native elements are set to x, y of window
		//
		//if the root renderer is relatively positioned,
		//then its offset must be applied to all of 
		//its children
		if (_rootRenderer.coreStyle.isRelativePositioned() == true)
		{
			for (i in 0...nativeElements.length)
			{
				
				//first try to apply the left offset of the root renderer if it is
				//not auto
				if (_rootRenderer.coreStyle.left != PositionOffset.cssAuto)
				{
					nativeElements[i].x += _rootRenderer.coreStyle.computedStyle.left;
				}
				//else the right offset,
				else if (_rootRenderer.coreStyle.right != PositionOffset.cssAuto)
				{
					nativeElements[i].x -= _rootRenderer.coreStyle.computedStyle.right;
				}
				
				//if both left and right offset is auto, then the root renderer uses its static
				//position (its normal position in the flow) and no offset needs to be applied
				//to its children
			
				//same for vertical offset
				if (_rootRenderer.coreStyle.top != PositionOffset.cssAuto)
				{
					nativeElements[i].y += _rootRenderer.coreStyle.computedStyle.top; 
				}
				else if (_rootRenderer.coreStyle.bottom != PositionOffset.cssAuto)
				{
					nativeElements[i].y -= _rootRenderer.coreStyle.computedStyle.bottom; 
				}
			}
		}
		
		//if the root renderer is absolutely positioned, then an offset might be applied
		//to its all its children
		else if (_rootRenderer.coreStyle.isPositioned() == true && _rootRenderer.coreStyle.isRelativePositioned() == false)
		{
			for (i in 0...nativeElements.length)
			{
				//if the left or right style is defined on the root renderer, then it doesn"t use its static position
				//in this direction, and an offset must be applied to all the children
				if (_rootRenderer.coreStyle.left != PositionOffset.cssAuto || _rootRenderer.coreStyle.right != PositionOffset.cssAuto)
				{
					nativeElements[i].x += _rootRenderer.coreStyle.computedStyle.marginLeft;
				}
				
				//for vertical offset, the same rule as horizontal offsets apply
				if (_rootRenderer.coreStyle.top != PositionOffset.cssAuto || _rootRenderer.coreStyle.bottom != PositionOffset.cssAuto)
				{
					nativeElements[i].y += _rootRenderer.coreStyle.computedStyle.marginTop;
				}
			}
		}
		
		#end
		
		
		return nativeElements;
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Render all the block container children of the layer
	 */
	private function renderBlockContainerChildren():Array<NativeElement>
	{
		var childrenBlockContainer:Array<ElementRenderer> = getBlockContainerChildren(cast(_rootRenderer));
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...childrenBlockContainer.length)
		{
			var nativeElements:Array<NativeElement> = childrenBlockContainer[i].render();
			
			for (j in 0...nativeElements.length)
			{
				ret.push(nativeElements[j]);
			}
		}
		return ret;
	}
	
	/**
	 * Retrieve all the children block container of this LayerRenderer by traversing
	 * recursively the rendering tree.
	 * 
	 * TODO : would also return the InlineBoxRenderer if they were attached to the
	 * rendering tree as they should
	 */
	private function getBlockContainerChildren(rootRenderer:FlowBoxRenderer):Array<ElementRenderer>
	{
		var ret:Array<ElementRenderer> = new Array<ElementRenderer>();
		
		for (i in 0...rootRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(rootRenderer.childNodes[i]);
			
			if (child.layerRenderer == this)
			{
				//TODO : must add more condition, for instance, no float
				if (child.canHaveChildren() == true && child.coreStyle.display != inlineBlock)
				{
					ret.push(cast(child));
					
					var childElementRenderer:Array<ElementRenderer> = getBlockContainerChildren(cast(child));
					
					for (j in 0...childElementRenderer.length)
					{
						ret.push(childElementRenderer[j]);
					}
				}
			}
		}
		return ret;
	}
	
	/**
	 * Render all the children LayerRenderer of this LayerRenderer
	 * and return an array of NativeElements from it
	 */
	private function renderChildLayer():Array<NativeElement>
	{
		var childLayers:Array<LayerRenderer> = getChildLayers(cast(_rootRenderer), this);
		
		//TODO : shouldn't have to do that
		childLayers.reverse();
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...childLayers.length)
		{
			var nativeElements:Array<NativeElement> = childLayers[i].render();
			for (j in 0...nativeElements.length)
			{
				ret.push(nativeElements[j]);
			}
		}
		
		return ret;
	}
	
	/**
	 * Retrieve all the children LayerRenderer of this LayerRenderer by traversing
	 * recursively the rendering tree.
	 */
	private function getChildLayers(rootRenderer:FlowBoxRenderer, referenceLayer:LayerRenderer):Array<LayerRenderer>
	{
		var childLayers:Array<LayerRenderer> = new Array<LayerRenderer>();
		
		//loop in all the children of the root renderer of this LayerRenderer
		for (i in 0...rootRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(rootRenderer.childNodes[i]);
			
			//if the child uses this layer
			if (child.layerRenderer == referenceLayer)
			{
				//if it can have children, recursively search for children layerRenderer
				if (child.canHaveChildren() == true && child.coreStyle.display != inlineBlock)
				{
					var childElementRenderer:Array<LayerRenderer> = getChildLayers(cast(child), referenceLayer);
					
					for (j in 0...childElementRenderer.length)
					{
						if (child.establishesNewFormattingContext() == true)
						{
							childElementRenderer[j].rootRenderer.bounds.x += child.bounds.x;
							childElementRenderer[j].rootRenderer.bounds.y += child.bounds.y;
						}
						
						childLayers.push(childElementRenderer[j]);
					}
				}
			}
			//if the child has a different LayerRenderer, store it in the childLayers array
			else
			{
				childLayers.push(child.layerRenderer);
			}
		}
		
		return childLayers;
	}
	
	private function renderInlineBoxRenderer():Array<NativeElement>
	{
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0..._rootRenderer.lineBoxes.length)
		{
			var childLineBoxes:Array<LineBox> = getLineBoxesInLine(_rootRenderer.lineBoxes[i]);
			
			for (j in 0...childLineBoxes.length)
			{
				if (childLineBoxes[j].layerRenderer == this)
				{
					var lineBoxNativeElements:Array<NativeElement> = childLineBoxes[j].render();
					for (k in 0...lineBoxNativeElements.length)
					{
						#if (flash9 || nme)
						lineBoxNativeElements[k].x += _rootRenderer.bounds.x;
						lineBoxNativeElements[k].y += _rootRenderer.bounds.y;
						#end
						
						ret.push(lineBoxNativeElements[k]);
					}
				}
				
			}
		}
		
		return ret;
	}
	
	/**
	 * Render all the in flow children (not positioned) using
	 * this LayerRenderer and return an array of NativeElement
	 * from it
	 */
	private function renderLineBoxes():Array<NativeElement>
	{
		var lineBoxes:Array<LineBox> = getLineBoxes(cast(_rootRenderer));
		
		var ret:Array<NativeElement> = new Array<NativeElement>();
		
		for (i in 0...lineBoxes.length)
		{
			var nativeElements:Array<NativeElement> = [];
			
			nativeElements = lineBoxes[i].render();
			
			for (j in 0...nativeElements.length)
			{
				ret.push(nativeElements[j]);
			}
		}
		
		return ret;
	}
	
	
	/**
	 * Return all the in flow children of this LayerRenderer by traversing
	 * recursively the rendering tree
	 */
	private function getLineBoxes(rootRenderer:FlowBoxRenderer):Array<LineBox>
	{
		var ret:Array<LineBox> = new Array<LineBox>();
		
		if (rootRenderer.establishesNewFormattingContext() == true && rootRenderer.coreStyle.childrenInline() == true)
		{
			var blockBoxRenderer:BlockBoxRenderer = cast(rootRenderer);
			
			for (i in 0...blockBoxRenderer.lineBoxes.length)
			{
				var lineBoxes:Array<LineBox> = getLineBoxesInLine(blockBoxRenderer.lineBoxes[i]);
				for (j in 0...lineBoxes.length)
				{
					if (lineBoxes[j].layerRenderer == this)
					{
						ret.push(lineBoxes[j]);
					}
				}
			}
		}
		else
		{
			for (i in 0...rootRenderer.childNodes.length)
			{
				var child:ElementRenderer = cast(rootRenderer.childNodes[i]);
				
				if (child.isDisplayed() == true)
				{
					if (child.layerRenderer == this)
					{
						if (child.isPositioned() == false)
						{	
							if (child.canHaveChildren() == true)
							{	
								var childLineBoxes:Array<LineBox> = getLineBoxes(cast(child));
								for (j in 0...childLineBoxes.length)
								{
									if (child.establishesNewFormattingContext() == true)
									{
										childLineBoxes[j].bounds.x += child.bounds.x;
										childLineBoxes[j].bounds.y += child.bounds.y;
									}
								
									ret.push(childLineBoxes[j]);
								}
							}
						}
					}
				}

			}
		}
		
		return ret;
	}
	
	private function getLineBoxesInLine(rootLineBox:LineBox):Array<LineBox>
	{
		var ret:Array<LineBox> = new Array<LineBox>();
		
		for (i in 0...rootLineBox.childNodes.length)
		{
			ret.push(cast(rootLineBox.childNodes[i]));
			
			if (rootLineBox.childNodes[i].hasChildNodes() == true)
			{
				var childLineBoxes:Array<LineBox> = getLineBoxesInLine(cast(rootLineBox.childNodes[i]));
				for (j in 0...childLineBoxes.length)
				{
					ret.push(childLineBoxes[j]);
				}
			}
		}
		
		return ret;
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
	
	private function get_rootRenderer():ElementRenderer
	{
		return _rootRenderer;
	}
	
}