/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.adapter;

import cocktail.core.style.CoreStyle;
import cocktail.core.unit.UnitManager;
import cocktail.core.style.StyleData;
import haxe.Log;

/**
 * This class is the public CSS Style API, similar
 * to using the Style object in JavaScript.
 * 
 * It proxies access to the CoreStyle which use typed
 * style object and set/get those styles using CSS
 * which it converts into typed style object
 * 
 * @author Yannick DOMINGUEZ
 */
class Style 
{
	/**
	 * display styles
	 */
	public var display(get_display, set_display):String;
	public var position(get_position, set_position):String;
	public var cssFloat(get_CSSFloat, set_CSSFloat):String;
	public var clear(get_clear, set_clear):String;
	
	/**
	 * box model styles
	 */
	public var marginLeft(get_marginLeft, set_marginLeft):String;
	public var marginRight(get_marginRight, set_marginRight):String;
	public var marginTop(get_marginTop, set_marginTop):String;
	public var marginBottom(get_marginBottom, set_marginBottom):String;
	
	public var paddingLeft(get_paddingLeft, set_paddingLeft):String;
	public var paddingRight(get_paddingRight, set_paddingRight):String;
	public var paddingTop(get_paddingTop, set_paddingTop):String;
	public var paddingBottom(get_paddingBottom, set_paddingBottom):String;

	public var width(get_width, set_width):String;
	public var height(get_height, set_height):String;
	
	public var minHeight(get_minHeight, set_minHeight):String;
	public var maxHeight(get_maxHeight, set_maxHeight):String;
	public var minWidth(get_minWidth, set_minWidth):String;
	public var maxWidth(get_maxWidth, set_maxWidth):String;

	public var top(get_top, set_top):String;
	public var left(get_left, set_left):String;
	public var bottom(get_bottom, set_bottom):String;
	public var right(get_right, set_right):String;
	
	/**
	 * background styles
	 */
	public var backgroundColor(get_backgroundColor, set_backgroundColor):String;
	public var backgroundImage(get_backgroundImage, set_backgroundImage):String;
	public var backgroundRepeat(get_backgroundRepeat, set_backgroundRepeat):String;
	public var backgroundOrigin(get_backgroundOrigin, set_backgroundOrigin):String;
	public var backgroundSize(get_backgroundSize, set_backgroundSize):String;
	public var backgroundPosition(get_backgroundPosition, set_backgroundPosition):String;
	public var backgroundClip(get_backgroundClip, set_backgroundClip):String;
	
	/**
	 * font styles
	 */
	public var fontSize(get_fontSize, set_fontSize):String;
	public var fontWeight(get_fontWeight, set_fontWeight):String;
	public var fontStyle(get_fontStyle, set_fontStyle):String;
	public var fontFamily(get_fontFamily, set_fontFamily ):String;
	public var fontVariant(get_fontVariant, set_fontVariant):String;
	public var color(get_color, set_color):String;
	
	/**
	 * text styles
	 */
	public var lineHeight(get_lineHeight, set_lineHeight):String;
	public var textTransform(get_textTransform, set_textTransform):String;
	public var letterSpacing(get_letterSpacing, set_letterSpacing):String;
	public var wordSpacing(get_wordSpacing, set_wordSpacing):String;
	public var whiteSpace(get_whiteSpace, set_whiteSpace):String;
	public var textAlign(get_textAlign, set_textAlign):String;
	public var textIndent(get_textIndent, set_textIndent):String;
	public var verticalAlign(get_verticalAlign, set_verticalAlign):String;
	
	/**
	 * visual effect styles
	 */
	public var opacity(get_opacity, set_opacity):String;
	public var visibility(get_visibility, set_visibility):String;
	public var overflowX(get_overflowX,  set_overflowX):String;
	public var overflowY(get_overflowY,  set_overflowY):String;
	
	/**
	 * user interface styles
	 */
	public var cursor(get_cursor, set_cursor):String;
	
	/**
	 * A ref to the CoreStyle instance wrapped 
	 * by this Style adapter
	 */
	private var _coreStyle:CoreStyle;
	
	/**
	 * class constructor. Store the ref to 
	 * the CoreStyle
	 */
	public function new(coreStyle:CoreStyle) 
	{
		_coreStyle = coreStyle;
	}

	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	private function get_opacity():String
	{
		return UnitManager.getCSSOpacity(_coreStyle.opacity);
	}
	
	private function set_opacity(value:String):String
	{
		//TODO : implement in UnitManager to check the value ?
		_coreStyle.opacity = Std.parseFloat(value);
		return value;
	}
	
