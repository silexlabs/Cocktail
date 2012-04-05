/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.focus.FocusManager;
import cocktail.core.dom.Document;
import cocktail.core.dom.Element;
import cocktail.core.event.Event;
import cocktail.core.HTMLAnchorElement;
import cocktail.core.HTMLElement;
import cocktail.core.HTMLHtmlElement;
import cocktail.core.HTMLImageElement;
import cocktail.core.HTMLInputElement;
import cocktail.core.NativeElement;
import cocktail.core.style.BodyCoreStyle;
import cocktail.core.Window;
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
	 * The element that contains the content for the document.
	 */
	private var _body:HTMLElement;
	public var body(get_body, never):HTMLElement;
	
	/**
	 * A reference to the Window used to listen for
	 * resize events
	 */
	private var _window:Window;
	
	private var _nativeElements:Array<NativeElement>;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		_body = createElement(HTML_BODY_TAG_NAME);
		
		_documentElement = new HTMLHtmlElement();
		_documentElement.appendChild(_body);
		
		_nativeElements = new Array<NativeElement>();
		
		//TODO : should not be singleton
		FocusManager.getInstance().bodyElement = cast(_body);
		
		//listen to the Window resizes
		_window = new Window();
		_window.onResize = onWindowResize;
		
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
	 * The BodyHTMLElement doesn't have a parent, so when invalidated,
	 * it always schedule a layout using the window dimensions as
	 * its containing HTMLElement dimensions
	 */
	public function invalidate(immediate:Bool = false):Void
	{
		//either schedule an asynchronous layout, or layout immediately
		if (immediate == false)
		{
			scheduleLayoutAndRender();
		}
		else
		{
			layout();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the view port is resized, insvalidate
	 * this BodyHTMLElement to lay it out with
	 * the new Window dimensions
	 */
	private function onWindowResize(event:Event):Void
	{
		scheduleLayoutAndRender();
	}
	
	private function layoutAndRender():Void
	{
		layout();
		render();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function layout():Void
	{
		var bodyCoreStyle:BodyCoreStyle = cast(_body.coreStyle);
		bodyCoreStyle.layout();
	}
	
	/**
	 * Start the rendering of the rendering tree
	 * and attach the resulting nativeElement (background,
	 * border, embedded asset...) to the provided
	 * nativeElement
	 */ 
	public function render():Void
	{
		detachNativeElements(_nativeElements);
		_nativeElements = _body.coreStyle.elementRenderer.layerRenderer.render();
		attachNativeElements(_nativeElements);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Attach a NativeElement to the
	 * styled HTMLElement using runtime specific API
	 */ 
	private function attachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Remove a NativeElement from the
	 * styled HTMLElement using runtime specific API
	 */
	private function detachNativeElement(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Attach an array of NativeElement to the
	 * styled HTMLElement using runtime specific API
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
	 * styled HTMLElement using runtime specific API
	 */
	private function detachNativeElements(nativeElements:Array<NativeElement>):Void
	{
		for (i in 0...nativeElements.length)
		{
			detachNativeElement(nativeElements[i]);
		}
	}
	
	/**
	 * Set a timer to trigger a layout of the HTMLElement asynchronously. this method is used by the invalidation
	 * mechanism. Setting a timer to execute the layout ensure that the layout only happen once when a series of style
	 * values are set instead of happening for every change.
	 */
	private function scheduleLayoutAndRender():Void
	{
		var layoutAndRenderDelegate:Void->Void = layoutAndRender;
		
		Timer.delay(function () { 
			layoutAndRenderDelegate();
		}, 1);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_body():HTMLElement 
	{
		return _body;
	}
}