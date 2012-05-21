/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.event.MouseEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.mouse.AbstractMouse;
import flash.Lib;
import haxe.Log;

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
		Lib.current.stage.addEventListener(flash.events.MouseEvent.CLICK, onNativeClick);
		Lib.current.stage.addEventListener(flash.events.MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		Lib.current.stage.addEventListener(flash.events.MouseEvent.MOUSE_UP, onNativeMouseUp);
		Lib.current.stage.addEventListener(flash.events.MouseEvent.MOUSE_MOVE, onNativeMouseMove);
		Lib.current.stage.addEventListener(flash.events.MouseEvent.MOUSE_WHEEL, onNativeMouseWheel);
	}
	
	/**
	 * Remove mouse listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		Lib.current.stage.removeEventListener(flash.events.MouseEvent.CLICK, onNativeClick);
		Lib.current.stage.removeEventListener(flash.events.MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		Lib.current.stage.removeEventListener(flash.events.MouseEvent.MOUSE_UP, onNativeMouseUp);
		Lib.current.stage.removeEventListener(flash.events.MouseEvent.MOUSE_MOVE, onNativeMouseMove);
		Lib.current.stage.removeEventListener(flash.events.MouseEvent.MOUSE_WHEEL, onNativeMouseWheel);
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
		
		
		var mouseEvent:MouseEvent = new MouseEvent();

		//TODO : screenX should be relative to sreen top left, but how to get this in flash ? use JavaScript ?
		mouseEvent.initMouseEvent(eventType, true, true, null, 0.0, typedEvent.stageX, typedEvent.stageY,
		typedEvent.stageX, typedEvent.stageY, typedEvent.ctrlKey, typedEvent.altKey, typedEvent.shiftKey, false, 0, null);
		
		return mouseEvent;
	}
	
	/**
	 * Create and return a cross-platform wheel event
	 * form the flash mouse wheel event
	 * 
	 * @param	event the native mouse wheel event
	 */
	override private function getWheelEvent(event:Dynamic):WheelEvent
	{
		//cast as flash mouse event
		var typedEvent:flash.events.MouseEvent = cast(event);
		
		var wheelEvent:WheelEvent = new WheelEvent();

		wheelEvent.initWheelEvent(WheelEvent.MOUSE_WHEEL, true, true, null, 0.0, typedEvent.stageX, typedEvent.stageY,
		typedEvent.stageX, typedEvent.stageY, 0, null, "", 0, typedEvent.delta, 0, 0 );
		
		return wheelEvent;
	}
}