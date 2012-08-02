/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

/**
 * The source element allows authors to specify multiple alternative
 * media resources for media elements. It does not represent anything on its own.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLSourceElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The src attribute gives the address of the media resource. 
	 * The value must be a valid non-empty URL potentially surrounded by spaces. 
	 * This attribute must be present.
	 */
	public var src(get_src, set_src):String;
	
	/**
	 * The type attribute gives the type of the media resource,
	 * to help the user agent determine if it can play this media resource before
	 * fetching it. If specified, its value must be a valid MIME type. 
	 * The codecs parameter, which certain MIME types define, might
	 * be necessary to specify exactly how the resource is encoded.
	 */
	public var type(get_type, set_type):String;
	
	/**
	 * The media attribute gives the intended media type of the media
	 * resource, to help the user agent determine if this media
	 * resource is useful to the user before fetching it.
	 * Its value must be a valid media query.The default,
	 * if the media attribute is omitted, is "all", meaning
	 * that by default the media resource is suitable for all media.
	 * 
	 * TODO 5 : media query not supported
	 */
	public var media(get_media, set_media):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_SOURCE_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The source element is not a visual one
	 */
	override private function createElementRenderer():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as <source /> element are serialised
	 * as self-closing tags
	 */
	override public function isVoidElement():Bool
	{
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_src():String
	{
		return getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME);
	}
	
	private function set_src(value:String):String
	{
		setAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME, value);
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
	
	private function get_media():String
	{
		return getAttribute(HTMLConstants.HTML_MEDIA_ATTRIBUTE_NAME);
	}
	
	private function set_media(value:String):String
	{
		setAttribute(HTMLConstants.HTML_MEDIA_ATTRIBUTE_NAME, value);
		return value;
	}
	
}