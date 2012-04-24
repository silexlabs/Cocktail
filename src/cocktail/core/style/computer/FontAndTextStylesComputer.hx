/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer;

import cocktail.core.style.CoreStyle;
import cocktail.core.unit.UnitData;
import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitManager;
import cocktail.core.font.FontData;
import haxe.Log;

/**
 * Compute the Font and Text related styles
 * of a HTMLElement, helped by the containing
 * HTMLElement dimensions and font metrics
 * 
 * @author Yannick DOMINGUEZ
 */
class FontAndTextStylesComputer 
{
	/**
	 * Class contructor. Private, as
	 * this class is meant to be accessed
	 * through its public static methods
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * compute all the font and text styles of the HTMLElement
	 * @param	style
	 * @param	containingHTMLElementData
	 * @param	containingHTMLElementFontMetricsData
	 */
	public static function compute(style:CoreStyle, containingHTMLElementData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Void
	{
		var computedStyle = style.computedStyle;

		//font size
		computedStyle.fontSize = getComputedFontSize(style, containingHTMLElementFontMetricsData.fontSize, containingHTMLElementFontMetricsData.xHeight);
		
		//line height
		computedStyle.lineHeight = getComputedLineHeight(style);
		
		//vertival align
		computedStyle.verticalAlign = getComputedVerticalAlign(style, containingHTMLElementData, containingHTMLElementFontMetricsData);
		
		//font weight
		computedStyle.fontWeight = style.fontWeight;
		
		//font style
		computedStyle.fontStyle = style.fontStyle;
		
		//font family
		computedStyle.fontFamily = style.fontFamily;
		
		//font variant
		computedStyle.fontVariant = style.fontVariant;
		
		//text transform
		computedStyle.textTransform = style.textTransform;
		
		//letter spacing
		computedStyle.letterSpacing = getComputedLetterSpacing(style);
		
		//word spacing
		computedStyle.wordSpacing = getComputedWordSpacing(style);
		
		//text indent
		computedStyle.textIndent = getComputedTextIndent(style, containingHTMLElementData);
		
		//white space
		computedStyle.whiteSpace = style.whiteSpace;
		
		//text align
		computedStyle.textAlign = getComputedTextAlign(style, computedStyle.whiteSpace);
		
		//text color
		computedStyle.color = getComputedColor(style);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the text indent to apply to the first line of an inline formatting context
	 */
	private static function getComputedTextIndent(style:CoreStyle, containingHTMLElementData:ContainingHTMLElementData):Int
	{
		var textIndent:Float;
		
		switch(style.textIndent)
		{
			case length(value):
				textIndent = UnitManager.getPixelFromLength(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				
			case percentage(value):
				textIndent = UnitManager.getPixelFromPercent(value, containingHTMLElementData.width);
		}
		
		return Math.round(textIndent);
	}
	
	/**
	 * Compute the vertical offset to apply to a HTMLElement in an inline
	 * formatting context
	 */
	private static function getComputedVerticalAlign(style:CoreStyle, containingHTMLElementData:ContainingHTMLElementData, containingHTMLElementFontMetricsData:FontMetricsData):Float
	{
		var verticalAlign:Float;
		
		switch(style.verticalAlign)
		{
			case baseline:
				verticalAlign = 0;
				
			case middle:
				var offsetHeight:Int = style.computedStyle.height + style.computedStyle.paddingTop + style.computedStyle.paddingBottom;
				verticalAlign = offsetHeight / 2 + containingHTMLElementFontMetricsData.xHeight / 2;
				
			case sub:
				verticalAlign = containingHTMLElementFontMetricsData.subscriptOffset;
				
			case cssSuper:
				verticalAlign = containingHTMLElementFontMetricsData.superscriptOffset;
				
			case textTop:
				verticalAlign = 0;
				//TODO : Align the top of the box with the top of the parent's content area
				
			case textBottom:
				verticalAlign = 0;
				//TODO : Align the bottom of the box with the bottom of the parent's content area 
				
			case percent(value):
				verticalAlign = UnitManager.getPixelFromPercent(value, Math.round(style.computedStyle.lineHeight));
				
			case length(value):
				verticalAlign = UnitManager.getPixelFromLength(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				
			case top:
				verticalAlign = 0;
			case bottom:	
				verticalAlign = 0;
		}
		
		return verticalAlign;
	}
	
	/**
	 * The text alignement might be influenced by the
	 * white space style. when there are no line-break,
	 * the text can't be justified
	 */
	private static function getComputedTextAlign(style:CoreStyle, computedWhiteSpace:WhiteSpace):TextAlign
	{
		var textAlign:TextAlign = style.textAlign;
		
		switch (computedWhiteSpace)
		{
			case pre:
				if (style.textAlign == TextAlign.justify)
				{
					
					textAlign = TextAlign.left;
				}
				
			default:
		}
		
		return textAlign;
	}
	
	/**
	 * Computed the color of a text of the HTMLElement
	 */
	private static function getComputedColor(style:CoreStyle):ColorData
	{
		return UnitManager.getColorDataFromCSSColor(style.color);
	}
	
	/**
	 * Compute the space to add between each word in a text in
	 * addition of the regular font space
	 */
	private static function getComputedWordSpacing(style:CoreStyle):Int
	{
		var wordSpacing:Int;
		
		switch (style.wordSpacing)
		{
			case normal:
				wordSpacing = 0;
				
			case length(unit):
				wordSpacing = Math.round(UnitManager.getPixelFromLength(unit, style.computedStyle.fontSize, style.fontMetrics.xHeight));
		}
		
		return wordSpacing;
	}
	
	/**
	 * Compute the line height of a HTMLElement in an inline
	 * formatting context
	 */
	private static function getComputedLineHeight(style:CoreStyle):Float
	{
		var lineHeight:Float;
		
		switch (style.lineHeight)
		{
			case length(unit):
				lineHeight = UnitManager.getPixelFromLength(unit, style.computedStyle.fontSize, style.fontMetrics.xHeight);
				
			case normal:
				lineHeight = style.computedStyle.fontSize * 1.2;
				
			case percentage(value):
				lineHeight = UnitManager.getPixelFromPercent(value, Math.round(style.computedStyle.fontSize));
				
			case number(value):
				lineHeight = style.computedStyle.fontSize * value;
		}
		
		return lineHeight;
	}
	
	/**
	 * Compute the space to apply between each
	 * letter in a text, in addition to the regular
	 * font letter spacing
	 */
	private static function getComputedLetterSpacing(style:CoreStyle):Int
	{
		var letterSpacing:Int;
		
		switch (style.letterSpacing)
		{
			case normal:
				letterSpacing = 0;
				
			case length(unit):
				letterSpacing = Math.round(UnitManager.getPixelFromLength(unit, style.fontMetrics.fontSize, style.fontMetrics.xHeight));
		}
		
		return letterSpacing;
	}
	
	/**
	 * Compute the font size of the text of a HTMLElement
	 */
	private static function getComputedFontSize(style:CoreStyle, parentFontSize:Float, parentXHeight:Float):Float
	{
		var fontSize:Float;
		
		switch (style.fontSize)
		{
			case length(unit):
				fontSize = UnitManager.getPixelFromLength(unit, parentFontSize, parentXHeight);
				
			case percentage(percent):
				fontSize = UnitManager.getPixelFromPercent(percent, Math.round(parentFontSize));
				
			case absoluteSize(value):
				fontSize = UnitManager.getFontSizeFromAbsoluteSizeValue(value);
				
			case relativeSize(value):
				fontSize = UnitManager.getFontSizeFromRelativeSizeValue(value, parentFontSize);
				
		}
		
		return fontSize;
	}
}