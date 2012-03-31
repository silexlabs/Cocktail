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
	 * it can't be changed afterwards.
	 */
	public function new(tagName:String) 
	{
		_tagName = tagName;
		super();
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