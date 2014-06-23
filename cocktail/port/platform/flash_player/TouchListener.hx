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
import cocktail.event.TouchEvent;
import cocktail.event.TouchList;
import cocktail.port.base.TouchListenerBase;
import cocktail.event.Touch;
import flash.Lib;
import flash.ui.Multitouch;
import flash.ui.MultitouchInputMode;
import cocktail.port.Bindings;

/**
 * This is the flash AVM2 implementation of the touch event listener.
 * Listens to flash native touch event
 * 
 * note : the Multitouch.inputMode should be set to MultiTouchInputPoint.TOUCH_POINT,
 * so that individual touch event are dispatched by flash
 * 
 * @author Yannick DOMINGUEZ
 */
class TouchListener extends TouchListenerBase
{
	/**
	 * class constructor.
	 */
	public function new(platform:Platform) 
	{
		super(platform);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private touch utils methods
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Set touch listeners on the hit testing sprite
	 * set up by the platform
	 */
	override private function setNativeListeners():Void
	{
		_platform.hitTestingSprite.addEventListener(flash.events.TouchEvent.TOUCH_BEGIN, onNativeTouchStart);
		_platform.hitTestingSprite.addEventListener(flash.events.TouchEvent.TOUCH_MOVE, onNativeTouchMove);
		_platform.hitTestingSprite.addEventListener(flash.events.TouchEvent.TOUCH_END, onNativeTouchEnd);
	}
	
	/**
	 * Remove touch listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		_platform.hitTestingSprite.removeEventListener(flash.events.TouchEvent.TOUCH_BEGIN, onNativeTouchStart);
		_platform.hitTestingSprite.removeEventListener(flash.events.TouchEvent.TOUCH_MOVE, onNativeTouchMove);
		_platform.hitTestingSprite.removeEventListener(flash.events.TouchEvent.TOUCH_END, onNativeTouchEnd);
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

		var localPoint = new flash.geom.Point(typedEvent.localX, typedEvent.localY);
		localPoint = _platform.convertToHitTestingSpriteSpace(localPoint, event.target, _platform.hitTestingSprite);
		
		var touch:Touch = new Touch();
		touch.identifier = typedEvent.touchPointID;
		touch.screenX = Math.round(localPoint.x);
		touch.screenY = Math.round(localPoint.y);
		touch.clientX = Math.round(localPoint.x);
		touch.clientY = Math.round(localPoint.y);
		touch.pageX = 0;
		touch.pageY = 0;
		
		//only init event type and the touch object at this
		//point, the event data will be completed later before
		//dispatching
		var touchEvent:TouchEvent = new TouchEvent();
		touchEvent.initTouchEvent(touchType, false, false, null, 0.0, new TouchList([touch]), null, null, false, false, false, false); 
		
		return touchEvent;
	}

 
  //////////////////////////////////////////////////////////////////////////////////////////
  // private utils method
  //////////////////////////////////////////////////////////////////////////////////////////
  

}
