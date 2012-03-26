/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.event;
import core.dom.EventTarget;
import core.HTMLElement;

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
	
	public static inline var FOCUS:String = "focus";
	
	public static inline var BLUR:String = "blur";
	
	public static inline var ERROR:String = "error";
	
	public static inline var READY_STATE_CHANGE:String = "readystatechange";
	
	//TODO : add current target
	
	/**
	 * The name of the event
	 */
	private var _type:String;
	public var type(get_type, never):String;
	
	/**
	 * Used to indicate the event target
	 */ 
	private var _target:EventTarget;
	public var target(get_target, never):EventTarget;
	
	/**
	 * Used to indicate whether Event.preventDefault()
	 * has been called for this event.
	 */
	private var _defaultPrevented:Bool;
	public var defaultPrevented(get_defaultPrevented, never):Bool;
	
	/**
	 * class constructor
	 */
	public function new(type:String, target:EventTarget) 
	{
		_type = type;
		_target = target;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * If an event is cancelable, the preventDefault method is used to signify
	 * that the event is to be canceled, meaning any default action normally 
	 * taken by the implementation as a result of the event will not occur.
	 * If, during any stage of event flow, the preventDefault
	 * method is called the event is canceled.
	 * Any default action associated with the event will not occur.
	 * Calling this method for a non-cancelable event has no effect.
	 * Once preventDefault has been called it will remain in effect throughout
	 * the remainder of the event's propagation.
	 * This method may be used during any stage of event flow. 
	 * 
	 * TODO : in JS, should call nativeElement's preventDefault. Store
	 * nativeEvent ?
	 */
	public function preventDefault():Void
	{
		_defaultPrevented = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_defaultPrevented():Bool 
	{
		return _defaultPrevented;
	}
	
	private function get_type():String 
	{
		return _type;
	}
	
	private function get_target():EventTarget
	{
		return _target;
	}
}