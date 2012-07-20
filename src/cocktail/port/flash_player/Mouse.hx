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
import cocktail.port.NativeBitmapData;
import cocktail.port.platform.mouse.AbstractMouse;
import cocktail.core.style.StyleData;
import flash.display.BitmapData;
import flash.Lib;
import cocktail.core.geom.GeomData;
import flash.Vector;
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
	// OVERRIDEN MOUSE CURSOR METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the mouse cursor using flash mouse API
	 */
	override public function setMouseCursor(cursor:Cursor):Void
	{
		//not supported by nme
		#if flash9
		
		switch(cursor)
		{
			case Cursor.cssAuto:
				flash.ui.Mouse.cursor = flash.ui.MouseCursor.AUTO;
				
			case Cursor.cssDefault:
				flash.ui.Mouse.cursor = flash.ui.MouseCursor.ARROW;
			
			case Cursor.pointer:
				flash.ui.Mouse.cursor = flash.ui.MouseCursor.BUTTON;	
				
			case Cursor.text:
				flash.ui.Mouse.cursor = flash.ui.MouseCursor.IBEAM;		
			
			//cross-hair don't exist in flash	
			case Cursor.crosshair:
				flash.ui.Mouse.cursor = flash.ui.MouseCursor.AUTO;		
		}
		
		#end
	}
	
	/**
	 * TODO 2 : re-implement once asset manager is developed
	 * 
	 * Set a bitmap as mouse cursor using flash mouse API
	 */
	private function setBitmapCursor(nativeBitmapData:NativeBitmapData, hotSpot:PointData):Void
	{
		//don't work for nme
		#if flash9
		
		//init the hotSpot if null
		//to the top left of the cursor
		if (hotSpot == null)
		{
			hotSpot = { x:0.0, y:0.0 };
		}
		
		//draw the image dom element onto a 32x32 transparent bitmap data
		var mouseCursorBitmapData:BitmapData = new BitmapData(32, 32, true, 0x00FFFFFF);
		mouseCursorBitmapData.draw(nativeBitmapData);
		
		//set the flash mouse cursor data with the drawn bitmap data
		//and the cursor hot spot
		var mouseCursorData:flash.ui.MouseCursorData = new flash.ui.MouseCursorData();
		mouseCursorData.data = new Vector<BitmapData>(1, true);
		mouseCursorData.data[0] = mouseCursorBitmapData;
		mouseCursorData.hotSpot = new flash.geom.Point(hotSpot.x, hotSpot.y);
		
		//generate a random ID for the new cursor
		var randomID:String = Std.string(Math.round(Math.random() * 1000));
		
		//register the cursor and set it
		flash.ui.Mouse.registerCursor(randomID, mouseCursorData);
		flash.ui.Mouse.cursor = randomID;
		
		//show the cursor if it was previously hidden
		flash.ui.Mouse.show();
		
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Set mouse listeners on the stage
	 */
	override private function setNativeListeners():Void
	{
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

		//TODO 5 : screenX should be relative to sreen top left, but how to get this in flash ? use JavaScript ?
		mouseEvent.initMouseEvent(eventType, true, true, null, 0.0, Math.round(typedEvent.stageX), Math.round(typedEvent.stageY),
		Math.round(typedEvent.stageX), Math.round(typedEvent.stageY), typedEvent.ctrlKey, typedEvent.altKey, typedEvent.shiftKey, false, 0, null);

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

		wheelEvent.initWheelEvent(WheelEvent.MOUSE_WHEEL, true, true, null, 0.0, Math.round(typedEvent.stageX), Math.round(typedEvent.stageY),
		Math.round(typedEvent.stageX), Math.round(typedEvent.stageY), 0, null, "", 0, typedEvent.delta, 0, 0 );
		
		return wheelEvent;
	}
}