/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.css.CSSStyleSheet;
import cocktail.core.dom.DOMConstants;
import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.UIEvent;
import cocktail.core.resource.AbstractResource;
import cocktail.core.resource.ResourceManager;
import cocktail.core.css.CSSData;

/**
 * The link element allows authors to link their document to other resources.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLLinkElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The IDL attribute disabled only applies to style sheet links. 
	 * When the link element defines a style sheet link, then the
	 * disabled attribute behaves as defined for the alternative style
	 * sheets DOM. For all other link elements it always return
	 * false and does nothing on setting.
	 */
	public var disabled(get_disabled, set_disabled):Bool;
	
	/**
	 * The destination of the link(s) is given by the href attribute,
	 * which must be present and must contain a valid non-empty URL
	 * potentially surrounded by spaces. If the href attribute
	 * is absent, then the element does not define a link.
	 * 
	 */
	public var href(get_href, set_href):String;
	
	/**
	 * The types of link indicated (the relationships) are given by
	 * the value of the rel attribute, which, if present, must have
	 * a value that is a set of space-separated tokens.
	 * If the rel attribute is absent, has no keywords,
	 * or if none of the keywords used are allowed then the 
	 * element does not create any links.
	 */
	public var rel(get_rel, set_rel):String;
	
	/**
	 * A list of the space separated rel attributes
	 */
	public var relList(get_relList, null):Array<String>;
	
	/**
	 * The media attribute says which media the resource
	 * applies to. The value must be a valid media query.
	 */
	public var media(get_media, set_media):String;
	
	/**
	 * The hreflang attribute on the link element has the same semantics
	 * as the hreflang attribute on a and area elements.
	 */
	public var hreflang(get_hreflang, set_hreflang):String;
	
	/**
	 * The type attribute gives the MIME type of the linked resource. 
	 * It is purely advisory. The value must be a valid MIME type.
	 * 
	 * For external resource links, the type attribute is used as a
	 * hint to user agents so that they can avoid fetching resources
	 * they do not support.
	 */
	public var type(get_type, set_type):String;
	
	/**
	 * A reference to the CSS style sheet created by this
	 * node's content. It is null by default, a style sheet
	 * is only created if this element has a text child
	 * node and is attached to the DOM
	 */
	public var sheet(default, null):CSSStyleSheet;
	
	public function new() 
	{
		super(HTMLConstants.HTML_LINK_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden, as when the style element is added
	 * to the DOM, it adds a style sheet to the 
	 * document if it has a child text node
	 */
	override public function attach():Void
	{
		super.attach();
		addStyleSheet();
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
	 * 
	 * TODO 1 : clean-up class
	 */
	private function addStyleSheet():Void
	{
		if (type == "text/css" && href != null && rel == "stylesheet")
		{
			var text:AbstractResource = ResourceManager.getTextResource(href);
			if (text.loaded == true)
			{
				createStyleSheet(text.nativeResource);
			}
			else
			{
				text.addEventListener(EventConstants.LOAD, onCSSLoaded);
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
	
	private function onCSSLoaded(event:Event):Void
	{
		var text:AbstractResource = cast(event.target);
		createStyleSheet(text.nativeResource);
	}
	
	private function createStyleSheet(css:String):Void
	{
		sheet = new CSSStyleSheet(css, PropertyOriginValue.AUTHOR);
		var htmlDocument:HTMLDocument = cast(ownerDocument);
		htmlDocument.addStyleSheet(sheet);
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
	
	private function get_href():String
	{
		return getAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME);
	}
	
	private function set_href(value:String):String
	{
		setAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_rel():String
	{
		return getAttribute(HTMLConstants.HTML_REL_ATTRIBUTE_NAME);
	}
	
	private function set_rel(value:String):String
	{
		setAttribute(HTMLConstants.HTML_REL_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_relList():Array<String>
	{
		return [];
	}
	
	private function get_media():String
	{
		return getAttribute(HTMLConstants.HTML_MEDIA_ATTRIBUTE_NAME);
	}
	
	private function set_media(value:String):String
	{
		setAttribute(HTMLConstants.HTML_MEDIA_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_hreflang():String
	{
		return getAttribute(HTMLConstants.HTML_HREFLANG_ATTRIBUTE_NAME);
	}
	
	private function set_hreflang(value:String):String
	{
		setAttribute(HTMLConstants.HTML_HREFLANG_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_type():String
	{
		return getAttribute(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME);
	}
	
	private function set_type(value:String):String
	{
		setAttribute(HTMLConstants.HTML_TYPE_ATTRIBUTE_NAME, value);
		return value;
	}
	
}