/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.multitouch;

import cocktail.event.EventConstants;
import cocktail.event.EventTarget;
import cocktail.event.Touch;
import cocktail.event.TouchEvent;
import cocktail.event.TouchList;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.ElementRenderer;

/**
 * This class keeps track of the currently active
 * touch points, for device supporting it and use
 * these data to complete the triggered TouchEvent
 * before sending them through the DOM
 * 
 * TODO 1 : implement TOUCH_CANCEL which should be implementation
 * specific
 * 
 * @author Yannick DOMINGUEZ
 */
class MultiTouchManager 
{
	/**
	 * The currently active Touch (points
	 * touched on the screen)
	 */
	private var _touches:Array<Touch>;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		_touches = new Array<Touch>();
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_touches = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Get a TouchEvent with only partial informations (at this point the TouchEvent only
	 * contains the data of the Touch which triggered it), and complete its info using
	 * the current state of touched point on screen
	 * 
	 * @param touchEvent the TouchEvent to complete
	 * @param target the element that was touched, triggering the TouchEvent
	 */
	public function setUpTouchEvent(touchEvent:TouchEvent, target:EventTarget):Void
	{
		//get the only Touch point currently provided by the TouchEvent
		var touch:Touch = touchEvent.touches.item(0);
		
		switch (touchEvent.type)
		{
			case EventConstants.TOUCH_START:
				registerTouch(touch, touchEvent, target);
				
			case EventConstants.TOUCH_END:
				unregisterTouch(touch, touchEvent);
				
			case EventConstants.TOUCH_MOVE:
				updateTouch(touch, touchEvent);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE TOUCH METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when a new touch start (the user adds a finger on the screen). Store
	 * the new Touch object and update the TouchEvent
	 * 
	 * @param	touch the touch which juste started
	 * @param	touchEvent the incomplete TouchEvent
	 * @param	target the element that was touched
	 */
	private function registerTouch(touch:Touch, touchEvent:TouchEvent, target:EventTarget):Void
	{
		touch.target = target;
		updatePagePosition(touch);
		
		//store the new Touch
		_touches.push(touch);
		
		//update the TouchEvent
		initTouchEvent(touchEvent, getTouchesByTarget(target), new TouchList([touch]));
	}
	
	/**
	 * Called when a touch end (the user lifts a finger from the screen). Remove the
	 * Touch object corresponding to the lifted finger by retrieving it thanks to its unique
	 * ID
	 * 
	 * @param	touch the removed touch
	 * @param	touchEvent the incomplete TouchEvent
	 */
	private function unregisterTouch(touch:Touch, touchEvent:TouchEvent):Void
	{
		//retrieve the removed touch from the touch array
		var storedTouch:Touch = getTouchByIdentifier(touch.identifier);
		//update the data of the removed Touch, as it will still be available when the
		//end TouchEvent will be dispatched
		updateStoredTouch(storedTouch, touch);
		
		//TODO 2 : should send a copy of the removed Touch for this event, else it won't be in
		//the array anymore when dispatched
		
		initTouchEvent(touchEvent, getTouchesByTarget(cast(touch.target)), new TouchList([touch]));
		
		//remove the removed Touch
		_touches.remove(storedTouch);
	}
	
	/**
	 * Called when one of the active touch (finger on the screen) moves. Retrieve
	 * the moving Touch and update its data
	 * 
	 * @param	touch the Touch corresponding to the finger that was moved
	 * @param	touchEvent the incomplete TouchEvent
	 */
	private function updateTouch(touch:Touch, touchEvent:TouchEvent):Void
	{
		//retrieve the stored Touch with the unique ID 
		var storedTouch:Touch = getTouchByIdentifier(touch.identifier);
		updateStoredTouch(storedTouch, touch);
		
		initTouchEvent(touchEvent, getTouchesByTarget(cast(touch.target)), new TouchList([touch]));
	}
	
	/**
	 * Update the data from a stored touch with the data of
	 * the new dispatched touch with the same ID, corresponding
	 * to the same finger on the screen
	 */
	private function updateStoredTouch(storedTouch:Touch, touch:Touch):Void
	{
		storedTouch.clientX = touch.clientX;
		storedTouch.clientY = touch.clientY;
		storedTouch.screenX = touch.screenX;
		storedTouch.screenY = touch.screenY;
		
		updatePagePosition(storedTouch);
	}
	
	/**
	 * Update the position of the Touch relative to the document,
	 * including scrolling
	 */
	private function updatePagePosition(touch:Touch):Void
	{
		//TODO 1 : implement
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE UTILS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils shortcut method to update the data of the TouchEvent
	 * 
	 * TODO 2 : implement keyboard
	 * TODO 2 : verify bubbling and cancel
	 */
	private function initTouchEvent(touchEvent:TouchEvent, targetTouches:TouchList, changedTouches:TouchList):Void
	{
		touchEvent.initTouchEvent(touchEvent.type, true, true, null, 0.0,
		new TouchList(_touches), targetTouches, changedTouches, false, false, false, false);
	}
	
	/**
	 * Returns all the currently active touches which have the same target,
	 * meaning they corresponded to the same HTMLElement when created
	 */
	private function getTouchesByTarget(target:EventTarget):TouchList
	{
		var targetTouches:Array<Touch> = new Array<Touch>();
		
		var length:Int = _touches.length;
		for (i in 0...length)
		{
			var touch:Touch = _touches[i];
			if (touch.target == target)
			{
				targetTouches.push(touch);
			}
		}
		
		return new TouchList(targetTouches);
	}
	
	/**
	 * Retrive a currently active Touch using its unique
	 * ID. when a new native touch event is dispatched, it keeps
	 * the same ID for the same finger
	 */
	private function getTouchByIdentifier(identifier:Int):Touch
	{
		var length:Int = _touches.length;
		for (i in 0...length)
		{
			var touch:Touch = _touches[i];
			if (touch.identifier == identifier)
			{
				return touch;
			}
		}
		
		return null;
	}
}
