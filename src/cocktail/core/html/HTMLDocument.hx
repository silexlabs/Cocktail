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
import cocktail.core.event.FocusEvent;
import haxe.Log;
import haxe.Timer;

/**
 * An HTMLDocument is the root of the HTML hierarchy and holds the entire content.
 * Besides providing access to the hierarchy, it also provides some convenience methods
 * for accessing certain sets of information from the document.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLDocument extends Document
{
	/**
	 * special HTML tags
	 */
	
	private static inline var HTML_IMAGE_ELEMENT_TAG_NAME:String = "img";
	
	private static inline var HTML_INPUT_ELEMENT_TAG_NAME:String = "input";
	
	private static inline var HTML_ANCHOR_ELEMENT_TAG_NAME:String = "a";
	
	private static inline var HTML_HTML_TAG_NAME:String = "html";
	
	private static inline var HTML_BODY_TAG_NAME:String = "body";
	
	/**
	 * key code listened to by the Document
	 */
	
	private static inline var TAB_KEY_CODE:Int = 9;
	
	private static inline var ENTER_KEY_CODE:Int = 13;
	
	private static inline var SPACE_KEY_CODE:Int = 32;
	
	/**
	 * The element that contains the content for the document.
	 * 
	 * The body is the root of the visual content in HTML
	 */
	private var _body:HTMLBodyElement;
	public var body(get_body, never):HTMLBodyElement;
	
	/**
	 * The activeElement set/get the element
	 * in the document which is focused.
	 * If no element in the Document is focused, this returns the body element. 
	 */
	private var _activeElement:HTMLElement;
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
	 * class constructor. Init class attributes
	 */
	public function new() 
	{
		super();
		
		_body = cast(createElement(HTML_BODY_TAG_NAME));
		_body.attach();
		
		_documentElement = createElement(HTML_HTML_TAG_NAME);
		_documentElement.appendChild(_body);
		
		_focusManager = new FocusManager();
		_activeElement = _body;
		
		_hoveredElementRenderer = _body.elementRenderer;
		
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
		
		switch (tagName.toLowerCase())
		{
			case HTML_IMAGE_ELEMENT_TAG_NAME:
				element = new HTMLImageElement();
				
			case HTML_INPUT_ELEMENT_TAG_NAME:
				element = new HTMLInputElement();
				
			case HTML_ANCHOR_ELEMENT_TAG_NAME:
				element = new HTMLAnchorElement();
				
			case HTML_HTML_TAG_NAME:
				element = new HTMLHtmlElement(); 
				
			case HTML_BODY_TAG_NAME:
				element = new HTMLBodyElement();
				
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
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent);
		elementRendererAtPoint.node.dispatchEvent(mouseEvent);
	}
	
	public function onPlatformMouseWheelEvent(mouseEvent:MouseEvent):Void
	{
		onPlatformMouseEvent(mouseEvent);
	}
	
	/**
	 * Mouse click event are a special case of
	 * mouse event dispatching, as they may trigger
	 * activation behaviour, such as following a 
	 * link for an HTMLAnchorElement
	 */
	public function onPlatformMouseClickEvent(mouseEvent:MouseEvent):Void
	{
		var elementRendererAtPoint:ElementRenderer = getFirstElementRendererWhichCanDispatchMouseEvent(mouseEvent);

		var htmlElement:HTMLElement = cast(elementRendererAtPoint.node);
		
		//find the first parent of the HTMLElement which has an activation behaviour, might
		//return null
		var nearestActivatableElement:HTMLElement = htmlElement.getNearestActivatableElement();

		//execute pre activation
		if (nearestActivatableElement != null)
		{
			nearestActivatableElement.runPreClickActivation();
		}
		
		htmlElement.dispatchEvent(mouseEvent);
		
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
			
			elementRendererAtPoint.dispatchEvent(mouseOverEvent);
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
					activeElement = _focusManager.getNextFocusedElement(keyboardEvent.shiftKey == true, _body, activeElement);
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
		_body.invalidateLayout();
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
		var elementRendererAtPoint:ElementRenderer = _body.elementRenderer.layerRenderer.getTopMostElementRendererAtPoint( { x: mouseEvent.screenX, y:mouseEvent.screenY }, 0, 0  );
		
		while (elementRendererAtPoint.node.nodeType != Node.ELEMENT_NODE)
		{
			elementRendererAtPoint = cast(elementRendererAtPoint.parentNode);
			if (elementRendererAtPoint == null)
			{
				return null;
			}
		}
		
		return elementRendererAtPoint;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_body():HTMLBodyElement 
	{
		return _body;
	}
	
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
			return _activeElement;
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
			var oldActiveElement:HTMLElement = _activeElement;
			
			//if the new activeElement is not focusable, the focus
			//is instead given to the HTMLBodyElement
			if (newActiveElement.isFocusable() == true)
			{
				_activeElement = newActiveElement;
			}
			else
			{
				_activeElement = _body;
			}
			
			//dispatch post-focus event which don't bubbles through the document
			
			var blurEvent:FocusEvent = new FocusEvent();
			blurEvent.initFocusEvent(FocusEvent.BLUR, false, false, null, 0.0, null);
			oldActiveElement.dispatchEvent(blurEvent);
			
			var focusEvent:FocusEvent = new FocusEvent();
			focusEvent.initFocusEvent(FocusEvent.FOCUS, false, false, null, 0.0, null);
			newActiveElement.dispatchEvent(focusEvent);
			
			if (_activeElement.onfocus != null)
			{
				var focusEvent:FocusEvent = new FocusEvent();
				focusEvent.initFocusEvent(FocusEvent.FOCUS, true, false, null, 0.0, null);
				
				_activeElement.onfocus(focusEvent);
			}
		}
		
		return _activeElement;
	}
	

	private function get_activeElement():HTMLElement
	{
		return _activeElement;
	}
}