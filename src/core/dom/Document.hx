/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.dom;

import core.Text;
import core.dom.DOMData;

/**
 * The Document interface represents the entire HTML or XML document.
 * Conceptually, it is the root of the document tree, and provides the
 * primary access to the document's data. Since elements, text nodes,
 * comments, processing instructions, etc. cannot exist outside the
 * context of a Document, the Document interface also contains the
 * factory methods needed to create these objects. The Node objects 
 * created have a ownerDocument attribute which associates them with
 * the Document within whose context they were created. 
 * 
 * TODO : implement ownerDocument ?
 * 
 * @author Yannick DOMINGUEZ
 */
class Document extends Node
{
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
	 * Creates an element of the type specified. 
	 * Note that the instance returned implements the Element interface,
	 * so attributes can be specified directly on the returned object.
	 * 
	 * @param	tagName The name of the element type to instantiate. For XML,
	 * this is case-sensitive, otherwise it depends on the case-sensitivity 
	 * of the markup language in use. In that case, the name is mapped
	 * to the canonical form of that markup by the DOM implementation.
	 * 
	 * @return A new Element object with the nodeName attribute set to tagName,
	 * and localName, prefix, and namespaceURI set to null
	 * 
	 * TODO : implement localName, prefix and namespaceURI
	 */
	public function createElement(tagName:String):Element
	{
		var element:Element = new Element(tagName);
		return element;
	}
	
	/**
	 * Creates a Text node given the specified string.
	 * @param	data The data for the node.
	 * @return The new Text object.
	 */
	public function createTextNode(data:String):Text
	{
		var text:Text = new Text();
		text.nodeValue = data;
		return text;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeType():NodeType
	{
		return NodeType.DOCUMENT_NODE;
	}
	
}