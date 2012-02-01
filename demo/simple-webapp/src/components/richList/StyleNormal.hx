/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.richList;

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

// RichList
import components.richList.RichListModels;

//Iphone
import Utils;

/**
 * This class defines the styles used by the normal RichList,
 * i.e. a list with each cell containing a text and an image on the same line, and having each cell under the previous one
 * 
 * @author Raphael Harmel
 */

class StyleNormal
{
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getDefaultStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;

		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:ContainerDOMElement):Void
	{
		getDefaultStyle(domElement);

		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
				
		//domElement.style.color = ColorValue.hex('#666666');
		
		getCellLine(domElement);

	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellImageStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		//domElement.style.position = absolute;

		domElement.style.paddingTop = PaddingStyleValue.length(px(6));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(8));
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		domElement.style.floatValue = FloatStyleValue.right;
		//domElement.style.width = DimensionStyleValue.length(px(8));
		//domElement.style.height = DimensionStyleValue.length(px(13));
		//domElement.style.height = DimensionStyleValue.length(px(29));
	}
	
	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);

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
		//domElement.style.width = DimensionStyleValue.percent(100);
	}

	/**
	 * Defines mouse over Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOverStyle(domElement:ContainerDOMElement):Void
	{
		//getCellTextStyle(domElement);

		domElement.style.color = ColorValue.hex('#333333');
	}
	
	/**
	 * Defines mouse out Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOutStyle(domElement:ContainerDOMElement):Void
	{
		//getCellTextStyle(domElement);

		domElement.style.color = ColorValue.hex('#666666');
	}
	
	/**
	 * Defines mouse down Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseDownStyle(domElement:ContainerDOMElement):Void
	{
		//getCellTextStyle(domElement);

		domElement.style.color = ColorValue.hex('#000000');
	}
	
	/**
	 * Defines mouse up Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseUpStyle(domElement:ContainerDOMElement):Void
	{
		//getCellTextStyle(domElement);

		domElement.style.color = ColorValue.hex('#333333');
	}
	
	/**
	 * Create a cell line
	 * 
	 * @param	domElement
	 */
	public static function getCellLine(domElement:ContainerDOMElement):Void
	{
		var line:ImageDOMElement = new ImageDOMElement();
		line.style.display = DisplayStyleValue.block;
		line.style.paddingTop = PaddingStyleValue.length(px(8));
		line.style.minWidth = ConstrainedDimensionStyleValue.percent(100);
		line.style.width = DimensionStyleValue.percent(100);
		line.style.height = DimensionStyleValue.length(px(1));
		line.load("images/greyPixel.png");
		
		domElement.addChild(line);
	}
	
}
