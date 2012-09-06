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
class Node<NodeClass:Node<NodeClass>> extends NodeBase<NodeClass>
{	
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
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns whether this node (if it is an element) has any attributes. 
	 * Always false for any other Node sub classes
	 */
	public function hasAttributes():Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
}