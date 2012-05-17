/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
	private var _relatedTarget:EventTarget;
	public var relatedTarget(get_relatedTarget, never):EventTarget;
	
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
	 * TODO : missing arguments
	 * 
	 * @param	eventTypeArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	canBubbleArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	cancelableArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	detailArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	relatedTargetArg Specifies FocusEvent.relatedTarget. This value may be null.
	 */
	public function initFocusEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, detailArg:Float,relatedTargetArg:EventTarget):Void
	{
		_type = eventTypeArg;
		_bubbles = canBubbleArg;
		_cancelable = cancelableArg;
		_detail = detailArg;
		_relatedTarget = relatedTargetArg;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_relatedTarget():EventTarget
	{
		return _relatedTarget;
	}
	
}