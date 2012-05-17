/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * The interface allows registration and removal 
 * of event listeners, and dispatch of events to an event target.
 * 
 * TODO : implement + doc
 * 
 * @author Yannick DOMINGUEZ
 */
class EventTarget
{
	private var _eventHandlers:Hash<Array<IEventListener>>;
	
	public function new() 
	{
		_eventHandlers = new Hash();
	}

	/**
	 * Dispatches an event into the implementation's event model.
	 * The event target of the event must be the EventTarget object on which dispatchEvent is called. 
	 * 
	 * @param	evt The event to be dispatched.
	 * @return Indicates whether any of the listeners which handled the event called Event.preventDefault().
	 * If Event.preventDefault() was called the is false
	 */
	public function dispatchEvent(evt:Event):Bool
	{
		// Dispatch to objects that are registered as listeners for
		// this object.
		dispatchQueue(_eventHandlers.get(evt.type), evt);
		return evt.defaultPrevented;
	}

	/**
	 * Registers an event listener, depending on the useCapture parameter,
	 * on the capture phase of the DOM event flow or its target and bubbling phases. 
	 * 
	 * @param	type Specifies the Event.type associated with the event for which the user is registering.
	 * @param	listener 
	 * The listener parameter must be an object which implements the EventListener
	 * interface, such as a reference to a . 
	 * 
	 * The listener parameter must be either an object
	 * that implements the EventListener interface, or a function.
	 * If listener is a function then it must be used as the callback
	 * for the event; otherwise, if listener implements EventTarget,
	 * then its handleEvent method must be used as the callback.
	 * 
	 * The listener parameter takes an object defined by the author
	 * which implements the EventListener interface and contains the method
	 * to be called when the event occurs.
	 * 
	 * @param	useCapture If true, useCapture indicates that the user wishes
	 * to add the event listener for the capture and target phases 
	 * only, i.e., this event listener will not be triggered during the bubbling
	 * phase. If false, the event listener must only be triggered during
	 * the target and bubbling phases.
	 */
	public function addEventListener(event:String, handler:IEventListener, useCapture:Bool = false):Void
	{
		if (_eventHandlers.exists(event) == false)
		{
			_eventHandlers.set(event, new Array<IEventListener>());
		}
		
		removeEventListener(event, handler);
		_eventHandlers.get(event).push(handler);
	}

	/**
	 * Removes an event listener. Calling removeEventListener with arguments
	 * which do not identify any currently registered EventListener on the EventTarget has no effect. 
	 * 
	 * @param	type Specifies the Event.type for which the user registered the event listener.
	 * @param	listener The EventListener to be removed.
	 * @param	useCapture 
	 * Specifies whether the EventListener being removed was registered for the capture
	 * phase or not. If a listener was registered twice, once for the capture and
	 * target phases and once for the target and bubbling phases, each must be removed 
	 * separately. Removal of an event listener registered for the capture and target
	 * phases does not affect the same event listener registered for the target and bubbling phases,
	 * and vice versa.
	 */
	public function removeEventListener(event:String, handler:IEventListener, useCapture:Bool = false):Void
	{
		if (_eventHandlers.exists(event) == true)
		{
			var registeredListeners:Array<IEventListener> = _eventHandlers.get(event);
			for (i in 0...registeredListeners.length)
			{
				var eventListener:IEventListener = registeredListeners[i];
				if (eventListener == handler) {
					registeredListeners.splice(i, 1);
					return;
				}
			}
		}
	}
	
	private function dispatchQueue(queue:Array<IEventListener>, evt:Event):Void
	{
		if (queue != null)
		{
			for (i in 0...queue.length)
			{
				var eventListener:IEventListener = queue[i];
				eventListener.handleEvent(evt);
			}
		}
	}
	
}