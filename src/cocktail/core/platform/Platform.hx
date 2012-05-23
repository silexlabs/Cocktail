/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.platform;

import cocktail.core.event.EventCallback;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.Keyboard;
import cocktail.core.Mouse;
import cocktail.core.NativeWindow;

/**
 * This class exposes an API to access platform
 * specific inputs, such as mouse clicks, window
 * resize...
 * 
 * Hides all the platforms interface behind a common API
 * 
 * TODO : makes for a lot of boiler-plate and repeated code, extend
 * this class instead of having lot of classes by composition ?
 * 
 * TODO : add method to set/get platform mouse cursor
 * 
 * @author Yannick DOMINGUEZ
 */
class Platform extends EventCallback
{

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
	 * An instance of the cross-platform keyboard class, used to listen
	 * to key down and up event
	 */
	private var _keyboard:Keyboard;
	
	/**
	 * An instance of the cross-platform mouse class, used to listen
	 * to mouse input
	 */
	private var _mouse:Mouse;
	
	/**
	 * An instance of the cross-platform class to access the native window,
	 * allowing for instance to open a new window or to listen to 
	 * resize event
	 */
	private var _nativeWindow:NativeWindow;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR & INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		initKeyboardListeners();
		initMouseListeners();
		initNativeWindowListners();
	}
	
	/**
	 * init mouse listeners
	 */
	private function initMouseListeners():Void
	{
		_mouse = new Mouse();
		_mouse.onMouseDown = dispatchMouseEvent;
		_mouse.onMouseUp = dispatchMouseEvent;
		_mouse.onMouseMove = dispatchMouseEvent;
		_mouse.onClick = dispatchMouseEvent;
		_mouse.onMouseWheel = dispatchMouseWheelEvent;
	}
	
	/**
	 * init keyboard listeners
	 */
	private function initKeyboardListeners():Void
	{
		_keyboard = new Keyboard();
		_keyboard.onKeyDown = dispatchKeyboardEvent;
		_keyboard.onKeyUp = dispatchKeyboardEvent;
	}
	
	/**
	 * Init listening to platform UI event
	 */
	private function initNativeWindowListners():Void
	{
		_nativeWindow = new NativeWindow();
		_nativeWindow.onResize = dispatchUIEvent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC PLATFORM METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Creates a new secondary browser window and loads the referenced resource.
	 * 
	 * TODO : this is a partial implementation for now, should return
	 * the created window and allow parameters
	 */
	public function open(url:String, name:String):Void
	{
		_nativeWindow.open(url, name);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PLATFORM CALLBACKS
	// Send a cross-platform event from a native platform event
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function dispatchMouseEvent(mouseEvent:MouseEvent):Void
	{
		switch(mouseEvent.type)
		{
			case MouseEvent.CLICK:
				if (_onClick != null)
				{
					_onClick(mouseEvent);
				}
				
			case MouseEvent.MOUSE_DOWN:
				if (_onMouseDown != null)
				{
					_onMouseDown(mouseEvent);
				}
				
			case MouseEvent.MOUSE_MOVE:
				if (_onMouseMove != null)
				{
					_onMouseMove(mouseEvent);
				}
				
			case MouseEvent.MOUSE_UP:
				if (_onMouseUp != null)
				{
					_onMouseUp(mouseEvent);
				}		
		}
	}
	
	private function dispatchMouseWheelEvent(mouseWheelEvent:WheelEvent):Void
	{
		if (_onMouseWheel != null)
		{
			_onMouseWheel(mouseWheelEvent);
		}
	}
	
	private function dispatchKeyboardEvent(keyboardEvent:KeyboardEvent):Void
	{
		switch (keyboardEvent.type)
		{
			case KeyboardEvent.KEY_DOWN:
				if (_onKeyDown != null)
				{
					_onKeyDown(keyboardEvent);
				}
				
			case KeyboardEvent.KEY_UP:
				if (_onKeyUp != null)
				{
					_onKeyUp(keyboardEvent);
				}	
		}
		
	}
	
	private function dispatchUIEvent(uiEvent:UIEvent):Void
	{
		if (_onResize != null)
		{
			_onResize(uiEvent);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PLATFORM GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_innerHeight():Int
	{
		return _nativeWindow.innerHeight;
	}
	
	private function get_innerWidth():Int
	{
		return _nativeWindow.innerWidth;
	}
	
}