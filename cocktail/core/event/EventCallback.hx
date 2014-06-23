/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.event;

import cocktail.event.*;

/**
 * Exposes attributes to set/get callbacks for all the DOM
 * events in one location. 
 * 
 * Add/Remove event listeners for the EventTarget
 * when callbacks are set/removed.
 * 
 * This classes is inherited by all DOM Objects
 * which can receive and dispatch events, such
 * as Node, Document and Window
 *
 * @author Yannick DOMINGUEZ
 */
class EventCallback extends EventTarget
{

	//////////////////////////////////////////////////////////////////////////////////////////
	// Mouse callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The callback called on mouse click (rapid mouse down and mouse up)
	 */
	public var onclick(default, set_onclick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse double click
	 */
	public var ondblclick(default, set_ondblclick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse down 
	 */
	public var onmousedown(default, set_onmousedown):MouseEvent->Void;
	
	/**
	 * The callback called on mouse up
	 */
	public var onmouseup(default, set_onmouseup):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer hovers this htmlElement
	 */
	public var onmouseover(default, set_onmouseover):MouseEvent->Void;
	
	/**
	 * The callback called on mouse out of this htmlElement
	 */
	public var onmouseout(default, set_onmouseout):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer moves over this htmlElement
	 */
	public var onmousemove(default, set_onmousemove):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse wheel is rotated while the mouse
	 * pointer is over this element
	 */
	public var onmousewheel(default, set_onmousewheel):WheelEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Keyboard callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The callback called on key down when this htmlElement has focus
	 */
	public var onkeydown(default, set_onkeydown):KeyboardEvent->Void;
	
	/**
	 * The callback called on key up when this htmlElement has focus
	 */
	public var onkeyup(default, set_onkeyup):KeyboardEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Focus callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * callback called when the HTMLElement receives 
	 * the focus
	 */
	public var onfocus(default, set_onfocus):FocusEvent->Void;
	
	/**
	 * callback called when the HTMLElement loses the focus
	 */
	public var onblur(default, set_onblur):FocusEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// UI callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when the window through which
	 * the document is viewed is resized
	 */
	public var onresize(default, set_onresize):UIEvent->Void;
	
	/**
	 * Callback called when the document enters or exit fullscreen
	 * mode
	 */
	public var onfullscreenchange(default, set_onfullscreenchange):Event->Void;
	
	/**
	 * Callback called when
	 * the content of the HTMLElement
	 * is scrolled
	 */
	public var onscroll(default, set_onscroll):UIEvent->Void;
	
	/**
	 * Callback called when the document or
	 * an external resource, such as a picture
	 * is loaded
	 */
	public var onload(default, set_onload):UIEvent->Void;
	
	/**
	 * Callback called when there is an
	 * error while loading an external
	 * resource such as a picture
	 */
	public var onerror(default, set_onerror):UIEvent->Void;
	
	/**
	 * Callback called when a value change in a form input,
	 * for instance when a checkbox value changes
	 */
	public var onchange(default, set_onchange):Event->Void;
	
	/**
	 * Callback called when is input by the user in a
	 * text based form control
	 */
	public var oninput(default, set_oninput):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Form callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called on a form when it is reseted
	 */
	public var onreset(default, set_onreset):Event->Void;
	
	/**
	 * Callback called on a form when it is reseted
	 */
	public var onsubmit(default, set_onsubmit):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Media callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when a media begins loading
	 */
	public var onloadstart(default, set_onloadstart):Event->Void;
	
	/**
	 * Called when a media has loaded some data
	 */
	public var onprogress(default, set_onprogress):Event->Void;
	
	/**
	 * Called when the user agent is intentionally not fectching
	 * media data
	 */
	public var onsuspend(default, set_onsuspend):Event->Void;
	
	/**
	 * Called when the loading of a media is canceled
	 */
	public var onemptied(default, set_onemptied):Event->Void;
	
	/**
	 * Called when the user agent can't fetch data
	 */
	public var onstalled(default, set_onstalled):Event->Void;
	
	/**
	 * Called when the metadata of the media have been loaded
	 */
	public var onloadedmetadata(default, set_onloadedmetadata):Event->Void;
	
	/**
	 * Called when the user agent can render the media data
	 * at the current playback position for the first time
	 */
	public var onloadeddata(default, set_onloadeddata):Event->Void;
	
	/**
	 * Called when the user agent can resume playback but
	 * estimates it won't have enough data to play the whole
	 * media without buffering
	 */
	public var oncanplay(default, set_oncanplay):Event->Void;
	
	/**
	 * Called when the user agents estimates that the media
	 * can be played through at the current playback rate without
	 * being stopped
	 */
	public var oncanplaythrough(default, set_oncanplaythrough):Event->Void;
	
	/**
	 * Called when playback is ready to start after 
	 * having been paused or delayed due to lack of media data.
	 */
	public var onplaying(default, set_onplaying):Event->Void;
	
	/**
	 * Called when playback has stopped because the next frame
	 * is not available, but the user agent expects
	 * that frame to become available in due course.
	 */
	public var onwaiting(default, set_onwaiting):Event->Void;
	
	/**
	 * Called when the seeking attribute has been set to true
	 */
	public var onseeking(default, set_onseeking):Event->Void;
	
	/**
	 * Called when the seeking attribute has been set to false
	 */
	public var onseeked(default, set_onseeked):Event->Void;
	
	/**
	 * Called when playback has stopped because the end 
	 * of the media resource was reached.
	 */
	public var onended(default, set_onended):Event->Void;
	
	/**
	 * Called when the duration attribute has
	 * been updated
	 */
	public var ondurationchange(default, set_ondurationchange):Event->Void;
	
	/**
	 * Called when the current playback position changed 
	 * as part of normal playback or in an especially
	 * interesting way, for example discontinuously.
	 */
	public var ontimeupdate(default, set_ontimeupdate):Event->Void;
	
	/**
	 * Called when The element is no longer paused.
	 * Fired after the play() method has returned, 
	 * or when the autoplay attribute has caused playback to begin.
	 */ 
	public var onplay(default, set_onplay):Event->Void;
	
	/**
	 * Called when the element has been paused. 
	 * Fired after the pause() method has returned.
	 */
	public var onpause(default, set_onpause):Event->Void;
	
	/**
	 * Called when either the volume attribute or the muted 
	 * attribute has changed. Fired after the relevant 
	 * attribute's setter has returned.
	 */
	public var onvolumechange(default, set_onvolumechange):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Transition callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the transition is complete. In the case where a transition is
	 * removed before completion, such as if the transition-property 
	 * is removed, then the event will not fire.
	 */
	public var ontransitionend(default, set_ontransitionend):TransitionEvent->Void;

	//////////////////////////////////////////////////////////////////////////////////////////
	// HISTORY callbacks
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * event.state contains a copy of the information that was provided to pushState() or replaceState()
	 */
	public var onpopstate(default, set_onpopstate):PopStateEvent->Void;
	
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACK HELPER
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Utils method to update the listener used by a callback
	 */
	private function updateCallbackListener(eventType:String, newListener:Dynamic->Void, oldListener:Dynamic->Void):Void
	{
		//if the callback is alreay linked to an EventListener
		//remove the event listener
		if (oldListener != null)
		{
			removeEventListener(eventType, oldListener);
		}
		
		//add a new event listener if the callback is not null
		if (newListener != null)
		{
			addEventListener(eventType, newListener);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACKS SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
		// MOUSE
	////////////////////////////
	
	private function set_onclick(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.CLICK, value, onclick);
		return onclick = value;
	}
	
	private function set_ondblclick(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.DOUBLE_CLICK, value, ondblclick);
		return ondblclick = value;
	}
	
	private function set_onmousedown(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_DOWN, value, onmousedown);
		return onmousedown = value;
	}
	
	private function set_onmouseup(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_UP, value, onmouseup);
		return onmouseup = value;
	}
	
