/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

/**
 * The title element represents the document's title or name. 
 * Authors should use titles that identify their documents even
 * when they are used out of context, for example 
 * in a user's history or bookmarks, or in search results.
 * The document's title is often different from its first heading,
 * since the first heading does not have to stand alone when taken out of context.
 * There must be no more than one title element per document.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLTitleElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The IDL attribute text must return a concatenation of the contents of all 
	 * the Text nodes that are children of the title element
	 * (ignoring any other nodes such as comments or elements),
	 * in tree order. On setting, it must act the same way as the textContent IDL attribute.
	 */
	public var text(get_text, set_text):String;

	public function new() 
	{
		super(HTMLConstants.HTML_TITLE_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_text():String
	{
		return textContent;
	}
	
	private function set_text(value:String):String
	{
		//TODO : implement using textContent once textContent setter implemented
		return value;
	}
}