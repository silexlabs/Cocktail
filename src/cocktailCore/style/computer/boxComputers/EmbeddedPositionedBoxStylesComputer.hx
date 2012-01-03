/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer.boxComputers;
import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktail.style.StyleData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class EmbeddedPositionedBoxStylesComputer extends EmbeddedBlockBoxStylesComputer
{

	public function new() 
	{
		super();
	}
	
	/**
	 * Compute the 'position offsets' styles :
	 * top, left, bottom, right, used if the DOMElement
	 * is 'positioned' (position style other than 'static')
	 */
	override private function measurePositionOffsets(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		measureHorizontalPositionOffsets(style, containingDOMElementData);
		measureVerticalPositionOffsets(style, containingDOMElementData);
		
			
		//top
		style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
		
		//bottom
		style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
	}
	
	private function measureHorizontalPositionOffsets(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		if (style.left == PositionOffsetStyleValue.autoValue || style.right == PositionOffsetStyleValue.autoValue)
		{
			if (style.marginLeft == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginLeft = 0;
			}
			if (style.marginRight == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginRight = 0;
			}
			
			if (style.left == PositionOffsetStyleValue.autoValue && style.right == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingDOMElementData);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			
			else if (style.left == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.left = containingDOMElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
			else if (style.right == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.left - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
		}
	
		else 
		{
			style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			if (style.marginLeft == MarginStyleValue.autoValue && style.marginRight == MarginStyleValue.autoValue)
			{
				var margin:Int = Math.round((containingDOMElementData.width - computedStyle.left - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight) / 2);
				
				//compute the size of one of the margin, which is half the remaining horizontal space
				//once all other values (padding, width, offset) are remove
				var computedMargin:Int = Math.round((containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2);
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginLeft = computedMargin;
					style.computedStyle.marginRight = computedMargin;
				}
				//if the margin width is negative, it is recomputed
				else
				{
					style.computedStyle.marginLeft = 0;
					style.computedStyle.marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
			}
			else if (style.marginLeft == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginLeft = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			}
			else if (style.marginRight == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			}
		}
	}
	
	private function measureVerticalPositionOffsets(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		if (style.top == PositionOffsetStyleValue.autoValue || style.bottom == PositionOffsetStyleValue.autoValue)
		{
			if (style.marginTop == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginTop = 0;
			}
			if (style.marginBottom == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginBottom = 0;
			}
			
			if (style.top == PositionOffsetStyleValue.autoValue && style.bottom == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.top = getComputedStaticTop(style, containingDOMElementData);
				style.computedStyle.bottom = containingDOMElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			
			else if (style.top == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.top = containingDOMElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom;
			}
			else if (style.bottom == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.bottom = containingDOMElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.top - computedStyle.paddingTop - computedStyle.paddingBottom;
			}
		}
	
		else 
		{
			style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			if (style.marginTop == MarginStyleValue.autoValue && style.marginBottom == MarginStyleValue.autoValue)
			{
				var margin:Int = Math.round((containingDOMElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom) / 2);
				
				//compute the size of one of the margin, which is half the remaining horizontal space
				//once all other values (padding, width, offset) are remove
				var computedMargin:Int = Math.round((containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginTop = computedMargin;
					style.computedStyle.marginBottom = computedMargin;
				}
				//if the margin width is negative, it is recomputed
				else
				{
					style.computedStyle.marginTop = 0;
					style.computedStyle.marginBottom = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom;
				}
			}
			else if (style.marginTop == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginTop = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			}
			else if (style.marginBottom == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginBottom = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			}
		}
	}
	
	/**
	 * compute the static value for left which is the value that will place the left margin edge
	 * of the DOMElement to the left edge of its containing DOMElement
	 */
	private function getComputedStaticLeft(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return style.computedStyle.marginLeft;
	}
	
		/**
	 * compute the static value for top which is the value that will place the top margin edge
	 * of the DOMElement to the top edge of its containing DOMElement
	 */
	private function getComputedStaticTop(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return style.computedStyle.marginTop;
	}
	
}