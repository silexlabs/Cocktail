/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.dom;

import cocktail.event.CustomEvent;
import cocktail.event.Event;
import cocktail.event.FocusEvent;
import cocktail.event.KeyboardEvent;
import cocktail.event.MouseEvent;
import cocktail.event.TransitionEvent;
import cocktail.event.UIEvent;
import cocktail.event.WheelEvent;
import cocktail.event.PopStateEvent;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;

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
	 * 
	 * TODO IMPORTANT : this attribute is supposed to return an
	 * Element but it has to be an HTMLElement to match the Haxe JS API
	 */
	public var documentElement(default, null):HTMLElement;
	
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
	 * Implemented by sub classes
	 * 
	 * @param	tagName The name of the element type to instantiate. For XML,
	 * this is case-sensitive, otherwise it depends on the case-sensitivity 
	 * of the markup language in use. In that case, the name is mapped
	 * to the canonical form of that markup by the DOM implementation.
	 * 
	 * @return A new Element object with the nodeName attribute set to tagName,
	 * and localName, prefix, and namespaceURI set to null
	 * 
	 * IMPORTANT should return Element instead of HTMLElement but necessary
	 * to match Haxe JS API
	 */
	public function createElement(tagName:String):HTMLElement
	{
		return null;
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
		text.ownerDocument = this;
		
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
			case DOMConstants.EVENT_INTERFACE:
				return new Event();
				
			case DOMConstants.UI_EVENT_INTERFACE:
				return new UIEvent();
				
			case DOMConstants.CUSTOM_EVENT_INTERFACE:
				return new CustomEvent();
				
			case DOMConstants.MOUSE_EVENT_INTERFACE:
				return new MouseEvent();
				
			case DOMConstants.KEYBOARD_EVENT_INTERFACE:
				return new KeyboardEvent();
				
			case DOMConstants.FOCUS_EVENT_INTERFACE:
				return new FocusEvent();
				
			case DOMConstants.WHEEL_EVENT_INTERFACE:
				return new WheelEvent();
				
			case DOMConstants.TRANSITION_EVENT_INTERFACE:
				return new TransitionEvent();
				
			case DOMConstants.POPSTATE_EVENT_INTERFACE:
				return new PopStateEvent();
				
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
		return doGetElementById(documentElement, elementId);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually return the Element matching the
	 * elementId, by traversing recursively the 
	 * DOM tree
	 */
	private function doGetElementById(node:HTMLElement, elementId:String):HTMLElement
	{
		//ID can only be matched by element node or descendant of element node
		if (node.nodeType == DOMConstants.ELEMENT_NODE)
		{
			//first check id on cildren, as the first child in tree order with matching
			//id should be returned
			if (node.hasChildNodes() == true)
			{
				var length:Int = node.childNodes.length;
				for (i in 0...length)
				{
					if (node.childNodes[i].nodeType == DOMConstants.ELEMENT_NODE)
					{
						var matchingElement:HTMLElement = doGetElementById(cast(node.childNodes[i]), elementId);
						//if a matching element is found, return it
						if (matchingElement != null)
						{
							return matchingElement;
						}
					}
				}
			}
			
			//check ID attribute, returns null if no ID attribute for this node
			if (node.getAttribute(HTMLConstants.HTML_ID_ATTRIBUTE_NAME) == elementId)
			{
				return node;
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
		//might be null if document not already initialised
		if (documentElement == null)
		{
			return [];
		}
		//use the implementation on the document element (for instance,
		//the HTML element in HTML)
		return documentElement.getElementsByTagName(tagName);
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
		return documentElement.getElementsByClassName(className);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeType():Int
	{
		return DOMConstants.DOCUMENT_NODE;
	}
}
