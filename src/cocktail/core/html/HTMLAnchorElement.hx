/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.event.Event;
import cocktail.core.mouse.MouseCursorManager;
import cocktail.core.event.MouseEvent;
import cocktail.core.dom.DOMData;
import cocktail.Lib;
import haxe.Log;
import cocktail.core.mouse.MouseData;

/**
 * The anchor element, used to link to an external document, or
 * to scroll to a position in the current document
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLAnchorElement extends HTMLElement
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

	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN MOUSE SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When the mouse up callback is retrieved, for instance when it needs to be called
	 * as a mouse up event has been dispatched over this HTMLElement, it returns
	 * a custom callback which not only executes the user callback if provided
	 * but also executes the default behaviour ofthe anchor element which is to 
	 * try to open the link
	 */
	override private function get_onMouseUp():MouseEvent->Void
	{
		return onMouseUpCallback;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// MOUSE EVENT CALLBACK
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the link in addition to calling the user callback
	 */
	private function onMouseUpCallback(mouseEvent:MouseEvent):Void
	{
		if (_onMouseUp != null)
		{
			_onMouseUp(mouseEvent);
		}
		
		//check wether a user callback canceled
		//the default behaviour
		if (mouseEvent.defaultPrevented == false)
		{
			openDocument();
		}
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ACTIVATION BEHAVIOUR
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The anchor HTMLElement has the default behaviour
	 * of following a link
	 */
	override public function hasActivationBehaviour():Bool
	{
		return true;
	}
	
	/**
	 * Follow the link after the click event was dispatched
	 */
	override public function runPostClickActivationStep(event:MouseEvent):Void
	{
		if (event.defaultPrevented == true)
		{
			return;
		}
		onMouseUpCallback(cast(event));
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDE PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An anchor is inherently focusable if its
	 * href is defined
	 */
	override private function isDefaultFocusable():Bool
	{
		if (href != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the linked document using
	 * the Window object
	 */
	private function openDocument():Void
	{
		if (_href != null)
		{
			Lib.window.open(_href, _target);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOCUMENT LINK SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_href(value:String):String
	{
		return 	_href = value;
	}
	
	private function get_href():String
	{
		return _href;
	}
		
	private function set_target(value:String):String
	{
		return _target = value;
	}
	
	private function get_target():String
	{
		return _target;
	}
	
	
	
}