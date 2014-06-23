/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.boxmodel;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSCascadeData;

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
		if (style.hasAutoLeft == true || style.hasAutoRight == true)
		{
			//any 'auto' margin is set to 0
			if (style.hasAutoMarginLeft == true)
			{
				usedValues.marginLeft = 0;
			}
			if (style.hasAutoMarginRight == true)
			{
				usedValues.marginRight = 0;
			}
			
			//if both left and right are 'auto', left is its static posittion, then right is deduced from the other values
			if (style.hasAutoLeft == true && style.hasAutoRight == true)
			{
				usedValues.left = getComputedStaticLeft(style, containingBlockData);
				usedValues.right = containingBlockData.width - usedValues.width - usedValues.marginLeft - usedValues.marginRight - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left;
			}
			//if only left is auto, right is computed then left is deduced
			else if (style.hasAutoLeft == true)
			{
				usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
				usedValues.left = containingBlockData.width - usedValues.width - usedValues.marginLeft - usedValues.marginRight - usedValues.right - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth;
			}
			//same for right
			else if (style.hasAutoRight == true)
			{
				usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
				usedValues.right = containingBlockData.width - usedValues.width - usedValues.marginLeft - usedValues.marginRight - usedValues.left - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth;
			}
		}
		//if neither left or right are auto
		else 
		{
			//compute left and right
			usedValues.left = getComputedPositionOffset(style.left, containingBlockData.width);
			usedValues.right = getComputedPositionOffset(style.right, containingBlockData.width);
			
			//then deduce the margins
			if (style.hasAutoMarginLeft == true && style.hasAutoMarginRight == true)
			{
				var margin:Float = (containingBlockData.width - usedValues.left - usedValues.right - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth) / 2;
				
				//compute the size of one of the margin, which is half the remaining horizontal space
				//once all other values (padding, width, border, offset) are removed
				var usedMargin:Float = (containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right) / 2;
				
				if (usedMargin >= 0)
				{
					usedValues.marginLeft = usedMargin;
					usedValues.marginRight = usedMargin;
				}
				//if the margin width is negative, it is recomputed
				else
				{
					usedValues.marginLeft = 0;
					usedValues.marginRight = containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right;
				}
			
				usedValues.marginLeft = 0;
			}
			else if (style.hasAutoMarginLeft == true)
			{
				usedValues.marginLeft = containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right - usedValues.marginRight;
			}
			else if (style.hasAutoMarginRight == true)
			{
				usedValues.marginRight = containingBlockData.width - usedValues.width - usedValues.paddingLeft - usedValues.paddingRight - usedValues.borderLeftWidth - usedValues.borderRightWidth - usedValues.left - usedValues.right - usedValues.marginLeft;
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
		
		if (style.hasAutoTop == true || style.hasAutoBottom == true)
		{
			if (style.hasAutoMarginTop == true)
			{
				usedValues.marginTop = 0;
			}
			if (style.hasAutoMarginBottom == true)
			{
				usedValues.marginBottom = 0;
			}
			
			if (style.hasAutoTop == true && style.hasAutoBottom == true)
			{
				usedValues.top = getComputedStaticTop(style, containingBlockData);
				usedValues.bottom = containingBlockData.height - usedValues.height - usedValues.marginTop - usedValues.marginBottom - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top;
			}
			
			else if (style.hasAutoTop == true)
			{
				usedValues.bottom = getComputedPositionOffset(style.bottom, containingBlockData.height);
				usedValues.top = containingBlockData.height - usedValues.height - usedValues.marginTop - usedValues.marginBottom - usedValues.bottom - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth;
			}
			else if (style.hasAutoBottom == true)
			{
				usedValues.top = getComputedPositionOffset(style.top, containingBlockData.height);
				usedValues.bottom = containingBlockData.height - usedValues.height - usedValues.marginTop - usedValues.marginBottom - usedValues.top - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth;
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
			
			if (style.hasAutoMarginTop == true && style.hasAutoMarginBottom == true)
			{
				var margin:Float = (containingBlockData.height - usedValues.top - usedValues.bottom - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth) / 2;
				
				var usedMargin:Float = (containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top - usedValues.bottom) / 2;
				
				if (usedMargin >= 0)
				{
					usedValues.marginTop = usedMargin;
					usedValues.marginBottom = usedMargin;
				}
				else
				{
					usedValues.marginTop = 0;
					usedValues.marginBottom = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top - usedValues.bottom;
				}
			}
			else if (style.hasAutoMarginTop == true)
			{
				usedValues.marginTop = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top - usedValues.bottom - usedValues.marginBottom;
			}
			else if (style.hasAutoMarginBottom == true)
			{
				usedValues.marginBottom = containingBlockData.height - usedValues.height - usedValues.paddingTop - usedValues.paddingBottom - usedValues.borderTopWidth - usedValues.borderBottomWidth - usedValues.top - usedValues.bottom - usedValues.marginTop;
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
