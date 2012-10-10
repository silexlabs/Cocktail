/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.formatter;

using cocktail.core.utils.Utils;

import cocktail.core.dom.Node;
import cocktail.core.layout.floats.FloatsManager;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.css.CSSData;
import cocktail.core.renderer.ElementRenderer;
import haxe.Log;

/**
 * This formatting context layout HTMLElement below each other
 * generally following the formattable tree order.
 * 
 * There might be exception, for instance if a container HTMLElement
 * with a fixed has overflowing children, its siblings will use
 * the height of the container to be positioned below, not the
 * added height of its children.
 * 
 * @author Yannick DOMINGUEZ
 */
class BlockFormattingContext extends FormattingContext
{
	
	private var _registeredFloats:Array<FloatVO>;
	
	/**
	 * A reference to an instance of the class laying out
	 * inline element. It is passed by reference instead
	 * of being instantiated each time, this way,
	 * only one instance is needed for each Document
	 */ 
	private var _inlineFormattingContext:InlineFormattingContext;
	
	/**
	 * class constructor
	 */
	public function new(inlineFormattingContext:InlineFormattingContext, floatsManager:FloatsManager) 
	{
		super(floatsManager);
		_inlineFormattingContext = inlineFormattingContext;
		_registeredFloats = new Array<FloatVO>();
	}
	
	override private function startFormatting():Void
	{
		//remove margin of formatting context, as child must be placed relative to padding box
		doFormat(_formattingContextRoot, - _formattingContextRoot.coreStyle.usedValues.marginLeft, - _formattingContextRoot.coreStyle.usedValues.marginTop, 0, _formattingContextRoot.coreStyle.usedValues.marginTop,  _formattingContextRoot.coreStyle.usedValues.marginBottom);
	}
	
	//TODO 1 : should be on FloatManager
	private function isFloatRegistered(child:ElementRenderer):Bool
	{
		var length:Int = _registeredFloats.length;
		for (i in 0...length)
		{
			if (_registeredFloats[i].node == child)
			{
				return true;
			}
		}
		
		return false;
	}
	
	private function getRegisteredFloat(child:ElementRenderer):FloatVO
	{
		var length:Int = _registeredFloats.length;
		for (i in 0...length)
		{
			if (_registeredFloats[i].node == child)
			{
				return _registeredFloats[i];
			}
		}
		
		return null;
	}
	
	private function doFormat(elementRenderer:ElementRenderer, concatenatedX:Float, concatenatedY:Float, currentLineY:Float, parentCollapsedMarginTop:Float, parentCollapsedMarginBottom:Float):Float
	{
		var elementRendererUsedValues:UsedValuesVO = elementRenderer.coreStyle.usedValues;
		
		concatenatedX += elementRendererUsedValues.paddingLeft  + elementRendererUsedValues.marginLeft;

		concatenatedY += elementRendererUsedValues.paddingTop + parentCollapsedMarginTop;
		
		var childHeight:Float = concatenatedY;
		
		var child:ElementRenderer = elementRenderer.firstChild;
		while(child != null)
		{
			var marginTop:Float = getCollapsedMarginTop(child, parentCollapsedMarginTop);
			var marginBottom:Float = getCollapsedMarginBottom(child, parentCollapsedMarginBottom);
			
			var usedValues:UsedValuesVO = child.coreStyle.usedValues;
			var width:Float = usedValues.width + usedValues.paddingLeft + usedValues.paddingRight;
			var height:Float = usedValues.height + usedValues.paddingTop + usedValues.paddingBottom;
			
			var x:Float = concatenatedX + child.coreStyle.usedValues.marginLeft;
			var y:Float = concatenatedY + marginTop;
			
			var childBounds:RectangleVO = child.bounds;
			childBounds.x = x;
			childBounds.y = y;
			childBounds.width = width;
			childBounds.height = height;
			
			if (child.isFloat() == true)
			{
				//TODO 1 : floats should use currentLineY instead, else, if a floated
				//element is declared after an inline one, it won't be on the right line
				if (isFloatRegistered(child) == false)
				{
					var floatBounds:RectangleVO = _floatsManager.registerFloat(child, concatenatedY, 0, elementRendererUsedValues.width);
					_registeredFloats.push(new FloatVO(child, floatBounds));
					
					format(_formattingContextRoot, false);
					return 0.0;
				}
				
				var floatBounds:RectangleVO = getRegisteredFloat(child).bounds;
				
				childBounds.x = floatBounds.x + usedValues.marginLeft;
				childBounds.y = floatBounds.y + usedValues.marginTop;
				childBounds.x += concatenatedX;
				
			}
			//for child with children of their own, their padding and margin are added at
			//the beginning of the recursive method
			else if (child.firstChild != null)
			{
				//children starting their own formatting context are not laid out
				//by this formatting context
				if (child.establishesNewFormattingContext() == false)
				{
					currentLineY = child.bounds.y;
					concatenatedY = doFormat(child, concatenatedX, concatenatedY, currentLineY, marginTop, marginBottom);
				}
				else 
				{
					if ((child.isPositioned() == false || child.isRelativePositioned() == true) && child.isFloat() == false)
					{
						//TODO 1 : doc, now block formatting context in charge of formatting line
						//boxes, because of floats
						if (child.childrenInline() == true)
						{
							_inlineFormattingContext.format(cast(child), false);
						}				
		
						currentLineY = child.bounds.y;
						concatenatedY += child.bounds.height + marginTop + marginBottom;
					}
				}
			}
			//for absolutely positioned element, their bounds are set to their static position
			//but they do not influence the formatting of subsequent children or sibling
			else if (child.isPositioned() == false || child.isRelativePositioned() == true)
			{
				concatenatedY += child.bounds.height + marginTop + marginBottom;
			}
			
			//find widest line for shrink-to-fit algorithm
			if (childBounds.x + childBounds.width + usedValues.marginRight > _formattingContextData.width)
			{
				//anonymous block box are not taken into account, as they always
				//have an auto width, they might cause error in the shrink-to-fit
				//computation, for instance if they take the width of the formatting
				//context root, it won't have the right max width
				if (child.isAnonymousBlockBox() == false)
				{
					_formattingContextData.width = childBounds.x + childBounds.width + usedValues.marginRight;
				}
			}
			
			if (concatenatedY  > _formattingContextData.height)
			{
				_formattingContextData.height = concatenatedY;
			}
			
			child = child.nextSibling;
		}
		
		//the current ElementRenderer can either have an auto height
		//or have an explicit height
		if (elementRenderer.coreStyle.isAuto(elementRenderer.coreStyle.height) == true)
		{
			//when it has an auto height, it uses the height of its children
			childHeight = concatenatedY - childHeight;
			elementRenderer.bounds.height = childHeight + elementRendererUsedValues.paddingBottom + elementRendererUsedValues.paddingTop ;
			elementRendererUsedValues.height = childHeight;
		}
		else
		{
			//here it has an explicit height, so it adds its own height
			//instead of the hieght of its children, if it children are
			//taller, they will overflow
			concatenatedY = childHeight;
			concatenatedY += elementRenderer.bounds.height;
		}
		
		concatenatedY += elementRendererUsedValues.paddingBottom + parentCollapsedMarginBottom;
		
		_floatsManager.removeFloats(concatenatedY);
		
		_registeredFloats.clear();
		
		return concatenatedY;
		
	}
	
