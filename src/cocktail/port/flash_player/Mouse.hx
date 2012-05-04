/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.event.MouseEvent;
import cocktail.core.html.HTMLElement;
import cocktail.core.mouse.AbstractMouse;
import cocktail.core.NativeElement;
import flash.Lib;

import cocktail.core.mouse.MouseData;

/**
 * This is the flash AVM2 implementation of the mouse event manager.
 * Listens to flash native mouse event on the flash Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class Mouse extends AbstractMouse
{
	
	/**
	 * class constructor.
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Set mouse listeners on the stage
	 */
	override private function setNativeListeners():Void
	{
		Lib.current.addEventListener(flash.events.MouseEvent.CLICK, onNativeClick);
		Lib.current.addEventListener(flash.events.MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		Lib.current.addEventListener(flash.events.MouseEvent.MOUSE_UP, onNativeMouseUp);
		Lib.current.addEventListener(flash.events.MouseEvent.MOUSE_MOVE, onNativeMouseMove);
	}
	
	/**
	 * Remove mouse listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		Lib.current.removeEventListener(flash.events.MouseEvent.CLICK, onNativeClick);
		Lib.current.removeEventListener(flash.events.MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		Lib.current.removeEventListener(flash.events.MouseEvent.MOUSE_UP, onNativeMouseUp);
		Lib.current.removeEventListener(flash.events.MouseEvent.MOUSE_MOVE, onNativeMouseMove);
	}
	
	/**
	 * Create and return a cross-platform mouse event
	 * form the flash mouse event
	 * 
	 * @param	event the native mouse event
	 */
	override private function getMouseEvent(event:Dynamic):MouseEvent
	{
		//cast as flash mouse event
		var typedEvent:flash.events.MouseEvent = cast(event);
		
		var eventType:String;
		
		switch (typedEvent.type)
		{
			case flash.events.MouseEvent.CLICK:
				eventType = MouseEvent.CLICK;
			
			case flash.events.MouseEvent.MOUSE_DOWN:
				eventType = MouseEvent.MOUSE_DOWN;
				
			case flash.events.MouseEvent.MOUSE_UP:
				eventType = MouseEvent.MOUSE_UP;
				
			case flash.events.MouseEvent.MOUSE_MOVE:
				eventType = MouseEvent.MOUSE_MOVE;	
				
			default:
				eventType = typedEvent.type;	
		}
		
		//TODO : the target is now null, should be determined by HTMLDocument
		var mouseEvent:MouseEvent = new MouseEvent(eventType, null, 0.0, typedEvent.stageX, typedEvent.stageY,
		typedEvent.localX, typedEvent.localY, typedEvent.ctrlKey, typedEvent.shiftKey, typedEvent.altKey);
		
		return mouseEvent;
	}
}