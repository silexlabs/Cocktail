/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;
import cocktail.core.html.HTMLElement;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.TextRenderer;

/**
 * The Text interface inherits from CharacterData and represents the textual
 * content (termed character data in XML) of an Element or Attr. 
 * If there is no markup inside an element's content, the text is contained 
 * in a single object implementing the Text interface that is the only child of 
 * the element. If there is markup, it is parsed into the information items
 * (elements, comments, etc.) and Text nodes that form the list of children of
 * the element.
 * 
 * When a document is first made available via the DOM,
 * there is only one Text node for each block of text. Users may create
 * adjacent Text nodes that represent the contents of a given element
 * without any intervening markup, but should be aware that there is no way
 * to represent the separations between these nodes in XML or HTML, so they
 * will not (in general) persist between DOM editing sessions. 
 * The Node.normalize() method merges any such adjacent Text objects into a
 * single node for each block of text.
 * 
 * TODO 5 : implement normalize()
 * 
 * No lexical check is done on the content of a Text node and, depending
 * on its position in the document, some characters must be escaped 
 * during serialization using character references; e.g. the characters "<&" if
 * the textual content is part of an element or of an attribute, the character
 * sequence "]]>" when part of an element, the quotation mark character " or 
 * the apostrophe character ' when part of an attribute.
 * 
 * @author Yannick DOMINGUEZ
 */
class Text extends CharacterData
{		
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Create a TextRenderer for the Text node
	 * 
	 * TODO 1 IMPORTANT : this class is not supposed to 
	 * inherit from HTMLElement and have this method.
	 * Should they share a IRenderable interface instead ?
	 * Maybe there should be an HTMLText class in the HTML package
	 * compositing this one ?
	 * 
	 * TODO 1 : when node value changes, should invalidate
	 * rendering
	 */
	override private function createElementRenderer():Void
	{
		elementRenderer = new TextRenderer(this);
	}
	
	/**
	 * Text node use their parent's CoreStyle
	 */
	override private function attachCoreStyle():Void
	{
		var parent:HTMLElement = parentNode;
		//the TextRenderer inherits its styles from its parent
		elementRenderer.coreStyle = parent.coreStyle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeName():String
	{
		return DOMConstants.TEXT_NODE_NAME;
	}
	
	override private function get_nodeType():Int
	{
		return DOMConstants.TEXT_NODE;
	}
}