/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;
import cocktail.core.html.HTMLElement;

/**
 * The UIEvent interface provides specific contextual information
 * associated with User Interface events.
 * 
 * @author Yannick DOMINGUEZ
 */
class UIEvent extends Event
{
	public static inline var SCROLL:String = "scroll";
	
	/**
	 * Specifies some detail information about the Event,
	 * depending on the type of event.
	 */ 
	private var _detail:Float;
	public var detail(get_detail, set_detail):Float;
	
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Initializes attributes of an UIEvent object.
	 * This method has the same behavior as Event.initEvent().
	 * 
	 * TODO : missing arguments
	 * 
	 * TODO : should call initEvent, same for inheriting classes
	 * 
	 * @param	eventTypeArg Specifies Event.type, the name of the event type.
	 * @param	canBubbleArg Specifies Event.bubbles. This parameter overrides the intrinsic bubbling behavior of the event.
	 * @param	cancelableArg Specifies Event.cancelable. This parameter overrides the intrinsic cancelable behavior of the event.
	 * @param	detailArg Specifies UIEvent.detail
	 */
	public function initUIEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, detailArg:Float):Void
	{
		_type = eventTypeArg;
		_bubbles = canBubbleArg;
		_cancelable = cancelableArg;
		_detail = detailArg;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_detail():Float 
	{
		return _detail;
	}
	
	private function set_detail(value:Float):Float 
	{
		return _detail = value;
	}
}