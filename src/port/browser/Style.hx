/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.browser;

import core.HTMLElement;
import core.nativeElement.NativeElement;
import core.style.AbstractStyle;
import core.unit.UnitData;
import core.style.formatter.FormattingContext;
import core.renderer.ElementRenderer;
import core.renderer.FlowBoxRenderer;
import haxe.Log;

import core.style.StyleData;

/**
 * In JavaScript, Styles are converted to native CSS styles and thus the browser manages the layout
 * and Styles of the document, not Cocktail. It would have been possible
 * to re-implement styles in JS, for instance processing the layout of the document 
 * entirely in JS, like in the Flash runtime but it would have had the following drawbacks : 
 * 
 * - huge performance hit
 * - generate non-standard HTML (e.g : to manage the layout in pure JS, all HTML elements should
 * have been positionned as 'absolute' instead on relying on the standard document's flow
 * - Some limitations would have occured such as floats which would have been very difficult 
 * to reproduce in pure JS
 * 
 * On the other hand, relying on CSS implies a few browser inconsistencies.
 * 
 * For each abstract style applied to a HTMLElement, this class converts it to a CSS String
 * which is applied to the style object of the native HTML element
 * 
 * Each time a layout happens (when a style changes, when the viewport is resized...), 
 * The width, height, x and y of the native JavaScript HTMLElement are stored.
 * 
 * They are also stored when the width/height/x/y are set directly on the HTMLElement
 * (with HTMLElement.x, HTMLElement.y ...).
 * Those value are stored immediately because in JavaScript when changing a style on an object,
 * methods to get the actual dimensions of an element (like clientWidth) are set asynchronously,
 * meaning that in the following example, the width var will be equal to 0 instead of 100 : 
 * myHTMLElement.style.width = 100px;
 * var width = myHTMLElement.clientWidth;
 * 
 * A Timer needs to be set to retrieve the value and that is why it is set after a layout
 * which is asynchronous to prevent having multiple timers and also immediately after
 * setting it using the x,y,width or height attributes of the HTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class Style extends AbstractStyle
{
	/**
	 * class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}
	
	/////////////////////////////////
	// DISPLAY STYLES
	////////////////////////////////
	
	/**
	 * CSS : display
	 */
	private function getCSSDisplay(value:Display):String
	{
		var cssDisplayValue:String;
		
		switch (value)
		{
			case block:
				cssDisplayValue = "block";
			
			case cssInline:
				cssDisplayValue = "inline";
			
			case inlineBlock:
				cssDisplayValue = "inline-block";
				
			case Display.none:
				cssDisplayValue = "none";
		}
		
		return cssDisplayValue;
	}
	
	/**
	 * CSS : float
	 */
	private function getCSSFloatAsString(value:CSSFloat):String
	{
		var cssCSSFloat:String;
		
		switch (value)
		{
			case CSSFloat.left:
				cssCSSFloat = "left";
				
			case CSSFloat.right:
				cssCSSFloat = "right";
				
			case CSSFloat.none:
				cssCSSFloat = "none";
		}
		
		return cssCSSFloat;
	}
	
	/**
	 * CSS : clear
	 */
	private function getCSSClear(value:Clear):String
	{
		var cssClearValue:String;
		
		switch (value)
		{
			case Clear.left:
				cssClearValue = "left";
				
			case Clear.right:
				cssClearValue = "right";
				
			case Clear.both:
				cssClearValue = "both";
				
			case Clear.none:
				cssClearValue = "none";
		}
		
		return cssClearValue;
	}
	
	/**
	 * CSS : position
	 */
	private function getCSSPosition(value:Position):String
	{
		var cssPositionValue:String;
		
		switch (value)
		{
			case cssStatic:
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
	
	/////////////////////////////////
	// VISUAL EFFECTS STYLES
	////////////////////////////////
	
	/**
	 * CSS : overflow
	 */
	private function getCSSOverflow(value:Overflow):String
	{
		var cssOverflowValue:String;
		
		switch (value)
		{
			case Overflow.visible:
				cssOverflowValue = "visible";
				
			case Overflow.hidden:
				cssOverflowValue = "hidden";
				
			case Overflow.scroll:
				cssOverflowValue = "scroll";
				
			case Overflow.cssAuto:
				cssOverflowValue = "auto";
		}
		
		return cssOverflowValue;
	}
	
	/**
	 * CSS : opacity
	 */
	private function getCSSOpacity(value:Opacity):String
	{
		var cssOpacityValue:String;
		cssOpacityValue = Std.string(value);
		
		return cssOpacityValue;
	}
	
	/**
	 * CSS : visibility
	 */
	private function getCSSVisibility(value:Visibility):String
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
	private function getCSSTransform(value:Transform):String
	{
		var cssTransformValue:String;
		
		switch(value)
		{
			case Transform.none:
				cssTransformValue = "none";
				
			case Transform.transformFunctions(value):
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
	private function getCSSTransformFunction(transformFunction:TransformFunction):String
	{
		var cssTransformFunction:String;
		
		switch (transformFunction)
		{
			case TransformFunction.matrix(value):
				cssTransformFunction = "matrix(" + value.a + "," + value.b + "," + value.c + "," + value.d + "," + value.e + "," + value.f + ")";
				
			case TransformFunction.rotate(angle):
				cssTransformFunction = "rotate(" + getCSSAngle(angle) + ")";
				
			case TransformFunction.scale(sx, sy):
				cssTransformFunction = "scale(" + sx + "," + sy + ")";
				
			case TransformFunction.scaleX(sx):
				cssTransformFunction = "scaleX(" + sx + ")";
				
			case TransformFunction.scaleY(sy):
				cssTransformFunction = "scaleY(" + sy + ")";	
				
			case TransformFunction.skew(skewX, skewY):
				cssTransformFunction = "skew(" + getCSSAngle(skewX) + "," + getCSSAngle(skewY) + ")";
			
			case TransformFunction.skewX(skewX):
				cssTransformFunction = "skewX(" + getCSSAngle(skewX) + ")";
				
			case TransformFunction.skewY(skewY):
				cssTransformFunction = "skewY(" + getCSSAngle(skewY) + ")";	
				
			case TransformFunction.translate(tx, ty):
				cssTransformFunction = "translate(" + getCSSTranslation(tx) + "," + getCSSTranslation(ty) + ")";
				
			case TransformFunction.translateX(tx):
				cssTransformFunction = "translateX(" + getCSSTranslation(tx)  +")";
				
			case TransformFunction.translateY(ty):
				cssTransformFunction = "translateY(" + getCSSTranslation(ty)  +")";		
		}
		
		return cssTransformFunction;
	}
	
	/**
	 * Return the CSS representation of a
	 * translation amount
	 */
	private function getCSSTranslation(translation:Translation):String
	{
		var cssTranslation:String;
		
		switch (translation)
		{
			case Translation.length(value):
				cssTranslation = getCSSLength(value);
				
			case Translation.percent(value):
				cssTranslation = getCSSPercentValue(value);
		}
		
		return cssTranslation;
	}
	
	/**
	 * CSS : transform-origin
	 */
	private function getCSSTransformOrigin(value:TransformOrigin):String
	{
		var cssTransformOriginValue:String;
		
		//x axis
		switch (value.x)
		{
			case TransformOriginX.length(value):
				cssTransformOriginValue = getCSSLength(value);
				
			case TransformOriginX.percent(value):
				cssTransformOriginValue = getCSSPercentValue(value);
				
			case TransformOriginX.left:
				cssTransformOriginValue = "left";
				
			case TransformOriginX.center:
				cssTransformOriginValue = "center";
				
			case TransformOriginX.right:
				cssTransformOriginValue = "right";
		}
		
		//add space to separat x and y axis values
		cssTransformOriginValue += " ";
		
		//y axis
		switch (value.y)
		{
			case TransformOriginY.length(value):
				cssTransformOriginValue += getCSSLength(value);
				
			case TransformOriginY.percent(value):
				cssTransformOriginValue += getCSSPercentValue(value);
				
			case TransformOriginY.top:
				cssTransformOriginValue += "top";
				
			case TransformOriginY.center:
				cssTransformOriginValue += "center";
				
			case TransformOriginY.bottom:
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
	private function getCSSMargin(value:Margin):String
	{
		var cssMarginValue:String;
		
		switch(value)
		{
			case length(unit):
				cssMarginValue = getCSSLength(unit);
			
			case percent(percentValue):
				cssMarginValue = getCSSPercentValue(percentValue);
				
			case cssAuto:
				cssMarginValue = "auto";
		}
		
		return cssMarginValue;
	}
	
	/**
	 * CSS : padding-top, padding-left...
	 */
	private function getCSSPadding(value:Padding):String
	{
		var cssPaddingValue:String;
		
		switch(value)
		{
			case length(unit):
				cssPaddingValue = getCSSLength(unit);
			
			case percent(percentValue):
				cssPaddingValue = getCSSPercentValue(percentValue);
		}
		
		return cssPaddingValue;
	}
	
	/**
	 * CSS : width, height
	 */
	private function getCSSDimension(value:Dimension):String
	{
		var cssDimensionValue:String;
		
		switch (value)
		{
			case Dimension.length(unit):
				cssDimensionValue = getCSSLength(unit);
				
			case Dimension.percent(percentValue):
				cssDimensionValue = getCSSPercentValue(percentValue);
				
			case Dimension.cssAuto:
				cssDimensionValue = "auto";
		}
		
		return cssDimensionValue;
	}
	
	/**
	 * CSS : top, left, right, bottom
	 */
	private function getCSSPositionOffset(value:PositionOffset):String
	{
		var cssPositionOffsetValue:String;
		
		switch (value)
		{
			case length(unit):
				cssPositionOffsetValue = getCSSLength(unit);	
			
			
			case percent(percentValue):
				cssPositionOffsetValue = getCSSPercentValue(percentValue);
				
			case cssAuto:
				cssPositionOffsetValue = "auto";
		}
		
		return cssPositionOffsetValue;
	}
	
	/**
	 * CSS : min-width, max-width, min-height, max-height
	 */
	private function getCSSConstrainedDimension(value:ConstrainedDimension):String
	{
		var cssConstrainedValue:String;
		
		switch (value)
		{
			case length(unit):
				cssConstrainedValue = getCSSLength(unit);
			
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
	private function getCSSVerticalAlign(value:VerticalAlign):String
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
				
			case VerticalAlign.top:
				cssVerticalAlignValue = "top";
				
			case VerticalAlign.bottom:
				cssVerticalAlignValue = "bottom";
				
			case percent(value):
				cssVerticalAlignValue = getCSSPercentValue(value);
				
			case length(value):
				cssVerticalAlignValue = getCSSLength(value);
		}
		
		return cssVerticalAlignValue;
		
	}
	
	/**
	 * CSS : line-height
	 */
	private function getCSSLineHeight(value:LineHeight):String
	{
		var cssLineHeightValue:String;
		
		switch (value)
		{
			case length(unit):
				cssLineHeightValue = getCSSLength(unit);
				
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
	private function getCSSFontSize(value:FontSize):String
	{
		var cssFontSizeValue:String;
		
		switch (value)
		{
			case length(unit):
				cssFontSizeValue = getCSSLength(unit);
				
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
	private function getCSSFontWeight(value:FontWeight):String
	{
		var cssFontWeightValue:String;
		
		switch (value)
		{
			case normal:
				cssFontWeightValue = "normal";
				
			case bold:
				cssFontWeightValue = "bold";
				
			case bolder:
				cssFontWeightValue = "bolder";
				
			case lighter:
				cssFontWeightValue = "lighter";
				
			case css100:
				cssFontWeightValue = "100";
				
			case css200:
				cssFontWeightValue = "200";
				
			case css300:
				cssFontWeightValue = "300";	
				
			case css400:
				cssFontWeightValue = "400";	
				
			case css500:
				cssFontWeightValue = "500";	
				
			case css600:
				cssFontWeightValue = "600";	
				
			case css700:
				cssFontWeightValue = "700";
				
			case css800:
				cssFontWeightValue = "800";	
				
			case css900:
				cssFontWeightValue = "900";	
		}
		
		return cssFontWeightValue;
	}
	
	/**
	 * CSS : font-style
	 */
	private function getCSSFontStyle(value:FontStyle):String
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
	private function getCSSFontVariant(value:FontVariant):String
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
	private function getCSSFontFamily(value:Array<FontFamily>):String
	{
		var cssFontFamilyValue:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String;
			
			switch (value[i])
			{
				case FontFamily.familyName(name):
					fontName = name;
				
				case FontFamily.genericFamily(genericName):
					switch (genericName)
					{
						case GenericFontFamily.serif:
							fontName = "serif";
						
						case GenericFontFamily.sansSerif:
							fontName = "sans-serif";
							
						case GenericFontFamily.monospace:
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
	private function getCSSTextAlign(value:TextAlign):String
	{
		var cssTextAlignValue:String;
		
		switch (value)
		{
			case TextAlign.left:
				cssTextAlignValue = "left";
				
			case TextAlign.right:
				cssTextAlignValue = "right";
				
			case TextAlign.center:
				cssTextAlignValue = "center";
				
			case TextAlign.justify:
				cssTextAlignValue = "justify";
		}
		
		return cssTextAlignValue;
	}
	
	/**
	 * CSS : white-space
	 */
	private function getCSSWhiteSpace(value:WhiteSpace):String
	{
		var cssWhiteSpaceValue:String;
		
		switch (value)
		{
			case WhiteSpace.normal:
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
	private function getCSSTextTransform(value:TextTransform):String
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
	private function getCSSTextIndent(value:TextIndent):String
	{
		var cssTextIndentValue:String;
		
		switch (value)
		{
			case length(value):
				cssTextIndentValue = getCSSLength(value);
				
			case percentage(value):
				cssTextIndentValue = getCSSPercentValue(value);
		}
		
		return cssTextIndentValue;
	}
	
	/**
	 * CSS : letter-spacing
	 */
	private function getCSSLetterSpacing(value:LetterSpacing):String
	{
		var cssLetterSpacingValue:String;
		
		switch (value)
		{
			case normal:
				cssLetterSpacingValue = "normal";
				
			case length(unit):
				cssLetterSpacingValue = getCSSLength(unit);
		}
		
		return cssLetterSpacingValue;
	}
	
	/**
	 * CSS : word-spacing
	 */
	private function getCSSWordSpacing(value:WordSpacing):String
	{
		var cssWordSpacingValue:String;
		
		switch (value)
		{
			case normal:
				cssWordSpacingValue = "normal";
				
			case length(unit):
				cssWordSpacingValue = getCSSLength(unit);
		}
		
		return cssWordSpacingValue;
	}
	
	
	
	/////////////////////////////////
	// BACKGROUND STYLES
	////////////////////////////////
	
	/**
	 * CSS : background-color
	 */
	private function getCSSBackgroundColor(value:BackgroundColor):String
	{
		var cssBackgroundColor:String;
		cssBackgroundColor = getCSSColor(value);
		
		return cssBackgroundColor;
	}
	
	/**
	 * CSS : background-origin
	 */
	private function getCSSBackgroundOrigin(value:Array<BackgroundOrigin>):String
	{
		var cssBackgroundOrigin:String = "";
		
		for (i in 0...value.length)
		{
			switch(value[i])
			{
				case BackgroundOrigin.borderBox:
					cssBackgroundOrigin += "border-box";
					
				case BackgroundOrigin.contentBox:
					cssBackgroundOrigin += "content-box";
					
				case BackgroundOrigin.paddingBox:
					cssBackgroundOrigin += "padding-box";
			}
			
			if (i < value.length -1)
			{
				cssBackgroundOrigin += ",";
			}
		}
		
		return cssBackgroundOrigin;
	}
	
	/**
	 * CSS : background-clip
	 */
	private function getCSSBackgroundClip(value:Array<BackgroundClip>):String
	{
		var cssBackgroundClip:String = "";
		
		for (i in 0...value.length)
		{
			switch(value[i])
			{
				case BackgroundClip.borderBox:
					cssBackgroundClip += "border-box";
					
				case BackgroundClip.contentBox:
					cssBackgroundClip += "content-box";
					
				case BackgroundClip.paddingBox:
					cssBackgroundClip += "padding-box";
			}
			
			if (i < value.length -1)
			{
				cssBackgroundClip += ",";
			}
		}
		
		return cssBackgroundClip;
	}
	
	/**
	 * CSS : background-image
	 */
	private function getCSSBackgroundImage(value:Array<BackgroundImage>):String
	{
		var cssBackgroundImage:String = "";
		
		for (i in 0...value.length)
		{
			switch (value[i])
			{
				case BackgroundImage.none:
					cssBackgroundImage += "none";
					
				case BackgroundImage.image(value):
					cssBackgroundImage += getCSSImageValue(value);
			}	
			
			if (i < value.length -1)
			{
				cssBackgroundImage += ",";
			}
			
		}
		
		return cssBackgroundImage;
	}
	
	/**
	 * CSS : background-size
	 */
	private function getCSSBackgroundSize(value:Array<BackgroundSize>):String
	{
		var cssBackgroundSize:String = "";
		
		for (i in 0...value.length)
		{
			switch (value[i])
			{
				case BackgroundSize.contain:
					cssBackgroundSize += "contain";
					
				case BackgroundSize.cover:
					cssBackgroundSize += "cover";
					
				case BackgroundSize.dimensions(value):
					cssBackgroundSize += getCSSBackgroundSizeDimensions(value);
			}
			
			if (i < value.length -1)
			{
				cssBackgroundSize += ",";
			}
		}
		
		return cssBackgroundSize;
	}
	
	private function getCSSBackgroundSizeDimensions(value:BackgroundSizeDimensions):String
	{
		var cssBackgroundSizeDimensions:String = getCSSBackgroundSizeDimension(value.x) + " " + getCSSBackgroundSizeDimension(value.y);
		return cssBackgroundSizeDimensions;
	}
	
	private function getCSSBackgroundSizeDimension(value:BackgroundSizeDimension):String
	{
		var cssBackgroundSizeDimension:String;
		
		switch (value)
		{
			case BackgroundSizeDimension.length(value):
				cssBackgroundSizeDimension = getCSSLength(value);
				
			case BackgroundSizeDimension.percent(value):
				cssBackgroundSizeDimension = getCSSPercentValue(value);
				
			case BackgroundSizeDimension.cssAuto:
				cssBackgroundSizeDimension = "auto";
		}
		
		return cssBackgroundSizeDimension;
	}
	
	/**
	 * CSS : background-position
	 */
	private function getCSSBackgroundPosition(value:Array<BackgroundPosition>):String
	{
		var cssBackgroundPositionData:String = "";
		
		for (i in 0...value.length)
		{
			cssBackgroundPositionData += getCSSBackgroundPositionX(value[i].x) + " " + getCSSBackgroundPositionY(value[i].y);
			
			if (i < value.length -1)
			{
				cssBackgroundPositionData += ",";
			}
		}
		
		return cssBackgroundPositionData;
	}
	
	private function getCSSBackgroundPositionX(value:BackgroundPositionX):String
	{
		var cssBackgroundPositionX:String;
		
		switch (value)
		{
			case BackgroundPositionX.length(value):
				cssBackgroundPositionX = getCSSLength(value);
				
			case BackgroundPositionX.percent(value):
				cssBackgroundPositionX = getCSSPercentValue(value);
				
			case BackgroundPositionX.center:
				cssBackgroundPositionX = "center";
				
			case BackgroundPositionX.left:
				cssBackgroundPositionX = "left";
				
			case BackgroundPositionX.right:
				cssBackgroundPositionX = "right";
		}
		
		return cssBackgroundPositionX;
	}
	
	private function getCSSBackgroundPositionY(value:BackgroundPositionY):String
	{
		var cssBackgroundPositionY:String;
		
		switch (value)
		{
			case BackgroundPositionY.length(value):
				cssBackgroundPositionY = getCSSLength(value);
				
			case BackgroundPositionY.percent(value):
				cssBackgroundPositionY = getCSSPercentValue(value);
				
			case BackgroundPositionY.bottom:
				cssBackgroundPositionY = "bottom";
				
			case BackgroundPositionY.top:
				cssBackgroundPositionY = "top";
				
			case BackgroundPositionY.center:
				cssBackgroundPositionY = "center";
		}
		
		return cssBackgroundPositionY;
	}
	
	/**
	 * CSS : background-repeat
	 */
	private function getCSSBackgroundRepeat(value:Array<BackgroundRepeat>):String
	{
		var cssBackgroundRepeat:String = "";
		
		for (i in 0...value.length)
		{
			cssBackgroundRepeat += getCSSBackgroundRepeatValue(value[i].x) + " " + getCSSBackgroundRepeatValue(value[i].y);
			
			if (i < value.length -1)
			{
				cssBackgroundRepeat += ",";
			}
		}
		
		return cssBackgroundRepeat;
	}
	
	private function getCSSBackgroundRepeatValue(value:BackgroundRepeatValue):String
	{
		var cssBackgroundRepeatValue:String;
		
		switch (value)
		{
			case BackgroundRepeatValue.noRepeat:
				cssBackgroundRepeatValue = "no-repeat";
				
			case BackgroundRepeatValue.repeat:
				cssBackgroundRepeatValue = "repeat";
				
			case BackgroundRepeatValue.round:
				cssBackgroundRepeatValue = "round";
				
			case BackgroundRepeatValue.space:
				cssBackgroundRepeatValue = "space";
		}
		
		return cssBackgroundRepeatValue;
	}
	
	/////////////////////////////////
	// UNIT CONVERSION
	// Convert abstract styles units
	// to CSS units
	////////////////////////////////
	
	private function getCSSImageValue(value:ImageValue):String
	{
		var cssImageValue:String;
		
		switch (value)
		{
			case ImageValue.url(value):
				cssImageValue = 'url("' + value + '")';
				
			case ImageValue.imageList(value):
				cssImageValue = "image(" + getCSSImageList(value) + ")";
				
			case ImageValue.gradient(value):
				cssImageValue = getCSSGradientValue(value);
		}
		
		return cssImageValue;
	}
	
	private function getCSSImageList(value:ImageDeclarationData):String
	{
		var cssImageList:String = "";
		
		for (i in 0...value.urls.length)
		{
			cssImageList += '"' + value.urls[i] + '"';
			
			if (i < value.urls.length -1)
			{
				cssImageList += ",";
			}
			else
			{
				cssImageList += ","+ getCSSColor(value.fallbackColor);
			}
		}
		
		return cssImageList;
	}
	
	private function getCSSGradientValue(value:GradientValue):String
	{
		var cssGradientValue:String;
		
		switch (value)
		{
			case GradientValue.linear(value):
				cssGradientValue = "linear-gradient(" + getCSSLinearGradientValue(value) + ")";
		}
		
		return cssGradientValue;
	}
	
	private function getCSSLinearGradientValue(value:LinearGradientData):String 
	{
		var cssLinearGradientValue:String = getCSSGradientAngle(value.angle) + "," + getCSSColorStopsValue(value.colorStops);
		return cssLinearGradientValue;
	}
	
	private function getCSSColorStopsValue(value:Array<GradientColorStopData>):String
	{
		var cssColorStopsData:String = "";
		
		for (i in 0...value.length)
		{
			cssColorStopsData += getCSSColor(value[i].color) + " " + getCSSColorStopValue(value[i].stop);
			
			if (i < value.length -1)
			{
				cssColorStopsData += ",";
			}
		}
		
		return cssColorStopsData;
	}
	
	private function getCSSColorStopValue(value:GradientStopValue):String
	{
		var cssColorStopValue:String;
		
		switch (value)
		{
			case GradientStopValue.percent(value):
				cssColorStopValue = getCSSPercentValue(value);
				
			case GradientStopValue.length(value):
				cssColorStopValue = getCSSLength(value);
		}
		
		return cssColorStopValue;
	}
	
	private function getCSSGradientAngle(value:GradientAngle):String
	{
		var cssGradientAngle:String;
		
		switch (value)
		{
			case GradientAngle.angle(value):
				cssGradientAngle = getCSSAngle(value);
				
			case GradientAngle.corner(value):
				cssGradientAngle = getCSSCornerValue(value);
				
			case GradientAngle.side(value):
				cssGradientAngle = getCSSSideValue(value);
		}
		
		return cssGradientAngle;
	}
	
	private function getCSSSideValue(value:GradientSideValue):String
	{
		var cssSideValue:String;
		
		switch (value)
		{
			case GradientSideValue.bottom:
				cssSideValue = "bottom";
				
			case GradientSideValue.left:
				cssSideValue = "left";
				
			case GradientSideValue.right:
				cssSideValue = "right";
				
			case GradientSideValue.top:
				cssSideValue = "top";
		}
		
		return cssSideValue;
	}
	
	private function getCSSCornerValue(value:GradientCornerValue):String
	{
		var cssCornerValue:String;
		
		switch (value)
		{
			case GradientCornerValue.bottomLeft:
				cssCornerValue = "left bottom";
				
			case GradientCornerValue.bottomRight:
				cssCornerValue = "right bottom";
				
			case GradientCornerValue.topLeft:
				cssCornerValue = "left top";
				
			case GradientCornerValue.topRight:
				cssCornerValue = "right top";
		}
		
		return cssCornerValue;
	}
	
	private function getCSSColor(value:ColorValue):String
	{
		var cssColorValue:String;
		
		switch (value)
		{
			case hex(value):
				cssColorValue = value;
				
			case rgb(red, green, blue):
				cssColorValue = "rgb(" + red + "," + green + "," + blue + ")";
				
			case rgba(red, green, blue, alpha):
				cssColorValue = "rgba(" + red + "," + green + "," + blue + "," + alpha + ")";
				
			case keyword(value):
				cssColorValue = getColorFromKeyword(value);
				
			case transparent:
				cssColorValue = "transparent";
		}
		
		return cssColorValue;
	}
	
	private function getCSSLength(lengthValue:Length):String
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
	
	private function getCSSAngle(value:Angle):String
	{
		var cssAngle:String;
		
		switch (value)
		{
			case Angle.deg(value):
				cssAngle = Std.string(value) + "deg";
				
			case Angle.rad(value):
				cssAngle = Std.string(value) + "rad";
				
			case Angle.grad(value):
				cssAngle = Std.string(value) + "grad";
				
			case Angle.turn(value):
				cssAngle = Std.string(value) + "turn";
		}
		
		return cssAngle;
	}
	
	private function getColorFromKeyword(value:ColorKeyword):String
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
	 * the vendor specific style name to use. Might return
	 * null if no style was found
	 * @param	nativeStyle the JavaScript Style object
	 */
	private function getVendorSpecificStyleName(nativeStyle:Dynamic, styleName:String):String
	{
		var vendorSpecificStyleName:String;
		
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
			else
			{
				vendorSpecificStyleName = null;
			}
		}
		
		return vendorSpecificStyleName;
	}
	
	/////////////////////////////////
	// OVERRIDEN STYLES SETTERS
	// All methods convert the Style
	// value into a CSS style value
	// (as a String) and set the native
	// CSS style on the HTMLElement's
	// NativeElement
	////////////////////////////////
	
	override private function setVerticalAlign(value:VerticalAlign):VerticalAlign
	{
		this._htmlElement.nativeElement.style.verticalAlign = getCSSVerticalAlign(value);
		super.setVerticalAlign(value);
		return _verticalAlign = value;
	}
	
	override private function setColor(value:ColorValue):ColorValue
	{
		this._htmlElement.nativeElement.style.color = getCSSColor(value);
		super.setColor(value);
		return _color = value;
	}
	
	override private function setWordSpacing(value:WordSpacing):WordSpacing
	{
		this._htmlElement.nativeElement.style.wordSpacing = getCSSWordSpacing(value);
		super.setWordSpacing(value);
		return _wordSpacing = value;
	}
	
	override private function setLetterSpacing(value:LetterSpacing):LetterSpacing
	{
		this._htmlElement.nativeElement.style.letterSpacing = getCSSLetterSpacing(value);
		super.setLetterSpacing(value);
		return _letterSpacing = value;
	}
	
	override private function setTextTransform(value:TextTransform):TextTransform
	{
		this._htmlElement.nativeElement.style.textTransform = getCSSTextTransform(value);
		super.setTextTransform(value);
		return _textTransform = value;
	}
	
	override private function setFontVariant(value:FontVariant):FontVariant
	{
		this._htmlElement.nativeElement.style.fontVariant = getCSSFontVariant(value);
		super.setFontVariant(value);
		return _fontVariant = value;
	}
	
	override private function setFontFamily(value:Array<FontFamily>):Array<FontFamily>
	{
		this._htmlElement.nativeElement.style.fontFamily = getCSSFontFamily(value);
		super.setFontFamily(value);
		return _fontFamily = value;
	}
	
	override private function setFontWeight(value:FontWeight):FontWeight
	{
		this._htmlElement.nativeElement.style.fontWeight = getCSSFontWeight(value);
		super.setFontWeight(value);
		return _fontWeight = value;
	}
	
	override private function setFontStyle(value:FontStyle):FontStyle
	{
		this._htmlElement.nativeElement.style.fontStyle = getCSSFontStyle(value);
		super.setFontStyle(value);
		return _fontStyle = value;
	}
	
	override private function setFontSize(value:FontSize):FontSize
	{
		this._htmlElement.nativeElement.style.fontSize = getCSSFontSize(value);
		super.setFontSize(value);
		return _fontSize = value;
	}
	
	override private function setLineHeight(value:LineHeight):LineHeight
	{
		this._htmlElement.nativeElement.style.lineHeight = getCSSLineHeight(value);
		super.setLineHeight(value);
		return _lineHeight = value;
	}
	
	override private function setMarginLeft(value:Margin):Margin 
	{
		this._htmlElement.nativeElement.style.marginLeft = getCSSMargin(value);
		super.setMarginLeft(value);
		return _marginLeft = value;
	}
	
	override private function setMarginRight(value:Margin):Margin 
	{
		this._htmlElement.nativeElement.style.marginRight = getCSSMargin(value);
		super.setMarginRight(value);
		return _marginRight = value;
	}
	
	override private function setMarginTop(value:Margin):Margin 
	{
		this._htmlElement.nativeElement.style.marginTop = getCSSMargin(value);
		super.setMarginTop(value);
		return _marginTop = value;
	}
	
	override private function setMarginBottom(value:Margin):Margin 
	{
		this._htmlElement.nativeElement.style.marginBottom = getCSSMargin(value);
		super.setMarginBottom(value);
		return _marginBottom = value;
	}
	
	override private function setPaddingLeft(value:Padding):Padding 
	{
		this._htmlElement.nativeElement.style.paddingLeft = getCSSPadding(value);
		super.setPaddingLeft(value);
		return _paddingLeft = value;
	}
	
	override private function setPaddingRight(value:Padding):Padding 
	{
		this._htmlElement.nativeElement.style.paddingRight = getCSSPadding(value);
		super.setPaddingRight(value);
		return _paddingRight = value;
	}
	
	override private function setPaddingTop(value:Padding):Padding 
	{
		this._htmlElement.nativeElement.style.paddingTop = getCSSPadding(value);
		super.setPaddingTop(value);
		return _paddingTop = value;
	}
	
	override private function setPaddingBottom(value:Padding):Padding 
	{
		this._htmlElement.nativeElement.style.paddingBottom = getCSSPadding(value);
		super.setPaddingBottom(value);
		return _paddingBottom = value;
	}
	
	override private function setDisplay(value:Display):Display 
	{
		this._htmlElement.nativeElement.style.display = getCSSDisplay(value);
		super.setDisplay(value);
		return _display = value;
	}
	
	override private function setPosition(value:Position):Position 
	{
		this._htmlElement.nativeElement.style.position = getCSSPosition(value);
		super.setPosition(value);
		return _position = value;
	}
	
	override private function setWidth(value:Dimension):Dimension 
	{
		this._htmlElement.nativeElement.style.width = getCSSDimension(value);
		super.setWidth(value);
		return _width = value;
	}
	
	override private function setHeight(value:Dimension):Dimension 
	{
		this._htmlElement.nativeElement.style.height = getCSSDimension(value);
		super.setHeight(value);
		return _height = value;
	}
	
	override private function setMinHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		this._htmlElement.nativeElement.style.minHeight = getCSSConstrainedDimension(value);
		super.setMinHeight(value);
		return _minHeight = value;
	}
	
	override private function setMaxHeight(value:ConstrainedDimension):ConstrainedDimension 
	{
		this._htmlElement.nativeElement.style.maxHeight = getCSSConstrainedDimension(value);
		super.setMaxHeight(value);
		return _maxHeight = value;
	}
	
	override private function setMinWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		this._htmlElement.nativeElement.style.minWidth = getCSSConstrainedDimension(value);
		super.setMinWidth(value);
		return _minWidth = value;
	}
	
	override private function setMaxWidth(value:ConstrainedDimension):ConstrainedDimension 
	{
		this._htmlElement.nativeElement.style.maxWidth = getCSSConstrainedDimension(value);
		super.setMaxWidth(value);
		return _maxWidth = value;
	}
	
	override private function setTop(value:PositionOffset):PositionOffset 
	{
		this._htmlElement.nativeElement.style.top = getCSSPositionOffset(value);
		super.setTop(value);
		return _top = value;
	}
	
	override private function setLeft(value:PositionOffset):PositionOffset 
	{
		this._htmlElement.nativeElement.style.left = getCSSPositionOffset(value);
		super.setLeft(value);
		return _left = value;
	}
	
	override private function setBottom(value:PositionOffset):PositionOffset 
	{
		this._htmlElement.nativeElement.style.bottom = getCSSPositionOffset(value);
		super.setBottom(value);
		return _bottom = value;
	}
	
	override private function setRight(value:PositionOffset):PositionOffset 
	{
		this._htmlElement.nativeElement.style.right = getCSSPositionOffset(value);
		super.setRight(value);
		return _right = value;
	}
	
	override private function setTextIndent(value:TextIndent):TextIndent
	{
		this._htmlElement.nativeElement.style.textIndent = getCSSTextIndent(value);
		super.setTextIndent(value);
		return _textIndent = value;
	}
	
	override private function setCSSFloat(value:CSSFloat):CSSFloat 
	{
		untyped this._htmlElement.nativeElement.style.cssFloat = getCSSFloatAsString(value);
		super.setCSSFloat(value);
		return _cssFloat = value;
	}
	
	override private function setClear(value:Clear):Clear 
	{
		this._htmlElement.nativeElement.style.clear = getCSSClear(value);
		super.setClear(value);
		return _clear = value;
	}
	
	override private function setWhiteSpace(value:WhiteSpace):WhiteSpace
	{
		this._htmlElement.nativeElement.style.whiteSpace = getCSSWhiteSpace(value);
		super.setWhiteSpace(value);
		return _whiteSpace = value;
	}
	
	override private function setTextAlign(value:TextAlign):TextAlign
	{
		this._htmlElement.nativeElement.style.textAlign = getCSSTextAlign(value);
		super.setTextAlign(value);
		return _textAlign = value;
	}
	
	override private function setOpacity(value:Opacity):Opacity
	{
		untyped this._htmlElement.nativeElement.style.opacity = getCSSOpacity(value);
		super.setOpacity(value);
		return _opacity = value;
	}
	
	override private function setVisibility(value:Visibility):Visibility
	{
		this._htmlElement.nativeElement.style.visibility = getCSSVisibility(value);
		super.setVisibility(value);
		return _visibility = value;
	}
	
	override private function setTransformOrigin(value:TransformOrigin):TransformOrigin
	{
		var nativeStyle:Dynamic = this._htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "transformOrigin");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName, getCSSTransformOrigin(value));
		}
		super.setTransformOrigin(value);
		
		return _transformOrigin = value;
	}
	
	override private function setTransform(value:Transform):Transform
	{
		var nativeStyle:Dynamic = this._htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "transform");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName , getCSSTransform(value));
		}
		
		super.setTransform(value);
		return _transform = value;
	}
	
	override private function setBackgroundColor(value:BackgroundColor):BackgroundColor
	{
		this._htmlElement.nativeElement.style.backgroundColor = getCSSBackgroundColor(value);
		super.setBackgroundColor(value);
		return _backgroundColor;
	}
	
	override private function setBackgroundOrigin(value:Array<BackgroundOrigin>):Array<BackgroundOrigin>
	{
		var nativeStyle:Dynamic = this._htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "backgroundOrigin");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName , getCSSBackgroundOrigin(value));
		}
		
		super.setBackgroundOrigin(value);
		return _backgroundOrigin;
	}
	
	override private function setBackgroundClip(value:Array<BackgroundClip>):Array<BackgroundClip>
	{
		var nativeStyle:Dynamic = this._htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "backgroundClip");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName , getCSSBackgroundClip(value));
		}
		
		super.setBackgroundClip(value);
		return _backgroundClip;
	}
	
	override private function setBackgroundImage(value:Array<BackgroundImage>):Array<BackgroundImage>
	{
		var cssBackgroundImage:String = getCSSBackgroundImage(value);
		
		//as gradient are not standard yet in CSS, the property has to be applied with each vendor speicific prefix, only the 
		//right one will be used
		this._htmlElement.nativeElement.style.backgroundImage = cssBackgroundImage;
		this._htmlElement.nativeElement.style.backgroundImage = StringTools.replace(cssBackgroundImage, 'linear-gradient', '-webkit-linear-gradient');
		this._htmlElement.nativeElement.style.backgroundImage = StringTools.replace(cssBackgroundImage, 'linear-gradient', '-moz-linear-gradient');
		
		super.setBackgroundImage(value);
		return _backgroundImage;
	}
	
	override private function setBackgroundPosition(value:Array<BackgroundPosition>):Array<BackgroundPosition>
	{
		this._htmlElement.nativeElement.style.backgroundPosition = getCSSBackgroundPosition(value);
		super.setBackgroundPosition(value);
		return _backgroundPosition;
	}
	
	override private function setBackgroundSize(value:Array<BackgroundSize>):Array<BackgroundSize>
	{
		var nativeStyle:Dynamic = this._htmlElement.nativeElement.style;
		//get vendor specific style name
		var vendorSpecificName:String = getVendorSpecificStyleName(nativeStyle, "backgroundSize");
		//only apply the style if it exists
		if (vendorSpecificName != null)
		{
			Reflect.setField(nativeStyle, vendorSpecificName , getCSSBackgroundSize(value));
		}
		
		super.setBackgroundSize(value);
		return _backgroundSize;
	}
	
	override private function setBackgroundRepeat(value:Array<BackgroundRepeat>):Array<BackgroundRepeat>
	{
		this._htmlElement.nativeElement.style.backgroundRepeat = getCSSBackgroundRepeat(value);
		super.setBackgroundRepeat(value);
		return _backgroundRepeat;
	}
	
	override private function setOverflowX(value:Overflow):Overflow
	{
		this._htmlElement.nativeElement.style.overflowX = getCSSOverflow(value);
		super.setOverflowX(value);
		return _overflowX = value;
	}
	
	override private function setOverflowY(value:Overflow):Overflow
	{
		this._htmlElement.nativeElement.style.overflowY = getCSSOverflow(value);
		super.setOverflowY(value);
		return _overflowY = value;
	}
}