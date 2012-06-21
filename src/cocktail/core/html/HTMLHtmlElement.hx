/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.renderer.LayerRenderer;

/**
 * Root of an HTML document
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLHtmlElement extends HTMLElement
{	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_HTML_TAG_NAME);
		
		//as the HTML htmlElement is the root
		//of the runtime, it attaches iself to the
		//rendering tree instead of waiting for
		//its parent to attach it
		attach();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * As the ElementRenderer generated by the 
	 * HTMLHTMLElement is the root of the rendering
	 * tree, its parent is always considered rendered
	 * so that this doesn't prevent the rendering of
	 * the document
	 */
	override private function isParentRendered():Bool
	{
		return true;
	}
	
	/**
	 * The HTMLHTMLElement always generate a root rendering
	 * tree element
	 */
	override private function createElementRenderer():Void
	{ 
		_elementRenderer = new InitialBlockRenderer(this);
		_elementRenderer.coreStyle = _coreStyle;
	}
	
	/**
	 * do nothing as there is no parent ElementRenderer. The HTMLHTMLElement
	 * attaches itself 
	 */
	override private function attachToParentElementRenderer():Void
	{
		
	}
	
	/**
	 * do nothing as there is no parent ElementRenderer
	 */
	override private function detachFromParentElementRenderer():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN COORDS GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return nothing as the HTMLHTMLElement is the root 
	 * of the rendering tree
	 */
	override private function get_offsetParent():HTMLElement
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM PARSER GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to reset the HTMLBodyElement when the innerHTML is set,
	 * as it reset the whole document
	 */
	override private function set_innerHTML(value:String):String
	{
		
		super.set_innerHTML(value);
		
		var htmlDocument:HTMLDocument = cast(_ownerDocument);
		htmlDocument.initBody(cast(getElementsByTagName(HTMLConstants.HTML_BODY_TAG_NAME)[0]));
		
		return value;
	}
	
}