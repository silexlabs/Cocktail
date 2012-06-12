/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;

import cocktail.core.dom.DOMData;

/**
 * he Attr interface represents an attribute in an Element object
 * 
 * @author Yannick DOMINGUEZ
 */
class Attr extends Node<Attr>
{
	/**
	 * Returns the name of this attribute.
	 * If Node.localName is different from null,
	 * this attribute is a qualified name.
	 */
	private var _name:String;
	public var name(get_name, null):String;
	
	/**
	 * On retrieval, the value of the attribute is returned as a string.
	 * Character and general entity references are replaced with their values.
	 * On setting, this creates a Text node with the unparsed contents
	 * of the string, i.e. any characters
	 * that an XML processor would recognize as markup
	 * are instead treated as literal text.
	 * 
	 * TODO 5 : create a Text node ?
	 */
	private var _value:String;
	public var value(get_value, set_value):String;
	
	/**
	 * True if this attribute was explicitly given a value in the instance document,
	 * false otherwise. If the application changed the value of this attribute
	 * node (even if it ends up having the same value as the default value)
	 * then it is set to true.
	 */
	private var _specified:Bool;
	public var specified(get_specified, never):Bool;
	
	/**
	 * Returns whether this attribute is known to be of type ID
	 * (i.e. to contain an identifier for its owner element)
	 * or not. When it is and its value is unique,
	 * the ownerElement of this attribute
	 * can be retrieved using the method Document.getElementById
	 */
	private var _isId:Bool;
	public var isId(get_isId, set_isId):Bool;
	
	/**
	 * The Element node this attribute is attached 
	 * to or null if this attribute is not in use.
	 */
	private var _ownerElement:Element;
	public var ownerElement(get_ownerElement, set_ownerElement):Element;
	
	/**
	 * class constructor
	 */
	public function new(name:String) 
	{
		_name = name;
		_specified = false;
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeName():String
	{
		return _name;
	}
	
	override private function get_nodeType():Int
	{
		return Node.ATTRIBUTE_NODE;
	}
	
	override private function get_nodeValue():String 
	{
		return value;
	}
	
	override private function set_nodeValue(value:String):String 
	{
		return this.value = value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_ownerElement():Element 
	{
		return _ownerElement;
	}
	
	private function set_ownerElement(value:Element):Element 
	{
		return _ownerElement = value;
	}
	
	private function get_isId():Bool
	{
		return _isId;
	}
	
	private function set_isId(value:Bool):Bool
	{
		return _isId = value;
	}
	
	private function get_name():String 
	{
		return _name;
	}
	
	private function get_value():String 
	{
		if (_value == null)
		{
			return "";
		}
		return _value;
	}
	
	private function set_value(value:String):String 
	{
		_specified = true;
		return _value = value;
	}
	
	private function get_specified():Bool 
	{
		return _specified;
	}
	
}