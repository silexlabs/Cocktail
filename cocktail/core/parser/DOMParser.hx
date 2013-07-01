/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.parser;

import cocktail.core.dom.Attr;
import cocktail.core.dom.Document;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.NamedNodeMap;
import cocktail.core.dom.Node;
import cocktail.core.html.HTMLConstants;
import cocktail.core.html.HTMLElement;
import haxe.xml.Parser;

/**
 * this class is used to parse html string and serialize the html dom
 * 
 * @author Yannick DOMINGUEZ
 */
class DOMParser 
{

	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Take an html string and build a DOM tree from it. Return
	 * the top node of this tree
	 * @param	html the HTML string to parse
	 * @param	ownerDocument used as a factory to create the HTML objects
	 * @return	the top node of the created DOM tree
	 */
	public static function parse(html:String, ownerDocument:Document):Node
	{
		return doSetInnerHTML(Parser.parse(html).firstElement(), ownerDocument);
	}
	
	/**
	 * Take an HTML DOM element and serialize it
	 * and its children into an HTML string
	 */
	public static function serialize(node:Node):String
	{
		// serialize node's children
		var xml:Xml = doGetInnerHTML(node, Xml.createElement(node.nodeName));
		// serialize node's attributes
		for (i in 0...node.attributes.length)
		{
			var attribute:Attr = cast(node.attributes.item(i));

			if (attribute.specified == true)
			{
				xml.set(attribute.name, attribute.value);
			}
		}
		return xml.toString();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually desirialize the HTML string
	 * and return the root Node created
	 * 
	 * @param xml the HTML string, deserialized as an
	 * Haxe xml object
	 */
	private static function doSetInnerHTML(xml : Xml, ownerDocument:Document):Node
	{
		switch( xml.nodeType ) {
		
		//node type for text node
		case Xml.PCData:
			return ownerDocument.createTextNode(xml.nodeValue);
		
		//node type for comment node	
		case Xml.Comment:
			return ownerDocument.createComment(xml.nodeValue);
		
		//node type for element node
		case Xml.Element:
			
			//create an HTMLElement with the name of the xml element
			//node
			var htmlElement:HTMLElement = ownerDocument.createElement(xml.nodeName);
			
			//loop in all of the xml child node
			for (child in xml)
			{
				//switch the type of the child node
				switch (child.nodeType)
				{
					//if it is a text node,
					//check if the child is not just an
					//empty string, in which case, no text node
					//is created
					case Xml.PCData:
						if (child.nodeValue == "")
						{
							continue;
						}
				}
			
				//desrialize the child, thus deserializing
				//the whole DOM tree recursively
				var childNode:Node = doSetInnerHTML(child, ownerDocument);
				htmlElement.appendChild(childNode);
			} 
			
			//set all the attributes of the xml node on the 
			//new HTMLElement node
			var attributes:Iterator<String> = xml.attributes();
			for( attribute in attributes ){
				var value:String = xml.get(attribute);
				htmlElement.setAttribute(attribute, value);
			}
			
			return htmlElement;
		}
		
		return null;
	}
	
	/**
	 * Actually serialise all the child nodes of the HTMLElement
	 * by traversing the DOM recursively.
	 * 
	 * Returns all the children serialised data as an Xml
	 * 
	 * TODO 5 : should serialize other type of nodes, such as
	 * doctype...
	 */
	private static function doGetInnerHTML(node:Node, xml:Xml):Xml
	{
		var length:Int = node.childNodes.length;
		for (i in 0...length)
		{
			var node:Node = node.childNodes[i];
			
			switch(node.nodeType)
			{
				case DOMConstants.ELEMENT_NODE:
				
					var child : HTMLElement = cast(node);
					
					//create an xml node with the tag name of the HTMLElement,
					//for instance 'div', 'span', 'img'...
					var childXml:Xml = Xml.createElement(child.nodeName);
					
					//set all the attributes of the child on its Xml node
					var childAttributes:NamedNodeMap = child.attributes;
					var childAttributesLength:Int = childAttributes.length;
					for (j in 0...childAttributesLength)
					{
						var attribute:Attr = cast(childAttributes.item(j));

						if (attribute.specified == true)
						{
							childXml.set(attribute.name, attribute.value);
						}
					}
					
					//special case for the "style" attribute,
					//retrived from the style declaration object
					//and serialized if at least one style is declared
					if (child.style.length > 0)
					{
						childXml.set(HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME, child.style.cssText);
					}
					
					//add the children's content to the Xml of the child
					xml.addChild(doGetInnerHTML(child, childXml));
					
					//when the child xml doesn't have children itself, check if it
					//is a void element, as if it isn't, it must not be represented as 
					//a self-closing tag and so an empty string children is added to it
					//to be sure that the xml parser also returns a closing tag 
					if (childXml.firstChild() == null && child.isVoidElement() == false)
					{
						childXml.addChild(Xml.createPCData(""));
					}

				case DOMConstants.TEXT_NODE:
					//serialize a Text node
					var text:Xml = Xml.createPCData(node.nodeValue);
					xml.addChild(text);
					
				case DOMConstants.COMMENT_NODE:
					//serialize a Comment node
					var comment:Xml = Xml.createComment(node.nodeValue);
					xml.addChild(comment);
			}
		}
		
		return xml;
	}
	
}