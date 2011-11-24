/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.unit;
import cocktail.unit.UnitData;

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
	 * @return returns the computed value as pixel with rounded
	 * values
	 */ 
	public static function getPixelFromLengthValue(length:LengthValue):Int
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
				lengthValue = value * (12 * (1/0.75));	
		}
		
		return Math.round(lengthValue);
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
	
}