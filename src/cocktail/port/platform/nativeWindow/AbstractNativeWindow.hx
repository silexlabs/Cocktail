/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.nativeWindow;
import cocktail.core.event.UIEvent;


/**
 * This class listens to native event dispatched
 * by the window of the current platform, for 
 * instance the Stage in flash
 * 
 * It then builds a cross-platform UIEvent
 * from the dispatched native events,
 * and call the callback corresponding to 
 * the keyboard event type if provided
 * 
 * It also exposes window level method such as
 * open
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractNativeWindow
{
	/**
	 * The callback to call when
	 * a native resize event is disptached
	 */
	public var onResize:UIEvent->Void;
	
	/**
	 * Height (in pixels) of the browser window viewport including,
	 * if rendered, the horizontal scrollbar.
	 */
	public var innerHeight(get_innerHeight, never):Int;
	
	/**
	 * Width (in pixels) of the browser window viewport including,
	 * if rendered, the vertical scrollbar.
	 */
	public var innerWidth(get_innerWidth, never):Int;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		//starts to listen to native input
		setNativeListeners();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open a new window using platform specific API
	 */
	public function open(url:String, name:String):Void
	{
		//abstract
	}
	
	/**
	 * Enters fullscreen mode
	 */
	public function enterFullscreen():Void
	{
		//abstract
	}
	
	/**
	 * Exit fullscreen mode
	 */
	public function exitFullscreen():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a cross-platform resize event from
	 * the native resize event, and call
	 * the resize callback if provided
	 * 
	 * @param	event the native resize event
	 */
	private function onNativeResize(event:Dynamic):Void
	{
		if (onResize != null)
		{
			onResize(getUIEvent(event));
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
	 * Create and return a cross-platform ui event
	 * from the dispatched native event
	 * 
	 * @param	event the native event
	 */
	private function getUIEvent(event:Dynamic):UIEvent
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////

	private function get_innerHeight():Int
	{
		return -1;
	}
	
	private function get_innerWidth():Int
	{
		return -1;
	}
}