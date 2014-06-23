/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.event.EventConstants;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.KeyboardListenerBase;
import cocktail.event.KeyboardEvent;
import flash.Lib;
import haxe.Log;
import cocktail.port.Bindings;

/**
 * This is the flash AVM2 implementation of the keyboard event manager.
 * Listens to flash native keyboard event on the flash Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class KeyboardListener extends KeyboardListenerBase
{
	/**
	 * class constructor
	 */
	public function new(platform:Platform) 
	{
		super(platform);
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
		Lib.current.stage.removeEventListener(flash.events.KeyboardEvent.KEY_DOWN, onNativeKeyDown);
		Lib.current.stage.removeEventListener(flash.events.KeyboardEvent.KEY_UP, onNativeKeyUp);
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
				eventType = EventConstants.KEY_DOWN;
				
			case flash.events.KeyboardEvent.KEY_UP:
				eventType = EventConstants.KEY_UP;
				
			default:
				eventType = typedEvent.type;
		}
		
		//TODO : check if charcode and keycode return right values
		var keyboardEvent:KeyboardEvent = new KeyboardEvent();
		keyboardEvent.initKeyboardEvent(eventType, true, true, null, Std.string(typedEvent.charCode), Std.string(typedEvent.keyCode), 0,
		getModifersList(typedEvent), false, "");
		
		return keyboardEvent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * serialised all pressed modifiers as a white-space separated list
	 */
	private function getModifersList(keyboardEvent:flash.events.KeyboardEvent):String
	{
		var modifiersList:String = "";
		
		if (keyboardEvent.shiftKey == true)
		{
			modifiersList += "Shift ";
		}
		
		if (keyboardEvent.ctrlKey == true)
		{
			modifiersList += "Control ";
		}
		
		if (keyboardEvent.altKey == true)
		{
			modifiersList += "Alt";
		}
		
		return modifiersList; 
	}
	
}