	private function get_visibility():String
	{
		return UnitManager.getCSSVisibility(_coreStyle.visibility);
	}
	
	private function set_visibility(value:String):String
	{
		_coreStyle.visibility = UnitManager.visibilityEnum(value);
		return value;
	}
	
	private function get_marginLeft():String 
	{
		return UnitManager.getCSSMargin(_coreStyle.marginLeft);
	}
	
	private function set_marginLeft(value:String):String 
	{
		_coreStyle.marginLeft = UnitManager.boxStyleEnum(Margin, value);
		return value;
	}
	
	private function get_marginRight():String 
	{
		return UnitManager.getCSSMargin(_coreStyle.marginRight);
	}
	
	private function set_marginRight(value:String):String 
	{
		_coreStyle.marginRight = UnitManager.boxStyleEnum(Margin, value);
		return value;
	}
	
	private function get_marginTop():String 
	{
		return UnitManager.getCSSMargin(_coreStyle.marginTop);
	}
	
	private function set_marginTop(value:String):String 
	{
		_coreStyle.marginTop = UnitManager.boxStyleEnum(Margin, value);
		return value;
	}
	
	private function get_marginBottom():String 
	{
		return UnitManager.getCSSMargin(_coreStyle.marginBottom);
	}
	
	private function set_marginBottom(value:String):String 
	{
		_coreStyle.marginBottom = UnitManager.boxStyleEnum(Margin, value);
		return value;
	}
	
	private function get_paddingLeft():String 
	{
		return UnitManager.getCSSPadding(_coreStyle.paddingLeft);
	}
	
	private function set_paddingLeft(value:String):String 
	{
		_coreStyle.paddingLeft = UnitManager.boxStyleEnum(Padding, value);
		return value;
	}
	
	private function get_paddingRight():String 
	{
		return UnitManager.getCSSPadding(_coreStyle.paddingRight);
	}
	
	private function set_paddingRight(value:String):String
	{
		_coreStyle.paddingRight = UnitManager.boxStyleEnum(Padding, value);
		return value;
	}
	
	private function get_paddingTop():String 
	{
		return UnitManager.getCSSPadding(_coreStyle.paddingTop);
	}
	
	private function set_paddingTop(value:String):String 
	{
		_coreStyle.paddingTop = UnitManager.boxStyleEnum(Padding, value);
		return value;
	}
	
	private function get_paddingBottom():String 
	{
		return UnitManager.getCSSPadding(_coreStyle.paddingBottom);
	}
	
	private function set_paddingBottom(value:String):String 
	{
		_coreStyle.paddingBottom = UnitManager.boxStyleEnum(Padding, value);
		return value;
	}
	
	private function get_display():String 
	{
		return UnitManager.getCSSDisplay(_coreStyle.display);
	}
	
	private function set_display(value:String):String 
	{
		_coreStyle.display = UnitManager.displayEnum(value);
		return value;
	}
	
	private function get_position():String 
	{
		return UnitManager.getCSSPosition(_coreStyle.position);
	}
	
	private function set_position(value:String):String 
	{
		_coreStyle.position = UnitManager.positionEnum(value);
		return value;
	}
	
	private function get_width():String 
	{
		return UnitManager.getCSSDimension(_coreStyle.width);
	}
	
	private function set_width(value:String):String 
	{
		_coreStyle.width = UnitManager.boxStyleEnum(Dimension, value);
		return value;
	}
	
	private function get_height():String 
	{
		return UnitManager.getCSSDimension(_coreStyle.height);
	}
	
	private function set_height(value:String):String 
	{
		_coreStyle.height = UnitManager.boxStyleEnum(Dimension, value);
		return value;
	}
	
	private function get_minHeight():String 
	{
		return UnitManager.getCSSConstrainedDimension(_coreStyle.minHeight);
	}
	
	private function set_minHeight(value:String):String 
	{
		_coreStyle.minHeight = UnitManager.constrainedDimensionEnum(value);
		return value;
	}
	
	private function get_maxHeight():String 
	{
		return UnitManager.getCSSConstrainedDimension(_coreStyle.maxHeight);
	}

	private function set_maxHeight(value:String):String 
	{
		_coreStyle.maxHeight = UnitManager.constrainedDimensionEnum(value);
		return value;
	}
	
	private function get_minWidth():String 
	{
		return UnitManager.getCSSConstrainedDimension(_coreStyle.minWidth);
	}
		
	private function set_minWidth(value:String):String 
	{
		_coreStyle.minWidth = UnitManager.constrainedDimensionEnum(value);
		return value;
	}
	
