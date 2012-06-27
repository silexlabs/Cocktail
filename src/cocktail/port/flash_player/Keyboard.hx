/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.html.HTMLElement;
import cocktail.port.NativeElement;
import cocktail.core.event.KeyboardEvent;
import cocktail.port.platform.keyboard.AbstractKeyboard;
import flash.Lib;
import haxe.Log;

/**
 * This is the flash AVM2 implementation of the keyboard event manager.
 * Listens to flash native keyboard event on the flash Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class Keyboard extends AbstractKeyboard
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private key utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set keyboard listeners on the stage
	 */
	override private function setNativeListeners():Void
	{
		Lib.current.stage.addEventListener(flash.events.KeyboardEvent.KEY_DOWN, onNativeKeyDown);
		Lib.current.stage.addEventListener(flash.events.KeyboardEvent.KEY_UP, onNativeKeyUp);
	}
	
	/**
	 * REmove keyboard listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		Lib.current.removeEventListener(flash.events.KeyboardEvent.KEY_DOWN, onNativeKeyDown);
		Lib.current.removeEventListener(flash.events.KeyboardEvent.KEY_UP, onNativeKeyUp);
	}
	
	/**
	 * Create and return a cross-platform keyboard event
	 * form the flash keyboard event
	 * 
	 * @param	event the native mouse event
	 */
	override private function getKeyData(event:Dynamic):KeyboardEvent
	{
		//cast the flash KeyboardEvent
		var typedEvent:flash.events.KeyboardEvent = cast(event);
		
		var eventType:String;
		
		switch (typedEvent.type)
		{
			case flash.events.KeyboardEvent.KEY_DOWN:
				eventType = KeyboardEvent.KEY_DOWN;
				
			case flash.events.KeyboardEvent.KEY_UP:
				eventType = KeyboardEvent.KEY_UP;
				
			default:
				eventType = typedEvent.type;
		}
		
		//TODO : check if charcode and keycode return right values
		var keyboardEvent:KeyboardEvent = new KeyboardEvent();
		keyboardEvent.initKeyboardEvent(eventType, true, true, null, Std.string(typedEvent.charCode), Std.string(typedEvent.keyCode), 0,
		"",	false, "");
		
		return keyboardEvent;
	}
	
}