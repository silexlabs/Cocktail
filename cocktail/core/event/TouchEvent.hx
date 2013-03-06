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