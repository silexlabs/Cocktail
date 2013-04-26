/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.css;

import cocktail.core.html.HTMLElement;

/**
 * The StyleSheet interface represents an abstract,
 * base style sheet.
 * 
 * @author Yannick DOMINGUEZ
 */
class StyleSheet 
{
	/**
	 * The type attribute return
	 * the style sheet type. (The literal string "text/css".)
	 */
	public var type(default, null):String;
	
	/**
	 * returns The URL of the style sheet or null
	 * if the style sheet was embedded.
	 */
	public var href(default, null):String;
	
	/**
	 * The DOM node associated with the style
	 * sheet or null if there is no associated DOM node.
	 */
	public var ownerNode(default, null):HTMLElement;
	
	/**
	 * The style sheet that is the parent of the style sheet.
	 * (used when using "@import" in a stylesheet)
	 */
	public var parentStyleSheet(default, null):StyleSheet;
	
	/**
	 * The title of the style sheet. It is said to be empty
	 * if the title is the empty string.
	 */
	public var title(default, null):String;
	
	/**
	 * The MediaList object associated with the
	 * style sheet.
	 */
	public var media(default, null):MediaList;
	
	/**
	 * The disabled attribute return true if the style
	 * sheet disabled flag is set, or false otherwise.
	 */
	public var disabled:Bool;
	
	/**
	 * class constructor
	 * @param	stylesheet the whole css style sheet
	 */
	public function new(stylesheet:String, ownerNode:HTMLElement = null, href:String = null, parentStyleSheet:StyleSheet = null) 
	{
		this.ownerNode = ownerNode;
		this.href = href;
		this.parentStyleSheet = parentStyleSheet;
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		
	}
	
}