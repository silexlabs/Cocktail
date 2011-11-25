/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.computer;

import cocktail.style.abstract.AbstractStyle;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;
import cocktail.unit.UnitManager;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class FontAndTextStylesComputer 
{

	public function new() 
	{
		
	}
	
	public static function compute(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions, containingDOMElementFontMetrics:FontMetrics):Void
	{
		var computedStyle = style.computedStyle;
		
		if (containingDOMElementFontMetrics != null)
		{
			computedStyle.fontSize = getComputedFontSize(style, containingDOMElementFontMetrics.fontSize, containingDOMElementFontMetrics.xHeight);
		}
		else
		{
			//TO DO : voir comment taille par défault du navigateur est géré, setter sur body en JS ?
			computedStyle.fontSize = getComputedFontSize(style, 12.0, 10.0);
		}
		
		
		computedStyle.lineHeight = getComputedLineHeight(style);
		
		computedStyle.verticalAlign = getComputedVerticalAlign(style, containingDOMElementFontMetrics);
		
		computedStyle.fontWeight = getComputedFontWeight(style);
		
		computedStyle.fontStyle = getComputedFontStyle(style);
		
		computedStyle.fontFamily = getComputedFontFamily(style);
		
		computedStyle.fontVariant = getComputedFontVariant(style);
		
		computedStyle.textTransform = getComputedTextTransform(style);
		
		computedStyle.letterSpacing = getComputedLetterSpacing(style);
		
		computedStyle.wordSpacing = getComputedWordSpacing(style);
		
		computedStyle.textIndent = getComputedTextIndent(style, containingDOMElementDimensions);
		
		computedStyle.whiteSpace = getComputedWhiteSpace(style);
		
		computedStyle.textAlign = getComputedTextAlign(style);
		
		computedStyle.color = getComputedColor(style);
		
	}
	
	private static function getComputedTextAlign(style:AbstractStyle):TextAlignStyleValue
	{
		return style.textAlign;
	}
	
	private static function getComputedWhiteSpace(style:AbstractStyle):WhiteSpaceStyleValue
	{
		return style.whiteSpace;
	}
	
	private static function getComputedTextIndent(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		var textIndent:Float;
		
		switch(style.textIndent)
		{
			case length(value):
				textIndent = UnitManager.getPixelFromLengthValue(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				
			case percentage(value):
				textIndent = UnitManager.getPixelFromPercent(value, containingDOMElementDimensions.width);
		}
		
		return Math.round(textIndent);
	}
	
	private static function getComputedVerticalAlign(style:AbstractStyle, containingDOMElementFontMetrics:FontMetrics):Float
	{
		
		//TO DO : must represent an offset from the inlinebox baseline
		var verticalAlign:Float;
		
		//To DO : move this to the box computer, will need to add either a ref to the containing dom element
		//or to its font metrics
		switch(style.verticalAlign)
		{
			case baseline:
				verticalAlign = 0;
				
			case middle:
				//! warning : containing dom element must be either an inline parent or the block which started inline context
				verticalAlign = style.domElement.offsetHeight / 2 + containingDOMElementFontMetrics.xHeight / 2;
			case sub:
				verticalAlign = containingDOMElementFontMetrics.subscriptOffset;
				
			case _super:
				verticalAlign = containingDOMElementFontMetrics.superscriptOffset;
				
			case textTop:
				verticalAlign = 0;
				//TO DO : Align the top of the box with the top of the parent's content area
				
			case textBottom:
				verticalAlign = 0;
				//TO DO : Align the bottom of the box with the bottom of the parent's content area 
				
			case percent(value):
				verticalAlign = UnitManager.getPixelFromPercent(value, Math.round(style.computedStyle.lineHeight));
				
			case length(value):
				verticalAlign = UnitManager.getPixelFromLengthValue(value, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				
			case top:
				verticalAlign = 0;
				//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
			case bottom:	
				verticalAlign = 0;
				//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
		}
		
		return verticalAlign;
	}
	
	private static function getComputedColor(style:AbstractStyle):Int
	{
		return UnitManager.getColorFromColorValue(style.color);
	}
	
	private static function getComputedWordSpacing(style:AbstractStyle):Int
	{
		var wordSpacing:Int;
		
		switch (style.wordSpacing)
		{
			case normal:
				wordSpacing = 0;
				
			case length(unit):
				wordSpacing = Math.round(UnitManager.getPixelFromLengthValue(unit, style.fontMetrics.fontSize, style.fontMetrics.xHeight));
		}
		
		return wordSpacing;
	}
	
	private static function getComputedLineHeight(style:AbstractStyle):Float
	{
		var lineHeight:Float;
		
		switch (style.lineHeight)
		{
			case length(unit):
				lineHeight = UnitManager.getPixelFromLengthValue(unit, style.fontMetrics.fontSize, style.fontMetrics.xHeight);
				
			case normal:
				lineHeight = style.computedStyle.fontSize * 1.2;
				
			case percentage(value):
				lineHeight = UnitManager.getPixelFromPercent(value, Math.round(style.computedStyle.fontSize));
				
			case number(value):
				lineHeight = style.computedStyle.fontSize * value;
		}
		
		return lineHeight;
	}
	
	private static function getComputedLetterSpacing(style:AbstractStyle):Int
	{
		var letterSpacing:Int;
		
		switch (style.letterSpacing)
		{
			case normal:
				letterSpacing = 0;
				
			case length(unit):
				letterSpacing = Math.round(UnitManager.getPixelFromLengthValue(unit, style.fontMetrics.fontSize, style.fontMetrics.xHeight));
		}
		
		return letterSpacing;
	}
	
	private static function getComputedTextTransform(style:AbstractStyle):TextTransformStyleValue
	{
		return style.textTransform;
	}
	
	private static function getComputedFontVariant(style:AbstractStyle):FontVariantStyleValue
	{
		return style.fontVariant;
	}
	
	private static function getComputedFontFamily(style:AbstractStyle):Array<FontFamilyStyleValue>
	{
		return style.fontFamily;
	}
	
	private static function getComputedFontSize(style:AbstractStyle, parentFontSize:Float, parentXHeight:Float):Float
	{
		var fontSize:Float;
		
		switch (style.fontSize)
		{
			case length(unit):
				fontSize = UnitManager.getPixelFromLengthValue(unit, parentFontSize, parentXHeight);
				
			case percentage(percent):
				fontSize = UnitManager.getPixelFromPercent(percent, Math.round(parentFontSize));
				
			case absoluteSize(value):
				fontSize = UnitManager.getFontSizeFromAbsoluteSizeValue(value);
				
			case relativeSize(value):
				fontSize = UnitManager.getFontSizeFromRelativeSizeValue(value, parentFontSize);
				
		}
		
		return fontSize;
	}
	
	private static function getComputedFontStyle(style:AbstractStyle):FontStyleStyleValue
	{
		return style.fontStyle;
	}
	
	private static function getComputedFontWeight(style:AbstractStyle):FontWeightStyleValue
	{
		return style.fontWeight;
	}
}