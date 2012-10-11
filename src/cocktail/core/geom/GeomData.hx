/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.geom;
import cocktail.core.utils.IPoolable;
import cocktail.core.utils.ObjectPool;
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
	class RectangleVO implements IPoolable
	{
		public var x:Float;
		public var y:Float;
		public var width:Float;
		public var height:Float;
		
		private static var _pool:ObjectPool<RectangleVO>;
		
		public static function getPool():ObjectPool<RectangleVO>
		{
			if (_pool == null)
			{
				_pool = new ObjectPool<RectangleVO>(RectangleVO);
			}
			return _pool;
		}
		
		public function new()
		{
			reset();
		}
		
		public function reset():Void
		{
			x = 0;
			y = 0;
			width = 0;
			height = 0;
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

