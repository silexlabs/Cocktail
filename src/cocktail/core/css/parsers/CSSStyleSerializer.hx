/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.css.parsers;

import cocktail.core.css.CSSData;

/**
 * This class serialize a CSS property value 
 * into a CSS string
 * 
 * @author Yannick DOMINGUEZ
 */
class CSSStyleSerializer 
{

	/**
	 * class constructor. Private, this is
	 * a static class
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC SERIALIZATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Entry point. Serialize a CSS property
	 */
	public static function serialize(property:CSSPropertyValue):String
	{
		switch(property)
		{
			case KEYWORD(value):
				return serializeKeyword(value);
				
			case IDENTIFIER(value):
				return value;
			
			//TODO 2 : add quotes ?
			case STRING(value):
				return value;
				
			//TODO 2 : should be the absolute escaped url	
			case URL(value):
				return "url(" + value + ")";
				
			case INHERIT:
				return "inherit";
				
			case INITIAL:
				return "initial";
				
			case TIME(value):
				return serializeTime(value);
				
			case PERCENTAGE(value):
				return value + "%";
				
			case ANGLE(value):
				return serializeAngle(value);
				
			case INTEGER(value):
				return Std.string(value);
				
			case NUMBER(value):
				return Std.string(value);
				
			case ABSOLUTE_LENGTH(value):
				return Std.string(value);
				
			case STEPS(intervalNumber, intervalChange):
				return "steps(" + Std.string(intervalNumber) + "," + serializeKeyword(intervalChange) + ")";
				
			case CUBIC_BEZIER(x1, y1, x2, y2):
				return "cubic-bezier(" + Std.string(x1) + "," + Std.string(y1) + "," + Std.string(x2) + "," + Std.string(y2) + ")";
				
			case FREQUENCY(value):
				return serializeFrequency(value);
				
			case LENGTH(value):
				return serializeLength(value);
				
			case RESOLUTION(value):
				return serializeResolution(value);
				
			case COLOR(value):
				return serializeColor(value);
				
			case TRANSFORM_FUNCTION(value):
				return serializeTransformFunction(value);
				
			case GROUP(value):
				return serializeGroup(value);
				
			case CSS_LIST(value):
				return serializeList(value);
				
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE SERIALIZATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private static function serializeList(list:Array<CSSPropertyValue>):String
	{
		var serializedList:String = "";
		
		for (i in 0...list.length)
		{
			serializedList += serialize(list[i]);
			
			if (i < list.length)
			{
				serializedList += ",";
			}
		}
		
		return serializedList;
	}
	
	private static function serializeGroup(group:Array<CSSPropertyValue>):String
	{
		var serializedGroup:String = "";
		
		for (i in 0...group.length)
		{
			serializedGroup += serialize(group[i]);
			
			if (i < group.length)
			{
				serializedGroup += " ";
			}
		}
		
		return serializedGroup;
	}
	
	private static function serializeTransformFunction(transformFunction:CSSTransformFunctionValue):String
	{
		switch(transformFunction)
		{
			case MATRIX(data):
				return "matrix(" + Std.string(data.a) + "," + Std.string(data.b) + "," + Std.string(data.c) + "," + Std.string(data.d) + "," + Std.string(data.e) + "," + Std.string(data.f) + ")";
				
			case TRANSLATE(tx, ty):
				return "translate(" + serializeTranslation(tx) + "," + serializeTranslation(ty) + ")";
				
			case TRANSLATE_X(tx):
				return "translateX(" + serializeTranslation(tx) + ")";
				
			case TRANSLATE_Y(ty):
				return "translateY(" + serializeTranslation(ty) + ")";	
				
			case SKEW(angleX, angleY):
				return "skew(" + serializeAngle(angleX) + "," + serializeAngle(angleY) + ")";
				
			case SKEW_X(angleX):
				return "skewX(" + serializeAngle(angleX) + ")";	
				
			case SKEW_Y(angleY):
				return "skewY(" + serializeAngle(angleY) + ")";		
				
			case ROTATE(angle):
				return "rotate(" + serializeAngle(angle) + ")";
				
			case SCALE(sx, sy):
				return "scale(" + Std.string(sx) + "," + Std.string(sy) + ")";
				
			case SCALE_X(sx):
				return "scaleX(" + Std.string(sx) + ")";
				
			case SCALE_Y(sy):
				return "scaleY(" + Std.string(sy) + ")";	
		}
	}
	
	private static function serializeTranslation(translation:CSSTranslationValue):String
	{
		switch(translation)
		{
			case LENGTH(value):
				return serializeLength(value);
				
			case PERCENTAGE(value):
				return value + "%";
				
			case ABSOLUTE_LENGTH(value):
				return Std.string(value);
		}
	}
	
	private static function serializeColor(color:CSSColorValue):String
	{
		switch(color)
		{
			case KEYWORD(value):
				return serializeColorKeyword(value);
				
			case RGB(red, green, blue):
				return "rgb(" + Std.string(red) + "," + Std.string(green) + "," + Std.string(blue) + ")";
				
			case RGB_PERCENTAGE(red, green, blue):
				return "rgb(" + Std.string(red) + "%," + Std.string(green) + "%," + Std.string(blue) + "%)";	
				
			case RGBA(red, green, blue, alpha):	
				return "rgba(" + Std.string(red) + "," + Std.string(green) + "," + Std.string(blue) + "," + Std.string(alpha) + ")";
				
			case RGBA_PERCENTAGE(red, green, blue, alpha):	
				return "rgba(" + Std.string(red) + "%," + Std.string(green) + "%," + Std.string(blue) + "%," + Std.string(alpha) + "%)";	
				
			case TRANSPARENT:
				return "transparent";
			
			case HSL(hue, saturation, lightness):
				return "hsl(" + Std.string(hue) + "," + Std.string(saturation) + "," + Std.string(lightness) + ")";
				
			case HSLA(hue, saturation, lightness, alpha):
				return "hsl(" + Std.string(hue) + "," + Std.string(saturation) + "," + Std.string(lightness) +"," + Std.string(alpha) + ")";	

			case HEX(value):
				return value;
				
			case CURRENT_COLOR:
				return "currentColor";
				
		}
	}
	
	private static function serializeColorKeyword(keyword:CSSColorKeyword):String
	{
		switch(keyword)
		{
			case AQUA:
				return 'aqua';
				
			case BLUE:
				return 'blue';
				
			case BLACK:
				return 'black';	
				
			case SILVER:
				return 'silver';	
				
			case GRAY:
				return 'gray';
				
			case WHITE:
				return 'white';	
				
			case MAROON:
				return 'maroon';	
				
			case RED:
				return 'red';
				
			case PURPLE:
				return 'purple';
				
			case FUSHIA:
				return 'fuchsia';		
				
			case GREEN:
				return 'green';
				
			case LIME:
				return 'lime';
				
			case OLIVE:
				return 'olive';		
				
			case YELLOW:
				return 'yellow';
				
			case NAVY:
				return 'navy';
				
			case ORANGE:
				return 'orange';
				
			case TEAL:
				return 'teal';
		}
	}
	
	private static function serializeResolution(resolution:CSSResolutionValue):String
	{
		switch(resolution)
		{
			case DPCM(value):
				return value + "dcpm";
				
			case DPI(value):
				return value + "dpi";
				
			case DPPX(value):
				return value + "dppx";
		}
	}
	
	private static function serializeLength(length:CSSLengthValue):String
	{
		switch(length)
		{
			case PX(value):
				return value + "px";
				
			case EM(value):
				return value + "em";
				
			case IN(value):
				return value + "in";
				
			case PC(value):
				return value + "pc";
				
			case EX(value):
				return value + "ex";
				
			case PT(value):
				return value + "pt";
				
			case MM(value):
				return value + "mm";
				
			case CM(value):
				return value + "cm";
		}
	}
	
	private static function serializeFrequency(frequency:CSSFrequencyValue):String
	{
		switch(frequency)
		{
			case HERTZ(value):
				return value + "hz";
				
			case KILO_HERTZ(value):
				return value + "khz";
		}
	}
	
	private static function serializeAngle(angle:CSSAngleValue):String
	{
		switch(angle)
		{
			case DEG(value):
				return value + "deg";
				
			case RAD(value):
				return value + "rad";
				
			case TURN(value):
				return value + "turn";
				
			case GRAD(value):
				return value +  "grad";
		}
	}
	
	private static function serializeTime(time:CSSTimeValue):String
	{
		switch(time)
		{
			case SECONDS(value):
				return value + "s";
				
			case MILLISECONDS(value):
				return value + "ms"; 
		}
	}
	
	private static function serializeKeyword(keyword:CSSKeywordValue):String
	{
		switch(keyword)
		{
			case NORMAL:
				return 'normal';
				
			case BOLD:
				return 'bold';
				
			case BOLDER:
				return 'bolder';
				
			case LIGHTER:
				return 'lighter';
				
			case OBLIQUE:
				return 'oblique';
				
			case ITALIC:
				return 'italic';
				
			case SMALL_CAPS:
				return 'small-caps';
				
			case PRE:
				return 'pre';
				
			case NO_WRAP:
				return 'no-wrap';
				
			case PRE_WRAP:
				return 'pre-wrap';
				
			case PRE_LINE:
				return 'pre-line';
				
			case LEFT:
				return 'left';
				
			case RIGHT:
				return 'right';
				
			case CENTER:
				return 'center';
				
			case JUSTIFY:
				return 'justify';
				
			case CAPITALIZE:
				return 'capitalize';
				
			case UPPERCASE:
				return 'uppercase';
				
			case LOWERCASE:
				return 'lowercase';
				
			case NONE:
				return 'none';
				
			case BASELINE:
				return 'baseline';
				
			case SUB:
				return 'sub';
				
			case SUPER:
				return 'super';
			
			case TOP:
				return 'top';
				
			case TEXT_TOP:
				return 'text-top';
				
			case MIDDLE:
				return 'middle';
				
			case BOTTOM:
				return 'bottom';
				
			case TEXT_BOTTOM:
				return 'text-bottom';
				
			case AUTO:
				return 'auto';
				
			case BLOCK:
				return 'block';
				
			case INLINE_BLOCK:
				return 'inline-block';
				
			case INLINE:
				return 'inline';
				
			case BOTH:
				return 'both';
				
			case STATIC:
				return 'static';
				
			case RELATIVE:
				return 'relative';
				
			case ABSOLUTE:
				return 'absolute';
				
			case FIXED:
				return 'fixed';
				
			case VISIBLE:
				return 'visible';
				
			case HIDDEN:
				return 'hidden';
				
			case SCROLL:
				return 'scroll';
				
			case BORDER_BOX:
				return 'border-box';
				
			case PADDING_BOX:
				return 'padding-box';
				
			case CONTENT_BOX:
				return 'content-box';
				
			case CONTAIN:
				return 'contain';
				
			case COVER:
				return 'cover';
				
			case CROSSHAIR:
				return 'crosshair';
				
			case DEFAULT:
				return 'default';
				
			case POINTER:
				return 'pointer';
				
			case TEXT:
				return 'text';
				
			case ALL:
				return 'all';
				
			case EASE:
				return 'ease';
				
			case LINEAR:
				return 'linear';
				
			case EASE_IN:
				return 'ease-in';	
				
			case EASE_OUT:
				return 'ease-out';
				
			case EASE_IN_OUT:
				return 'ease-in-out';
				
			case STEP_START:
				return 'step-start';
				
			case STEP_END:
				return 'step-end';
				
			case START:
				return 'start';
				
			case END:
				return 'end';
				
			case XX_SMALL:
				return "xx-small";
				
			case X_SMALL:
				return "x-small";	
				
			case SMALL:
				return "small";	
				
			case XX_LARGE:
				return "xx-large";	
				
			case X_LARGE:
				return "x-large";	
				
			case LARGE:
				return "large";	
				
			case MEDIUM:
				return "medium";
				
			case LARGER:
				return "larger";
				
			case SMALLER:
				return "smaller";
				
			case SPACE:
				return "space";
				
			case ROUND:
				return "round";
				
			case REPEAT_Y:
				return "repeat-y";
				
			case REPEAT_X:
				return "repeat-x";	
				
			case NO_REPEAT:
				return "no-repeat";
				
			case REPEAT:
				return "repeat";
		}
	}
	
}