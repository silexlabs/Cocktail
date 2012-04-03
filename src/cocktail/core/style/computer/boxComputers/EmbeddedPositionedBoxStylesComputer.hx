/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer.boxComputers;
import cocktail.core.style.AbstractCoreStyle;
import cocktail.core.style.StyleData;
import haxe.Log;

/**
 * This is the box computer for replaced
 * absolutely positioned HTMLElement, such as
 * an absolutely positioned ImageHTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedPositionedBoxStylesComputer extends EmbeddedBlockBoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Compute the 'position offsets' styles :
	 * top, left, bottom, right. Also compute
	 * the margin as needed
	 */
	override private function measurePositionOffsets(style:AbstractCoreStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		//horizontal position offsets and margins
		measureHorizontalPositionOffsets(style, containingHTMLElementData);
		//vertical position offsets and margins
		measureVerticalPositionOffsets(style, containingHTMLElementData);	
	}
	
	/**
	 * Compute, left, right and marginLeft marginRight styles
	 */
	private function measureHorizontalPositionOffsets(style:AbstractCoreStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
			
		//if left or right are 'auto'
		if (style.left == PositionOffset.cssAuto || style.right == PositionOffset.cssAuto)
		{
			//any 'auto' margin is set to 0
			if (style.marginLeft == Margin.cssAuto)
			{
				style.computedStyle.marginLeft = 0;
			}
			if (style.marginRight == Margin.cssAuto)
			{
				style.computedStyle.marginRight = 0;
			}
			
			//if both left and right are 'auto', left is its static posittion, then right is deduced from the other values
			if (style.left == PositionOffset.cssAuto && style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingHTMLElementData);
				style.computedStyle.right = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only left is auto, right is computed then left is deduced
			else if (style.left == PositionOffset.cssAuto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.left = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
			//same for right
			else if (style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingHTMLElementData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.left - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
		}
		//if neither left or right are auto
		else 
		{
			//compute left and right
			style.computedStyle.left = getComputedPositionOffset(style.left, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//then deduce the margins
			if (style.marginLeft == Margin.cssAuto && style.marginRight == Margin.cssAuto)
			{
				var margin:Int = Math.round((containingHTMLElementData.width - computedStyle.left - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight) / 2);
				
				//compute the size of one of the margin, which is half the remaining horizontal space
				//once all other values (padding, width, offset) are remove
				var computedMargin:Int = Math.round((containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2);
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginLeft = computedMargin;
					style.computedStyle.marginRight = computedMargin;
				}
				//if the margin width is negative, it is recomputed
				else
				{
					style.computedStyle.marginLeft = 0;
					style.computedStyle.marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
			
				style.computedStyle.marginLeft = 0;
			}
			else if (style.marginLeft == Margin.cssAuto)
			{
				style.computedStyle.marginLeft = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			}
			else if (style.marginRight == Margin.cssAuto)
			{
				style.computedStyle.marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			}
		}
	}
	
	/**
	 * Compute, top, bottom and marginTop marginBottom styles. Works the same as
	 * measureHorizontalPositionOffsets
	 */
	private function measureVerticalPositionOffsets(style:AbstractCoreStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		if (style.top == PositionOffset.cssAuto || style.bottom == PositionOffset.cssAuto)
		{
			if (style.marginTop == Margin.cssAuto)
			{
				style.computedStyle.marginTop = 0;
			}
			if (style.marginBottom == Margin.cssAuto)
			{
				style.computedStyle.marginBottom = 0;
			}
			
			if (style.top == PositionOffset.cssAuto && style.bottom == PositionOffset.cssAuto)
			{
				style.computedStyle.top = getComputedStaticTop(style, containingHTMLElementData);
				style.computedStyle.bottom = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			
			else if (style.top == PositionOffset.cssAuto)
			{
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.top = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom;
			}
			else if (style.bottom == PositionOffset.cssAuto)
			{
				style.computedStyle.top = getComputedPositionOffset(style.top, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.bottom = containingHTMLElementData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.top - computedStyle.paddingTop - computedStyle.paddingBottom;
			}
			else
			{
				style.computedStyle.top = getComputedPositionOffset(style.top, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			}
		}
	
		else 
		{
			style.computedStyle.top = getComputedPositionOffset(style.top, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			if (style.marginTop == Margin.cssAuto && style.marginBottom == Margin.cssAuto)
			{
				var margin:Int = Math.round((containingHTMLElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom) / 2);
				
				var computedMargin:Int = Math.round((containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginTop = computedMargin;
					style.computedStyle.marginBottom = computedMargin;
				}
				else
				{
					style.computedStyle.marginTop = 0;
					style.computedStyle.marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom;
				}
			}
			else if (style.marginTop == Margin.cssAuto)
			{
				style.computedStyle.marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			}
			else if (style.marginBottom == Margin.cssAuto)
			{
				style.computedStyle.marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			}
		}
	}
	
	/**
	 * compute the static value for left which is the value that will place the left margin edge
	 * of the HTMLElement to the left edge of its containing HTMLElement
	 */
	private function getComputedStaticLeft(style:AbstractCoreStyle, containingHTMLElementData:ContainingHTMLElementData):Int
	{
		return style.computedStyle.marginLeft;
	}
	
		/**
	 * compute the static value for top which is the value that will place the top margin edge
	 * of the HTMLElement to the top edge of its containing HTMLElement
	 */
	private function getComputedStaticTop(style:AbstractCoreStyle, containingHTMLElementData:ContainingHTMLElementData):Int
	{
		return style.computedStyle.marginTop;
	}
	
}