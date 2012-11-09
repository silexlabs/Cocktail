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
 * The popstate event is fired in certain cases when navigating to a session history entry.
 * The PopStateEvent interface provides specific contextual information 
 * associated with popstate events. To create an instance of the 
 * PopStateEvent interface, use the DocumentEvent.createEvent("PopStateEvent")
 * method call.
 */
class PopStateEvent extends UIEvent
{
	/**
	 * the new current state
	 */
	public var state:Null<Dynamic>;
	
	public function new() 
	{
		super();
	}
	
	/**
	 * Initializes attributes of a PopStateEvent object. 
	 * This method has the same behavior as UIEvent.initUIEvent(). 
	 */
	public function initPopStateEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, viewArg:Dynamic, detailArg:Float, state:Null<Dynamic>):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initUIEvent(eventTypeArg, canBubbleArg, cancelableArg, viewArg, detailArg);
		this.state = state;
	}
	
}