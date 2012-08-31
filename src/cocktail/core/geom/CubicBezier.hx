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
 * Class used to compute cubic bezier
 * for CSS transitions.
 * 
 * I don't understand any of it.
 * 
 * @author Yannick DOMINGUEZ
 */
class CubicBezier 
{

	private var _x1:Float;
	
	private var _y1:Float;
	
	private var _x2:Float;
	
	private var _y2:Float;
	
	private var _cx:Float;
	
	private var _bx:Float;
	
	private var _ax:Float;
	
	private var _cy:Float;
	
	private var _by:Float;
	
	private var _ay:Float;
	
	/**
	 * Class constructor
	 */
	public function new(x1:Float, y1:Float, x2:Float, y2:Float) 
	{
		_x1 = x1;
		_y1 = y1;
		_x2 = x2;
		_y2 = y2;
		
		_cx = 3 * _x1;
		_bx = 3 * (_x2 - _x1) - _cx;
		_ax = 1 - _cx - _bx;
		
		_cy = 3 * _y1;
		_by = 3 * (_y2 - _y1) - _cy;
		_ay = 1 - _cy - _by;
	}
	
	public function bezierX(t:Float):Float
	{
		return t * (_cx + t * (_bx + t * _ax));
	}
	
	public function bezierY(t:Float):Float
	{
		return t * (_cy + t * (_by + t * _ay));
	}
	
}