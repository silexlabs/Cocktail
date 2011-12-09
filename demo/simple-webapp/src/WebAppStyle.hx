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

	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getDefaultStyle(domElement:DOMElement):Void
	{
		var computedStyle:ComputedStyleData = {
		width : 0,
		height : 0,
		minHeight : 0,
		maxHeight : 0,
		minWidth : 0,
		maxWidth : 0,
		marginLeft : 0,
		marginRight : 0,
		marginTop : 0,
		marginBottom : 0,
		paddingLeft : 0,
		paddingRight : 0,
		paddingTop : 0,
		paddingBottom : 0,
		left: 0,
		right: 0,
		top: 0,
		bottom : 0,
		clear : ClearStyleValue.none,
		float : FloatStyleValue.none,
		display : DisplayStyleValue.block,
		position: PositionStyleValue.staticStyle,
		verticalAlign : 0.0,
		fontSize:12.0,
		lineHeight:14.0,
		fontWeight:FontWeightStyleValue.normal,
		fontStyle:FontStyleStyleValue.normal,
		fontFamily:[FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.serif)],
		fontVariant:FontVariantStyleValue.normal,
		textTransform:TextTransformStyleValue.none,
		letterSpacing:0,
		wordSpacing:0,
		textIndent:0,
		whiteSpace:WhiteSpaceStyleValue.normal,
		textAlign:TextAlignStyleValue.left,
		color:0
		}
		
		domElement.style.computedStyle = computedStyle;

		//domElement.style.width = DimensionStyleValue.length(px(320));
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
		
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));

		domElement.style.position = PositionStyleValue.staticStyle;
	}
	
	/**
	 * Defines main container Style
	 * 
	 * @param	domElement
	 */
	public static function getMainContainerStyle(domElement:DOMElement):Void
	{
		getDefaultStyle(domElement);
		
		domElement.style.fontFamily = [FontFamilyStyleValue.familyName('Helvetica'), FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)];

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
		//getDefaultStyle(domElement);
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);

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
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);
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
		domElement.style.color = ColorValue.hex('222222');

		domElement.style.fontSize = FontSizeStyleValue.length(px(20));
		domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('Helvetica'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.textAlign = TextAlignStyleValue.center;

	}

	/**
	 * Defines header title text Style
	 * 
	 * @param	domElement
	 */
	public static function getHeaderTextStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.color = ColorValue.hex('EEEEEE');

		domElement.style.fontSize = FontSizeStyleValue.length(px(20));
		//domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('Helvetica'),
				FontFamilyStyleValue.genericFamily(GenericFontFamilyValue.sansSerif)
			];
		domElement.style.textAlign = TextAlignStyleValue.center;

		//domElement.style.paddingLeft = PaddingStyleValue.length(px(15));
		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.length(px(43));
		//domElement.style.height = DimensionStyleValue.percent(100);
	}

	/**
	 * Defines back button Style
	 * 
	 * @param	domElement
	 */
	public static function getBackButtonStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
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
		
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.color = ColorValue.hex('EEEEEE');

		domElement.style.fontSize = FontSizeStyleValue.length(px(14));
		domElement.style.lineHeight = LineHeightStyleValue.normal;
		domElement.style.fontWeight = FontWeightStyleValue.bold;
		domElement.style.fontStyle = FontStyleStyleValue.normal;
		domElement.style.fontFamily =
			[
				FontFamilyStyleValue.familyName('Helvetica'),
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