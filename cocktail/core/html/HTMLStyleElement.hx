/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

import cocktail.core.css.CSSCascadeData;
import cocktail.css.*;
import cocktail.css.CSSOMData;
import cocktail.core.dom.DOMConstants;
import cocktail.core.dom.Node;

/**
 * The style element allows authors to embed style information in their documents.
 * The style element is one of several inputs to the styling processing model.
 * The element does not represent content for the user.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLStyleElement extends HTMLElement
{
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public var disabled(get_disabled, set_disabled):Bool;
	
	/**
	 * A reference to the CSS style sheet created by this
	 * node's content. It is null by default, a style sheet
	 * is only created if this element has at least one text child
	 * node and is attached to the DOM
	 */
	public var sheet(default, null):CSSStyleSheet;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_STYLE_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to refresh the style sheet if a
	 * text node child is added to this style node
	 */
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		if (newChild.nodeType == DOMConstants.TEXT_NODE)
		{
			updateStyleSheet();
		}
		
		return newChild;
	}
	
	/**
	 * update the style sheet from the document when
	 * a text node child is removed
	 */
	override public function removeChild(oldChild:Node):Node
	{
		super.removeChild(oldChild);
		
		if (oldChild.nodeType == DOMConstants.TEXT_NODE)
		{
			updateStyleSheet();
		}
		
		return oldChild;
	}
	
	/**
	 * Overriden to try to refresh the style sheet to the document if a
	 * text node child is added to this style node
	 */
	override public function insertBefore(newChild:Node, refChild:Node):Node
	{
		super.insertBefore(newChild, refChild);
		if (refChild != null)
		{
			if (newChild.nodeType == DOMConstants.TEXT_NODE)
			{
				updateStyleSheet();
			}
		}
		
		return newChild;
	}
	
	/**
	 * Overriden, as when the style element is added
	 * to the DOM, it adds a style sheet to the 
	 * document if it has at least one child text node
	 */
	override private function addedToDOM():Void
	{
		super.addedToDOM();
		updateStyleSheet();
	}

	/**
	 * Overriden as when this node is removed
	 * from the dom, it must also remove its 
	 * style sheet from the document if any
	 */
	override private function removedFromDOM():Void
	{
		super.removedFromDOM();
		updateStyleSheet();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * To actually add a style sheet to the 
	 * document, the style node must both be
	 * attached to the DOM and have at least one
	 * text node child
	 */
	private function updateStyleSheet():Void
	{
		//stylesheet will be replaced
		if (sheet != null)
		{
			removeStyleSheet();
		}
		
		if (attachedToDOM == true)
		{
			var css:String = concatenateChildTextNode();
			if (css != "")
			{
				//create a style sheet from the content of all the childs node value
				sheet = new CSSStyleSheet(css, PropertyOriginValue.AUTHOR, cast this);
				var htmlDocument:HTMLDocument = cast(ownerDocument);
				htmlDocument.addStyleSheet(sheet);
			}
		}
	}
	
	/**
	 * Remove the style sheet from the document
	 * if it was previously added
	 */
	private function removeStyleSheet():Void
	{
		if (sheet != null)
		{
			var htmlDocument:HTMLDocument = cast(ownerDocument);
			htmlDocument.removeStyleSheet(sheet);
			sheet = null;
		}
	}
	
	/**
	 * Return the concatenated node value of all
	 * text node child or an empty string if there
	 * are no such child
	 */
	private function concatenateChildTextNode():String
	{
		var content:String = "";
		
		var length:Int = childNodes.length;
		for (i in 0...length)
		{
			if (childNodes[i].nodeType == DOMConstants.TEXT_NODE)
			{
				content += childNodes[i].nodeValue;
			}
		}
		
		return content;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The style element is not a visual one
	 */
	override private function createElementRenderer():Void
	{
		
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_disabled():Bool
	{
		return getAttributeAsBool(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME);
	}
	
	private function set_disabled(value:Bool):Bool
	{
		setAttribute(HTMLConstants.HTML_DISABLED_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
}
