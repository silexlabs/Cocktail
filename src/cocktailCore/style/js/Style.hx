/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.js;

import cocktail.domElement.DOMElement;
import cocktailCore.style.abstract.AbstractStyle;
import cocktail.unit.UnitData;
import haxe.Log;

import cocktail.style.StyleData;

/**
 * In JavaScript, Styles are converted to native CSS styles and thus the browser manages the layout
 * and Styles of the document, not Cocktail. It would have been possible
 * to re-implement styles in JS, for instance processing the layout of the document 
 * entirely in JS, like in the Flash runtime but it would have had the following drawbacks : 
 * 
 * - way worse performance
 * - generate non-standard HTML (e.g : to manage the layout in pure JS, all HTML elements should
 * have been positionned as 'absolute' instead on relying on the standard document's flow
 * - Some limitations would have occured such as floats which would have been very difficult 
 * to reproduce in pure JS
 * 
 * On the other hand, relying on CSS implies a few browser inconsistencies.
 * 
 * For each abstract style applied to a DOMElement, this class converts it to a CSS String
 * which is applied to the style object of the native HTML element
 * 
 * @author Yannick DOMINGUEZ
 */
class Style extends AbstractStyle
{
	
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	/////////////////////////////////
	// DISPLAY STYLES
	////////////////////////////////
	
	/**
	 * CSS : display
	 */
	private function getCSSDisplay(value:DisplayStyleValue):String
	{
		var displayValue:String;
		
		switch (value)
		{
			case block:
				displayValue = "block";
			
			case inlineStyle:
				displayValue = "inline";
			
			case inlineBlock:
				displayValue = "inline-block";
				
			case DisplayStyleValue.none:
				displayValue = "none";
		}
		
		return displayValue;
	}
	
	/**
	 * CSS : float
	 */
	private function getCSSFloat(value:FloatStyleValue):String
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
		
