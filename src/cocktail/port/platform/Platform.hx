/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform;

import cocktail.core.event.Event;
import cocktail.core.event.EventCallback;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.port.Keyboard;
import cocktail.port.Mouse;
import cocktail.port.NativeWindow;
import cocktail.core.layout.LayoutData;
import cocktail.port.TouchListener;

/**
 * This class exposes an API to access platform
 * specific inputs, such as mouse clicks, window
 * resize...
 * 
 * Hides all the platforms interface behind a common API
 * 
 * @author Yannick DOMINGUEZ
 */
class Platform
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
	 * An instance of the cross-platform class to access the native window,
	 * allowing for instance to open a new window or to listen to 
	 * resize event
	 */
	public var nativeWindow(default, null):NativeWindow;
	
	/**
	 * An access of the cross platform class used to listen to touch 
	 * events
	 */
	public var touchListener(default, null):TouchListener;
	
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
		mouse = new Mouse();
		keyboard = new Keyboard();
		nativeWindow = new NativeWindow();
		touchListener = new TouchListener();
	}
}