/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.keyboard.js;

import haxe.Log;
import js.Lib;
import cocktailCore.keyboard.abstract.AbstractKeyboard;
import cocktail.keyboard.KeyboardData;

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
			untyped Lib.document.removeEventListener("keydown", onNativeKeyDown);
		}
		else
		{
			//add listener on the Document to receive global keyboard events
			//eventually might be applied at element level to add focus
			//management with keyboard
			untyped Lib.document.addEventListener("keydown", onNativeKeyDown);
		}
		return _onKeyDown = value;
	}
	
	override private function setOnKeyUp(value:KeyEventData->Void):KeyEventData->Void
	{
		if (value == null)
		{
			untyped Lib.document.removeEventListener("keyup", onNativeKeyUp);
		}
		else
		{
			untyped Lib.document.addEventListener("keyup", onNativeKeyUp);
		}
		return _onKeyUp = value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private key utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the key that triggered the keyboard event
	 * @param	event the native key up or down event
	 * @return a sruct containing the key code and ascii value
	 */
	override private function getKeyData(event:Dynamic):KeyEventData
	{
		var key:KeyEventData = {
			value : getKeyValue(event.keyCode),
			code : event.keyCode,
			ascii : event.charCode,
			altKey : event.altKey ,
			controlKey : event.ctrlKey,
			shiftKey : event.shiftKey
		}
		
		return key;
	}
	
}