/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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
			
			case STRING(value):
				return '"'+value+'"';
				
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
				
			case FONT_SIZE_LINE_HEIGHT_GROUP(fontSize, lineHeight):
				return serialize(fontSize) + "/" + serialize(lineHeight);
				
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
			case MATRIX(a, b, c, d, e, f):
				return "matrix(" + Std.string(a) + "," + Std.string(b) + "," + Std.string(c) + "," + Std.string(d) + "," + Std.string(e) + "," + Std.string(f) + ")";
				
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
				return "#" + value;
				
			case CURRENT_COLOR:
				return "currentColor";
				
		}
	}
	
	private static function serializeColorKeyword(keyword:CSSColorKeyword):String
	{
		switch(keyword)
		{
			case ALICE_BLUE:
				return "aliceblue";
				
			case ANTIQUE_WHITE:
				return "antiquewhite";
				
			case AQUA:
				return 'aqua';
				
			case AQUAMARINE:
				return "aquamarine";	
				
			case AZURE:
				return "azure";	
				
			case BEIGE:
				return "beige";	
				
			case BISQUE:
				return "bisque";	
				
			case BLUE:
				return 'blue';
				
			case BLACK:
				return 'black';	
				
			case BLANCHE_DALMOND:
				return "blanchedalmond";	
			
			case BLUE_VIOLET:
				return "blueviolet";
				
			case BROWN:
				return "brown";
				
			case BURLY_WOOD:
				return "burlywood";	
				
			case CADET_BLUE:
				return "cadetblue";	
				
			case CHARTREUSE:
				return "chartreuse";	
				
			case CHOCOLATE:
				return "chocolate";	
				
			case CORAL:
				return "coral";
				
			case CORNFLOWER_BLUE:
				return "cornflowerblue";	
				
			case CORNSILK:
				return "cornsilk";	
				
			case CRIMSON:
				return "crimson";	
				
			case CYAN:
				return "cyan";	
				
			case DARK_BLUE:
				return "darkblue";	
				
			case DARK_CYAN:
				return "darkcyan";	
				
			case DARK_GOLDEN_ROD:
				return "darkgoldenrod";	
				
			case DARK_GRAY:
				return "darkgray";	
				
			case DARK_GREEN:
				return "darkgreen";	
				
			case DARK_GREY:
				return "darkgrey";
			
			case DARK_KHAKI:
				return "darkkhaki";	
				
			case DARK_MAGENTA:
				return "darkmagenta";
				
			case DARK_OLIVE_GREEN:
				return "darkolivegreen";	
				
			case DARK_ORANGE:
				return "darkorange";	
				
			case DARK_ORCHID:
				return "darkorchid";	
				
			case DARK_RED:
				return "darkred";
				
			case DARK_SALMON:
				return "darksalmon";	
				
			case DARK_SEA_GREEN:
				return "darkseagreen";	
				
			case DARK_SLATE_BLUE:
				return "darkslateblue";	
				
			case DARK_SLATE_GRAY:
				return "darkslategray";	
				
			case DARK_SLATE_GREY:
				return "darkslategrey";	
				
			case DARK_TURQUOISE:
				return "darkturquoise";	
				
			case DARK_VIOLET:
				return "darkviolet";	
				
			case DEEP_PINK:
				return "deeppink";
				
			case DEEP_SKY_BLUE:
				return "deepskyblue";	
				
			case DIM_GRAY:
				return "dimgray";	
				
			case DIM_GREY:
				return "dimgrey";	
				
			case DODGER_BLUE:
				return "dodgerblue";	
			
			case FIRE_BRICK:
				return "firebrick";	
				
			case FLORAL_WHITE:
				return "floralwhite";	
				
			case FOREST_GREEN:
				return "forestgreen";	
				
			case FUCHSIA:
				return "fuchsia";	
				
			case GAINSBORO:
				return "gainsboro";	
				
			case GHOST_WHITE:
				return "ghostwhite";		
				
			case GOLD:
				return "gold";	
				
			case GOLDEN_ROD:
				return "goldenrod";			
				
			case GRAY:
				return "gray";		
				
			case GREY:
				return "grey";		
				
			case GREEN_YELLOW:
				return "greenyellow";		
				
			case HONEY_DEW:
				return "honeydew";	
				
			case HOT_PINK:
				return "hotpink";		
				
			case INDIGO:
				return "indigo";	
				
			case IVORY:
				return "ivory";	
				
			case INDIAN_RED:
				return "indianred";			
				
			case KHAKI:
				return "khaki";	
				
			case LAVENDER:
				return "lavender";		
				
			case LAVENDER_BLUSH:
				return "lavenderblush";		
				
			case LAWN_GREEN:
				return "lawngreen";
				
			case LEMON_CHIFFON:
				return "lemonchiffon";	
				
			case LIGHT_BLUE:
				return "lightblue";	
				
			case LIGHT_CORAL:
				return "lightcoral";	
				
			case LIGHT_CYAN:
				return "lightcyan";		
				
			case LIGHT_GOLDENROD_YELLOW:
				return "lightgoldenrodyellow";		
				
			case LIGHT_GRAY:
				return "lightgray";		
				
			case LIGHT_GREEN:
				return "lightgreen";	
				
			case LIGHT_GREY:
				return "lightgrey";
				
			case LIGHT_PINK:
				return "lightpink";	
				
			case LIGHT_SALMON:
				return "lightsalmon";		
				
			case LIGHT_SEA_GREEN:
				return "lightseagreen";		
		
			case LIGHT_SKY_BLUE:
				return "lightskyblue";		
				
			case LIGHT_SLATE_GRAY:
				return "lightslategray";		
				
			case LIGHT_SLATE_GREY:
				return "lightslategrey";	
				
			case LIGHT_STEEL_BLUE:
				return "lightsteelblue";	
				
			case LIGHT_YELLOW:
				return "lightyellow";
				
			case LIME:
				return "lime";	
				
			case LIME_GREEN:
				return "limegreen";	
				
			case LINEN:
				return "linen";	
				
			case MAGENTA:
				return "magenta";		
				
			case MAROON:
				return "marron";	
				
			case MEDIUM_AQUAMARINE:
				return "mediumaquamarine";		
				
			case MEDIUM_BLUE:
				return "mediumblue";
				
			case MEDIUM_ORCHID:
				return "mediumorchid";		
				
			case MEDIUM_PURPLE:
				return "mediumpurple";		
				
			case MEDIUM_SEA_GREEN:
				return "mediumseagreen";	
				
			case MEDIUM_SLATE_BLUE:
				return "mediumslateblue";	
				
			case MEDIUM_SPRING_GREEN:
				return "mediumspringgreen";		
				
			case MEDIUM_TURQUOISE:
				return "mediumturquoise";	
				
			case MEDIUM_VIOLET_RED:
				return "mediumvioletred";	
				
			case MIDNIGHT_BLUE:
				return "midnightblue";	
				
			case MINT_CREAM:
				return "mintcream";		
				
			case MISTY_ROSE:
				return "mistyrose";		
				
			case MOCCASIN:
				return "moccasin";	
				
			case NAVAJO_WHITE:
				return "navajowhite";	
							
			case OLD_LACE:
				return "oldlace";		
				
			case OLIVE_DRAB:
				return "olivedrab";		
				
			case ORANGE_RED:
				return "orangered";		
				
			case ORCHID:
				return "orchid";
				
			case PALE_GOLDEN_ROD:
				return "palegoldenrod";		
				
			case PALE_GREEN:
				return "palegreen";	
				
			case PALE_TURQUOISE:
				return "paleturquoise";		
				
			case PALE_VIOLET_RED:
				return "palevioletred";			
				
			case PAPAYA_WHIP:
				return "papayawhip";
				
			case PEACH_PUFF:
				return "peachpuff";		
				
			case PERU:
				return "peru";	
				
			case PINK:
				return "pink";
				
			case PLUM:
				return "plum";	
				
			case POWDER_BLUE:
				return "powderblue";	
				
			case ROSY_BROWN:
				return "rosybrown";		
				
			case ROYAL_BLUE:
				return "royalblue";	
				
			case SADDLE_BROWN:
				return "saddlebrown";	
				
			case SALMON:
				return "salmon";
				
			case SANDY_BROWN:
				return "sandybrown";
				
			case SEA_GREEN:
				return "seagreen";	
				
			case SEA_SHELL:
				return "seashell";
				
			case SIENNA:
				return "sienna";			
				
			case SILVER:
				return 'silver';
				
			case SKY_BLUE:
				return "skyblue";	
		
			case SLATE_BLUE:
				return "slateblue";			
				
			case SLATE_GRAY:
				return "slategray";		
				
			case SLATE_GREY:
				return "slategrey";		
				
			case SNOW:
				return "snow";		
				
			case SPRING_GREEN:
				return "springgreen";		
				
			case STEEL_BLUE:
				return "steelblue";	
				
			case TAN:
				return "tan";		
				
			case THISLE:
				return "thisle";	
				
			case TOMATO:
				return "tomato";	
				
			case TURQUOISE:
				return "turquoise";		
				
			case VIOLET:
				return "violet";			
				
			case WHEAT:
				return "wheat";
				
			case WHITE:
				return 'white';	
				
			case WHITE_SMOKE:
				return "whitesmoke";
				
			case YELLOW_GREEN:
				return "yellowgreen";			
				
			case RED:
				return 'red';
				
			case PURPLE:
				return 'purple';	
				
			case GREEN:
				return 'green';
				
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
				
			case CH(value):
				return value + "ch";	
				
			case REM(value):
				return value + "rem";
				
			case VMAX(value):
				return value + "vmax";
				
			case VMIN(value):
				return value + "vmin";	
				
			case VW(value):
				return value + "vw";	
				
			case VH(value):
				return value + "vh";		
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
				
			case THIN:
				return "thin";
				
			case THICK:
				return "thick";
				
			case DOTTED:
				return "dotted";
				
			case DASHED:
				return "dashed";
				
			case SOLID:
				return "solid";
				
			case DOUBLE:
				return "double";
				
			case GROOVE:
				return "groove";
				
			case RIDGE:
				return "ridge";
				
			case INSET:
				return "inset";
				
			case OUTSET:
				return "outset";
				
			case INVERT:
				return "invert";
				
			case UNDERLINE:
				return "underline";
				
			case OVERLINE:
				return "overline";
				
			case LINE_THROUGH:
				return "line-through";
				
			case BLINK:
				return "blink";
		}
	}
	
}