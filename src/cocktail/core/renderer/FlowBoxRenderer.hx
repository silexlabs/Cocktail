 /*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.html.HTMLElement;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;

/**
 * This is a base class for ElementRenderer which are
 * container such as the block box and inline box.
 * 
 * It takes cares of laying out its children
 * 
 * @author Yannick DOMINGUEZ
 */
class FlowBoxRenderer extends BoxRenderer 
{
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return all the LineBoxes created by this ElementRenderer
	 * in one line, as an array of LineBoxes
	 */
	private function getLineBoxesInLine(rootLineBox:LineBox):Array<LineBox>
	{
		var ret:Array<LineBox> = new Array<LineBox>();
		
		var length:Int = rootLineBox.childNodes.length;
		for (i in 0...length)
		{
			ret.push(rootLineBox.childNodes[i]);
			
			if (rootLineBox.childNodes[i].hasChildNodes() == true)
			{
				var childLineBoxes:Array<LineBox> = getLineBoxesInLine(rootLineBox.childNodes[i]);
				
				var childLength:Int = childLineBoxes.length;
				for (j in 0...childLength)
				{
					ret.push(childLineBoxes[j]);
				}
			}
		}
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ElementRenderer
	 */
	override private function layoutChildren(firstPositionedAncestorData:FirstPositionedAncestorData):Void
	{
		//Holds a reference to the dimensions of the first positioned ancestor of the 
		//laid out children and to each of the children using it as first positioned ancestor
		//
		//if the ElementRenderer is positioned, it becomes the first positioned ancestor for the children it
		//lays out, and will be used as origin for absolutely positioned children. Each absolutely positioned
		//children will be stored and once this ElementRenderer is laid out, it will lay out all those children.
		//The layout of absolutely positioned children must happen once the dimensions of this ElementRenderer are 
		//known so that children can be positioned using the 'bottom' and 'right' styles which use the dimensions
		//of the ElementRenderer as containing dimensions
		var childrenFirstPositionedAncestorData:FirstPositionedAncestorData = getChildrenFirstPositionedAncestorData(firstPositionedAncestorData);
		
		/**
		 * Actually layout all the children of the ElementRenderer by calling
		 * the layout method recursively on all the children
		 */
		var length:Int = _childNodes.length;
		for (i in 0...length)
		{
			var childElementRenderer:ElementRenderer = _childNodes[i];
			childElementRenderer.layout(childrenFirstPositionedAncestorData);
		}
		
		//starts the formatting of the children of this FlowBoxRenderer
		//if it establishes a new formatting context
		//
		//TODO 3 : should only be called for BlockBoxRenderer
		format();
		
		if (_positionedChildrenNeedLayout == true)
		{
			//if this ElementRenderer is positioned, it means that it is the first positioned ancestor
			//for its positioned children and it is its responsability to lay them out
			layoutAbsolutelyPositionedChildrenIfNeeded(childrenFirstPositionedAncestorData, getWindowData());
		}
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * starts the formatting of the box
	 */
	private function format():Void
	{
		//abstract
	}
	
	/**
	 * layout absolutely positioned descendant if this ElementRenderer is positioned
	 */
	private function layoutAbsolutelyPositionedChildrenIfNeeded(childrenFirstPositionedAncestorData:FirstPositionedAncestorData, viewportData:ContainingBlockData):Void
	{
		if (isPositioned() == true)
		{
			//lay out each stored children
			var length:Int = childrenFirstPositionedAncestorData.elements.length;
			for (i in 0...length)
			{
				var element:ElementRenderer = childrenFirstPositionedAncestorData.elements[i];
				//layout the child ElementRenderer which set its x and y positioned origin in the space of this ElementRenderer's
				//positioned origin
				layoutPositionedChild(element, getContainerBlockData(), viewportData);
			}
		}
	}
	
	/**
	 * layout an absolutely positioned ElementRenderer (with a position style of 'fixed' or 'absolute')
	 * using either the first positioned ancestor dimensions or the viewport's
	 * 
	 * @param firstPositionedAncestorData the dimensions of the first positioned ancestor
	 * @param viewportData the dimensions of the viewport
	 */
	private function layoutPositionedChild(elementRenderer:ElementRenderer, firstPositionedAncestorData:ContainingBlockData, viewportData:ContainingBlockData):Void
	{
		switch (elementRenderer.computedStyle.position)
		{	
			//positioned 'fixed' ElementRenderer, use the viewport
			case fixed:
				doLayoutPositionedChild(elementRenderer, viewportData);
				
			//positioned 'absolute' ElementRenderer use the first positioned ancestor data	
			case absolute:
				doLayoutPositionedChild(elementRenderer, firstPositionedAncestorData);
				
			default:
		}
	}
	
	/**
	 * Actually lay out the positioned ElementRenderer
	 */
	private function doLayoutPositionedChild(elementRenderer:ElementRenderer, containingBlockData:ContainingBlockData):Void
	{
		//for horizonal offset, if both left and right are not auto,
		//left takes precedance so we try to apply left offset first
		if (elementRenderer.coreStyle.left != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.x = getLeftOffset(elementRenderer);
		}
		//if no left offset is defined, then try to apply a right offset.
		//Right offset takes the containing block width minus the
		//width of the positioned children as value for a 0 right offset
		else if (elementRenderer.coreStyle.right != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.x = getRightOffset(elementRenderer, containingBlockData.width);
		}
		//if both right and left are 'auto', then the ElementRenderer is positioned to its
		//static position, the position it would have had in the flow if it were positioned as 'static'.
		//At this point the bounds of the ElementRenderer already matches its static position
		
		//for vertical offset, the same rule as horizontal offsets apply
		if (elementRenderer.coreStyle.top != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.y = getTopOffset(elementRenderer);
		}
		else if (elementRenderer.coreStyle.bottom != PositionOffset.cssAuto)
		{
			elementRenderer.positionedOrigin.y = getBottomOffset(elementRenderer, containingBlockData.height);
		}
	}
	
	/**
	 * get the left offset to apply the ElementRenderer
	 */
	private function getLeftOffset(elementRenderer:ElementRenderer):Float
	{
		return elementRenderer.coreStyle.computedStyle.left + elementRenderer.coreStyle.computedStyle.marginLeft;
	}
	
	/**
	 * get the right offset to apply the ElementRenderer
	 */
	private function getRightOffset(elementRenderer:ElementRenderer, containingHTMLElementWidth:Float):Float
	{
		return containingHTMLElementWidth - elementRenderer.coreStyle.computedStyle.width + elementRenderer.coreStyle.computedStyle.paddingLeft
		+ elementRenderer.coreStyle.computedStyle.paddingRight + elementRenderer.coreStyle.computedStyle.right - elementRenderer.coreStyle.computedStyle.marginRight;
	}
	
	/**
	 * get the top offset to apply the ElementRenderer
	 */
	private function getTopOffset(elementRenderer:ElementRenderer):Float
	{
		return elementRenderer.coreStyle.computedStyle.top + elementRenderer.coreStyle.computedStyle.marginTop;
	}
	
	/**
	 * get the bottom offset to apply the ElementRenderer
	 */
	private function getBottomOffset(elementRenderer:ElementRenderer, containingHTMLElementHeight:Float):Float
	{
		return containingHTMLElementHeight - elementRenderer.coreStyle.computedStyle.height + elementRenderer.coreStyle.computedStyle.paddingTop +
		elementRenderer.coreStyle.computedStyle.paddingBottom - elementRenderer.coreStyle.computedStyle.bottom;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the children of this ElementRenderer
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * @return true if at least one child is inline level
	 */
	override public function childrenInline():Bool
	{	
		var length:Int = _childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = _childNodes[i];
			//floated and absolutely positioned element are not taken into
			//account
			if (child.isFloat() == false)
			{
				if (child.isPositioned() == false || child.isRelativePositioned() == true)
				{
					if (child.isInlineLevel() == true)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the structure used to layout absolutely positioned
	 * children. If this ElementRenderer is positioned, a new
	 * structure is created, else the current one is used
	 */
	private function getChildrenFirstPositionedAncestorData(firstPositionedAncestorData:FirstPositionedAncestorData):FirstPositionedAncestorData
	{
		var childFirstPositionedAncestorData:FirstPositionedAncestorData;
		
		if (isPositioned() == true)
		{
			childFirstPositionedAncestorData = {
				data: getContainerBlockData(),
				elements: new Array<ElementRenderer>()
			}
		}
		else
		{
			childFirstPositionedAncestorData = firstPositionedAncestorData;
		}
		
		return childFirstPositionedAncestorData;
	}
}