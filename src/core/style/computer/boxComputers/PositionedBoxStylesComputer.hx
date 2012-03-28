/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style.computer.boxComputers;

import core.style.AbstractStyle;
import core.style.StyleData;
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
	override public function shrinkToFit(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData, minimumWidth:Int):Int
	{
		var shrinkedWidth:Int;
		
		//shrink-to-fit only happen if either left or right is auto
		if (style.left == PositionOffset.cssAuto || style.right == PositionOffset.cssAuto)
		{
			var computedStyle:ComputedStyleData = style.computedStyle;
			//compute the shrinked width
			shrinkedWidth = doShrinkToFit(style, containingHTMLElementData, minimumWidth);
			
			//if both right and left are auto, use left static position, then deduce right
			if (style.left == PositionOffset.cssAuto && style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingHTMLElementData);
				style.computedStyle.right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only right is auto, compute left then deduce right
			else if (style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//same for left
			else if (style.left == PositionOffset.cssAuto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.left = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - shrinkedWidth - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
		}
		//here the width is not shrinked
		else
		{
			shrinkedWidth = style.computedStyle.width;
		}
		
		//constrain width before returning it
		shrinkedWidth = constrainWidth(style, shrinkedWidth);
		
		return shrinkedWidth;
	}
	
	/**
	 * Overriden as in some cases, depending on the specified value of
	 * top and bottom style, the height used value might not be the children
	 * height of the DOMElement
	 */
	override public function applyContentHeight(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData, childrenHeight:Int):Int
	{
		var height:Int;
		
		//if neither top and bottom are auto, then height can be computed using all the other vertical dimensions
		if (style.top != PositionOffset.cssAuto && style.bottom != PositionOffset.cssAuto)
		{
			var computedStyle:ComputedStyleData = style.computedStyle;
			height = containingHTMLElementData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.marginTop - computedStyle.marginBottom;
		}
		else
		{
			height = childrenHeight;
		}
		
		//constrain height before returning it
		height = constrainHeight(style, height);
		
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
	override private function measurePositionOffsets(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		
	}
	
	// HORIZONTAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also left, right and the horizontal margins when an
	 * auto width is computed. Left and right might be computed in the shrink-to-fit
	 * method if they are defined as auto
	 */ 
	override private function measureAutoWidth(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//first, any auto value for margins are computed to 0
		if (style.marginLeft == Margin.cssAuto)
		{
			computedStyle.marginLeft = 0;
		}
		else
		{
			computedStyle.marginLeft = getComputedMarginLeft(style, containingHTMLElementData);
		}
		
		if (style.marginRight == Margin.cssAuto)
		{
			computedStyle.marginRight = 0;
		}
		else
		{
			computedStyle.marginRight = getComputedMarginRight(style, containingHTMLElementData);
		}
		
		//if neither left or right are auto but width is
		if (style.left != PositionOffset.cssAuto && style.right != PositionOffset.cssAuto)
		{
			//left and right are computed as they are defined either as length or percentage
			computedStyle.left = getComputedPositionOffset(style.left, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			computedStyle.right = getComputedPositionOffset(style.right, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//the computed width is deduced from all the other computed horizontal values. It is the remaining space when all the other value
			//are substracted from the containing DOMElement width
			setComputedWidth(style, containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.left - computedStyle.right - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight);
		}
		//if left, right and width are auto, then the width will be "shrinked-to-fit" once all the children have been laid out,
		//so the width is first set to an "inifinite" width which will allow to find the max line width of the formatted children
		//used by the shrink-to-fit method
		else
		{
			//TODO : setting a number too big makes BitmapData crashes in Flash
			setComputedWidth(style, 1000000);
		}
	}
	
	/**
	 * overriden to also compute left and right style
	 */
	override private function measureWidth(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//compute the width which is either defined as a length or a percentage
		setComputedWidth(style, getComputedWidth(style, containingHTMLElementData));
		
		//if neither left nor right are defined as auto
		if (style.left != PositionOffset.cssAuto && style.right != PositionOffset.cssAuto)
		{
			//compute left and right defined either as length or percentage
			style.computedStyle.left = getComputedPositionOffset(style.left, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//if both margin are auto, they will take the same size
			if (style.marginLeft == Margin.cssAuto && style.marginRight == Margin.cssAuto)
			{
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
			
			}
			//if only margin left is auto
			else if (style.marginLeft == Margin.cssAuto)
			{
				//compute margin right then deduce margin left from the remaining horizontal
				//space
				style.computedStyle.marginRight = getComputedMarginRight(style, containingHTMLElementData);
				style.computedStyle.marginLeft = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			}
			//same if only margin right is auto
			else if (style.marginRight == Margin.cssAuto)
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, containingHTMLElementData);
				style.computedStyle.marginRight = containingHTMLElementData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			}
			//else if no margins are auto, compute them
			else
			{
				style.computedStyle.marginLeft = getComputedMarginLeft(style, containingHTMLElementData);
				style.computedStyle.marginRight = getComputedMarginRight(style, containingHTMLElementData);
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
				style.computedStyle.marginLeft = getComputedMarginLeft(style, containingHTMLElementData);
			}
			
			if (style.marginRight == Margin.cssAuto)
			{
				style.computedStyle.marginRight = 0;
			}
			else
			{
				style.computedStyle.marginRight = getComputedMarginRight(style, containingHTMLElementData);
			}
			
			//if left and right are both auto, the statc position of left is used, then right is computed
			if (style.left == PositionOffset.cssAuto && style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedStaticLeft(style, containingHTMLElementData);
				style.computedStyle.right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only left is auto, compute right then deduce left from the remaining horizontal space
			else if (style.left == PositionOffset.cssAuto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.left = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.right;
			}
			//same for right
			else if(style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingHTMLElementData.width, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.right = containingHTMLElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
		}
	}
	
	// VERTICAL DIMENSIONS
	/////////////////////////////////
	
	/**
	 * overriden to compute also top, bottom and the vertical margins when an
	 * auto height is computed.
	 */ 
	override private function measureAutoHeight(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//first, any auto value for margins are computed to 0
		if (style.marginTop == Margin.cssAuto)
		{
			style.computedStyle.marginTop = 0;
		}
		else
		{
			style.computedStyle.marginTop = getComputedMarginTop(style, containingHTMLElementData);
		}
		
		if (style.marginBottom == Margin.cssAuto)
		{
			style.computedStyle.marginBottom = 0;
		}
		else
		{
			style.computedStyle.marginBottom = getComputedMarginBottom(style, containingHTMLElementData);
		}
		
		//if neither top or bottom are auto but height is
		if (style.top != PositionOffset.cssAuto && style.bottom != PositionOffset.cssAuto)
		{
			//top and bottom are computed as they are defined either as length or percentage
			style.computedStyle.top = getComputedPositionOffset(style.top, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//the computed height is deduced from all the other computed vertical values. It is the remaining space when all the other value
			//are substracted from the containing DOMElement height
			setComputedHeight(style, containingHTMLElementData.height - computedStyle.marginTop - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom);
		}
		//if only bottom is auto, compute top then deduce bottom from the remaining vertical space
		else if (style.bottom == PositionOffset.cssAuto)
		{
			style.computedStyle.top = getComputedPositionOffset(style.top, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
		}
		//same for top
		else if(style.top == PositionOffset.cssAuto)
		{
			
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.top = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
		}
		
		//if top or bottom are auto, then the height will be computed once the layout
		//of the DOMElement children is done
	}
	
	/**
	 * overriden to also compute top and bottom style
	 */
	override private function measureHeight(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Void
	{
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//compute the height which is either defined as a length or a percentage
		setComputedHeight(style, getComputedHeight(style, containingHTMLElementData));
		
		//if neither top nor bottom are defined as auto
		if (style.top != PositionOffset.cssAuto && style.bottom != PositionOffset.cssAuto)
		{
			//compute top and bottom defined either as length or percentage
			style.computedStyle.top = getComputedPositionOffset(style.top, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//if both margin are auto, they will take the same size
			if (style.marginTop == Margin.cssAuto && style.marginBottom == Margin.cssAuto)
			{
				//compute the size of one of the margin, which is half the remaining vertical space
				//once all other values (padding, width, offset) are removed
				var computedMargin:Int = Math.round((containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2);
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginTop = computedMargin;
					style.computedStyle.marginBottom = computedMargin;
				}
				//if the margin height is negative, it is recomputed
				else
				{
					style.computedStyle.marginBottom = 0;
					style.computedStyle.marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom - computedStyle.top;
				}
			
			}
			//if only margin top is auto
			else if (style.marginTop == Margin.cssAuto)
			{
				//compute margin top then deduce margin bottom from the remaining vertical
				//space
				style.computedStyle.marginBottom = getComputedMarginBottom(style, containingHTMLElementData);
				style.computedStyle.marginTop = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			}
			//same if only margin bottom is auto
			else if (style.marginBottom == Margin.cssAuto)
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, containingHTMLElementData);
				style.computedStyle.marginBottom = containingHTMLElementData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			}
			//else if no margins are auto, compute them
			else
			{
				style.computedStyle.marginTop = getComputedMarginTop(style, containingHTMLElementData);
				style.computedStyle.marginBottom = getComputedMarginBottom(style, containingHTMLElementData);
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
				style.computedStyle.marginTop = getComputedMarginTop(style, containingHTMLElementData);
			}
			
			if (style.marginBottom == Margin.cssAuto)
			{
				style.computedStyle.marginBottom = 0;
			}
			else
			{
				style.computedStyle.marginBottom = getComputedMarginBottom(style, containingHTMLElementData);
			}
		
			//if top and bottom are both auto, the static position of top is used, then bottom is computed
			if (style.top == PositionOffset.cssAuto && style.bottom == PositionOffset.cssAuto)
			{
				style.computedStyle.top = getComputedStaticTop(style, containingHTMLElementData);
				style.computedStyle.bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			//if only bottom is auto, compute top then deduce bottom from the remaining vertical space
			else if (style.bottom == PositionOffset.cssAuto)
			{
				
				style.computedStyle.top = getComputedPositionOffset(style.top, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.bottom = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			//same for top
			else if(style.top == PositionOffset.cssAuto)
			{
				
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingHTMLElementData.height, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				style.computedStyle.top = containingHTMLElementData.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.bottom;
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
	private function getComputedStaticLeft(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Int
	{
		return style.computedStyle.marginLeft;
	}
	
	/**
	 * compute the static value for top which is the value that will place the top margin edge
	 * of the DOMElement to the top edge of its containing DOMElement
	 */
	private function getComputedStaticTop(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData):Int
	{
		return style.computedStyle.marginTop;
	}
	
	/**
	 * Actually shrink the width
	 */
	private function doShrinkToFit(style:AbstractStyle, containingHTMLElementData:ContainingHTMLElementData, minimumWidth:Int):Int
	{
		/**
		 * TODO: the shrink to fit
		 * algorithm might need to be improved for
		 * some border cases
		 */
		return minimumWidth;
	}
	
}