	private function get_maxWidth():String 
	{
		return UnitManager.getCSSConstrainedDimension(_coreStyle.maxWidth);
	}
	
	private function set_maxWidth(value:String):String 
	{
		_coreStyle.maxWidth = UnitManager.constrainedDimensionEnum(value);
		return value;
	}
	
	private function get_top():String 
	{
		return UnitManager.getCSSPositionOffset(_coreStyle.top);
	}
	
	private function set_top(value:String):String 
	{
		_coreStyle.top = UnitManager.boxStyleEnum(PositionOffset, value);
		return value;
	}
	
	private function get_left():String 
	{
		return UnitManager.getCSSPositionOffset(_coreStyle.left);
	}
		
	private function set_left(value:String):String 
	{
		_coreStyle.left = UnitManager.boxStyleEnum(PositionOffset, value);
		return value;
	}
	
	private function get_bottom():String 
	{
		return UnitManager.getCSSPositionOffset(_coreStyle.bottom);
	}
	
	private function set_bottom(value:String):String 
	{
		_coreStyle.bottom = UnitManager.boxStyleEnum(PositionOffset, value);
		return value;
	}
	
	private function get_right():String 
	{
		return UnitManager.getCSSPositionOffset(_coreStyle.right);
	}
	
	private function set_right(value:String):String 
	{
		_coreStyle.right = UnitManager.boxStyleEnum(PositionOffset, value);
		return value;
	}
	
	private function get_CSSFloat():String 
	{
		return UnitManager.getCSSFloatAsString(_coreStyle.cssFloat);
	}
	
	private function set_CSSFloat(value:String):String 
	{
		_coreStyle.cssFloat = UnitManager.cssFloatEnum(value);
		return value;
	}
	
	private function get_clear():String 
	{
		return UnitManager.getCSSClear(_coreStyle.clear);
	}
	
	private function set_clear(value:String):String 
	{
		_coreStyle.clear = UnitManager.clearEnum(value);
		return value;
	}
	
	private function get_fontSize():String
	{
		return UnitManager.getCSSFontSize(_coreStyle.fontSize);
	}
	
	private function set_fontSize(value:String):String
	{
		_coreStyle.fontSize = UnitManager.fontSizeEnum(value);
		return value;
	}
	
	private function get_fontWeight():String
	{
		return UnitManager.getCSSFontWeight(_coreStyle.fontWeight);
	}
	
	private function set_fontWeight(value:String):String
	{
		_coreStyle.fontWeight = UnitManager.fontWeightEnum(value);
		return value;
	}
	
	private function get_fontStyle():String
	{
		return UnitManager.getCSSFontStyle(_coreStyle.fontStyle);
	}
	
	private function set_fontStyle(value:String):String
	{
		_coreStyle.fontStyle = UnitManager.fontStyleEnum(value);
		return value;
	}
	
	private function get_fontFamily():String
	{
		return UnitManager.getCSSFontFamily(_coreStyle.fontFamily);
	}
	
	private function set_fontFamily(value:String):String
	{
		_coreStyle.fontFamily = UnitManager.fontFamilyEnum(value);
		return value;
	}

	private function get_fontVariant():String
	{
		return UnitManager.getCSSFontVariant(_coreStyle.fontVariant);
	}
	
	private function set_fontVariant(value:String):String
	{
		_coreStyle.fontVariant = UnitManager.fontVariantEnum(value);
		return value;
	}
	
	private function get_textTransform():String
	{
		return UnitManager.getCSSTextTransform(_coreStyle.textTransform);
	}
	
	private function set_textTransform(value:String):String
	{
		_coreStyle.textTransform = UnitManager.textTransformEnum(value);
		return value;
	}
	
	private function get_letterSpacing():String
	{
		return UnitManager.getCSSLetterSpacing(_coreStyle.letterSpacing);
	}
	
	private function set_letterSpacing(value:String):String
	{
		_coreStyle.letterSpacing = UnitManager.letterSpacingEnum(value);
		return value;
	}
	
	private function get_color():String
	{
		return UnitManager.getCSSColor(_coreStyle.color);
	}
	
	private function set_color(value:String):String
	{
		_coreStyle.color = UnitManager.colorEnum(value);
		return value;
	}
	
	private function get_wordSpacing():String
	{
		return UnitManager.getCSSWordSpacing(_coreStyle.wordSpacing);
	}
	
	private function set_wordSpacing(value:String):String
	{
		_coreStyle.wordSpacing = UnitManager.wordSpacingEnum(value);
		return value;
	}
	
