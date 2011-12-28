/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package ;

// DOM
import cocktail.domElement.DOMElement;
import cocktailCore.style.StyleData;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;

/**
 * Defines the style of the web app
 * 
 * @author Raphael Harmel
 */

class WebAppStyle 
{
	static inline var headerHeight:Int = 43;
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getDefaultStyle(domElement:DOMElement):Void
	{
		
		//domElement.style.width = DimensionStyleValue.length(px(320));
		//domElement.style.width = DimensionStyleValue.percent(100);
		//domElement.style.minHeight = ConstrainedDimensionStyleValue.length(px(420));
		domElement.style.minHeight = ConstrainedDimensionStyleValue.percent(130);
	}
	
	/**
	 * Defines body Style
	 * 
	 * @param	domElement
	 */
	public static function getBodyStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.staticStyle;

		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
	}
	
	/**
	 * Defines main container Style
	 * 
	 * @param	domElement
	 */
	public static function getMainContainerStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		
		//domElement.style.width = DimensionStyleValue.percent(100);

		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));

		domElement.style.position = PositionStyleValue.staticStyle;
	}
	
	/**
	 * Defines page container Style
	 * 
	 * @param	domElement
	 */
	public static function getPageContainerStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		
		//domElement.style.width = DimensionStyleValue.percent(100);
		//domElement.style.height = DimensionStyleValue.percent(100);

		domElement.style.left = PositionOffsetStyleValue.auto;
		domElement.style.top = PositionOffsetStyleValue.auto;
	}
	
	/**
	 * Defines home page Style
	 * 
	 * @param	domElement
	 */
	public static function getHomePageStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		//getPageStyle(domElement);
	}
	
	/**
	 * Defines default page Style
	 * 
	 * @param	domElement
	 */
	public static function getPageStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);
	}
	
	/**
	 * Defines home background image style Style
	 * 
	 * @param	domElement
	 */
	public static function getBgStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
		domElement.style.right = PositionOffsetStyleValue.length(px(0));
		domElement.style.bottom = PositionOffsetStyleValue.length(px(0));
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);
		//domElement.style.width = DimensionStyleValue.length(px(100));
		//domElement.style.height = DimensionStyleValue.length(px(100));
	}
	
	
	/**
	 * Defines header Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.relative;
		domElement.style.display = DisplayStyleValue.block;
		
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
	}

	/**
	 * Defines header tile Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderTileStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);		
		getHeaderStyle(domElement);
		
		//domElement.style.position = PositionStyleValue.fixed;
		domElement.style.position = PositionStyleValue.relative;
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.bottom = PositionOffsetStyleValue.auto;
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(headerHeight));
	}

	/**
	 * Defines footer menu image Style
	 * 
	 * @param	domElement
	 */
	public static function getFooterMenuStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);		
		//getHeaderStyle(domElement);
		
		//domElement.style.position = PositionStyleValue.fixed;
		domElement.style.position = PositionStyleValue.fixed;
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.top = PositionOffsetStyleValue.auto;
		domElement.style.bottom = PositionOffsetStyleValue.length(px(0));
		domElement.style.width = DimensionStyleValue.auto;
		//domElement.style.height = DimensionStyleValue.length(px(headerHeight));
	}

	/**
	 * Defines footer tile Style
	 * 
	 * @param	domElement
	 */
	public static function getFooterTileStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);		
		getHeaderStyle(domElement);
		
		domElement.style.position = PositionStyleValue.fixed;
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.top = PositionOffsetStyleValue.auto;
		domElement.style.bottom = PositionOffsetStyleValue.length(px(0));
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(headerHeight));
	}

	/**
	 * Defines header title text Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderTextStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		getHeaderStyle(domElement);
		
		//domElement.style.position = PositionStyleValue.fixed;
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.color = ColorValue.hex('#454545');

		domElement.style.fontSize = FontSizeStyleValue.length(px(20));
		//domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('HelveticaNeue'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.textAlign = TextAlignStyleValue.center;

		//domElement.style.paddingLeft = PaddingStyleValue.length(px(15));
		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		
		domElement.style.width = DimensionStyleValue.percent(100);
		//domElement.style.width = DimensionStyleValue.auto;
		domElement.style.height = DimensionStyleValue.length(px(headerHeight));
		//domElement.style.height = DimensionStyleValue.percent(100);
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}

	/**
	 * Defines back button Style
	 * 
	 * @param	domElement
	 */
	public static function getBackButtonStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		getHeaderStyle(domElement);
		
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.paddingTop = PaddingStyleValue.length(px(6));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(10));
	}

	/**
	 * Defines back button text Style
	 * 
	 * @param	domElement
	 */
	public static function getBackButtonTextStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		getHeaderStyle(domElement);
		
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.color = ColorValue.hex('#EEEEEE');

		domElement.style.fontSize = FontSizeStyleValue.length(px(14));
		domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('HelveticaNeue'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.textAlign = TextAlignStyleValue.center;

		domElement.style.paddingTop = PaddingStyleValue.length(px(12));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(30));
		//domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}

	/**
	 * Defines back button image Style
	 * 
	 * @param	domElement
	 */
	public static function getBackButtonImageStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		getHeaderStyle(domElement);

		domElement.style.display = DisplayStyleValue.inlineStyle;
		domElement.style.position = PositionStyleValue.relative;
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.left = PositionOffsetStyleValue.length(px(0));
	}

	/**
	 * Defines text content Style
	 * 
	 * @param	domElement
	 */
	public static function getTextContentStyle(domElement:DOMElement):Void
	{
		domElement.style.paddingBottom = PaddingStyleValue.length(px(8));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(8));
		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		domElement.style.paddingRight = PaddingStyleValue.length(px(8));
	}
	
}