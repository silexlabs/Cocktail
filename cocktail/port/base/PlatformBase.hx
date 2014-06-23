/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.KeyboardEvent;
import cocktail.event.MouseEvent;
import cocktail.event.UIEvent;
import cocktail.event.WheelEvent;
import cocktail.core.stacking.StackingContext;
import cocktail.port.Bindings;
import cocktail.geom.GeomData;

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
	public var keyboardListener(default, null):KeyboardListener;
	
	/**
	 * An instance of the cross-platform mouse class, used to listen
	 * to mouse input
	 */
	public var mouseListener(default, null):MouseListener;
	
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
	 * Height (in pixels) of the viewport. Might be either, the
	 * same as viewport.width if set explicitely or is dependant
	 * on the platform
	 */
	public var viewportHeight(get_viewportHeight, never):Float;
	
	/**
	 * Same as above for viewport's width
	 */
	public var viewportWidth(get_viewportWidth, never):Float;
	
	/**
	 * Same as above for viewport's x
	 */
	public var viewportX(get_viewportX, never):Float;
	
	/**
	 * Same as above for viewport's y
	 */
	public var viewportY(get_viewportY, never):Float;
	
	/**
	 * the viewport of the current document, in the space
	 * of its native container (for instance in a browser, it is
	 * the browser tab, for a desktop application, it is the window
	 * of the application).
	 * 
	 * The viewport is initially null.
	 * When the viewport is null, it has the following consequence :
	 * The native platform will determine the viewport, for instance in flash
	 * it will use the stage width and height, and will use the top left of the 
	 * flash movie as viewport
	 */
	public var viewport(default, set_viewport):RectangleVO;
	
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
		
		mouseListener = new MouseListener(cast(this));
		keyboardListener = new KeyboardListener(cast(this));
		touchListener = new TouchListener(cast(this));
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		removeNativeListeners();
		
		mouseListener.dispose();
		mouseListener = null;
		keyboardListener.dispose();
		keyboardListener = null;
		touchListener.dispose();
		touchListener = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
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
	 * return the platform layer used as the root
	 * of the document
	 */
	public function getRootPlatformLayer():PlatformLayer
	{
		return null;
	}
	
	/**
	 * Return the platform layer used as the top of the
	 * native layer tree
	 */
	public function getTopPlatformLayer():PlatformLayer
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the height of the platform viewport
	 * (for instance the stage height in flash)
	 */
	private function getNativeViewportHeight():Float
	{
		return -1;
	}
	
	/**
	 * Same as above for viewport width
	 */
	private function getNativeViewportWidth():Float
	{
		return -1;
	}
	
	/**
	 * Same as above for viewport x
	 */
	private function getNativeViewportX():Float
	{
		return -1;
	}
	
	/**
	 * Same as above for viewport y
	 */
	private function getNativeViewportY():Float
	{
		return -1;
	}
	
	/**
	 * Called after the viewport was updated.
	 * Perform all native api calls required
	 * to update the viewport
	 */
	private function onViewportUpdate():Void
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
	 * simulate a platform resize event, used
	 * when the viewport is updated
	 */
	private function triggerResizeEvent():Void
	{
		var resizeEvent:UIEvent = new UIEvent();
		resizeEvent.initUIEvent(EventConstants.RESIZE, false, false, null, 0.0);
		
		if (onResize != null)
		{
			onResize(resizeEvent);
		}
	}
	
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

	/**
	 * update viewport, then trigger fake
	 * resize event
	 */
	private function set_viewport(value:RectangleVO):RectangleVO
	{
		viewport = value;
		onViewportUpdate();
		triggerResizeEvent();
		
		return viewport = value;
	}
	
	private function get_viewportHeight():Float
	{
		if (viewport != null)
		{
			return viewport.height;
		}
		else
		{
			return getNativeViewportHeight();
		}
	}
	
	private function get_viewportWidth():Float
	{
		if (viewport != null)
		{
			return viewport.width;
		}
		else
		{
			return getNativeViewportWidth();
		}
	}
	
	private function get_viewportX():Float
	{
		if (viewport != null)
		{
			return viewport.x;
		}
		else
		{
			return getNativeViewportX();
		}
	}
	
	private function get_viewportY():Float
	{
		if (viewport != null)
		{
			return viewport.y;
		}
		else
		{
			return getNativeViewportY();
		}
	}
}
