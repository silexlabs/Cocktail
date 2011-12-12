/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.keyboard.abstract;

import haxe.Log;
import cocktail.nativeElement.NativeElement;
import cocktail.keyboard.KeyboardData;

/**
 * This package is made to offer a simple API for keyboard interactions.
 *
 * We choose not to use a singleton pattern or static class and found
 * a simple way for exposing the keyboard state and for calling a custom callback function.
 * 
 * The class is to be instantiated, and then you can set the instance attributes 
 * onKeyDown and onKeyUp to your callbacks. These callbacks will receive a Key
 * object with the key code and modifier key state as a parameter.
 * 
 * This is a base abstract class, implemented for each runtime
 * 
 * @author a.hoyau [at] silexlabs.org
 * @author Yannick DOMINGUEZ
 */
class AbstractKeyboard 
{
	/**
	 * The callback to call when
	 * a key is pressed
	 */
	private var _onKeyDown:KeyEventData->Void;
	public var onKeyDown(getOnKeyDown, setOnKeyDown):KeyEventData->Void;
	
	/**
	 * The callback to call when 
	 * a key is released
	 */
	private var _onKeyUp:KeyEventData->Void;
	public var onKeyUp(getOnKeyUp, setOnKeyUp):KeyEventData->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{

	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native keyboard event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Calls the onKeyDown callback with the pressed key data
	 * @param	event the native key down event
	 */
	private function onNativeKeyDown(event:Dynamic):Void
	{
		if (onKeyDown != null)
		{
			onKeyDown(getKeyData(event));
		}
	}
	
	/**
	 * Calls the onKeyUp callback with the released
	 * key data
	 * @param	event the native key up event
	 */
	private function onNativeKeyUp(event:Dynamic):Void
	{
		if (onKeyUp != null)
		{
			onKeyUp(getKeyData(event));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACKS SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setOnKeyDown(value:KeyEventData->Void):KeyEventData->Void
	{
		return _onKeyDown = value;
	}
	
	private function getOnKeyDown():KeyEventData->Void
	{
		return _onKeyDown;
	}
	
	private function setOnKeyUp(value:KeyEventData->Void):KeyEventData->Void
	{
		return _onKeyUp = value;
	}
	
	private function getOnKeyUp():KeyEventData->Void
	{
		return _onKeyUp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private key utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the key that triggered the keyboard event
	 * @param	event the native key up or down event
	 * @return a sruct containing the key code and ascii value
	 */
	private function getKeyData(event:Dynamic):KeyEventData
	{
		return null;
	}
	
	/**
	 * Return a key enum value from a key code
	 * @param	keyCode the target key code
	 * @return a key enum value. Default to "unknown" if the
	 * key isn't listed in the enum values
	 */
	private function getKeyValue(keyCode:Int):KeyboardKeyValue
	{
		var keyboardKeyValue:KeyboardKeyValue = unknown;
		
		switch (keyCode)
		{
			case 65:
				keyboardKeyValue = a;
				
			case 66:
				keyboardKeyValue = b;
				
			case 67:
				keyboardKeyValue = c;
				
			case 68:
				keyboardKeyValue = d;		
				
			case 69:
				keyboardKeyValue = e;
				
			case 70:
				keyboardKeyValue = f;
				
			case 71:
				keyboardKeyValue = g;
				
			case 72:
				keyboardKeyValue = h;
				
			case 73:
				keyboardKeyValue = i;
			
			case 74:
				keyboardKeyValue = j;
				
			case 75:
				keyboardKeyValue = k;
				
			case 76:
				keyboardKeyValue = l;
				
			case 77:
				keyboardKeyValue = m;
				
			case 78:
				keyboardKeyValue = n;
				
			case 79:
				keyboardKeyValue = o;
				
			case 80:
				keyboardKeyValue = p;
				
			case 81:
				keyboardKeyValue = q;
				
			case 82:
				keyboardKeyValue = r;
				
			case 83:
				keyboardKeyValue = s;
			
			case 84:
				keyboardKeyValue = t;
			
			case 85:
				keyboardKeyValue = u;
				
			case 86:
				keyboardKeyValue = v;
				
			case 87:
				keyboardKeyValue = w;
				
			case 88:
				keyboardKeyValue = x;
				
			case 89:
				keyboardKeyValue = y;
				
			case 90:
				keyboardKeyValue = z;
			
			case 8:
				keyboardKeyValue = backSpace;
				
			case 20:
				keyboardKeyValue = capsLock;
				
			case 17:
				keyboardKeyValue = control;
				
			case 46:
				keyboardKeyValue = del;
				
			case 40:
				keyboardKeyValue = down;
				
			case 35:
				keyboardKeyValue = end;
			
			case 13:
				keyboardKeyValue = enter;
				
			case 27:
				keyboardKeyValue = escape;
			
			case 112:
				keyboardKeyValue = F1;
			
			case 121:
				keyboardKeyValue = F10;
				
			case 122:
				keyboardKeyValue = F11;
				
			case 123:
				keyboardKeyValue = F12;
				
			case 124:
				keyboardKeyValue = F13;
			
			case 125:
				keyboardKeyValue = F14;
				
			case 126:
				keyboardKeyValue = F15;
				
			case 113:
				keyboardKeyValue = F2;
				
			case 114:
				keyboardKeyValue = F3;
				
			case 115:
				keyboardKeyValue = F4;
				
			case 116:
				keyboardKeyValue = F5;
				
			case 117:
				keyboardKeyValue = F6;
				
			case 118:
				keyboardKeyValue = F7;
				
			case 119:
				keyboardKeyValue = F8;
				
			case 120:
				keyboardKeyValue = F9;
			
			case 36:
				keyboardKeyValue = home;
				
			case 45:
				keyboardKeyValue = insert;
				
			case 37:
				keyboardKeyValue = left;
				
			case 96:
				keyboardKeyValue = numpad0;
				
			case 97:
				keyboardKeyValue = numpad1;
				
			case 98:
				keyboardKeyValue = numpad2;
			
			case 99:
				keyboardKeyValue = numpad3;
				
			case 100:
				keyboardKeyValue = numpad4;
				
			case 101:
				keyboardKeyValue = numpad5;
				
			case 102:
				keyboardKeyValue = numpad6;
			
			case 103:
				keyboardKeyValue = numpad7;
			
			case 104:
				keyboardKeyValue = numpad8;
				
			case 105:
				keyboardKeyValue = numpad9;
				
			case 107:
				keyboardKeyValue = numpadAdd;
			
			case 108:
				keyboardKeyValue = numpadEnter;
			
			case 110:
				keyboardKeyValue = numpadDecimal;
			
			case 111:
				keyboardKeyValue = numpadDivide;
				
			case 106:
				keyboardKeyValue = numpadMultiply;
				
			case 109:
				keyboardKeyValue = numpadSubstract;
				
			case 34:
				keyboardKeyValue = pageDown;
			
			case 33:
				keyboardKeyValue = pageUp;
				
			case 39:
				keyboardKeyValue = right;
				
			case 16:
				keyboardKeyValue = shift;
			
			case 32:
				keyboardKeyValue = space;
				
			case 9:
				keyboardKeyValue = tab;
				
			case 38:
				keyboardKeyValue = up;
				
			default:
				keyboardKeyValue = unknown;
		}
		
		return keyboardKeyValue;
	}
}