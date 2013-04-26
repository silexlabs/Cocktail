/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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