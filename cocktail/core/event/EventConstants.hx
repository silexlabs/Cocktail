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
 * Lists all supported event types
 * 
 * @author Yannick DOMINGUEZ
 */
class EventConstants 
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// MEDIA (VIDEO AND AUDIO)
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The element is no longer paused. Fired after the play()
	 * method has returned, or when the autoplay 
	 * attribute has caused playback to begin.
	 */
	public static inline var PLAY:String = "play";
	
	/**
	 * Playback is ready to start after having been paused
	 * or delayed due to lack of media data.
	 */
	public static inline var PLAYING:String = "playing";
	
	/**
	 * The element has been paused. Fired after
	 * the pause() method has returned.
	 */
	public static inline var PAUSE:String = "pause";
	
	/**
	 * The user agent stops fetching the media data before 
	 * it is completely downloaded, but not due to an error.
	 */
	public static inline var ABORT:String = "abort";
	
	/**
	 * The user agent begins looking for media data,
	 * as part of the resource selection algorithm.
	 */
	public static inline var LOAD_START:String = "loadstart";
	
	/**
	 * Playback has stopped because the next frame is not
	 * available, but the user agent expects that frame
	 * to become available in due course.
	 */
	public static inline var WAITING:String = "waiting";
	
	/**
	 * The current playback position changed as part of
	 * normal playback or in an especially 
	 * interesting way, for example discontinuously.
	 */
	public static inline var TIME_UPDATE:String = "timeupdate";
	
	/**
	 * Playback has stopped because the end of the media 
	 * resource was reached.
	 */
	public static inline var ENDED:String = "ended";
	
	/**
	 * The user agent can render the media data at 
	 * the current playback position for the first time.
	 */
	public static inline var LOADED_DATA:String = "loadeddata";
	
	/**
	 * The seeking IDL attribute changed to true.
	 */
	public static inline var SEEKING:String = "seeking";
	
	/**
	 * The seeking IDL attribute changed to false.
	 */
	public static inline var SEEKED:String = "seeked";
	
	/**
	 * The user agent is fetching media data.
	 */
	public static inline var PROGRESS:String = "progress";
	
	/**
	 * The user agent can resume playback of the media data,
	 * but estimates that if playback were to be started now,
	 * the media resource could not be rendered at
	 * the current playback rate up to its end without
	 * having to stop for further buffering of content.
	 */
	public static inline var CAN_PLAY:String = "canplay";
	
	/**
	 * A media element whose networkState was previously not 
	 * in the NETWORK_EMPTY state has just switched to 
	 * that state (either because of a fatal error during
	 * load that's about to be reported, or because the
	 * load() method was invoked while the resource
	 * selection algorithm was already running).
	 */
	public static inline var EMPTIED:String = "emptied";
	
	/**
	 * The user agent has just determined the duration
	 * and dimensions of the media resource
	 */
	public static inline var LOADED_METADATA:String = "loadedmetadata";
	
	/**
	 * The duration attribute has just been updated.
	 */
	public static inline var DURATION_CHANGE:String = "durationchange";
	
	/**
	 * Either the volume attribute or the muted attribute has
	 * changed. Fired after the relevant attribute's
	 * setter has returned.
	 */
	public static inline var VOLUME_CHANGE:String = "volumechange";
	
	/**
	 * The user agent is intentionally not currently fetching media data.
	 */
	public static inline var SUSPEND:String = "suspend";
	
	/**
	 * The user agent is trying to fetch media data, but data
	 * is unexpectedly not forthcoming.
	 */
	public static inline var STALLED:String = "stalled";
	
	/**
	 * The user agent estimates that if playback were to be 
	 * started now, the media resource could be rendered at
	 * the current playback rate all the way to its 
	 * end without having to stop for further buffering.
	 */
	public static inline var CAN_PLAY_THROUGH:String = "canplaythrough";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// XMLHTTPREQUEST
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Dispatched when the readyState attribute changes at some seemingly 
	 * arbitrary times for historical reasons.
	 */
	public static inline var READY_STATE_CHANGE:String = "readystatechange";
	
	/**
	 * Dispatched when the author specified timeout has passed before
	 * the request could complete.
	 */
	public static inline var TIME_OUT:String = "timeout";
	
	/**
	 * Dispatched when the request has completed 
	 * (either in success or failure).
	 */
	public static inline var LOAD_END:String = "loadend";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FULLSCREEN
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The user either enter or exit fullscreen mode
	 */
	public static inline var FULL_SCREEN_CHANGE:String = "fullscreenchange";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FOCUS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A user agent must dispatch this event when an event target 
	 * receives focus. The focus must be given to the element before 
	 * the dispatch of this event type. This event type is similar to focusin, 
	 * but is dispatched after focus is shifted, and does not bubble.
	 */
	public static inline var FOCUS:String = "focus";
	
	/**
	 * A user agent must dispatch this event when an event target loses focus.
	 * The focus must be taken from the element before the dispatch of this
	 * event type. This event type is similar to focusout,
	 * but is dispatched after focus is shifted, and does not bubble.
	 */
	public static inline var BLUR:String = "blur";
	
	/**
	 * A user agent must dispatch this event when an event target
	 * is about to receive focus. This event type must be 
	 * dispatched before the element is given focus. The event
	 * target must be the element which is about to receive focus.
	 * This event type is similar to focus, but is dispatched before
	 * focus is shifted, and does bubble.
	 */
	public static inline var FOCUS_IN:String = "focusin";
	
	/**
	 * A user agent must dispatch this event when an event target is about to
	 * lose focus. This event type must be dispatched before 
	 * the element loses focus. The event target must be 
	 * the element which is about to lose focus. This event 
	 * type is similar to blur, but is dispatched before focus 
	 * is shifted, and does bubble.
	 */
	public static inline var FOCUS_OUT:String = "focusout";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// KEYBOARD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A user agent must dispatch this event when a key is
	 * pressed down. The keydown event type is device dependent
	 * and relies on the capabilities of the input devices 
	 * and how they are mapped in the operating system. 
	 * This event type must be generated after the key
	 * mapping. This event type must be dispatched before
	 * the keypress and keyup events event associated
	 * with the same key.
	 */
	public static inline var KEY_DOWN:String = "keydown";
	
	/**
	 * A user agent must dispatch this event when a key
	 * is pressed down, if and only if that key normally 
	 * produces a character value. The keypress event type 
	 * is device dependent and relies on the capabilities 
	 * of the input devices and how they are mapped in 
	 * the operating system. This event type must be 
	 * generated after the key mapping. It must not
	 * be fired when using an input method editor.
	 * This event type must be dispatched after the 
	 * keydown event and before the keyup event 
	 * associated with the same key.
	 */
	public static inline var KEY_UP:String = "keyup";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The click event occurs when the pointing device
	 * button is clicked over an element. 
	 * A click is defined as a mousedown and mouseup
	 * over the same screen location.
	 * The sequence of these events is:
	 * mousedown
	 * mouseup
	 * click
	 */
	public static inline var CLICK:String = "click";
	
	/**
	 * A user agent must dispatch this event when a pointing device button is
	 * clicked twice over an element. The definition of a double
	 * click depends on the environment configuration, except that
	 * the event target must be the same between mousedown, mouseup, 
	 * and dblclick. This event type must be dispatched after the event
	 * type click if a click and double click occur simultaneously,
	 * and after the event type mouseup otherwise.
	 */
	public static inline var DOUBLE_CLICK:String = "dblclick";
	
	/**
	 * The mouseup event occurs when the pointing device button is
	 * released over an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_UP:String = "mouseup";
	
	/**
	 * The mousedown event occurs when the pointing device button
	 * is pressed over an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_DOWN:String = "mousedown";
	
	/**
	 * The mouseover event occurs when the pointing device is moved
	 * onto an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_OVER:String = "mouseover";
	
	/**
	 * The mouseout event occurs when the pointing device is moved 
	 * away from an element. This event is valid for most elements.
	 */
	public static inline var MOUSE_OUT:String = "mouseout";
	
	/**
	 * The mousemove event occurs when the pointing device is moved 
	 * while it is over an element. This event is valid for most elements. 
	 */
	public static inline var MOUSE_MOVE:String = "mousemove";
	
	/**
	 * The mouseleave event occurs when a pointing device is moved 
	 * off of the boundaries of an element and all of its descendent elements.
	 * This event type is similar to mouseout, but differs in that does not bubble,
	 * and that it must not be dispatched until the pointing device has left
	 * the boundaries of the element and the boundaries of all of its children.
	 */
	public static inline var MOUSE_LEAVE:String = "mouseleave";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TOUCH
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TRANSITION
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The ‘transitionend’ event occurs at the completion
	 * of the transition. In the case where a transition 
	 * is removed before completion, such as if the 
	 * transition-property is removed, then the event will not fire.
	 */
	public static inline var TRANSITION_END:String = "transitionend";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// UI
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * A user agent must dispatch this event when a document view or an element
	 * has been scrolled. This event type is dispatched after the scroll has
	 * occurred.When dispatched on the Document element,
	 * this event type must bubble to the defaultView object.
	 */
	public static inline var SCROLL:String = "scroll";
	
	/**
	 * A user agent must dispatch this event when a document view has
	 * been resized. This event type is dispatched after all effects
	 * for that occurrence of resizing of that particular event target
	 * have been executed by the user agent.
	 * 
	 * User agents which support continuous reflow of the document's 
	 * layout during user-initiated resizing must dispatch this event
	 * synchronously after each reflow of the document.
	 * 
	 * The defaultView object should always be resizable. A host language
	 * may define certain elements to be resizable, and under what
	 * conditions (e.g., specific elements like iframe, or elements
	 * with particular characteristics like width and height); however,
	 * this specification does not define the behavior for elements.
	 */
	public static inline var RESIZE:String = "resize";
	
	/**
	 * A user agent must dispatch this event when the DOM 
	 * implementation finishes loading the resource 
	 * (such as the document) and any dependent resources
	 * (such as images, style sheets, or scripts). Dependent resources
	 * that fail to load must not prevent this event from firing if the
	 * resource that loaded them is still accessible via the DOM.
	 * If this event type is dispatched, implementations are required
	 * to dispatch this event at least on the Document node.
	 */
	public static inline var LOAD:String = "load";
	
	/**
	 * A user agent must dispatch this event when a resource
	 * failed to load, or has been loaded but cannot be interpreted
	 * according to its semantics, such as an invalid image,
	 * a script execution error, or non-well-formed XML.
	 */
	public static inline var ERROR:String = "error";
	
	/**
	 * Used at various places to signal a change, for instance used
	 * when the value of a checkbox input changes. I didn't found
	 * a formal definition in the w3c specs
	 */
	public static inline var CHANGE:String = "change";
	
	/**
	 * Used to signal a user input in a text based form control
	 */
	public static inline var INPUT:String = "input";
	
	/**
	 * Sent when a form content is reseted
	 */
	public static inline var RESET:String = "reset";
	
	/**
	 * Sent when a form is submitted as the result of
	 * a user action
	 */
	public static inline var SUBMIT:String = "submit";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE WHEEL
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * 	
	 * The mouse wheel event occurs when the mouse wheel is rotated
	 * while the pointing device is over an HTMLElement
	 */
	public static inline var MOUSE_WHEEL:String = "wheel";
	
	private function new() 
	{
		
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// HISTORY
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The user either enter or exit fullscreen mode
	 */
	public static inline var POP_STATE:String = "popstate";
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// INTERNAL (ONLY USED WITHIN COCKTAIL)
	//////////////////////////////////////////////////////////////////////////////////////////
		
	/**
	 * When a config parameter is changed, the Config object
	 * dispatch an event of this type
	 */
	public static inline var CONFIG_CHANGED:String = "configchanged";
	
}