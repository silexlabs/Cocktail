/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;

import cocktail.core.dom.DOMData;
import cocktail.core.event.EventCallback;
import cocktail.core.event.EventTarget;
import haxe.Log;

/**
 * The Node interface is the primary datatype for the entire Document Object Model.
 * It represents a single node in the document tree. While all objects implementing the Node
 * interface expose methods for dealing with children, not all objects implementing the Node
 * interface may have children. For example, Text nodes may not have children, and adding children
 * to such nodes results in a DOMException being raised.
 * 
 * TODO 5 : implement DOMException in all of the DOM package
 * 
 * The attributes nodeName, nodeValue and attributes are included as a mechanism to get at node
 * information without casting down to the specific derived interface.
 * In cases where there is no obvious mapping of these attributes for a specific nodeType
 * (e.g., nodeValue for an Element or attributes for a Comment), this returns null.
 * Note that the specialized interfaces may contain additional and more convenient mechanisms to get and set the relevant information. 
 * 
 * @author Yannick DOMINGUEZ
 */
class Node extends EventCallback
{
	/**
	 * The node is an Element.
	 */
	public static inline var ELEMENT_NODE:Int = 1;
	
	/**
	 * The node is an Attr.
	 */
	public static inline var ATTRIBUTE_NODE:Int = 2;
	
	/**
	 * The node is a Text node.
	 */ 
	public static inline var TEXT_NODE:Int = 3;
	
	/**
	 * The node is a CDATASection.
	 */
	public static inline var CDATA_SECTION_NODE:Int = 4;
	
	/**
	 * The node is an EntityReference.
	 */
	public static inline var ENTITY_REFERENCE_NODE:Int = 5;
	
	/**
	 * The node is an Entity.
	 */
	public static inline var ENTITY_NODE:Int = 6;
	
	/**
	 * The node is a ProcessingInstruction.
	 */
	public static inline var PROCESSING_INSTRUCTION_NODE:Int = 7;
	
	/**
	 * The node is a Comment.
	 */
	public static inline var COMMENT_NODE:Int = 8;
	
	/**
	 * The node is a Document.
	 */
	public static inline var DOCUMENT_NODE:Int = 9;
	
	/**
	 * The node is a DocumentType.
	 */
	public static inline var DOCUMENT_TYPE_NODE:Int = 10;
	
	/**
	 * The node is a DocumentFragment.
	 */
	public static inline var DOCUMENT_FRAGMENT_NODE:Int = 11;
	
	/**
	 * The node is a Notation.
	 */
	public static inline var NOTATION_NODE:Int = 11;
	
	/**
	 * A value representing the underlying object
	 */
	public var nodeType(get_nodeType, never):Int;
	
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
	 */
	private var _parentNode:Node;
	public var parentNode(get_parentNode, set_parentNode):Node;
	
	/**
	 * A NodeList that contains all children of this node. 
	 * If there are no children, this is a NodeList containing no nodes.
	 */
	private var _childNodes:Array<Node>;
	public var childNodes(get_childNodes, never):Array<Node>;
	
	/**
	 * The first child of this node. If there is no such node,
	 * this returns null.
	 */
	public var firstChild(get_firstChild, never):Node;
	
	/**
	 * The last child of this node. If there is no such node,
	 * this returns null.
	 */
	public var lastChild(get_lastChild, never):Node;
	
	/**
	 * The node immediately following this node. 
	 * If there is no such node, this returns null.
	 */
	public var nextSibling(get_nextSibling, never):Node;
	
	/**
	 * The node immediately preceding this node. 
	 * If there is no such node, this returns null.
	 */
	public var previousSibling(get_previousSibling, never):Node;
	
	/**
	 * A NamedNodeMap containing the attributes of this node 
	 * (if it is an Element) or null otherwise.
	 */
	private var _attributes:NamedNodeMap;
	public var attributes(get_attributes, never):NamedNodeMap;
	
	/**
	 * The Document object associated with this node. 
	 * This is also the Document object used to create new nodes.
	 * When this node is a Document or a DocumentType
	 * which is not used with any Document yet, this is null.
	 */
	private var _ownerDocument:Document;
	public var ownerDocument(get_ownerDocument, set_ownerDocument):Document;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		_childNodes = new Array<Node>();
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
	 * TODO 5 : implement DocumentFragment
	 * 
	 * @return The node added.
	 */
	public function appendChild(newChild:Node):Node
	{
		//TODO 5 : don't seem to work, bug with HTMLBodyElement ?
		//if (newChild.ownerDocument != _ownerDocument)
		//{
			//Raised if newChild was created from a different
			//document than the one that created this node.
			//throw DOMException.WRONG_DOCUMENT_ERR;
		//}
		//
		
		removeFromParentIfNecessary(newChild);
		
		newChild.parentNode = this;
		_childNodes.push(newChild);
	
		return newChild;
	}
	
