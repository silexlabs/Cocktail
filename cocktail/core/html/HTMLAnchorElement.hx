/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.event.Event;
import cocktail.event.MouseEvent;
import haxe.Log;

/**
 * The anchor element, used to link to an external document, or
 * to scroll to a position in the current document
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLAnchorElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The absolute URI of the linked resource.
	 * This attribute specifies the location of a Web resource, thus defining
	 * a link between the current element (the source anchor)
	 * and the destination anchor defined by this attribute.
	 */
	public var href(get_href, set_href):String;
	
	/**
	 * Frame to render the resource in.
	 * This attribute specifies the name of a frame where a document is to be opened.
	 */
	public var target(get_target, set_target):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_ANCHOR_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ACTIVATION BEHAVIOUR
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The anchor HTMLElement has the default behaviour
	 * of following a link
	 */
	override public function hasActivationBehaviour():Bool
	{
		return true;
	}
	
	/**
	 * Follow the link after the click event was dispatched
	 */
	override public function runPostClickActivationStep(event:MouseEvent):Void
	{
		if (event.defaultPrevented == true)
		{
			return;
		}
		openDocument();
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDE PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * An anchor is inherently focusable if its
	 * href is defined
	 */
	override private function isDefaultFocusable():Bool
	{
		if (href != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open the linked document using
	 * the Window object
	 */
	private function openDocument():Void
	{
		if (href != null)
		{
			_ownerHTMLDocument.navigateToURL(href, target);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTER_SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_href(value:String):String
	{
		setAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_href():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME);
	}
		
	private function set_target(value:String):String
	{
		setAttribute(HTMLConstants.HTML_TARGET_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_target():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_TARGET_ATTRIBUTE_NAME);
	}
	
	
	
}
