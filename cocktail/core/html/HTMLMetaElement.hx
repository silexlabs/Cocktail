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
	
	/**
	 * when added to dom, check wether this meta
	 * update the config of the document
	 */
	override private function addedToDOM():Void
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
		return getAttributeAsDOMString(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME);
	}
	
	private function set_name(value:String):String
	{
		setAttribute(HTMLConstants.HTML_NAME_ATTRIBUTE_NAME, value);
		updateConfig();
		return value;
	}
	
	private function get_content():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_CONTENT_ATTRIBUTE_NAME);
	}
	
	private function set_content(value:String):String
	{
		setAttribute(HTMLConstants.HTML_CONTENT_ATTRIBUTE_NAME, value);
		updateConfig();
		return value;
	}
	
}