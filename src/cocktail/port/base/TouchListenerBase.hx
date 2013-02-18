/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.base;

import cocktail.core.event.TouchEvent;
import cocktail.core.event.EventData;
import cocktail.port.Platform;

/**
 * This class listens to native touch event
 * using the API of the current platform.
 * 
 * It then builds a cross-platform TouchEvent object
 * form the touch and call the related callback
 * if provided
 * 
 * For instance in Flash, it listens to native touch
 * events on the Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class TouchListenerBase
{
	/**
	 * The callback called when a touch start
	 * event is dispatched
	 */
	public var onTouchStart:TouchEvent->Void;
	
	/**
	 * The callback called when a touch end
	 * event is dispatched
	 */
	public var onTouchEnd:TouchEvent->Void;
	
	/**
	 * The callback called when a touch move event
	 * is dispatched
	 */
	public var onTouchMove:TouchEvent->Void;
	
	/**
	 * Hold a ref to the owning platform, might
	 * be needed for some platform specific
	 * operations
	 */
	private var _platform:Platform;
	
	/**
	 * class constructor
	 */
	public function new(platform:Platform)
	{
		_platform = platform;
		
		//starts to listen to native keyboard input
		setNativeListeners();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native touch event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a cross-platform TouchEvent from
	 * the native touch start event, and call
	 * the touch start callback if provided
	 * 
	 * @param	event the native touch event
	 */
	private function onNativeTouchStart(event:Dynamic):Void
	{
		if (onTouchStart != null)
		{
			onTouchStart(getTouchEvent(event));
		}
	}
	
	/**
	 * same as touch start event
	 */
	private function onNativeTouchEnd(event:Dynamic):Void
	{
		if (onTouchEnd != null)
		{
			onTouchEnd(getTouchEvent(event));
		}
	}

	/**
	 * same as touch start event
	 */
	private function onNativeTouchMove(event:Dynamic):Void
	{
		if (onTouchMove != null)
		{
			onTouchMove(getTouchEvent(event));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private touch utils methods
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
	 * Return a cross-platform Touch object from a 
	 * native touch event
	 */
	private function getTouchEvent(event:Dynamic):TouchEvent
	{
		return null;
	}
}