/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail;

import cocktail.html.Document;
import cocktail.html.DOMWindow;

/**
 * Entry point of the Cocktail library
 * mimicking js.Browser
 * 
 * @author Yannick DOMINGUEZ
 */
class Browser 
{
	/**
	 * Return the html document
	 */
	public static var document(default, null):Document;
	
	/**
	 * return the window
	 */
	public static var window(default, null):DOMWindow;
	
	/**
	 * class constructor. private as this
	 * class is used through static methods
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * instantiate Docuement and Window, called
	 * the first time either of them is requested
	 */
	public static function init(htmlDocument:Document):Void
	{
		document = htmlDocument;
		window = document.window;
	}
}