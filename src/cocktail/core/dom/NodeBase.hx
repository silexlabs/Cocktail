/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;
import cocktail.core.event.EventCallback;
import cocktail.core.event.EventTarget;

/**
 * This base class is inherited by all the elements
 * particpating in a tree data structure, such as the 
 * DOM tree, the rendering tree and the line box tree.
 * 
 * The standard w3c interface is implemented on the 
 * Node object, this base class only exspoes
 * method used to traverse a tree of data
 * 
 * @author Yannick DOMINGUEZ
 */
class NodeBase<NodeClass:NodeBase<NodeClass>> extends EventCallback
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
	 * class constructor
	 */
	public function new() 
	{
		super();
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
		
		var newChildNodes:Array<NodeClass> = new Array<NodeClass>();
		
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			if (childNodes[i] != oldChild)
			{
				newChildNodes.push(childNodes[i]);
			}
		}
		childNodes = newChildNodes;
		
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
			//will store the new child nodes with the newly inserted one
			var newChildNodes:Array<NodeClass> = new Array<NodeClass>();
			
			var length:Int = childNodes.length;
			for (i in 0...length)
			{
				if (childNodes[i] == refChild)
				{
					newChildNodes.push(newChild);
				}
				newChildNodes.push(childNodes[i]);
			}
			
			//the child are appended after the first loop to prevent
			//from modifying the child node array while looping
			for (i in 0...newChildNodes.length)
			{
				appendChild(newChildNodes[i]);
			}
			
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
			var length:Int = parentNode.childNodes.length;
			for (i in 0...length)
			{
				if (isSameNode(parentNode.childNodes[i]) == true)
				{
					return parentNode.childNodes[i + 1];
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
				if (isSameNode(parentNode.childNodes[i]) == true)
				{
					return parentNode.childNodes[i - 1];
				}
			}
		}
		
		return null;
	}
}