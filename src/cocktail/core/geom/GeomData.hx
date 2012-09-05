/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.geom;

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
	class RectangleVO {
		public var x:Float;
		public var y:Float;
		public var width:Float;
		public var height:Float;
		
		public function new(x:Float, y:Float, width:Float, height:Float)
		{
			this.x = x;
			this.y = y;
			this.width = width;
			this.height = height;
		}
	}
	
	/**
	 * Represents a point in 2d space
	 */
	class PointVO {
		public var x:Float;
		public var y:Float;
		
		public function new(x:Float, y:Float)
		{
			this.x = x;
			this.y = y;
		}
	}
	
	/**
	 * Represents a width and
	 * height dimension
	 */
	class DimensionVO {
		
		public var width:Float;
		public var height:Float;
		
		public function new(width:Float, height:Float)
		{
			this.width = width;
			this.height = height;
		}
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

