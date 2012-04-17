/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.unit;

import cocktail.core.unit.UnitData;
import cocktail.core.style.StyleData;
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
	
	
	static public function constrainedDimensionEnum(string:String):ConstrainedDimension
	{
		if (string == "none")
			return ConstrainedDimension.none;
		
		var parsed:VUnit = string2VUnit(string);
		var constrainedDimension:ConstrainedDimension;
		
		switch(parsed.unit)
		{
			case "%":
				constrainedDimension = ConstrainedDimension.percent(Std.parseInt(parsed.value));
				
			default:
				constrainedDimension = ConstrainedDimension.length(string2Length(parsed));
		}
		
		return  constrainedDimension;
	}
	
	static public function displayEnum(string:String):Display
	{
		var parsed:String = trim(string);
		
		var display:Display;
		
		switch(parsed)
		{
			case "inline":
				display = Display.cssInline;
				
			case "block":
				display = Display.block;
				
			case "inline-block":
				display = Display.inlineBlock;
				
			case "none":
				display = Display.none;
				
			default:
				//TODO : throw exception ?
				display = null;
		}
		
		return  display;
	}
	
	static public function overflowEnum(string:String):Overflow
	{
		var parsed:String = trim(string);
		
		var overflow:Overflow;
		
		switch(parsed)
		{
			case "visible":
				overflow = Overflow.visible;
				
			case "scroll":
				overflow = Overflow.scroll;
				
			case "auto":
				overflow = Overflow.cssAuto;
				
			case "hidden":
				overflow = Overflow.hidden;
				
			default:
				//TODO : throw exception ?
				overflow = null;
		}
		
		return  overflow;
	}
	
	static public function verticalAlignEnum(string:String):VerticalAlign
	{
		string = trim(string);
		
		var verticalAlign:VerticalAlign;
		
		switch(string)
		{
			case "baseline":
				verticalAlign = VerticalAlign.baseline;
				
			case "bottom":
				verticalAlign = VerticalAlign.bottom;
				
			case "super":
				verticalAlign = VerticalAlign.cssSuper;
				
			case "middle":
				verticalAlign = VerticalAlign.middle;
				
			case "top":
				verticalAlign = VerticalAlign.top;
				
			case "textBottom":
				verticalAlign = VerticalAlign.textBottom;	
				
			case "textTop":
				verticalAlign = VerticalAlign.textTop;	
				
			case "sub":
				verticalAlign = VerticalAlign.sub;		
				
			default:
				//TODO : throw exception ?
				verticalAlign = null;
		}
		
		if (verticalAlign == null)
		{
			var parsed:VUnit = string2VUnit(string);
			
			switch (parsed.unit)
			{
				case "%":
					verticalAlign = VerticalAlign.percent(Std.parseInt(parsed.value));
					
				default:
					verticalAlign = VerticalAlign.length(string2Length(parsed));
			}
		}
		
		return  verticalAlign;
	}
	
	static public function clearEnum(string:String):Clear
	{
		var parsed:String = trim(string);
		
		var clear:Clear;
		
		switch(parsed)
		{
			case "both":
				clear = Clear.both;
				
			case "left":
				clear = Clear.left;
				
			case "right":
				clear = Clear.right;
				
			case "none":
				clear = Clear.none;
				
			default:
				//TODO : throw exception ?
				clear = null;
		}
		
		return  clear;
	}
	
	static public function positionEnum(string:String):Position
	{
		var parsed:String = trim(string);
		
		var position:Position;
		
		switch(parsed)
		{
			case "static":
				position = Position.cssStatic;
				
			case "absolute":
				position = Position.absolute;
				
			case "relative":
				position = Position.relative;
				
			case "fixed":
				position = Position.fixed;
				
			default:
				//TODO : throw exception ?
				position = null;
		}
		
		return  position;
	}
	
	static public function whiteSpaceEnum(string:String):WhiteSpace
	{
		var parsed:String = trim(string);
		
		var whiteSpace:WhiteSpace;
		
		switch(parsed)
		{
			case "normal":
				whiteSpace = WhiteSpace.normal;
				
			case "nowrap":
				whiteSpace = WhiteSpace.nowrap;
				
			case "pre":
				whiteSpace = WhiteSpace.pre;
				
			case "preLine":
				whiteSpace = WhiteSpace.preLine;
				
			case "preWrap":
				whiteSpace = WhiteSpace.preWrap;	
				
			default:
				//TODO : throw exception ?
				whiteSpace = null;
		}
		
		return  whiteSpace;
	}
	
	static public function textAlignEnum(string:String):TextAlign
	{
		var parsed:String = trim(string);
		
		var textAlign:TextAlign;
		
		switch(parsed)
		{
			case "left":
				textAlign = TextAlign.left;
				
			case "right":
				textAlign = TextAlign.right;
				
			case "center":
				textAlign = TextAlign.center;
				
			case "justify":
				textAlign = TextAlign.justify;
				
			default:
				//TODO : throw exception ?
				textAlign = null;
		}
		
		return  textAlign;
	}
	
	static public function fontWeightEnum(string:String):FontWeight
	{
		var parsed:String = trim(string);
		
		var fontWeight:FontWeight;
		
		switch(parsed)
		{
			case "bold":
				fontWeight = FontWeight.bold;
				
			case "bolder":
				fontWeight = FontWeight.bolder;
				
			case "normal":
				fontWeight = FontWeight.normal;
				
			case "lighter":
				fontWeight = FontWeight.lighter;
				
			case "100":
				fontWeight = FontWeight.css100;
				
			case "200":
				fontWeight = FontWeight.css200;	
				
			case "300":
				fontWeight = FontWeight.css300;
				
			case "400":
				fontWeight = FontWeight.css400;	
				
			case "500":
				fontWeight = FontWeight.css500;
				
			case "600":
				fontWeight = FontWeight.css600;	
				
			case "700":
				fontWeight = FontWeight.css700;
				
			case "800":
				fontWeight = FontWeight.css800;	
				
			case "900":
				fontWeight = FontWeight.css900;		
				
			default:
				//TODO : throw exception ?
				fontWeight = null;
		}
		
		return  fontWeight;
	}
	
	static public function fontStyleEnum(string:String):FontStyle
	{
		var parsed:String = trim(string);
		
		var fontStyle:FontStyle;
		
		switch(parsed)
		{
			case "italic":
				fontStyle = FontStyle.italic;
				
			case "normal":
				fontStyle = FontStyle.normal;
				
			default:
				//TODO : throw exception ?
				fontStyle = null;
		}
		
		return  fontStyle;
	}
	
	static public function fontVariantEnum(string:String):FontVariant
	{
		var parsed:String = trim(string);
		
		var fontVariant:FontVariant;
		
		switch(parsed)
		{
			case "normal":
				fontVariant = FontVariant.normal;
				
			case "small-caps":
				fontVariant = FontVariant.smallCaps;
				
			default:
				//TODO : throw exception ?
				fontVariant = null;
		}
		
		return  fontVariant;
	}
	
	static public function textTransformEnum(string:String):TextTransform
	{
		var parsed:String = trim(string);
		
		var textTransform:TextTransform;
		
		switch(parsed)
		{
			case "capitalize":
				textTransform = TextTransform.capitalize;
				
			case "lowercase":
				textTransform = TextTransform.lowercase;
				
			case "uppercase":
				textTransform = TextTransform.uppercase;
				
			case "none":
				textTransform = TextTransform.none;
				
			default:
				//TODO : throw exception ?
				textTransform = null;
		}
		
		return  textTransform;
	}
	
	
	static public function visibilityEnum(string:String):Visibility
	{
		var parsed:String = trim(string);
		
		var visibility:Visibility;
		
		switch(parsed)
		{
			case "hidden":
				visibility = Visibility.hidden;
				
			case "visible":
				visibility = Visibility.visible;
				
			default:
				//TODO : throw exception ?
				visibility = null;
		}
		
		return  visibility;
	}
	
	static public function cursorEnum(string:String):Cursor
	{
		var parsed:String = trim(string);
		
		var cursor:Cursor;
		
		switch(parsed)
		{
			case "auto":
				cursor = Cursor.cssAuto;
				
			case "crosshair":
				cursor = Cursor.crosshair;
				
			case "pointer":
				cursor = Cursor.pointer;	
				
			case "default":
				cursor = Cursor.cssDefault;		
				
			default:
				//TODO : throw exception ?
				cursor = null;
		}
		
		return  cursor;
	}
	
	static public function wordSpacingEnum(string:String):WordSpacing
	{
		if (string == "normal")
			return WordSpacing.normal;
			
		var parsed:VUnit = string2VUnit(string);
		
		var wordSpacing:WordSpacing;
		
		switch(parsed.unit)
		{
			case "%":
				wordSpacing = null;
				
			default:
				wordSpacing = WordSpacing.length(string2Length(parsed));
		}
		
		return  wordSpacing;
	}
	
	/**
	 * convert a string into a typed enum
	 * TODO: ImageValue.imageList and ImageValue.gradient
	 * @example converts 'url("./abc.gif"),url  (./def.jpg)' into [BackgroundImage.image(ImageValue.url("./abc.gif")),BackgroundImage.image(ImageValue.url("./def.jpg"))] 
	 */
	static public function backgroundImageEnum(string:String):Array<BackgroundImage>
	{
		if (string == "none") 
			return [BackgroundImage.none];

		var array:Array<String> = string2VList(string, ",");
		var arrayBgImg:Array<BackgroundImage> = [];
		for (val in array)
		{
			if (val == "none") 
				arrayBgImg.push(BackgroundImage.none);
			else
				arrayBgImg.push(BackgroundImage.image(ImageValue.url(string2URLData(val))));
		}
		return arrayBgImg;
	}
	
	//TODO
	static public function backgroundRepeatEnum(string:String):Array<BackgroundRepeat>
	{
		return [];
	}
	
	//TODO
	static public function backgroundOriginEnum(string:String):Array<BackgroundOrigin>
	{
		return [];
	}
	
	//TODO
	static public function backgroundSizeEnum(string:String):Array<BackgroundSize>
	{
		return [];
	}
	
	//TODO
	static public function backgroundPositionEnum(string:String):Array<BackgroundPosition>
	{
		return [];
	}
	
	//TODO
	static public function backgroundClipEnum(string:String):Array<BackgroundClip>
	{
		return [];
	}
	
	/**
	 * convert a string into a typed enum
	 * @example	converts "Times New Roman",Georgia,Serif into ["Times New Roman","Georgia","Serif"]
	 */
	static public function fontFamilyEnum(string:String):Array<String>
	{
		return string2Array(string);
	}
	
	static public function letterSpacingEnum(string:String):LetterSpacing
	{
		if (string == "normal")
			return LetterSpacing.normal;
			
		var parsed:VUnit = string2VUnit(string);
		
		var letterSpacing:LetterSpacing;
		
		switch(parsed.unit)
		{
			case "%":
				letterSpacing = null;
				
			default:
				letterSpacing = LetterSpacing.length(string2Length(parsed));
		}
		
		return  letterSpacing;
	}
	
	//TODO : parse number value for lineHeight
	static public function lineHeightEnum(string:String):LineHeight
	{
		if (string == "normal")
			return LineHeight.normal;
		
			
		var parsed:VUnit = string2VUnit(string);
		
		var lineHeight:LineHeight;
		
		switch(parsed.unit)
		{
			case "%":
				lineHeight = LineHeight.percentage(Std.parseInt(parsed.value));
				
			default:
				lineHeight = LineHeight.length(string2Length(parsed));
		}
		
		return  lineHeight;
	}
	
	static public function textIndentEnum(string:String):TextIndent
	{
		var parsed:VUnit = string2VUnit(string);
		
		var textIndent:TextIndent;
		
		switch(parsed.unit)
		{
			case "%":
				textIndent = TextIndent.percentage(Std.parseInt(parsed.value));
				
			default:
				textIndent = TextIndent.length(string2Length(parsed));
		}
		
		return  textIndent;
	}
	
	
	static public function cssFloatEnum(string:String):CSSFloat
	{
		var parsed:String = trim(string);
		
		var cssFloat:CSSFloat;
		
		switch(parsed)
		{
			case "left":
				cssFloat = CSSFloat.left;
				
			case "right":
				cssFloat = CSSFloat.right;
				
			case "none":
				cssFloat = CSSFloat.none;
				
			default:
				//TODO : throw exception ?
				cssFloat = null;
		}
		
		return  cssFloat;
	}
	
	/**
	 * convert a string into a typed Color enum
	 * @example CSSParser.colorEnum("yellow") returns Color.yellow
	 */
	static public function colorEnum(string:String):CSSColor{
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
			case "transparent": CSSColor.transparent;
			case "aqua": CSSColor.keyword(aqua);
			case "black": CSSColor.keyword(black);
			case "blue": CSSColor.keyword(blue);
			case "fuchsia": CSSColor.keyword(fuchsia);
			case "gray": CSSColor.keyword(gray);
			case "green": CSSColor.keyword(green);
			case "lime": CSSColor.keyword(lime);
			case "maroon": CSSColor.keyword(maroon);
			case "navy": CSSColor.keyword(navy);
			case "olive": CSSColor.keyword(olive);
			case "orange": CSSColor.keyword(orange);
			case "purple": CSSColor.keyword(purple);
			case "red": CSSColor.keyword(red);
			case "silver": CSSColor.keyword(silver);
			case "teal": CSSColor.keyword(teal);
			case "white": CSSColor.keyword(white);
			case "yellow": CSSColor.keyword(yellow);	
			default:
				throw "unknown color \""+string+"\"";
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS FOR STRING TO ENUM CONVERSION (lexa)
	//////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * function used internally to convert an rgba value to a 4 digit object of type VCol
	 * 
	 */
	static private function string2RGBA(string:String):VCol
	{
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
	static private function string2RGB(string:String):VCol
	{
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
	static private function trim(string:String):String
	{
		return StringTools.ltrim(StringTools.rtrim(string));
	} 
	/**
	 * function used internally to split a string to a value/unit strings pair   
	 */
	static private function string2VUnit(string:String):VUnit
	{
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
	static private function string2Length(parsed):Length
	{
		return switch (parsed.unit)
		{
			case "in":
				Length.cssIn(Std.parseInt(parsed.value));	
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
			case "":
				// special case of "0" without unit
				var v:Int = Std.parseInt(parsed.value);
				if (v == 0)
					Length.px(v);
				else 
					throw("Bad unit \"" + parsed.unit+"\"");
			default:
				throw("Bad unit \"" + parsed.unit+"\"");
		}
	}
	/**
	 * function used internally to convert a value/unit strings pair to an enum  
	 * @example	Assert.equals("http://test.com", UnitManager.string2URLData('url("http://test.com")'));
	 */
	static private function string2URLData(string:String):URLData
	{
		// trim
		string = trim(string);
		// remove "url(" and ")" + trim
		string = trim(string.substr(4, string.length - 5));
		// remove the quotes if there are some
		if (StringTools.startsWith(string, "\""))
			string = string.substr(1);
		if (StringTools.endsWith(string, "\""))
			string = string.substr(0, string.length - 1);
		return cast(string);
	}
	/**
	 * function used internally to convert a value/unit strings pair to an enum  
	 * @example	Assert.same(["1px","2pt", "3px", "4%"], UnitManager.string2VList("1px 2pt 3px 4%"));
	 * @example	"Times New Roman",Georgia,Serif into ["Times New Roman","Georgia","Serif"]
	 */
	static private function string2VList(string:String, sep:String = " "):Array<String>
	{
		if (sep == " ") 
		{
			// if the sep char is a blank space, remove only the double spaces
			string = ~/[ ]{2,}/g.replace(string, " ");
		}
		else
		{
			// else, remove all spaces
			string = StringTools.replace(string, " ", "");
		}
		// trim
		string = trim(string);
		// split
		var array:Array<String> = string.split(sep);
		return array;
	}
	/**
	 * @example	converts "Times New Roman", Georgia,Serif into ["Times New Roman","Georgia","Serif"]
	 */
	static private function string2Array(string:String):Array<String>
	{
		// build an array of values
		var r : EReg = ~/[ "]*[,"][ "]*/g;
		// split where elements are separated by , or ", or ," or ","
		var res = r.split(string);
		// remove the 1st element which may be empty because of a "
		if (res[0] == "") res.shift();
		return res;
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
				
			case cssIn(value):
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
	
	//////////////////////////////////////////////////////////////////////
	// METHODS CONVERTING A TYPED STYLE INTO A CSS STRING
	//////////////////////////////////////////////////////////////////////
	
	/////////////////////////////////
	// DISPLAY STYLES
	////////////////////////////////
	
	/**
	 * CSS : display
	 */
	public static function getCSSDisplay(value:Display):String
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
	public static function getCSSFloatAsString(value:CSSFloat):String
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
	public static function getCSSClear(value:Clear):String
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
	public static function getCSSPosition(value:Position):String
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
	public static function getCSSOverflow(value:Overflow):String
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
	public static function getCSSOpacity(value:Opacity):String
	{
		var cssOpacityValue:String;
		cssOpacityValue = Std.string(value);
		
		return cssOpacityValue;
	}
	
	/**
	 * CSS : visibility
	 */
	public static function getCSSVisibility(value:Visibility):String
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
	public static function getCSSTransform(value:Transform):String
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
	private static function getCSSTransformFunction(transformFunction:TransformFunction):String
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
	private static function getCSSTranslation(translation:Translation):String
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
	public static function getCSSTransformOrigin(value:TransformOrigin):String
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
	public static function getCSSMargin(value:Margin):String
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
	public static function getCSSPadding(value:Padding):String
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
	public static function getCSSDimension(value:Dimension):String
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
	public static function getCSSPositionOffset(value:PositionOffset):String
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
	public static function getCSSConstrainedDimension(value:ConstrainedDimension):String
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
	public static function getCSSVerticalAlign(value:VerticalAlign):String
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
				
			case cssSuper:
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
	public static function getCSSLineHeight(value:LineHeight):String
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
	public static function getCSSFontSize(value:FontSize):String
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
	public static function getCSSFontWeight(value:FontWeight):String
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
	public static function getCSSFontStyle(value:FontStyle):String
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
	public static function getCSSFontVariant(value:FontVariant):String
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
	public static function getCSSFontFamily(value:Array<String>):String
	{
		var cssFontFamilyValue:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String = value[i];
			
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
	public static function getCSSTextAlign(value:TextAlign):String
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
	public static function getCSSWhiteSpace(value:WhiteSpace):String
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
	public static function getCSSTextTransform(value:TextTransform):String
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
	public static function getCSSTextIndent(value:TextIndent):String
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
	public static function getCSSLetterSpacing(value:LetterSpacing):String
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
	public static function getCSSWordSpacing(value:WordSpacing):String
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
	public static function getCSSBackgroundColor(value:BackgroundColor):String
	{
		var cssBackgroundColor:String;
		cssBackgroundColor = getCSSColor(value);
		
		return cssBackgroundColor;
	}
	
	/**
	 * CSS : background-origin
	 */
	public static function getCSSBackgroundOrigin(value:Array<BackgroundOrigin>):String
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
	public static function getCSSBackgroundClip(value:Array<BackgroundClip>):String
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
	public static function getCSSBackgroundImage(value:Array<BackgroundImage>):String
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
	public static function getCSSBackgroundSize(value:Array<BackgroundSize>):String
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
	
	private static function getCSSBackgroundSizeDimensions(value:BackgroundSizeDimensions):String
	{
		var cssBackgroundSizeDimensions:String = getCSSBackgroundSizeDimension(value.x) + " " + getCSSBackgroundSizeDimension(value.y);
		return cssBackgroundSizeDimensions;
	}
	
	private static function getCSSBackgroundSizeDimension(value:BackgroundSizeDimension):String
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
	public static function getCSSBackgroundPosition(value:Array<BackgroundPosition>):String
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
	
	private static function getCSSBackgroundPositionX(value:BackgroundPositionX):String
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
	
	private static function getCSSBackgroundPositionY(value:BackgroundPositionY):String
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
	public static function getCSSBackgroundRepeat(value:Array<BackgroundRepeat>):String
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
	
	private static function getCSSBackgroundRepeatValue(value:BackgroundRepeatValue):String
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
	// USER INTERFACE STYLES
	////////////////////////////////
	
	/**
	 * CSS : cursor
	 */
	public static function getCSSCursor(value:Cursor):String
	{
		var cssCursorValue:String;
		
		switch (value)
		{
			case Cursor.cssAuto:
				cssCursorValue = "auto";
				
			case Cursor.crosshair:
				cssCursorValue = "crosshair";
				
			case Cursor.cssDefault:
				cssCursorValue = "default";
				
			case Cursor.pointer:
				cssCursorValue = "pointer";
		}
		
		return cssCursorValue;
	}
	
	/////////////////////////////////
	// UNIT CONVERSION
	// Convert abstract styles units
	// to CSS units
	////////////////////////////////
	
	private static function getCSSImageValue(value:ImageValue):String
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
	
	private static function getCSSImageList(value:ImageDeclarationData):String
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
	
	private static function getCSSGradientValue(value:GradientValue):String
	{
		var cssGradientValue:String;
		
		switch (value)
		{
			case GradientValue.linear(value):
				cssGradientValue = "linear-gradient(" + getCSSLinearGradientValue(value) + ")";
		}
		
		return cssGradientValue;
	}
	
	private static function getCSSLinearGradientValue(value:LinearGradientData):String 
	{
		var cssLinearGradientValue:String = getCSSGradientAngle(value.angle) + "," + getCSSColorStopsValue(value.colorStops);
		return cssLinearGradientValue;
	}
	
	private static function getCSSColorStopsValue(value:Array<GradientColorStopData>):String
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
	
	private static function getCSSColorStopValue(value:GradientStopValue):String
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
	
	private static function getCSSGradientAngle(value:GradientAngle):String
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
	
	private static function getCSSSideValue(value:GradientSideValue):String
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
	
	private static function getCSSCornerValue(value:GradientCornerValue):String
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
	
	public static function getCSSColor(value:Color):String
	{
		var cssColor:String;
		
		switch (value)
		{
			case hex(value):
				cssColor = value;
				
			case rgb(red, green, blue):
				cssColor = "rgb(" + red + "," + green + "," + blue + ")";
				
			case rgba(red, green, blue, alpha):
				cssColor = "rgba(" + red + "," + green + "," + blue + "," + alpha + ")";
				
			case keyword(value):
				cssColor = getColorFromKeyword(value);
				
			case transparent:
				cssColor = "transparent";
		}
		
		return cssColor;
	}
	
	private static function getCSSLength(lengthValue:Length):String
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
				
			case cssIn(inchesValue):
				cssLength = Std.string(inchesValue) + "in";
				
			case em(emValue	):
				cssLength = Std.string(emValue) + "em";
				
			case ex(exValue):
				cssLength = Std.string(exValue) + "ex";
		}
	
		return cssLength;	
	}
	
	private static function getCSSPercentValue(value:Int):String
	{
		return Std.string(value) + "%";
	}
	
	private static function getCSSAngle(value:Angle):String
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
	
	private static function getColorFromKeyword(value:ColorKeyword):String
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
	
}