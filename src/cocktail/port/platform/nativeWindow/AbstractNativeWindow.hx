/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.nativeWindow;
import cocktail.core.event.Event;
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
	 * The callback called when entering/exiting fullscreen mode
	 */
	public var onFullScreenChange:Event->Void;
	
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
	
	/**
	 * Wether fullscreen is allowed
	 * @return
	 */
	public function fullScreenEnabled():Bool
	{
		return false;
	}
	
	/**
	 * Wether fullscreen mode is activated
	 */
	public function fullscreen():Bool
	{
		return false;
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
	
	/**
	 * Create a cross-platform full screen change event from
	 * the native full screen change event, and call
	 * the full screen change callback if provided
	 * 
	 * @param	event the native full sreen change event
	 */
	private function onNativeFullScreenChange(event:Dynamic):Void
	{
		if (onFullScreenChange != null)
		{
			onFullScreenChange(getEvent(event));
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
	
	/**
	 * Create and return a cross-platform event
	 * from the dispatched native event
	 * 
	 * @param	event the native event
	 */
	private function getEvent(event:Dynamic):Event
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