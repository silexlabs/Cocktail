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


/**
 * This class defines the styles used by the CellText
 * 
 * @author Raphael Harmel
 */

class CellTextStyle
{
	static inline var CELL_VERTICAL_SPACE:Int = 5;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function setCellStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.position = PositionStyleValue.relative;
		
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(CELL_VERTICAL_SPACE));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
				
	}
	
	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function setCellTextStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.inlineStyle;
		domElement.style.position = PositionStyleValue.relative;

		domElement.style.paddingLeft = PaddingStyleValue.length(px(8));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		
		domElement.style.fontSize = FontSizeStyleValue.length(px(20));
		domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('Helvetica'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.fontVariant = FontVariantStyleValue.normal;
		domElement.style.textTransform = TextTransformStyleValue.none;
		domElement.style.letterSpacing = LetterSpacingStyleValue.normal;
		domElement.style.wordSpacing = WordSpacingStyleValue.normal;
		domElement.style.textIndent = TextIndentStyleValue.length(px(0));
		domElement.style.whiteSpace = WhiteSpaceStyleValue.normal;
		domElement.style.textAlign = TextAlignStyleValue.left;
		
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		
		domElement.style.color = ColorValue.hex('#666666');
	}
	
	/**
	 * Defines cell line Style
	 * 
	 * @param	domElement
	 */
	public static function setCellLineStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.position = PositionStyleValue.relative;

		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(1));
		domElement.style.marginTop = MarginStyleValue.length(px(CELL_VERTICAL_SPACE));
	}
	
}
