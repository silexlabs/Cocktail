/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail;

import cocktail.core.html.HTMLDocument;
import cocktail.core.Window;

/**
 * Entry point of the Cocktail library
 * mimicking js.Lib
 * 
 * @author Yannick DOMINGUEZ
 */
class Lib 
{
	/**
	 * Return the html document
	 */
	private static var _document:HTMLDocument;
	public static var document(get_document, never):HTMLDocument;
	
	/**
	 * return the window
	 */
	private static var _window:Window;
	public static var window(get_window, never):Window;
	
	/**
	 * class constructor. private as this
	 * class is used through static methods
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * instantiate Docuement and Window, called
	 * the first time either of them is requested
	 */
	private static function init():Void
	{
		_document = new HTMLDocument();
		_window = new Window(_document);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STATIC GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private static function get_document():HTMLDocument 
	{
		if (_document == null)
		{
			init();
		}
		
		return _document;
	}
	
	private static function get_window():Window
	{
		if (_window == null)
		{
			init();
		}
		return _window;
	}
	
	
	
}