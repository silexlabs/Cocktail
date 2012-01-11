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
	override public function position(domElement:DOMElement, containingDOMElementData:ContainingDOMElementData, staticPosition:PointData):ChildTemporaryPositionData
	{
		var childrenTemporaryPositionData:ChildTemporaryPositionData = 
		{
			domElement:domElement,
			x:0,
			y:0,
			lineIndex:0
		}
		
		//for horizonal offset, if both left and right are not null (different form 'auto'),
		//left takes precedance so we try to apply left offset first
		if (domElement.style.left != PositionOffsetStyleValue.autoValue)
		{
			//first place the DOMElement at its first positioned ancestor
			//x origin
			//then apply offset
			childrenTemporaryPositionData.x =  Math.round(staticPosition.x) + getLeftOffset(domElement);
		}
		//if no left offset is defined, then try to apply a right offset
		//right offset takes the containing DOMElement element width minus, the
		//width of the DOMElement as value for a 0 offset
		else if (domElement.style.right != PositionOffsetStyleValue.autoValue)
		{
			childrenTemporaryPositionData.x =  Math.round(staticPosition.x) + getRightOffset(domElement, containingDOMElementData.width);
		}
		//if both right and left are 'auto', then the DOMElement is positioned to its
		//'static position', the position it would have had in the document if it were positioned as 'static'
		else
		{
			childrenTemporaryPositionData.x = Math.round(staticPosition.x);
		}
		
		//for vertical offset, the same rule as hortizontal offsets apply
		if (domElement.style.top != PositionOffsetStyleValue.autoValue)
		{
			childrenTemporaryPositionData.y =  Math.round(staticPosition.y) + getTopOffset(domElement);
		}
		else if (domElement.style.bottom != PositionOffsetStyleValue.autoValue)
		{
			childrenTemporaryPositionData.y = Math.round(staticPosition.y) + getBottomOffset(domElement, containingDOMElementData.height);
		}
		else
		{
			childrenTemporaryPositionData.y = Math.round(staticPosition.y);
		}
		
		return childrenTemporaryPositionData;
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