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
 * This is the base classes for class in charge
 * in charge of laying out 'positioned' DOMElements.
 * 
 * A positioned DOMElement is one with a 'position' style value
 * of 'relative', 'absolute' or 'fixed'.
 * 
 * There are 2 kinds of positioned DOMElements : absolutely positioned
 * ('absolute' or 'fixed') and relatively positioned ('relative').
 * 
 * Absolutely positioned DOMElements are taken out of the flow
 * and positioned by taking either their first positioned ancestor
 * as origin ('absolute') or the viewport('fixed').
 * 
 * Relatively positioned DOMElement are first placed into the normal
 * flow, then an offset is applied to them.
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
	 * dimensions and positions and/or apply an offset to it
	 * 
	 * @param	domElement the DOMElement to position
	 * @param	containingDOMElement the dimensions and positions of the DOMElement used to position the 
	 * target DOMElement for absolutely positioned DOMElements (its first positioned ancestor or the viewport)
	 * @param staticPosition the position the DOMElement would have in the flow if it weren't positioned. Used if
	 * the position styles (left, right, top and bottom) are set to 'auto'
	 */
	public function position(domElement:DOMElement, containingDOMElementData:ContainingDOMElementData, staticPosition:PointData):Void
	{
		//for horizonal offset, if both left and right are not null (different form 'auto'),
		//left takes precedance so we try to apply left offset first
		if (domElement.style.left != PositionOffsetStyleValue.autoValue)
		{
			//first place the DOMElement at its first positioned ancestor
			//x origin
			applyGlobalX(domElement,  containingDOMElementData.globalX);
			//then apply offset
			domElement.style.setNativeX(domElement, getLeftOffset(domElement) );
		}
		//if no left offset is defined, then try to apply a right offset
		//right offset takes the containing DOMElement element width minus, the
		//width of the DOMElement as value for a 0 offset
		else if (domElement.style.right != PositionOffsetStyleValue.autoValue)
		{
			applyGlobalX(domElement,  containingDOMElementData.globalX);
			domElement.style.setNativeX(domElement, getRightOffset(domElement, containingDOMElementData.width));
		}
		//if both right and left are 'auto', then the DOMElement is positioned to its
		//'static position', the position it would have had in the document if it were positioned as 'static'
		else
		{
			domElement.style.setNativeX(domElement, Math.round(staticPosition.x));
		}
		
		//for vertical offset, the same rule as hortizontal offsets apply
		if (domElement.style.top != PositionOffsetStyleValue.autoValue)
		{
			applyGlobalY(domElement,  containingDOMElementData.globalY);
			domElement.style.setNativeY(domElement, getTopOffset(domElement));
		}
		else if (domElement.style.bottom != PositionOffsetStyleValue.autoValue)
		{
			applyGlobalY(domElement,  containingDOMElementData.globalY);
			domElement.style.setNativeY(domElement, getBottomOffset(domElement, containingDOMElementData.height));
		}
		else
		{
			domElement.style.setNativeY(domElement, Math.round(staticPosition.y));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * set a global X on the DOMElement
	 */
	private function applyGlobalX(domElement:DOMElement, globalX:Int):Void
	{
		domElement.globalX = globalX;
	}
	
	/**
	 * set a global Y on the DOMElement
	 */
	private function applyGlobalY(domElement:DOMElement, globalY:Int):Void
	{
		domElement.globalY = globalY;
	}
	
	/**
	 * get the left offset to apply the DOMElement
	 */
	private function getLeftOffset(domElement:DOMElement):Int
	{
		return domElement.style.getNativeX() + domElement.style.computedStyle.left + domElement.style.computedStyle.marginLeft;
	}
	
	/**
	 * get the right offset to apply the DOMElement
	 */
	private function getRightOffset(domElement:DOMElement, containingDOMElementWidth:Int):Int
	{
		return domElement.style.getNativeX() + containingDOMElementWidth - domElement.style.computedStyle.width - domElement.style.computedStyle.right - domElement.style.computedStyle.marginRight;
	}
	
	/**
	 * get the top offset to apply the DOMElement
	 */
	private function getTopOffset(domElement:DOMElement):Int
	{
		return domElement.style.getNativeY() + domElement.style.computedStyle.top + domElement.style.computedStyle.marginTop;
	}
	
	/**
	 * get the bottom offset to apply the DOMElement
	 */
	private function getBottomOffset(domElement:DOMElement, containingDOMElementHeight:Int):Int
	{
		return domElement.style.getNativeY() + containingDOMElementHeight - domElement.style.computedStyle.height - domElement.style.computedStyle.bottom - domElement.style.computedStyle.marginBottom;
	}
	
}