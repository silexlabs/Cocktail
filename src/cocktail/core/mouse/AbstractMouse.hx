/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.mouse;

import cocktail.core.html.HTMLElement;
import cocktail.core.NativeElement;
import cocktail.core.event.MouseEvent;

import cocktail.core.mouse.MouseData;

/**
 * This package is made to offer a simple API for mouse interactions.
 *
 * This class is the base class for mouse interaction. It listens to 
 * mouse events thanks to runtime specific implementations and calls
 * the appropriate registered callbacks.
 * 
 * It takes a target HTMLElement objects onto which the mouse
 * event will be listened.
 * 
 * TODO : should now be simplified now that events are only listened
 * by HTMLDocument.
 * Add an InputManager ?
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractMouse 
{
	/**The callback to call when
	 * the native element is clicked
	 */
	private var _onClick:MouseEvent->Void;
	public var onClick(get_onClick, set_onClick):MouseEvent->Void;
	
	/** 
	 * The callback to call when
	 * the mouse is pressed on the native element
	 */
	private var _onMouseDown:MouseEvent->Void;
	public var onMouseDown(getOnMouseDown, setOnMouseDown):MouseEvent->Void;
	
	/**
	 * The callback to call when 
	 * the native element is released
	 */
	private var _onMouseUp:MouseEvent->Void;
	public var onMouseUp(getOnMouseUp, setOnMouseUp):MouseEvent->Void;
	
	/**
	 * The callback to call when the mouse move while
	 * over the native element
	 */
	private var _onMouseMove:MouseEvent->Void;
	public var onMouseMove(getOnMouseMove, setOnMouseMove):MouseEvent->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		setNativeListeners();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native mouse event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Calls the onClick callback with the current mouse data
	 * @param	event the native mouse down event
	 */
	private function onNativeClick(event:Dynamic):Void
	{
		if (onClick != null)
		{
			onClick(getMouseEvent(event));
		}
	}
	
	/**
	 * Calls the onMouseDown callback with the current mouse data
	 * @param	event the native mouse down event
	 */
	private function onNativeMouseDown(event:Dynamic):Void
	{
		if (onMouseDown != null)
		{
			onMouseDown(getMouseEvent(event));
		}
	}
	
	/**
	 * Calls the onMouseUp callback with the current mouse data
	 * @param	event the native mouse up event
	 */
	private function onNativeMouseUp(event:Dynamic):Void
	{
		if (onMouseUp != null)
		{
			onMouseUp(getMouseEvent(event));
		}
	}
	
	/**
	 * Calls the onMouseMove callback with the current mouse data
	 * @param	event the native mouse move event
	 */
	private function onNativeMouseMove(event:Dynamic):Void
	{
		if (onMouseMove != null)
		{
			onMouseMove(getMouseEvent(event));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : doc
	private function setNativeListeners():Void
	{
		//abstract
	}
	
	private function removeNativeListeners():Void
	{
		//abstract
	}
	
	/**
	 * Returns the current mouse data
	 * @param	event the native mouse event
	 * @return a sruct containing the mouse current data
	 */
	private function getMouseEvent(event:Dynamic):MouseEvent
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACK SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_onClick(value:MouseEvent->Void):MouseEvent->Void
	{
		return this._onClick = value;
	}
	
	private function get_onClick():MouseEvent->Void
	{
		return this._onClick;
	}
	
	private function setOnMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		return this._onMouseDown = value;
	}
	
	private function getOnMouseDown():MouseEvent->Void
	{
		return this._onMouseDown;
	}
	
	private function setOnMouseUp(value:MouseEvent->Void):MouseEvent->Void
	{
		return this._onMouseUp = value;
	}
	
	private function getOnMouseUp():MouseEvent->Void
	{
		return this._onMouseUp;
	}
	
	private function setOnMouseMove(value:MouseEvent->Void):MouseEvent->Void
	{
		return this._onMouseMove = value;
	}
	
	private function getOnMouseMove():MouseEvent->Void
	{
		return this._onMouseMove;
	}
	
}