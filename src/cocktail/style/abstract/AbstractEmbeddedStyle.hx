/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.style.computer.BlockEmbeddedBoxComputer;
import cocktail.style.computer.BoxComputer;
import cocktail.style.computer.FloatEmbeddedBoxComputer;
import cocktail.style.computer.InlineBlockEmbeddedBoxComputer;
import cocktail.style.computer.InlineEmbeddedBoxComputer;
import cocktail.style.computer.NoneBoxComputer;
import cocktail.style.computer.PositionedEmbeddedBoxComputer;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.Style;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * This is the style implementation for embedded
 * DOMElement. Embedded DOMElement include external
 * content in the document, such as picture or video
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractEmbeddedStyle extends Style
{
	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	/**
	 * This is method is overriden to use box computer specific to 
	 * embedded DOMElement instead of the default one
	 */
	override private function computeBoxModelStyle(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, lastPositionedDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions):Void
	{
		//instantiate the right box computer class
		//based on the DOMElement's positioning
		//scheme
		var boxComputer:BoxComputer;
		
		//get the right containing dimensions. For example,
		//for a DOMElement with a 'position' style of 'absolute',
		//it is the last positioned DOMElement
		var containingBlockDimensions:ContainingDOMElementDimensions = getContainingDOMElementDimensions(containingDOMElementDimensions, rootDOMElementDimensions, lastPositionedDOMElementDimensions );
		
		//get the embedded box computers based on
		//the positioning scheme
		if (isFloat() == true)
		{
			boxComputer = new FloatEmbeddedBoxComputer();
		}
		else if (isPositioned() == true && isRelativePositioned() == false)
		{
			boxComputer = new PositionedEmbeddedBoxComputer();
		}
		switch(this._computedStyle.display)
		{
			case block:
				boxComputer = new BlockEmbeddedBoxComputer();
				
			case inlineBlock:
				boxComputer = new InlineBlockEmbeddedBoxComputer();	
			
			case none:
				boxComputer = new NoneBoxComputer();
			
			case _inline:
				boxComputer = new InlineEmbeddedBoxComputer();
		}
		
		//compute the embedded DOMElement box model styles
		boxComputer.measure(this, containingBlockDimensions);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as all inherithing classes of the
	 * Embedded DOMElement are embedded
	 */
	override public function isEmbedded():Bool
	{
		return true;
	}
	
}