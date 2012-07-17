/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
import cocktail.core.style.StyleData;

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
	}
}