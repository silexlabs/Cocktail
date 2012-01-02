/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer.boxComputers;

import cocktail.domElement.EmbeddedDOMElement;
import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * This is the box computer implementation for an
 * embedded block DOMElement.
 * 
 * It add special treatement for dimensions
 * computation, as an embedded DOMElement has intrinsic
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
	 * Override the way a value of 'auto' for the width style
	 * is computed, as an embedded DOMElement may have an intrinsic width
	 * and/or intrinsic ratio
	 */ 
	override private function getComputedAutoWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		var ret:Int = 0;
		
		var embeddedDOMElement:EmbeddedDOMElement = cast(style.domElement);
		
		//if the 'height' style also is defined as 'auto'
		if (style.height == DimensionStyleValue.autoValue)
		{
			//first try to use the intrinsic width of the embedded
			//DOMElement if it exist (it might for instance be a
			//picture width for an ImageDOMElement)
			if (embeddedDOMElement.intrinsicWidth != null)
			{
				ret = embeddedDOMElement.intrinsicWidth;
			}
			//else deduce the intrinsic width from the intrinsic height and ratio
			else if (embeddedDOMElement.intrinsicHeight != null && embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(embeddedDOMElement.intrinsicHeight * embeddedDOMElement.intrinsicRatio);
			}
			else if (embeddedDOMElement.intrinsicRatio != null)
			{
				//If 'height' and 'width' both have computed values of 'auto' 
				//and the element has an intrinsic ratio but no intrinsic height
				//or width, then the used value of 'width' is undefined in CSS 2.1.
				//However, it is suggested that, if the containing block's width
				//does not itself depend on the replaced element's width,
				//then the used value of 'width' is calculated from the
				//constraint equation used for block-level, non-replaced elements in normal flow. 
				if (containingDOMElementData.isWidthAuto == false)
				{
					var computedStyle:ComputedStyleData = style.computedStyle;
					ret = containingDOMElementData.width - computedStyle.marginLeft - computedStyle.marginRight - computedStyle.paddingLeft - computedStyle.paddingRight;
				}
				else
				{
					ret = 0;
				}
			}
		}
		
		//if the 'height' style is not auto
		else
		{
			//compute the used height
			var computedHeight:Int = getComputedDimension(style.height, containingDOMElementData.height, containingDOMElementData.isHeightAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//deduce the width from the intrinsic ratio and the computed height
			if (embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(computedHeight * embeddedDOMElement.intrinsicRatio);
			}
			//else use the intrinsic width if defined
			else if (embeddedDOMElement.intrinsicWidth != null)
			{
				ret = embeddedDOMElement.intrinsicWidth;
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
	 * is computed, as an embedded DOMElement may have an intrinsic height
	 * and/or intrinsic ratio
	 */ 
	override private function getComputedAutoHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		var embeddedDOMElement:EmbeddedDOMElement = cast(style.domElement);
		var ret:Int = 0;
		
		//if the 'width' style is also set to 'auto'
		if (style.width == DimensionStyleValue.autoValue)
		{
			//try to use the intrinsic height if not null
			if (embeddedDOMElement.intrinsicHeight != null)
			{
				ret = embeddedDOMElement.intrinsicHeight;
			}
		}
		//else if 'width' is not 'auto'
		else
		{
			//compute the used value of 'width'
			var computedWidth:Int = getComputedDimension(style.width, containingDOMElementData.width, containingDOMElementData.isWidthAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight);

			//deduce the height from the computed width and the intrinsic ratio if it is defined
			if (embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(computedWidth / embeddedDOMElement.intrinsicRatio);
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
	 * for block embedded DOMElement, an 'auto' for vertical margin compute to 0, 
	 * horizontal margin are computed like for non-embedded block DOMElements
	 */
	override private function getComputedAutoMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool = false ):Int
	{
		var computedMargin:Int;
		
		if (isHorizontalMargin == false)
		{
			computedMargin = 0;
		}
		else
		{
			computedMargin = super.getComputedAutoMargin(marginStyleValue, opositeMarginStyleValue, containingDOMElementDimension, computedDimension, isDimensionAuto, computedPaddingsDimension, fontSize, xHeight, isHorizontalMargin );
		}
		
		return computedMargin;
	}
	
}