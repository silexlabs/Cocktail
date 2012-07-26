/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer.boxComputers;

import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import haxe.Log;

/**
 * This is the box computer for non-replaced
 * absolutely positioned HTMLElement, such as
 * an absolutely positioned ContainerHTMLElement
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
	// OVERRIDEN PRIVATE MEASURE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to prevent computing left, right,
	 * top and bottom which in this case are computed in the 
	 * width and height methods
	 */
	override private function measurePositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		
	}
	
	// HORIZONTAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also left, right and the horizontal margins when an
	 * auto width is computed. Left and right might be computed in the shrink-to-fit
	 * method if they are defined as auto
	 */ 
	override private function measureAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		var computedStyle:ComputedStyle = style.computedStyle;
		
		var computedWidth:Float = 0.0;
		
		//first, any auto value for margins are computed to 0
		if (style.marginLeft == Margin.cssAuto)
		{
			computedStyle.marginLeft = 0;
		}
		else
		{
			computedStyle.marginLeft = getComputedMarginLeft(style, computedWidth, containingBlockData, fontMetrics);
		}
		
		if (style.marginRight == Margin.cssAuto)
		{
			computedStyle.marginRight = 0;
		}
		else
		{
			computedStyle.marginRight = getComputedMarginRight(style, computedWidth, containingBlockData, fontMetrics);
		}
		
		//if neither left or right are auto but width is
		if (style.left != PositionOffset.cssAuto && style.right != PositionOffset.cssAuto)
		{
			//left and right are computed as they are defined either as length or percentage
			computedStyle.left = getComputedPositionOffset(style.left, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			computedStyle.right = getComputedPositionOffset(style.right, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			
			//the computed width is deduced from all the other computed horizontal values. It is the remaining space when all the other value
			//are substracted from the containing HTMLElement width
			computedWidth = containingBlockData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
		}
		//if width is auto and left, right or both are auto, then the width will be "shrinked-to-fit" once all the children have been laid out,
		//so the width is first set to the containing block width width which will allow to find the max line width of the formatted children
		//used by the shrink-to-fit method during formatting
		else
		{
			//if only left is auto, compute right then deduce left from the remaining horizontal space
			//TODO 4 : left is not actually computed yet, it must be computed during shrink-to-fit
			if (style.left == PositionOffset.cssAuto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			}
			//same for right
			else if(style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			}
			
			//TODO 2 : setting the containing element width is a hack which will not
			//always work. The shrink to fit computation of this class needs to be 
			//improved
			computedWidth = containingBlockData.width;
		}
		
		return computedWidth;
	}
	
	/**
	 * overriden to also compute left and right style
	 */
	override private function measureWidth(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		var computedStyle:ComputedStyle = style.computedStyle;
		
		//compute the width which is either defined as a length or a percentage
		var computedWidth:Float = getComputedWidth(style, containingBlockData, fontMetrics);

		//if neither left nor right are defined as auto
		if (style.left != PositionOffset.cssAuto && style.right != PositionOffset.cssAuto)
		{
			//compute left and right defined either as length or percentage
			style.computedStyle.left = getComputedPositionOffset(style.left, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			
			//if both margin are auto, they will take the same size
			if (style.marginLeft == Margin.cssAuto && style.marginRight == Margin.cssAuto)
			{
				//compute the size of one of the margin, which is half the remaining horizontal space
				//once all other values (padding, width, offset) are remove
				var computedMargin:Float = (containingBlockData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right) / 2;
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginLeft = computedMargin;
					style.computedStyle.marginRight = computedMargin;
				}
				//if the margin width is negative, it is recomputed
				else
				{
					style.computedStyle.marginLeft = 0;
					style.computedStyle.marginRight = containingBlockData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right;
				}
			
			}
			//if only margin left is auto
			else if (style.marginLeft == Margin.cssAuto)
			{
				//compute margin right then deduce margin left from the remaining horizontal
				//space
				style.computedStyle.marginRight = getComputedMarginRight(style, computedWidth, containingBlockData, fontMetrics);
				style.computedStyle.marginLeft = containingBlockData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			}
			//same if only margin right is auto
			else if (style.marginRight == Margin.cssAuto)
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, computedWidth, containingBlockData, fontMetrics);
				style.computedStyle.marginRight = containingBlockData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			}
			//else if no margins are auto, compute them
			else
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, computedWidth, containingBlockData, fontMetrics);
				style.computedStyle.marginRight = getComputedMarginRight(style, computedWidth, containingBlockData, fontMetrics);
			}
		}
		//if either left or right is auto
		else
		{
			//any auto margin computes to 0
			if (style.marginLeft == Margin.cssAuto)
			{
				style.computedStyle.marginLeft = 0;
			}
			else
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, computedWidth, containingBlockData, fontMetrics);
			}
			
			if (style.marginRight == Margin.cssAuto)
			{
				style.computedStyle.marginRight = 0;
			}
			else
			{
				style.computedStyle.marginRight = getComputedMarginRight(style, computedWidth, containingBlockData, fontMetrics);
			}
			
			//if left and right are both auto, the statc position of left is used, then right is computed
			if (style.left == PositionOffset.cssAuto && style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingBlockData);
				style.computedStyle.right = containingBlockData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only left is auto, compute right then deduce left from the remaining horizontal space
			else if (style.left == PositionOffset.cssAuto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.left = containingBlockData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
			//same for right
			else if(style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.right = containingBlockData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
		}
		
		return computedWidth;
	}
	
	// VERTICAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also top, bottom and the vertical margins when an
	 * auto height is computed.
	 */ 
	override private function measureAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		var computedStyle:ComputedStyle = style.computedStyle;
		
		var computedHeight:Float = 0.0;
		
		//first, any auto value for margins are computed to 0
		if (style.marginTop == Margin.cssAuto)
		{
			style.computedStyle.marginTop = 0;
		}
		else
		{
			style.computedStyle.marginTop = getComputedMarginTop(style, computedHeight, containingBlockData, fontMetrics);
		}
		
		if (style.marginBottom == Margin.cssAuto)
		{
			style.computedStyle.marginBottom = 0;
		}
		else
		{
			style.computedStyle.marginBottom = getComputedMarginBottom(style, computedHeight, containingBlockData, fontMetrics);
		}
		
		//if neither top or bottom are auto but height is
		if (style.top != PositionOffset.cssAuto && style.bottom != PositionOffset.cssAuto)
		{
			//top and bottom are computed as they are defined either as length or percentage
			style.computedStyle.top = getComputedPositionOffset(style.top, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			
			//the computed height is deduced from all the other computed vertical values. It is the remaining space when all the other value
			//are substracted from the containing HTMLElement height
			computedHeight = containingBlockData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom;
		}
		//if only bottom is auto, compute top then deduce bottom from the remaining vertical space
		else if (style.bottom == PositionOffset.cssAuto)
		{
			style.computedStyle.top = getComputedPositionOffset(style.top, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.bottom = containingBlockData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
		}
		//same for top
		else if(style.top == PositionOffset.cssAuto)
		{
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.top = containingBlockData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
		}

		//if top or bottom are auto, then the height will be computed once the layout
		//of the HTMLElement children is done
		return computedHeight;
	}
	
	/**
	 * overriden to also compute top and bottom style
	 */
	override private function measureHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		var computedStyle:ComputedStyle = style.computedStyle;
		
		//compute the height which is either defined as a length or a percentage
		var computedHeight:Float = getComputedHeight(style, containingBlockData, fontMetrics);
		
		//if neither top nor bottom are defined as auto
		if (style.top != PositionOffset.cssAuto && style.bottom != PositionOffset.cssAuto)
		{
			//compute top and bottom defined either as length or percentage
			style.computedStyle.top = getComputedPositionOffset(style.top, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			
			//if both margin are auto, they will take the same size
			if (style.marginTop == Margin.cssAuto && style.marginBottom == Margin.cssAuto)
			{
				//compute the size of one of the margin, which is half the remaining vertical space
				//once all other values (padding, width, offset) are removed
				var computedMargin:Float = (containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2;
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginTop = computedMargin;
					style.computedStyle.marginBottom = computedMargin;
				}
				//if the margin height is negative, it is recomputed
				else
				{
					style.computedStyle.marginBottom = 0;
					style.computedStyle.marginTop = containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom - computedStyle.top;
				}
			
			}
			//if only margin top is auto
			else if (style.marginTop == Margin.cssAuto)
			{
				//compute margin top then deduce margin bottom from the remaining vertical
				//space
				style.computedStyle.marginBottom = getComputedMarginBottom(style, computedHeight, containingBlockData, fontMetrics);
				style.computedStyle.marginTop = containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			}
			//same if only margin bottom is auto
			else if (style.marginBottom == Margin.cssAuto)
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, computedHeight, containingBlockData, fontMetrics);
				style.computedStyle.marginBottom = containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			}
			//else if no margins are auto, compute them
			else
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, computedHeight, containingBlockData, fontMetrics);
				style.computedStyle.marginBottom = getComputedMarginBottom(style, computedHeight, containingBlockData, fontMetrics);
			}
		}
		//if either top or bottom is auto
		else
		{
			//any auto margin computes to 0
			if (style.marginTop == Margin.cssAuto)
			{
				style.computedStyle.marginTop = 0;
			}
			else
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, computedHeight, containingBlockData, fontMetrics);
			}
			
			if (style.marginBottom == Margin.cssAuto)
			{
				style.computedStyle.marginBottom = 0;
			}
			else
			{
				style.computedStyle.marginBottom = getComputedMarginBottom(style, computedHeight, containingBlockData, fontMetrics);
			}
		
			//if top and bottom are both auto, the static position of top is used, then bottom is computed
			if (style.top == PositionOffset.cssAuto && style.bottom == PositionOffset.cssAuto)
			{
				style.computedStyle.top = getComputedStaticTop(style, containingBlockData);
				style.computedStyle.bottom = containingBlockData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			//if only bottom is auto, compute top then deduce bottom from the remaining vertical space
			else if (style.bottom == PositionOffset.cssAuto)
			{
				
				style.computedStyle.top = getComputedPositionOffset(style.top, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.bottom = containingBlockData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			//same for top
			else if(style.top == PositionOffset.cssAuto)
			{
				
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.top = containingBlockData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
			}
		}
		
		return computedHeight;
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * compute the static value for left which is the value that will place the left margin edge
	 * of the HTMLElement to the left edge of its containing HTMLElement
	 */
	private function getComputedStaticLeft(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		return style.computedStyle.marginLeft;
	}
	
	/**
	 * compute the static value for top which is the value that will place the top margin edge
	 * of the HTMLElement to the top edge of its containing HTMLElement
	 */
	private function getComputedStaticTop(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		return style.computedStyle.marginTop;
	}
}