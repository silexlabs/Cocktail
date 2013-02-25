/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.core.config.Config;

/**
 * The meta element represents various kinds of metadata that
 * cannot be expressed using the title, base, link, style,
 * and script elements.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLMetaElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The name of the metadata
	 */
	public var name(get_name, set_name):String;
	
	/**
	 * The content of the metadata
	 */
	public var content(get_content, set_content):String;

	public function new() 
	{
		super(HTMLConstants.HTML_META_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ATTRIBUTE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setAttribute(attributeName:String, value:String):Void
	{
		if (attributeName == HTMLConstants.HTML_NAME_ATTRIBUTE_NAME)
		{
			name = value;
		}
		else if (attributeName == HTMLConstants.HTML_CONTENT_ATTRIBUTE_NAME)
		{
			content = value;
		}
		else
		{
			super.setAttribute(attributeName, value);
		}
	}
	
	override public function getAttribute(attributeName:String):String
	{
		if (attributeName == HTMLConstants.HTML_NAME_ATTRIBUTE_NAME)
		{
			return name;
		}
		else if (attributeName == HTMLConstants.HTML_CONTENT_ATTRIBUTE_NAME)
		{
			return content;
		}
		else
		{
			return super.getAttribute(attributeName);
		}
	}
	
	/**
	 * when added to dom, check wether this meta
	 * update the config of the document
	 */
	override public function addedToDOM():Void
	{
		super.addedToDOM();
		updateConfig();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Some meta tag might be used to override
	 * config params of the document
	 */
	private function updateConfig():Void
	{
		if (isAttachedToDOM() == true && name != null && content != null)
		{
			Config.getInstance().updateConfig(name, content);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_name():String
	{
		return super.getAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME);
	}
	
	private function set_name(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME, value);
		updateConfig();
		return value;
	}
	
	private function get_content():String
	{
		return super.getAttribute(HTMLConstants.HTML_CONTENT_ATTRIBUTE_NAME);
	}
	
	private function set_content(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_CONTENT_ATTRIBUTE_NAME, value);
		updateConfig();
		return value;
	}
	
}