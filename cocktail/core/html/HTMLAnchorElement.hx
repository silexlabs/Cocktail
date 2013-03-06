/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.event.Event;
import cocktail.core.event.MouseEvent;
import cocktail.Lib;
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
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Overriden as getting the target attribute require 
	 * extra logic
	 */
	override public function getAttribute(name:String):String
	{
		if (name == HTMLConstants.HTML_TARGET_ATTRIBUTE_NAME)
		{
			return target;
		}
		else
		{
			return super.getAttribute(name);
		}
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
			Lib.window.open(href, target);
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
		return getAttribute(HTMLConstants.HTML_HREF_ATTRIBUTE_NAME);
	}
		
	private function set_target(value:String):String
	{
		setAttribute(HTMLConstants.HTML_TARGET_ATTRIBUTE_NAME, value);
		return value;
	}
	
	private function get_target():String
	{
		var target:String = super.getAttribute(HTMLConstants.HTML_TARGET_ATTRIBUTE_NAME);
		
		if (target == null)
		{
			return HTMLConstants.TARGET_SELF;
		}
		
		return target;
	}
	
	
	
}