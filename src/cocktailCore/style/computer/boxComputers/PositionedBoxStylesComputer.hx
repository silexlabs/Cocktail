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
import cocktailCore.style.StyleData;
import haxe.Log;

/**
 * This is the box computer for non-replaced
 * absolutely positioned DOMElement, such as
 * an absolutely positioned ContainerDOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class PositionedBoxStylesComputer extends BoxStylesComputer
{

	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * if the width is set to 'auto', then this method is called and might shrink the
	 * width of the DOMElement to fit its content
	 */
	override public function shrinkToFit(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		var shrinkedWidth:Int;
		
		//shrink-to-fit only happen if either left or right is auto
		if (style.left == PositionOffsetStyleValue.auto || style.right == PositionOffsetStyleValue.auto)
		{
			var computedStyle:ComputedStyleData = style.computedStyle;
			//compute the shrinked width
			shrinkedWidth = doShrinkToFit(style, containingDOMElementData, minimumWidth);
			
			//if both right and left are auto, use left static position, then deduce right
			if (style.left == PositionOffsetStyleValue.auto && style.right == PositionOffsetStyleValue.auto)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingDOMElementData);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only right is auto, compute left then deduce right
			else if (style.right == PositionOffsetStyleValue.auto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//same for left
			else if (style.left == PositionOffsetStyleValue.auto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.left = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
		}
		//here the width is not shrinked
		else
		{
			shrinkedWidth = style.computedStyle.width;
		}
		
		return shrinkedWidth;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE MEASURE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to prevent computing left, right,
	 * top and bottom which in this case are computed in the 
	 * width and height methods
	 */
	override private function measurePositionOffsets(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		
	}
	
	// HORIZONTAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also left, right and the horizontal margins when an
	 * auto width is computed. Left and right might be computed in the shrink-to-fit
	 * method if they are defined as auto
	 */ 
	override private function measureAutoWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//first, any auto value for margins are computed to 0
		if (style.marginLeft == MarginStyleValue.auto)
		{
			style.computedStyle.marginLeft = 0;
		}
		else
		{
			style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
		}
		
		if (style.marginRight == MarginStyleValue.auto)
		{
			style.computedStyle.marginRight = 0;
		}
		else
		{
			style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
		}
		
		//if neither left or right are auto but width is
		if (style.left != PositionOffsetStyleValue.auto && style.right != PositionOffsetStyleValue.auto)
		{
			//left and right are computed as they are defined either as length or percentage
			style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//the computed width is deduced from all the other computed horizontal values. It is the remaining space when all the other value
			//are substracted from the containing DOMElement width
			style.computedStyle.width = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
		}
	}
	
	/**
	 * overriden to also compute left and right style
	 */
	override private function measureWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//compute the width which is either defined as a length or a percentage
		style.computedStyle.width = getComputedWidth(style, containingDOMElementData);
		
		//if neither left nor right are defined as auto
		if (style.left != PositionOffsetStyleValue.auto && style.right != PositionOffsetStyleValue.auto)
		{
			//compute left and right defined either as length or percentage
			style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//if both margin are auto, they will take the same size
			if (style.marginLeft == MarginStyleValue.auto && style.marginRight == MarginStyleValue.auto)
			{
				//compute the size of one of the margin, which is the remaining horizontal space
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
					style.computedStyle.marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
				}
			
			}
			//if only margin left is auto
			else if (style.marginLeft == MarginStyleValue.auto)
			{
				//compute margin right then deduce margin left from the remaining horizontal
				//space
				style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
				style.computedStyle.marginLeft = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			}
			//same if only margin right is auto
			else if (style.marginRight == MarginStyleValue.auto)
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
				style.computedStyle.marginRight = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			}
			//else if no margins are auto, compute them
			else
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
				style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
			}
		}
		//if either left or right is auto
		else
		{
			//any auto margin computes to 0
			if (style.marginLeft == MarginStyleValue.auto)
			{
				style.computedStyle.marginLeft = 0;
			}
			else
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
			}
			
			if (style.marginRight == MarginStyleValue.auto)
			{
				style.computedStyle.marginRight = 0;
			}
			else
			{
				style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
			}
			
			//if left and right are both auto, the statc position of left is used, then right is computed
			if (style.left == PositionOffsetStyleValue.auto && style.right == PositionOffsetStyleValue.auto)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingDOMElementData);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only left is auto, compute right then deduce left from the remaining horizontal space
			else if (style.left == PositionOffsetStyleValue.auto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.left = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
			//same for right
			else if(style.right == PositionOffsetStyleValue.auto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
		}
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * compute the static value for left which is the value that will place the left margin edge
	 * of the DOMElement to the left edge of its containing DOMElement
	 */
	private function getComputedStaticLeft(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return style.computedStyle.marginLeft;
	}
	
	/**
	 * Actually shrink the width
	 */
	private function doShrinkToFit(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		var shrinkedWidth:Int;
		
		//if the minimum width that must use the inlineBlock
		//is not superior to the width of the containing
		//DOMElement, use the minimum width
		if (minimumWidth < containingDOMElementData.width)
		{
			shrinkedWidth = minimumWidth;
		}
		else
		{
			shrinkedWidth = containingDOMElementData.width;
		}
		return shrinkedWidth;
	}
	
}