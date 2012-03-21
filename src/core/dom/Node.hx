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
 * The Node interface is the primary datatype for the entire Document Object Model.
 * It represents a single node in the document tree. While all objects implementing the Node
 * interface expose methods for dealing with children, not all objects implementing the Node
 * interface may have children. For example, Text nodes may not have children, and adding children
 * to such nodes results in a DOMException being raised.
 * 
 * TODO : implement DOMException
 * 
 * The attributes nodeName, nodeValue and attributes are included as a mechanism to get at node
 * information without casting down to the specific derived interface.
 * In cases where there is no obvious mapping of these attributes for a specific nodeType
 * (e.g., nodeValue for an Element or attributes for a Comment), this returns null.
 * Note that the specialized interfaces may contain additional and more convenient mechanisms to get and set the relevant information. 
 * 
 * @author Yannick DOMINGUEZ
 */
class Node 
{
	/**
	 * A value representing the underlying object
	 */
	public var nodeType(get_nodeType, never):NodeType;
	
	/**
	 * The value of this node, depending on its type.
	 * When it is defined to be null, setting it has no effect,
	 * including if the node is read-only
	 */
	public var nodeValue(get_nodeValue, set_nodeValue):String;
	
	/**
	 * The name of this node, depending on its type
	 */
	public var nodeName(get_nodeName, never):String;
	
	/**
	 * The parent of this node. All nodes, except Attr, Document, DocumentFragment,
	 * Entity, and Notation may have a parent. However,
	 * if a node has just been created and not yet added
	 * to the tree, or if it has been removed from the tree, this is null. 
	 * 
	 * TODO : in the spec, it says read only. Should retrieve parent with
	 * ownerDocument instead of storing ref to it ?
	 */
	private var _parentNode:Node;
	public var parentNode(get_parentNode, set_parentNode):Node;
	
	/**
	 * A NodeList that contains all children of this node. 
	 * If there are no children, this is a NodeList containing no nodes.
	 * 
	 * TODO : implement NodeList instead of using Array ?
	 */
	private var _childNodes:Array<Node>;
	public var childNodes(get_childNodes, never):Array<Node>;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Removes the child node indicated by oldChild 
	 * from the list of children, and returns it.
	 * 
	 * @param The node being removed.
	 * @return The node removed.
	 */
	public function removeChild(oldChild:Node):Node
	{
		oldChild.parentNode = null;
		
		var newChildNodes:Array<Node> = new Array<Node>();
		for (i in 0..._childNodes.length)
		{
			if (_childNodes[i] != oldChild)
			{
				newChildNodes.push(_childNodes[i]);
			}
		}
		this._childNodes = newChildNodes;
		
		return oldChild;
	}
	
	/**
	 * Adds the node newChild to the end of the list of children of this node.
	 * If the newChild is already in the tree, it is first removed.
	 * @param	newChild The node to add. If it is a DocumentFragment object, 
	 * the entire contents of the document fragment are moved into the child list of this node
	 * 
	 * TODO : implement DocumentFragment
	 * 
	 * @return The node added.
	 */
	public function appendChild(newChild:Node):Node
	{
		if (newChild.parentNode != null)
		{
			var parentNode:Node = newChild.parentNode;
			parentNode.removeChild(newChild);
		}
		newChild.parentNode = this;
		_childNodes.push(newChild);
		
		return newChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_nodeType():NodeType 
	{
		return null;
	}
	
	private function get_parentNode():Node 
	{
		return _parentNode;
	}
	
	private function set_parentNode(value:Node):Node 
	{
		return _parentNode = value;
	}
	
	private function get_childNodes():Array<Node> 
	{
		return _childNodes;
	}
	
	private function get_nodeValue():String 
	{
		return null;
	}
	
	private function set_nodeValue(value:String):String 
	{
		return value;
	}
	
	private function get_nodeName():String
	{
		return null;
	}
}