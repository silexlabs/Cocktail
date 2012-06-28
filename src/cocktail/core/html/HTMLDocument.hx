/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.dom.Document;
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
	public var activeElement(default, set_activeElement):HTMLElement;
	
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
	 * class constructor. Init class attributes
	 */
	public function new() 
	{
		super();
		
		documentElement = createElement(HTMLConstants.HTML_HTML_TAG_NAME);
		initBody(cast(createElement(HTMLConstants.HTML_BODY_TAG_NAME)));
		documentElement.appendChild(body);
		_focusManager = new FocusManager();
		_shouldDispatchClickOnNextMouseUp = false;
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
	 * TODO 5 : always true for now, as it
	 * is always supported by the flash target
	 */
	private function get_fullscreenEnabled():Bool
	{
		return true;
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
		
		while (elementRendererAtPoint.node.nodeType != Node.ELEMENT_NODE || elementRendererAtPoint.isAnonymousBlockBox() == true)
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
			htmlElement = cast(htmlElement.parentNode);
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
	 * When a new activeElement is set, call 
	 * the focus out (blur) method on the previous
	 * one and then call the focus in on the 
	 * new one
	 */
	private function set_activeElement(newActiveElement:HTMLElement):HTMLElement
	{			
		//if the activeHTMLElement is set to null, do nothing
		if (newActiveElement == null)
		{
			return activeElement;
		}
		
		//the first time this setter is called, the activeElement
		//is null and it is set to the body element
		if (activeElement == null)
		{
			return activeElement = newActiveElement;
		}
		
		//do nothing if the new activeHTMLElement is the same
		//as the current one
		if (newActiveElement != activeElement)
		{
			//else dispatch a serie of FocusEvent on the element losing
			//focus and on the one gaining it
			
			//dispatch pre-focus shift focus event which bubbles in the document
			
			var focusOutEvent:FocusEvent = new FocusEvent();
			focusOutEvent.initFocusEvent(FocusEvent.FOCUS_OUT, true, false, null, 0.0, newActiveElement);
			activeElement.dispatchEvent(focusOutEvent);
			
			var focusInEvent:FocusEvent = new FocusEvent();
			focusInEvent.initFocusEvent(FocusEvent.FOCUS_IN, true, false, null, 0.0, activeElement);
			newActiveElement.dispatchEvent(focusInEvent);
			
			//store the new active element before dispatching focus and blur event
			var oldActiveElement:HTMLElement = activeElement;
			
			//if the new activeElement is not focusable, the focus
			//is instead given to the HTMLBodyElement
			if (newActiveElement.isFocusable() == true)
			{
				activeElement = newActiveElement;
			}
			else
			{
				activeElement = body;
			}
			
			//dispatch post-focus event which don't bubbles through the document
			
			var blurEvent:FocusEvent = new FocusEvent();
			blurEvent.initFocusEvent(FocusEvent.BLUR, false, false, null, 0.0, null);
			oldActiveElement.dispatchEvent(blurEvent);
			
			var focusEvent:FocusEvent = new FocusEvent();
			focusEvent.initFocusEvent(FocusEvent.FOCUS, false, false, null, 0.0, null);
			newActiveElement.dispatchEvent(focusEvent);
			
			if (activeElement.onfocus != null)
			{
				var focusEvent:FocusEvent = new FocusEvent();
				focusEvent.initFocusEvent(FocusEvent.FOCUS, true, false, null, 0.0, null);
				
				activeElement.onfocus(focusEvent);
			}
		}
		
		return activeElement;
	}
}