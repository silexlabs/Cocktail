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
import cocktail.core.event.Event;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.focus.FocusManager;
import cocktail.core.HTMLAnchorElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLHtmlElement;
import cocktail.core.html.HTMLImageElement;
import cocktail.core.html.HTMLInputElement;
import cocktail.core.Keyboard;
import cocktail.core.keyboard.AbstractKeyboard;
import cocktail.core.Mouse;
import cocktail.core.NativeElement;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.style.BodyCoreStyle;
import cocktail.core.Window;
import haxe.Log;
import haxe.Timer;

/**
 * An HTMLDocument is the root of the HTML hierarchy and holds the entire content.
 * Besides providing access to the hierarchy, it also provides some convenience methods
 * for accessing certain sets of information from the document.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractHTMLDocument extends Document
{
	/**
	 * special HTML tags
	 */
	
	private static inline var HTML_IMAGE_ELEMENT_TAG_NAME:String = "img";
	
	private static inline var HTML_CANVAS_ELEMENT_TAG_NAME:String = "canvas";
	
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
	 * A reference to the Window, used to listen for
	 * resize events
	 */
	private var _window:Window;
	
	/**
	 * The NativeElements created when rendering
	 * this Document. They are runtime specific
	 */
	private var _nativeElements:Array<NativeElement>;
	
	/**
	 *The activeElement set/get the element
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
	 * An instance of the cross-platform keyboard class, used to listen
	 * to key down and up event
	 */
	private var _keyboard:Keyboard;
	
	/**
	 * An instance of the cross-platform mouse class, used to listen
	 * to mouse input
	 */
	private var _mouse:Mouse;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new() 
	{
		super();
		
		_body = cast(createElement(HTML_BODY_TAG_NAME));
		_documentElement = createElement(HTML_HTML_TAG_NAME);
		_documentElement.appendChild(_body);
		
		_nativeElements = new Array<NativeElement>();
		
		_focusManager = new FocusManager();
		_activeElement = _body;
		
		//listen to the Window resizes
		_window = new Window();
		_window.onResize = onWindowResize;
		
		initKeyboardListeners();
		initMouseListeners();
	}
	
	//TODO : doc
	private function initMouseListeners():Void
	{
		_mouse = new Mouse(NativeElementManager.getRoot());
		_mouse.onMouseDown = onMouseDown;
		_mouse.onMouseUp = onMouseUp;
		_mouse.onMouseMove = onMouseMove;
		_mouse.onClick = onClick;
	}
	
	/**
	 * init keyboard listeners
	 */
	private function initKeyboardListeners():Void
	{
		//listens for event on the root of the runtime
		_keyboard = new Keyboard(NativeElementManager.getRoot());
		_keyboard.onKeyDown = onKeyDown;
		_keyboard.onKeyUp = onKeyUp;
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
				
			case HTML_CANVAS_ELEMENT_TAG_NAME:
				element = new HTMLCanvasElement();
				
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
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The Document is invalidated for instance when the
	 * DOM changes after adding/removing a child or when
	 * a style changes.
	 * When this happen, the Document needs to be layout
	 * and rendered again
	 * 
	 * @param immediate define wether the layout must be synchronous
	 * or asynchronous
	 */
	public function invalidate(immediate:Bool = false):Void
	{
		//either schedule an asynchronous layout and rendering, or layout
		//and render immediately
		if (immediate == false)
		{
			scheduleLayoutAndRender();
		}
		else
		{
			layoutAndRender();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function onMouseDown(mouseEvent:MouseEvent):Void
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = _body.coreStyle.elementRenderer.layerRenderer.getElementRenderersAtPoint( { x: mouseEvent.screenX, y:mouseEvent.screenY } );

		//TODO : if empty array, use body
		for (i in 0...elementRenderersAtPoint.length)
		{
			if (elementRenderersAtPoint[i].coreStyle.htmlElement.onmousedown != null)
			{
				elementRenderersAtPoint[i].coreStyle.htmlElement.onmousedown(mouseEvent);
				break;
			}
		}	
	}
	
	private function onClick(mouseEvent:MouseEvent):Void
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = _body.coreStyle.elementRenderer.layerRenderer.getElementRenderersAtPoint( { x: mouseEvent.screenX, y:mouseEvent.screenY } );

		//TODO : if empty array, use body
		for (i in 0...elementRenderersAtPoint.length)
		{
			if (elementRenderersAtPoint[i].coreStyle.htmlElement.onclick != null)
			{
				elementRenderersAtPoint[i].coreStyle.htmlElement.onclick(mouseEvent);
				break;
			}
		}	
	}
	
	//TODO : implement mouse over and mouse out with this method
	private function onMouseMove(mouseEvent:MouseEvent):Void
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = _body.coreStyle.elementRenderer.layerRenderer.getElementRenderersAtPoint( { x: mouseEvent.screenX, y:mouseEvent.screenY } );

		for (i in 0...elementRenderersAtPoint.length)
		{
			if (elementRenderersAtPoint[i].coreStyle.htmlElement.onmousemove != null)
			{
				elementRenderersAtPoint[i].coreStyle.htmlElement.onmousemove(mouseEvent);
				break;
			}
		}	
	}
	
	private function onMouseUp(mouseEvent:MouseEvent):Void
	{
		var elementRenderersAtPoint:Array<ElementRenderer> = _body.coreStyle.elementRenderer.layerRenderer.getElementRenderersAtPoint( { x: mouseEvent.screenX, y:mouseEvent.screenY } );
		
		for (i in 0...elementRenderersAtPoint.length)
		{
			if (elementRenderersAtPoint[i].coreStyle.htmlElement.onmouseup != null)
			{
				elementRenderersAtPoint[i].coreStyle.htmlElement.onmouseup(mouseEvent);
				break;
			}
		}	
	}
	
	/**
	 * When a key is pressed, redirect it to
	 * the active element and detect if a tab
	 * focus or a simulated click must happen.
	 */
	private function onKeyDown(keyboardEvent:KeyboardEvent):Void
	{
		if (activeElement.onkeydown != null)
		{
			activeElement.onkeydown(keyboardEvent);
		}
		
		switch (keyboardEvent.key)
		{
			case TAB_KEY_CODE:
				//only do sequantial navigation if default was not prevented
				if (keyboardEvent.defaultPrevented == false)
				{
					activeElement = _focusManager.getNextFocusedElement(keyboardEvent.shiftKey == true, _body, activeElement);
				}
				
	
			case ENTER_KEY_CODE, SPACE_KEY_CODE:
				//only simulate click if default was not prevented
				if (keyboardEvent.defaultPrevented == false)
				{
					activeElement.click();
				}
		}
	}
	
	/**
	 * When a key up event happens, redirect to the
	 * currently active HTMLElement
	 */
	private function onKeyUp(keyEventData:KeyboardEvent):Void
	{
		if (activeElement.onkeyup != null)
		{
			activeElement.onkeyup(keyEventData);
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * As the name implies,
	 * layout the DOM, then render it
	 */
	private function layoutAndRender():Void
	{
		layout();
		render();
	}
	
	/**
	 * start the layout, starting on the Body
	 * element which is the root of the visual
	 * elements in an HTML Document
	 */
	private function layout():Void
	{
		var bodyCoreStyle:BodyCoreStyle = cast(_body.coreStyle);
		bodyCoreStyle.startLayout();
	}
	
	/**
	 * Start the rendering of the rendering tree
	 * built during layout
	 * and attach the resulting nativeElements (background,
	 * border, embedded asset...) to the display root
	 * of the runtime (for instance the Stage in Flash)
	 */ 
	private function render():Void
	{
		//first all the previous native elements
		//are detached
		detachNativeElements(_nativeElements);
		
		//start the rendering at the root layer renderer
		_nativeElements = _body.coreStyle.elementRenderer.layerRenderer.render();
		attachNativeElements(_nativeElements);
	}
	
	/**
	 * Attach a NativeElement to the
	 * display root. Runtime specific
	 */ 
	private function attachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Remove a NativeElement from the
	 * display root. Runtime specific.
	 */
	private function detachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Attach an array of NativeElement to the
	 * display root
	 */
	private function attachNativeElements(nativeElements:Array<NativeElement>):Void
	{
		for (i in 0...nativeElements.length)
		{
			attachNativeElement(nativeElements[i]);
		}
	}
	
	/**
	 * Remove an array of NativeElement from the
	 * display root
	 */
	private function detachNativeElements(nativeElements:Array<NativeElement>):Void
	{
		for (i in 0...nativeElements.length)
		{
			detachNativeElement(nativeElements[i]);
		}
	}
	
	/**
	 * Set a timer to trigger a layout and rendering of the HTML Document asynchronously.
	 * Setting a timer to execute the layout and rendering ensure that the layout only happen once when a series of style
	 * values are set or when many elements are attached/removed from the DOM, instead of happening for every change.
	 */
	private function scheduleLayoutAndRender():Void
	{
		var layoutAndRenderDelegate:Void->Void = layoutAndRender;
		
		//calling the methods 1 millisecond later is enough to ensure
		//that first all synchronous code is executed
		Timer.delay(function () { 
			layoutAndRenderDelegate();
		}, 1);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the Window is resized, schedule
	 * a layout and rendering
	 */
	private function onWindowResize(event:Event):Void
	{
		scheduleLayoutAndRender();
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
	private function set_activeElement(value:HTMLElement):HTMLElement
	{			
		//if the activeHTMLElement is set to null, do nothing
		if (value == null)
		{
			return _activeElement;
		}
		
		//do nothing if the new activeHTMLElement is the same
		//as the current one
		if (value != activeElement)
		{
			//else call the blur callback on the element
			if (activeElement.onblur != null)
			{
				activeElement.onblur(new Event(Event.BLUR, activeElement));
			}
			
			//then store the new one and call the focus callback on it
			_activeElement = value;
			if (_activeElement.onfocus != null)
			{
				_activeElement.onfocus(new Event(Event.FOCUS, _activeElement));
			}
		}
		
		return _activeElement;
	}
	

	private function get_activeElement():HTMLElement
	{
		return _activeElement;
	}
}