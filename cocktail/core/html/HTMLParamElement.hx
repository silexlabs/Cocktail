/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

/**
 * The param element defines parameters for plugins invoked by object elements. 
 * It does not represent anything on its own.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLParamElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The name attribute gives the name of the parameter.
	 */
	public var name(get_name, set_name):String;
	
	/**
	 * The value attribute gives the value of the parameter.
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_PARAM_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The param element is not a visual one
	 */
	override private function createElementRenderer():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN DOM PARSER GETTER/SETTER AND METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as <param> element are serialised
	 * as self-closing tags
	 */
	override public function isVoidElement():Bool
	{
		return true;
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
		return value;
	}
	
	private function get_value():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME);
	}
	
	private function set_value(value:String):String
	{
		setAttribute(HTMLConstants.HTML_VALUE_ATTRIBUTE_NAME, value);
		return value;
	}
	
	
	
	
}