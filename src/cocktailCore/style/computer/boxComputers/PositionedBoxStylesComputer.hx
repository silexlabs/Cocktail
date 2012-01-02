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
		if (style.left == PositionOffsetStyleValue.autoValue || style.right == PositionOffsetStyleValue.autoValue)
		{
			var computedStyle:ComputedStyleData = style.computedStyle;
			//compute the shrinked width
			shrinkedWidth = doShrinkToFit(style, containingDOMElementData, minimumWidth);
			
			//if both right and left are auto, use left static position, then deduce right
			if (style.left == PositionOffsetStyleValue.autoValue && style.right == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingDOMElementData);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only right is auto, compute left then deduce right
			else if (style.right == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//same for left
			else if (style.left == PositionOffsetStyleValue.autoValue)
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
	
	/**
	 * Overriden as in some cases, depending on the specified value of
	 * top and bottom style, the height used value might not be the children
	 * height of the DOMElement
	 */
	override public function applyContentHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData, childrenHeight:Int):Int
	{
		var height:Int;
		
		//if neither top and bottom are auto, then height can be computed using all the other vertical dimensions
		if (style.top != PositionOffsetStyleValue.autoValue && style.bottom != PositionOffsetStyleValue.autoValue)
		{
			var computedStyle:ComputedStyleData = style.computedStyle;
			height = containingDOMElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
		}
		else
		{
			height = childrenHeight;
		}
		
		return height;
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
		if (style.marginLeft == MarginStyleValue.autoValue)
		{
			style.computedStyle.marginLeft = 0;
		}
		else
		{
			style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
		}
		
		if (style.marginRight == MarginStyleValue.autoValue)
		{
			style.computedStyle.marginRight = 0;
		}
		else
		{
			style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
		}
		
		//if neither left or right are auto but width is
		if (style.left != PositionOffsetStyleValue.autoValue && style.right != PositionOffsetStyleValue.autoValue)
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
		if (style.left != PositionOffsetStyleValue.autoValue && style.right != PositionOffsetStyleValue.autoValue)
		{
			//compute left and right defined either as length or percentage
			style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//if both margin are auto, they will take the same size
			if (style.marginLeft == MarginStyleValue.autoValue && style.marginRight == MarginStyleValue.autoValue)
			{
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
			//if only margin left is auto
			else if (style.marginLeft == MarginStyleValue.autoValue)
			{
				//compute margin right then deduce margin left from the remaining horizontal
				//space
				style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
				style.computedStyle.marginLeft = containingDOMElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			}
			//same if only margin right is auto
			else if (style.marginRight == MarginStyleValue.autoValue)
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
			if (style.marginLeft == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginLeft = 0;
			}
			else
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, containingDOMElementData);
			}
			
			if (style.marginRight == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginRight = 0;
			}
			else
			{
				style.computedStyle.marginRight = getComputedMarginRight(style, containingDOMElementData);
			}
			
			//if left and right are both auto, the statc position of left is used, then right is computed
			if (style.left == PositionOffsetStyleValue.autoValue && style.right == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingDOMElementData);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only left is auto, compute right then deduce left from the remaining horizontal space
			else if (style.left == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.left = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
			//same for right
			else if(style.right == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingDOMElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
		}
	}
	
	// VERTICAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also top, bottom and the vertical margins when an
	 * auto height is computed.
	 */ 
	override private function measureAutoHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//first, any auto value for margins are computed to 0
		if (style.marginTop == MarginStyleValue.autoValue)
		{
			style.computedStyle.marginTop = 0;
		}
		else
		{
			style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementData);
		}
		
		if (style.marginBottom == MarginStyleValue.autoValue)
		{
			style.computedStyle.marginBottom = 0;
		}
		else
		{
			style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementData);
		}
		
		//if neither top or bottom are auto but height is
		if (style.top != PositionOffsetStyleValue.autoValue && style.bottom != PositionOffsetStyleValue.autoValue)
		{
			//top and bottom are computed as they are defined either as length or percentage
			style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//the computed height is deduced from all the other computed vertical values. It is the remaining space when all the other value
			//are substracted from the containing DOMElement height
			style.computedStyle.height = containingDOMElementData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom;
		}
		
		//if top or bottom are auto, then the height will be computed once the layout
		//of the DOMElement children is done
	}
	
	/**
	 * overriden to also compute top and bottom style
	 */
	override private function measureHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//compute the height which is either defined as a length or a percentage
		style.computedStyle.height = getComputedHeight(style, containingDOMElementData);
		
		//if neither top nor bottom are defined as auto
		if (style.top != PositionOffsetStyleValue.autoValue && style.bottom != PositionOffsetStyleValue.autoValue)
		{
			//compute top and bottom defined either as length or percentage
			style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//if both margin are auto, they will take the same size
			if (style.marginTop == MarginStyleValue.autoValue && style.marginBottom == MarginStyleValue.autoValue)
			{
				//compute the size of one of the margin, which is half the remaining vertical space
				//once all other values (padding, width, offset) are removed
				var computedMargin:Int = Math.round((containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginTop = computedMargin;
					style.computedStyle.marginBottom = computedMargin;
				}
				//if the margin height is negative, it is recomputed
				else
				{
					style.computedStyle.marginBottom = 0;
					style.computedStyle.marginTop = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom - computedStyle.top;
				}
			
			}
			//if only margin top is auto
			else if (style.marginTop == MarginStyleValue.autoValue)
			{
				//compute margin top then deduce margin bottom from the remaining vertical
				//space
				style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementData);
				style.computedStyle.marginTop = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			}
			//same if only margin bottom is auto
			else if (style.marginBottom == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementData);
				style.computedStyle.marginBottom = containingDOMElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			}
			//else if no margins are auto, compute them
			else
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementData);
				style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementData);
			}
		}
		//if either top or bottom is auto
		else
		{
			//any auto margin computes to 0
			if (style.marginTop == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginTop = 0;
			}
			else
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, containingDOMElementData);
			}
			
			if (style.marginBottom == MarginStyleValue.autoValue)
			{
				style.computedStyle.marginBottom = 0;
			}
			else
			{
				style.computedStyle.marginBottom = getComputedMarginBottom(style, containingDOMElementData);
			}
			
			//if top and bottom are both auto, the static position of top is used, then bottom is computed
			if (style.top == PositionOffsetStyleValue.autoValue && style.bottom == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.top = getComputedStaticTop(style, containingDOMElementData);
				style.computedStyle.bottom = containingDOMElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			//if only bottom is auto, compute top then deduce bottom from the remaining vertical space
			else if (style.bottom == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.top = getComputedPositionOffset(style.top, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.bottom = containingDOMElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			//same for top
			else if(style.top == PositionOffsetStyleValue.autoValue)
			{
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingDOMElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.top = containingDOMElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
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
	 * compute the static value for top which is the value that will place the top margin edge
	 * of the DOMElement to the top edge of its containing DOMElement
	 */
	private function getComputedStaticTop(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return style.computedStyle.marginTop;
	}
	
	/**
	 * Actually shrink the width
	 */
	private function doShrinkToFit(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		var shrinkedWidth:Int;
		
		//if the minimum width that must use the DOMElement
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