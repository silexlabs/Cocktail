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
 * The MouseEvent interface provides specific contextual information associated with Mouse events.
 *
 * The detail attribute inherited from UIEvent indicates the number of times a mouse button
 * has been pressed and released over the same screen location during a user action.
 * The attribute value is 1 when the user begins this action and increments by 1
 * for each full sequence of pressing and releasing. If the user moves the mouse
 * between the mousedown and mouseup the value will be set to 0, indicating
 * that no click is occurring.
 * 
 * TODO : implement
 * 
 * In the case of nested elements mouse events are always targeted at the most deeply
 * nested element. Ancestors of the targeted element may use bubbling to obtain
 * notification of mouse events which occur within its descendent elements.
 * 
 * @author Yannick DOMINGUEZ
 */
class MouseEvent extends UIEvent
{	
	/**
	 * The click event occurs when the pointing device
	 * button is clicked over an element. 
	 * A click is defined as a mousedown and mouseup
	 * over the same screen location.
	 * The sequence of these events is:
	 * mousedown
	 * mouseup
	 * click
	 */
	public static inline var CLICK:String = "click";
	
	/**
	 * The mouseup event occurs when the pointing device button is
	 * released over an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_UP:String = "mouseup";
	
	/**
	 * The mousedown event occurs when the pointing device button
	 * is pressed over an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_DOWN:String = "mousedown";
	
	/**
	 * he mouseover event occurs when the pointing device is moved
	 * onto an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_OVER:String = "mouseover";
	
	/**
	 * The mouseout event occurs when the pointing device is moved 
	 * away from an element. This event is valid for most elements.
	 */
	public static inline var MOUSE_OUT:String = "mouseout";
	
	/**
	 * The mousemove event occurs when the pointing device is moved 
	 * while it is over an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_MOVE:String = "mousemove";
	
	/**
	 * The horizontal coordinate at which the event occurred relative
	 * to the origin of the screen coordinate system.
	 */
	private var _screenX:Float;
	public var screenX(get_screenX, never):Float;
	
	/**
	 * The vertical coordinate at which the event occurred relative
	 * to the origin of the screen coordinate system.
	 */
	private var _screenY:Float;
	public var screenY(get_screenY, never):Float;
	
	/**
	 * The horizontal coordinate at which the event occurred relative
	 * to the DOM implementation's client area.
	 */
	private var _clientX:Float;
	public var clientX(get_clientX, never):Float;
	
	/**
	 * The vertical coordinate at which the event occurred 
	 * relative to the DOM implementation's client area.
	 */
	private var _clientY:Float;
	public var clientY(get_clientY, never):Float;
	
	/**
	 * Used to indicate whether the 'ctrl' key was depressed
	 * during the firing of the event.
	 */
	private var _ctrlKey:Bool;
	public var ctrlKey(get_ctrlKey, never):Bool;
	
	/**
	 * Used to indicate whether the 'shift' key was depressed
	 * during the firing of the event.
	 */
	private var _shiftKey:Bool;
	public var shiftKey(get_shiftKey, never):Bool;
	
	/**
	 * Used to indicate whether the 'alt' key was depressed during
	 * the firing of the event. On some platforms this key may map to an alternative key name.
	 */
	private var _altKey:Bool;
	public var altKey(get_altKey, null):Bool;
	
	public function new(type:String, target:HTMLElement, detail:Float, screenX:Float, screenY:Float, clientX:Float, clientY:Float, 
	ctrlKey:Bool, shiftKey:Bool, altKey:Bool) 
	{
		super(type, target, detail);
		
		_screenX = screenX;
		_screenY = screenY;
		_clientX = clientX;
		_clientY = clientY;
		_ctrlKey = ctrlKey;
		_shiftKey = shiftKey;
		_altKey = altKey;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_altKey():Bool 
	{
		return _altKey;
	}
	
	private function get_shiftKey():Bool 
	{
		return _shiftKey;
	}
	
	private function get_ctrlKey():Bool 
	{
		return _ctrlKey;
	}
	
	private function get_clientY():Float 
	{
		return _clientY;
	}
	
	private function get_clientX():Float 
	{
		return _clientX;
	}
	
	private function get_screenX():Float 
	{
		return _screenX;
	}
	
	private function get_screenY():Float 
	{
		return _screenY;
	}
	
}