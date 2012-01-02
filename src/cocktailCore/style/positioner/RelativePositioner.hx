/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.positioner;

import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
import cocktail.geom.GeomData;
import haxe.Log;

/**
 * This is the box positioner implementation
 * for 'relative' DOMElement.
 * 
 * Prevents DOMElement from being globally
 * positioned as 'relative' DOMElement remain
 * in normal flow, only an offset is applied to
 * them
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
	
	/**
	 * Overriden as relative DOMElement are positioned in the flow
	 */
	override private function applyGlobalX(domElement:DOMElement, globalX:Int):Void
	{
		
	}
	
	/**
	 * Overriden as relative DOMElement are positioned in the flow
	 */
	override private function applyGlobalY(domElement:DOMElement, globalY:Int):Void
	{
		
	}
	
	/**
	 * Overriden because the margin isn't use as is it already applied when the
	 * relative DOMElement is inserted into the flow
	 */
	override private function getLeftOffset(domElement:DOMElement):Int
	{
		return domElement.style.getNativeX() + domElement.style.computedStyle.left;
	}
	
	/**
	 * Overriden because the margin isn't use as is it already applied when the
	 * relative DOMElement is inserted into the flow
	 */
	override private function getRightOffset(domElement:DOMElement, containingDOMElementWidth:Int):Int
	{
		return domElement.style.getNativeX() + containingDOMElementWidth - domElement.style.computedStyle.width - domElement.style.computedStyle.right ;
	}
	
	/**
	 * Overriden because the margin isn't use as is it already applied when the
	 * relative DOMElement is inserted into the flow
	 */
	override private function getTopOffset(domElement:DOMElement):Int
	{
		return domElement.style.getNativeY() + domElement.style.computedStyle.top;
	}
	
	/**
	 * Overriden because the margin isn't use as is it already applied when the
	 * relative DOMElement is inserted into the flow
	 */
	override private function getBottomOffset(domElement:DOMElement, containingDOMElementHeight:Int):Int
	{
		return domElement.style.getNativeY() + containingDOMElementHeight - domElement.style.computedStyle.height - domElement.style.computedStyle.bottom ;
	}
	
}