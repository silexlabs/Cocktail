/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.dom.Node;
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
	 * the html tag name for the body
	 */
	private static inline var HTML_BODY_TAG_NAME:String = "body";
	
	/**
	 * class constructor.
	 */
	public function new() 
	{	
		super(HTML_BODY_TAG_NAME);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	//TODO : doc
	override public function attach():Void
	{
		createElementRenderer();
		if (_elementRenderer != null)
		{
			for (i in 0..._childNodes.length)
			{
				switch (_childNodes[i].nodeType)
				{
					case Node.ELEMENT_NODE:
						var child:HTMLElement = cast(_childNodes[i]);
						child.attach();
						
						
					case Node.TEXT_NODE:
						var textRenderer:TextRenderer = new TextRenderer(_childNodes[i]);
						textRenderer.coreStyle = _coreStyle;
						_elementRenderer.appendChild(textRenderer);
				}
			
			}
		}
	}
	
	override public function detach():Void
	{
		if (_elementRenderer != null)
		{
			for (i in 0..._childNodes.length)
			{
				var child:HTMLElement = cast(_childNodes[i]);
				child.detach();
			}
		}
	}
	
	override private function createElementRenderer():Void
	{ 
		_elementRenderer = new InitialBlockRenderer(this);
		_elementRenderer.coreStyle = _coreStyle;
		_elementRenderer.attach();
	}
	
	/**
	 * TODO : doc
	 */
	override private function get_offsetParent():HTMLElement
	{
		return null;
	}
}