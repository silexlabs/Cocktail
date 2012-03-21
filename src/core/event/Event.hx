/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.event;

/**
 * The Event interface is used to provide contextual information
 * about an event to the handler processing the event.
 * An object which implements the Event interface is generally
 * passed as the first parameter to an event handler. More specific
 * context information is passed to event handlers by deriving
 * additional interfaces from Event which contain information
 * directly relating to the type of event they accompany. These
 * derived interfaces are also implemented by the object passed
 * to the event listener.
 * 
 * @author Yannick DOMINGUEZ
 */
class Event 
{
	public static inline var SCROLL:String = "scroll";
	
	public static inline var LOAD:String = "load";
	
	//TODO : add target and current target
	
	/**
	 * The name of the event
	 */
	private var _type:String;
	public var type(get_type, null):String;
	
	/**
	 * class constructor
	 */
	public function new(type:String) 
	{
		_type = type;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_type():String 
	{
		return _type;
	}
}