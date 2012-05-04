/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.keyboard;

import cocktail.core.event.KeyboardEvent;
import cocktail.core.html.HTMLElement;
import haxe.Log;
import cocktail.core.NativeElement;

/**
 * This package is made to offer a simple API for keyboard interactions.
 *
 * We choose not to use a singleton pattern or static class and found
 * a simple way for exposing the keyboard state and for calling a custom callback function.
 * 
 * The class is to be instantiated, and then you can set the instance attributes 
 * onKeyDown and onKeyUp to your callbacks.
 * 
 * This is a base abstract class, implemented for each runtime
 * 
 * TODO : should now be simplified now that events are only listened
 * by HTMLDocument
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
	private var _onKeyDown:KeyboardEvent->Void;
	public var onKeyDown(getOnKeyDown, setOnKeyDown):KeyboardEvent->Void;
	
	/**
	 * The callback to call when 
	 * a key is released
	 */
	private var _onKeyUp:KeyboardEvent->Void;
	public var onKeyUp(getOnKeyUp, setOnKeyUp):KeyboardEvent->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		setNativeListeners();
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
	
	private function setOnKeyDown(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		return _onKeyDown = value;
	}
	
	private function getOnKeyDown():KeyboardEvent->Void
	{
		return _onKeyDown;
	}
	
	private function setOnKeyUp(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		return _onKeyUp = value;
	}
	
	private function getOnKeyUp():KeyboardEvent->Void
	{
		return _onKeyUp;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private key utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : doc
	private function setNativeListeners():Void
	{
		//abstract
	}
	
	private function removeNativeListeners():Void
	{
		//abstract
	}
	
	/**
	 * Returns the key that triggered the keyboard event
	 * @param	event the native key up or down event
	 * @return a sruct containing the key code and ascii value
	 */
	private function getKeyData(event:Dynamic):KeyboardEvent
	{
		return null;
	}
}