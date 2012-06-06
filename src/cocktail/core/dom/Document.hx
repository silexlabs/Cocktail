/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;

import cocktail.core.event.CustomEvent;
import cocktail.core.event.Event;
import cocktail.core.event.FocusEvent;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.event.TransitionEvent;
import cocktail.core.event.UIEvent;
import cocktail.core.event.WheelEvent;
import cocktail.core.html.HTMLElement;
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
	 * event interfaces const
	 */
	public static inline var EVENT_INTERFACE:String = "Event";
	
	public static inline var UI_EVENT_INTERFACE:String = "UIEvent";
	
	public static inline var MOUSE_EVENT_INTERFACE:String = "MouseEvent";
	
	public static inline var FOCUS_EVENT_INTERFACE:String = "FocusEvent";
	
	public static inline var KEYBOARD_EVENT_INTERFACE:String = "KeyboardEvent";
	
	public static inline var WHEEL_EVENT_INTERFACE:String = "WheelEvent";
	
	public static inline var CUSTOM_EVENT_INTERFACE:String = "CustomEvent";
	
	public static inline var TRANSITION_EVENT_INTERFACE:String = "TransitionEvent";
	
	/**
	 * This is a convenience attribute that allows direct access
	 * to the child node that is the document element of the document.
	 * 
	 * TODO IMPORTANT : this attribute is supposed to return an
	 * Element but it has to be an HTMLElement to match the Haxe JS API
	 */
	private var _documentElement:HTMLElement;
	public var documentElement(get_documentElement, never):HTMLElement;
	
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
	 * TODO 4 : for ownerDocument, when should it be set when
	 * instantiating classes instead of using factory method ?
	 * 
	 * TODO 4 : should return Element instead of HTMLElement but necessary
	 * to match Haxe JS API
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
	 * Creates a Comment node given the specified string.
	 * @param	data The data for the node.
	 * @return The new Comment object.
	 */
	public function createComment(data:String):Comment
	{
		var comment:Comment = new Comment();
		comment.nodeValue = data;
		return comment;
	}
	
	/**
	 * Creates an Attr of the given name. Note that the 
	 * Attr instance can then be set on an Element using
	 * the setAttributeNode method.
	 * To create an attribute with a qualified name
	 * and namespace URI, use the createAttributeNS method.
	 * 
	 * TODO 5 : implement localName, prefix, namespaceURI
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
	 * Provides a mechanism by which the user can create an Event object
	 * of a type supported by the implementation.
	 * If the feature “Events” is supported by the Document object, 
	 * the DocumentEvent interface must be implemented on the same object.
	 * Language-specific type casting may be required.
	 * @param	eventInterface
	 * @return
	 */
	public function createEvent(eventInterface:String):Event
	{	
		switch (eventInterface)
		{
			case EVENT_INTERFACE:
				return new Event();
				
			case UI_EVENT_INTERFACE:
				return new UIEvent();
				
			case CUSTOM_EVENT_INTERFACE:
				return new CustomEvent();
				
			case MOUSE_EVENT_INTERFACE:
				return new MouseEvent();
				
			case KEYBOARD_EVENT_INTERFACE:
				return new KeyboardEvent();
				
			case FOCUS_EVENT_INTERFACE:
				return new FocusEvent();
				
			case WHEEL_EVENT_INTERFACE:
				return new WheelEvent();
				
			case TRANSITION_EVENT_INTERFACE:
				return new TransitionEvent();
				
			default:
				throw DOMException.NOT_SUPPORTED_ERR;
		}
		
		return null;
	}
	
	/**
	 * Returns the Element that has an ID attribute with the given value.
	 * If no such element exists, this returns null.
	 * If more than one element has an ID attribute with that value, return the first found one.
	 * use Attr.isId to determine if an attribute is of type ID.
	 * 
	 * IMPORTANT : this method is supposed to return an Element but to match
	 * Haxe JS API, we return an HTMLElement instead. It might be a problem
	 * eventually to use the lib with other XML format
	 * 
	 * @param	elementId The unique id value for an element.
	 * @return	The matching element or null if there is none.
	 */
	public function getElementById(elementId:String):HTMLElement
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
	private function doGetElementById(node:Node, elementId:String):HTMLElement
	{
		//call method recursively if node has child and is itself an element
		if (node.hasChildNodes() == true && node.nodeType == Node.ELEMENT_NODE)
		{
			for (i in 0...node.childNodes.length)
			{
				var matchingElement:HTMLElement = doGetElementById(node.childNodes[i], elementId);
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
			var element:HTMLElement = cast(node);
			
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
	 * IMPORTANT : this method is supposed to return an array of Element but to match
	 * Haxe JS API, we return an array of HTMLElement instead. It might be a problem
	 * eventually to use the lib with other XML format
	 * 
	 * @param	tagName The name of the tag to match on. The special value "*" matches all tags.
	 * For XML, the tagname parameter is case-sensitive, otherwise
	 * it depends on the case-sensitivity of the markup language in use. 
	 * 
	 * @return A new NodeList object containing all the matched Elements.
	 */
	public function getElementsByTagName(tagName:String):Array<HTMLElement>
	{
		//use the implementation on the document element (for instance,
		//the HTML element in HTML)
		return _documentElement.getElementsByTagName(tagName);
	}
	
	/**
	 * Returns a set of elements which have all the given class names.
	 * 
	 * IMPORTANT : return array of HTMLElement because of haxe JS
	 * 
	 * @param	className the class name to match. If it is a list of class names
	 * separated by spaces, it returns only the elements which matches all the class
	 * names
	 * @return A list of matching Element nodes.
	 */
	public function getElementsByClassName(className:String):Array<HTMLElement>
	{
		return _documentElement.getElementsByClassName(className);
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
	
	private function get_documentElement():HTMLElement
	{
		return _documentElement;
	}
}