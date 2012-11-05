/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.flash_player;

import cocktail.core.event.EventConstants;
import cocktail.core.event.TouchEvent;
import cocktail.core.event.TouchList;
import cocktail.port.base.TouchListenerBase;
import cocktail.core.event.EventData;
import flash.Lib;
import flash.ui.Multitouch;
import flash.ui.MultitouchInputMode;

/**
 * This is the flash AVM2 implementation of the touch event listener.
 * Listens to flash native touch event on the flash Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class TouchListener extends TouchListenerBase
{
	/**
	 * class constructor.
	 */
	public function new() 
	{
		super();
		
		//must active the input only mode in flash to receive low level
		//touch input instead of gesture
		Multitouch.inputMode = MultitouchInputMode.TOUCH_POINT;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private touch utils methods
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Set touch listeners on the stage
	 */
	override private function setNativeListeners():Void
	{
		Lib.current.stage.addEventListener(flash.events.TouchEvent.TOUCH_BEGIN, onNativeTouchStart);
		Lib.current.stage.addEventListener(flash.events.TouchEvent.TOUCH_MOVE, onNativeTouchMove);
		Lib.current.stage.addEventListener(flash.events.TouchEvent.TOUCH_END, onNativeTouchEnd);
	}
	
	/**
	 * Remove touch listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		Lib.current.stage.removeEventListener(flash.events.TouchEvent.TOUCH_BEGIN, onNativeTouchStart);
		Lib.current.stage.removeEventListener(flash.events.TouchEvent.TOUCH_MOVE, onNativeTouchMove);
		Lib.current.stage.removeEventListener(flash.events.TouchEvent.TOUCH_END, onNativeTouchEnd);
	}
	
	/**
	 * Create and return a cross-platform TouchEvent
	 * from the flash touch event
	 * 
	 * @param	event the native touch event
	 */
	override private function getTouchEvent(event:Dynamic):TouchEvent
	{
		//cast as flash touch event
		var typedEvent:flash.events.TouchEvent = cast(event);
		
		var touchType:String;
		
		switch (typedEvent.type)
		{
			case flash.events.TouchEvent.TOUCH_BEGIN:
				touchType = EventConstants.TOUCH_START;
				
			case flash.events.TouchEvent.TOUCH_END:
				touchType = EventConstants.TOUCH_END;
				
			case flash.events.TouchEvent.TOUCH_MOVE:
				touchType = EventConstants.TOUCH_MOVE;	
				
			default:
				touchType = typedEvent.type;	
		}
		
		var touch:Touch = {
			identifier:typedEvent.touchPointID,
			target:null,
			screenX:Math.round(typedEvent.stageX),
			screenY:Math.round(typedEvent.stageY),
			clientX:Math.round(typedEvent.stageX),
			clientY:Math.round(typedEvent.stageY),
			pageX:0,
			pageY:0
		}
		
		//only init event type and the touch object at this
		//point, the event data will be completed later before
		//dispatching
		var touchEvent:TouchEvent = new TouchEvent();
		touchEvent.initTouchEvent(touchType, false, false, null, 0.0, new TouchList([touch]), null, null, false, false, false, false); 
		
		return touchEvent;
	}
}