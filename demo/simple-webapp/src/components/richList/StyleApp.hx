/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;

// DOM
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

// RichList
import components.richList.RichListModels;


/**
 * This class defines the styles used by the App RichList,
 * i.e. a list with each cell containing an image over a text, and having each cell next to the previous one

 * @author Raphael Harmel
 */

class StyleApp
{
	private static inline var appIconSize:Int = 57;
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getDefaultStyle(domElement:DOMElement):Void
	{
		domElement.style.marginLeft =MarginStyleValue.length(px(6));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(5));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(10));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(10));
		
		domElement.style.display = DisplayStyleValue.inlineBlock;
		domElement.style.position = PositionStyleValue.relative;
	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(6));
		domElement.style.marginTop = MarginStyleValue.length(px(6));
		domElement.style.marginBottom = MarginStyleValue.length(px(6));

		domElement.style.paddingLeft = PaddingStyleValue.length(px(5));
		domElement.style.paddingRight = PaddingStyleValue.length(px(5));		
		
		domElement.style.display = DisplayStyleValue.inlineBlock;
		domElement.style.color = ColorValue.hex('#BDBDCE');
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellImageStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		//domElement.style.width = domElement.style.height = DimensionStyleValue.length(px(60));
		//domElement.style.width = DimensionStyleValue.percent(50);
		domElement.style.width = domElement.style.height = DimensionStyleValue.length(px(appIconSize));
		//domElement.style.height = DimensionStyleValue.percent(50);
		domElement.style.marginBottom = MarginStyleValue.length(px(3));
	}
	
	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.width = DimensionStyleValue.length(px(appIconSize));
		domElement.style.color = ColorValue.hex('#BDBDCE');
		
		domElement.style.fontFamily = [FontFamilyStyleValue.familyName('Helvetica'), FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)];
		domElement.style.fontSize = FontSizeStyleValue.length(px(12));
		domElement.style.textAlign = TextAlignStyleValue.center;
	}

	/**
	 * Defines mouse over Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOverStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.hex('#DDDDDD');
	}
	
	/**
	 * Defines mouse out Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOutStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.hex('#BDBDCE');
	}
	
	/**
	 * Defines mouse down Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseDownStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.keyword(ColorKeywordValue.white);
	}
	
	/**
	 * Defines mouse up Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseUpStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.hex('#BDBDCE');
	}
}