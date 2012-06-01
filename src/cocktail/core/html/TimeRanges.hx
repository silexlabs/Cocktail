 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.html.HTMLData;

/**
 * Objects implementing the TimeRanges interface represent a
 * list of ranges (periods) of time.
 * 
 * @author Yannick DOMINGUEZ
 */
class TimeRanges 
{
	/**
	 * Returns the number of ranges in the object.
	 */
	public var length(get_length, never):Int;
	
	/**
	 * An array of range
	 */
	private var _ranges:Array<Range>;
	
	/**
	 * class constructor
	 */
	public function new(ranges:Array<Range>) 
	{
		_ranges = ranges;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the time for the start of the range 
	 * with the given index.
	 */
	public function start(index:Int):Float
	{
		return _ranges[index].start;
	}
	
	/**
	 * Returns the time for the end of the range
	 * with the given index.
	 */
	public function end(index:Int):Float
	{
		return _ranges[index].end;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_length():Int
	{
		return _ranges.length;
	}
	
}