/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

import cocktail.core.event.EventData;

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