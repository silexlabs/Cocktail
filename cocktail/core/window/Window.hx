/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.window;

import cocktail.core.dom.Document;
import cocktail.event.Event;
import cocktail.core.event.EventCallback;
import cocktail.event.EventConstants;
import cocktail.event.UIEvent;
import cocktail.core.html.HTMLAnchorElement;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.port.Bindings;
import cocktail.core.layout.LayoutData;
import cocktail.core.history.History;

/**
 * Represents the window through which the Document is
 * viewed
 * 
 * It holds a reference to the class proxying access
 * to platform specific event and methods
 * 
 * @author Yannick DOMINGUEZ
 */
class Window extends EventCallback
{
	/**
	 * return the document viewed through the window
	 */
	public var document(default, null):HTMLDocument;
	
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
	 * A reference to the history instance
	 */
	public var history:History;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR & INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor. Initialise the Document
	 */
	public function new(htmlDocument:HTMLDocument) 
	{
		super();
		init(htmlDocument);
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		document = null;
		history.dispose();
		history = null;
	}
	
	/**
	 * Initialise the Document and set platform specific
	 * listener on it
	 */
	private function init(htmlDocument:HTMLDocument):Void
	{
		document = htmlDocument;
		setDocumentListener(document);
		
		// history
		history = new History(htmlDocument);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Creates a new secondary browser window and loads the referenced resource.
	 */
	public function open(url:String, name:String = HTMLConstants.TARGET_BLANK):Void
	{
		document.navigateToURL(url, name);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * set listeners for document events which should also be dispatched on the window
	 */
	private function setDocumentListener(document:HTMLDocument):Void
	{
		document.addEventListener(EventConstants.LOAD, function(e) dispatchEvent(e));
		document.addEventListener(EventConstants.RESIZE, function(e) dispatchEvent(e));
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_innerHeight():Int
	{
		return Math.floor(document.getViewportHeight());
	}
	
	private function get_innerWidth():Int
	{
		return Math.floor(document.getViewportWidth());
	}
}
