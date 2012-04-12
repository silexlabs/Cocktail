/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.browser;

import cocktail.core.dom.Document;
import cocktail.core.event.Event;
import cocktail.core.window.AbstractWindow;
import js.Lib;

/**
 * This is the browser implementation of the
 * Window object
 * 
 * @author Yannick DOMINGUEZ
 */
class Window extends AbstractWindow
{
	/**
	 * class constructor
	 */
	public function new(document:Document = null) 
	{
		super(document);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a resize callback is set, listen for resize events
	 * on the native JavaScript Window object
	 */
	override private function set_onResize(value:Event->Void):Event->Void
	{
		if (value == null)
		{
			untyped Lib.window.removeEventListener("resize", onNativeResize);
		}
		else
		{
			untyped Lib.window.addEventListener("resize", onNativeResize);
		}
		
		return _onResize = value;
	}
	
	/**
	 * Return the JavaScript Window height
	 */
	override private function get_innerHeight():Int
	{
		return Lib.window.innerHeight;
	}
	
	/**
	 * Return the JavaScript Window width
	 */
	override private function get_innerWidth():Int
	{
		return Lib.window.innerWidth;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * called when a resize event is triggered on the 
	 * JavaScript Window
	 */
	private function onNativeResize(event:Dynamic):Void
	{
		if (_onResize != null)
		{
			_onResize(new Event(Event.RESIZE, this));
		}
	}
	
}