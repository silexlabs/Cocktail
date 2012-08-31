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
 * The FocusEvent interface provides specific contextual information 
 * associated with Focus events. To create an instance of the 
 * FocusEvent interface, use the DocumentEvent.createEvent("FocusEvent")
 * method call.
 * 
 * @author Yannick DOMINGUEZ
 */
class FocusEvent extends UIEvent
{
	/**
	 * A user agent must dispatch this event when an event target 
	 * receives focus. The focus must be given to the element before 
	 * the dispatch of this event type. This event type is similar to focusin, 
	 * but is dispatched after focus is shifted, and does not bubble.
	 */
	public static inline var FOCUS:String = "focus";
	
	/**
	 * A user agent must dispatch this event when an event target loses focus.
	 * The focus must be taken from the element before the dispatch of this
	 * event type. This event type is similar to focusout,
	 * but is dispatched after focus is shifted, and does not bubble.
	 */
	public static inline var BLUR:String = "blur";
	
	/**
	 * A user agent must dispatch this event when an event target
	 * is about to receive focus. This event type must be 
	 * dispatched before the element is given focus. The event
	 * target must be the element which is about to receive focus.
	 * This event type is similar to focus, but is dispatched before
	 * focus is shifted, and does bubble.
	 */
	public static inline var FOCUS_IN:String = "focusin";
	
	/**
	 * A user agent must dispatch this event when an event target is about to
	 * lose focus. This event type must be dispatched before 
	 * the element loses focus. The event target must be 
	 * the element which is about to lose focus. This event 
	 * type is similar to blur, but is dispatched before focus 
	 * is shifted, and does bubble.
	 */
	public static inline var FOCUS_OUT:String = "focusout";
	
	/**
	 * Used to identify a secondary EventTarget related to a Focus event, 
	 * depending on the type of event. For security reasons with nested
	 * browsing contexts, when tabbing into or out of a nested context,
	 * the relevant EventTarget should be null.
	 */
	public var relatedTarget(default, null):EventTarget;
	
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Initializes attributes of a FocusEvent object. 
	 * This method has the same behavior as UIEvent.initUIEvent(). 
	 * 
	 * @param	eventTypeArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	canBubbleArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	cancelableArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	detailArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	viewArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	relatedTargetArg Specifies FocusEvent.relatedTarget. This value may be null.
	 */
	public function initFocusEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, viewArg:Dynamic, detailArg:Float,relatedTargetArg:EventTarget):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initUIEvent(eventTypeArg, canBubbleArg, cancelableArg, viewArg, detailArg);
		relatedTarget = relatedTargetArg;
	}
	
}