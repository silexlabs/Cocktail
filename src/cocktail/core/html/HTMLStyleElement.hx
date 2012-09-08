/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

import cocktail.core.css.CSSStyleSheet;
import cocktail.core.css.StyleSheet;
import cocktail.core.dom.DOMConstants;
import cocktail.core.css.CSSData;

/**
 * The style element allows authors to embed style information in their documents.
 * The style element is one of several inputs to the styling processing model.
 * The element does not represent content for the user.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLStyleElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public var disabled(get_disabled, set_disabled):Bool;
	
	/**
	 * A reference to the CSS style sheet created by this
	 * node's content. It is null by default, a style sheet
	 * is only created if this element has a text child
	 * node and is attached to the DOM
	 */
	public var sheet(default, null):CSSStyleSheet;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_STYLE_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to try to add a style sheet to the document if a
	 * text node child is appended to this style node
	 */
	override public function appendChild(newChild:HTMLElement):HTMLElement
	{
		super.appendChild(newChild);
		
		if (newChild.nodeType == DOMConstants.TEXT_NODE)
		{
			addStyleSheet();
		}
		
		return newChild;
	}
	
	/**
	 * remove the style sheet from the document when
	 * a text node child is removed
	 */
	override public function removeChild(oldChild:HTMLElement):HTMLElement
	{
		super.removeChild(oldChild);
		
		if (oldChild.nodeType == DOMConstants.TEXT_NODE)
		{
			removeStyleSheet();
		}
		
		return oldChild;
	}
	
	/**
	 * Overriden, as when the style element is added
	 * to the DOM, it adds a style sheet to the 
	 * document if it has a child text node
	 */
	override public function attach():Void
	{
		addStyleSheet();
		
		//attach after to prevent uncesseray
		//cascading
		super.attach();
	}

	/**
	 * Overriden as when this node is removed
	 * from the dom, it must also remove its 
	 * style sheet from the document if any
	 */
	override public function detach():Void
	{
		super.detach();
		removeStyleSheet();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * To actually add a style sheet to the 
	 * document, the style node must both be
	 * attached to the DOM and have a text
	 * child node
	 */
	private function addStyleSheet():Void
	{
		if (hasChildNodes() == true)
		{
			if (childNodes[0].nodeType == DOMConstants.TEXT_NODE)
			{
				if (sheet == null)
				{
					//create a style sheet from the content of the child text node
					sheet = new CSSStyleSheet(childNodes[0].nodeValue, PropertyOriginValue.AUTHOR, this);
					var htmlDocument:HTMLDocument = cast(ownerDocument);
					htmlDocument.addStyleSheet(sheet);
				}
			}
		}
	}
	
	/**
	 * Remove the style sheet from the document
	 * if it was previously added
	 */
	private function removeStyleSheet():Void
	{
		if (sheet != null)
		{
			var htmlDocument:HTMLDocument = cast(ownerDocument);
			htmlDocument.removeStyleSheet(sheet);
			sheet = null;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The style element is not a visual one
	 */
	override private function createElementRenderer():Void
	{
		
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_disabled():Bool
	{
		if (getAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME) != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private function set_disabled(value:Bool):Bool
	{
		super.setAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
}