		return floatValue;
	}
	
	/**
	 * CSS : clear
	 */
	private function getCSSClear(value:ClearStyleValue):String
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
		
		return clearValue;
	}
	
	/**
	 * CSS : position
	 */
	private function getCSSPosition(value:PositionStyleValue):String
	{
		var positionValue:String;
		
		switch (value)
		{
			case staticStyle:
				positionValue = "static";
			
			case relative:
				positionValue = "relative";
			
			case absolute:
				positionValue = "absolute";
				
			case fixed:
				positionValue = "fixed";
		}
		
		return positionValue;
	}
	
	/////////////////////////////////
	// BOX MODEL STYLES
	////////////////////////////////
	
	/**
	 * CSS : margin-top, margin-left...
	 */
	private function getCSSMargin(value:MarginStyleValue):String
	{
		var marginValue:String;
		
		switch(value)
		{
			case length(unit):
				marginValue = getCSSLengthValue(unit);
			
			case percent(percentValue):
				marginValue = getCSSPercentValue(Std.string(percentValue));
				
			case auto:
				marginValue = "auto";
		}
		
		return marginValue;
	}
	
	/**
	 * CSS : padding-top, padding-left...
	 */
	private function getCSSPadding(value:PaddingStyleValue):String
	{
		var paddingValue:String;
		
		switch(value)
		{
			case length(unit):
				paddingValue = getCSSLengthValue(unit);
			
			case percent(percentValue):
				paddingValue = getCSSPercentValue(Std.string(percentValue));
		}
		
		return paddingValue;
	}
	
	/**
	 * CSS : width, height
	 */
	private function getCSSDimension(value:DimensionStyleValue):String
	{
		var dimensionValue:String;
		
		switch (value)
		{
			case DimensionStyleValue.length(unit):
				dimensionValue = getCSSLengthValue(unit);
				
			case DimensionStyleValue.percent(percentValue):
				dimensionValue = getCSSPercentValue(Std.string(percentValue));
				
			case DimensionStyleValue.auto:
				dimensionValue = "auto";
		}
		
		return dimensionValue;
	}
	
	/**
	 * CSS : top, left, right, bottom
	 */
	private function getCSSPositionOffset(value:PositionOffsetStyleValue):String
	{
		var positionOffsetValue:String;
		
		switch (value)
		{
			case length(unit):
				positionOffsetValue = getCSSLengthValue(unit);	
			
			
			case percent(percentValue):
				positionOffsetValue = getCSSPercentValue(Std.string(percentValue));
				
			case auto:
				positionOffsetValue = "auto";
		}
		
		return positionOffsetValue;
	}
	
	/**
	 * CSS : min-width, max-width, min-height, max-height
	 */
	private function getCSSConstrainedDimension(value:ConstrainedDimensionStyleValue):String
	{
		var constrainedValue:String;
		
		switch (value)
		{
			case length(unit):
				constrainedValue = getCSSLengthValue(unit);
			
			case percent(percentValue):
				constrainedValue = getCSSPercentValue(Std.string(percentValue));
				
			case none:	
				constrainedValue = "none";
		}
		
		return constrainedValue;
		
	}
	
	/**
	 * CSS : vertical-align
	 */
	private function getCSSVerticalAlign(value:VerticalAlignStyleValue):String
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
				
			case superStyle:
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
				verticalAlignValue = getCSSPercentValue(Std.string(value));
				
			case length(value):
				verticalAlignValue = getCSSLengthValue(value);
		}
		
		return verticalAlignValue;
		
	}
	
	/**
	 * CSS : line-height
	 */
	private function getCSSLineHeight(value:LineHeightStyleValue):String
	{
		var lineHeightValue:String;
		
		switch (value)
		{
			case length(unit):
				lineHeightValue = getCSSLengthValue(unit);
				
			case normal:
				lineHeightValue = "normal";
				
			case percentage(value):
				lineHeightValue = getCSSPercentValue(Std.string(value));
				
			case number(value):
				lineHeightValue = Std.string(value);	
		}
		
		return lineHeightValue;
	}
	
	/////////////////////////////////
	// FONT STYLES
	////////////////////////////////
	
		
	/**
	 * CSS : font-size
	 */
	private function getCSSFontSize(value:FontSizeStyleValue):String
	{
		var fontValue:String;
		
		switch (value)
		{
			case length(unit):
				fontValue = getCSSLengthValue(unit);
				
			case percentage(percent):
				fontValue = getCSSPercentValue(Std.string(percent));
				
			case absoluteSize(value):
				switch (value)
				{
					case xxSmall:
						fontValue = "xx-small";
					
					case xSmall:
						fontValue = "x-small";
						
					case small:
						fontValue = "small";
						
					case medium:
						fontValue = "medium";
						
					case large:
						fontValue = "large";
						
					case xLarge:
						fontValue = "x-large";
						
					case xxLarge:	
						fontValue = "xx-large";
				}
				
			case relativeSize(value):
				switch (value)
				{
					case larger:
						fontValue = "larger";
						
					case smaller:
						fontValue = "smaller";
				}
		}
		
		return fontValue;
	}
	
	/**
	 * CSS : font-weight
	 */
	private function getCSSFontWeight(value:FontWeightStyleValue):String
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
	
	/**
	 * CSS : font-style
	 */
	private function getCSSFontStyle(value:FontStyleStyleValue):String
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
	
	/**
	 * CSS : font-variant
	 */
	private function getCSSFontVariant(value:FontVariantStyleValue):String
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
	
	/**
	 * CSS : font-family
	 */
	private function getCSSFontFamily(value:Array<FontFamilyStyleValue>):String
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
			
			//escapes font name constituted of multiple words
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
	
	/////////////////////////////////
	// TEXT STYLES
	////////////////////////////////
	
	/**
	 * CSS : text-align
	 */
	private function getCSSTextAlign(value:TextAlignStyleValue):String
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
	
	/**
	 * CSS : white-space
	 */
	private function getCSSWhiteSpace(value:WhiteSpaceStyleValue):String
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
	
	/**
	 * CSS : text-transform
	 */
	private function getCSSTextTransform(value:TextTransformStyleValue):String
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
	
	/**
	 * CSS : text-indent
	 */
	private function getCSSTextIndent(value:TextIndentStyleValue):String
	{
		var textIndentValue:String;
		
		switch (value)
		{
			case length(value):
				textIndentValue = getCSSLengthValue(value);
				
			case percentage(value):
				textIndentValue = getCSSPercentValue(Std.string(value));
		}
		
		return textIndentValue;
	}
	
	/**
	 * CSS : letter-spacing
	 */
	private function getCSSLetterSpacing(value:LetterSpacingStyleValue):String
	{
		var letterSpacingValue:String;
		
		switch (value)
		{
			case normal:
				letterSpacingValue = "normal";
				
			case length(unit):
				letterSpacingValue = getCSSLengthValue(unit);
		}
		
		return letterSpacingValue;
	}
	
	/**
	 * CSS : word-spacing
	 */
	private function getCSSWordSpacing(value:WordSpacingStyleValue):String
	{
		var wordSpacingValue:String;
		
		switch (value)
		{
			case normal:
				wordSpacingValue = "normal";
				
			case length(unit):
				wordSpacingValue = getCSSLengthValue(unit);
		}
		
		return wordSpacingValue;
	}
	
	/**
	 * CSS : color
	 */
	private function getCSSColor(value:ColorValue):String
	{
		var colorValue:String;
		
		switch (value)
		{
			case hex(value):
				colorValue = value;
				
			case RGB(red, green, blue):
				colorValue = "rgb(" + red + "," + green + "," + blue + ")";
				
		
			case keyword(value):
				colorValue = getColorFromKeyword(value);
		}
		
		return colorValue;
	}
	
	/////////////////////////////////
	// UNIT CONVERSION
	// Convert abstract styles units
	// to CSS units
	////////////////////////////////
	
	private function getCSSLengthValue(lengthValue:LengthValue):String
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
				
			case em(emValue	):
				ret = Std.string(emValue) + "em";
				
			case ex(exValue):
				ret = Std.string(exValue) + "ex";
		}
	
		return ret;	
	}
	
	private function getCSSPercentValue(value:String):String
	{
		return value + "%";
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
	
	/////////////////////////////////
	// OVERRIDEN STYLES SETTERS
	// All methods convert the Style
	// value into a CSS style value
	// (as a String) and set the native
	// CSS style on the DOMElement's
	// NativeElement
	////////////////////////////////
	
	override private function setVerticalAlign(value:VerticalAlignStyleValue):VerticalAlignStyleValue
	{
		this._domElement.nativeElement.style.verticalAlign = getCSSVerticalAlign(value);
		return _verticalAlign = value;
	}
	
	override private function setColor(value:ColorValue):ColorValue
	{
		this._domElement.nativeElement.style.color = getCSSColor(value);
		return _color = value;
	}
	
	override private function setWordSpacing(value:WordSpacingStyleValue):WordSpacingStyleValue
	{
		this._domElement.nativeElement.style.wordSpacing = getCSSWordSpacing(value);
		return _wordSpacing = value;
	}
	
	override private function setLetterSpacing(value:LetterSpacingStyleValue):LetterSpacingStyleValue
	{
		this._domElement.nativeElement.style.letterSpacing = getCSSLetterSpacing(value);
		return _letterSpacing = value;
	}
	
	override private function setTextTransform(value:TextTransformStyleValue):TextTransformStyleValue
	{
		this._domElement.nativeElement.style.textTransform = getCSSTextTransform(value);
		return _textTransform = value;
	}
	
	override private function setFontVariant(value:FontVariantStyleValue):FontVariantStyleValue
	{
		this._domElement.nativeElement.style.fontVariant = getCSSFontVariant(value);
		return _fontVariant = value;
	}
	
	override private function setFontFamily(value:Array<FontFamilyStyleValue>):Array<FontFamilyStyleValue>
	{
		this._domElement.nativeElement.style.fontFamily = getCSSFontFamily(value);
		return _fontFamily = value;
	}
	
	override private function setFontWeight(value:FontWeightStyleValue):FontWeightStyleValue
	{
		this._domElement.nativeElement.style.fontWeight = getCSSFontWeight(value);
		return _fontWeight = value;
	}
	
	override private function setFontStyle(value:FontStyleStyleValue):FontStyleStyleValue
	{
		this._domElement.nativeElement.style.fontStyle = getCSSFontStyle(value);
		return _fontStyle = value;
	}
	
	override private function setFontSize(value:FontSizeStyleValue):FontSizeStyleValue
	{
		this._domElement.nativeElement.style.fontSize = getCSSFontSize(value);
		return _fontSize = value;
	}
	
	override private function setLineHeight(value:LineHeightStyleValue):LineHeightStyleValue
	{
		this._domElement.nativeElement.style.lineHeight = getCSSLineHeight(value);
		return _lineHeight = value;
	}
	
	override private function setMarginLeft(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginLeft = getCSSMargin(value);
		return _marginLeft = value;
	}
	
	override private function setMarginRight(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginRight = getCSSMargin(value);
		return _marginRight = value;
	}
	
	override private function setMarginTop(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginTop = getCSSMargin(value);
		return _marginTop = value;
	}
	
	override private function setMarginBottom(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginBottom = getCSSMargin(value);
		return _marginBottom = value;
	}
	
	override private function setPaddingLeft(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingLeft = getCSSPadding(value);
		return _paddingLeft = value;
	}
	
	override private function setPaddingRight(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingRight = getCSSPadding(value);
		return _paddingRight = value;
	}
	
	override private function setPaddingTop(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingTop = getCSSPadding(value);
		return _paddingTop = value;
	}
	
	override private function setPaddingBottom(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingBottom = getCSSPadding(value);
		return _paddingBottom = value;
	}
	
	override private function setDisplay(value:DisplayStyleValue):DisplayStyleValue 
	{
		this._domElement.nativeElement.style.display = getCSSDisplay(value);
		return _display = value;
	}
	
	override private function setPosition(value:PositionStyleValue):PositionStyleValue 
	{
		this._domElement.nativeElement.style.position = getCSSPosition(value);
		return _position = value;
	}
	
	override private function setWidth(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.width = getCSSDimension(value);
		return _width = value;
	}
	
	override private function setHeight(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.height = getCSSDimension(value);
		return _height = value;
	}
	
	override private function setMinHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minHeight = getCSSConstrainedDimension(value);
		return _minHeight = value;
	}
	
	override private function setMaxHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxHeight = getCSSConstrainedDimension(value);
		return _maxHeight = value;
	}
	
	override private function setMinWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minWidth = getCSSConstrainedDimension(value);
		return _minWidth = value;
	}
	
	override private function setMaxWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxWidth = getCSSConstrainedDimension(value);
		return _maxWidth = value;
	}
	
	override private function setTop(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.top = getCSSPositionOffset(value);
		return _top = value;
	}
	
	override private function setLeft(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.left = getCSSPositionOffset(value);
		return _left = value;
	}
	
	override private function setBottom(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.bottom = getCSSPositionOffset(value);
		return _bottom = value;
	}
	
	override private function setRight(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.right = getCSSPositionOffset(value);
		return _right = value;
	}
	
	override private function setTextIndent(value:TextIndentStyleValue):TextIndentStyleValue
	{
		this._domElement.nativeElement.style.textIndent = getCSSTextIndent(value);
		return _textIndent = value;
	}
	
	override private function setFloat(value:FloatStyleValue):FloatStyleValue 
	{
		untyped this._domElement.nativeElement.style.cssFloat = getCSSFloat(value);
		return _float = value;
	}
	
	override private function setClear(value:ClearStyleValue):ClearStyleValue 
	{
		this._domElement.nativeElement.style.clear = getCSSClear(value);
		return _clear = value;
	}
	
	override private function setWhiteSpace(value:WhiteSpaceStyleValue):WhiteSpaceStyleValue
	{
		this._domElement.nativeElement.style.whiteSpace = getCSSWhiteSpace(value);
		return _whiteSpace = value;
	}
	
	override private function setTextAlign(value:TextAlignStyleValue):TextAlignStyleValue
	{
		this._domElement.nativeElement.style.textAlign = getCSSTextAlign(value);
		return _textAlign = value;
	}
	
}