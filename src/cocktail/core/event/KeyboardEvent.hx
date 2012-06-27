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
	/**
	 * This set of constants must be used to indicate the location 
	 * of a key on the device. In case a DOM implementation wishes
	 * to provide a new location information, 
	 * a value different from the following constant values must be used.
	 */
	
	 /**
	  * The key activation must not be distinguished 
	  * as the left or right version of the key,
	  * and did not originate from the numeric
	  * keypad (or did not originate with a virtual 
	  * key corresponding to the numeric keypad). 
	  */
	public static inline var DOM_KEY_LOCATION_STANDARD:Int = 0x00;
	
	/**
	 * The key activated originated from the left 
	 * key location (there is more than one possible location for this key)
	 */
	public static inline var DOM_KEY_LOCATION_LEFT:Int = 0x01;
	
	/**
	 * The key activation originalted from the right key 
	 * location (there is more than one possible location for this key)
	 */
	public static inline var DOM_KEY_LOCATION_RIGHT:Int = 0x02;
	
	/**
	 * The key activation originated on the numeric keypad
	 * or with a virtual key corresponding to the numeric keypad
	 */
	public static inline var DOM_KEY_LOCATION_NUMPAD:Int = 0x03;
	
	/**
	 * The key activation originated on a mobile device,
	 * either on a physical keypad or a virtual keyboard
	 */
	public static inline var DOM_KEY_LOCATION_MOBILE:Int = 0x04;
	
	/**
	 * The key activation originated on a
	 * game controller or a joystick on a mobile device
	 */
	public static inline var DOM_KEY_LOCATION_JOYSTICK:Int = 0x05;
	
	
	//TODO 3 : add keypress
	public static inline var KEY_DOWN:String = "keydown";
	
	public static inline var KEY_UP:String = "keyup";
	
	/**
	 * char holds the character value of the key pressed.
	 * 
	 * TODO 5 : should be named char but prevent cpp
	 * compilation
	 */
	public var keyChar(default, null):String;
	
	/**
	 * key holds the key value of the key pressed.
	 */
	public var key(default, null):String;
	
	/**
	 * The location attribute contains an indication of the 
	 * location of the key on the device, as described in
	 * Keyboard event types.
	 */
	public var location(default, null):Int;
	
	/**
	 * The locale attribute contains a 
	 * BCP-47 tag indicating the locale for which the keyboard
	 * originating the event is configured, e.g. "en-US".
	 * May be the empty string when inapplicable or unknown,
	 * e.g. when this information is not exposed by the underlying platform.
	 */
	public var locale(default, null):String;
	
	/**
	 * true if the 'Ctrl' (control) key modifier was active.
	 */
	public var ctrlKey(default, null):Bool;
	
	/**
	 * true if the shift (Shift) key modifier was active.
	 */
	public var shiftKey(default, null):Bool;
	
	/**
	 * true if the 'Alt' (alternative) or 'Option' key modifier was active.
	 */
	public var altKey(default, null):Bool;
	
	/**
	 * true if the meta (Meta) key modifier was active. 
	 */ 
	public var metaKey(default, null):Bool;
	
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
	public var repeat(default, null):Bool;
	
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
	 * @param	eventTypeArg Specifies Event.type, the name of the event type.
	 * @param	canBubbleArg Specifies Event.bubbles. This parameter overrides the intrinsic bubbling behavior of the event.
	 * @param	cancelableArg Specifies Event.cancelable. This parameter overrides the intrinsic cancelable behavior of the event.
	 * @param	detailArg Specifies UIEvent.detail
	 */
	public function initKeyboardEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, viewArg:Dynamic, charArg:String,
	keyArg:String, locationArg:Int, modifiersListArg:String, repeatArg:Bool, localeArg:String):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initUIEvent(eventTypeArg, canBubbleArg, cancelableArg, viewArg, 0);
		keyChar = charArg;
		key = keyArg;
		repeat = repeatArg;
		location = locationArg;
		locale = localeArg;
	}
}