	private function get_lineHeight():String
	{
		return UnitManager.getCSSLineHeight(_coreStyle.lineHeight);
	}
	
	private function set_lineHeight(value:String):String
	{
		_coreStyle.lineHeight = UnitManager.lineHeightEnum(value);
		return value;
	}
	
	private function get_verticalAlign():String
	{
		return UnitManager.getCSSVerticalAlign(_coreStyle.verticalAlign);
	}
	
	private function set_verticalAlign(value:String):String
	{
		_coreStyle.verticalAlign = UnitManager.verticalAlignEnum(value);
		return value;
	}
	
	private function get_textIndent():String
	{
		return UnitManager.getCSSTextIndent(_coreStyle.textIndent);
	}
	
	private function set_textIndent(value:String):String
	{
		_coreStyle.textIndent = UnitManager.textIndentEnum(value);
		return value;
	}
	
	private function get_whiteSpace():String
	{
		return UnitManager.getCSSWhiteSpace(_coreStyle.whiteSpace);
	}
	
	private function set_whiteSpace(value:String):String
	{
		_coreStyle.whiteSpace = UnitManager.whiteSpaceEnum(value);
		return value;
	}
	
	private function get_textAlign():String
	{
		return UnitManager.getCSSTextAlign(_coreStyle.textAlign);
	}
	
	private function set_textAlign(value:String):String
	{
		_coreStyle.textAlign = UnitManager.textAlignEnum(value);
		return value;
	}
	
	private function set_backgroundColor(value:String):String
	{
		_coreStyle.backgroundColor = UnitManager.colorEnum(value);
		return value;
	}
	
	private function get_backgroundColor():String
	{
		return UnitManager.getCSSColor(_coreStyle.backgroundColor);
	}
	
	private function set_backgroundImage(value:String):String
	{
		_coreStyle.backgroundImage = UnitManager.backgroundImageEnum(value);
		return value;
	}
	
	private function get_backgroundImage():String
	{
		return UnitManager.getCSSBackgroundImage(_coreStyle.backgroundImage);
	}
	
	private function set_backgroundRepeat(value:String):String
	{
		_coreStyle.backgroundRepeat = UnitManager.backgroundRepeatEnum(value);
		return value;
	}
	
	private function get_backgroundRepeat():String
	{
		return UnitManager.getCSSBackgroundRepeat(_coreStyle.backgroundRepeat);
	}
	
	private function set_backgroundSize(value:String):String
	{
		_coreStyle.backgroundSize = UnitManager.backgroundSizeEnum(value);
		return value;
	}
	
	private function get_backgroundSize():String
	{
		return UnitManager.getCSSBackgroundSize(_coreStyle.backgroundSize);
	}
	
	private function set_backgroundClip(value:String):String
	{
		_coreStyle.backgroundClip = UnitManager.backgroundClipEnum(value);
		return value;
	}
	
	private function get_backgroundClip():String
	{
		return UnitManager.getCSSBackgroundClip(_coreStyle.backgroundClip);
	}
	
	private function set_backgroundPosition(value:String):String
	{
		_coreStyle.backgroundPosition = UnitManager.backgroundPositionEnum(value);
		return value;
	}
	
	private function get_backgroundPosition():String
	{
		return UnitManager.getCSSBackgroundPosition(_coreStyle.backgroundPosition);
	}
	
	private function set_backgroundOrigin(value:String):String
	{
		_coreStyle.backgroundOrigin = UnitManager.backgroundOriginEnum(value);
		return value;
	}
	
	private function get_backgroundOrigin():String
	{
		return UnitManager.getCSSBackgroundOrigin(_coreStyle.backgroundOrigin);
	}
	
	private function get_overflowX():String
	{
		return UnitManager.getCSSOverflow(_coreStyle.overflowX);
	}
	
	private function set_overflowX(value:String):String
	{
		_coreStyle.overflowX = UnitManager.overflowEnum(value);
		return value;
	}
	
	private function get_overflowY():String
	{
		return UnitManager.getCSSOverflow(_coreStyle.overflowY);
	}
	
	private function set_overflowY(value:String):String
	{
		_coreStyle.overflowY = UnitManager.overflowEnum(value);
		return UnitManager.getCSSOverflow(_coreStyle.overflowY);
	}
	
	private function set_cursor(value:String):String
	{
		_coreStyle.cursor = UnitManager.cursorEnum(value);
		return value;
	}
	
	private function get_cursor():String
	{
		return UnitManager.getCSSCursor(_coreStyle.cursor);
	}
	
}