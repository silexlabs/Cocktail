/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.keyboard.as3;

import flash.events.KeyboardEvent;
import flash.Lib;
import haxe.Log;
import cocktailCore.keyboard.abstract.AbstractKeyboard;
import cocktail.keyboard.KeyboardData;

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
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN CALLBACKS SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setOnKeyDown(value:KeyEventData->Void):KeyEventData->Void
	{
		if (value == null)
		{
			Lib.current.stage.removeEventListener(KeyboardEvent.KEY_DOWN, onNativeKeyDown);
		}
		else
		{
			//in flash keyboard event are listened from the stage to receive global 
			//keyboard event. We might evolve this features with focus management
			//eventually
			Lib.current.stage.addEventListener(KeyboardEvent.KEY_DOWN, onNativeKeyDown);
		}
		return _onKeyDown = value;
	}
	
	override private function setOnKeyUp(value:KeyEventData->Void):KeyEventData->Void
	{
		if (value == null)
		{
			Lib.current.stage.removeEventListener(KeyboardEvent.KEY_UP, onNativeKeyUp);
		}
		else
		{
			Lib.current.stage.addEventListener(KeyboardEvent.KEY_UP, onNativeKeyUp);
		}
		return _onKeyUp = value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private key utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the key that triggered the keyboard event
	 * @param	event the native key up or down event
	 * @return a sruct containing the key code and other key values
	 */
	override private function getKeyData(event:Dynamic):KeyEventData
	{
		//cast the flash KeyboardEvent
		var typedEvent:KeyboardEvent = cast(event);
		
		var key:KeyEventData = {
			value : getKeyValue(typedEvent.keyCode),
			code : typedEvent.keyCode,
			ascii : typedEvent.charCode,
			altKey : typedEvent.altKey ,
			controlKey : typedEvent.ctrlKey,
			shiftKey : typedEvent.shiftKey
		}
		
		return key;
	}
	
}