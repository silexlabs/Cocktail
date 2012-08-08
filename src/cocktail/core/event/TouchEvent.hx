/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * This interface defines the touchstart, touchend, touchmove,
 * and touchcancel event types. TouchEvent objects are immutable;
 * after one is created and initialized, its attributes must not change.
 * 
 * @author Yannick DOMINGUEZ
 */
class TouchEvent extends UIEvent
{
	/**
	 * A user agent must dispatch this event type to indicate when
	 * the user places a touch point on the touch surface. The target
	 * of this event must be an Element. If the touch point is within
	 * a frame, the event should be dispatched to an element in
	 * the child browsing context of that frame. If the preventDefault 
	 * method is called on this event, it should prevent any default
	 * actions caused by any touch events associated with the same 
	 * active touch point, including mouse events or scrolling.
	 */
	public static inline var TOUCH_START:String = "touchstart";
	
	/**
	 * A user agent must dispatch this event type to indicate when the
	 * user removes a touch point from the touch surface, also
	 * including cases where the touch point physically leaves the
	 * touch surface, such as being dragged off of the screen. The
	 * target of this event must be the same Element on which
	 * the touch point started when it was first placed on the
	 * surface, even if the touch point has since moved outside the
	 * interactive area of the target element. The touch point or 
	 * points that were removed must be included in the changedTouches 
	 * attribute of the TouchEvent, and must not be included in
	 * the touches and targetTouches attributes.
	 */
	public static inline var TOUCH_END:String = "touchend";
	
	/**
	 * A user agent must dispatch this event type to indicate when
	 * the user moves a touch point along the touch surface. The
	 * target of this event must be the same Element on which
	 * the touch point started when it was first placed on the surface,
	 * even if the touch point has since moved outside the interactive
	 * area of the target element. Note that the rate at which the
	 * user agent sends touchmove events is implementation-defined,
	 * and may depend on hardware capabilities and other
	 * implementation details. If the preventDefault method is called
	 * on the first touchmove event of an active touch point, it
	 * should prevent any default action caused by any touchmove
	 * event associated with the same active touch point, such as
	 * scrolling.
	 */
	public static inline var TOUCH_MOVE:String = "touchmove";
	
	/**
	 * A user agent must dispatch this event type to indicate when a 
	 * touch point has been disrupted in an implementation-specific
	 * manner, such as a synchronous event or action originating
	 * from the UA canceling the touch, or the touch point leaving
	 * the document window into a non-document area which is capable
	 * of handling user interactions. (e.g. The UA's native user interface,
	 * plug-ins) A user agent may also dispatch this event type when
	 * the user places more touch points on the touch surface than the
	 * device or implementation is configured to store, in which case 
	 * the earliest Touch object in the TouchList should be removed. 
	 * 
	 * The target of this event must be the same Element on which the 
	 * touch point started when it was first placed on the surface,
	 * even if the touch point has since moved outside the interactive
	 * area of the target element. The touch point or points that were
	 * removed must be included in the changedTouches attribute of the
	 * TouchEvent, and must not be included in the touches and
	 * targetTouches attributes.
	 */
	public static inline var TOUCH_CANCEL:String = "touchcancel";
	
	/**
	 * a list of Touches for every point of contact currently touching the surface.
	 */
	public var touches(default, null):TouchList;
	
	/**
	 * a list of Touches for every point of contact that is touching the surface 
	 * and started on the element that is the target of the current event.
	 */
	public var targetTouches(default, null):TouchList;
	
	/**
	 * a list of Touches for every point of contact which contributed to the event.
	 * For the touchstart event this must be a list of the touch
	 * points that just became active with the current event. For the touchmove
	 * event this must be a list of the touch points that have moved since 
	 * the last event. For the touchend and touchcancel events this must 
	 * be a list of the touch points that have just been removed from the surface.
	 */
	public var changedTouches(default, null):TouchList;
	
	/**
	 * true if the alt (Alternate) key modifier
	 * is activated; otherwise false
	 */
	public var altKey(default, null):Bool;
	
	/**
	 * true if the meta (Meta) key modifier is activated; otherwise false. 
	 * On some platforms this attribute may map to a differently-named key modifier.
	 */
	public var metaKey(default, null):Bool;
	
	/**
	 * true if the ctrl (Control) key modifier is activated; otherwise false
	 */
	public var ctrlKey(default, null):Bool;
	
	/**
	 * true if the shift (Shift) key modifier is activated; otherwise false
	 */
	public var shiftKey(default, null):Bool;
	
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Initializes attributes of a TouchEvent object.
	 * This method has the same behavior as Event.initEvent().
	 */
	public function initTouchEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, viewArg:Dynamic, detailArg:Float,
	touchesArg:TouchList, targetTouchesArg:TouchList, changedTouchesArg:TouchList, altKeyArg:Bool, metaKeyArg:Bool, ctrlKeyArg:Bool,
	shiftKeyArg:Bool):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initUIEvent(eventTypeArg, canBubbleArg, cancelableArg, viewArg, detailArg);
		touches = touchesArg;
		targetTouchesArg = targetTouches;
		changedTouches = changedTouchesArg;
		altKey = altKeyArg;
		metaKey = metaKeyArg;
		ctrlKey = ctrlKeyArg;
		shiftKey = shiftKeyArg;
	}
	
}