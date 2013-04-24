/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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