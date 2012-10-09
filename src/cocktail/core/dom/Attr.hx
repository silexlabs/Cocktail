/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.dom;

import cocktail.core.html.HTMLElement;

/**
 * the Attr interface represents an attribute in an Element object
 * 
 * @author Yannick DOMINGUEZ
 */
class Attr<ElementClass:Node<ElementClass>> extends Node<Attr<ElementClass>>
{
	/**
	 * Returns the name of this attribute.
	 * If Node.localName is different from null,
	 * this attribute is a qualified name.
	 */
	public var name(default, null):String;
	
	/**
	 * On retrieval, the value of the attribute is returned as a string.
	 * Character and general entity references are replaced with their values.
	 * On setting, this creates a Text node with the unparsed contents
	 * of the string, i.e. any characters
	 * that an XML processor would recognize as markup
	 * are instead treated as literal text.
	 */
	public var value(get_value, set_value):String;
	
	/**
	 * True if this attribute was explicitly given a value in the instance document,
	 * false otherwise. If the application changed the value of this attribute
	 * node (even if it ends up having the same value as the default value)
	 * then it is set to true.
	 */
	public var specified(default, null):Bool;
	
	/**
	 * Returns whether this attribute is known to be of type ID
	 * (i.e. to contain an identifier for its owner element)
	 * or not. When it is and its value is unique,
	 * the ownerElement of this attribute
	 * can be retrieved using the method Document.getElementById
	 */
	public var isId:Bool;
	
	/**
	 * The Element node this attribute is attached 
	 * to or null if this attribute is not in use.
	 */
	public var ownerElement:ElementClass;
	
	/**
	 * class constructor
	 */
	public function new(name:String) 
	{
		this.name = name;
		specified = false;
		super();
	}
	
	/**
	 * attribute nodes can't have children
	 */
	override private function initChildNodes():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as attr node clone its own attributes
	 */
	override private function doCloneNode():Attr<ElementClass>
	{
		var clonedAttr:Attr<ElementClass> = new Attr<ElementClass>(this.name);
		clonedAttr.specified = this.specified;
		clonedAttr.isId = this.isId;
		clonedAttr.value = this.value;
		
		return clonedAttr;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeName():String
	{
		return name;
	}
	
	override private function get_nodeType():Int
	{
		return DOMConstants.ATTRIBUTE_NODE;
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
	
	private function get_value():String 
	{
		if (value == null)
		{
			return "";
		}
		return value;
	}
	
	private function set_value(value:String):String 
	{
		specified = true;
		return this.value = value;
	}
}