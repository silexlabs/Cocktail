/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

// DOM
import cocktail.domElement.DOMElement;
//import cocktail.domElement.ImageDOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.view.Constants;

/**
 * Defines the style of the app
 * 
 * @author Raphael Harmel
 */

class HeaderStyle 
{
	/**
	 * Defines header Style
	 * 
	 * @param	domElement
	 */
	public static function setHeaderStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.fixed;
		//domElement.style.position = PositionStyleValue.relative;
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.bottom = PositionOffsetStyleValue.autoValue;
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		
		domElement.style.minWidth = ConstrainedDimensionStyleValue.percent(100);
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(Constants.HEADER_HEIGHT));
		
		//domElement.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.url( new URLData("assets/header.jpg")))];
		domElement.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.url("assets/headerGrey.jpg"))];
		
		// background with gradients - not supported in HTML4, so not used to be HbbTV compliant
		/*domElement.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.gradient(GradientValue.linear( { angle:GradientAngleValue.angle(AngleValue.deg(90)),
		colorStops:[{color:ColorValue.rgba(0, 255, 0,0.7), stop:GradientStopValue.percent(0)}, {color:ColorValue.rgba(255, 0, 0,0.3), stop:GradientStopValue.percent(100)} ]} )))];*/
	}

	/**
	 * Defines header static Style
	 * done as a workaround to have a layout using a minimum of absolute values
	 * 
	 * @param	domElement
	 */
	public static function setHeaderStaticStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.staticStyle;
		domElement.style.display = DisplayStyleValue.block;

		domElement.style.minWidth = ConstrainedDimensionStyleValue.percent(100);
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(Constants.HEADER_HEIGHT));
		
	}

	/**
	 * Defines header title text Style
	 * 
	 * @param	domElement
	 */
	public static function setHeaderTextStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.color = ColorValue.hex('#454545');

		domElement.style.fontSize = FontSizeStyleValue.length(px(20));
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('HelveticaNeue'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.textAlign = TextAlignStyleValue.center;

		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		
		domElement.style.minWidth = ConstrainedDimensionStyleValue.percent(100);
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.width = DimensionStyleValue.percent(100);
		//domElement.style.height = DimensionStyleValue.length(px(Constants.HEADER_HEIGHT));
		domElement.style.height = DimensionStyleValue.percent(100);
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}

	/**
	 * Defines back button Style
	 * 
	 * @param	domElement
	 */
	public static function setBackButtonStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.paddingTop = PaddingStyleValue.length(px(6));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(10));
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
	}

	/**
	 * Defines back button text Style
	 * 
	 * @param	domElement
	 */
	public static function setBackButtonTextStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.color = ColorValue.hex('#EEEEEE');

		domElement.style.fontSize = FontSizeStyleValue.length(px(14));
		domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('Arial'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.textAlign = TextAlignStyleValue.center;

		domElement.style.paddingTop = PaddingStyleValue.length(px(12));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(30));
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
	}

	/**
	 * Defines back button image Style
	 * 
	 * @param	domElement
	 */
	public static function setBackButtonImageStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.inlineStyle;
		domElement.style.position = PositionStyleValue.relative;
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
	}
	
}