/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;
import cocktail.core.html.HTMLElement;

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
 * TODO 2 : init methods such as initEvent have just been deprecated (2/07/2012),
 * should now refer to DOM4 spec for event construction
 * 
 * @author Yannick DOMINGUEZ
 */
class Event 
{	
	//PhaseType, An integer indicating which phase of the event flow is being processed
	
	/**
	 * The current event phase is the capture phase.
	 */
	public static inline var CAPTURING_PHASE:Int = 1;
	
	/**
	 * The current event is in the target phase, i.e., 
	 * it is being evaluated at the proximal event target.
	 */
	public static inline var AT_TARGET:Int = 2;
	
	/**
	 * The current event phase is the bubbling phase.
	 */
	public static inline var BUBBLING_PHASE:Int = 3;
	
	/**
	 * Used to indicate which phase of event flow
	 * is currently being accomplished.
	 */
	public var eventPhase:Int;
	
	/**
	 * The name of the event
	 */
	public var type(default, null):String;
	
	/**
	 * Used to indicate the event target. This attribute
	 * contains the proximal event target when used with the Event dispatch and DOM event flow.
	 */ 
	public var target:EventTarget;
	
	/**
	 * Used to indicate the EventTarget whose EventListeners
	 * are currently being processed. 
	 * This is particularly useful during
	 * the capture and bubbling phases. 
	 * When used with the Event dispatch and DOM event flow,
	 * this attribute contains the proximal event target or a target ancestor.
	 */
	public var currentTarget:EventTarget;
	
	/**
	 * Used to indicate whether or not an event is a bubbling event.
	 * If the event can bubble the value is true
	 */
	public var bubbles(default, null):Bool;
	
	/**
	 * Used to indicate whether or not an event can have its default
	 * action prevented. If the default action can be prevented it is true
	 */
	public var cancelable(default, null):Bool;
	
	/**
	 * Used to indicate whether Event.preventDefault()
	 * has been called for this event.
	 */
	public var defaultPrevented(default, null):Bool;
	
	/**
	 * Used to indicate wether Event.stopPropagation()
	 * has been called for this event
	 */
	public var propagationStopped(default, null):Bool;
	
	/**
	 * Used to indicate wether Event.stopImmediatePropagation()
	 * has been called for this event
	 */
	public var immediatePropagationStopped(default, null):Bool;
	
	/**
	 * Wheter this event has already been dispatched
	 */
	public var dispatched:Bool;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Initializes attributes of an Event created through the
	 * DocumentEvent.createEvent method. This method may only 
	 * be called before the Event has been dispatched via the EventTarget.dispatchEvent()
	 * method. If the method is called several times before invoking EventTarget.dispatchEvent,
	 * only the final invocation takes precedence. This method has no effect if called after
	 * the event has been dispatched. If called from a subclass of the Event 
	 * interface only the values specified in this method are modified, all
	 * other attributes are left unchanged.This method sets the Event.type attribute
	 * to eventTypeArg.
	 * 
	 * @param	eventTypeArg Specifies Event.type, the name of the event type.
	 * @param	canBubbleArg Specifies Event.bubbles. This parameter overrides the intrinsic bubbling behavior of the event.
	 * @param	cancelableArg Specifies Event.cancelable. This parameter overrides the intrinsic cancelable behavior of the event.
	 */
	public function initEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		type = eventTypeArg;
		bubbles = canBubbleArg;
		cancelable = cancelableArg;
	}
	
	/**
	 * When this method is invoked, the event must be canceled,
	 * meaning any default actions normally taken by the
	 * implementation as a result of the event must not occur
	 * 
	 * Default actions which occur prior to the event's dispatch are reverted.
	 * Calling this method for a non-cancelable event must have no effect.
	 * If an event has more than one default action, each cancelable default
	 action must be canceled. 
	 */
	public function preventDefault():Void
	{
		defaultPrevented = true;
	}
	
	/**
	 * Prevents other event listeners from being triggered
	 * but its effect must be deferred until all event
	 * listeners attached on the Event.currentTarget have
	 * been triggered. Once it has been called,
	 * further calls to this method have no additional effect. 
	 */
	public function stopPropagation():Void
	{
		propagationStopped = true;
	}
	
	/**
	 * Prevents other event listeners from being triggered and,
	 * unlike Event.stopPropagation() its effect must be immediate .
	 * Once it has been called, further calls to this method have no additional effect. 
	 */
	public function stopImmediatePropagation():Void
	{
		immediatePropagationStopped = true;
	}
}