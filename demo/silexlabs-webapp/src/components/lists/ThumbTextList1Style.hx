/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.lists;

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
import cocktailCore.style.StyleData;
import Constants;

// list
import components.lists.ListBaseModels;

//Iphone
import Utils;

/**
 * This class defines the styles used by a Thumb & text cell,
 * i.e. a list with each cell containing a thumbnail on the left and text informations on the right,
 * and having each cell under the previous one
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1Style
{
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getListStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		//domElement.style.marginBottom = MarginStyleValue.length(px(Constants.footerHeight));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		//domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(Constants.footerHeight));
		
		//domElement.style.bottom = PositionOffsetStyleValue.length(px(100));
	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:DOMElement):Void
	{
		domElement.style.paddingTop = PaddingStyleValue.percent(1);
	}
	
	/**
	 * Defines info block Style
	 * 
	 * @param	domElement
	 */
	public static function getCellInfoBlockStyle(domElement:DOMElement):Void
	{
		//getCellStyle(domElement);

		domElement.style.display = DisplayStyleValue.inlineBlock;
		domElement.style.width = DimensionStyleValue.percent(10);
		//domElement.style.height = DimensionStyleValue.length(px(2));
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}
	
	/**
	 * Defines cell number Style
	 * 
	 * @param	domElement
	 */
	public static function getCellNumberStyle(domElement:DOMElement):Void
	{
		getCellTextStyle(domElement);
		
		domElement.style.fontSize = FontSizeStyleValue.length(px(20));
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.color = ColorValue.hex('#989898');
		domElement.style.textAlign = TextAlignStyleValue.center;
		domElement.style.paddingBottom = PaddingStyleValue.percent(10);
	}
	
	/**
	 * Defines comment count Style
	 * 
	 * @param	domElement
	 */
	public static function getCellCommentCountStyle(domElement:DOMElement):Void
	{
		getCellTextStyle(domElement);
		
		domElement.style.fontSize = FontSizeStyleValue.length(px(17));
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.color = ColorValue.hex('#CC3517');
		domElement.style.textAlign = TextAlignStyleValue.center;
	}
	
	/**
	 * Defines cell info block image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellInfoBlockImageStyle(domElement:DOMElement):Void
	{
		//getCellTextStyle(domElement);
		
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.marginLeft = MarginStyleValue.auto;
		domElement.style.marginRight = MarginStyleValue.auto;
		domElement.style.marginTop = MarginStyleValue.auto;
		domElement.style.marginBottom = MarginStyleValue.auto;
		domElement.style.paddingBottom = PaddingStyleValue.percent(10);
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellThumbnailStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		getCellStyle(domElement);
		//domElement.style.position = absolute;
		domElement.style.display = DisplayStyleValue.inlineStyle;
		
		domElement.style.paddingLeft = PaddingStyleValue.percent(1);
		domElement.style.paddingRight = PaddingStyleValue.percent(1);
		domElement.style.paddingBottom = PaddingStyleValue.percent(1);

		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(200));
		domElement.style.width = DimensionStyleValue.percent(30);
		//domElement.style.height = DimensionStyleValue.percent(100);
		//domElement.style.height = DimensionStyleValue.length(px(Std.int(domElement.width * 3 / 2)));
		//domElement.style.height = DimensionStyleValue.length(px(180));
	}
	
	/**
	 * Defines cell line Style
	 * 
	 * @param	domElement
	 */
	public static function getCellLineStyle(domElement:DOMElement):Void
	{
		//getListStyle(domElement);

		domElement.style.display = DisplayStyleValue.block;
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(1));
	}
	
	/**
	 * Defines cell text block Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextBlockStyle(domElement:DOMElement):Void
	{
		getCellStyle(domElement);
		
		domElement.style.display = DisplayStyleValue.inlineBlock;
		domElement.style.marginLeft = MarginStyleValue.percent(2);
		domElement.style.verticalAlign = VerticalAlignStyleValue.top;
		domElement.style.width = DimensionStyleValue.percent(55);
	}

	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.color = ColorValue.hex('#202020');
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('HelveticaNeue'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
	}

	/**
	 * Defines cell title Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTitleStyle(domElement:DOMElement):Void
	{
		getCellTextStyle(domElement);
		
		domElement.style.fontSize = FontSizeStyleValue.length(px(18));
		domElement.style.fontWeight = FontWeightStyleValue.bold;
	}

	/**
	 * Defines cell comment Style
	 * 
	 * @param	domElement
	 */
	public static function getCellCommentStyle(domElement:DOMElement):Void
	{
		getCellTextStyle(domElement);

		domElement.style.fontSize = FontSizeStyleValue.length(px(13));
		domElement.style.fontWeight = FontWeightStyleValue.normal;
	}

	/**
	 * Defines cell description Style
	 * 
	 * @param	domElement
	 */
	public static function getCellDescriptionStyle(domElement:DOMElement):Void
	{
		getCellTextStyle(domElement);

		domElement.style.fontSize = FontSizeStyleValue.length(px(14));
		domElement.style.fontWeight = FontWeightStyleValue.bold;
	}

	/**
	 * Defines mouse over Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOverStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.hex('#333333');
	}
	
	/**
	 * Defines mouse out Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOutStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.hex('#666666');
	}
	
	/**
	 * Defines mouse down Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseDownStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.hex('#000000');
	}
	
	/**
	 * Defines mouse up Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseUpStyle(domElement:ContainerDOMElement):Void
	{
		domElement.style.color = ColorValue.hex('#333333');
	}
	
}
