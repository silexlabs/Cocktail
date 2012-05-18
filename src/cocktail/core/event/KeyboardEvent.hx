/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

import cocktail.core.html.HTMLElement;

/**
 * The KeyboardEvent interface provides specific contextual information associated with
 * keyboard devices. Each keyboard event references a key using a value.
 * Keyboard events are commonly directed at the element that has the focus.
 * 
 * The KeyboardEvent interface provides convenient attributes for some common
 * modifiers keys: KeyboardEvent.ctrlKey, KeyboardEvent.shiftKey, KeyboardEvent.altKey,
 * KeyboardEvent.metaKey. These attributes are equivalent to using the method
 * KeyboardEvent.getModifierState(keyArg) with 'Control', 'Shift', 'Alt', or 'Meta' respectively.
 * 
 * @author Yannick DOMINGUEZ
 */
class KeyboardEvent extends UIEvent
{
	
	//TODO : add keypress
	public static inline var KEY_DOWN:String = "keydown";
	
	public static inline var KEY_UP:String = "keyup";
	
	/**
	 * char holds the character value of the key pressed.
	 * 
	 * TODO : should be named char but prevent cpp
	 * compilation
	 */
	private var _keyChar:String;
	public var keyChar(get_keyChar, never):String;
	
	/**
	 * key holds the key value of the key pressed.
	 */
	private var _key:String;
	public var key(get_key, never):String;
	
	/**
	 * true if the 'Ctrl' (control) key modifier was active.
	 */
	private var _ctrlKey:Bool;
	public var ctrlKey(get_ctrlKey, never):Bool;
	
	/**
	 * true if the shift (Shift) key modifier was active.
	 */
	private var _shiftKey:Bool;
	public var shiftKey(get_shiftKey, never):Bool;
	
	/**
	 * true if the 'Alt' (alternative) or 'Option' key modifier was active.
	 */
	private var _altKey:Bool;
	public var altKey(get_altKey, never):Bool;
	
	/**
	 * true if the key has been pressed in a sustained manner.
	 * Holding down a key must result in the repeating the events 
	 * keydown, keypress (when supported by the user agent), and 
	 * textinput (when the keypress results in text input) in this order,
	 * at a rate determined by the system configuration.
	 * 
	 * For mobile devices which have long-key-press behavior,
	 * the first key event with a repeat attribute value of 'true'
	 * must serve as an indication of a long-key-press. The length of
	 * time that the key must be pressed in order to begin repeating
	 * is configuration-dependent.
	 */
	private var _repeat:Bool;
	public var repeat(get_repeat, never):Bool;
	
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The KeyboardEvent interface provides specific contextual information associated with
	 * keyboard devices. Each keyboard event references a key using a value. Keyboard events
	 * are commonly directed at the element that has the focus.The KeyboardEvent interface
	 * provides convenient attributes for some common modifiers keys: KeyboardEvent.ctrlKey,
	 * KeyboardEvent.shiftKey, KeyboardEvent.altKey, KeyboardEvent.metaKey.
	 * 
	 * These attributes are equivalent to using the method KeyboardEvent.getModifierState(keyArg)
	 * with 'Control', 'Shift', 'Alt', or 'Meta' respectively.
	 * 
	 * To create an instance of the KeyboardEvent interface, use the
	 * DocumentEvent.createEvent("KeyboardEvent") method call.
	 * 
	 * TODO : missing arguments
	 * 
	 * @param	eventTypeArg Specifies Event.type, the name of the event type.
	 * @param	canBubbleArg Specifies Event.bubbles. This parameter overrides the intrinsic bubbling behavior of the event.
	 * @param	cancelableArg Specifies Event.cancelable. This parameter overrides the intrinsic cancelable behavior of the event.
	 * @param	detailArg Specifies UIEvent.detail
	 */
	public function initKeyboardEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, charArg:String,
	keyArg:String, repeat:Bool):Void
	{
		//can't alter event after it has been dispatched
		if (_dispatched == true)
		{
			return;
		}
		
		initUIEvent(eventTypeArg, canBubbleArg, cancelableArg, 0);
		_keyChar = charArg;
		_key = keyArg;
		_repeat = repeat;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_altKey():Bool 
	{
		return _altKey;
	}
	
	private function get_shiftKey():Bool 
	{
		return _shiftKey;
	}
	
	private function get_ctrlKey():Bool 
	{
		return _ctrlKey;
	}
	
	private function get_keyChar():String 
	{
		return _keyChar;
	}
	
	private function get_key():String 
	{
		return _key;
	}
	
	private function get_repeat():Bool
	{
		return _repeat;
	}
	
	
	
}