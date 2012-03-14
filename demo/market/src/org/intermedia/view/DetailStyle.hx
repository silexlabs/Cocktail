/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.view.Constants;
import org.intermedia.view.ScreenResolution;

/**
 * This class defines the styles used by the detail view
 * 
 * @author Raphael Harmel
 */

class DetailStyle
{
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function setDefault(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.position = PositionStyleValue.absolute;
		
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.autoValue;
		
		domElement.style.top = PositionOffsetStyleValue.length(px(Constants.HEADER_HEIGHT));
		domElement.style.bottom = PositionOffsetStyleValue.length(px(0));
	}

	/**
	 * Defines thumblist Style
	 * 
	 * @param	domElement
	 */
	public static function setThumbnail(domElement:DOMElement):Void
	{
		var imageMaxWidth:Int = 250;
		
		domElement.style.display = DisplayStyleValue.block;
		
			domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(imageMaxWidth));
			domElement.style.maxHeight = ConstrainedDimensionStyleValue.percent(50);
			domElement.style.width = DimensionStyleValue.percent(80);	
		
	}
	
	/**
	 * Defines text Style
	 * 
	 * @param	domElement
	 */
	public static function setText(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.color = ColorValue.hex('#202020');
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('Arial'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
	}

	/**
	 * Defines cell title Style
	 * 
	 * @param	domElement
	 */
	public static function setTitle(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	//public static function setTitle(domElement:DOMElement):Void
	{
		setText(domElement);
		
		var fontSize:Int = 14;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 14;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 16;
		else  fontSize = 18;
		
		domElement.style.fontSize = FontSizeStyleValue.length(px(fontSize));
		domElement.style.fontWeight = FontWeightStyleValue.bold;
	}

	/**
	 * Defines cell comment Style
	 * 
	 * @param	domElement
	 */
	public static function setAuthor(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	//public static function setAuthor(domElement:DOMElement):Void
	{
		setText(domElement);

		var fontSize:Int = 10;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 10;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 11;
		else  fontSize = 12;
		
		domElement.style.fontSize = FontSizeStyleValue.length(px(fontSize));
		domElement.style.fontWeight = FontWeightStyleValue.normal;
	}

	/**
	 * Defines cell description Style
	 * 
	 * @param	domElement
	 */
	public static function setDescription(domElement:DOMElement):Void
	{
		setText(domElement);

		domElement.style.fontSize = FontSizeStyleValue.length(px(14));
		//domElement.style.fontWeight = FontWeightStyleValue.bold;
	}
	
}
