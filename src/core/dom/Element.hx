/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.dom;

import core.dom.DOMData;

/**
 * The Element interface represents an element in an HTML or XML document.
 * Elements may have attributes associated with them; since the Element interface 
 * inherits from Node, the generic Node interface attribute attributes may be used
 * to retrieve the set of all attributes for an element. There are methods on the
 * Element interface to retrieve either an Attr object by name or an attribute
 * value by name. In XML, where an attribute value may contain entity references,
 * an Attr object should be retrieved to examine the possibly fairly complex sub-tree
 * representing the attribute value. On the other hand, in HTML, where all attributes 
 * have simple string values, methods to directly access an attribute value can
 * safely be used as a convenience.
 * 
 * @author Yannick DOMINGUEZ
 */
class Element extends Node
{

	/**
	 * The name of the element
	 */
	private var _tagName:String;
	public var tagName(get_tagName, never):String;
	
	/**
	 * returns a reference to the first child node of that element which is of nodeType Element.
	 * returns, null if this Element has no child nodes or no Element child nodes
	 */
	public var firtsElementChild(get_firstElementChild, never):Element;
	
	/**
	 * returns a reference to the first last child node of that element which is of nodeType Element.
	 * returns, null if this Element has no child nodes or no Element child nodes
	 */
	public var lastElementChild(get_lastElementChild, never):Element;
	
	/**
	 * returns a reference to the first previous sibling element which is of nodeType Element.
	 * returns, null if this Element has no previous siblings or none of them are Element
	 */
	public var previousElementSibling(get_previousElementSibling, never):Element;
	
	/**
	 * returns a reference to the first next sibling element which is of nodeType Element.
	 * returns, null if this Element has no next siblings or none of them are Element
	 */
	public var nextElementSibling(get_nextElementSibling, never):Element;
	
	/**
	 * Returns the number of children of this Element which are 
	 * Element
	 */
	public var childElementCount(get_childElementCount, never):Int;
	
