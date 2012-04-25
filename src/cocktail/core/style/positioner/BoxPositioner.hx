/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.positioner;

import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.ElementRenderer;
import haxe.Log;

/**
 * This is the base classes for classes 
 * in charge of laying out 'positioned' HTMLElements.
 * 
 * A positioned HTMLElement is one with a 'position' style value
 * of 'relative', 'absolute' or 'fixed' (any value but 'static').
 * 
 * There are 2 kinds of positioned HTMLElements : absolutely positioned
 * ('absolute' or 'fixed') and relatively positioned ('relative').
 * 
 * Absolutely positioned HTMLElements are taken out of the flow
 * and positioned by taking either their first positioned ancestor
 * as origin ('absolute') or the viewport('fixed').
 * 
 * Relatively positioned HTMLElement are first placed into the normal
 * flow, then an offset is applied to them using the top, left, right
 * and bottom styles.
 * 
 * This base class implements the behaviour of the 'absolute' 
 * position value
 * 
 * 
 * TODO : doc is obsolete now that relative positioning is render time offset.
 * Shouldn't need 3 classes, method should go into ContainerCoreStyle.positionAbsolutely...
 * It is useless to position fixed element before rendering time unless they use their
 * static position. Maybe inheriting FixedPositioner should only do something for static
 * fixed elements.
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
	 * Main entry point, determine the position of the HTMLElement's ElementRenderer relative to its first positioned
	 * ancestor
	 * 
	 * @param elementRenderer the ElementRenderer created by the HTMLElement
	 * @param	containingHTMLElement the dimensions and positions of the HTMLElement used to position the 
	 * target HTMLElement for absolutely positioned HTMLElements (its first positioned ancestor or the viewport)
	 * @param staticPosition the position the ElementRenderer would have had in the flow if it weren't positioned. Used if
	 * opposing position styles (left and right, top and bottom) both are set to 'auto'
	 */
	public function position(elementRenderer:ElementRenderer, containingHTMLElementData:ContainingHTMLElementData, staticPosition:PointData):ElementRenderer
	{
		var htmlElement:HTMLElement = elementRenderer.coreStyle.htmlElement;
		
		//for horizonal offset, if both left and right are not auto,
		//left takes precedance so we try to apply left offset first
		if (htmlElement.coreStyle.left != PositionOffset.cssAuto)
		{
			
			elementRenderer.positionedOrigin.x = getLeftOffset(htmlElement, Math.round(staticPosition.x));
		}
		//if no left offset is defined, then try to apply a right offset.
		//Right offset takes the containing HTMLElement width minus the
		//width of the positioned children as value for a 0 right offset
		else if (htmlElement.coreStyle.right != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.x = getRightOffset(htmlElement, containingHTMLElementData.width, Math.round(staticPosition.x));
		}
		//if both right and left are 'auto', then the HTMLElement is positioned to its
		//'static position', the position it would have had in the flow if it were positioned as 'static'
		else
		{
			//TODO : static position is now localBounds for positioned elements ?s
			//elementRenderer.bounds.x = Math.round(staticPosition.x);
		}
		
		//for vertical offset, the same rule as horizontal offsets apply
		if (htmlElement.coreStyle.top != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.y = getTopOffset(htmlElement, Math.round(staticPosition.y));
		}
		else if (htmlElement.coreStyle.bottom != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.y = getBottomOffset(htmlElement, containingHTMLElementData.height, Math.round(staticPosition.y));
		}
		else
		{
			//elementRenderer.bounds.y = Math.round(staticPosition.y);
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
		return htmlElement.coreStyle.computedStyle.left;
	}
	
	/**
	 * get the right offset to apply the ElementRenderer
	 */
	private function getRightOffset(htmlElement:HTMLElement, containingHTMLElementWidth:Int, staticPosition:Int):Int
	{
		return containingHTMLElementWidth - htmlElement.coreStyle.computedStyle.width +
		htmlElement.coreStyle.computedStyle.paddingLeft + htmlElement.coreStyle.computedStyle.paddingRight - htmlElement.coreStyle.computedStyle.right;
	}
	
	/**
	 * get the top offset to apply the ElementRenderer
	 */
	private function getTopOffset(htmlElement:HTMLElement, staticPosition:Int):Int
	{
		return htmlElement.coreStyle.computedStyle.top;
	}
	
	/**
	 * get the bottom offset to apply the ElementRenderer
	 */
	private function getBottomOffset(htmlElement:HTMLElement, containingHTMLElementHeight:Int, staticPosition:Int):Int
	{
		return containingHTMLElementHeight - htmlElement.coreStyle.computedStyle.height + htmlElement.coreStyle.computedStyle.paddingTop +
		htmlElement.coreStyle.computedStyle.paddingBottom - htmlElement.coreStyle.computedStyle.bottom;
	}
	
}