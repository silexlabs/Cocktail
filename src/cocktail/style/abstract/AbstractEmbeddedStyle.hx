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
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractEmbeddedStyle extends Style
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	
	
	override public function computeBoxModelStyle(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElementDimensions:ContainingDOMElementDimensions):Void
	{
		var boxComputer:BoxComputer;
		
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
		
		boxComputer.measure(this, containingDOMElementDimensions);
	}
	
}