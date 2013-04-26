/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.event;
import cocktail.core.html.HTMLElement;

/**
 * The MouseEvent interface provides specific contextual information associated with Mouse events.
 *
 * The detail attribute inherited from UIEvent indicates the number of times a mouse button
 * has been pressed and released over the same screen location during a user action.
 * The attribute value is 1 when the user begins this action and increments by 1
 * for each full sequence of pressing and releasing. If the user moves the mouse
 * between the mousedown and mouseup the value will be set to 0, indicating
 * that no click is occurring.
 * 
 * In the case of nested elements mouse events are always targeted at the most deeply
 * nested element. Ancestors of the targeted element may use bubbling to obtain
 * notification of mouse events which occur within its descendent elements.
 * 
 * @author Yannick DOMINGUEZ
 */
class MouseEvent extends UIEvent
{	
	/**
	 * The horizontal coordinate at which the event occurred relative
	 * to the origin of the screen coordinate system.
	 */
	public var screenX(default, null):Int;
	
	/**
	 * The vertical coordinate at which the event occurred relative
	 * to the origin of the screen coordinate system.
	 */
	public var screenY(default, null):Int;
	
	/**
	 * The horizontal coordinate at which the event occurred relative
	 * to the DOM implementation's client area.
	 */
	public var clientX(default, null):Int;
	
	/**
	 * The vertical coordinate at which the event occurred 
	 * relative to the DOM implementation's client area.
	 */
	public var clientY(default, null):Int;
	
	/**
	 * Used to indicate whether the 'ctrl' key was depressed
	 * during the firing of the event.
	 */
	public var ctrlKey(default, null):Bool;
	
	/**
	 * Used to indicate whether the 'shift' key was depressed
	 * during the firing of the event.
	 */
	public var shiftKey(default, null):Bool;
	
	/**
	 * Used to indicate whether the 'alt' key was depressed during
	 * the firing of the event. On some platforms this key may map to an alternative key name.
	 */
	public var altKey(default, null):Bool;
	
	/**
	 * Refer to the KeyboardEvent.metaKey attribute.
	 */
	public var metaKey(default, null):Bool;
	
	/**
	 * During mouse events caused by the depression or release of a mouse button,
	 * button must be used to indicate which pointer device button changed state.
	 * The value of the MouseEvent.button attribute must be as follows:
		 * 
		 * 0 must indicate the primary button of the device (in general, the left
		 * button or the only button on single-button devices,
		 * used to activate a user interface control or select text).
		 * 
		 * 1 must indicate the auxiliary button (in general,
		 * the middle button, often combined with a mouse wheel).
		 * 
		 * 2 must indicate the secondary button (in general, the right button,
		 * often used to display a context menu).
		 * 
	 *Some pointing devices may provide or simulate more buttons, and values 
	 * higher than 2 may be used to represent such buttons.
	 */
	public var button(default, null):Int;
	
	/**
	 * Used to identify a secondary EventTarget related to a UI
	 * event, depending on the type of event.
	 */
	public var relatedTarget(default, null):EventTarget;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Initializes attributes of a MouseEvent object. 
	 * This method has the same behavior as UIEvent.initUIEvent().
	 * 
	 * @param	eventTypeArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	canBubbleArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	cancelableArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	viewArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	detailArg Refer to the UIEvent.initUIEvent() method for a description of this parameter.
	 * @param	screenXArg Specifies MouseEvent.screenX.
	 * @param	screenYArg Specifies MouseEvent.screenY.
	 * @param	clientXArg Specifies MouseEvent.clientX.
	 * @param	clientYArg Specifies MouseEvent.clientY.
	 * @param	ctrlKeyArg Specifies MouseEvent.ctrlKey.
	 * @param	altKeyArg Specifies MouseEvent.altKey.
	 * @param	shiftKeyArg Specifies MouseEvent.shiftKey.
	 * @param	metaKeyArg Specifies MouseEvent.metaKey.
	 * @param	buttonArg Specifies MouseEvent.button.
	 * @param	relatedTargetArg Specifies MouseEvent.relatedTarget. This value may be null.
	 */
	public function initMouseEvent(eventTypeArg:String, canBubbleArg:Bool, cancelableArg:Bool, viewArg:Dynamic, detailArg:Float,
	screenXArg:Int, screenYArg:Int, clientXArg:Int, clientYArg:Int, ctrlKeyArg:Bool, altKeyArg:Bool,
	shiftKeyArg:Bool, metaKeyArg:Bool, buttonArg:Int, relatedTargeArg:EventTarget):Void
	{
		//can't alter event after it has been dispatched
		if (dispatched == true)
		{
			return;
		}
		
		initUIEvent(eventTypeArg, canBubbleArg, cancelableArg, viewArg, detailArg);
		screenX = screenXArg;
		screenY = screenYArg;
		clientX = clientXArg;
		clientY = clientYArg;
		ctrlKey = ctrlKeyArg;
		shiftKey = shiftKeyArg;
		altKey = altKeyArg;
		metaKey = metaKeyArg;
		button = buttonArg;
		relatedTarget = relatedTargeArg;
	}
}