/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.computer.boxComputers;

import cocktail.domElement.EmbeddedDOMElement;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.computer.BoxStylesComputer;
import cocktail.style.StyleData;

/**
 * This is the box computer implementation for an
 * embedded block DOMElement.
 * 
 * It add special treatement for dimensions
 * computation, as an embedded DOMElement has intrinsic
 * dimensions
 * 
 * 
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
		if (style.height == DimensionStyleValue.auto)
		{
			//first try to use the intrinsic width of the embedded
			//DOMElement if it exist (it might for instance be a
			//picture width for an ImageDOMElement)
			if (embeddedDOMElement.intrinsicWidth != null)
			{
				ret = embeddedDOMElement.intrinsicWidth;
			}
			//else deduce the intrinsic width from the intrinsic height and rotaio
			else if (embeddedDOMElement.intrinsicHeight != null && embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(embeddedDOMElement.intrinsicHeight * embeddedDOMElement.intrinsicRatio);
			}
			else if (embeddedDOMElement.intrinsicRatio != null)
			{
				//TO DO : 
				//If 'height' and 'width' both have computed values of 'auto' 
				//and the element has an intrinsic ratio but no intrinsic height
				//or width, then the used value of 'width' is undefined in CSS 2.1.
				//However, it is suggested that, if the containing block's width
				//does not itself depend on the replaced element's width,
				//then the used value of 'width' is calculated from the
				//constraint equation used for block-level, non-replaced elements in normal flow. 
				ret = 0;
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
				//TO DO :
				//Otherwise, if 'width' has a computed value of 'auto',
				//but none of the conditions above are met, then the used 
				//value of 'width' becomes 300px. If 300px is too wide to fit the device,
				//UAs should use the width of the largest rectangle that has a 2:1 ratio
				//and fits the device instead. 	
				ret = 0;
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
		if (style.width == DimensionStyleValue.auto)
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
			var computedWidth:Int = getComputedDimension(style.width, containingDOMElementData.height, containingDOMElementData.isHeightAuto, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
			
			//deduce theheight from the computed width and the intrinsic ratio if it is defined
			if (embeddedDOMElement.intrinsicRatio != null)
			{
				ret = Math.round(computedWidth * embeddedDOMElement.intrinsicRatio);
			}
			else
			{
				//TO DO : 
				//Otherwise, if 'height' has a computed value of 'auto',
				//but none of the conditions above are met, then the used value of 'height'
				//must be set to the height of the largest rectangle that has a 2:1 ratio, has a
				//height not greater than 150px, and has a width not greater than the device width. 
			}
		}
		
		return ret;
	}
	
}