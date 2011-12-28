/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.unit;
import cocktail.unit.UnitData;
import haxe.Log;

/**
 * This class exposes static unit conversion
 * methods
 * 
 * @author Yannick DOMINGUEZ
 */
class UnitManager 
{
	/**
	 * class constructor. Private as this class 
	 * is meant to be manipulated through static
	 * methods
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Get a value in pixel 
	 * from a length value
	 * (px, em, cm...)
	 * @param	length contains the unit type and the value
	 * @param	emReference the computed value used as reference
	 * when computing an em relative length value. It can be either the
	 * DOMElement's computed font size or its parent's if the computed em
	 * value is the font size of the DOMElement
	 * @param exReference he computed value used as reference
	 * when computing an ex relative length value. It can be either the
	 * DOMElement's x-height or its parent's x-height if the computed ex value
	 * is the font size of the DOMElement
	 * @return returns the computed value as pixel with rounded
	 * values
	 */ 
	public static function getPixelFromLengthValue(length:LengthValue, emReference:Float, exReference:Float):Int
	{
		var lengthValue:Float;
		
		switch (length)
		{
			case px(value):
				lengthValue = value;
				
			case mm(value):
				lengthValue = (value * ((72 * (1 / 0.75)) / 2.54)) / 10;
				
			case cm(value):
				lengthValue = value * ((72 * (1/0.75)) / 2.54);
				
			case pt(value):
				lengthValue = value * 1/0.75;	
				
			case _in(value):
				lengthValue = value * (72 * (1/0.75));
				
			case pc(value):
				lengthValue = value * (12 * (1 / 0.75));	
				
			case em(value):
				lengthValue = emReference * value;
				
			case ex(value):
				lengthValue = exReference * value;
		}
		
		return Math.round(lengthValue);
	}
	
	/**
	 * Takes an absolute size value for a font size and return
	 * a pixel value
	 */
	public static function getFontSizeFromAbsoluteSizeValue(absoluteSize:FontSizeAbsoluteSizeValue):Float
	{
		var fontSize:Float;
		
		var mediumFontSize:Int = 16;
		
		switch (absoluteSize)
		{
			case xxSmall:
				fontSize = 9;
				
			case xSmall:
				fontSize = 10;
				
			case small:
				fontSize = 13;
				
			case medium:
				fontSize = 16;
				
			case large:
				fontSize = 18;
				
			case xLarge:
				fontSize = 24;
				
			case xxLarge:
				fontSize = 32;
		}
		
		return fontSize;
	}
	
	/**
	 * Take a relative value for a font size and return
	 * a pixel value using the parent's computed font
	 */
	public static function getFontSizeFromRelativeSizeValue(relativeSize:FontSizeRelativeSizeValue, parentFontSize:Float):Float
	{
		var fontSize:Float;
		
		switch (relativeSize)
		{
			case larger:
				fontSize = getLargerFontSize(parentFontSize);
				
			case smaller:
				fontSize = getSmallerFontSize(parentFontSize);
		}
		
		return fontSize;
	}
	
	/**
	 * Get a percentage of a reference value
	 * @param	percent form 0 to 100
	 * @param	reference the reference value
	 * @return a percentage of the reference value
	 */
	public static function getPixelFromPercent(percent:Int, reference:Int):Float
	{
		return reference * (percent * 0.01);
	}
	
	/**
	 * Get an integer color value from a serialised color value
	 */
	public static function getColorFromColorValue(value:ColorValue):Int
	{
		var color:Int;
		
		switch (value)
		{
			case RGB(red, green, blue):
				color = red;
				color = (color << 8) + green;
				color = (color << 8) + blue;
			
			case hex(value):
				color = Std.parseInt(StringTools.replace(value, "#", "0x"));
				
			case keyword(value):
				color = getColorFromColorValueKeyword(value);

		}
		
		return color;
	}
	
	/**
	 * Get a radian angle from any other angle value
	 */
	public static function getRadFromAngleValue(value:AngleValue):Float
	{
		var angle:Float;
		
		switch (value)
		{
			case deg(value):
				angle = value * (Math.PI / 180);
				
			case rad(value):
				angle = value;
				
			case turn(value):
				angle = (value * 360) * (Math.PI / 180);
				
			case grad(value):	
				angle = value * (Math.PI / 200);
		}
		
		return angle;
	}
	
	/**
	 * Get a degree angle from any other angle value
	 */
	public static function getDegreeFromAngleValue(value:AngleValue):Float
	{
		var angle:Float;
		
		switch (value)
		{
			case deg(value):
				angle = value;
				
			case rad(value):
				angle = value * (180 / Math.PI);
				
			case turn(value):
				angle = value * 360;
				
			case grad(value):	
				angle = value * 0.9;
		}
		
		return angle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Get an integer color value from a keyword color value
	 */
	private static function getColorFromColorValueKeyword(value:ColorKeywordValue):Int
	{
		var hexColor:String;
		
		switch (value)
		{
			case aqua:
				hexColor = "#00FFFF";
				
			case black:
				hexColor = "#000000";
				
			case blue:
				hexColor = "#0000FF";
				
			case fuchsia:
				hexColor = "#FF00FF";
				
			case gray:
				hexColor = "#808080";
				
			case green:
				hexColor = "#008000";
				
			case lime:
				hexColor = "#00FF00";
				
			case maroon:
				hexColor = "#800000";
				
			case navy:
				hexColor = "#000080";
				
			case olive:
				hexColor = "#808000";
				
			case orange:
				hexColor = "#FFA500";
				
			case purple:
				hexColor = "#800080";
				
			case red:
				hexColor = "#FF0000";
				
			case silver:
				hexColor = "#C0C0C0";
				
			case teal:
				hexColor = "#008080";
				
			case white:
				hexColor = "#FFFFFF";
				
			case yellow:
				hexColor = "#FFFF00";
				
		}
		
		return getColorFromColorValue(ColorValue.hex(hexColor));
	}
	
	/**
	 * Get the next largest font size in the font size size array, taking
	 * the parent's font size as starting value
	 */
	private static function getLargerFontSize(parentFontSize:Float):Float
	{
		var fontSizeTable:Array<Int> = [9, 10, 13, 16, 18, 24, 32];
		var fontSize:Float = fontSizeTable[fontSizeTable.length - 1];
		
		for (i in 0...fontSizeTable.length)
		{
			if (fontSizeTable[i] > parentFontSize)
			{
				fontSize = fontSizeTable[i];
				break;
			}
		}
	
		return fontSize;
	}
	
	/**
	 * Get the next smallest font size in the font size size array, taking
	 * the parent's font size as starting value
	 */
	private static function getSmallerFontSize(parentFontSize:Float):Float
	{
		
		var fontSizeTable:Array<Int> = [9, 10, 13, 16, 18, 24, 32];
		var fontSize:Float = fontSizeTable[0];
		
		var i:Int = fontSizeTable.length - 1;
		
		while (i > 0 )
		{
			if (fontSizeTable[i] < parentFontSize)
			{
				
				fontSize = fontSizeTable[i];
				
				break;
			}
			
			i--;
		}
			
		return fontSize;
	}
	
}