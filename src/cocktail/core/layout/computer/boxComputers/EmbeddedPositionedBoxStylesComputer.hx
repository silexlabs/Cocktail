/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.computer.boxComputers;
import cocktail.core.css.CSSStyleDeclaration;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;
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
	override private function measurePositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockVO):Void
	{
		//horizontal position offsets and margins
		measureHorizontalPositionOffsets(style, containingBlockData);
		//vertical position offsets and margins
		measureVerticalPositionOffsets(style, containingBlockData);	
	}
	
	/**
	 * Compute, left, right and marginLeft marginRight styles
	 */
	private function measureHorizontalPositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockVO):Void
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		//if left or right are 'auto'
		if (style.isAuto(style.left) == true || style.isAuto(style.right) == true)
		{
			//any 'auto' margin is set to 0
			if (style.isAuto(style.marginLeft) == true)
			{
				usedValues.marginLeft = 0;
			}
			if (style.isAuto(style.marginRight) == true)
			{
				usedValues.marginRight = 0;
			}
			
			//if both left and right are 'auto', left is its static posittion, then right is deduced from the other values
			if (style.isAuto(style.left) == true && style.isAuto(style.right) == true)
			{
				usedValues.left = getComputedStaticLeft(style, containingBlockData);
				usedValues.right = containingBlockData.width - usedValues.width - usedValues.marginLeft - usedValues.marginRight - usedValues.paddingLeft - usedValues.paddingRight - usedValues.left;
			}
			//if only left is auto, right is computed then left is deduced
			else if (style.isAuto(style.left) == true)
			{
				usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
				usedValues.left = containingBlockData.width - usedValues.width - usedValues.marginLeft - usedValues.marginRight - usedValues.right - usedValues.paddingLeft - usedValues.paddingRight;
			}
			//same for right
			else if (style.isAuto(style.right) == true)
			{
				usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
				usedValues.right = containingBlockData.width - usedValues.width - usedValues.marginLeft - usedValues.marginRight - usedValues.left - usedValues.paddingLeft - usedValues.paddingRight;
			}
		}
		//if neither left or right are auto
		else 
		{
			//compute left and right
			usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
			usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
			
			//then deduce the margins
			if (style.isAuto(style.marginLeft) == true && style.isAuto(style.marginRight) == true)
			{
				var margin:Float = (containingBlockData.width - usedValues.left - usedValues.right - usedValues.paddingLeft - usedValues.paddingRight) / 2;
				
				//compute the size of one of the margin, which is half the remaining horizontal space
				//once all other values (padding, width, offset) are remove
				var usedMargin:Float = (containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.left - usedValues.right) / 2;
				
				if (usedMargin >= 0)
				{
					usedValues.marginLeft = usedMargin;
					usedValues.marginRight = usedMargin;
				}
				//if the margin width is negative, it is recomputed
				else
				{
					usedValues.marginLeft = 0;
					usedValues.marginRight = containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.left - usedValues.right;
				}
			
				usedValues.marginLeft = 0;
			}
			else if (style.isAuto(style.marginLeft) == true)
			{
				usedValues.marginLeft = containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.left - usedValues.right - usedValues.marginRight;
			}
			else if (style.isAuto(style.marginRight) == true)
			{
				usedValues.marginRight = containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.left - usedValues.right - usedValues.marginLeft;
			}
		}
	}
	
	/**
	 * Compute, top, bottom and marginTop marginBottom styles. Works the same as
	 * measureHorizontalPositionOffsets
	 */
	private function measureVerticalPositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockVO):Void
	{
		var usedValues:UsedValuesVO = style.usedValues;
		
		if (style.isAuto(style.top) == true || style.isAuto(style.bottom) == true)
		{
			if (style.isAuto(style.marginTop) == true)
			{
				usedValues.marginTop = 0;
			}
			if (style.isAuto(style.marginBottom) == true)
			{
				usedValues.marginBottom = 0;
			}
			
			if (style.isAuto(style.top) == true && style.isAuto(style.bottom) == true)
			{
				usedValues.top = getComputedStaticTop(style, containingBlockData);
				usedValues.bottom = containingBlockData.height - usedValues.height - usedValues.marginTop - usedValues.marginBottom - usedValues.paddingTop - usedValues.paddingBottom - usedValues.top;
			}
			
			else if (style.isAuto(style.top) == true)
			{
				usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
				usedValues.top = containingBlockData.height - usedValues.height - usedValues.marginTop - usedValues.marginBottom - usedValues.bottom - usedValues.paddingTop - usedValues.paddingBottom;
			}
			else if (style.isAuto(style.bottom) == true)
			{
				usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
				usedValues.bottom = containingBlockData.height - usedValues.height - usedValues.marginTop - usedValues.marginBottom - usedValues.top - usedValues.paddingTop - usedValues.paddingBottom;
			}
			else
			{
				usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
				usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
			}
		}
	
		else 
		{
			usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
			usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
			
			if (style.isAuto(style.marginTop) == true && style.isAuto(style.marginBottom) == true)
			{
				var margin:Float = (containingBlockData.height - usedValues.top - usedValues.bottom - usedValues.paddingTop - usedValues.paddingBottom) / 2;
				
				var usedMargin:Float = (containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.top - usedValues.bottom) / 2;
				
				if (usedMargin >= 0)
				{
					usedValues.marginTop = usedMargin;
					usedValues.marginBottom = usedMargin;
				}
				else
				{
					usedValues.marginTop = 0;
					usedValues.marginBottom = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.top - usedValues.bottom;
				}
			}
			else if (style.isAuto(style.marginTop) == true)
			{
				usedValues.marginTop = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.top - usedValues.bottom - usedValues.marginBottom;
			}
			else if (style.isAuto(style.marginBottom) == true)
			{
				usedValues.marginBottom = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.top - usedValues.bottom - usedValues.marginTop;
			}
		}
	}
	
	/**
	 * compute the static value for left which is the value that will place the left margin edge
	 * of the HTMLElement to the left edge of its containing HTMLElement
	 */
	private function getComputedStaticLeft(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		return style.usedValues.marginLeft;
	}
	
		/**
	 * compute the static value for top which is the value that will place the top margin edge
	 * of the HTMLElement to the top edge of its containing HTMLElement
	 */
	private function getComputedStaticTop(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		return style.usedValues.marginTop;
	}
	
}