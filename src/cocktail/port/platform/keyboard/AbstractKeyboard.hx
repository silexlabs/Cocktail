/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.keyboard;

import cocktail.core.event.KeyboardEvent;
import cocktail.core.html.HTMLElement;
import haxe.Log;

/**
 * This class listens to native keyboard event
 * using the API of the current platform.
 * 
 * It then builds a cross-platform KeyboardEvent
 * from the dispatched native keyboard events,
 * and call the callback corresponding to 
 * the keyboard event type if provided
 * 
 * For instance in Flash, it listens to keyboard
 * events on the Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractKeyboard 
{
	/**
	 * The callback to call when
	 * a native key down event is dispatched
	 */
	public var onKeyDown:KeyboardEvent->Void;
	
	/**
	 * The callback to call when
	 * a native key up event is dispatched
	 */
	public var onKeyUp:KeyboardEvent->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		//starts to listen to native keyboard input
		setNativeListeners();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native keyboard event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a cross-platform key down event from
	 * the native key down event, and call
	 * the key down callback if provided
	 * 
	 * @param	event the native mouse click event
	 */
	private function onNativeKeyDown(event:Dynamic):Void
	{
		if (onKeyDown != null)
		{
			onKeyDown(getKeyData(event));
		}
	}
	
	/**
	 * same as key down event
	 */
	private function onNativeKeyUp(event:Dynamic):Void
	{
		if (onKeyUp != null)
		{
			onKeyUp(getKeyData(event));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private key utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set listeners for platform specific events
	 */
	private function setNativeListeners():Void
	{
		//abstract
	}
	
	/**
	 * Remove listeners for platform specific events
	 */
	private function removeNativeListeners():Void
	{
		//abstract
	}
	
	/**
	 * Create and return a cross-platform keyboard event
	 * from the dispatched native keyboard event
	 * 
	 * @param	event the native keyboard event
	 */
	private function getKeyData(event:Dynamic):KeyboardEvent
	{
		return null;
	}
}