/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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