	private function set_onmouseover(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_OVER, value, onmouseover);
		return onmouseover = value;
	}
	
	private function set_onmouseout(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_OUT, value, onmouseout);
		return onmouseout = value;
	}
	
	private function set_onmousemove(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_MOVE, value, onmousemove);
		return onmousemove = value;
	}
	
	private function set_onmousewheel(value:WheelEvent->Void):WheelEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_WHEEL, value, onmousewheel);
		return onmousewheel = value;
	}
	
		// KEYBOARD
	////////////////////////////
	
	private function set_onkeydown(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(EventConstants.KEY_DOWN, value, onkeydown);
		return onkeydown = value;
	}
	
	private function set_onkeyup(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(EventConstants.KEY_UP, value, onkeyup);
		return onkeyup = value;
	}
	
		// FOCUS
	////////////////////////////
	
	private function set_onfocus(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(EventConstants.FOCUS, value, onfocus);
		return onfocus = value;
	}
	
	private function set_onblur(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(EventConstants.BLUR, value, onblur);
		return onblur = value;
	}

		// UI
	////////////////////////////
	
	private function set_onresize(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.RESIZE, value, onresize);
		return onresize = value;
	}
	
	private function set_onfullscreenchange(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.FULL_SCREEN_CHANGE, value, onfullscreenchange);
		return onfullscreenchange = value;
	}
	
	private function set_onscroll(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.SCROLL, value, onscroll);
		return onscroll = value;
	}
	
	private function set_onload(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD, value, onload);
		return onload = value;
	}
		
	private function set_onerror(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.ERROR, value, onerror);
		return onerror = value;
	}
	
	private function set_onchange(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.CHANGE, value, onchange);
		return onchange = value;
	}
	
	private function set_oninput(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.INPUT, value, oninput);
		return oninput = value;
	}
	
		// FORM
	////////////////////////////
	
	private function set_onreset(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.RESET, value, onreset);
		return onreset = value;
	}
	
	private function set_onsubmit(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.SUBMIT, value, onsubmit);
		return onsubmit = value;
	}
	
		// VIDEO
	////////////////////////////
	
	private function set_onloadstart(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.LOAD_START, value, onloadstart);
		return onloadstart = value;
	}
	
	private function set_onprogress(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PROGRESS, value, onprogress);
		return onprogress = value;
	}
	
	private function set_onsuspend(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.SUSPEND, value, onsuspend);
		return onsuspend = value;
	}
	
	private function set_onemptied(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.EMPTIED, value, onemptied);
		return onemptied = value;
	}
	
	private function set_onstalled(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.STALLED, value, onstalled);
		return onstalled = value;
	}
	
	private function set_onloadedmetadata(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.LOADED_METADATA, value, onloadedmetadata);
		return onloadedmetadata = value;
	}
	
	private function set_onloadeddata(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.LOADED_DATA, value, onloadeddata);
		return onloadeddata = value;
	}
	
	private function set_oncanplay(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.CAN_PLAY, value, oncanplay);
		return oncanplay = value;
	}
	
	private function set_oncanplaythrough(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.CAN_PLAY_THROUGH, value, oncanplaythrough);
		return oncanplaythrough = value;
	}
	
	private function set_onplaying(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PLAYING, value, onplaying);
		return onplaying = value;
	}
	
	private function set_onwaiting(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.WAITING, value, onwaiting);
		return onwaiting = value;
	}
	
	private function set_onseeking(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.SEEKING, value, onseeking);
		return onwaiting = value;
	}
	
	private function set_onseeked(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.SEEKED, value, onseeked);
		return onseeked = value;
	}
	
	private function set_onended(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.ENDED, value, onended);
		return onended = value;
	}
	
	private function set_ondurationchange(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.DURATION_CHANGE, value, ondurationchange);
		return ondurationchange = value;
	}
	
	private function set_ontimeupdate(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.TIME_UPDATE, value, ontimeupdate);
		return ontimeupdate = value;
	}
	
	private function set_onplay(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PLAY, value, onplay);
		return onplay = value;
	}
	
	private function set_onpause(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PAUSE, value, onpause);
		return onpause = value;
	}
	
	private function set_onvolumechange(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.VOLUME_CHANGE, value, onvolumechange);
		return onvolumechange = value;
	}
	
	// TRANSITION
	////////////////////////////
	
	private function set_ontransitionend(value:TransitionEvent->Void):TransitionEvent->Void
	{
		updateCallbackListener(EventConstants.TRANSITION_END, value, ontransitionend);
		return ontransitionend = value;
	}

	// HISTORY
	////////////////////////////
	
	private function set_onpopstate(value:PopStateEvent->Void):PopStateEvent->Void
	{
		updateCallbackListener(EventConstants.POP_STATE, value, onpopstate);
		return onpopstate = value;
	}
}
