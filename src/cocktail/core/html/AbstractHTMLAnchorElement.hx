/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.mouse.MouseCursorManager;
import cocktail.core.nativeElement.NativeElementManager;
import cocktail.core.nativeElement.NativeElementData;
import cocktail.core.event.MouseEvent;
import cocktail.core.dom.DOMData;
import haxe.Log;
import cocktail.core.mouse.MouseData;


#if (flash9 || nme)
import cocktail.port.flash_player.HTMLElement;

#elseif js
import cocktail.port.browser.HTMLElement;

#end

/**
 * The anchor element, used to link to an external document, or
 * to scroll to a position in the current document
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractHTMLAnchorElement extends HTMLElement
{
	//target const
	
	/**
	 * Opens the linked document in a new window or tab
	 */ 
	public static inline var TARGET_BLANK:String = "_blank";
	
	/**
	 * Opens the linked document in the same frame as it was clicked (this is default)
	 */
	public static inline var TARGET_SELF:String = "_self";
	
	/**
	 * Opens the linked document in the parent frame
	 */
	public static inline var TARGET_PARENT:String = "_parent";
	
	/**
	 * Opens the linked document in the full body of the window
	 */
	public static inline var TARGET_TOP:String = "_top";
	
	/**
	 * the html tag name for the anchor
	 */
	private static inline var HTML_ANCHOR_TAG_NAME:String = "a";
	
	/**
	 * The absolute URI of the linked resource.
	 * This attribute specifies the location of a Web resource, thus defining
	 * a link between the current element (the source anchor)
	 * and the destination anchor defined by this attribute.
	 */
	private var _href:String;
	public var href(get_href, set_href):String;
	
	/**
	 * Frame to render the resource in.
	 * This attribute specifies the name of a frame where a document is to be opened.
	 */
	private var _target:String;
	public var target(get_target, set_target):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTML_ANCHOR_TAG_NAME);
		_target = TARGET_SELF;
	}
	
	/**
	 * create a native anchor element
	 */
	override private function initNativeElement():Void
	{
		_nativeElement = NativeElementManager.createNativeElement(NativeElementTypeValue.anchor);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When setting a mouse down callback, it is always
	 * set on the mouse for the HTML anchor as even
	 * if the user sets a null callback for the mouse down
	 * event, the callback must be called to follow the
	 * http link if it is provided
	 */
	override private function set_onMouseDown(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseDown = value;
		_mouse.onMouseDown = onMouseDownCallback;
		
		return _onMouseDown;
	}
	
	/**
	 * Same as mouse down, the callbakc is always set
	 * to add the default behaviour of setting the mouse
	 * cursor on mouse over
	 */
	override private function set_onMouseOver(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseOver = value;
		_mouse.onMouseOver = onMouseOverCallback;
		
		return _onMouseOver;
	}
	
	/**
	 * Same as mouse out
	 */
	override private function set_onMouseOut(value:MouseEvent->Void):MouseEvent->Void
	{
		_onMouseOut = value;
		_mouse.onMouseOut = onMouseOutCallback;
		
		return _onMouseOut;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE EVENT CALLBACK
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the link in addition to calling the user callback
	 */
	override private function onMouseDownCallback(mouseEvent:MouseEvent):Void
	{
		if (_onMouseDown != null)
		{
			_onMouseDown(mouseEvent);
		}
		
		//check wether a user callback canceled
		//the default behaviour
		if (mouseEvent.defaultPrevented == false)
		{
			openDocument();
		}
	}

	/**
	 * Display a pointer cursor when hovering an anchor
	 */
	override private function onMouseOverCallback(mouseEvent:MouseEvent):Void
	{
		if (_onMouseOver != null)
		{
			_onMouseOver(mouseEvent);
		}
		
		displayPointerCursor();
	}
	
	/**
	 * Remove the pointer cursor when hovering out of an anchor
	 */
	override private function onMouseOutCallback(mouseEvent:MouseEvent):Void
	{
		if (_onMouseOut != null)
		{
			_onMouseOut(mouseEvent);
		}
		
		hidePointerCursor();
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the linked document using
	 * runtime specific API. Overriden
	 * by runtime as needed
	 */
	private function openDocument():Void
	{
		//abstract
	}
	
	/**
	 * set the pointer cursor
	 */
	private function displayPointerCursor():Void
	{
		MouseCursorManager.setMouseCursor(MouseCursorValue.native(NativeOSMouseCursorValue.pointer));
	}
	
	/**
	 * switch back to the default cursor
	 */
	private function hidePointerCursor():Void
	{
		MouseCursorManager.setMouseCursor(MouseCursorValue.cssAuto);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOCUMENT LINK SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * set the href attribute and refresh
	 * the mouse down callback with the new href
	 * value
	 */
	private function set_href(value:String):String
	{
		_href = value;
		set_onMouseDown(_onMouseDown);
		set_onMouseOver(_onMouseOver);
		set_onMouseOut(_onMouseOut);
		return value;
	}
	
	private function get_href():String
	{
		return _href;
	}
		
	/**
	 * set the target attribute and refresh
	 * the mouse down callback with the new target
	 * value
	 */
	private function set_target(value:String):String
	{
		_target = value;
		set_onMouseDown(_onMouseDown);
		set_onMouseOver(_onMouseOver);
		set_onMouseOut(_onMouseOut);
		return value;
	}
	
	private function get_target():String
	{
		return _target;
	}
	
	
	
}