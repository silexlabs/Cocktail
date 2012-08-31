 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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