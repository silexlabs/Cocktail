/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

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
	RGB(red:Int, green:Int, blue:Int);
	
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
}

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