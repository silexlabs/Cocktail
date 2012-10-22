/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.history;

import cocktail.core.history.HistoryData;

/**
 * Implementation of the history API as stated here http://dev.w3.org/html5/spec/single-page.html#history
 */
class History
{	    	
	/**
	 * number of entries in the history
	 */
	public var length(getLength, null):Int;
	/**
	 * current state object
	 */
	public var state(getState, null):Dynamic;
	/**
	 * array of states
	 */
	private var stateArray:Array<StateData>;
	/**
	 *
	 */
	private var currentIdx
	/**
	 * event.state contains a copy of the information that was provided to pushState() or replaceState()
	 */
	private var onpopstate
	/**
	 * class constructor
	 */
	public function new() 
	{
		stateArray = new Array();
	}
	/**
	 * getter for the length property
	 */
	public function getLength():Int 
	{
		return 0;
	}
	/**
	 * getter for the state property
	 */
	public function getState():Dynamic 
	{
		return null;
	}
	/**
	 * Goes back or forward the specified number of steps in the joint session history.
	 * A zero delta will reload the current page. If the delta is out of range, does nothing.
	 */
	public function go(delta:Int) 
	{
		// make a copy of the state data
		// throw a 
		//see http://dev.w3.org/html5/spec/single-page.html?utm_source=dlvr.it&utm_medium=feed#event-popstate
	}
	/**
	 * Goes back one step in the joint session history. If there is no previous page, does nothing.
	 */
	public function back()
	{
		go(-1);
	}
	/**
	 * Goes forward one step in the joint session history. If there is no next page, does nothing.
	 */
	public function forward()
	{
		go(1);
	}
	/**
	 * Pushes the given data onto the session history, with the given title, and, if provided, the given URL.
	 */
	public function pushState(data:Dynamic, title:String, url:Null<String>=null)
	{
		
	}
	/**
	 * Updates the current entry in the session history to have the given data, title, and, if provided, URL.
	 */
	public function replaceState(data:Dynamic, title:String, url:Null<String>=null)
	{
		
	}
}