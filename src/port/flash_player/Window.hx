/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.flash_player;

import core.dom.Document;
import core.window.AbstractWindow;
import core.event.Event;
import flash.Lib;

/**
 * This is the implementation of the 
 * Window object for the flash player
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
	 * When a resize callback is set, listen to resize event
	 * on the flash Stage
	 */
	override private function set_onResize(value:Event->Void):Event->Void
	{
		if (value == null)
		{
			Lib.current.stage.removeEventListener(flash.events.Event.RESIZE, onNativeResize);
		}
		else
		{
			Lib.current.stage.addEventListener(flash.events.Event.RESIZE, onNativeResize);
		}
		
		return _onResize = value;
	}
	
	/**
	 * Return the flash Stage height
	 */
	override private function get_innerHeight():Int
	{
		return Lib.current.stage.stageHeight;
	}
	
	/**
	 * Return the flash Stage width
	 */
	override private function get_innerWidth():Int
	{
		return Lib.current.stage.stageWidth;
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when flash Stage is resized
	 */
	private function onNativeResize(event:Dynamic):Void
	{
		if (_onResize != null)
		{
			_onResize(new Event(Event.RESIZE, this));
		}
	}
	
}