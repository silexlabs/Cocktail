/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.dom;

import cocktail.core.event.EventCallback;
import cocktail.core.event.EventTarget;
import haxe.Log;

interface INode<NodeClass>{
	var parentNode:NodeClass;
	var childNodes(default, null):Array<NodeClass>;
	var firstChild(get, never):NodeClass;
	var lastChild(get, never):NodeClass;
	function cloneNode(deep:Bool):NodeClass;
	function removeChild(oldChild:NodeClass):NodeClass;
}

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
class Node<NodeClass:(EventCallback, INode<NodeClass>)> extends EventCallback implements INode<NodeClass>
{	
	/**
	 * The parent of this node. All nodes, except Attr, Document, DocumentFragment,
	 * Entity, and Notation may have a parent. However,
	 * if a node has just been created and not yet added
	 * to the tree, or if it has been removed from the tree, this is null.
	 */
	public var parentNode:NodeClass;
	
	/**
	 * A NodeList that contains all children of this node. 
	 * If there are no children, this is a NodeList containing no nodes.
	 */
	public var childNodes(default, null):Array<NodeClass>;
	
	/**
	 * The first child of this node. If there is no such node,
	 * this returns null.
	 */
	public var firstChild(get_firstChild, never):NodeClass;
	
	/**
	 * The last child of this node. If there is no such node,
	 * this returns null.
	 */
	public var lastChild(get_lastChild, never):NodeClass;
	
	/**
	 * The node immediately following this node. 
	 * If there is no such node, this returns null.
	 */
	public var nextSibling(get_nextSibling, never):NodeClass;
	
	/**
	 * The node immediately preceding this node. 
	 * If there is no such node, this returns null.
	 */
	public var previousSibling(get_previousSibling, never):NodeClass;
	
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
	 * A NamedNodeMap containing the attributes of this node 
	 * (if it is an Element) or null otherwise.
	 */
	public var attributes(default, null):NamedNodeMap<NodeClass>;
	
	/**
	 * The Document object associated with this node. 
	 * This is also the Document object used to create new nodes.
	 * When this node is a Document or a DocumentType
	 * which is not used with any Document yet, this is null.
	 */
	public var ownerDocument(default, set_ownerDocument):Document;
	
