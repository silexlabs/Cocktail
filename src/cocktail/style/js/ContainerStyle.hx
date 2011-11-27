/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.js;

import cocktail.domElement.DOMElement;
import cocktail.style.abstract.AbstractContainerStyle;
import cocktail.style.StyleData;


/**
 * This is the JavaScript implementation of the ContainerStyle.
 * 
 * In JS, styles are applied using native CSS, so the browser
 * formats the document instead of Cocktail
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerStyle extends AbstractContainerStyle
{
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}

	/**
	 * Overriden to prevent layout in JS, as it will be done by
	 * the browser via CSS.
	 */
	override public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:AbsolutelyPositionedContainingDOMElementDimensions, rootDOMElement:AbsolutelyPositionedContainingDOMElementDimensions, containingDOMElementFontMetrics:FontMetrics):Void
	{
		
	}
	
}