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
import cocktailCore.style.StyleData;
import haxe.Log;

/**
 * This is the base classes for class in charge of placing
 * in charge of laying out 'positioned' DOMElements.
 * 
 * A positioned DOMElement is one with a 'position' style value
 * of 'relative', 'absolute' or 'fixed'.
 * 
 * There are 2 kinds of positioned DOMElements : absolutely positioned
 * ('absolute' or 'fixed') and relatively positioned ('relative').
 * 
 * Absolutely positioned DOMElements are taken out of the flow
 * and positioned by taking their first positioned DOMElement
 * as origin.
 * 
 * Relatively positioned DOMElement are first placed into the normal
 * flow, then a position offset is applied to them.
 * 
 * This base class implements the behaviour of the 'absolute' 
 * position value
 * 
 * @author Yannick DOMINGUEZ
 */
class BoxPositioner 
{

	/**
	 * Class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Main entry point, place a positioned element in the document based on a containingDOMElement
	 * dimensions and positions
	 * 
	 * @param	domElement the DOMElement to position
	 * @param	containingDOMElement the dimensions and positions of the DOMElement used to position the 
	 * target DOMElement
	 */
	public function position(domElement:DOMElement, containingDOMElementData:ContainingDOMElementData):Void
	{

		//the DOMElement is first place in the same position as
		//its containing DOMElement, using its global coordinates
		domElement.globalX = containingDOMElementData.globalX;
		domElement.globalY = containingDOMElementData.globalY;
		
		//an offset is then applied to it, using the left, top, right and bottom
		//computed styles value
		applyOffset(domElement, containingDOMElementData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply an offset to the DOMElement using its top, left, bottom and right
	 * styles value
	 */
	private function applyOffset(domElement:DOMElement, containingDOMElementData:ContainingDOMElementData):Void
	{
		//for horizonal offset, if both left and right are not null (different form 'auto'),
		//left takes precedance so we try to apply left offset first
		if (domElement.style.left != PositionOffsetStyleValue.auto)
		{
			domElement.style.setNativeX(domElement, domElement.style.getNativeX(domElement) + domElement.style.computedStyle.left);
		}
		//if no left offset is defined, then try to apply a right offset
		//right offset takes the containing DOMElement element width minus, the
		//width of the DOMElement as value for a 0 offset
		else if (domElement.style.right != PositionOffsetStyleValue.auto)
		{
			domElement.style.setNativeX(domElement, containingDOMElementData.width - domElement.style.computedStyle.width - domElement.style.computedStyle.right);
		}
		
		//for vertical offset, the same rule as hortizontal offsets apply
		if (domElement.style.top != PositionOffsetStyleValue.auto)
		{
			domElement.style.setNativeY(domElement, domElement.style.getNativeY(domElement) + domElement.style.computedStyle.top);
		}
		else if (domElement.style.bottom != PositionOffsetStyleValue.auto)
		{
			domElement.style.setNativeY(domElement, containingDOMElementData.height - domElement.style.computedStyle.height - domElement.style.computedStyle.bottom);
		}
	}
	
}