/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;

import cocktail.core.html.HTMLElement;
import cocktail.core.Text;
import cocktail.core.dom.DOMData;

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
 * @author Yannick DOMINGUEZ
 */
class Document extends Node
{
	/**
	 * This is a convenience attribute that allows direct access
	 * to the child node that is the document element of the document.
	 */
	private var _documentElement:Element;
	public var documentElement(get_documentElement, never):Element;
	
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
	 * TODO : for ownerDocument, when should it be set when
	 * instantiating classes ?
	 */
	public function createElement(tagName:String):HTMLElement
	{
		var element:HTMLElement = new HTMLElement(tagName);
		element.ownerDocument = this;
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
	
	/**
	 * Creates an Attr of the given name. Note that the 
	 * Attr instance can then be set on an Element using
	 * the setAttributeNode method.
	 * To create an attribute with a qualified name
	 * and namespace URI, use the createAttributeNS method.
	 * 
	 * TODO : implement localName, prefix, namespaceURI
	 * 
	 * @param	name The name of the attribute.
	 * @return A new Attr object with the nodeName attribute 
	 * set to name, and localName, prefix, 
	 * and namespaceURI set to null. The value 
	 * of the attribute is the empty string.
	 */
	public function createAttribute(name:String):Attr
	{
		var attribute:Attr = new Attr(name);
		return attribute;
	}
	
	/**
	 * Returns the Element that has an ID attribute with the given value.
	 * If no such element exists, this returns null.
	 * If more than one element has an ID attribute with that value, return the first found one.
	 * use Attr.isId to determine if an attribute is of type ID.
	 * 
	 * @param	elementId The unique id value for an element.
	 * @return	The matching element or null if there is none.
	 */
	public function getElementById(elementId:String):Element
	{
		return doGetElementById(_documentElement, elementId);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually return the Element matching the
	 * elementId, by traversing recursively the 
	 * DOM tree
	 */
	private function doGetElementById(node:Node, elementId:String):Element
	{
		//call method recursively if node has child and is itself an element
		if (node.hasChildNodes() == true && node.nodeType == Node.ELEMENT_NODE)
		{
			for (i in 0...node.childNodes.length)
			{
				var matchingElement:Element = doGetElementById(node.childNodes[i], elementId);
				//if a matching element is found, return it
				if (matchingElement != null)
				{
					return matchingElement;
				}
			}
		}
		
		//check if node has atribute, as it can't have
		//an Id with no attributes
		if (node.hasAttributes() == true)
		{
			var attributes:NamedNodeMap = node.attributes;
			var element:Element = cast(node);
			
			//loop in all the element's attributes to find the
			//Id attribute if defined
			for (i in 0...attributes.length)
			{
				
				var attribute:Attr = element.getAttributeNode(attributes.item(i).nodeName);
				
				//if an Id attribute is found and specified
				if (attribute.isId == true && attribute.specified == true)
				{
					//if it matches the searched element Id, return the element
					if (attribute.value == elementId)
					{
						return element;
					}
				}
			}
		}
		
		//at this point no element with a matching Id was found
		return null;
	}
	
	/**
	 * Returns a NodeList of all the Elements in 
	 * document order with a given tag name and
	 * are contained in the document.
	 * 
	 * @param	tagName The name of the tag to match on. The special value "*" matches all tags.
	 * For XML, the tagname parameter is case-sensitive, otherwise
	 * it depends on the case-sensitivity of the markup language in use. 
	 * 
	 * @return A new NodeList object containing all the matched Elements.
	 */
	public function getElementsByTagName(tagName:String):Array<Node>
	{
		//use the implementation on the document element (for instance,
		//the HTML element in HTML)
		return _documentElement.getElementsByTagName(tagName);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeType():Int
	{
		return Node.DOCUMENT_NODE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_documentElement():Element
	{
		return _documentElement;
	}
}