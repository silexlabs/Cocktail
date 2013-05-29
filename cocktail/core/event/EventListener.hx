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
	public var listener(default, null):Dynamic->Void;
	
	/**
	 * The type of event this listener listens for
	 */
	public var eventType(default, null):String;
	
	/**
	 * class constructor. Init
	 * class attributes
	 */
	public function new(eventType:String, listener:Dynamic->Void, useCapture:Bool)
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
}