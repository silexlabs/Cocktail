/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.flash_player;

import core.nativeElement.NativeElement;
import core.event.KeyboardEvent;
import flash.Lib;
import haxe.Log;
import core.keyboard.AbstractKeyboard;
import core.keyboard.KeyboardData;

/**
 * This is the flash AVM2 implementation of the keyboard abstraction.
 * Set listeners on native flash keyboard event and call the corresponding
 * callback
 * 
 * @author Yannick DOMINGUEZ
 */
class Keyboard extends AbstractKeyboard
{
	/**
	 * class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
		
		//set native Flash events
		_keyDownEvent = flash.events.KeyboardEvent.KEY_DOWN;
		_keyUpEvent = flash.events.KeyboardEvent.KEY_UP;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private key utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually remove and set listeners on the nativeElement.
	 * The listener is always removed and if the htmlElement
	 * callback is not null a new listener is set
	 */
	override private function updateListeners(keyboardEvent:String, nativeCallback:Dynamic->Void, htmlElementCallback:KeyboardEvent->Void):Void
	{
		_htmlElement.nativeElement.removeEventListener(keyboardEvent, nativeCallback);
		
		if (htmlElementCallback != null)
		{
			_htmlElement.nativeElement.addEventListener(keyboardEvent, nativeCallback);
		}
	}
	
	/**
	 * Returns the key that triggered the keyboard event
	 * @param	event the native key up or down event
	 * @return a sruct containing the key code and other key values
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
		
		var keyboardEvent:KeyboardEvent = new KeyboardEvent(eventType, _htmlElement, 0.0, typedEvent.charCode, 
		typedEvent.keyCode, typedEvent.ctrlKey, typedEvent.shiftKey, typedEvent.altKey);
		
		
		return keyboardEvent;
	}
	
}