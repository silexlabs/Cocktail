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
 * This event is used for measuring progress
 * while a resource is loaded
 * 
 * TODO 2 : to be coherent with the other event objects,
 * this one as an init method which will become
 * obsolete with the DOM4 specification which
 * uses constructor instead.
 * 
 * @author Yannick DOMINGUEZ
 */
class ProgressEvent extends Event
{
	/**
	 * Return wether the total length of the loaded
	 * resource is known
	 */
	public var lengthComputable(default, null):Bool;
	
	/**
	 * The current amount of loaded data
	 */
	public var loaded(default, null):Float;
	
	/**
	 * The total size of the loaded resource
	 */
	public var total(default, null):Float;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		lengthComputable = false;
		loaded = 0;
		total = 0;
	}
	
	/**
	 * Init the ProgressEvent, similar to initEvent
	 * on Event
	 */
	public function initProgressEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, lengthComputableArg:Bool,
	loadedArg:Float, totalArg:Float):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initEvent(eventTypeArg, canBubbleArg, cancelableArg);
		
		lengthComputable = lengthComputableArg;
		loaded = loadedArg;
		total = totalArg;
	}
	
}