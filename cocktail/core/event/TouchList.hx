/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.event;

import cocktail.core.event.Touch;

/**
 * This interface defines a list of individual points of contact for a 
 * touch event. TouchList objects are immutable;
 * after one is created, its contents must not change.
 * 
 * @author Yannick DOMINGUEZ
 */
class TouchList 
{
	/**
	 * The touches of this touch list
	 */
	private var _touches:Array<Touch>;
	
	public var length(get_length, null):Int;
	
	/**
	 * class constructor
	 */
	public function new(touches:Array<Touch>) 
	{
		_touches = touches;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * returns the Touch at the specified index in the list
	 */
	public function item(index:Int):Touch
	{
		return _touches[index];
	}
	
	/**
	 * returns the first Touch item in the list whose
	 * identifier property matches the specified identifier
	 */
	public function identifiedTouch(identifier:Int):Touch
	{
		for (i in 0...length)
		{
			if (_touches[i].identifier == identifier)
			{
				return _touches[i];
			}
		}
		
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return number of touch for this touch list
	 */
	private function get_length():Int
	{
		return _touches.length;
	}
	
}