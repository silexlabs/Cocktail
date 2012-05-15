/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.window;

import cocktail.core.dom.Document;
import cocktail.core.event.Event;
import cocktail.core.event.EventTarget;
import cocktail.core.html.HTMLAnchorElement;

/**
 * Represents the window through which the Document is
 * viewed
 * 
 * TODO : should implement onload callback
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractWindow extends EventTarget
{
	/**
	 * callback called when the window is resized, such as
	 * when in a browser, the browser is resized
	 */
	private var _onResize:Event->Void;
	public var onResize(get_onResize, set_onResize):Event->Void;
	
	/**
	 * return the document viewed through the window
	 */
	private var _document:Document;
	public var document(get_document, never):Document;
	
	/**
	 * Height (in pixels) of the browser window viewport including,
	 * if rendered, the horizontal scrollbar.
	 */
	public var innerHeight(get_innerHeight, never):Int;
	
	/**
	 * Width (in pixels) of the browser window viewport including,
	 * if rendered, the vertical scrollbar.
	 */
	public var innerWidth(get_innerWidth, never):Int;
	
	/**
	 * class constructor. Store a ref
	 * to the provided document
	 * 
	 * TODO : Window should instantiate Document but window object
	 * is instantiated multiple time to listen to resize event
	 */
	public function new(document:Document = null) 
	{
		super();
		_document = document;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Creates a new secondary browser window and loads the referenced resource.
	 * 
	 * TODO : this is a partial implementation for now, should return
	 * the created window and allow parameters
	 */
	public function open(url:String, name:String = HTMLAnchorElement.TARGET_BLANK):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_onResize(value:Event->Void):Event->Void
	{
		return _onResize = value;
	}
	
	private function get_onResize():Event->Void
	{
		return _onResize;
	}
	
	private function get_innerHeight():Int
	{
		return -1;
	}
	
	private function get_innerWidth():Int
	{
		return -1;
	}
	
	private function get_document():Document
	{
		return _document;
	}
}