	/**
	 * class constructor. Set the name of the tag,
	 * it can't be changed afterwards. Instantiate
	 * the attribute node map here because it is the
	 * only type of node which can have any
	 */
	public function new(tagName:String) 
	{
		_tagName = tagName;
		_attributes = new NamedNodeMap();
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Retrieves an attribute value by name.
	 * 
	 * @param	name The name of the attribute to retrieve.
	 * @return The Attr value as a string, or the empty string
	 * if that attribute does not have a specified or default value.
	 */
	public function getAttribute(name:String):String
	{
		var attribute:Attr = getAttributeNode(name);
		if (attribute != null)
		{
			return attribute.value;
		}
		else
		{
			return null;
		}
	}
	
	/**
	 * Adds a new attribute. If an attribute with that name
	 * is already present in the element,
	 * its value is changed to be that of the value parameter.
	 * This value is a simple string; it is not parsed as it
	 * is being set. So any markup (such as syntax to be
	 * recognized as an entity reference) is treated as
	 * literal text, and needs to be appropriately escaped
	 * by the implementation when it is written out.
	 * In order to assign an attribute value that contains
	 * entity references, the user must create an Attr
	 * node plus any Text and EntityReference nodes,
	 * build the appropriate subtree,
	 * and use setAttributeNode to assign it as the value of an attribute.
	 * 
	 * @param	name The name of the attribute to create or alter.
	 * @param	value Value to set in string form.
	 */
	public function setAttribute(name:String, value:String):Void
	{
		var attribute:Attr = cast(_attributes.getNamedItem(name));
		if (attribute == null)
		{
			attribute = new Attr(name);
			_attributes.setNamedItem(attribute);
		}
		
		attribute.value = value;
	}
	
	/**
	 * Retrieves an attribute node by name.
	 * 
	 * @param	name The name (nodeName) of the
	 * attribute to retrieve.
	 * @return The Attr node with the specified name 
	 * (nodeName) or null if there is no such attribute.
	 */
	public function getAttributeNode(name:String):Attr
	{
		var attribute:Node = _attributes.getNamedItem(name);
		
		if (attribute != null)
		{
			return cast(attribute);
		}
		
		return null;
	}
	
	/**
	 * Adds a new attribute node. If an attribute with that name
	 * (nodeName) is already present in the element, 
	 * it is replaced by the new one. 
	 * Replacing an attribute node by itself has no effect.
	 * 
	 * @param newAttr The Attr node to add to the attribute list.
	 * @return If the newAttr attribute replaces an existing attribute,
	 * the replaced Attr node is returned, otherwise null is returned.
	 */
	public function setAttributeNode(newAttr:Attr):Attr
	{
		return cast(_attributes.setNamedItem(newAttr));
	}
	
	/**
	 * Removes an attribute by name. If a default value for the removed
	 * attribute is defined in the DTD, a new attribute
	 * immediately appears with the default value as well 
	 * as the corresponding namespace URI, local name, and prefix 
	 * when applicable. 
	 * If no attribute with this name is found, this method has no effect.
	 * 
	 * @param	name The name of the attribute to remove.
	 */
	public function removeAttribute(name:String):Void
	{
		_attributes.removeNamedItem(name);
	}
	
	/**
	 * Returns true when an attribute with a given name 
	 * is specified on this element or has a default value, false otherwise.
	 * 
	 * @param	name The name of the attribute to look for.
	 * @return true if an attribute with the given name 
	 * is specified on this element or has a default value, false otherwise.
	 */
	public function hasAttribute(name:String):Bool
	{
		return _attributes.getNamedItem(name) != null;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeName():String
	{
		return _tagName;
	}
	
	override private function get_nodeType():NodeType
	{
		return NodeType.ELEMENT_NODE;
	}
	
	override private function get_attributes():NamedNodeMap 
	{
		return _attributes;
	}
	
	override private function get_hasAttributes():Bool
	{
		return _attributes.length > 0;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// ELEMENT TRAVERSAL GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_firstElementChild():Element
	{
		if (hasChildNodes == false)
		{
			return null;
		}
		
		if (firstChild.nodeType == NodeType.ELEMENT_NODE)
		{
			return cast(firstChild);
		}
		else
		{
			for (i in 0..._childNodes.length)
			{
				if (_childNodes[i].nodeType == NodeType.ELEMENT_NODE)
				{
					return cast(_childNodes[i]);
				}
			}
		}
		
		return null;
	}
	
	private function get_lastElementChild():Element
	{
		if (hasChildNodes == false)
		{
			return null;
		}
		
		if (lastChild.nodeType == NodeType.ELEMENT_NODE)
		{
			return cast(lastChild);
		}
		else
		{
			for (i in _childNodes.length...0)
			{
				if (_childNodes[i].nodeType == NodeType.ELEMENT_NODE)
				{
					return cast(_childNodes[i]);
				}
			}
		}
		
		return null;
	}
	
	private function get_nextElementSibling():Element
	{
		if (nextSibling == null)
		{
			return null;
		}
		
		var nextElementSibling:Node = nextSibling;
		
		while (nextElementSibling.nodeType != NodeType.ELEMENT_NODE)
		{
			nextElementSibling = nextElementSibling.nextSibling;
			
			if (nextElementSibling == null)
			{
				return null;
			}
		}
		
		return cast(nextElementSibling);
	}
	
	private function get_previousElementSibling():Element
	{
		if (previousSibling == null)
		{
			return null;
		}
		
		var previousElementSibling:Node = previousSibling;
		
		while (previousElementSibling.nodeType != NodeType.ELEMENT_NODE)
		{
			previousElementSibling = previousElementSibling.previousSibling;
			
			if (previousElementSibling == null)
			{
				return null;
			}
		}
		
		return cast(previousElementSibling);
	}
	
	private function get_childElementCount():Int
	{
		var childElementCount:Int = 0;
		
		for (i in 0..._childNodes.length)
		{
			if (_childNodes[i].nodeType == NodeType.ELEMENT_NODE)
			{
				childElementCount++;
			}
		}
		
		return childElementCount;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_tagName():String 
	{
		return _tagName;
	}
}