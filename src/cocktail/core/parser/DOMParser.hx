 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.parser;

import cocktail.core.dom.Attr;
import cocktail.core.dom.Document;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.NamedNodeMap;
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
	public static function parse(html:String, ownerDocument:Document):HTMLElement
	{
		//wrap the HTML String in a div element, else
		//when creating the html node, only the first 
		//node content is deserialized and not its
		//siblings
		var wrappedHTML:String = HTMLConstants.HTML_TOKEN_LESS_THAN + HTMLConstants.HTML_DIV_TAG_NAME + HTMLConstants.HTML_TOKEN_MORE_THAN;
		wrappedHTML += html;
		wrappedHTML += HTMLConstants.HTML_TOKEN_LESS_THAN + HTMLConstants.HTML_TOKEN_SOLIDUS + HTMLConstants.HTML_DIV_TAG_NAME + HTMLConstants.HTML_TOKEN_MORE_THAN;

		var node:HTMLElement = doSetInnerHTML(Parser.parse(wrappedHTML).firstElement(), ownerDocument);
		return node;
	}
	
	/**
	 * Take an HTML DOM element and serialize it
	 * and its children into an HTML string
	 */
	public static function serialize(node:HTMLElement):String
	{
		var xml:Xml = doGetInnerHTML(node, Xml.createElement(node.nodeName));
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
	private static function doSetInnerHTML(xml : Xml, ownerDocument:Document):HTMLElement
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
			
			var htmlElement : HTMLElement;
			var name:String = xml.nodeName.toLowerCase();
	
			//create an HTMLElement with the name of the xml element
			//node
			htmlElement = ownerDocument.createElement(name);
			
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
				var childNode:HTMLElement = doSetInnerHTML(child, ownerDocument);

				htmlElement.appendChild(childNode);
			} 
			
			//set all the attributes of the xml node on the 
			//new HTMLElement node
			for( attribute in xml.attributes() ){
				attribute = attribute.toLowerCase();
				var value:String = xml.get(attribute);
				htmlElement.setAttribute(attribute, value);
			}
			
			return htmlElement;
		}
		
		//TODO 2 : will cause bug if node type not supported
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
	private static function doGetInnerHTML(node:HTMLElement, xml:Xml):Xml
	{
		var length:Int = node.childNodes.length;
		for (i in 0...length)
		{
			var child:HTMLElement = node.childNodes[i];
			
			switch(child.nodeType)
			{
				case DOMConstants.ELEMENT_NODE:
				
					//create an xml node with the tag name of the HTMLElement,
					//for instance 'div', 'span', 'img'...
					var childXml:Xml = Xml.createElement(child.nodeName);
					
					//set all the attributes of the child on its Xml node
					var childAttributes:NamedNodeMap<HTMLElement> = child.attributes;
					var childAttributesLength:Int = childAttributes.length;
					for (j in 0...childAttributesLength)
					{
						var attribute:Attr<HTMLElement> = cast(childAttributes.item(j));
						
						if (attribute.specified == true)
						{
							childXml.set(attribute.name, attribute.value);
						}
					}
					
					//concatenate all the of the specified styles of the HTMLElement
					//children into a CSS string
					var htmlChild:HTMLElement = child;
					var styleAttributes:NamedNodeMap<HTMLElement> = htmlChild.style.attributes;
					var concatenatedStyles:String = "";
					
					var attributesLength:Int = styleAttributes.length;
					for (j in 0...attributesLength)
					{
						var attribute:Attr<HTMLElement> = cast(styleAttributes.item(j));
						
						if (attribute.specified == true)
						{
							concatenatedStyles += attribute.name + ":" + attribute.value +";";
						}
					}
					
					//set the CSS string as the 'style' attribute of the HTMLElement
					//if at least one style one specified on it
					if (concatenatedStyles != "")
					{
						childXml.set(HTMLConstants.HTML_STYLE_ATTRIBUTE_NAME, concatenatedStyles);
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
					var text:Xml = Xml.createPCData(child.nodeValue);
					xml.addChild(text);
					
				case DOMConstants.COMMENT_NODE:
					//serialize a Comment node
					var comment:Xml = Xml.createComment(child.nodeValue);
					xml.addChild(comment);
			}
		}
		
		return xml;
	}
	
}