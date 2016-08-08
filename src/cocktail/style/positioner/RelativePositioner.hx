/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.positioner;

import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;

/**
 * This is the box positioner implementation
 * for 'relative' DOMElement.
 * 
 * Prevents DOMElement from being globally
 * positioned as 'relative' DOMElement remain
 * in normal flow
 * 
 * @author Yannick DOMINGUEZ
 */
class RelativePositioner extends BoxPositioner
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERIDDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Override to prevent DOMElement from being globally positioned, 'relative' DOMElement are
	 * first normally positioned in the flow, then an offset is applied to them
	 */
	override public function position(domElement:DOMElement, containingDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions):Void
	{
		applyOffset(domElement, containingDOMElementDimensions);
	}
	
}