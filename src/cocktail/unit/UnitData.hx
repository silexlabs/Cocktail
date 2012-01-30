/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.unit;

/**
 * Contains CSS units related enums
 */

/**
 * Lists the different types of 
 * unit supported with an explicitly
 * set length such as px, cm, em...
 * 
 * There are two kinds of length units :
 * - absolute (px, cm, mm, pt, pc, in).
 * absolute length are all computed to pixel
 * values.
 * 
 * - relative (em and ex). Relative length units 
 * specify a length relative to another length property.
 */
enum LengthValue {
	
	/**
	 * pixel, 1px is equal to 0.75pt.
	 */
	px(value:Float);
	
	/**
	 * centimeters
	 */
	cm(value:Float);
	
	/**
	 * millimeters
	 */
	mm(value:Float);
	
	/**
	 * points, the points
	 * are equal to 1/72nd of 1in. 
	 */
	pt(value:Float);
	
	/**
	 * picas, 1pc is equal to 12pt.
	 */
	pc(value:Float);
	
	/**
	 * inches, 1in is equal to 2.54cm.
	 */
	_in(value:Float);
	
	/**
	 * The 'em' unit is equal to the
	 * computed value of the 'font-size'
	 * property of the element on which it is used.
	 * The exception is when 'em'
	 * occurs in the value of the 'font-size' 
	 * property itself, in which case it
	 * refers to the font size of the parent
	 * element. It may be used for vertical or
	 * horizontal measurement.
	 */
	em(value:Float);
	
	/**
	 * The 'ex' unit is defined by the element's first available font.
	 * The exception is when 'ex' occurs in
	 * the value of the 'font-size' property,
	 * in which case it refers to the 'ex' of the
	 * parent element.The 'x-height' 
	 * is so called because it is often equal to the height
	 * of the lowercase "x". However, an 'ex' is
	 * defined even for fonts that do not contain an "x".
	 */
	ex(value:Float);
}

/**
 * Lists the possible values to 
 * define an absolute size for a font.
 * The actual value matching each
 * of the absolute values depends 
 * on the user agent and the user 
 * preferences
 */
enum FontSizeAbsoluteSizeValue {
	xxSmall;
	xSmall;
	small;
	medium;
	large;
	xLarge;
	xxLarge;
}

/**
 * Lists the possible relative values
 * to define the font size of a
 * DOMElement in relation
 * with the parent font size.
 */
enum FontSizeRelativeSizeValue {
	larger;
	smaller;
}

/**
 * Lists the different color format supported.
 * Each value describes one color
 */
enum ColorValue {
	
	/**
	 * each value (red, green and blue)
	 * must be an integer from 0 to 255
	 */
	rgb(red:Int, green:Int, blue:Int);
	
	/**
	 * same as rgb + alpha is a float from 
	 * 0 (transparent) to 1 (opaque)
	 */
	rgba(red:Int, green:Int, blue:Int, alpha:Float);
	
	/**
	 * The color value must be represented
	 * as 6 hexadecimal number string started
	 * with a "#" charachter.
	 * e.g : for red, #FF0000
	 */
	hex(value:String);
	
	/**
	 * the color is chosen among a
	 * set of predefined colors
	 */ 
	keyword(value:ColorKeywordValue);
	
	/**
	 * a fully transparent color, equivalent
	 * to rgba(0,0,0,0)
	 */
	transparent;
}

/**
 * This value represents a 2D image which
 * can either be loaded from an external
 * source, or a programmaticaly drawn
 * gradient
 */
enum ImageValue {
	
	/**
	 * the image is loaded from a URL
	 */
	url(value:URLData);
	
	/**
	 * The image is specified as multiple URL, the
	 * first valid URL being used
	 */
	imageList(value:Array<ImageDeclarationValue>);
	
	/**
	 * The image is a programmaticaly drawn
	 * gradient
	 */
	gradient(value:GradientValue);
}

/**
 * An element for a list of image, can either
 * be an image URL or a fallback color used if
 * all the URL in the image list are invalid
 */
enum ImageDeclarationValue {
	url(value:URLData);
	color(value:ColorValue);
}

/**
 * The different types of gradient which
 * can be used as image
 */
enum GradientValue {
	linear(value:LinearGradientData);
}

/**
 * a linear gradient, which has a direction
 * and a variable number of colors
 */
typedef LinearGradientData = {
	var angle:GradientAngleValue;
	var colorStops:Array<GradientColorStopData>;
}

/**
 * Each color stops is constituted of a
 * color and the position of this color
 * in the gradient
 */
typedef GradientColorStopData = {
	var color:ColorValue;
	var stop:GradientStopValue;
}

/**
 * A color stop position can be defined as
 * an absolute value or a percentage of
 * the gradient box
 */
enum GradientStopValue {
	length(value:LengthValue);
	percent(value:Int);
}

/**
 * The angle of a linear gradient can either
 * be an angle (defined in deg, rad...) or a keyword
 * representing a side or corner of the gradient box
 */
enum GradientAngleValue {
	angle(value:AngleValue);
	side(value:GradientSideValue);
	corner(horizontal:GradientHorizontalSideValue, vertical:GradientVerticalSideValue);
}

/**
 * the side of the gradient box.
 * Top is equal to a 0deg angle
 */
enum GradientSideValue {
	top;
	left;
	bottom;
	right;
}

/**
 * the vertical side of the gradient box
 */
enum GradientVerticalSideValue {
	top;
	bottom;
}

/**
 * the horizontal side of the gradient box
 */
enum GradientHorizontalSideValue {
	left;
	right;
}

/**
 * Define a CSS URL value
 */
typedef URLData = String;

/**
 * Lists the default available colors
 */
enum ColorKeywordValue {
	aqua;
	black;
	blue;
	fuchsia;
	gray;
	green;
	lime;
	maroon;
	navy;
	olive;
	orange;
	purple;
	red;
	silver;
	teal;
	white;
	yellow;
}

/**
 * Lists the different available
 * units to specify an angle
 */
enum AngleValue {
	
	/**
	 * Degress. There are
	 * 360 degrees in a full 
	 * circle
	 */
	deg(value:Float);
	
	/**
	 * Gradians. There
	 * are 400 gradians in
	 * a full circle
	 */
	grad(value:Float);
	
	/**
	 * Radians. There are 2π
	 * radians in a full circle.
	 */
	rad(value:Float);
	
	/**
	 * Turns. There is 1 
	 * turn in a full circle. 
	 */
	turn(value:Float);
}