/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style.positioner;

import core.style.StyleData;
import core.geom.GeomData;
import core.dom.HTMLElement;
import haxe.Log;

/**
 * This is the box positioner implementation
 * for 'relative' DOMElement.
 * 
 * Override all the methods computing the offset
 * to apply to the DOMElement relative to its first positioned
 * ancestor, as for a 'relative' positioned ancestor, the static
 * x or y position is always added because the offset is applied
 * relative to the static position of the DOMElement
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
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function getLeftOffset(htmlElement:HTMLElement, staticPosition:Int):Int
	{
		return staticPosition + htmlElement.style.computedStyle.left;
	}
	
	override private function getRightOffset(htmlElement:HTMLElement, containingDOMElementWidth:Int, staticPosition:Int):Int
	{
		return staticPosition + containingDOMElementWidth - htmlElement.offsetWidth - htmlElement.style.computedStyle.right;
	}
	
	override private function getTopOffset(htmlElement:HTMLElement, staticPosition:Int):Int
	{
		return staticPosition + htmlElement.style.computedStyle.top;
	}
	
	override private function getBottomOffset(htmlElement:HTMLElement, containingDOMElementHeight:Int, staticPosition:Int):Int
	{
		return staticPosition - htmlElement.style.computedStyle.bottom;
	}
}