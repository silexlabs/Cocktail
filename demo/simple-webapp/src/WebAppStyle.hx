/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

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
 * Defines the style of this web app
 * 
 * @author Raphael Harmel
 */

class WebAppStyle 
{

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

	}
	
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
	
	public static function getPageContainerStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);

		domElement.style.left = PositionOffsetStyleValue.auto;
		domElement.style.top = PositionOffsetStyleValue.auto;
	}
	
	public static function getHomePageStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		//getPageStyle(domElement);
	}
	
	public static function getPageStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);
	}
	
	public static function getBgStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);
	}
	
	
	public static function getHeaderStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.relative;
		domElement.style.display = DisplayStyleValue.block;
		//domElement.style.float = FloatStyleValue.left;
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

	
	public static function getBackButtonStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.absolute;
		domElement.style.float = FloatStyleValue.left;
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

		domElement.style.paddingLeft = PaddingStyleValue.length(px(15));
		domElement.style.paddingTop = PaddingStyleValue.length(px(12));
		//domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
	}

	public static function getHeaderTextStyle(domElement:DOMElement):Void
	{
		//getDefaultStyle(domElement);
		
		domElement.style.position = PositionStyleValue.absolute;
		//domElement.style.float = FloatStyleValue.none;
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
		//domElement.style.height = DimensionStyleValue.length(px(43));
		domElement.style.height = DimensionStyleValue.percent(100);
	}

	public static function getTextContentStyle(domElement:DOMElement):Void
	{
		domElement.style.paddingBottom = PaddingStyleValue.length(px(8));
		domElement.style.paddingLeft = PaddingStyleValue.length(px(8));
		domElement.style.paddingTop = PaddingStyleValue.length(px(8));
		domElement.style.paddingRight = PaddingStyleValue.length(px(8));
	}

	
}