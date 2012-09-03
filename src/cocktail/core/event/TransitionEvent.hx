/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * The TransitionEvent interface provides specific 
 * contextual information associated with transitions.
 * 
 * @author Yannick DOMINGUEZ
 */
class TransitionEvent extends Event
{
	/**
	 * The name of the CSS property associated with the transition.
	 */
	public var propertyName(default, null):String;
	
	/**
	 * The amount of time the transition has been running,
	 * in seconds, when this event fired.
	 * Note that this value is not affected by the value
	 * of transition-delay.
	 */
	public var elapsedTime(default, null):Float;
	
	/**
	 * The name (beginning with two colons) of the CSS
	 * pseudo-element on which the transition occured
	 * (in which case the target of the event is that
	 * pseudo-element's corresponding element), 
	 * or the empty string if the transition occurred
	 * on an element (which means the target of
	 * the event is that element).
	 * 
	 * TODO 5 : complete once pseudo elements are implemented
	 */
	public var pseudoElement(default, null):String;
	
	/**
	 * class constructor
	 */
	public function new()
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The initTransitionEvent method is used to initialize the value
	 * of a TransitionEvent created through the DocumentEvent
	 * interface. This method may only be called before
	 * the TransitionEvent has been dispatched via the dispatchEvent
	 * method, though it may be called multiple times during
	 * that phase if necessary. If called multiple times,
	 * the final invocation takes precedence.
	 * 
	 * @param	eventTypeArg Specifies the event type.
	 * @param	canBubbleArg Specifies whether or not the event can bubble.
	 * @param	cancelableArg Specifies whether or not the event's default action can 
	 * be prevented. Since a TransitionEvent is purely for notification, there
	 * is no default action.
	 * @param	propertyNameArg Specifies the name of the property associated with
	 * the Event. (See the propertyName attribute.)
	 * @param	elapsedTimeArg Specifies the amount of time, in seconds, the transition has been
	 * running at the time of initialization. (See the elapsedTime attribute.)
	 * @param	pseudoElementArg Specifies the pseudo-element on which the
	 * transition occurred. (See the pseudoElement attribute.)
	 */
	public function initTransitionEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, propertyNameArg:String,
	elapsedTimeArg:Float, pseudoElementArg:String):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initEvent(eventTypeArg, canBubbleArg, cancelableArg);
		
		propertyName = propertyNameArg;
		elapsedTime = elapsedTimeArg;
		pseudoElement = pseudoElementArg;
	}
}