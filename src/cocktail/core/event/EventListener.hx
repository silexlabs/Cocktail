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
 * which the EventListener interface and register their event
 * listener on an EventTarget.
 * 
 * The content authors should also
 * remove their EventListener from its EventTarget after they 
 * have completed using the listener.Copying a Node, with methods
 * such as Node.cloneNode or Range.cloneContents, must not copy
 * the event listeners attached to it.
 * 
 * Event listeners must
 * be attached to the newly created Node afterwards, if so desired.
 * 
 * Moving a Node, with methods Document.adoptNode, Node.appendChild,
 * or Range.extractContents, must not affect the event listeners attached to it. 
 * 
 * @author Yannick DOMINGUEZ
 */
class EventListener  
{
	
	private var _useCapture:Bool;
	public var useCapture(get_useCapture, never):Bool;
	
	private var _listener:Event->Void;
	public var listener(get_listener, never):Event->Void;
	
	
	private var _eventType:String;
	public var eventType(get_eventType, never):String;
	
	public function new(eventType:String, listener:Event->Void, useCapture:Bool)
	{
		_listener = listener;
		_useCapture = useCapture;
		_eventType = eventType;
	}
	
	/**
	 * This method must be called whenever an event occurs of the
	 * event type for which the EventListener interface was registered.
	 * 
	 * @param	evt The Event contains contextual 
	 * information about the event.
	 */
	public function handleEvent(evt:Event):Void
	{
		_listener(evt);
	}
	
	public function dispose():Void
	{
		_listener = null;
	}
	
	private function get_eventType():String
	{
		return _eventType;
	}
	
	private function get_listener():Event->Void
	{
		return _listener;
	}
	
	private function get_useCapture():Bool
	{
		return _useCapture;
	}
}