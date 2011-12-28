/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.js;

import cocktail.domElement.DOMElement;
import cocktailCore.style.abstract.AbstractStyle;
import cocktail.unit.UnitData;
import cocktailCore.style.formatter.FormattingContext;
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
 * Each time a layout happens (when a style changes, when the viewport is resized...), 
 * The width, height, x and y of the native JavaScript HTMLElement are stored.
 * 
 * They are also stored when the width/height/x/y are set directly on the DOMElement
 * (with DOMElement.x, DOMElement.y ...).
 * Those value are stored immediately because in JavaScript when changing a style on an object,
 * methods to get the actual width of an element (like clientWidth) are set asynchronously,
 * meaning that in the following example, the width var will be equal to 0 instead of 100 : 
 * myHTMLElement.style.width = 100px;
 * var width = myHTMLElement.clientWidth;
 * 
 * A Timer needs to be set to retrieve the value and that is why it is set after a layout
 * which is asynchronous to prevent having multiple timers and also immediately after
 * setting it using the x,y,width or height attributes of the DOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class Style extends AbstractStyle
{
	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to allow the dimensions and position of the native HTMLElement to be stored
	 */
	override public function flow(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null):Void
	{	
		//make the children store their own position and dimension
		flowChildren(containingDOMElementData, viewportData, lastPositionedDOMElementData, containingDOMElementFontMetricsData, formatingContext);
		
		//store the JavaScript dimension and position of the native HTMLElement, now that they are available
		setNativeHeight(untyped this._domElement.nativeElement.clientHeight);
		setNativeWidth(untyped this._domElement.nativeElement.clientWidth);
		setNativeX(this._domElement, untyped this._domElement.nativeElement.offsetLeft);
		setNativeY(this._domElement, untyped this._domElement.nativeElement.offsetTop);
		
		//The DOMElement is set to valid to allow future re layout
		this._isInvalid = false;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to prevent the DOMElement to be inserted into the flow, it is managed by the browser in
	 * JavaScript
	 */
	override private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null ):Void
	{
		
	}
	
	/////////////////////////////////
	// DISPLAY STYLES
	////////////////////////////////
	
	/**
	 * CSS : display
	 */
	private function getCSSDisplay(value:DisplayStyleValue):String
	{
		var cssDisplayValue:String;
		
		switch (value)
		{
			case block:
				cssDisplayValue = "block";
			
			case inlineStyle:
				cssDisplayValue = "inline";
			
			case inlineBlock:
				cssDisplayValue = "inline-block";
				
			case DisplayStyleValue.none:
				cssDisplayValue = "none";
		}
		
		return cssDisplayValue;
	}
	
	/**
	 * CSS : float
	 */
	private function getCSSFloat(value:FloatStyleValue):String
	{
		var cssFloatValue:String;
		
		switch (value)
		{
			case FloatStyleValue.left:
				cssFloatValue = "left";
				
			case FloatStyleValue.right:
				cssFloatValue = "right";
				
			case FloatStyleValue.none:
				cssFloatValue = "none";
		}
		
		return cssFloatValue;
	}
	
	/**
	 * CSS : clear
	 */
	private function getCSSClear(value:ClearStyleValue):String
	{
		var cssClearValue:String;
		
		switch (value)
		{
			case ClearStyleValue.left:
				cssClearValue = "left";
				
			case ClearStyleValue.right:
				cssClearValue = "right";
				
			case ClearStyleValue.both:
				cssClearValue = "both";
				
			case ClearStyleValue.none:
				cssClearValue = "none";
		}
		
		return cssClearValue;
	}
	
	/**
	 * CSS : position
	 */
	private function getCSSPosition(value:PositionStyleValue):String
	{
		var cssPositionValue:String;
		
		switch (value)
		{
			case staticStyle:
				cssPositionValue = "static";
			
			case relative:
				cssPositionValue = "relative";
			
			case absolute:
				cssPositionValue = "absolute";
				
			case fixed:
				cssPositionValue = "fixed";
		}
		
		return cssPositionValue;
	}
	
	/**
	 * CSS : opacity
	 */
	private function getCSSOpacity(value:OpacityStyleValue):String
	{
		var cssOpacityValue:String;
		
		switch (value)
		{
			case OpacityStyleValue.number(value):
				cssOpacityValue = Std.string(value);
		}
		
		return cssOpacityValue;
	}
	
	/**
	 * CSS : visibility
	 */
	private function getCSSVisibility(value:VisibilityStyleValue):String
	{
		var cssVisibilityValue:String;
		
		switch (value)
		{
			case visible:
				cssVisibilityValue = "visible";
				
			case hidden:
				cssVisibilityValue = "hidden";
		}
		
		return cssVisibilityValue;
	}
	
	/**
	 * CSS : transform
	 */
	private function getCSSTransform(value:TransformStyleValue):String
	{
		var cssTransformValue:String;
		
		switch(value)
		{
			case TransformStyleValue.none:
				cssTransformValue = "none";
				
			case TransformStyleValue.transformFunctions(value):
				cssTransformValue = "";
				for (i in 0...value.length)
				{
					cssTransformValue += getCSSTransformFunction(value[i]);
					if (i < value.length - 1)
					{
						cssTransformValue += " ";
					}
				}		
		}
		
		return cssTransformValue;
	}
	
	/**
	 * Returns the CSS representation of one transform
	 * function
	 */
	private function getCSSTransformFunction(transformFunction:TransformFunctionValue):String
	{
		var cssTransformFunction:String;
		
		switch (transformFunction)
		{
			case TransformFunctionValue.matrix(value):
				cssTransformFunction = "matrix(" + value.a + "," + value.b + "," + value.c + "," + value.d + "," + value.e + "," + value.f + ")";
				
			case TransformFunctionValue.rotate(angle):
				cssTransformFunction = "rotate(" + getCSSAngleValue(angle) + ")";
				
			case TransformFunctionValue.scale(sx, sy):
				cssTransformFunction = "scale(" + sx + "," + sy + ")";
				
			case TransformFunctionValue.scaleX(sx):
				cssTransformFunction = "scaleX(" + sx + ")";
				
			case TransformFunctionValue.scaleY(sy):
				cssTransformFunction = "scaleY(" + sy + ")";	
				
			case TransformFunctionValue.skew(skewX, skewY):
				cssTransformFunction = "skew(" + getCSSAngleValue(skewX) + "," + getCSSAngleValue(skewY) + ")";
			
			case TransformFunctionValue.skewX(skewX):
				cssTransformFunction = "skewX(" + getCSSAngleValue(skewX) + ")";
				
			case TransformFunctionValue.skewY(skewY):
				cssTransformFunction = "skewY(" + getCSSAngleValue(skewY) + ")";	
				
			case TransformFunctionValue.translate(tx, ty):
				cssTransformFunction = "translate(" + getCSSTranslation(tx) + "," + getCSSTranslation(ty) + ")";
				
			case TransformFunctionValue.translateX(tx):
				cssTransformFunction = "translateX(" + getCSSTranslation(tx)  +")";
				
			case TransformFunctionValue.translateY(ty):
				cssTransformFunction = "translateY(" + getCSSTranslation(ty)  +")";		
		}
		
		return cssTransformFunction;
	}
	
	/**
	 * Return the CSS representation of a
	 * translation amount
	 */
	private function getCSSTranslation(translation:TranslationValue):String
	{
		var cssTranslationValue:String;
		
		switch (translation)
		{
			case TranslationValue.length(value):
				cssTranslationValue = getCSSLengthValue(value);
				
			case TranslationValue.percent(value):
				cssTranslationValue = getCSSPercentValue(value);
		}
		
		return cssTranslationValue;
	}
	
	/**
	 * CSS : transform-origin
	 */
	private function getCSSTransformOrigin(value:TransformOriginStyleData):String
	{
		var cssTransformOriginValue:String;
		
		//x axis
		switch (value.x)
		{
			case TransformOriginXStyleValue.length(value):
				cssTransformOriginValue = getCSSLengthValue(value);
				
			case TransformOriginXStyleValue.percent(value):
				cssTransformOriginValue = getCSSPercentValue(value);
				
			case TransformOriginXStyleValue.left:
				cssTransformOriginValue = "left";
				
			case TransformOriginXStyleValue.center:
				cssTransformOriginValue = "center";
				
			case TransformOriginXStyleValue.right:
				cssTransformOriginValue = "right";
		}
		
		//add space to separat x and y axis values
		cssTransformOriginValue += " ";
		
		//y axis
		switch (value.y)
		{
			case TransformOriginYStyleValue.length(value):
				cssTransformOriginValue += getCSSLengthValue(value);
				
			case TransformOriginYStyleValue.percent(value):
				cssTransformOriginValue += getCSSPercentValue(value);
				
			case TransformOriginYStyleValue.top:
				cssTransformOriginValue += "top";
				
			case TransformOriginYStyleValue.center:
				cssTransformOriginValue += "center";
				
			case TransformOriginYStyleValue.bottom:
				cssTransformOriginValue += "bottom";
		}
		
		return cssTransformOriginValue;
	}
	
	/////////////////////////////////
	// BOX MODEL STYLES
	////////////////////////////////
	
	/**
	 * CSS : margin-top, margin-left...
	 */
	private function getCSSMargin(value:MarginStyleValue):String
	{
		var cssMarginValue:String;
		
		switch(value)
		{
			case length(unit):
				cssMarginValue = getCSSLengthValue(unit);
			
			case percent(percentValue):
				cssMarginValue = getCSSPercentValue(percentValue);
				
			case autoValue:
				cssMarginValue = "auto";
		}
		
		return cssMarginValue;
	}
	
	/**
	 * CSS : padding-top, padding-left...
	 */
	private function getCSSPadding(value:PaddingStyleValue):String
	{
		var cssPaddingValue:String;
		
		switch(value)
		{
			case length(unit):
				cssPaddingValue = getCSSLengthValue(unit);
			
			case percent(percentValue):
				cssPaddingValue = getCSSPercentValue(percentValue);
		}
		
		return cssPaddingValue;
	}
	
	/**
	 * CSS : width, height
	 */
	private function getCSSDimension(value:DimensionStyleValue):String
	{
		var cssDimensionValue:String;
		
		switch (value)
		{
			case DimensionStyleValue.length(unit):
				cssDimensionValue = getCSSLengthValue(unit);
				
			case DimensionStyleValue.percent(percentValue):
				cssDimensionValue = getCSSPercentValue(percentValue);
				
			case DimensionStyleValue.autoValue:
				cssDimensionValue = "auto";
		}
		
		return cssDimensionValue;
	}
	
	/**
	 * CSS : top, left, right, bottom
	 */
	private function getCSSPositionOffset(value:PositionOffsetStyleValue):String
	{
		var cssPositionOffsetValue:String;
		
		switch (value)
		{
			case length(unit):
				cssPositionOffsetValue = getCSSLengthValue(unit);	
			
			
			case percent(percentValue):
				cssPositionOffsetValue = getCSSPercentValue(percentValue);
				
			case autoValue:
				cssPositionOffsetValue = "auto";
		}
		
		return cssPositionOffsetValue;
	}
	
	/**
	 * CSS : min-width, max-width, min-height, max-height
	 */
	private function getCSSConstrainedDimension(value:ConstrainedDimensionStyleValue):String
	{
		var cssConstrainedValue:String;
		
		switch (value)
		{
			case length(unit):
				cssConstrainedValue = getCSSLengthValue(unit);
			
			case percent(percentValue):
				cssConstrainedValue = getCSSPercentValue(percentValue);
				
			case none:	
				cssConstrainedValue = "none";
		}
		
		return cssConstrainedValue;
		
	}
	
	/**
	 * CSS : vertical-align
	 */
	private function getCSSVerticalAlign(value:VerticalAlignStyleValue):String
	{
		var cssVerticalAlignValue:String;
		
		switch (value)
		{
			case baseline:
				cssVerticalAlignValue = "baseline";
				
			case middle:
				cssVerticalAlignValue = "middle";
				
			case sub:
				cssVerticalAlignValue = "sub";
				
			case superStyle:
				cssVerticalAlignValue = "super";
				
			case textTop:
				cssVerticalAlignValue = "text-top";
				
			case textBottom:
				cssVerticalAlignValue = "text-bottom";
				
			case VerticalAlignStyleValue.top:
				cssVerticalAlignValue = "top";
				
			case VerticalAlignStyleValue.bottom:
				cssVerticalAlignValue = "bottom";
				
			case percent(value):
				cssVerticalAlignValue = getCSSPercentValue(value);
				
			case length(value):
				cssVerticalAlignValue = getCSSLengthValue(value);
		}
		
		return cssVerticalAlignValue;
		
	}
	
	/**
	 * CSS : line-height
	 */
	private function getCSSLineHeight(value:LineHeightStyleValue):String
	{
		var cssLineHeightValue:String;
		
		switch (value)
		{
			case length(unit):
				cssLineHeightValue = getCSSLengthValue(unit);
				
			case normal:
				cssLineHeightValue = "normal";
				
			case percentage(value):
				cssLineHeightValue = getCSSPercentValue(value);
				
			case number(value):
				cssLineHeightValue = Std.string(value);	
		}
		
		return cssLineHeightValue;
	}
	
	/////////////////////////////////
	// FONT STYLES
	////////////////////////////////
	
		
	/**
	 * CSS : font-size
	 */
	private function getCSSFontSize(value:FontSizeStyleValue):String
	{
		var cssFontSizeValue:String;
		
		switch (value)
		{
			case length(unit):
				cssFontSizeValue = getCSSLengthValue(unit);
				
			case percentage(percent):
				cssFontSizeValue = getCSSPercentValue(percent);
				
			case absoluteSize(value):
				switch (value)
				{
					case xxSmall:
						cssFontSizeValue = "xx-small";
					
					case xSmall:
						cssFontSizeValue = "x-small";
						
					case small:
						cssFontSizeValue = "small";
						
					case medium:
						cssFontSizeValue = "medium";
						
					case large:
						cssFontSizeValue = "large";
						
					case xLarge:
						cssFontSizeValue = "x-large";
						
					case xxLarge:	
						cssFontSizeValue = "xx-large";
				}
				
			case relativeSize(value):
				switch (value)
				{
					case larger:
						cssFontSizeValue = "larger";
						
					case smaller:
						cssFontSizeValue = "smaller";
				}
		}
		
		return cssFontSizeValue;
	}
	
	/**
	 * CSS : font-weight
	 */
	private function getCSSFontWeight(value:FontWeightStyleValue):String
	{
		var cssFontWeightValue:String;
		
		switch (value)
		{
			case normal:
				cssFontWeightValue = "normal";
				
			case bold:
				cssFontWeightValue = "bold";
		}
		
		return cssFontWeightValue;
	}
	
	/**
	 * CSS : font-style
	 */
	private function getCSSFontStyle(value:FontStyleStyleValue):String
	{
		var cssFontStyleValue:String;
		
		switch (value)
		{
			case normal:
				cssFontStyleValue = "normal";
				
			case italic:
				cssFontStyleValue = "italic";
		}
		
		return cssFontStyleValue;
	}
	
	/**
	 * CSS : font-variant
	 */
	private function getCSSFontVariant(value:FontVariantStyleValue):String
	{
		var cssFontVariantValue:String;
		
		switch (value)
		{
			case normal:
				cssFontVariantValue = "normal";
				
			case smallCaps:
				cssFontVariantValue = "small-caps";
		}
		
		return cssFontVariantValue;
	}
	
	/**
	 * CSS : font-family
	 */
	private function getCSSFontFamily(value:Array<FontFamilyStyleValue>):String
	{
		var cssFontFamilyValue:String = "";
		
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
			
			cssFontFamilyValue += fontName;
			
			if (i < value.length -1)
			{
				cssFontFamilyValue += ",";
			}
		}
		
		return cssFontFamilyValue;
	}
	
	/////////////////////////////////
	// TEXT STYLES
	////////////////////////////////
	
	/**
	 * CSS : text-align
	 */
	private function getCSSTextAlign(value:TextAlignStyleValue):String
	{
		var cssTextAlignValue:String;
		
		switch (value)
		{
			case TextAlignStyleValue.left:
				cssTextAlignValue = "left";
				
			case TextAlignStyleValue.right:
				cssTextAlignValue = "right";
				
			case TextAlignStyleValue.center:
				cssTextAlignValue = "center";
				
			case TextAlignStyleValue.justify:
				cssTextAlignValue = "justify";
		}
		
		return cssTextAlignValue;
	}
	
	/**
	 * CSS : white-space
	 */
	private function getCSSWhiteSpace(value:WhiteSpaceStyleValue):String
	{
		var cssWhiteSpaceValue:String;
		
		switch (value)
		{
			case WhiteSpaceStyleValue.normal:
				cssWhiteSpaceValue = "normal";
				
			case pre:
				cssWhiteSpaceValue = "pre";
				
			case nowrap:
				cssWhiteSpaceValue = "nowrap";
				
			case preWrap:
				cssWhiteSpaceValue = "pre-wrap";
				
			case preLine:
				cssWhiteSpaceValue = "pre-line";
		}
		
		return cssWhiteSpaceValue;
	}
	
	/**
	 * CSS : text-transform
	 */
	private function getCSSTextTransform(value:TextTransformStyleValue):String
	{
		var cssTextTransformValue:String;
		
		switch (value)
		{
			case none:
				cssTextTransformValue = "none";
				
			case uppercase:
				cssTextTransformValue = "uppercase";
				
			case lowercase:
				cssTextTransformValue = "lowercase";
				
			case capitalize:
				cssTextTransformValue = "capitalize";
		}
		
		return cssTextTransformValue;
	}
	
	/**
	 * CSS : text-indent
	 */
	private function getCSSTextIndent(value:TextIndentStyleValue):String
	{
		var cssTextIndentValue:String;
		
		switch (value)
		{
			case length(value):
				cssTextIndentValue = getCSSLengthValue(value);
				
			case percentage(value):
				cssTextIndentValue = getCSSPercentValue(value);
		}
		
		return cssTextIndentValue;
	}
	
	/**
	 * CSS : letter-spacing
	 */
	private function getCSSLetterSpacing(value:LetterSpacingStyleValue):String
	{
		var cssLetterSpacingValue:String;
		
		switch (value)
		{
			case normal:
				cssLetterSpacingValue = "normal";
				
			case length(unit):
				cssLetterSpacingValue = getCSSLengthValue(unit);
		}
		
		return cssLetterSpacingValue;
	}
	
	/**
	 * CSS : word-spacing
	 */
	private function getCSSWordSpacing(value:WordSpacingStyleValue):String
	{
		var cssWordSpacingValue:String;
		
		switch (value)
		{
			case normal:
				cssWordSpacingValue = "normal";
				
			case length(unit):
				cssWordSpacingValue = getCSSLengthValue(unit);
		}
		
		return cssWordSpacingValue;
	}
	
	/**
	 * CSS : color
	 */
	private function getCSSColor(value:ColorValue):String
	{
		var cssColorValue:String;
		
		switch (value)
		{
			case hex(value):
				cssColorValue = value;
				
			case RGB(red, green, blue):
				cssColorValue = "rgb(" + red + "," + green + "," + blue + ")";
				
		
			case keyword(value):
				cssColorValue = getColorFromKeyword(value);
		}
		
		return cssColorValue;
	}
	
	/////////////////////////////////
	// UNIT CONVERSION
	// Convert abstract styles units
	// to CSS units
	////////////////////////////////
	
	private function getCSSLengthValue(lengthValue:LengthValue):String
	{
		var cssLength:String;
		
		switch (lengthValue)
		{
			case px(pixelValue):
				cssLength = Std.string(pixelValue) + "px";
				
			case pt(pointValue):
				cssLength = Std.string(pointValue) + "pt";
				
			case mm(milimetersValue):
				cssLength = Std.string(milimetersValue) + "mm";
				
			case pc(picasValue):
				cssLength = Std.string(picasValue) + "pc";
				
			case cm(centimetersValue):
				cssLength = Std.string(centimetersValue) + "cm";
				
			case _in(inchesValue):
				cssLength = Std.string(inchesValue) + "in";
				
			case em(emValue	):
				cssLength = Std.string(emValue) + "em";
				
			case ex(exValue):
				cssLength = Std.string(exValue) + "ex";
		}
	
		return cssLength;	
	}
	
	private function getCSSPercentValue(value:Int):String
	{
		return Std.string(value) + "%";
	}
	
	private function getCSSAngleValue(value:AngleValue):String
	{
		var cssAngle:String;
		
		switch (value)
		{
			case AngleValue.deg(value):
				cssAngle = Std.string(value) + "deg";
				
			case AngleValue.rad(value):
				cssAngle = Std.string(value) + "rad";
				
			case AngleValue.grad(value):
				cssAngle = Std.string(value) + "grad";
				
			case AngleValue.turn(value):
				cssAngle = Std.string(value) + "turn";
		}
		
		return cssAngle;
	}
	
	private function getColorFromKeyword(value:ColorKeywordValue):String
	{
		var cssColor:String;
		
		switch (value)
		{
			case aqua:
				cssColor = "aqua";
				
			case black:
				cssColor = "black";
				
			case blue:
				cssColor = "blue";
				
			case fuchsia:
				cssColor = "fuchsia";
				
			case gray:
				cssColor = "gray";
				
			case green:
				cssColor = "green";
				
			case lime:
				cssColor = "lime";
				
			case maroon:
				cssColor = "maroon";
				
			case navy:
				cssColor = "navy";
				
			case olive:
				cssColor = "olive";
				
			case orange:
				cssColor = "orange";
				
			case purple:
				cssColor = "purple";
				
			case red:
				cssColor = "red";
				
			case silver:
				cssColor = "silver";
				
			case teal:
				cssColor = "teal";
				
			case white:
				cssColor = "white";
				
			case yellow:
				cssColor = "yellow";	
		}
		
		return cssColor;
	}
	
	/////////////////////////////////
	// UTIL METHOD
	////////////////////////////////
	
	/**
	 * For CSS styles not yet available across browser, find
	 * the vendor specific style name to use
	 * @param	nativeStyle the JavaScript Style object
	 */
	private function getVendorSpecificStyleName(nativeStyle:Dynamic, styleName:String):String
	{
		var vendorSpecificStyleName:String = styleName;
		
		//first check if the standard style exists
		if (Reflect.hasField(nativeStyle, styleName))
		{
			vendorSpecificStyleName = styleName;
		}
		else
		{
			
			//capitalise the style name to respect camel case
			//convention
			var styleNameCap:String = styleName.charAt(0).toUpperCase();
			var styleNameEnd:String = styleName.substr(1);
			styleName = styleNameCap + styleNameEnd;
			
			//firefox
			if (Reflect.field(nativeStyle, "Moz" + styleName) != null)
			{
				vendorSpecificStyleName = "Moz" + styleName;
			}
			//webkit (chrome, safari...)
			else if (Reflect.field(nativeStyle, "Webkit" + styleName) != null)
			{
				vendorSpecificStyleName = "Webkit" + styleName;
			}
			//ie
			else if (Reflect.field(nativeStyle, "Ms" + styleName) != null)
			{
				vendorSpecificStyleName = "Ms" + styleName;
			}
			//opera
			else if (Reflect.field(nativeStyle, "O" + styleName) != null)
			{
				vendorSpecificStyleName = "O" + styleName;
			}
		}
		
		return vendorSpecificStyleName;
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
		super.setVerticalAlign(value);
		return _verticalAlign = value;
	}
	
	override private function setColor(value:ColorValue):ColorValue
	{
		this._domElement.nativeElement.style.color = getCSSColor(value);
		super.setColor(value);
		return _color = value;
	}
	
	override private function setWordSpacing(value:WordSpacingStyleValue):WordSpacingStyleValue
	{
		this._domElement.nativeElement.style.wordSpacing = getCSSWordSpacing(value);
		super.setWordSpacing(value);
		return _wordSpacing = value;
	}
	
	override private function setLetterSpacing(value:LetterSpacingStyleValue):LetterSpacingStyleValue
	{
		this._domElement.nativeElement.style.letterSpacing = getCSSLetterSpacing(value);
		super.setLetterSpacing(value);
		return _letterSpacing = value;
	}
	
	override private function setTextTransform(value:TextTransformStyleValue):TextTransformStyleValue
	{
		this._domElement.nativeElement.style.textTransform = getCSSTextTransform(value);
		super.setTextTransform(value);
		return _textTransform = value;
	}
	
	override private function setFontVariant(value:FontVariantStyleValue):FontVariantStyleValue
	{
		this._domElement.nativeElement.style.fontVariant = getCSSFontVariant(value);
		super.setFontVariant(value);
		return _fontVariant = value;
	}
	
	override private function setFontFamily(value:Array<FontFamilyStyleValue>):Array<FontFamilyStyleValue>
	{
		this._domElement.nativeElement.style.fontFamily = getCSSFontFamily(value);
		super.setFontFamily(value);
		return _fontFamily = value;
	}
	
	override private function setFontWeight(value:FontWeightStyleValue):FontWeightStyleValue
	{
		this._domElement.nativeElement.style.fontWeight = getCSSFontWeight(value);
		super.setFontWeight(value);
		return _fontWeight = value;
	}
	
	override private function setFontStyle(value:FontStyleStyleValue):FontStyleStyleValue
	{
		this._domElement.nativeElement.style.fontStyle = getCSSFontStyle(value);
		super.setFontStyle(value);
		return _fontStyle = value;
	}
	
	override private function setFontSize(value:FontSizeStyleValue):FontSizeStyleValue
	{
		this._domElement.nativeElement.style.fontSize = getCSSFontSize(value);
		super.setFontSize(value);
		return _fontSize = value;
	}
	
	override private function setLineHeight(value:LineHeightStyleValue):LineHeightStyleValue
	{
		this._domElement.nativeElement.style.lineHeight = getCSSLineHeight(value);
		super.setLineHeight(value);
		return _lineHeight = value;
	}
	
	override private function setMarginLeft(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginLeft = getCSSMargin(value);
		super.setMarginLeft(value);
		return _marginLeft = value;
	}
	
	override private function setMarginRight(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginRight = getCSSMargin(value);
		super.setMarginRight(value);
		return _marginRight = value;
	}
	
	override private function setMarginTop(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginTop = getCSSMargin(value);
		super.setMarginTop(value);
		return _marginTop = value;
	}
	
	override private function setMarginBottom(value:MarginStyleValue):MarginStyleValue 
	{
		this._domElement.nativeElement.style.marginBottom = getCSSMargin(value);
		super.setMarginBottom(value);
		return _marginBottom = value;
	}
	
	override private function setPaddingLeft(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingLeft = getCSSPadding(value);
		super.setPaddingLeft(value);
		return _paddingLeft = value;
	}
	
	override private function setPaddingRight(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingRight = getCSSPadding(value);
		super.setPaddingRight(value);
		return _paddingRight = value;
	}
	
	override private function setPaddingTop(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingTop = getCSSPadding(value);
		super.setPaddingTop(value);
		return _paddingTop = value;
	}
	
	override private function setPaddingBottom(value:PaddingStyleValue):PaddingStyleValue 
	{
		this._domElement.nativeElement.style.paddingBottom = getCSSPadding(value);
		super.setPaddingBottom(value);
		return _paddingBottom = value;
	}
	
	override private function setDisplay(value:DisplayStyleValue):DisplayStyleValue 
	{
		this._domElement.nativeElement.style.display = getCSSDisplay(value);
		super.setDisplay(value);
		return _display = value;
	}
	
	override private function setPosition(value:PositionStyleValue):PositionStyleValue 
	{
		this._domElement.nativeElement.style.position = getCSSPosition(value);
		super.setPosition(value);
		return _position = value;
	}
	
	override private function setWidth(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.width = getCSSDimension(value);
		super.setWidth(value);
		return _width = value;
	}
	
	override private function setHeight(value:DimensionStyleValue):DimensionStyleValue 
	{
		this._domElement.nativeElement.style.height = getCSSDimension(value);
		super.setHeight(value);
		return _height = value;
	}
	
	override private function setMinHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minHeight = getCSSConstrainedDimension(value);
		super.setMinHeight(value);
		return _minHeight = value;
	}
	
	override private function setMaxHeight(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxHeight = getCSSConstrainedDimension(value);
		super.setMaxHeight(value);
		return _maxHeight = value;
	}
	
	override private function setMinWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.minWidth = getCSSConstrainedDimension(value);
		super.setMinWidth(value);
		return _minWidth = value;
	}
	
	override private function setMaxWidth(value:ConstrainedDimensionStyleValue):ConstrainedDimensionStyleValue 
	{
		this._domElement.nativeElement.style.maxWidth = getCSSConstrainedDimension(value);
		super.setMaxWidth(value);
		return _maxWidth = value;
	}
	
	override private function setTop(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.top = getCSSPositionOffset(value);
		super.setTop(value);
		return _top = value;
	}
	
	override private function setLeft(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.left = getCSSPositionOffset(value);
		super.setLeft(value);
		return _left = value;
	}
	
	override private function setBottom(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.bottom = getCSSPositionOffset(value);
		super.setBottom(value);
		return _bottom = value;
	}
	
	override private function setRight(value:PositionOffsetStyleValue):PositionOffsetStyleValue 
	{
		this._domElement.nativeElement.style.right = getCSSPositionOffset(value);
		super.setRight(value);
		return _right = value;
	}
	
	override private function setTextIndent(value:TextIndentStyleValue):TextIndentStyleValue
	{
		this._domElement.nativeElement.style.textIndent = getCSSTextIndent(value);
		super.setTextIndent(value);
		return _textIndent = value;
	}
	
	override private function setFloatValue(value:FloatStyleValue):FloatStyleValue 
	{
		untyped this._domElement.nativeElement.style.cssFloat = getCSSFloat(value);
		super.setFloatValue(value);
		return floatValue = value;
	}
	
	override private function setClear(value:ClearStyleValue):ClearStyleValue 
	{
		this._domElement.nativeElement.style.clear = getCSSClear(value);
		super.setClear(value);
		return _clear = value;
	}
	
	override private function setWhiteSpace(value:WhiteSpaceStyleValue):WhiteSpaceStyleValue
	{
		this._domElement.nativeElement.style.whiteSpace = getCSSWhiteSpace(value);
		super.setWhiteSpace(value);
		return _whiteSpace = value;
	}
	
	override private function setTextAlign(value:TextAlignStyleValue):TextAlignStyleValue
	{
		this._domElement.nativeElement.style.textAlign = getCSSTextAlign(value);
		super.setTextAlign(value);
		return _textAlign = value;
	}
	
	override private function setOpacity(value:OpacityStyleValue):OpacityStyleValue
	{
		untyped this._domElement.nativeElement.style.opacity = getCSSOpacity(value);
		super.setOpacity(value);
		return _opacity = value;
	}
	
	override private function setVisibility(value:VisibilityStyleValue):VisibilityStyleValue
	{
		this._domElement.nativeElement.style.visibility = getCSSVisibility(value);
		super.setVisibility(value);
		return _visibility = value;
	}
	
	override private function setTransformOrigin(value:TransformOriginStyleData):TransformOriginStyleData
	{
		var nativeStyle:Dynamic = this._domElement.nativeElement.style;
		//get vendor specific style name
		Reflect.setField(nativeStyle, getVendorSpecificStyleName(nativeStyle, "transformOrigin"), getCSSTransformOrigin(value));
		super.setTransformOrigin(value);
		return _tranformOrigin = value;
	}
	
	override private function setTransform(value:TransformStyleValue):TransformStyleValue
	{
		var nativeStyle:Dynamic = this._domElement.nativeElement.style;
		//get vendor specific style name
		Reflect.setField(nativeStyle, getVendorSpecificStyleName(nativeStyle, "transform"), getCSSTransform(value));
		super.setTransform(value);
		return _transform = value;
	}
	
}