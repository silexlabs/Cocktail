/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;	
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import haxe.Log;

/**
 * This class exposes helper static methods
 * to convert CSS values
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSValueConverter 
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
	 * htmlElement's computed font size or its parent's if the computed em
	 * value is the font size of the htmlElement
	 * @param exReference he computed value used as reference
	 * when computing an ex relative length value. It can be either the
	 * htmlElement's x-height or its parent's x-height if the computed ex value
	 * is the font size of the htmlElement
	 * @return returns the computed value as pixel with rounded
	 * values
	 */ 
	public static function getPixelFromLength(length:CSSLengthValue, emReference:Float, exReference:Float):Float
	{
		var lengthValue:Float;
		
		switch (length)
		{
			case PX(value):
				lengthValue = value;
				
			case MM(value):
				lengthValue = (value * ((72 * (1 / 0.75)) / 2.54)) / 10;
				
			case CM(value):
				lengthValue = value * ((72 * (1/0.75)) / 2.54);
				
			case PT(value):
				lengthValue = value * 1/0.75;	
				
			case IN(value):
				lengthValue = value * (72 * (1 / 0.75));
				
			case PC(value):
				lengthValue = value * (12 * (1 / 0.75));	
				
			case EM(value):
				lengthValue = emReference * value;
				
			case EX(value):
				lengthValue = exReference * value;
		}
		
		return lengthValue;
	}
	
	/**
	 * Convert a font-family property into a string array
	 * of font names
	 */
	public static function getFontFamilyAsStringArray(value:CSSPropertyValue):Array<String>
	{
		var fontNames:Array<String> = new Array<String>();
		
		switch(value)
		{
			case CSS_LIST(value):
				for (i in 0...value.length)
				{
					switch(value[i])
					{
						case STRING(value):
							fontNames.push(value);
							
						case IDENTIFIER(value):
							fontNames.push(value);

						default:
							throw 'Illegal value for font family style';
					}
					
				}
				
			case IDENTIFIER(value):
				fontNames = [value];
				
			default:	
				throw 'Illegal value for font family style';
				
		}
		
		return fontNames;
	}
	
	/**
	 * Takes an absolute size value for a font size and return
	 * a pixel value
	 * 
	 * TODO 2 : values are hard-coded, should go into config ?
	 */
	public static function getFontSizeFromAbsoluteSizeValue(absoluteSize:CSSKeywordValue):Float
	{
		var fontSize:Float = 0.0;
		
		var mediumFontSize:Int = 16;
		
		switch (absoluteSize)
		{
			case XX_SMALL:
				fontSize = 9;
				
			case X_SMALL:
				fontSize = 10;
				
			case SMALL:
				fontSize = 13;
				
			case MEDIUM:
				fontSize = 16;
				
			case LARGE:
				fontSize = 18;
				
			case X_LARGE:
				fontSize = 24;
				
			case XX_LARGE:
				fontSize = 32;
				
			default:
				throw 'Illegal keyword value for font size';
		}
		
		return fontSize;
	}
	
	/**
	 * Take a relative value for a font size and return
	 * a pixel value using the parent's computed font
	 */
	public static function getFontSizeFromRelativeSizeValue(relativeSize:CSSKeywordValue, parentFontSize:Float):Float
	{
		var fontSize:Float = 0.0;
		
		switch (relativeSize)
		{
			case LARGER:
				fontSize = getLargerFontSize(parentFontSize);
				
			case SMALLER:
				fontSize = getSmallerFontSize(parentFontSize);
				
			default:
				throw 'Illegal keyword value for font size';	
		}
		
		return fontSize;
	}
	
	/**
	 * Get a percentage of a reference value
	 * @param	percent form 0 to 100
	 * @param	reference the reference value
	 * @return a percentage of the reference value
	 */
	public static function getPixelFromPercent(percent:Float, reference:Float):Float
	{
		return reference * (percent * 0.01);
	}
	
	/**
	 * Get a percentage from a pixel value in a reference value
	 * @param	pixel
	 * @param	reference
	 * @return
	 */
	public static function getPercentFromPixel(pixel:Float, reference:Float):Float
	{
		return (reference / pixel) * 100;
	}
	
	
	/**
	 * Return the computed value of a CSS color from a specified
	 * CSS Color. For instance, color keyword (blue, red...) are computed
	 * into rgba color
	 * 
	 * TODO 2 : manage currentColor
	 * 
	 * @param	colorProperty the specified color value
	 * @param	currentColor the computed value of the 'color' property
	 */
	public static function getComputedCSSColorFromCSSColor(colorProperty:CSSColorValue, currentColor:CSSColorValue):CSSColorValue
	{
		switch(colorProperty)
		{
			case KEYWORD(value):
				return getRGBAColorFromColorKeyword(value);
				
			case TRANSPARENT:
				return RGBA(0, 0, 0, 0.0);
				
			case RGB(red, green, blue):
				
				//clamp to valid color values
				red = clampInteger(red, 255, 0);
				green = clampInteger(green, 255, 0);
				blue = clampInteger(blue, 255, 0);
				
				return RGBA(red, green, blue, 1.0);
				
			case RGB_PERCENTAGE(red, green, blue):	
				
				//clamp to valid percent values
				red = clampNumber(red, 100, 0);
				green = clampNumber(green, 100, 0);
				blue = clampNumber(blue, 100, 0);
				
				return RGBA(Math.round(255 * (red * 0.01)), Math.round(255 * (green * 0.01)), Math.round(255 * (blue * 0.01)), 1.0);
				
			case RGBA(red, green, blue, alpha):
				
				//clamp to valid color values
				red = clampInteger(red, 255, 0);
				green = clampInteger(green, 255, 0);
				blue = clampInteger(blue, 255, 0);
				
				alpha = clampNumber(alpha, 1.0, 0.0);
				
				return RGBA(red, green, blue, alpha);
				
			case RGBA_PERCENTAGE(red, green, blue, alpha):
				
				//clamp to valid percent values
				red = clampNumber(red, 100, 0);
				green = clampNumber(green, 100, 0);
				blue = clampNumber(blue, 100, 0);
				
				alpha = clampNumber(alpha, 1.0, 0.0);
				
				return RGBA(Math.round(255 * (red * 0.01)), Math.round(255 * (green * 0.01)), Math.round(255 * (blue * 0.01)), alpha);
				
			case HSL(hue, saturation, lightness):
				return colorProperty;
				
			case HSLA(hue, saturation, lightness, alpha):
				return colorProperty;
			
			case HEX(value):
				
				//pad the hex number if needed by duplicating
				//each value
				var paddedHex:String = "";
				if (value.length == 3)
				{
					paddedHex += value.charAt(0);
					paddedHex += value.charAt(0);
					paddedHex += value.charAt(1);
					paddedHex += value.charAt(1);
					paddedHex += value.charAt(2);
					paddedHex += value.charAt(2);
				}
				else
				{
					paddedHex = value;
				}
				
				//compute the hex into an rgba number
				return hexToRGBA(paddedHex);
				
			case CURRENT_COLOR:	
				return currentColor;
		}
	}
	
	/**
	 * Get an integer color and an alpha from 0 to 1 from a serialised color value
	 */
	public static function getColorDataFromCSSColor(value:CSSColorValue):ColorData
	{
		var colorValue:Int = 0;
		var alphaValue:Float = 0;
		
		switch (value)
		{
			case RGBA(red, green, blue, alpha):
				colorValue = red;
				colorValue = (colorValue << 8) + green;
				colorValue = (colorValue << 8) + blue;
				alphaValue = alpha;	
				
			case HSL(hue, saturation, lightness):
				//TODO 2
			case HSLA(hue, saturation, lightness, alpha): 
				//TODO 2
				
			default:
				//other color values (keyword, hex, rgb...) were converted to RGBA during 
				//cascade
		}
		
		var colorData:ColorData = {
			color:colorValue,
			alpha:alphaValue
		}
		
		return colorData;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils to clamp a number to a given range
	 */
	private static function clampNumber(number:Float, max:Float, min:Float):Float
	{
		if (number > max)
		{
			return max;
		}
		if (number < min)
		{
			return min;
		}
		return number;
	}
	
	/**
	 * Same as above for integer values
	 */
	private static function clampInteger(integer:Int, max:Int, min:Int):Int
	{
		if (integer > max)
		{
			return max;
		}
		if (integer < min)
		{
			return min;
		}
		return integer;
	}
	
	/**
	 * Convert an hex value to RGB
	 * 
	 * TODO 4 : probably the ugliest thing I've done so far
	 */
	private static function hexToRGBA(hex:String):CSSColorValue
	{
		var red:Int = hexToInt(hex.charAt(0)) * 16 + hexToInt(hex.charAt(1));
		var green:Int = hexToInt(hex.charAt(2)) * 16 + hexToInt(hex.charAt(3));
		var blue:Int = hexToInt(hex.charAt(4)) * 16 + hexToInt(hex.charAt(5));
		
		return RGBA(red, green, blue, 1.0);
	}
	
	/**
	 * convert hexa to int
	 */
	private static function hexToInt(char:String):Int
	{
		switch(char.toUpperCase())
		{
			case "0":
				return 0;
				
			case "1":
				return 1;
				
			case "2":
				return 2;
				
			case "3":
				return 3;
				
			case "4":
				return 4;
				
			case "5":
				return 5;
				
			case "6":
				return 6;
				
			case "7":
				return 7;
				
			case "8":
				return 8;
				
			case "9":
				return 9;
				
			case "A":
				return 10;
				
			case "B":
				return 11;
				
			case "C":
				return 12;
				
			case "D":
				return 13;
				
			case "E":
				return 14;
				
			case "F":
				return 15;
		}
		
		return 0;
	}
	
	/**
	 * return a CSS rgba color from a 
	 * color keyword
	 */
	private static function getRGBAColorFromColorKeyword(value:CSSColorKeyword):CSSColorValue
	{	
		switch (value)
		{
			case AQUA:
				return RGBA(0, 255, 255, 1.0);
				
			case BLACK:
				return RGBA(0, 0, 0, 1.0);
				
			case BLUE:
				return RGBA(0, 0, 255, 1.0);
				
			case FUSHIA:
				return RGBA(255, 0, 255, 1.0);
				
			case GRAY:
				return RGBA(128, 128, 128, 1.0);
				
			case GREEN:
				return RGBA(0, 128, 0, 1.0);
				
			case LIME:
				return RGBA(0, 255, 0, 1.0);
				
			case MAROON:
				return RGBA(128, 0, 0, 1.0);
				
			case NAVY:
				return RGBA(0, 0, 128, 1.0);
				
			case OLIVE:
				return RGBA(128, 128, 0, 1.0);
				
			case ORANGE:
				return RGBA(255, 165, 0, 1.0);
				
			case PURPLE:
				return RGBA(255, 165, 0, 1.0);
				
			case RED:
				return RGBA(255, 0, 0, 1.0);
				
			case SILVER:
				return RGBA(192, 192, 192, 1.0);
				
			case TEAL:
				return RGBA(0, 128, 128, 1.0);
				
			case WHITE:
				return RGBA(255, 255, 255, 1.0);
				
			case YELLOW:
				return RGBA(255, 255, 0, 1.0);
				
		}
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
