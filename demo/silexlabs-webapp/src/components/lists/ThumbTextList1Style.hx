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
import cocktail.viewport.Viewport;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import Constants;

// list
import components.lists.ListBaseModels;

// Utils
import Utils;
import ScreenResolution;

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
		domElement.style.paddingBottom = PaddingStyleValue.length(px(Constants.footerHeight));
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
		domElement.style.display = DisplayStyleValue.inlineBlock;
		domElement.style.width = DimensionStyleValue.percent(10);
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}
	
	/**
	 * Defines cell number Style
	 * 
	 * @param	domElement
	 */
	public static function getCellNumberStyle(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);
		
		var fontSize:Int = 12;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 12;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 16;
		else  fontSize = 20;
		domElement.style.fontSize = FontSizeStyleValue.length(px(fontSize));

		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.color = ColorValue.hex('#989898');
		domElement.style.textAlign = TextAlignStyleValue.center;
		domElement.style.paddingBottom = PaddingStyleValue.percent(2);
	}
	
	/**
	 * Defines comment count Style
	 * 
	 * @param	domElement
	 */
	public static function getCellCommentCountStyle(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);
		
		var fontSize:Int = 11;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 11;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 14;
		else  fontSize = 17;
		domElement.style.fontSize = FontSizeStyleValue.length(px(fontSize));

		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.color = ColorValue.hex('#CC3517');
		domElement.style.textAlign = TextAlignStyleValue.center;
	}
	
	/**
	 * Defines cell info block image Style
	 * 
	 * @param	domElement
	 */
	//public static function getCellInfoBlockImageStyle(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	public static function getCellInfoBlockLineStyle(domElement:ImageDOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.marginLeft = MarginStyleValue.autoValue;
		domElement.style.marginRight = MarginStyleValue.autoValue;
		domElement.style.marginTop = MarginStyleValue.autoValue;
		domElement.style.marginBottom = MarginStyleValue.autoValue;
		domElement.style.paddingBottom = PaddingStyleValue.percent(5);
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		//domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(domElement.intrinsicWidth));
		domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(50));
		domElement.style.width = DimensionStyleValue.percent(90);
	}
	
	/**
	 * Defines cell info block image Style
	 * 
	 * @param	domElement
	 */
	//public static function getCellInfoBlockImageStyle(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	public static function getCellInfoBlockImageStyle(domElement:ImageDOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.marginLeft = MarginStyleValue.autoValue;
		domElement.style.marginRight = MarginStyleValue.autoValue;
		domElement.style.marginTop = MarginStyleValue.autoValue;
		domElement.style.marginBottom = MarginStyleValue.autoValue;
		domElement.style.paddingBottom = PaddingStyleValue.percent(2);
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		//domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(domElement.intrinsicWidth));
		domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(20));
		domElement.style.width = DimensionStyleValue.percent(50);
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellThumbnailStyle(domElement:DOMElement):Void
	{
		getCellStyle(domElement);
		
		domElement.style.display = DisplayStyleValue.inlineStyle;
		
		domElement.style.paddingLeft = PaddingStyleValue.percent(1);
		domElement.style.paddingRight = PaddingStyleValue.percent(1);
		domElement.style.paddingBottom = PaddingStyleValue.percent(1);

		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(200));
		domElement.style.width = DimensionStyleValue.percent(30);
	}
	
	/**
	 * Defines cell line Style
	 * 
	 * @param	domElement
	 */
	public static function getCellLineStyle(domElement:DOMElement):Void
	{
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
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
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
	public static function getCellTitleStyle(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);
		
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
	public static function getCellCommentStyle(domElement:DOMElement,?screenResolutionSize:ScreenResolutionSize):Void
	{
		getCellTextStyle(domElement);

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
