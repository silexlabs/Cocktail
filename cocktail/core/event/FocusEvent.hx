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