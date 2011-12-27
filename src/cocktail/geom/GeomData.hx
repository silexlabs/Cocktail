/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
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
	typedef RectangleData = {
		var x:Float;
		var y:Float;
		var width:Float;
		var height:Float;
	}
	
	/**
	 * Represents a point in 2d space
	 */
	typedef PointData = {
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
	 * Represents the values of a 3x3 Matrix
	 */
	typedef MatrixData = {
		var a:Float;
		var b:Float;
		var c:Float;
		var d:Float;
		var e:Float;
		var f:Float;
	}