	private function getCollapsedMarginTop(child:ElementRenderer, parentCollapsedMarginTop:Float):Float
	{
		var childUsedValues:UsedValuesVO = child.coreStyle.usedValues;
		
		var marginTop:Float = childUsedValues.marginTop;

		if (childUsedValues.paddingTop == 0)
		{
			if (child.previousSibling != null)
			{
				var previousSibling:ElementRenderer = child.previousSibling;
				var previsousSiblingUsedValues:UsedValuesVO = previousSibling.coreStyle.usedValues;
				if (previsousSiblingUsedValues.paddingBottom == 0)
				{
					if (previsousSiblingUsedValues.marginBottom > marginTop)
					{
						//this an exception for negative margin whose height are substracted
						//from collapsed margin height
						if (marginTop > 0)
						{
							marginTop = 0;
						}
					}
				}
			}
			else if (child.parentNode != null)
			{
				var parent:ElementRenderer = child.parentNode;
				
				if (parent.establishesNewFormattingContext() == false)
				{
					if (parent.coreStyle.usedValues.paddingTop == 0)
					{
						if (parentCollapsedMarginTop > marginTop)
						{
							marginTop = 0;
						}
					}
				}
			}
		}
		
		return marginTop;
	}
	
	private function getCollapsedMarginBottom(child:ElementRenderer, parentCollapsedMarginBottom:Float):Float
	{
		var childUsedValues:UsedValuesVO = child.coreStyle.usedValues;
		var marginBottom:Float = childUsedValues.marginBottom;
		
		if (childUsedValues.paddingBottom == 0)
		{
			if (child.nextSibling != null)
			{
				var nextSibling:ElementRenderer = child.nextSibling;
				var nextSiblingUsedValues:UsedValuesVO = nextSibling.coreStyle.usedValues;
				if (nextSiblingUsedValues.paddingTop == 0)
				{
					if (nextSiblingUsedValues.marginTop > marginBottom)
					{
						marginBottom = 0;
					}
				}
			}
			else if (child.parentNode != null)
			{
				var parent:ElementRenderer = child.parentNode;
				
				if (parent.establishesNewFormattingContext() == false)
				{
					if (parent.coreStyle.usedValues.paddingBottom == 0)
					{
						if (parentCollapsedMarginBottom > marginBottom)
						{
							marginBottom = 0;
						}
					}
				}
			}
		}
		
		return marginBottom;
	}
	
}