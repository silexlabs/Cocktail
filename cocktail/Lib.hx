/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail;

import cocktail.core.html.HTMLDocument;
import cocktail.core.window.Window;

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
	public static var document(get_document, null):HTMLDocument;
	
	/**
	 * return the window
	 */
	public static var window(get_window, null):Window;
	
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
		
		//window = new Window();
		//document = window.document;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// STATIC GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private static function get_document():HTMLDocument 
	{
		if (document == null)
		{
			init();
		}
		
		return document;
	}
	
	private static function get_window():Window
	{
		if (window == null)
		{
			init();
		}
		return window;
	}
	
	
	
}