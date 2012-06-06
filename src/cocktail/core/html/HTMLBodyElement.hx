/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.dom.Node;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.InitialBlockRenderer;
import cocktail.core.renderer.TextRenderer;

/**
 * The HTML document body. This element is always present
 * in the DOM API, even if the tags are not present in the source document.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLBodyElement extends HTMLElement
{
	/**
	 * class constructor.
	 */
	public function new() 
	{	
		super(HTMLConstants.HTML_BODY_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING TREE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * As the ElementRenderer generated by the 
	 * HTMLBodyElement is the root of the rendering
	 * tree, its parent is always considered rendered
	 * so that this doesn't prevent the rendering of
	 * the document
	 */
	override private function isParentRendered():Bool
	{
		return true;
	}
	
	/**
	 * The HTMLBodyElement always generate a root rendering
	 * tree element
	 */
	override private function createElementRenderer():Void
	{ 
		_elementRenderer = new InitialBlockRenderer(this);
		_elementRenderer.coreStyle = _coreStyle;
	}
	
	/**
	 * do nothing as there is no parent ElementRenderer. The HTMLBodyElement
	 * is always attached to the HtmlHtmlElement which doesn't generate any 
	 * ElementRenderer
	 */
	override private function attachToParentElementRenderer():Void
	{
		
	}
	
	/**
	 * do nothing as there is no parent ElementRenderer
	 */
	override private function detachFromParentElementRenderer():Void
	{
		trace("detach body");
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN COORDS GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return nothing as the HTMLBodyElement is the root 
	 * of the rendering tree
	 */
	override private function get_offsetParent():HTMLElement
	{
		return null;
	}
}