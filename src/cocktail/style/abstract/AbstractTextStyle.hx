/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.abstract;

import cocktail.domElement.DOMElement;
import cocktail.domElement.TextDOMElement;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.Style;
import cocktail.style.StyleData;
import cocktail.domElement.DOMElementData;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractTextStyle extends Style
{
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	

	override private function flowChildren(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, lastPositionedDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, formatingContext:FormattingContext = null ):Void
	{
		
		var textDOMElement:TextDOMElement = cast(this._domElement);
		
		
		textDOMElement.reset();
		
	
		
		/**
		 * TO DO : recursive method to compute all child textDOMElement
		 * Should it be here ?
		 */
		for (i in 0...textDOMElement.children.length)
		{
			if (textDOMElement.children[i].type == TextDOMElementChildrenValue.textDOMElement)
			{
				var childrenTextDOMElement:TextDOMElement = cast(textDOMElement.children[i].children);
					childrenTextDOMElement.style.computeDOMElement(containingDOMElementDimensions, rootDOMElementDimensions, lastPositionedDOMElementDimensions);

			}
		
		}
		
		
		var textLine:DOMElement = textDOMElement.createTextLine(formatingContext.getRemainingLineWidth());
		
		
		while( textLine != null)
		{
			
			textLine.style.computeDOMElement(containingDOMElementDimensions, rootDOMElementDimensions, lastPositionedDOMElementDimensions);

			
			formatingContext.insert(textLine);
			textLine = textDOMElement.createTextLine(formatingContext.getRemainingLineWidth());
		}
		
		
	}
	

	override private function applyComputedDimensions():Void
	{
		
	}
	
}