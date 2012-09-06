/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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

