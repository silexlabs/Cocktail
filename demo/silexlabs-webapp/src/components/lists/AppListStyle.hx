/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.lists;

// DOM
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.DOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktailCore.style.StyleData;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import Constants;

/**
 * This class defines the styles used by an App cell,
 * i.e. a list with each cell containing an image over a text, and having each cell next to the previous one

 * @author Raphael Harmel
 */

class AppListStyle
{
	static inline var cellWidth:Int = 60;
	static inline var cellHeight:Int = 43;
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getListStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.fixed;
		domElement.style.display = DisplayStyleValue.inlineBlock;
		
		domElement.style.marginLeft =MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));

		domElement.style.top = PositionOffsetStyleValue.auto;
		domElement.style.bottom = PositionOffsetStyleValue.length(px(0));
		domElement.style.left = PositionOffsetStyleValue.auto;
		domElement.style.right = PositionOffsetStyleValue.auto;
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(Constants.footerHeight));

		domElement.style.textAlign = TextAlignStyleValue.center;

	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.inlineBlock;
		
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(2));
		//domElement.style.marginBottom = MarginStyleValue.length(px(10));
		
		domElement.style.width = DimensionStyleValue.length(px(cellWidth));
		domElement.style.height = DimensionStyleValue.length(px(cellHeight));
		domElement.style.color = ColorValue.hex('#BDBDCE');
	}
	
	/**
	 * Defines selected menu item image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellSelectedStyle(domElement:ImageDOMElement):Void
	{
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.marginLeft = MarginStyleValue.auto;
		domElement.style.marginRight = MarginStyleValue.auto;
		domElement.style.width = DimensionStyleValue.length(px(cellWidth));
		domElement.style.height = DimensionStyleValue.length(px(cellHeight));
		domElement.style.bottom = PositionOffsetStyleValue.length(px(2));
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellImageStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.marginLeft = MarginStyleValue.auto;
		domElement.style.marginRight = MarginStyleValue.auto;
		domElement.style.height = DimensionStyleValue.length(px(31));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
	}
	
	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.color = ColorValue.hex('#999999');
			domElement.style.fontFamily =
		[
			FontFamilyStyleValue.familyName('HelveticaNeue'),
			FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
		];
		domElement.style.fontSize = FontSizeStyleValue.length(px(10));
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.textAlign = TextAlignStyleValue.center;
	}

	/**
	 * Defines mouse over Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOverStyle(domElement:ContainerDOMElement):Void
	{

	}
	
	/**
	 * Defines mouse out Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOutStyle(domElement:ContainerDOMElement):Void
	{
	}
	
	/**
	 * Defines mouse down Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseDownStyle(domElement:ContainerDOMElement):Void
	{
	}
	
	/**
	 * Defines mouse up Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseUpStyle(domElement:ContainerDOMElement):Void
	{
	}
}