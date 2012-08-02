/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.mouse;

import cocktail.core.event.MouseEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.style.StyleData;

/**
 * This class listens to native mouse event
 * using the API of the current platform.
 * 
 * It then builds a cross-platform MouseEvent
 * from the dispatched native mouse events,
 * and call the callback corresponding to 
 * the mouse event type if provided
 * 
 * For instance in Flash, it listens to mouse
 * events on the Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractMouse 
{
	/** 
	 * The callback to call when
	 * a native mouse down evednt is dispatched
	 */
	public var onMouseDown:MouseEvent->Void;
	
	/**
	 * The callback to call when 
	 * a native mouse up event is dispatched
	 */
	public var onMouseUp:MouseEvent->Void;
	
	/**
	 * The callback to call when a native
	 * mouse move event is dispatched
	 */
	public var onMouseMove:MouseEvent->Void;
	
	/**
	 * The callback to call when the mouse wheel
	 * is rotated
	 */
	public var onMouseWheel:WheelEvent->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		//starts to listen to native mouse events
		setNativeListeners();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE CURSOR METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the mouse cursor using platform API
	 */
	public function setMouseCursor(cursor:Cursor):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native mouse event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a cross-platform mouse down event from
	 * the native mouse down event, and call
	 * the mouse down callback if provided
	 * 
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
	 * same as mouse down
	 */
	private function onNativeMouseUp(event:Dynamic):Void
	{
		if (onMouseUp != null)
		{
			onMouseUp(getMouseEvent(event));
		}
	}
	
	/**
	 * same as mouse down
	 */
	private function onNativeMouseMove(event:Dynamic):Void
	{
		if (onMouseMove != null)
		{
			onMouseMove(getMouseEvent(event));
		}
	}
	
	/**
	 * same as mouse down, for a wheel event
	 */
	private function onNativeMouseWheel(event:Dynamic):Void
	{
		if (onMouseWheel != null)
		{
			onMouseWheel(getWheelEvent(event));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set listener for platform specific events
	 */
	private function setNativeListeners():Void
	{
		//abstract
	}
	
	/**
	 * Set listeners of platform specific events
	 */
	private function removeNativeListeners():Void
	{
		//abstract
	}
	
	/**
	 * Create and return a cross-platform mouse event
	 * from the dispatched native mouse event
	 * 
	 * @param	event the native mouse event
	 */
	private function getMouseEvent(event:Dynamic):MouseEvent
	{
		return null;
	}
	
	/**
	 * Create and return a cross-platform wheel event
	 * from the dispatched native mouse wheel event
	 * 
	 * @param	event the native mouse wheel event
	 */
	private function getWheelEvent(event:Dynamic):WheelEvent
	{
		return null;
	}
}