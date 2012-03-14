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
import cocktailCore.style.renderer.ElementRenderer;
import haxe.Log;

/**
 * This is the base classes for classes 
 * in charge of laying out 'positioned' DOMElements.
 * 
 * A positioned DOMElement is one with a 'position' style value
 * of 'relative', 'absolute' or 'fixed' (any value but 'static').
 * 
 * There are 2 kinds of positioned DOMElements : absolutely positioned
 * ('absolute' or 'fixed') and relatively positioned ('relative').
 * 
 * Absolutely positioned DOMElements are taken out of the flow
 * and positioned by taking either their first positioned ancestor
 * as origin ('absolute') or the viewport('fixed').
 * 
 * Relatively positioned DOMElement are first placed into the normal
 * flow, then an offset is applied to them using the top, left, right
 * and bottom styles.
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
	 * Main entry point, determine the position of the DOMElement relative to its first positioned
	 * ancestor
	 * 
	 * @param elementRenderer the ElementRenderer created by the DOMElement
	 * @param	containingDOMElement the dimensions and positions of the DOMElement used to position the 
	 * target DOMElement for absolutely positioned DOMElements (its first positioned ancestor or the viewport)
	 * @param staticPosition the position the DOMElement would have had in the flow if it weren't positioned. Used if
	 * opposing position styles (left and right, top and bottom) both are set to 'auto'
	 */
	public function position(elementRenderer:ElementRenderer, containingDOMElementData:ContainingDOMElementData, staticPosition:PointData):ElementRenderer
	{
		//TODO : refactor
		var domElement:DOMElement = elementRenderer.style.domElement;
		
		//for horizonal offset, if both left and right are not auto,
		//left takes precedance so we try to apply left offset first
		if (domElement.style.left != PositionOffsetStyleValue.autoValue)
		{
			elementRenderer.bounds.x = getLeftOffset(domElement, Math.round(staticPosition.x));
		}
		//if no left offset is defined, then try to apply a right offset.
		//Right offset takes the containing DOMElement width minus the
		//width of the positioned children as value for a 0 right offset
		else if (domElement.style.right != PositionOffsetStyleValue.autoValue)
		{
			elementRenderer.bounds.x = getRightOffset(domElement, containingDOMElementData.width, Math.round(staticPosition.x));
		}
		//if both right and left are 'auto', then the DOMElement is positioned to its
		//'static position', the position it would have had in the flow if it were positioned as 'static'
		else
		{
			elementRenderer.bounds.x = Math.round(staticPosition.x);
		}
		
		//for vertical offset, the same rule as horizontal offsets apply
		if (domElement.style.top != PositionOffsetStyleValue.autoValue)
		{
			elementRenderer.bounds.y = getTopOffset(domElement, Math.round(staticPosition.y));
		}
		else if (domElement.style.bottom != PositionOffsetStyleValue.autoValue)
		{
			elementRenderer.bounds.y = getBottomOffset(domElement, containingDOMElementData.height, Math.round(staticPosition.y));
		}
		else
		{
			elementRenderer.bounds.y = Math.round(staticPosition.y);
		}
		
		
		return elementRenderer;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * get the left offset to apply the DOMElement
	 */
	private function getLeftOffset(domElement:DOMElement, staticPosition:Int):Int
	{
		return domElement.style.computedStyle.left;
	}
	
	/**
	 * get the right offset to apply the DOMElement
	 */
	private function getRightOffset(domElement:DOMElement, containingDOMElementWidth:Int, staticPosition:Int):Int
	{
		return containingDOMElementWidth - domElement.offsetWidth - domElement.style.computedStyle.right;
	}
	
	/**
	 * get the top offset to apply the DOMElement
	 */
	private function getTopOffset(domElement:DOMElement, staticPosition:Int):Int
	{
		return domElement.style.computedStyle.top;
	}
	
	/**
	 * get the bottom offset to apply the DOMElement
	 */
	private function getBottomOffset(domElement:DOMElement, containingDOMElementHeight:Int, staticPosition:Int):Int
	{
		return containingDOMElementHeight - domElement.offsetHeight - domElement.style.computedStyle.bottom;
	}
	
}