/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer.boxComputers;

import cocktail.core.html.EmbeddedElement;
import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;
import haxe.Log;

/**
 * This is the box computer implementation for an
 * embedded block HTMLElement.
 * 
 * It add special treatement for dimensions
 * computation, as an embedded HTMLElement has intrinsic
 * dimensions
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedBlockBoxStylesComputer extends BoxStylesComputer
{

	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Overriden to process width before margins. For an embedded element a
	 * computed width can always be computed event when width is auto
	 */
	override private function measureAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		//width
		style.computedStyle.width = getComputedAutoWidth(style, containingBlockData, fontMetrics);
			
		//left margin
		style.computedStyle.marginLeft = getComputedMarginLeft(style, containingBlockData, fontMetrics);
		//right margin
		style.computedStyle.marginRight = getComputedMarginRight(style, containingBlockData, fontMetrics);
	}
	
	/**
	 * Override the way a value of 'auto' for the width style
	 * is computed, as an embedded HTMLElement may have an intrinsic width
	 * and/or intrinsic ratio
	 */ 
	override private function getComputedAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		var ret:Float = 0.0;
		
		var embeddedHTMLElement:EmbeddedElement = cast(style.htmlElement);
		
		//first try to use the HTML width attribute if it was specified
		//for the embedded HTMLElement
		//TODO 1 : this is not how it is supposed to work, should only try HTML width attribute
		//if width style is not specified. Must correct once cascading is implemented
		if (embeddedHTMLElement.getAttributeNode("width") != null)
		{
			ret = embeddedHTMLElement.width;
		}
		//if the 'height' style also is defined as 'auto'
		else if (style.height == Dimension.cssAuto)
		{
			//first try to use the intrinsic width of the embedded
			//HTMLElement if it exist (it might for instance be a
			//picture width for an ImageHTMLElement)
			
			if (embeddedHTMLElement.intrinsicWidth != null)
			{
				ret = embeddedHTMLElement.intrinsicWidth;
			}
			//else deduce the intrinsic width from the intrinsic height and ratio
			else if (embeddedHTMLElement.intrinsicHeight != null && embeddedHTMLElement.intrinsicRatio != null)
			{
				ret = embeddedHTMLElement.intrinsicHeight * embeddedHTMLElement.intrinsicRatio;
			}
			else if (embeddedHTMLElement.intrinsicRatio != null)
			{
				//If 'height' and 'width' both have computed values of 'auto' 
				//and the element has an intrinsic ratio but no intrinsic height
				//or width, then the used value of 'width' is undefined in CSS 2.1.
				//However, it is suggested that, if the containing block's width
				//does not itself depend on the replaced element's width,
				//then the used value of 'width' is calculated from the
				//constraint equation used for block-level, non-replaced elements in normal flow. 
				if (containingBlockData.isWidthAuto == false)
				{
					var computedStyle:ComputedStyle = style.computedStyle;
					
					ret = containingBlockData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
				}
				else
				{
					ret = 0.0;
				}
			}
			
		}
		
		//if the 'height' style is not auto
		else
		{
			//compute the used height
			var computedHeight:Float = getComputedDimension(style.height, containingBlockData.height, containingBlockData.isHeightAuto, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.height = computedHeight;
			
			//deduce the width from the intrinsic ratio and the computed height
			if (embeddedHTMLElement.intrinsicRatio != null)
			{
				ret = computedHeight / embeddedHTMLElement.intrinsicRatio;
			}
			//else use the intrinsic width if defined
			else if (embeddedHTMLElement.intrinsicWidth != null)
			{
				ret = embeddedHTMLElement.intrinsicWidth;
			}
			else
			{
				//Otherwise, if 'width' has a computed value of 'auto',
				//but none of the conditions above are met, then the used 
				//value of 'width' becomes 300px.
				ret = 300;
			}
			
		}
		
		return ret;
	}
	
	/**
	 * Override the way a value of 'auto' for the height style
	 * is computed, as an embedded HTMLElement may have an intrinsic height
	 * and/or intrinsic ratio
	 */ 
	override private function getComputedAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		var ret:Float = 0.0;
		
		//TODO 4 : should style have a reference to the HTMLElement ? Should they be
		//applied to multiple HTMLElement ?
		var embeddedHTMLElement:EmbeddedElement = cast(style.htmlElement);
		
		//first try to use the HTML height attribute if it was specified
		//for the embedded HTMLElement
		//TODO 1 : this is not how it is supposed to work, should only try HTML height attribute
		//if height style is not specified. Must correct once cascading is implemented
		if (embeddedHTMLElement.getAttributeNode("height") != null)
		{
			ret = embeddedHTMLElement.height;
		}
		//if the 'width' style is also set to 'auto'
		else if (style.width == Dimension.cssAuto)
		{
			//try to use the intrinsic height of the embedded
			//HTMLElement if it exist (it might for instance be a
			//picture width for an ImageHTMLElement)
			if (embeddedHTMLElement.intrinsicHeight != null)
			{
				ret = embeddedHTMLElement.intrinsicHeight;
			}
			//else deduce the intrinsic height from the intrinsic width and ratio
			else if (embeddedHTMLElement.intrinsicWidth != null && embeddedHTMLElement.intrinsicRatio != null)
			{
				ret = embeddedHTMLElement.intrinsicWidth * embeddedHTMLElement.intrinsicRatio;
			}
			//TODO 3 : check what must happen here
			else if (embeddedHTMLElement.intrinsicRatio != null)
			{
				
			}
		}
		//else if 'width' is not 'auto'
		else
		{
			
			//compute the used value of 'width'
			var computedWidth:Float = getComputedDimension(style.width, containingBlockData.width, containingBlockData.isWidthAuto, fontMetrics.fontSize, fontMetrics.xHeight);
			style.computedStyle.width = computedWidth;
			
			//deduce the height from the computed width and the intrinsic ratio if it is defined
			if (embeddedHTMLElement.intrinsicRatio != null)
			{
				ret = style.computedStyle.width * embeddedHTMLElement.intrinsicRatio;
			}
			else
			{
				//Otherwise, if 'height' has a computed value of 'auto',
				//but none of the conditions above are met, then the used value of 'height'
				//is 150px
				ret = 150;
			}
		}
		
		return ret;
	}
	
	/**
	 * for block embedded HTMLElement, an 'auto' for vertical margin compute to 0, 
	 * horizontal margin are computed like for non-embedded block HTMLElements
	 */
	override private function getComputedAutoMargin(marginStyleValue:Margin, opositeMargin:Margin, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsDimension:Float, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool):Float
	{
		var computedMargin:Float;
	
		if (isHorizontalMargin == false)
		{
			computedMargin = 0.0;
		}
		else
		{
			//the "isDimensionAuto" flag is set to false, as for embedded element, there is always a computed width 
			//at this point
			computedMargin = super.getComputedAutoMargin(marginStyleValue, opositeMargin, containingHTMLElementDimension, computedDimension, false, computedPaddingsDimension, fontSize, xHeight, isHorizontalMargin );
		}
		
		return computedMargin;
	}
	
}