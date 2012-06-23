/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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