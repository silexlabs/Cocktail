/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.unit;
import cocktail.core.css.CSSData;

/**
 * Contains CSS units related enums
 */

/**
 * Represents a color with
 * its alpha (from 0 to 1)
 */
typedef ColorData = {
	var color:Int;
	var alpha:Float;
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
	 * first valid URL being used. a fallback color
	 * is provided if all urls fails
	 */
	imageList(value:ImageDeclarationData);
	
	/**
	 * The image is a programmaticaly drawn
	 * gradient
	 */
	gradient(value:GradientValue);
}

/**
 * define an array of URLs to load, the first
 * valid URL is used. If all fail, the fallback
 * color is used
 */
typedef ImageDeclarationData = {
	var urls:Array<URLData>;
	var fallbackColor:CSSColorValue;
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
	var angle:GradientAngle;
	var colorStops:Array<GradientColorStopData>;
}

/**
 * Each color stops is constituted of a
 * color and the position of this color
 * in the gradient
 */
typedef GradientColorStopData = {
	var color:CSSColorValue;
	var stop:GradientStopValue;
}

/**
 * A color stop position can be defined as
 * an absolute value or a percentage of
 * the gradient box
 */
enum GradientStopValue {
	length(value:CSSLengthValue);
	percent(value:Int);
}

/**
 * The angle of a linear gradient can either
 * be an angle (defined in deg, rad...) or a keyword
 * representing a side or corner of the gradient box
 */
enum GradientAngle {
	angle(value:CSSAngleValue);
	side(value:GradientSideValue);
	corner(value:GradientCornerValue);
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
 * a corner of the gradient box
 */
enum GradientCornerValue {
	topRight;
	bottomRight;
	bottomLeft;
	topLeft;
}

/**
 * Define a CSS URL value
 */
typedef URLData = String;
