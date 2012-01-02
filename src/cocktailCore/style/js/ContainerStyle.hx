/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.js;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktailCore.style.abstract.AbstractContainerStyle;
import cocktailCore.style.formatter.FormattingContext;
import cocktail.style.StyleData;
import haxe.Log;


/**
 * This is the JavaScript implementation of the ContainerStyle.
 * 
 * In JS, styles are applied using native CSS, so the browser
 * formats the document instead of Cocktail.
 * 
 * Cocktail only store for each DOMElement the position
 * and dimensions of its native HTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerStyle extends AbstractContainerStyle
{
	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	/**
	 * Make all the DOMElement retrieve their native HTMLElement positions
	 * and dimensions
	 */
	override private function flowChildren(containingDOMElementData:ContainingDOMElementData, viewportData:ContainingDOMElementData, lastPositionedDOMElementData:LastPositionedDOMElementData, containingDOMElementFontMetricsData:FontMetricsData, formatingContext:FormattingContext = null):Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		for (i in 0...containerDOMElement.children.length)
		{
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.flow(containingDOMElementData, viewportData, lastPositionedDOMElementData, containingDOMElementFontMetricsData, formatingContext);
			}
		}
	}
		
	
}