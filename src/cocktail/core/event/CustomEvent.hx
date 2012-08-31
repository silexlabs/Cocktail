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
 * The CustomEvent interface is the recommended interface for application-specific
 * event types. Unlike the Event interface, it allows applications to provide
 * contextual information about the event type. Application-specific
 * event types should use a prefix string on the event type name
 * to avoid clashes with future general-purpose event types.
 * To create an instance of the CustomEvent interface,
 * use the DocumentEvent.createEvent("CustomEvent") method call.
 * 
 * @author Yannick DOMINGUEZ
 */
class CustomEvent extends Event
{
	/**
	 * Specifies some detail information about the Event.
	 */
	public var detail(default, null):Dynamic;
	
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
	 * Initializes attributes of a CustomEvent object. This method has the same behavior as Event.initEvent().
	 * 
	 * @param	eventTypeArg Specifies Event.type, the name of the event type.
	 * @param	canBubbleArg Specifies Event.bubbles. This parameter overrides the intrinsic bubbling behavior of the event.
	 * @param	cancelableArg Specifies Event.cancelable. This parameter overrides the intrinsic cancelable behavior of the event.
	 * @param	detailArg Specifies CustomEvent.detail. This value may be null.
	 */
	public function initCustomEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, detailArg:Dynamic):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initEvent(eventTypeArg, canBubbleArg, cancelableArg);
		detail = detailArg;
	}
}