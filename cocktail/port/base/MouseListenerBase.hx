/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.core.config.Config;
import cocktail.event.Event;
import cocktail.event.MouseEvent;
import cocktail.event.WheelEvent;
import cocktail.core.layout.LayoutData;
import cocktail.port.Bindings;
import cocktail.css.CSSStyleData;

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
class MouseListenerBase
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
	 * The callback to call when a native mouse leave
	 * event is dispatched, which is dispatched when
	 * the mouse leaves the window of the document
	 */
	public var onMouseLeave:Event->Void;
	
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
		
		//starts to listen to native mouse events
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
	// MOUSE CURSOR METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the mouse cursor using platform API
	 */
	public function setMouseCursor(cursor:CSSPropertyValue):Void
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
	
	/**
	 * same as mouse down, for a mouse leave event
	 */
	private function onNativeMouseLeave(event:Dynamic):Void
	{
		if (onMouseLeave != null)
		{
			onMouseLeave(getEvent(event));
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
}
