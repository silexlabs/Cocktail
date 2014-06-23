/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.core.config.Config;
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;	
import cocktail.geom.GeomData;
import cocktail.css.CSSStyleData;

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
	 * @param	relativeLengthReference holds all the data necessary to
	 * compute a relative length
	 * @return returns the computed value as pixel with rounded
	 * values
	 */ 
	public static function getPixelFromLength(length:CSSLengthValue, relativeLengthReference:RelativeLengthReferenceData):Float
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
				lengthValue = relativeLengthReference.em * value;
				
			case EX(value):
				lengthValue = relativeLengthReference.ex * value;
				
			case CH(value):
				lengthValue = relativeLengthReference.ch * value;
				
			case REM(value):
				lengthValue = relativeLengthReference.rem * value;
				
			case VMAX(value):
				if (relativeLengthReference.viewportHeight > relativeLengthReference.viewportWidth)
				{
					lengthValue = (relativeLengthReference.viewportHeight * 0.01) * value;	
				}
				else
				{
					lengthValue = (relativeLengthReference.viewportWidth * 0.01) * value;
				}
				
			case VMIN(value):	
				if (relativeLengthReference.viewportHeight < relativeLengthReference.viewportWidth)
				{
					lengthValue = (relativeLengthReference.viewportHeight * 0.01) * value;	
				}
				else
				{
					lengthValue = (relativeLengthReference.viewportWidth * 0.01) * value;
				}
				
			case VH(value):
				lengthValue = (relativeLengthReference.viewportHeight * 0.01) * value;	
				
			case VW(value):	
				lengthValue = (relativeLengthReference.viewportWidth * 0.01) * value;
		}
		
		return lengthValue;
	}
	
	public static function getBorderWidthFromBorderWidthKeyword(value:CSSKeywordValue):Float
	{
		switch(value)
		{
			case THIN:
				return Config.getInstance().thinBorderWidth;
				
			case MEDIUM:
				return Config.getInstance().mediumBorderWidth;
				
			case THICK:
				return Config.getInstance().thickBorderWidth;
				
			default:
				throw 'not a valid border width keyword';
		}
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
				
			case STRING(value):
				fontNames = [value];
				
			default:	
				throw 'Illegal value for font family style';
				
		}
		
		return fontNames;
	}
	
	/**
	 * Takes an absolute size value for a font size and return
	 * a pixel valueSZ
	 */
	public static function getFontSizeFromAbsoluteSizeValue(absoluteSize:CSSKeywordValue):Float
	{
		var fontSize:Float = 0.0;
		
		switch (absoluteSize)
		{
			case XX_SMALL:
				fontSize = Config.getInstance().xxSmallFontSize;
				
			case X_SMALL:
				fontSize = Config.getInstance().xSmallFontSize;
				
			case SMALL:
				fontSize = Config.getInstance().smallFontSize;
				
			case MEDIUM:
				fontSize = Config.getInstance().mediumFontSize;
				
			case LARGE:
				fontSize = Config.getInstance().largeFontSize;
				
			case X_LARGE:
				fontSize = Config.getInstance().xLargeFontSize;
				
			case XX_LARGE:
				fontSize = Config.getInstance().xxLargeFontSize;
				
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
	public inline static function getPixelFromPercent(percent:Float, reference:Float):Float
	{
		return reference * (percent * 0.01);
	}
	
	/**
	 * Get a percentage from a pixel value in a reference value
	 * @param	pixel
	 * @param	reference
	 * @return
	 */
	public inline static function getPercentFromPixel(pixel:Float, reference:Float):Float
	{
		return (reference / pixel) * 100;
	}
	
	
	/**
	 * Return the computed value of a CSS color from a specified
	 * CSS Color. For instance, color keyword (blue, red...) are computed
	 * into rgba color
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
				
				hue = 360 / hue;
				saturation = 100 / saturation;
				lightness = 100 / lightness;
				
				return HSLAToRGBA(hue, saturation, lightness, 1.0);
				
			case HSLA(hue, saturation, lightness, alpha):
				
				hue = 360 / hue;
				saturation = 100 / saturation;
				lightness = 100 / lightness;
				
				return HSLAToRGBA(hue, saturation, lightness, alpha);
			
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
	public static function getColorVOFromCSSColor(value:CSSColorValue, colorVO:ColorVO):Void
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
				
			default:
				//other color values (keyword, hex, rgb...) were converted to RGBA during 
				//cascade
		}
		
		colorVO.color = colorValue;
		colorVO.alpha = alphaValue;
	}
	
	/**
	 * Convert an hsla value to an rgba value.
	 * The hue,  saturation and lightness value should
	 * be normalized to fractions of 0 to 1
	 */
	private static function HSLAToRGBA(hue:Float, saturation:Float, lightness:Float, alpha:Float):CSSColorValue
	{
		var m2:Float = 0;
		if (lightness < 0.5)
		{
			m2 = lightness * (saturation + 1);
		}
		else
		{
			m2 = lightness + saturation - lightness * saturation;
		}
		
		var m1:Float = lightness * 2 - m2;
		
		var r:Int = Math.round(hueToRGB(m1, m2, hue + 1 / 3));
		var g:Int = Math.round(hueToRGB(m1, m2, hue));
		var b:Int = Math.round(hueToRGB(m1, m2, hue - 1 / 3));
		
		return RGBA(r, g, b, alpha);
	}
	
	/**
	 * convert a hue to its corresponding
	 * rgb value
	 */
	private static function hueToRGB(m1:Float, m2:Float, h:Float):Float
	{
		if (h < 0)
		{
			h = h + 1;
		}
		
		if (h > 1)
		{
			h = h - 1;
		}
		
		if (h * 6 < 1)
		{
			return m1 + (m2 - m1) * h * 6;
		}
		
		if (h * 2 < 1)
		{
			return m2;
		}
		
		if (h * 3 < 2)
		{
			return m1 + (m2 - m1) * (2 / 3 - h) * 6;
		}
		
		return m1;
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
			case ALICE_BLUE:
				return RGBA(240, 248, 255, 1.0);
				
			case ANTIQUE_WHITE:
				return RGBA(250, 235, 215, 1.0);	
			
			case AQUA:
				return RGBA(0, 255, 255, 1.0);
				
			case AQUAMARINE:
				return RGBA(127, 255, 212, 1.0);	
				
			case AZURE:
				return RGBA(240, 255, 255, 1.0);	
				
			case BEIGE:
				return RGBA(245, 245, 220, 1.0);
				
			case BISQUE:
				return RGBA(255, 228, 196, 1.0);		
				
			case BLACK:
				return RGBA(0, 0, 0, 1.0);
				
			case BLANCHE_DALMOND:
				return RGBA(255, 235, 205, 1.0);
				
			case BLUE:
				return RGBA(0, 0, 255, 1.0);
				
			case BLUE_VIOLET:
				return RGBA(138, 43, 226, 1.0);	
				
			case BROWN:
				return RGBA(165, 42, 42, 1.0);	
				
			case BURLY_WOOD:
				return RGBA(222, 184, 135, 1.0);	
				
			case CADET_BLUE:
				return RGBA(95, 158, 160, 1.0);	
				
			case CHARTREUSE:
				return RGBA(127, 255, 0, 1.0);	
				
			case CHOCOLATE:
				return RGBA(210, 105, 30, 1.0);	
				
			case CORAL:
				return RGBA(255, 127, 80, 1.0);	
				
			case CORNFLOWER_BLUE:
				return RGBA(100, 149, 237, 1.0);	
				
			case CORNSILK:
				return RGBA(255, 248, 220, 1.0);	
				
			case CRIMSON:
				return RGBA(220, 20, 60, 1.0);	
				
			case CYAN:
				return RGBA(0, 255, 255, 1.0);	
				
			case DARK_BLUE:
				return RGBA(0, 0, 139, 1.0);	
				
			case DARK_CYAN:
				return RGBA(0, 139, 139, 1.0);	
				
			case DARK_GOLDEN_ROD:
				return RGBA(184, 134, 11, 1.0);	
				
			case DARK_GRAY:
				return RGBA(169, 169, 169, 1.0);	
				
			case DARK_GREEN:
				return RGBA(0, 100, 0, 1.0);	
				
			case DARK_GREY:
				return RGBA(169, 169, 169, 1.0);	
				
			case DARK_KHAKI:
				return RGBA(189, 183, 107, 1.0);
				
			case DARK_MAGENTA:
				return RGBA(139, 0, 139, 1.0);	
				
			case DARK_OLIVE_GREEN:
				return RGBA(85, 107, 47, 1.0);
				
			case DARK_ORANGE:
				return RGBA(255, 140, 0, 1.0);	
				
			case DARK_ORCHID:
				return RGBA(153, 50, 204, 1.0);	
				
			case DARK_RED:
				return RGBA(139, 0, 0, 1.0);	
				
			case DARK_SALMON:
				return RGBA(233, 150, 122, 1.0);	
				
			case DARK_SEA_GREEN:
				return RGBA(143, 188, 143, 1.0);	
				
			case DARK_SLATE_BLUE:
				return RGBA(72, 61, 139, 1.0);	
				
			case DARK_SLATE_GRAY:
				return RGBA(47, 79, 79, 1.0);	
				
			case DARK_SLATE_GREY:
				return RGBA(47, 79, 79, 1.0);	
				
			case DARK_TURQUOISE:
				return RGBA(0, 206, 209, 1.0);	
				
			case DARK_VIOLET:
				return RGBA(148, 0, 211, 1.0);	
				
			case DEEP_PINK:
				return RGBA(255, 20, 147, 1.0);	
				
			case DEEP_SKY_BLUE:
				return RGBA(0, 191, 255, 1.0);	
				
			case DIM_GRAY:
				return RGBA(105, 105, 105, 1.0);	
				
			case DIM_GREY:
				return RGBA(105, 105, 105, 1.0);
				
			case DODGER_BLUE:
				return RGBA(30, 144, 255, 1.0);	
				
			case FIRE_BRICK:
				return RGBA(178, 34, 34, 1.0);	
				
			case FLORAL_WHITE:
				return RGBA(255, 250, 240, 1.0);	
				
			case FOREST_GREEN:
				return RGBA(34, 139, 34, 1.0);	
				
			case FUCHSIA:
				return RGBA(255, 0, 255, 1.0);
				
			case GAINSBORO:
				return RGBA(220, 220, 220, 1.0);	
				
			case GHOST_WHITE:
				return RGBA(248, 248, 255, 1.0);	
				
			case GOLD:
				return RGBA(255, 215, 0, 1.0);	
				
			case GOLDEN_ROD:
				return RGBA(218, 165, 32, 1.0);	
				
			case GRAY:
				return RGBA(128, 128, 128, 1.0);
				
			case GREEN:
				return RGBA(0, 128, 0, 1.0);
				
			case GREEN_YELLOW:
				return RGBA(173, 255, 47, 1.0);	
				
			case GREY:
				return RGBA(128, 128, 128, 1.0);	
				
			case HONEY_DEW:
				return RGBA(240, 255, 240, 1.0);		
				
			case HOT_PINK:
				return RGBA(255, 105, 180, 1.0);	
				
			case INDIAN_RED:
				return RGBA(205, 92, 92, 1.0);	
				
			case INDIGO:
				return RGBA(75, 0, 130, 1.0);		
				
			case IVORY:
				return RGBA(255, 255, 240, 1.0);		
				
			case KHAKI:
				return RGBA(240, 230, 140, 1.0);	
				
			case LAVENDER:
				return RGBA(230, 230, 250, 1.0);		
				
			case LAVENDER_BLUSH:
				return RGBA(255, 240, 245, 1.0);		
				
			case LAWN_GREEN:
				return RGBA(124, 252, 0, 1.0);		
				
			case LEMON_CHIFFON:
				return RGBA(255, 250, 205, 1.0);	
				
			case LIGHT_BLUE:
				return RGBA(173, 216, 130, 1.0);	
				
			case LIGHT_CORAL:
				return RGBA(240, 128, 128, 1.0);
				
			case LIGHT_CYAN:
				return RGBA(224, 255, 255, 1.0);		
				
			case LIGHT_GOLDENROD_YELLOW:
				return RGBA(250, 250, 210, 1.0);	
				
			case LIGHT_GRAY:
				return RGBA(211, 211, 211, 1.0);	
				
			case LIGHT_GREEN:
				return RGBA(144, 238, 144, 1.0);		
				
			case LIGHT_GREY:
				return RGBA(211, 211, 211, 1.0);	
				
			case LIGHT_PINK:
				return RGBA(255, 182, 193, 1.0);	
				
			case LIGHT_SALMON:
				return RGBA(255, 160, 122, 1.0);	
				
			case LIGHT_SEA_GREEN:
				return RGBA(32, 178, 170, 1.0);		
				
			case LIGHT_SKY_BLUE:
				return RGBA(135, 206, 250, 1.0);		
				
			case LIGHT_SLATE_GRAY:
				return RGBA(119, 136, 153, 1.0);		
			
			case LIGHT_SLATE_GREY:
				return RGBA(119, 136, 153, 1.0);	
				
			case LIGHT_STEEL_BLUE:
				return RGBA(176, 196, 222, 1.0);	
				
			case LIGHT_YELLOW:
				return RGBA(255, 255, 224, 1.0);		
				
			case LIME:
				return RGBA(0, 255, 0, 1.0);
				
			case LIME_GREEN:
				return RGBA(50, 205, 50, 1.0);		
				
			case LINEN:
				return RGBA(250, 240, 230, 1.0);	
				
			case MAGENTA:
				return RGBA(255, 0, 255, 1.0);		
				
			case MAROON:
				return RGBA(128, 0, 0, 1.0);
				
			case MEDIUM_AQUAMARINE:
				return RGBA(102, 205, 170, 1.0);	
				
			case MEDIUM_BLUE:
				return RGBA(0, 0, 205, 1.0);	
				
			case MEDIUM_ORCHID:
				return RGBA(186, 85, 211, 1.0);	
				
			case MEDIUM_PURPLE:
				return RGBA(147, 112, 219, 1.0);		
				
			case MEDIUM_SEA_GREEN:
				return RGBA(60, 179, 113, 1.0);	
				
			case MEDIUM_SLATE_BLUE:
				return RGBA(123, 104, 238, 1.0);	
				
			case MEDIUM_SPRING_GREEN:
				return RGBA(0, 250, 154, 1.0);		
				
			case MEDIUM_TURQUOISE:
				return RGBA(72, 209, 204, 1.0);	
				
			case MEDIUM_VIOLET_RED:
				return RGBA(199, 21, 133, 1.0);	
				
			case MIDNIGHT_BLUE:
				return RGBA(25, 25, 112, 1.0);	
				
			case MINT_CREAM:
				return RGBA(245, 255, 250, 1.0);		
				
			case MISTY_ROSE:
				return RGBA(255, 228, 225, 1.0);	
				
			case MOCCASIN:
				return RGBA(255, 228, 181, 1.0);		
				
			case NAVAJO_WHITE:
				return RGBA(255, 222, 173, 1.0);	
				
			case NAVY:
				return RGBA(0, 0, 128, 1.0);
				
			case OLD_LACE:
				return RGBA(253, 245, 230, 1.0);		
				
			case OLIVE:
				return RGBA(128, 128, 0, 1.0);
				
			case OLIVE_DRAB:
				return RGBA(107, 142, 35, 1.0);		
				
			case ORANGE:
				return RGBA(255, 165, 0, 1.0);
				
			case ORANGE_RED:
				return RGBA(255, 69, 0, 1.0);	
				
			case ORCHID:
				return RGBA(218, 112, 214, 1.0);		
				
			case PALE_GOLDEN_ROD:
				return RGBA(238, 232, 170, 1.0);	
				
			case PALE_GREEN:
				return RGBA(152, 251, 152, 1.0);
				
			case PALE_TURQUOISE:
				return RGBA(175, 238, 238, 1.0);		
				
			case PALE_VIOLET_RED:
				return RGBA(219, 112, 147, 1.0);	
				
			case PAPAYA_WHIP:
				return RGBA(255, 239, 213, 1.0);	
				
			case PEACH_PUFF:
				return RGBA(255, 218, 185, 1.0);	
				
			case PERU:
				return RGBA(205, 133, 63, 1.0);		
				
			case PINK:
				return RGBA(255, 192, 203, 1.0);		
				
			case PLUM:
				return RGBA(221, 160, 221, 1.0);	
				
			case POWDER_BLUE:
				return RGBA(176, 224, 230, 1.0);		
				
			case PURPLE:
				return RGBA(128, 0, 128, 1.0);
				
			case RED:
				return RGBA(255, 0, 0, 1.0);
				
			case ROSY_BROWN:
				return RGBA(188, 143, 143, 1.0);	
				
			case ROYAL_BLUE:
				return RGBA(65, 105, 225, 1.0);	
				
			case SADDLE_BROWN:
				return RGBA(139, 69, 19, 1.0);		
				
			case SALMON:
				return RGBA(250, 128, 114, 1.0);	
				
			case SANDY_BROWN:
				return RGBA(244, 164, 96, 1.0);		
				
			case SEA_GREEN:
				return RGBA(46, 139, 87, 1.0);	
				
			case SEA_SHELL:
				return RGBA(255, 245, 238, 1.0);		
				
			case SIENNA:
				return RGBA(160, 82, 45, 1.0);		
				
			case SILVER:
				return RGBA(192, 192, 192, 1.0);
				
			case SKY_BLUE:
				return RGBA(135, 206, 235, 1.0);	
				
			case SLATE_BLUE:
				return RGBA(106, 90, 205, 1.0);		
				
			case SLATE_GRAY:
				return RGBA(112, 128, 144, 1.0);		
				
			case SLATE_GREY:
				return RGBA(112, 128, 144, 1.0);	
				
			case SNOW:
				return RGBA(255, 250, 250, 1.0);
				
			case SPRING_GREEN:
				return RGBA(0, 255, 127, 1.0);		
				
			case STEEL_BLUE:
				return RGBA(70, 130, 180, 1.0);		
				
			case TAN:
				return RGBA(210, 180, 140, 1.0);	
				
			case TEAL:
				return RGBA(0, 128, 128, 1.0);
				
			case THISLE:
				return RGBA(216, 191, 216, 1.0);	
				
			case TOMATO:
				return RGBA(255, 99, 71, 1.0);		
				
			case TURQUOISE:
				return RGBA(64, 224, 208, 1.0);		
				
			case VIOLET:
				return RGBA(238, 130, 238, 1.0);	
				
			case WHEAT:
				return RGBA(245, 222, 179, 1.0);		
				
			case WHITE:
				return RGBA(255, 255, 255, 1.0);
				
			case WHITE_SMOKE:
				return RGBA(245, 245, 245, 1.0);	
				
			case YELLOW:
				return RGBA(255, 255, 0, 1.0);
				
			case YELLOW_GREEN:
				return RGBA(154, 205, 50, 1.0);		
				
		}
	}
	
	/**
	 * Get the next largest font size in the font size size array, taking
	 * the parent's font size as starting value
	 */
	private static function getLargerFontSize(parentFontSize:Float):Float
	{
		var fontSizeTable:Array<Int> = [
		Config.getInstance().xxSmallFontSize,
		Config.getInstance().xSmallFontSize,
		Config.getInstance().smallFontSize,
		Config.getInstance().mediumFontSize,
		Config.getInstance().largeFontSize,
		Config.getInstance().xLargeFontSize,
		Config.getInstance().xxLargeFontSize];
		
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
		var fontSizeTable:Array<Int> = [
		Config.getInstance().xxSmallFontSize,
		Config.getInstance().xSmallFontSize,
		Config.getInstance().smallFontSize,
		Config.getInstance().mediumFontSize,
		Config.getInstance().largeFontSize,
		Config.getInstance().xLargeFontSize,
		Config.getInstance().xxLargeFontSize];
		
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
