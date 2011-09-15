/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.geom;

/**
 * This file contains geometry themed struct and enums
 */

//////////////////////////////////////////////////////////////////////////////////////////
// General geometry structures and enums
//////////////////////////////////////////////////////////////////////////////////////////
 
	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * represent a rectangle
	 */
	typedef Rectangle = {
		var x:Float;
		var y:Float;
		var width:Float;
		var height:Float;
	}
	
	/**
	 * Represents a point in 2d space
	 */
	typedef Point = {
		var x:Float;
		var y:Float;
	}

//////////////////////////////////////////////////////////////////////////////////////////
// Matrix structures and enums
//////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////////////
	// Structures
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Represents the value of a 3x3 Matrix
	 */
	typedef MatrixData = {
		var a:Float;
		var b:Float;
		var c:Float;
		var d:Float;
		var e:Float;
		var f:Float;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Enums
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The different value used to determine a transformation origin.
	 * It can be specified by a constant, representing a point (top-left, center...) 
	 * or directly by a point (in px).
	 */
	enum RegistrationPointValue {
		constant(registrationPointX:RegistrationPointXValue, registrationPointY:RegistrationPointYValue);
		point(point:Point);
	}
	
	/**
	 * The different values for the transformation origin
	 * along the x axis
	 */
	enum RegistrationPointXValue {
		left;
		center;
		right;
	}
	
	/**
	 * The different values for the transformation origin
	 * along the y axis
	 */
	enum RegistrationPointYValue {
		top;
		middle;
		bottom;
	}

