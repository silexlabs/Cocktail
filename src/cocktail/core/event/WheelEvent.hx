/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * The WheelEvent interface provides specific contextual information associated with omnidirectional mouse wheel events.
 * To create an instance of the WheelEvent interface, use the DocumentEvent.createEvent("WheelEvent") method call.
 * 
 * @author Yannick DOMINGUEZ
 */
class WheelEvent extends MouseEvent
{
	/**
	 * The distance the wheel has rotated around the y-axis.
	 */
	private var _deltaY:Float;
	public var deltaY(get_deltaY, never):Float;
	
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
	 * Initializes attributes of a WheelEvent object. 
	 * This method has the same behavior as MouseEvent.initMouseEvent().
	 */
	public function initWheelEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, detailArg:Float,
	screenXArg:Float, screenYArg:Float, clientXArg:Float, clientYArg:Float, ctrlKeyArg:Bool, altKeyArg:Bool,
	shiftKeyArg:Bool, deltaYArg:Float):Void
	{
		initMouseEvent(eventTypeArg, canBubbleArg, cancelableArg, detailArg, screenXArg, screenYArg, clientXArg, clientYArg,
		ctrlKeyArg, shiftKeyArg, altKeyArg);
		_deltaY = deltaYArg;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_deltaY():Float
	{
		return _deltaY;
	}
	
}