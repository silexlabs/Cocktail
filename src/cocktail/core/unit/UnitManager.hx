/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.unit;
import cocktail.core.unit.UnitData;
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
	// PUBLIC METHODS FOR STRING TO ENUM CONVERSION (lexa)
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * convert a string into a typed enum
	 * works with Cocktail enums Dimension, Margin, Padding 
	 * @example CSSParser.boxStyleEnum(Padding, "100 px ") returns Padding.length(Length.px(100))
	 */
	static public function boxStyleEnum<EnumName>(enumType:Enum<EnumName>, string:String):EnumName{
		if(string == "auto")
			return Type.createEnum(enumType, "cssAuto");
		
		// split unit and value
		var parsed:VUnit = string2VUnit(string);
		// convert into typed enum
		return switch (parsed.unit){
			case "%":
				Type.createEnum(enumType, "percent", [Std.parseInt(parsed.value)]);	
			default:
				Type.createEnum(enumType, "length", [string2Length(parsed)]);
		}
	}
	/**
	 * convert a string into a typed Color enum
	 * @example CSSParser.colorEnum("yellow") returns Color.yellow
	 */
	static public function colorEnum(string:String):Color{
		// clean up a bit
		string = trim(string);
		// case of hex values, e.g. #FFFFFF
		if (StringTools.startsWith(string, "#"))
			return hex(string.substr(1));
		// case of rgba values, e.g. rgba(255, 255, 255, 1)
		if (StringTools.startsWith(string, "rgba")){
			var vcol:VCol = string2RGBA(string);
			return rgba(vcol.r, vcol.g, vcol.b, vcol.a);
		}
		// case of rgb values, e.g. rgb(255, 255, 255)
		if (StringTools.startsWith(string, "rgb")){
			var vcol:VCol = string2RGB(string);
			return rgb(vcol.r, vcol.g, vcol.b);
		}
		// case of transparent and keywords
		return switch (string)
		{
			case "transparent": Color.transparent;
			case "aqua": Color.keyword(aqua);
			case "black": Color.keyword(black);
			case "blue": Color.keyword(blue);
			case "fuchsia": Color.keyword(fuchsia);
			case "gray": Color.keyword(gray);
			case "green": Color.keyword(green);
			case "lime": Color.keyword(lime);
			case "maroon": Color.keyword(maroon);
			case "navy": Color.keyword(navy);
			case "olive": Color.keyword(olive);
			case "orange": Color.keyword(orange);
			case "purple": Color.keyword(purple);
			case "red": Color.keyword(red);
			case "silver": Color.keyword(silver);
			case "teal": Color.keyword(teal);
			case "white": Color.keyword(white);
			case "yellow": Color.keyword(yellow);	
			default:
				throw "unknown color \""+string+"\"";
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS FOR STRING TO ENUM CONVERSION (lexa)
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * function used internally to convert an rgba value to a 4 digit object of type VCol
	 */
	static private function string2RGBA(string:String):VCol{
		// remove "rgba(" and ")"
		string = string.substr(5, string.length - 6);
		// split into [r, g, b, a]
		var rgba:Array<String> = string.split(",");
		// insert "0"s if some channels are missing
		while(rgba.length < 4)
			rgba.push("0");
		// return a typed object
		return {
			r:Std.parseInt(trim(rgba[0])),
			g:Std.parseInt(trim(rgba[1])),
			b:Std.parseInt(trim(rgba[2])),
			a:Std.parseFloat(trim(rgba[3]))
		};
	}
	/**
	 * function used internally to convert an rgb value to a 3 digit object of type VCol
	 */
	static private function string2RGB(string:String):VCol{
		// remove "rgb(" and ")"
		string = string.substr(4, string.length - 5);
		// split into [r, g, b, a]
		var rgba:Array<String> = string.split(",");
		// insert "0"s if some channels are missing
		while(rgba.length < 3)
			rgba.push("0");
		// return a typed object
		return {
			r:Std.parseInt(trim(rgba[0])),
			g:Std.parseInt(trim(rgba[1])),
			b:Std.parseInt(trim(rgba[2])),
			a:null
		};
	}
	/**
	 * function used internally to trim left and right a string   
	 */
	static private function trim(string:String):String{
		return StringTools.ltrim(StringTools.rtrim(string));
	} 
	/**
	 * function used internally to split a string to a value/unit strings pair   
	 */
	static private function string2VUnit(string:String):VUnit{
		var r : EReg = ~/([0-9]*)(.*)/;
		r.match(string);
//		trace("return "+r.matched(1)+"+"+r.matched(2));
		return {
			value: r.matched(1), 
			unit : trim(r.matched(2))
		};
	}
	/**
	 * function used internally to convert a value/unit strings pair to an enum  
	 */
	static private function string2Length(parsed):Length{
		return switch (parsed.unit)
		{
			case "in":
				Length._in(Std.parseInt(parsed.value));	
			case "cm":
				Length.cm(Std.parseInt(parsed.value));	
			case "em":
				Length.em(Std.parseInt(parsed.value));	
			case "ex":
				Length.ex(Std.parseInt(parsed.value));	
			case "mm":
				Length.mm(Std.parseInt(parsed.value));	
			case "pc":
				Length.pc(Std.parseInt(parsed.value));	
			case "pt":
				Length.pt(Std.parseInt(parsed.value));	
			case "px":
				Length.px(Std.parseInt(parsed.value));
			default:
				throw("Bad unit \"" + parsed.unit+"\"");
		}
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
	public static function getPixelFromLength(length:Length, emReference:Float, exReference:Float):Int
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
	public static function getFontSizeFromAbsoluteSizeValue(absoluteSize:FontSizeAbsoluteSize):Float
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
	public static function getFontSizeFromRelativeSizeValue(relativeSize:FontSizeRelativeSize, parentFontSize:Float):Float
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
	 * Get a percentage from a pixel value in a reference value
	 * @param	pixel
	 * @param	reference
	 * @return
	 */
	public static function getPercentFromPixel(pixel:Int, reference:Int):Float
	{
		return (reference / pixel) * 100;
	}
	
	/**
	 * Get an integer color and an alpha from 0 to 1 from a serialised color value
	 */
	public static function getColorDataFromCSSColor(value:CSSColor):ColorData
	{
		var colorValue:Int;
		var alphaValue:Float;
		
		switch (value)
		{
			case rgb(red, green, blue):
				colorValue = red;
				colorValue = (colorValue << 8) + green;
				colorValue = (colorValue << 8) + blue;
				alphaValue = 1.0;
			
			case rgba(red, green, blue, alpha):
				colorValue = red;
				colorValue = (colorValue << 8) + green;
				colorValue = (colorValue << 8) + blue;
				alphaValue = alpha;
				
			case hex(value):
				colorValue = Std.parseInt(StringTools.replace(value, "#", "0x"));
				alphaValue = 1.0;
				
			case keyword(value):
				colorValue = getColorDataFromColorKeyword(value).color;
				alphaValue = 1.0;
			
			case transparent:
				colorValue = 0xFFFFFF;
				alphaValue = 0.0;
		}
		
		var colorData:ColorData = {
			color:colorValue,
			alpha:alphaValue
		}
		
		return colorData;
	}
	
	/**
	 * Get a radian angle from any other angle value
	 */
	public static function getRadFromAngle(value:Angle):Float
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
	public static function getDegreeFromAngle(value:Angle):Float
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
	private static function getColorDataFromColorKeyword(value:ColorKeyword):ColorData
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
		
		return getColorDataFromCSSColor(CSSColor.hex(hexColor));
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