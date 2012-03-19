/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.positioner;

import cocktail.style.StyleData;
import core.geom.GeomData;
import core.dom.HTMLElement;
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
	 * Main entry point, determine the position of the DOMElement's ElementRenderer relative to its first positioned
	 * ancestor
	 * 
	 * @param elementRenderer the ElementRenderer created by the DOMElement
	 * @param	containingDOMElement the dimensions and positions of the DOMElement used to position the 
	 * target DOMElement for absolutely positioned DOMElements (its first positioned ancestor or the viewport)
	 * @param staticPosition the position the ElementRenderer would have had in the flow if it weren't positioned. Used if
	 * opposing position styles (left and right, top and bottom) both are set to 'auto'
	 */
	public function position(elementRenderer:ElementRenderer, containingDOMElementData:ContainingDOMElementData, staticPosition:PointData):ElementRenderer
	{
		var htmlElement:HTMLElement = elementRenderer.style.htmlElement;
		
		//for horizonal offset, if both left and right are not auto,
		//left takes precedance so we try to apply left offset first
		if (htmlElement.style.left != PositionOffset.autoValue)
		{
			elementRenderer.bounds.x = getLeftOffset(htmlElement, Math.round(staticPosition.x));
		}
		//if no left offset is defined, then try to apply a right offset.
		//Right offset takes the containing DOMElement width minus the
		//width of the positioned children as value for a 0 right offset
		else if (htmlElement.style.right != PositionOffset.autoValue)
		{
			elementRenderer.bounds.x = getRightOffset(htmlElement, containingDOMElementData.width, Math.round(staticPosition.x));
		}
		//if both right and left are 'auto', then the DOMElement is positioned to its
		//'static position', the position it would have had in the flow if it were positioned as 'static'
		else
		{
			elementRenderer.bounds.x = Math.round(staticPosition.x);
		}
		
		//for vertical offset, the same rule as horizontal offsets apply
		if (htmlElement.style.top != PositionOffset.autoValue)
		{
			elementRenderer.bounds.y = getTopOffset(htmlElement, Math.round(staticPosition.y));
		}
		else if (htmlElement.style.bottom != PositionOffset.autoValue)
		{
			elementRenderer.bounds.y = getBottomOffset(htmlElement, containingDOMElementData.height, Math.round(staticPosition.y));
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
	 * get the left offset to apply the ElementRenderer
	 */
	private function getLeftOffset(htmlElement:HTMLElement, staticPosition:Int):Int
	{
		return htmlElement.style.computedStyle.left;
	}
	
	/**
	 * get the right offset to apply the ElementRenderer
	 */
	private function getRightOffset(htmlElement:HTMLElement, containingDOMElementWidth:Int, staticPosition:Int):Int
	{
		return containingDOMElementWidth - htmlElement.offsetWidth - htmlElement.style.computedStyle.right;
	}
	
	/**
	 * get the top offset to apply the ElementRenderer
	 */
	private function getTopOffset(htmlElement:HTMLElement, staticPosition:Int):Int
	{
		return htmlElement.style.computedStyle.top;
	}
	
	/**
	 * get the bottom offset to apply the ElementRenderer
	 */
	private function getBottomOffset(htmlElement:HTMLElement, containingDOMElementHeight:Int, staticPosition:Int):Int
	{
		return containingDOMElementHeight - htmlElement.offsetHeight - htmlElement.style.computedStyle.bottom;
	}
	
}