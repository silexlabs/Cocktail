/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.dom.Document;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.Element;
import cocktail.core.dom.Node;
import cocktail.core.event.Event;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.focus.FocusManager;
import cocktail.core.html.HTMLAnchorElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLHtmlElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.renderer.RendererData;
import cocktail.core.event.FocusEvent;
import cocktail.Lib;
import haxe.Log;
import haxe.Timer;
import cocktail.core.style.StyleData;

/**
 * An HTMLDocument is the root of the HTML hierarchy and holds the entire content.
 * Besides providing access to the hierarchy, it also provides some convenience methods
 * for accessing certain sets of information from the document.
 * 
 * TODO 3 : should manage current click count
 * TODO 3 : should manage double click events
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLDocument extends Document
{
	/**
	 * key code listened to by the Document
	 */
	
	private static inline var TAB_KEY_CODE:Int = 9;
	
	private static inline var ENTER_KEY_CODE:Int = 13;
	
	private static inline var SPACE_KEY_CODE:Int = 32;
	
	/**
	 * A coefficient to apply to apply to the mouse
	 * wheel delta to get the right scroll amount, based
	 * on Windows implementation
	 */
	private static inline var MOUSE_WHEEL_DELTA_MULTIPLIER:Int = 10;
	
	/**
	 * The minimum amount of time between two layout and rendering. Can
	 * be used to set the framerate of the application. Dividing 1000
	 * by this value gives the framerate of the application
	 */
	private static inline var INVALIDATION_INTERVAL:Int = 20;
	
	/**
	 * The element that contains the content for the document.
	 * 
	 * The body is the root of the visual content in HTML
	 */
	public var body(default, null):HTMLBodyElement;
	
	/**
	 * The activeElement set/get the element
	 * in the document which is focused.
	 * If no element in the Document is focused, this returns the body element. 
	 */
	public var activeElement(get_activeElement, set_activeElement):HTMLElement;
	
	/**
	 * An instance of the FocusManager, managing the focus
	 * for this Document
	 */
	private var _focusManager:FocusManager;
	
	/**
	 * A reference to the ElementRenderer currently hovered by the
	 * mouse pointer. Used to detect when to dispatch mouse over
	 * and mouse out events 
	 */
	private var _hoveredElementRenderer:ElementRenderer;
	
	/**
	 * Returns true if document has the ability
	 * to display elements fullscreen, or false otherwise.
	 */
	public var fullscreenEnabled(get_fullscreenEnabled, never):Bool;
	
	/**
	 * Returns the element that is displayed fullscreen,
	 * or null if there is no such element.
	 */
	public var fullscreenElement(default, set_fullscreenElement):HTMLElement;
	
	/**
	 * Callback listened to by the Window object
	 * to enter fullscreen mode when needed using
	 * platform specific API
	 */
	public var onEnterFullscreen:Void->Void;
	
	/**
	 * Callback listened to by the Window object
	 * to exit fullscreen mode when needed using
	 * platform specific API
	 */
	public var onExitFullscreen:Void->Void;
	
	/**
	 * Callback listened to by the Window object
	 * to chnge the mouse cursor when needed using
	 * platform specific APIs
	 */
	public var onSetMouseCursor:Cursor->Void;
	
	/**
	 * a flag determining if a click event must be dispatched
	 * on the hovered element on the next mouse up event.
	 * 
	 * A click event is dispatched if there was a mouse down
	 * event then a mouse up event dispatched on the same hovered
	 * element
	 */
	private var _shouldDispatchClickOnNextMouseUp:Bool;
	
	/**
	 * Wether a call to the invalidation method is already
	 * scheduled, only one call to this method
	 * method can be scheduled at a time to prevent too many
	 * re-layout and re-rendering
	 */
	private var _invalidationScheduled:Bool;
	
	/*
	 * Wheter the document needs a re-layout on next
	 * ivnvalidation method call
	 */ 
	private var _documentNeedsLayout:Bool;
	
	/*
	 * Wheter the document needs a re-rendering on next
	 * ivnvalidation method call
	 */ 
	private var _documentNeedsRendering:Bool;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new() 
	{
		super();
		
		_focusManager = new FocusManager();
			
		documentElement = createElement(HTMLConstants.HTML_HTML_TAG_NAME);
		initBody(cast(createElement(HTMLConstants.HTML_BODY_TAG_NAME)));
		documentElement.appendChild(body);
		
		
	
		
		_shouldDispatchClickOnNextMouseUp = false;
				
		_invalidationScheduled = false;
		_documentNeedsLayout = true;
		_documentNeedsRendering = true;
	}
	
	/**
	 * Init the body element of the document and the attributes
	 * depending on it. Set as public so that the body element
	 * can be reset if the inner HTML of thr whole document
	 * changes
	 */
	public function initBody(htmlBodyElement:HTMLBodyElement):Void
	{
		body = htmlBodyElement;
		documentElement.appendChild(body);
		_hoveredElementRenderer = body.elementRenderer;
		activeElement = body;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to instantiate specific HTML element if needed based
	 * on the tag name
	 */
	override public function createElement(tagName:String):HTMLElement
	{
		var element:HTMLElement;
		
		//tag names are always uppercase in HTML
		tagName = tagName.toUpperCase();
		
		switch (tagName)
		{
			case HTMLConstants.HTML_IMAGE_TAG_NAME:
				element = new HTMLImageElement();
				
			case HTMLConstants.HTML_INPUT_TAG_NAME:
				element = new HTMLInputElement();
				
			case HTMLConstants.HTML_ANCHOR_TAG_NAME:
				element = new HTMLAnchorElement();
				
			case HTMLConstants.HTML_HTML_TAG_NAME:
				element = new HTMLHtmlElement(); 
				
			case HTMLConstants.HTML_BODY_TAG_NAME:
				element = new HTMLBodyElement();
				
			case HTMLConstants.HTML_VIDEO_TAG_NAME:
				element = new HTMLVideoElement();
				
			case HTMLConstants.HTML_SOURCE_TAG_NAME:
				element = new HTMLSourceElement();
				
			case HTMLConstants.HTML_OBJECT_TAG_NAME:
				element = new HTMLObjectElement();
				
			default:
				element = new HTMLElement(tagName);
		}
		
		element.ownerDocument = this;
		
		return element;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC PLATFORM CALLBACKS
	// Those callbacks are called in reaction to platform level event, such
	// as a resize of the window of the application
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Dispatch the MouseEvent on the DOM node of the top most 
	 * ElementRenderer under the mouse pointer
	 * 
	 * @param	mouseEvent
	 */
	public function onPlatformMouseEvent(mouseEvent:MouseEvent):Void
	{
		//store the even type before dispatching it, as the event object is
		//reseted after dispatch
		var eventType:String = mouseEvent.type;
		
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent);
		elementRendererAtPoint.node.dispatchEvent(mouseEvent);
	
		switch(eventType)
		{
			case MouseEvent.MOUSE_DOWN:
				//reset the click sequence when a mouse down is dispatched
				_shouldDispatchClickOnNextMouseUp = true;
			
				
			case MouseEvent.MOUSE_UP:
				//on mouse up, if nothing canceled the click sequence, dispatch
				//a click event after the mouse up event
				if (_shouldDispatchClickOnNextMouseUp == true)
				{
					dispatchClickEvent(mouseEvent);
				}
		}
	}
	
	/**
	 * When a mouse wheel event occurs first dispatch it, and
	 * if the default action wasn't prevented, vertically scroll
	 * the first vertically scrollable parent of the event target
	 */
	public function onPlatformMouseWheelEvent(wheelEvent:WheelEvent):Void
	{
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(wheelEvent);
		elementRendererAtPoint.node.dispatchEvent(wheelEvent);
		
		if (wheelEvent.defaultPrevented == false)
		{
			var htmlElement:HTMLElement = elementRendererAtPoint.node;
			
			//get the amount of vertical scrolling to apply in pixel
			var scrollOffset:Int = Math.round(wheelEvent.deltaY * MOUSE_WHEEL_DELTA_MULTIPLIER) ;
			
			//get the first ancestor which can be vertically scrolled
			var scrollableHTMLElement:HTMLElement = getFirstVerticallyScrollableHTMLElement(htmlElement, scrollOffset);
			if (scrollableHTMLElement != null)
			{
				scrollableHTMLElement.scrollTop -= scrollOffset;
			}
		
		}
	}
	
	/**
	 * MouseMove events are a special case of mouse event
	 * dispatching as they also must manager the hovered
	 * htmlElement
	 * 
	 * TODO 4 : implement all the mouse event such as mouseleave, and
	 * check if the implementation is in the right order
	 */
	public function onPlatformMouseMoveEvent(mouseEvent:MouseEvent):Void
	{
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent);

		if (_hoveredElementRenderer != elementRendererAtPoint)
		{
			var mouseOutEvent:MouseEvent = new MouseEvent();
			mouseOutEvent.initMouseEvent(MouseEvent.MOUSE_OUT, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY, mouseEvent.clientX,
			mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.altKey, mouseEvent.shiftKey, mouseEvent.metaKey, mouseEvent.button, elementRendererAtPoint.node);
			
			_hoveredElementRenderer.node.dispatchEvent(mouseOutEvent);
			
			var oldHoveredElementRenderer:ElementRenderer = _hoveredElementRenderer;
			_hoveredElementRenderer = elementRendererAtPoint;
			
			var mouseOverEvent:MouseEvent = new MouseEvent();
			mouseOverEvent.initMouseEvent(MouseEvent.MOUSE_OVER, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY, mouseEvent.clientX,
			mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.shiftKey,  mouseEvent.altKey, mouseEvent.metaKey, mouseEvent.button, oldHoveredElementRenderer.node);
			
			elementRendererAtPoint.node.dispatchEvent(mouseOverEvent);
			
			//when the hovered element changes, if a mouse up event is dispatched
			//on the new hovered element, no click should be dispatched on it, as 
			//no mouse down was dispatched on it
			_shouldDispatchClickOnNextMouseUp = false;
			
			//update the mouse cursor with the cursor style of the newly hovered 
			//element
			setMouseCursor(elementRendererAtPoint.node.coreStyle.computedStyle.cursor);
		}
		
		elementRendererAtPoint.node.dispatchEvent(mouseEvent);
	}
	
	
	/**
	 * When a key is pressed, dispatch the keyboardEvent
	 * on the active element and detect if a tab
	 * focus or a simulated click must happen.
	 */
	public function onPlatformKeyDownEvent(keyboardEvent:KeyboardEvent):Void
	{
		activeElement.dispatchEvent(keyboardEvent);

		//TODO 4 : should this logic go into HTMLElement ? or is it application/embedder level ?
		switch (Std.parseInt(keyboardEvent.keyChar))
		{
			case TAB_KEY_CODE:
				//only do sequantial navigation if default was not prevented
				if (keyboardEvent.defaultPrevented == false)
				{
					activeElement = _focusManager.getNextFocusedElement(keyboardEvent.shiftKey == true, body, activeElement);
				}
	
			case ENTER_KEY_CODE, SPACE_KEY_CODE:
				//only simulate click if default was not prevented
				//TODO 3 : should run activation behaviour steps ?
				if (keyboardEvent.defaultPrevented == false)
				{
					activeElement.click();
				}
		}
	}
	
	/**
	 * When a key up event happens, dispatches it
	 * on the activeElement
	 */
	public function onPlatformKeyUpEvent(keyboardEvent:KeyboardEvent):Void
	{
		activeElement.dispatchEvent(keyboardEvent);
	}
	
	/**
	 * When the Window is resized, invalidate
	 * the body
	 */
	public function onPlatformResizeEvent(event:UIEvent):Void
	{
		documentElement.invalidate(InvalidationReason.windowResize);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE CLICK METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * dispatch a click event on the currently hovered element if a mouse down and mouse up
	 * was called on it without the mouse hovering another element in between
	 * 
	 * Mouse click event are a special case of
	 * mouse event dispatching, as they may trigger
	 * activation behaviour, such as following a 
	 * link for an HTMLAnchorElement
	 * 
	 * @param mouseEvent, the mouse up event which triggered the click
	 */
	private function dispatchClickEvent(mouseEvent:MouseEvent):Void
	{
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent);
		
		var htmlElement:HTMLElement = elementRendererAtPoint.node;
		
		//find the first parent of the HTMLElement which has an activation behaviour, might
		//return null
		var nearestActivatableElement:HTMLElement = htmlElement.getNearestActivatableElement();

		//execute pre activation
		if (nearestActivatableElement != null)
		{
			nearestActivatableElement.runPreClickActivation();
		}
		
		//create a mouse click event from the mouse up event
		var clickEvent:MouseEvent = new MouseEvent();
		clickEvent.initMouseEvent(MouseEvent.CLICK, true, true, null, 0.0, mouseEvent.screenX, mouseEvent.screenY,
		mouseEvent.clientX, mouseEvent.clientY, mouseEvent.ctrlKey, mouseEvent.altKey, mouseEvent.shiftKey,
		mouseEvent.metaKey, mouseEvent.button, null);
		
		htmlElement.dispatchEvent(clickEvent);
		
		//execute post or canceled activation behaviour
		if (nearestActivatableElement != null)
		{
			if (mouseEvent.defaultPrevented == true)
			{
				nearestActivatableElement.runCanceledActivationStep();
			}
			else
			{
				nearestActivatableElement.runPostClickActivationStep(mouseEvent);
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE CURSOR METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Change the current mouse cursor, using platform
	 * specific APIs
	 */
	private function setMouseCursor(cursor:Cursor):Void
	{
		if (onSetMouseCursor != null)
		{
			onSetMouseCursor(cursor);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// FULLSCREEN METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Stops any elements within document
	 * from being displayed fullscreen.
	 * 
	 * TODO 5 : implementation doesn't respect
	 * w3c spec, but spec still in early stages
	 */
	public function exitFullscreen():Void
	{
		//do nothing if no element is on fullscreen
		//currently
		if (fullscreenElement == null)
		{
			return;
		}
		
		fullscreenElement = null;
		
		//call the callback, so that the Window
		//object can exit fullscreen using platform
		//specific API
		if (onExitFullscreen != null)
		{
			onExitFullscreen();
		}
		
		//fire a fullscreen event
		var fullscreenEvent:Event = new Event();
		fullscreenEvent.initEvent(Event.FULL_SCREEN_CHANGE, true, false);
	}
	
	/**
	 * Return wether fullscreen mode is allowed
	 * 
	 * TODO 3 : a bit messy to have cross-reference
	 * to Platform 
	 */
	private function get_fullscreenEnabled():Bool
	{
		return Lib.window.platform.nativeWindow.fullScreenEnabled();
	}
	
	/**
	 * start fullscreen mode
	 * 
	 * TODO 5 : implementation doesn't respect
	 * w3c spec, but spec still in early stages
	 */
	private function set_fullscreenElement(value:HTMLElement):HTMLElement
	{
		//do nothing if element is null. Might also
		//be called when exiting fullscreen to set 
		//fullsrcreen element to null
		if (value == null)
		{
			fullscreenElement = null;
			return value;
		}
		
		//do nothing if already in fullscreen mode
		if (fullscreenElement != null)
		{
			return fullscreenElement;
		}
		
		fullscreenElement = value;
		
		//call enter fullscreen callbakc, so that
		//Window can enter fullscreen using platform
		//specific API
		if (onEnterFullscreen != null)
		{
			onEnterFullscreen();
		}
		
		//fire fullscreen event
		var fullscreenEvent:Event = new Event();
		fullscreenEvent.initEvent(Event.FULL_SCREEN_CHANGE, true, false);
		
		return value;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * schedule a layout of the document
	 */
	public function invalidateLayout():Void
	{
		_documentNeedsLayout = true;
		invalidate();
	}
	
	/**
	 * schedule a rendering of the document
	 */
	public function invalidateRendering():Void
	{
		_documentNeedsRendering = true;
		invalidate();
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE INVALIDATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * schedule an invalidation
	 */
	private function invalidate():Void
	{
		if (_invalidationScheduled == false)
		{
			doInvalidate();
		}
	}
	
	/**
	 * Actually schedule an invalidation if one
	 * is not yet scheduled
	 */
	private function doInvalidate():Void
	{
		_invalidationScheduled = true;
		scheduleLayoutAndRender();
	}
	
	/**
	 * layout and render the document
	 * as needed
	 */
	private function layoutAndRender():Void
	{
		//only layout if the invalidate layout
		//method was called
		if (_documentNeedsLayout == true)
		{
			startLayout();
			_documentNeedsLayout = false;
		}
		
		//same as for layout
		if (_documentNeedsRendering == true)
		{
			startRendering();
			_documentNeedsRendering = false;
		}
	}
	
	/**
	 * Callback called after an invalidation is
	 * scheduled, starts the layout and rendering
	 */
	private function onLayoutSchedule():Void
	{
		layoutAndRender();
		_invalidationScheduled = false;
	}
	
	/**
	 * Start rendering the rendering
	 * tree, starting with the root ElementRenderer
	 */ 
	private function startRendering():Void
	{
		#if (flash9 || nme)
		//start the rendering at the root layer renderer
		documentElement.elementRenderer.render(flash.Lib.current, false);
		#end
	}
	
	/**
	 * Start the layout of the rendering tree,
	 * starting with the root ElementRenderer
	 */
	private function startLayout():Void
	{
		//layout all ElementRenderer, after this, ElementRenderer are 
		//aware of their bounds relative to their containing block
		documentElement.elementRenderer.layout(false);
		
		//set the global bounds on the rendering tree. After this, ElementRenderer
		//are aware of their bounds relative ot the viewport
		documentElement.elementRenderer.setGlobalOrigins(0, 0, 0, 0);
	}
	
	/**
	 * Set a timer to trigger a layout and rendering of the document asynchronously.
	 * Setting a timer to execute the layout and rendering ensure that it only
	 * happen once when a series of style values are set or when many elements
	 * are attached/removed from the DOM, instead of happening for every change.
	 */
	private function scheduleLayoutAndRender():Void
	{
		var onLayoutScheduleDelegate:Void->Void = onLayoutSchedule;
		#if (flash9 || nme)
		//calling the methods 1 millisecond later is enough to ensure
		//that first all synchronous code is executed
		Timer.delay(function () { 
			onLayoutScheduleDelegate();
		}, INVALIDATION_INTERVAL);
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Utils method returning the first ElementRenderer whose dom node
	 * is an Element node. This is used when dispatching MouseEvent, as their target
	 * can only be Element node.
	 */
	private function getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent:MouseEvent):ElementRenderer
	{
		var screenX:Float = mouseEvent.screenX;
		var screenY:Float = mouseEvent.screenY;
		var elementRendererAtPoint:ElementRenderer = body.elementRenderer.layerRenderer.getTopMostElementRendererAtPoint( { x: screenX, y: screenY }, 0, 0  );
		
		//when no element is under mouse like for instance when the mouse leaves
		//the window, return the body
		if (elementRendererAtPoint == null)
		{
			return body.elementRenderer;
		}
		
		while (elementRendererAtPoint.node.nodeType != DOMConstants.ELEMENT_NODE || elementRendererAtPoint.isAnonymousBlockBox() == true)
		{
			elementRendererAtPoint = elementRendererAtPoint.parentNode;
			if (elementRendererAtPoint == null)
			{
				return null;
			}
		}
		
		return elementRendererAtPoint;
	}
	
	/**
	 * Utils method returning the first HTMLElement parent which
	 * can be vertically scrolled. The provided htmlElement is returned
	 * if it can be vertically scrolled
	 * 
	 * The scrollOffset is also provided as if a vertically scrollable element
	 * is completely scrolled and adding this offset won't make a difference,
	 * then it is not considered scrollable
	 */
	private function getFirstVerticallyScrollableHTMLElement(htmlElement:HTMLElement, scrollOffset:Int):HTMLElement
	{
		while (htmlElement.isVerticallyScrollable(scrollOffset) == false)
		{
			htmlElement = htmlElement.parentNode;
			if ( htmlElement == null)
			{
				return null;
			}
		}
		
		return htmlElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the activeElement on the focusManager
	 */
	private function set_activeElement(newActiveElement:HTMLElement):HTMLElement
	{	
		_focusManager.setActiveElement(newActiveElement, body);
		return activeElement;
	}
	
	/**
	 * get the active element from the focus manager,
	 */
	private function get_activeElement():HTMLElement
	{
		return _focusManager.activeElement;
	}
}