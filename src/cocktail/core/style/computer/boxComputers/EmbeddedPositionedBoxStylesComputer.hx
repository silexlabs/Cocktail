/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.style.computer.boxComputers;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
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
	override private function measurePositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		//horizontal position offsets and margins
		measureHorizontalPositionOffsets(style, containingBlockData, fontMetrics);
		//vertical position offsets and margins
		measureVerticalPositionOffsets(style, containingBlockData, fontMetrics);	
	}
	
	/**
	 * Compute, left, right and marginLeft marginRight styles
	 */
	private function measureHorizontalPositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		var computedStyle:ComputedStyle = style.computedStyle;
			
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
				style.computedStyle.left = getComputedStaticLeft(style, containingBlockData);
				style.computedStyle.right = containingBlockData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left;
			}
			//if only left is auto, right is computed then left is deduced
			else if (style.left == PositionOffset.cssAuto)
			{
				style.computedStyle.right = getComputedPositionOffset(style.right, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.left = containingBlockData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
			//same for right
			else if (style.right == PositionOffset.cssAuto)
			{
				style.computedStyle.left = getComputedPositionOffset(style.left, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.right = containingBlockData.width - computedStyle.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.left - computedStyle.paddingLeft - computedStyle.paddingRight;
			}
		}
		//if neither left or right are auto
		else 
		{
			//compute left and right
			style.computedStyle.left = getComputedPositionOffset(style.left, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.right = getComputedPositionOffset(style.right, containingBlockData.width, fontMetrics.fontSize, fontMetrics.xHeight);
			
			//then deduce the margins
			if (style.marginLeft == Margin.cssAuto && style.marginRight == Margin.cssAuto)
			{
				var margin:Float = (containingBlockData.width - computedStyle.left - computedStyle.right - computedStyle.paddingLeft - computedStyle.paddingRight) / 2;
				
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
			
				style.computedStyle.marginLeft = 0;
			}
			else if (style.marginLeft == Margin.cssAuto)
			{
				style.computedStyle.marginLeft = containingBlockData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginRight;
			}
			else if (style.marginRight == Margin.cssAuto)
			{
				style.computedStyle.marginRight = containingBlockData.width - computedStyle.width - computedStyle.paddingLeft - computedStyle.paddingRight - computedStyle.left - computedStyle.right - computedStyle.marginLeft;
			}
		}
	}
	
	/**
	 * Compute, top, bottom and marginTop marginBottom styles. Works the same as
	 * measureHorizontalPositionOffsets
	 */
	private function measureVerticalPositionOffsets(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		var computedStyle:ComputedStyle = style.computedStyle;
		
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
				style.computedStyle.top = getComputedStaticTop(style, containingBlockData);
				style.computedStyle.bottom = containingBlockData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top;
			}
			
			else if (style.top == PositionOffset.cssAuto)
			{
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.top = containingBlockData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom;
			}
			else if (style.bottom == PositionOffset.cssAuto)
			{
				style.computedStyle.top = getComputedPositionOffset(style.top, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.bottom = containingBlockData.height - computedStyle.height - computedStyle.marginTop - computedStyle.marginBottom - computedStyle.top - computedStyle.paddingTop - computedStyle.paddingBottom;
			}
			else
			{
				style.computedStyle.top = getComputedPositionOffset(style.top, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
				style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			}
		}
	
		else 
		{
			style.computedStyle.top = getComputedPositionOffset(style.top, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height, fontMetrics.fontSize, fontMetrics.xHeight);
			
			if (style.marginTop == Margin.cssAuto && style.marginBottom == Margin.cssAuto)
			{
				var margin:Float = (containingBlockData.height - computedStyle.top - computedStyle.bottom - computedStyle.paddingTop - computedStyle.paddingBottom) / 2;
				
				var computedMargin:Float = (containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom) / 2;
				
				if (computedMargin >= 0)
				{
					style.computedStyle.marginTop = computedMargin;
					style.computedStyle.marginBottom = computedMargin;
				}
				else
				{
					style.computedStyle.marginTop = 0;
					style.computedStyle.marginBottom = containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom;
				}
			}
			else if (style.marginTop == Margin.cssAuto)
			{
				style.computedStyle.marginTop = containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginBottom;
			}
			else if (style.marginBottom == Margin.cssAuto)
			{
				style.computedStyle.marginBottom = containingBlockData.height - computedStyle.height - computedStyle.paddingTop - computedStyle.paddingBottom - computedStyle.top - computedStyle.bottom - computedStyle.marginTop;
			}
		}
	}
	
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