	/**
	 * Inserts the node newChild before the existing child node refChild. 
	 * If refChild is null, insert newChild at the end of the list of children.
	 * If newChild is a DocumentFragment object, all of its children are
	 * inserted, in the same order, before refChild. 
	 * If the newChild is already in the tree, it is first removed.	
	 * 
	 * @param	newChild The node to insert.
	 * @param	refChild The reference node, i.e., the node before 
	 * which the new node must be inserted.
	 * @return	The node being inserted
	 */
	public function insertBefore(newChild:Node, refChild:Node):Node
	{
		if (refChild == null)
		{
			appendChild(newChild);
		}
		else
		{	
			for (i in 0..._childNodes.length)
			{
				if (_childNodes[i] == refChild)
				{
					appendChild(newChild);
				}
				appendChild(_childNodes[i]);
			}
		}
		
		return newChild;
	}
	
	/**
	 * Replaces the child node oldChild with newChild in the list of children,
	 * and returns the oldChild node.
	 * If newChild is a DocumentFragment object, oldChild is replaced by all
	 * of the DocumentFragment children, which are inserted in the same order.
	 * If the newChild is already in the tree, it is first removed.
	 * 
	 * @param	newChild The new node to put in the child list.
	 * @param	oldChild The node being replaced in the list.
	 * @return	The node replaced.
	 */
	public function replaceChild(newChild:Node, oldChild:Node):Node
	{
		for (i in 0..._childNodes.length)
		{
			if (_childNodes[i] == oldChild)
			{
				removeChild(oldChild);
				appendChild(newChild);
			}
		}
		
		return oldChild;
	}
	
	/**
	 * Returns whether this node is the same node as the given one.
	 * This method provides a way to determine whether two Node
	 * references returned by the implementation reference
	 * the same object. When two Node references are references
	 * to the same object, even if through a proxy, the references 
	 * may be used completely interchangeably, such that all attributes
	 * have the same values and calling the same DOM method on either
	 * reference always has exactly the same effect.
	 * 
	 * @param	other The node to test against.
	 * @return Returns true if the nodes are the same, false otherwise.
	 */
	public function isSameNode(other:Node):Bool
	{
		return other == this;
	}
	
	/**
	 * Returns whether this node has any children.
	 */
	public function hasChildNodes():Bool
	{
		return _childNodes.length > 0;
	}
	
	/**
	 * Returns whether this node (if it is an element) has any attributes. 
	 * Always false for any other Node sub classes
	 */
	public function hasAttributes():Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return all the parent of the node until the root
	 * node is reached
	 */
	override private function getTargetAncestors():Array<EventTarget>
	{
		var parent:Node = _parentNode;
		var targetAncestors:Array<EventTarget> = new Array<EventTarget>();
		
		while (parent != null)
		{
			targetAncestors.push(parent);
			parent = parent.parentNode;
		}
		
		return targetAncestors;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a node is about to be added to another, 
	 * first detach it if it was already attached to the tree
	 */
	private function removeFromParentIfNecessary(newChild:Node):Void
	{
		if (newChild.parentNode != null)
		{
			var parentNode:Node = newChild.parentNode;
			parentNode.removeChild(newChild);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_firstChild():Node
	{
		if (hasChildNodes() == true)
		{
			return _childNodes[0];
		}
		else
		{
			return null;
		}
	}
	
	private function get_lastChild():Node
	{
		if (hasChildNodes() == true)
		{
			return _childNodes[_childNodes.length - 1];
		}
		else
		{
			return null;
		}
	}
	
	private function get_nextSibling():Node
	{
		//if the node is not attached, it
		//has no siblings
		if (_parentNode == null)
		{
			return null;
		}
		
		else if (_parentNode.lastChild != this)
		{
			//loop in all child to find this node and return
			//the next one
			for (i in 0..._parentNode.childNodes.length)
			{
				if (isSameNode(_parentNode.childNodes[i]) == true)
				{
					return _parentNode.childNodes[i + 1];
				}
			}
		}
		
		//if the node is the last of its parent, it has no
		//next sibling
		return null;
	}
	
	/**
	 * same as get_nextSibling
	 */
	private function get_previousSibling():Node
	{
		if (_parentNode == null)
		{
			return null;
		}
		else if (_parentNode.firstChild != this)
		{
			for (i in 0..._parentNode.childNodes.length)
			{
				if (isSameNode(_parentNode.childNodes[i]) == true)
				{
					return _parentNode.childNodes[i - 1];
				}
			}
		}
		
		return null;
	}
	
	private function get_nodeType():Int 
	{
		return -1;
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
		if (value != null)
		{
			//Raised when the node is readonly and if it is not defined to be null.
			throw DOMException.NO_MODIFICATION_ALLOWED_ERR;
		}
		
		return value;
	}
	
	private function get_nodeName():String
	{
		return null;
	}
	
	private function get_attributes():NamedNodeMap 
	{
		return null;
	}
	
	private function get_ownerDocument():Document
	{
		return _ownerDocument;
	}
	
	private function set_ownerDocument(value:Document):Document
	{
		return _ownerDocument = value;
	}
}