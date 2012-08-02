/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * The EventListener interface is the primary way to handle events.
 * Content authors must define on object, such as a function,
 * with the EventListener interface and register their event
 * listener on an EventTarget.
 * 
 * @author Yannick DOMINGUEZ
 */
class EventListener  
{
	/**
	 * Wheter this event listener is triggered during the
	 * capture phase (if true) or the bubling phase (if false)
	 */
	public var useCapture(default, null):Bool;
	
	/**
	 * The callback to call when this event listener is triggered
	 */
	public var listener(default, null):Event->Void;
	
	/**
	 * The type of event this listener listens for
	 */
	public var eventType(default, null):String;
	
	/**
	 * class constructor. Init
	 * class attributes
	 */
	public function new(eventType:String, listener:Event->Void, useCapture:Bool)
	{
		this.listener = listener;
		this.useCapture = useCapture;
		this.eventType = eventType;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method must be called whenever an event occurs of the
	 * event type for which the EventListener interface was registered.
	 * 
	 * @param	evt The Event contains contextual 
	 * information about the event.
	 */
	public function handleEvent(evt:Event):Void
	{
		listener(evt);
	}
	
	/**
	 * clean-up method removing callback reference.
	 * Called when the EventListener is removed
	 * from an EventTarget
	 */
	public function dispose():Void
	{
		listener = null;
	}
}