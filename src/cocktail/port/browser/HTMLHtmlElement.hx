/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.browser;
import cocktail.core.dom.Node;
import cocktail.core.html.AbstractHTMLHtmlElement;

/**
 * This id the browser port of the HTML root element
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLHtmlElement extends AbstractHTMLHtmlElement
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Overriden to prevent from appending the native HTML
	 * element, as it would for instance fore the body
	 * tag to be attached to it
	 */
	override public function appendChild(newChild:Node):Node
	{
		removeFromParentIfNecessary(newChild);
		
		newChild.parentNode = this;
		_childNodes.push(newChild);
		
		return newChild;
	}
	
}