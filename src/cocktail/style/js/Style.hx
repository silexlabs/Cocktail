/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.js;

import cocktail.domElement.DOMElement;
import cocktail.style.abstract.AbstractStyle;
import haxe.Log;

import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class Style extends AbstractStyle
{
	
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	
	private function getConvertedValue(lengthValue:LengthValue):String
	{
		var ret:String;
		
		switch (lengthValue)
		{
			case px(pixelValue):
				ret = Std.string(pixelValue) + "px";
				
			case pt(pointValue):
				ret = Std.string(pointValue) + "pt";
				
			case mm(milimetersValue):
				ret = Std.string(milimetersValue) + "mm";
				
			case pc(picasValue):
				ret = Std.string(picasValue) + "pc";
				
			case cm(centimetersValue):
				ret = Std.string(centimetersValue) + "cm";
				
			case _in(inchesValue):
				ret = Std.string(inchesValue) + "in";
		}
	
		return ret;	
	}
	
	private function getTextAlignStyleValue(value:TextAlignStyleValue):String
	{
		var textAlignValue:String;
		
		switch (value)
		{
			case TextAlignStyleValue.left:
				textAlignValue = "left";
				
			case TextAlignStyleValue.right:
				textAlignValue = "right";
				
			case TextAlignStyleValue.center:
				textAlignValue = "center";
				
			case TextAlignStyleValue.justify:
				textAlignValue = "justify";
		}
		
		return textAlignValue;
	}
	
	private function getWhiteSpaceStyleValue(value:WhiteSpaceStyleValue):String
	{
		var whiteSpaceValue:String;
		
		switch (value)
		{
			case WhiteSpaceStyleValue.normal:
				whiteSpaceValue = "normal";
				
			case pre:
				whiteSpaceValue = "pre";
				
			case nowrap:
				whiteSpaceValue = "nowrap";
				
			case preWrap:
				whiteSpaceValue = "pre-wrap";
				
			case preLine:
				whiteSpaceValue = "pre-line";
		}
		
		return whiteSpaceValue;
	}
	
	private function getFontSizeValue(value:FontSizeStyleValue):String
	{
		var fontValue:String;
		
		switch (value)
		{
			case length(unit):
				fontValue = getConvertedValue(unit);
		}
		
		return fontValue;
	}
	
	private function getLineHeightValue(value:LineHeightStyleValue):String
	{
		var lineHeightValue:String;
		
		switch (value)
		{
			case length(unit):
				lineHeightValue = getConvertedValue(unit);
				
			case normal:
				lineHeightValue = "normal";
				
			case percentage(value):
				lineHeightValue = Std.string(value) + "%";
				
			case number(value):
				lineHeightValue = Std.string(value);	
		}
		
		return lineHeightValue;
	}
	
	private function getMarginValue(value:MarginStyleValue):String
	{
		var marginValue:String;
		
		switch(value)
		{
			case length(unit):
				marginValue = getConvertedValue(unit);
			
			case percent(percentValue):
				marginValue = Std.string(percentValue) + "%";
				
			case auto:
				marginValue = "auto";
		}
		
		return marginValue;
	}
	
	private function getPaddingValue(value:PaddingStyleValue):String
	{
		var paddingValue:String;
		
		switch(value)
		{
			case length(unit):
				paddingValue = getConvertedValue(unit);
			
			case percent(percentValue):
				paddingValue = Std.string(percentValue) + "%";
		}
		
		return paddingValue;
	}
	
	private function getDimensionValue(value:DimensionStyleValue):String
	{
		var dimensionValue:String;
		
		switch (value)
		{
			case DimensionStyleValue.length(unit):
				dimensionValue = getConvertedValue(unit);
				
			case DimensionStyleValue.percent(percentValue):
				dimensionValue = Std.string(percentValue) + "%";
				
			case DimensionStyleValue.auto:
				dimensionValue = "auto";
		}
		
		return dimensionValue;
	}
	
	private function getPositionOffsetStyleValue(value:PositionOffsetStyleValue):String
	{
		var positionOffsetValue:String;
		
		switch (value)
		{
			case length(unit):
				positionOffsetValue = getConvertedValue(unit);	
			
			
			case percent(percentValue):
				positionOffsetValue = Std.string(percentValue) + "%";
				
			case auto:
				positionOffsetValue = "auto";
		}
		
		return positionOffsetValue;
	}
	
	private function getConstrainedDimensionValue(value:ConstrainedDimensionStyleValue):String
	{
		var constrainedValue:String;
		
		switch (value)
		{
			case length(unit):
				constrainedValue = getConvertedValue(unit);
			
			case percent(percentValue):
				constrainedValue = Std.string(percentValue) + "%";
				
			case none:	
				constrainedValue = "none";
		}
		
		return constrainedValue;
		
	}
	
	private function getFontWeightValue(value:FontWeightStyleValue):String
	{
		var fontWeightValue:String;
		
		switch (value)
		{
			case normal:
				fontWeightValue = "normal";
				
			case bold:
				fontWeightValue = "bold";
		}
		
		return fontWeightValue;
	}
	
	private function getFontStyleValue(value:FontStyleStyleValue):String
	{
		var fontStyleValue:String;
		
		switch (value)
		{
			case normal:
				fontStyleValue = "normal";
				
			case italic:
				fontStyleValue = "italic";
		}
		
		return fontStyleValue;
	}
	
	private function getFontVariantValue(value:FontVariantStyleValue):String
	{
		var fontVariantValue:String;
		
		switch (value)
		{
			case normal:
				fontVariantValue = "normal";
				
			case smallCaps:
				fontVariantValue = "small-caps";
		}
		
		return fontVariantValue;
	}
	
	private function getFontFamilyValue(value:Array<FontFamilyStyleValue>):String
	{
		var fontFamilyValue:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String;
			
			switch (value[i])
			{
				case FontFamilyStyleValue.familyName(name):
					fontName = name;
				
				case FontFamilyStyleValue.genericFamily(genericName):
					switch (genericName)
					{
						case GenericFontFamilyValue.serif:
							fontName = "serif";
						
						case GenericFontFamilyValue.sansSerif:
							fontName = "sans-serif";
							
						case GenericFontFamilyValue.monospace:
							fontName = "monospace";
					}
			}
			
			if (fontName.indexOf(" ") != -1)
			{
				fontName = "'" + fontName + "'";
			}
			
			fontFamilyValue += fontName;
			
			if (i < value.length -1)
			{
				fontFamilyValue += ",";
			}
		}
		
		return fontFamilyValue;
	}
	
	private function getTextTransformValue(value:TextTransformStyleValue):String
	{
		var textTransformValue:String;
		
		switch (value)
		{
			case none:
				textTransformValue = "none";
				
			case uppercase:
				textTransformValue = "uppercase";
				
			case lowercase:
				textTransformValue = "lowercase";
				
			case capitalize:
				textTransformValue = "capitalize";
		}
		
		return textTransformValue;
	}
	
	private function getLetterSpacingValue(value:LetterSpacingStyleValue):String
	{
		var letterSpacingValue:String;
		
		switch (value)
		{
			case normal:
				letterSpacingValue = "normal";
				
			case length(unit):
				letterSpacingValue = getConvertedValue(unit);
		}
		
		return letterSpacingValue;
	}
	
	private function getWordSpacingValue(value:WordSpacingStyleValue):String
	{
		var wordSpacingValue:String;
		
		switch (value)
		{
			case normal:
				wordSpacingValue = "normal";
				
			case length(unit):
				wordSpacingValue = getConvertedValue(unit);
		}
		
		return wordSpacingValue;
	}
	
	private function getColorValue(value:ColorStyleValue):String
	{
		var colorValue:String;
		
		switch (value)
		{
			case numeric(value):
				colorValue = getColorFromValue(value);
				
			case keyword(value):
				colorValue = getColorFromKeyword(value);
		}
		
		return colorValue;
	}
	
	private function getColorFromValue(value:ColorValue):String
	{
		var colorValue:String;
		
		switch (value)
		{
			case hex(value):
				colorValue = value;
				
			case RGB(red, green, blue):
				colorValue = "rgb(" + red + "," + green + "," + blue + ")";
		}
		
		return colorValue;
	}
	
	private function getColorFromKeyword(value:ColorKeywordValue):String
	{
		var hexColor:String;
		
		switch (value)
		{
			case aqua:
				hexColor = "aqua";
				
			case black:
				hexColor = "black";
				
			case blue:
				hexColor = "blue";
				
			case fuchsia:
				hexColor = "fuchsia";
				
			case gray:
				hexColor = "gray";
				
			case green:
				hexColor = "green";
				
			case lime:
				hexColor = "lime";
				
			case maroon:
				hexColor = "maroon";
				
			case navy:
				hexColor = "navy";
				
			case olive:
				hexColor = "olive";
				
			case orange:
				hexColor = "orange";
				
			case purple:
				hexColor = "purple";
				
			case red:
				hexColor = "red";
				
			case silver:
				hexColor = "silver";
				
			case teal:
				hexColor = "teal";
				
			case white:
				hexColor = "white";
				
			case yellow:
				hexColor = "yellow";
				
		}
		
		return hexColor;
	}
	
	private function getVerticalAlignValue(value:VerticalAlignStyleValue):String
	{
		var verticalAlignValue:String;
		
		switch (value)
		{
			case baseline:
				verticalAlignValue = "baseline";
				
			case middle:
				verticalAlignValue = "middle";
				
			case sub:
				verticalAlignValue = "sub";
				
			case _super:
				verticalAlignValue = "super";
				
			case textTop:
				verticalAlignValue = "text-top";
				
			case textBottom:
				verticalAlignValue = "text-bottom";
				
			case VerticalAlignStyleValue.top:
				verticalAlignValue = "top";
				
			case VerticalAlignStyleValue.bottom:
				verticalAlignValue = "bottom";
				
			case percent(value):
				verticalAlignValue = value + "%";
				
			case length(value):
				verticalAlignValue = getConvertedValue(value);
		}
		
		return verticalAlignValue;
		
	}
	
	private function getTextIndentStyleValue(value:TextIndentStyleValue):String
	{
		var textIndentValue:String;
		
		switch (value)
		{
			case length(value):
				textIndentValue = getConvertedValue(value);
				
			case percentage(value):
				textIndentValue = value + "%";
		}
		
		return textIndentValue;
	}
	
	/////////////////////////////////
	// STYLES SETTERS/GETTERS
	////////////////////////////////
	
	override private function setVerticalAlign(value:VerticalAlignStyleValue):VerticalAlignStyleValue
	{
		this._domElement.nativeElement.style.verticalAlign = getVerticalAlignValue(value);
		return _verticalAlign = value;
	}
	
	override private function setColor(value:ColorStyleValue):ColorStyleValue
	{
		this._domElement.nativeElement.style.color = getColorValue(value);
		return _color = value;
	}
	
	override private function setWordSpacing(value:WordSpacingStyleValue):WordSpacingStyleValue
	{
		this._domElement.nativeElement.style.wordSpacing = getWordSpacingValue(value);
		return _wordSpacing = value;
	}
	
	override private function setLetterSpacing(value:LetterSpacingStyleValue):LetterSpacingStyleValue
	{
		this._domElement.nativeElement.style.letterSpacing = getLetterSpacingValue(value);
		return _letterSpacing = value;
	}
	
	override private function setTextTransform(value:TextTransformStyleValue):TextTransformStyleValue
	{
		this._domElement.nativeElement.style.textTransform = getTextTransformValue(value);
		return _textTransform = value;
	}
	
	override private function setFontVariant(value:FontVariantStyleValue):FontVariantStyleValue
	{
		this._domElement.nativeElement.style.fontVariant = getFontVariantValue(value);
		return _fontVariant = value;
	}
	
	override private function setFontFamily(value:Array<FontFamilyStyleValue>):Array<FontFamilyStyleValue>
	{
		this._domElement.nativeElement.style.fontFamily = getFontFamilyValue(value);
		return _fontFamily = value;
	}
	
	override private function setFontWeight(value:FontWeightStyleValue):FontWeightStyleValue
	{
		this._domElement.nativeElement.style.fontWeight = getFontWeightValue(value);
		return _fontWeight = value;
	}
	
	override private function setFontStyle(value:FontStyleStyleValue):FontStyleStyleValue
	{
		this._domElement.nativeElement.style.fontStyle = getFontStyleValue(value);
		return _fontStyle = value;
	}
	
	
	override private function setFontSize(value:FontSizeStyleValue):FontSizeStyleValue
	{
		this._domElement.nativeElement.style.fontSize = getFontSizeValue(value);
		return _fontSize = value;
	}
	
	override private function setLineHeight(value:LineHeightStyleValue):LineHeightStyleValue
	{
		this._domElement.nativeElement.style.lineHeight = getLineHeightValue(value);
		return _lineHeight = value;
	}
	
	override private function setMarginLeft(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginLeft = getMarginValue(value);
		return _marginLeft = value;
	}
	
	override private function setMarginRight(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginRight = getMarginValue(value);
		return _marginRight = value;
	}
	
	override private function setMarginTop(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginTop = getMarginValue(value);
		return _marginTop = value;
	}
	
	override private function setMarginBottom(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginBottom = getMarginValue(value);
		return _marginBottom = value;
	}
	
	override private function setPaddingLeft(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingLeft = getPaddingValue(value);
		return _paddingLeft = value;
	}
	
	override private function setPaddingRight(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingRight = getPaddingValue(value);
		return _paddingRight = value;
	}
	
	override private function setPaddingTop(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingTop = getPaddingValue(value);
		return _paddingTop = value;
	}
	
	override private function setPaddingBottom(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingBottom = getPaddingValue(value);
		return _paddingBottom = value;
	}
	
	override private function setDisplay(value:DisplayStyleValue):DisplayStyleValue 
	{
		var displayValue:String;
		
		switch (value)
		{
			case block:
				displayValue = "block";
			
			case _inline:
				displayValue = "inline";
			
			case inlineBlock:
				displayValue = "inline-block";
				
			case DisplayStyleValue.none:
				displayValue = "none";
		}
		this._domElement.nativeElement.style.display = displayValue;
		
		return _display = value;
	}
	
	override private function setPosition(value:PositionStyleValue):PositionStyleValue 
	{
		var positionValue:String;
		
		switch (value)
		{
			case _static:
				positionValue = "static";
			
			case relative:
				positionValue = "relative";
			
			case absolute:
				positionValue = "absolute";
				
			case fixed:
				positionValue = "fixed";
		}
		
		this._domElement.nativeElement.style.position = positionValue;
		
		return _position = value;
	}
	
	override private function setWidth(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.width = getDimensionValue(value);
		
		return _width = value;
	}
	
	override private function setHeight(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.height = getDimensionValue(value);
		
		return _height = value;
	}
	
	override private function setMinHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minHeight = getConstrainedDimensionValue(value);
		return _minHeight = value;
	}
	
	override private function setMaxHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxHeight = getConstrainedDimensionValue(value);
		return _maxHeight = value;
	}
	
	override private function setMinWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minWidth = getConstrainedDimensionValue(value);
		return _minWidth = value;
	}
	
	override private function setMaxWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxWidth = getConstrainedDimensionValue(value);
		return _maxWidth = value;
	}
	
	override private function setTop(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.top = getPositionOffsetStyleValue(value);
		return _top = value;
	}
	
	override private function setLeft(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.left = getPositionOffsetStyleValue(value);
		return _left = value;
	}
	
	override private function setBottom(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.bottom = getPositionOffsetStyleValue(value);
		return _bottom = value;
	}
	
	override private function setRight(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.right = getPositionOffsetStyleValue(value);
		return _right = value;
	}
	
	override private function setTextIndent(value:TextIndentStyleValue):TextIndentStyleValue
	{
		this._domElement.nativeElement.style.textIndent = getTextIndentStyleValue(value);
		return _textIndent = value;
	}
	
	override private function setFloat(value:FloatStyleValue):FloatStyleValue 
	{
		var floatValue:String;
		
		switch (value)
		{
			case FloatStyleValue.left:
				floatValue = "left";
				
			case FloatStyleValue.right:
				floatValue = "right";
				
			case FloatStyleValue.none:
				floatValue = "none";
		}
		
		untyped this._domElement.nativeElement.style.cssFloat = floatValue;
		
		return _float = value;
	}
	
	override private function setClear(value:ClearStyleValue):ClearStyleValue 
	{
		var clearValue:String;
		
		switch (value)
		{
			case ClearStyleValue.left:
				clearValue = "left";
				
			case ClearStyleValue.right:
				clearValue = "right";
				
			case ClearStyleValue.both:
				clearValue = "both";
				
			case ClearStyleValue.none:
				clearValue = "none";
		}
		
		this._domElement.nativeElement.style.clear = clearValue;
		
		return _clear = value;
	}
	
	override private function setWhiteSpace(value:WhiteSpaceStyleValue):WhiteSpaceStyleValue
	{
		this._domElement.nativeElement.style.whiteSpace = getWhiteSpaceStyleValue(value);
		return _whiteSpace = value;
	}
	
	override private function setTextAlign(value:TextAlignStyleValue):TextAlignStyleValue
	{
		this._domElement.nativeElement.style.textAlign = getTextAlignStyleValue(value);
		return _textAlign = value;
	}
	
}