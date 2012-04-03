/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.browser;

import cocktail.core.NativeElement;
import cocktail.core.event.KeyboardEvent;
import haxe.Log;
import js.Lib;
import cocktail.core.keyboard.AbstractKeyboard;
import cocktail.core.keyboard.KeyboardData;

/**
 * This is the JavaScript implementation of the keyboard abstraction.
 * Set listeners on native javascript keyboard event and call the
 * corresponding callbacks
 * 
 * @author Yannick DOMINGUEZ
 */
class Keyboard extends AbstractKeyboard
{
	/**
	 * native keyboard JavaScript events
	 */
	private static inline var KEY_DOWN_EVENT:String = "keydown";
	
	private static inline var KEY_UP_EVENT:String = "keyup";
	
	/**
	 * class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
		
		//set native JS events
		_keyDownEvent = KEY_DOWN_EVENT;
		_keyUpEvent = KEY_UP_EVENT;
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
		untyped _htmlElement.nativeElement.removeEventListener(keyboardEvent, nativeCallback);
		
		if (htmlElementCallback != null)
		{
			untyped _htmlElement.nativeElement.addEventListener(keyboardEvent, nativeCallback);
		}
	}
	
	/**
	 * Returns the key that triggered the keyboard event
	 * @param	event the native key up or down event
	 * @return a sruct containing the key code and ascii value
	 */
	override private function getKeyData(event:Dynamic):KeyboardEvent
	{
		var eventType:String;
		
		switch (event.type)
		{
			case KEY_DOWN_EVENT:
				eventType = KeyboardEvent.KEY_DOWN;
				
			case KEY_UP_EVENT:
				eventType = KeyboardEvent.KEY_UP;
				
			default:
				eventType = event.type;	
		}
		
		var keyboardEvent:KeyboardEvent = new KeyboardEvent(eventType, _htmlElement, 0.0, event.charCode, 
		event.keyCode, event.ctrlKey, event.shiftKey, event.altKey);
		
	
		
		return keyboardEvent;
	}
	
}