/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

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
	public var onclick(default, set_onClick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse double click
	 */
	public var ondblclick(default, set_onDblClick):MouseEvent->Void;
	
	/**
	 * The callback called on mouse down 
	 */
	public var onmousedown(default, set_onMouseDown):MouseEvent->Void;
	
	/**
	 * The callback called on mouse up
	 */
	public var onmouseup(default, set_onMouseUp):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer hovers this htmlElement
	 */
	public var onmouseover(default, set_onMouseOver):MouseEvent->Void;
	
	/**
	 * The callback called on mouse out of this htmlElement
	 */
	public var onmouseout(default, set_onMouseOut):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse pointer moves over this htmlElement
	 */
	public var onmousemove(default, set_onMouseMove):MouseEvent->Void;
	
	/**
	 * The callback called when the mouse wheel is rotated while the mouse
	 * pointer is over this element
	 */
	public var onmousewheel(default, set_onMouseWheel):WheelEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Keyboard callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The callback called on key down when this htmlElement has focus
	 */
	public var onkeydown(default, set_onKeyDown):KeyboardEvent->Void;
	
	/**
	 * The callback called on key up when this htmlElement has focus
	 */
	public var onkeyup(default, set_onKeyUp):KeyboardEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Focus callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * callback called when the HTMLElement receives 
	 * the focus
	 */
	public var onfocus(default, set_onFocus):FocusEvent->Void;
	
	/**
	 * callback called when the HTMLElement loses the focus
	 */
	public var onblur(default, set_onBlur):FocusEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// UI callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback called when the window through which
	 * the document is viewed is resized
	 */
	public var onresize(default, set_onResize):UIEvent->Void;
	
	/**
	 * Callback called when the document enters or exit fullscreen
	 * mode
	 */
	public var onfullscreenchange(default, set_onFullScreenChange):Event->Void;
	
	/**
	 * Callback called when
	 * the content of the HTMLElement
	 * is scrolled
	 */
	public var onscroll(default, set_onScroll):UIEvent->Void;
	
	/**
	 * Callback called when the document or
	 * an external resource, such as a picture
	 * is loaded
	 */
	public var onload(default, set_onLoad):UIEvent->Void;
	
	/**
	 * Callback called when there is an
	 * error while loading an external
	 * resource such as a picture
	 */
	public var onerror(default, set_onError):UIEvent->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Media callbacks
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when a media begins loading
	 */
	public var onloadstart(default, set_onLoadStart):Event->Void;
	
	/**
	 * Called when a media has loaded some data
	 */
	public var onprogress(default, set_onProgress):Event->Void;
	
	/**
	 * Called when the user agent is intentionally not fectching
	 * media data
	 */
	public var onsuspend(default, set_onSuspend):Event->Void;
	
	/**
	 * Called when the loading of a media is canceled
	 */
	public var onemptied(default, set_onEmptied):Event->Void;
	
	/**
	 * Called when the user agent can't fetch data
	 */
	public var onstalled(default, set_onStalled):Event->Void;
	
	/**
	 * Called when the metadata of the media have been loaded
	 */
	public var onloadedmetadata(default, set_onLoadedMetadata):Event->Void;
	
	/**
	 * Called when the user agent can render the media data
	 * at the current playback position for the first time
	 */
	public var onloadeddata(default, set_onLoadedData):Event->Void;
	
	/**
	 * Called when the user agent can resume playback but
	 * estimates it won't have enough data to play the whole
	 * media without buffering
	 */
	public var oncanplay(default, set_onCanPlay):Event->Void;
	
	/**
	 * Called when the user agents estimates that the media
	 * can be played through at the current playback rate without
	 * being stopped
	 */
	public var oncanplaythrough(default, set_onCanPlayThrough):Event->Void;
	
	/**
	 * Called when playback is ready to start after 
	 * having been paused or delayed due to lack of media data.
	 */
	public var onplaying(default, set_onPlaying):Event->Void;
	
	/**
	 * Called when playback has stopped because the next frame
	 * is not available, but the user agent expects
	 * that frame to become available in due course.
	 */
	public var onwaiting(default, set_onWaiting):Event->Void;
	
	/**
	 * Called when the seeking attribute has been set to true
	 */
	public var onseeking(default, set_onSeeking):Event->Void;
	
	/**
	 * Called when the seeking attribute has been set to false
	 */
	public var onseeked(default, set_onSeeked):Event->Void;
	
	/**
	 * Called when playback has stopped because the end 
	 * of the media resource was reached.
	 */
	public var onended(default, set_onEnded):Event->Void;
	
	/**
	 * Called when the duration attribute has
	 * been updated
	 */
	public var ondurationchange(default, set_onDurationChanged):Event->Void;
	
	/**
	 * Called when the current playback position changed 
	 * as part of normal playback or in an especially
	 * interesting way, for example discontinuously.
	 */
	public var ontimeupdate(default, set_onTimeUpdate):Event->Void;
	
	/**
	 * Called when The element is no longer paused.
	 * Fired after the play() method has returned, 
	 * or when the autoplay attribute has caused playback to begin.
	 */ 
	public var onplay(default, set_onPlay):Event->Void;
	
	/**
	 * Called when the element has been paused. 
	 * Fired after the pause() method has returned.
	 */
	public var onpause(default, set_onPause):Event->Void;
	
	/**
	 * Called when either the volume attribute or the muted 
	 * attribute has changed. Fired after the relevant 
	 * attribute's setter has returned.
	 */
	public var onvolumechange(default, set_onVolumeChange):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Transition callback
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the transition is complete. In the case where a transition is
	 * removed before completion, such as if the transition-property 
	 * is removed, then the event will not fire.
	 */
	public var ontransitionend(default, set_onTransitionEnd):TransitionEvent->Void;
	
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
	private function updateCallbackListener(eventType:String, newListener:Event->Void, oldListener:Event->Void):Void
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
	
	private function set_onClick(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.CLICK, cast(value), cast(onclick));
		return onclick = value;
	}
	
	private function set_onDblClick(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.DOUBLE_CLICK, cast(value), cast(ondblclick));
		return ondblclick = value;
	}
	
	private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_DOWN, cast(value), cast(onmousedown));
		return onmousedown = value;
	}
	
	private function set_onMouseUp(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_UP, cast(value), cast(onmouseup));
		return onmouseup = value;
	}
	
	private function set_onMouseOver(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_OVER, cast(value), cast(onmouseover));
		return onmouseover = value;
	}
	
	private function set_onMouseOut(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_OUT, cast(value), cast(onmouseout));
		return onmouseout = value;
	}
	
	private function set_onMouseMove(value:MouseEvent->Void):MouseEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_MOVE, cast(value), cast(onmousemove));
		return onmousemove = value;
	}
	
	private function set_onMouseWheel(value:WheelEvent->Void):WheelEvent->Void
	{
		updateCallbackListener(EventConstants.MOUSE_WHEEL, cast(value), cast(onmousewheel));
		return onmousewheel = value;
	}
	
		// KEYBOARD
	////////////////////////////
	
	private function set_onKeyDown(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(EventConstants.KEY_DOWN, cast(value), cast(onkeydown));
		return onkeydown = value;
	}
	
	private function set_onKeyUp(value:KeyboardEvent->Void):KeyboardEvent->Void
	{
		updateCallbackListener(EventConstants.KEY_UP, cast(value), cast(onkeyup));
		return onkeyup = value;
	}
	
		// FOCUS
	////////////////////////////
	
	private function set_onFocus(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(EventConstants.FOCUS, cast(value), cast(onfocus));
		return onfocus = value;
	}
	
	private function set_onBlur(value:FocusEvent->Void):FocusEvent->Void
	{
		updateCallbackListener(EventConstants.BLUR, cast(value), cast(onblur));
		return onblur = value;
	}

		// UI
	////////////////////////////
	
	private function set_onResize(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.RESIZE, cast(value), cast(onresize));
		return onresize = value;
	}
	
	private function set_onFullScreenChange(value:Event->Void):Event->Void
	{
		updateCallbackListener(Event.FULL_SCREEN_CHANGE, value, onfullscreenchange);
		return onfullscreenchange = value;
	}
	
	private function set_onScroll(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.SCROLL, cast(value), cast(onscroll));
		return onscroll = value;
	}
	
	private function set_onLoad(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD, cast(value), cast(onload));
		return onload = value;
	}
		
	private function set_onError(value:UIEvent->Void):UIEvent->Void
	{
		updateCallbackListener(EventConstants.ERROR, cast(value), cast(onerror));
		return onerror = value;
	}
	
	
		// VIDEO
	////////////////////////////
	
	private function set_onLoadStart(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.LOAD_START, value, onloadstart);
		return onloadstart = value;
	}
	
	private function set_onProgress(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PROGRESS, value, onprogress);
		return onprogress = value;
	}
	
	private function set_onSuspend(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.SUSPEND, value, onsuspend);
		return onsuspend = value;
	}
	
	private function set_onEmptied(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.EMPTIED, value, onemptied);
		return onemptied = value;
	}
	
	private function set_onStalled(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.STALLED, value, onstalled);
		return onstalled = value;
	}
	
	private function set_onLoadedMetadata(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.LOADED_METADATA, value, onloadedmetadata);
		return onloadedmetadata = value;
	}
	
	private function set_onLoadedData(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.LOADED_DATA, value, onloadeddata);
		return onloadeddata = value;
	}
	
	private function set_onCanPlay(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.CAN_PLAY, value, oncanplay);
		return oncanplay = value;
	}
	
	private function set_onCanPlayThrough(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.CAN_PLAY_THROUGH, value, oncanplaythrough);
		return oncanplaythrough = value;
	}
	
	private function set_onPlaying(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PLAYING, value, onplaying);
		return onplaying = value;
	}
	
	private function set_onWaiting(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.WAITING, value, onwaiting);
		return onwaiting = value;
	}
	
	private function set_onSeeking(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.SEEKING, value, onseeking);
		return onwaiting = value;
	}
	
	private function set_onSeeked(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.SEEKED, value, onseeked);
		return onseeked = value;
	}
	
	private function set_onEnded(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.ENDED, value, onended);
		return onended = value;
	}
	
	private function set_onDurationChanged(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.DURATION_CHANGE, value, ondurationchange);
		return ondurationchange = value;
	}
	
	private function set_onTimeUpdate(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.TIME_UPDATE, value, ontimeupdate);
		return ontimeupdate = value;
	}
	
	private function set_onPlay(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PLAY, value, onplay);
		return onplay = value;
	}
	
	private function set_onPause(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.PAUSE, value, onpause);
		return onpause = value;
	}
	
	private function set_onVolumeChange(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.VOLUME_CHANGE, value, onvolumechange);
		return onvolumechange = value;
	}
	
		// TRANSITION
	////////////////////////////
	
	private function set_onTransitionEnd(value:TransitionEvent->Void):TransitionEvent->Void
	{
		updateCallbackListener(TransitionEvent.TRANSITION_END, cast(value), cast(ontransitionend));
		return ontransitionend = value;
	}
}