/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.computer;


import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.unit.UnitData;
import cocktail.core.layout.LayoutData;
import cocktail.core.unit.UnitManager;
import cocktail.core.css.CSSData;
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
	 * @param	containingBlockData
	 * @param	containingBlockFontMetricsData
	 */
	public static function compute(style:CoreStyle, containingBlockData:ContainingBlockData):Void
	{
		var usedValues:UsedValuesData = style.usedValues;

		//line height
		var fontSize:Float = style.getAbsoluteLength(style.fontSize);
		usedValues.lineHeight = getUsedLineHeight(style, fontSize);
		
		//text indent
		usedValues.textIndent = getUsedTextIndent(style, containingBlockData);
		
		usedValues.color = UnitManager.getColorDataFromCSSColor(style.getColor(style.color));
		
		//letter spacing
		usedValues.letterSpacing = getUsedLetterSpacing(style);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the text indent to apply to the first line of an inline formatting context
	 */
	private static function getUsedTextIndent(style:CoreStyle, containingBlockData:ContainingBlockData):Float
	{
		var usedTextIndent:Float = 0.0;
		
		switch(style.textIndent)
		{
			case ABSOLUTE_LENGTH(value):
				usedTextIndent = value;
				
			case PERCENTAGE(value):
				usedTextIndent = UnitManager.getPixelFromPercent(value, containingBlockData.width);
				
			default:	
		}
		
		return usedTextIndent;
	}
	
	/**
	 * Compute the line height of a HTMLElement in an inline
	 * formatting context
	 */
	private static function getUsedLineHeight(style:CoreStyle, fontSize:Float):Float
	{
		var usedLineHeight:Float = 0.0;
		
		switch (style.lineHeight)
		{
			case ABSOLUTE_LENGTH(value):
				usedLineHeight = value;
				
			case KEYWORD(value):
				usedLineHeight = fontSize * 1.2;
				
			case NUMBER(value):
				usedLineHeight = fontSize * value;
				
			default:	
		}
		
		return usedLineHeight;
	}
	
	private static function getUsedLetterSpacing(style:CoreStyle):Float
	{
		var usedLetterSpacing:Float = 0.0;
		
		switch(style.letterSpacing)
		{
			case ABSOLUTE_LENGTH(value):
				usedLetterSpacing = value;
				
			case KEYWORD(value):
				usedLetterSpacing = 0.0;
				
			default:	
		}
		
		return usedLetterSpacing;
	}
}