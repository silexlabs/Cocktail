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
class Node<NodeClass:Node<NodeClass>> extends NodeBase<NodeClass>
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
	 * A NamedNodeMap containing the attributes of this node 
	 * (if it is an Element) or null otherwise.
	 */
	private var _attributes:NamedNodeMap<NodeClass>;
	public var attributes(get_attributes, never):NamedNodeMap<NodeClass>;
	
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
	
	private function get_nodeName():String
	{
		return null;
	}
	
	private function get_attributes():NamedNodeMap<NodeClass>
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