	/**
	 * The textContent attribute must return the following, depending on the context object:
	 *
	 *	DocumentFragment
	 *	Element
	 *	The concatenation of data of all the Text node descendants of the context object, in tree order.
	 *
	 *	Text
	 *	ProcessingInstruction
	 * 	Comment
	 *	The context object's data.
	 * 
	 *  Any other node
	 *	Null.
	 * 
	 * TODO : implement setting
	 */
	public var textContent(get_textContent, null):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		initChildNodes();
	}
	
	/**
	 * Instantiate an array to hold child nodes
	 * for this node
	 */
	private function initChildNodes():Void
	{
		childNodes = new Array<NodeClass>();
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
	public function removeChild(oldChild:NodeClass):NodeClass
	{
		oldChild.parentNode = null;
		childNodes.remove(oldChild);
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
	public function appendChild(newChild:NodeClass):NodeClass
	{
		removeFromParentIfNecessary(newChild);
		
		newChild.parentNode = cast(this);
		childNodes.push(newChild);
	
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
	public function insertBefore(newChild:NodeClass, refChild:NodeClass):NodeClass
	{
		if (refChild == null)
		{
			appendChild(newChild);
		}
		else
		{	
			var length:Int = childNodes.length;
			for (i in 0...length)
			{		
				if (childNodes[i] == refChild)
				{
					childNodes.insert(i, newChild);
					
					//set the parent of the new child
					removeFromParentIfNecessary(newChild);
					newChild.parentNode = cast(this);
					return newChild;
				}
			}
			
			//if the ref child wasn't found, throw
			//a dom exception
			throw DOMException.NOT_FOUND_ERR;
		}
		
		return newChild;
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
	public function isSameNode(other:NodeClass):Bool
	{
		return other == this;
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
	public function replaceChild(newChild:NodeClass, oldChild:NodeClass):NodeClass
	{
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			if (childNodes[i] == oldChild)
			{
				removeChild(oldChild);
				appendChild(newChild);
			}
		}
		
		return oldChild;
	}
	
	/**
	 * Returns whether this node has any children.
	 */
	public function hasChildNodes():Bool
	{
		return childNodes.length > 0;
	}
	
	/**
	 * Returns a duplicate of this node, i.e., serves as a generic copy constructor for nodes.
	 * The duplicate node has no parent (parentNode is null) and no user data. 
	 * User data associated to the imported node is not carried over. However, if any UserDataHandlers
	 * has been specified along with the associated data these handlers will be called with
	 * the appropriate parameters before this method returns.
	 * 
	 * Cloning an Element copies all attributes and their values, including those generated by the
	 * XML processor to represent defaulted attributes, but this method does not copy any
	 * children it contains unless it is a deep clone. This includes text contained in an
	 * the Element since the text is contained in a child Text node. Cloning an Attr directly,
	 * as opposed to be cloned as part of an Element cloning operation, returns a specified attribute
	 * (specified is true). Cloning an Attr always clones its children, since they represent its value,
	 * no matter whether this is a deep clone or not. Cloning an EntityReference automatically constructs
	 * its subtree if a corresponding Entity is available, no matter whether this is a deep clone or not.
	 * Cloning any other type of node simply returns a copy of this node.
	 * 
	 * Note that cloning an immutable subtree results in a mutable copy, but the children
	 * of an EntityReference clone are readonly. In addition, clones of unspecified Attr nodes
	 * are specified. And, cloning Document, DocumentType, Entity, and Notation nodes is implementation dependent.
	 * 
	 * @param	deep If true, recursively clone the subtree under the specified node; 
	 * if false, clone only the node itself (and its attributes, if it is an Element).
	 * @return The duplicate node
	 */
	public function cloneNode(deep:Bool):NodeClass
	{
		var clonedNode:Node<NodeClass> = doCloneNode();
		if (deep == true)
		{
			var childLength:Int = childNodes.length;
			for (i in 0...childLength)
			{
				clonedNode.appendChild(childNodes[i].cloneNode(deep));
			}
		}
		return cast(clonedNode);
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
		var parent:NodeClass = parentNode;
		var targetAncestors:Array<EventTarget> = super.getTargetAncestors();
		
		while (parent != null)
		{
			targetAncestors.push(parent);
			parent = parent.parentNode;
		}
		
		return targetAncestors;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * clone this node and return the clone.
	 * What gets clone varies for each
	 * node type
	 */
	private function doCloneNode():NodeClass
	{
		return cast(new Node<NodeClass>());
	}
		
	/**
	 * When a node is about to be added to another, 
	 * first detach it if it was already attached to the tree
	 */
	private function removeFromParentIfNecessary(newChild:NodeClass):Void
	{
		if (newChild.parentNode != null)
		{
			var parentNode:NodeClass = newChild.parentNode;
			parentNode.removeChild(newChild);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_firstChild():NodeClass
	{
		if (hasChildNodes() == true)
		{
			return childNodes[0];
		}
		else
		{
			return null;
		}
	}
	
	private function get_lastChild():NodeClass
	{
		if (hasChildNodes() == true)
		{
			return childNodes[childNodes.length - 1];
		}
		else
		{
			return null;
		}
	}
	
	private function get_nextSibling():NodeClass
	{
		//if the node is not attached, it
		//has no siblings
		if (parentNode == null)
		{
			return null;
		}
		
		else if (parentNode.lastChild != this)
		{
			//loop in all child to find this node and return
			//the next one
			var parentChildNodes:Array<NodeClass> = parentNode.childNodes;
			var length:Int = parentChildNodes.length;
			for (i in 0...length)
			{
				//TODO IMPORTANT : big hack for php target. Without
				//this specific method, comparaison does'nt use strict
				//equality ("===") and cause infinite loop. It seems simpler
				//to correct here than to subclass for php target
				#if php
				if (untyped __physeq__(parentChildNodes[i], this))
				#else
				if (parentChildNodes[i] == this)
				#end
				{
					return parentChildNodes[i + 1];
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
	private function get_previousSibling():NodeClass
	{
		if (parentNode == null)
		{
			return null;
		}
		else if (parentNode.firstChild != this)
		{
			var length:Int = parentNode.childNodes.length;
			for (i in 0...length)
			{
				if (parentNode.childNodes[i] == this)
				{
					return parentNode.childNodes[i - 1];
				}
			}
		}
		
		return null;
	}
	
	private function get_nodeType():Int 
	{
		return -1;
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
	
	private function set_ownerDocument(value:Document):Document
	{
		return ownerDocument = value;
	}
	
	private function get_nodeName():String
	{
		return null;
	}
	
	private function get_textContent():String
	{
		return null;
	}
}