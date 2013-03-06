/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.core.event.Event;
import cocktail.core.event.EventCallback;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.stacking.StackingContext;
import cocktail.port.Keyboard;
import cocktail.port.Mouse;
import cocktail.port.NativeLayer;
import cocktail.port.TouchListener;

/**
 * This class exposes an API to access platform
 * specific inputs, such as mouse clicks, window
 * resize...
 * 
 * Hides all the platforms interface behind a common API.
 * 
 * It is overrided by each supported platform
 * 
 * @author Yannick DOMINGUEZ
 */
class PlatformBase
{
	/**
	 * An instance of the cross-platform keyboard class, used to listen
	 * to key down and up event
	 */
	public var keyboard(default, null):Keyboard;
	
	/**
	 * An instance of the cross-platform mouse class, used to listen
	 * to mouse input
	 */
	public var mouse(default, null):Mouse;
	
	/**
	 * An access of the cross platform class used to listen to touch 
	 * events
	 */
	public var touchListener(default, null):TouchListener;
	
	/**
	 * The callback to call when
	 * a native resize event is dispatched
	 */
	public var onResize:UIEvent->Void;
	
	/**
	 * The callback called when the screen orientation change,
	 * most likely on a handeld or tablet device
	 */
	public var onOrientationChange:Event->Void;
	
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR & INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor.
	 * 
	 * Init cross platform classes
	 */
	public function new() 
	{
		//starts to listen to native platform input
		setNativeListeners();
		
		mouse = new Mouse(cast(this));
		keyboard = new Keyboard(cast(this));
		touchListener = new TouchListener(cast(this));
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
	
	/**
	 * Return the root native layer of the target native
	 * display list
	 */
	public function getInitialNativeLayer():NativeLayer
	{
		return null;
	}
	
	/**
	 * Called after the hit testing bounds of each
	 * elements in the document is ready, gives the 
	 * platform an opportunity to update its native
	 * hit testing bounds if needed
	 */
	public function updateHitTestingBounds(stackingContext:StackingContext):Void
	{
		
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
	
	/**
	 * Create a cross-platform orientation change event from
	 * the native orientation change event, and call 
	 * the orientation change callback if provided
	 * 
	 * @param	event the native orientation change event
	 */
	private function onNativeOrientationChange(event:Dynamic):Void
	{
		if (onOrientationChange != null)
		{
			onOrientationChange(getEvent(event));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private utils methods
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