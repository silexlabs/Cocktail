/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.event.KeyboardEvent;
import cocktail.core.html.HTMLElement;
import cocktail.port.Bindings;
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
class KeyboardListenerBase 
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
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		removeNativeListeners();
		_platform = null;
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
