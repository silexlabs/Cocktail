/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.MouseEvent;
import cocktail.event.WheelEvent;
import cocktail.port.base.MouseListenerBase;
import cocktail.port.Bindings;
import cocktail.core.layout.LayoutData;
import flash.display.BitmapData;
import flash.display.DisplayObject;
import flash.display.DisplayObjectContainer;
import flash.geom.Point;
import flash.Lib;
import cocktail.geom.GeomData;
import flash.Vector;
import cocktail.css.CSSStyleData;

/**
 * This is the flash AVM2 implementation of the mouse event manager.
 * Listens to flash native mouse event
 * 
 * @author Yannick DOMINGUEZ
 */
class MouseListener extends MouseListenerBase
{
	/**
	 * class constructor.
	 */
	public function new(platform:Platform) 
	{
		super(platform);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE CURSOR METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the mouse cursor using flash mouse API
	 */
	override public function setMouseCursor(cursor:CSSPropertyValue):Void
	{
		//not supported by openfl
		#if flash
		
		switch(cursor)
		{
			case KEYWORD(value):
				switch(value)
				{
					case AUTO:
						flash.ui.Mouse.cursor = flash.ui.MouseCursor.AUTO;
						
					case DEFAULT:
						flash.ui.Mouse.cursor = flash.ui.MouseCursor.ARROW;
					
					case POINTER:
						flash.ui.Mouse.cursor = flash.ui.MouseCursor.BUTTON;	
						
					case TEXT:
						flash.ui.Mouse.cursor = flash.ui.MouseCursor.IBEAM;		
					
					//cross-hair don't exist in flash	
					case CROSSHAIR:
						flash.ui.Mouse.cursor = flash.ui.MouseCursor.AUTO;		
						
					default:
						throw 'Illegal keyword value for cursor style';
				}
				
			case URL(value):
				
			default:
				throw 'Illegal value for cursor style';
			
			
		}
		
		#end
	}
	
	/**
	 * TODO 2 : re-implement once asset manager is developed
	 * 
	 * Set a bitmap as mouse cursor using flash mouse API
	 */
	private function setBitmapCursor(nativeBitmapData:NativeBitmapData, hotSpot:PointVO):Void
	{
		//don't work for openfl
		#if (flash && !openfl)
		
		//init the hotSpot if null
		//to the top left of the cursor
		if (hotSpot == null)
		{
			hotSpot = new PointVO(0.0, 0.0);
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
	 * Set mouse listeners on the hit testing sprite set
	 * up for the platform
	 */
	override private function setNativeListeners():Void
	{
		_platform.hitTestingSprite.addEventListener(flash.events.MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		_platform.hitTestingSprite.addEventListener(flash.events.MouseEvent.MOUSE_UP, onNativeMouseUp);
		_platform.hitTestingSprite.addEventListener(flash.events.MouseEvent.MOUSE_MOVE, onNativeMouseMove);
		_platform.hitTestingSprite.addEventListener(flash.events.MouseEvent.MOUSE_WHEEL, onNativeMouseWheel);
		
		//when either mouse exist stage flash or hit testing boundaries, it is considered to have left the document
		_platform.hitTestingSprite.addEventListener(flash.events.MouseEvent.MOUSE_OUT, onNativeMouseLeave);
		Lib.current.stage.addEventListener(flash.events.Event.MOUSE_LEAVE , onNativeMouseLeave);
	}
	
	/**
	 * Remove mouse listeners
	 */
	override private function removeNativeListeners():Void
	{
		_platform.hitTestingSprite.removeEventListener(flash.events.MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		_platform.hitTestingSprite.removeEventListener(flash.events.MouseEvent.MOUSE_UP, onNativeMouseUp);
		_platform.hitTestingSprite.removeEventListener(flash.events.MouseEvent.MOUSE_MOVE, onNativeMouseMove);
		_platform.hitTestingSprite.removeEventListener(flash.events.MouseEvent.MOUSE_WHEEL, onNativeMouseWheel);
		
		_platform.hitTestingSprite.removeEventListener(flash.events.MouseEvent.MOUSE_OUT, onNativeMouseLeave);
		Lib.current.stage.removeEventListener(flash.events.Event.MOUSE_LEAVE , onNativeMouseLeave);
	}
	
	/**
	 * Create and return a cross-platform mouse event
	 * from the flash mouse event
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
				eventType = EventConstants.MOUSE_DOWN;
				
			case flash.events.MouseEvent.MOUSE_UP:
				eventType = EventConstants.MOUSE_UP;
				
			case flash.events.MouseEvent.MOUSE_MOVE:
				eventType = EventConstants.MOUSE_MOVE;	
				
			default:
				eventType = typedEvent.type;	
		}
		
		var mouseEvent:MouseEvent = new MouseEvent();
		
		var localPoint:Point = new Point(typedEvent.localX, typedEvent.localY);
		localPoint = _platform.convertToHitTestingSpriteSpace(localPoint, event.target, _platform.hitTestingSprite);
		
		//use local x and y for mouse event, as they should be relative to hit testing sprite which represents
		//the viewport of the document
		mouseEvent.initMouseEvent(eventType, true, true, null, 0.0, Math.round(localPoint.x), Math.round(localPoint.y),
		Math.round(localPoint.x), Math.round(localPoint.y), typedEvent.ctrlKey, typedEvent.altKey, typedEvent.shiftKey, false, 0, null);

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
		var offset = Lib.current.localToGlobal(new flash.geom.Point());

		wheelEvent.initWheelEvent(EventConstants.MOUSE_WHEEL, true, true, null, 0.0, Math.round(typedEvent.stageX - offset.x), Math.round(typedEvent.stageY - offset.y),
		Math.round(typedEvent.stageX - offset.x), Math.round(typedEvent.stageY - offset.y), 0, null, "", 0, typedEvent.delta, 0, 0 );


		return wheelEvent;
	}
	
	/**
	 * Create and return a cross-platform event
	 * form the flash event
	 * 
	 * @param	event the native event
	 */
	override private function getEvent(event:Dynamic):Event
	{
		//cast as flash event
		var typedEvent:flash.events.Event = cast(event);
		
		var event:Event = new Event();
		event.initEvent(EventConstants.MOUSE_LEAVE, true, false);
		
		return event;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// private utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
}
