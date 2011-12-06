/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

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

	public static function getDefaultStyle(domElement:DOMElement):Void
	{
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
		domElement.style.right = PositionOffsetStyleValue.length(px(0));
		domElement.style.bottom  = PositionOffsetStyleValue.length(px(0));
		
		domElement.style.minWidth = ConstrainedDimensionStyleValue.none;
		domElement.style.maxWidth = ConstrainedDimensionStyleValue.none;
		domElement.style.minHeight = ConstrainedDimensionStyleValue.none;
		domElement.style.maxHeight = ConstrainedDimensionStyleValue.none;
		
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
		
		domElement.style.color = ColorValue.keyword(ColorKeywordValue.black);
		
		domElement.style.display = block;
		
		//domElement.style.position = _static;
		domElement.style.position = staticStyle;
		
		domElement.style.width = DimensionStyleValue.auto;
		domElement.style.height = DimensionStyleValue.auto;
		
		domElement.style.float = FloatStyleValue.none;
		domElement.style.clear = ClearStyleValue.none;
	}
	
	public static function getCellStyle(domElement:ContainerDOMElement):Void
	{
		getDefaultStyle(domElement);

		domElement.style.paddingLeft = PaddingStyleValue.length(px(8));
		domElement.style.paddingRight = PaddingStyleValue.length(px(8));
		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(8));
				
		//domElement.style.position = absolute;
		//domElement.style.float = FloatStyleValue.left;
		domElement.style.color = ColorValue.hex('666666');


		// create line to separate cells
		//var line:GraphicDOMElement;
		//line = createLine(0xDDDDDD);
		
		//domElement.removeChild(line);
		//domElement.addChild(line);
	}
	
	public static function getCellImageStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		//domElement.style.position = absolute;

		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		domElement.style.float = FloatStyleValue.right;
	}
	
	public static function getCellMouseOverStyle(domElement:ContainerDOMElement):Void
	{
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('333333');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	public static function getCellMouseOutStyle(domElement:ContainerDOMElement):Void
	{
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('666666');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	public static function getCellMouseDownStyle(domElement:ContainerDOMElement):Void
	{
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('000000');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	public static function getCellMouseUpStyle(domElement:ContainerDOMElement):Void
	{
		//getCellStyle(domElement);

		domElement.style.color = ColorValue.hex('333333');

		// create line to separate cells
		//addLineAgain(domElement);
	}
	
	public static function getCellLineStyle(domElement:DOMElement):Void
	{
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(1));
	}
	
	private static function createLine(color:Int):GraphicDOMElement
	{
		var line:GraphicDOMElement = Utils.getGraphic();
		getCellLineStyle(line);
		Utils.fillGraphic(line, color);
		
		return(line);
	}
	
	private static function addLineAgain(domElement:ContainerDOMElement)
	{
		// create line to separate cells
		var line:GraphicDOMElement;
		line = createLine(0xDDDDDD);
		
		domElement.removeChild(line);
		domElement.addChild(line);
	}
}
