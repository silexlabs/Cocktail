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
	public function new(node:Node) 
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
		
		for (i in 0...rootLineBox.childNodes.length)
		{
			ret.push(cast(rootLineBox.childNodes[i]));
			
			if (rootLineBox.childNodes[i].hasChildNodes() == true)
			{
				var childLineBoxes:Array<LineBox> = getLineBoxesInLine(cast(rootLineBox.childNodes[i]));
				for (j in 0...childLineBoxes.length)
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
	override private function layoutChildren(containingBlockData:ContainingBlockData, viewportData:ContainingBlockData, firstPositionedAncestorData:FirstPositionedAncestorData, containingBlockFontMetricsData:FontMetricsData, formattingContext:FormattingContext):Void
	{
		//compute all the styles of the children that will affect
		//their layout (display, position, float, clear)
		//Those styles need to be computed before a new FormattingContext
		//gets instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		//
		//TODO : should not be necessary anymore, this should be done
		//in HTMLElement, as when the display style changes, a new ElementRenderer
		//must be instantiated. Also, the ElementRenderer should not loop into the
		//HTMLElements
		for (i in 0..._node.childNodes.length)
		{
			//only HTMLElement styles are computed, not Text as they have no style.
			//When determining the formatting context to use, Text nodes are always assumed
			//to be inline as text is always laid out on a line when rendered.
			//Text node use its parent HTMLElement's styles for rendering
			if (_node.childNodes[i].nodeType == Node.ELEMENT_NODE)
			{
				var childHTMLElement:HTMLElement = cast(_node.childNodes[i]);
				childHTMLElement.coreStyle.computeDisplayStyles();
			}
		}
		
		//The children of the ElementRenderer are laid out either
		//using a new formatting context if this establishes a new one
		//or it uses the current formatting context
		var childrenFormattingContext:FormattingContext = getFormattingContext(formattingContext);
		
		//get the containing dimensions that will be used to lay out the children
		//of the ElementRenderer (its width and height)
		var childrenContainingBlockData:ContainingBlockData = getContainerBlockData();
		
		//get the computed font metrics of the this ElementRenderer. Those metrics
		//are based on the font family and the font size used
		var childrenContainingHTMLElementFontMetricsData:FontMetricsData = _coreStyle.fontMetrics;
		
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
		
		//actually layout all children
		doLayoutChildren(childrenContainingBlockData, viewportData, childrenFirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
		
		//if the width is defined as 'auto', it might need to 
		//be computed to 'shrink-to-fit' (takes its content width)
		//in some cases
		if (this._coreStyle.width == Dimension.cssAuto)
		{
			shrinkToFitIfNeeded(containingBlockData, childrenFormattingContext.maxWidth, formattingContext, firstPositionedAncestorData, viewportData );
		}
		//else it is already computed and is set on the bounds
		//of tht ElementRenderer
		//
		//TODO : shouldn't it be set during formatting instead ?
		else
		{
			_bounds.width = _coreStyle.computedStyle.width;
		}
		
		//if the 'height' style of this ElementRenderer is 
		//defined as 'auto', then in most cases, it depends on its content height
		//and it must now be adjusted to the total height
		//of its children. For some border cases though, the total height
		//of the children is not used and auto height is computed in
		//another way
		//
		//TODO : shouldn't be useful anymore, its taken care of during formatting ? the only 
		//needed thing is to update the computed height
		if (this._coreStyle.height == Dimension.cssAuto)
		{
			//format the children formatting context, so that the bounds
			//of the children of this ElementRenderer can be found.
			//The height of this bound is applied as the new height
			//It only needs to be done for ElementRenderer which doesn't
			//establish a new formatting context for its children, else
			//the formatting context would have been already formatted
			//at this point
			if (establishesNewFormattingContext() == false)
			{
				childrenFormattingContext.format();
			}
			
			//TODO : check if this intermediate method is actually useful, seems to be only
			//used for positioned elements
			this.computedStyle.height = _coreStyle.applyContentHeightIfNeeded(getRelevantContainingBlockData(containingBlockData, viewportData,  firstPositionedAncestorData.data), Math.round(this.bounds.height), isReplaced());
		}
		//else it is already computed and is set on the bounds
		//of tht ElementRenderer
		else
		{
			_bounds.height = _coreStyle.computedStyle.height;
		}
		
		//if this ElementRenderer is positioned, it means that it is the first positioned ancestor
		//for its positioned children and it is its responsability to lay them out
		layoutAbsolutelyPositionedChildrenIfNeeded(childrenFirstPositionedAncestorData, viewportData);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually layout all the children of the ElementRenderer by calling
	 * the layout method recursively on all the children
	 */
	private function doLayoutChildren(childrenContainingBlockData:ContainingBlockData, viewportData:ContainingBlockData, childFirstPositionedAncestorData:FirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData:FontMetricsData, childrenFormattingContext:FormattingContext):Void
	{			
		for (i in 0..._childNodes.length)
		{
			var childElementRenderer:ElementRenderer = cast(_childNodes[i]);
			childElementRenderer.layout(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, childrenContainingHTMLElementFontMetricsData, childrenFormattingContext);
		}
		
		//prompt the children formatting context, to format all the children
		//ElementRenderer belonging to it. After this call, all the
		//ElementRenderer have the right bounds, in the space of the containing
		//block which established the formatting context
		//
		//This method is only called if a new formatting
		//context was established by this ElementRenderer,
		//meaning that it also is responsible of formatting it
		if (establishesNewFormattingContext() == true)
		{
			childrenFormattingContext.format();
		}
	}
	
	/**
	 * layout absolutely positioned descendant if this ElementRenderer is positioned
	 */
	private function layoutAbsolutelyPositionedChildrenIfNeeded(childrenFirstPositionedAncestorData:FirstPositionedAncestorData, viewportData:ContainingBlockData):Void
	{
		if (isPositioned() == true)
		{
			//lay out each stored children
			for (i in 0...childrenFirstPositionedAncestorData.elements.length)
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
	 * TODO : check if elementRenderer is passed by reference and not value
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
	private function getLeftOffset(elementRenderer:ElementRenderer):Int
	{
		return elementRenderer.coreStyle.computedStyle.left + elementRenderer.coreStyle.computedStyle.marginLeft;
	}
	
	/**
	 * get the right offset to apply the ElementRenderer
	 */
	private function getRightOffset(elementRenderer:ElementRenderer, containingHTMLElementWidth:Int):Int
	{
		return containingHTMLElementWidth - elementRenderer.coreStyle.computedStyle.width + elementRenderer.coreStyle.computedStyle.paddingLeft
		+ elementRenderer.coreStyle.computedStyle.paddingRight + elementRenderer.coreStyle.computedStyle.right - elementRenderer.coreStyle.computedStyle.marginRight;
	}
	
	/**
	 * get the top offset to apply the ElementRenderer
	 */
	private function getTopOffset(elementRenderer:ElementRenderer):Int
	{
		return elementRenderer.coreStyle.computedStyle.top + elementRenderer.coreStyle.computedStyle.marginTop;
	}
	
	/**
	 * get the bottom offset to apply the ElementRenderer
	 */
	private function getBottomOffset(elementRenderer:ElementRenderer, containingHTMLElementHeight:Int):Int
	{
		return containingHTMLElementHeight - elementRenderer.coreStyle.computedStyle.height + elementRenderer.coreStyle.computedStyle.paddingTop +
		elementRenderer.coreStyle.computedStyle.paddingBottom - elementRenderer.coreStyle.computedStyle.bottom;
	}
	
	/**
	 * In certain cases, when the width of the ElementRenderer is 'auto',
	 * its computed value is 'shrink-to-fit' meaning that it will take either
	 * the width of the widest line formed by its children or the width of its
	 * container if the children overflows
	 * 
	 * If the width of this ElementRenderer is indeed shrinked, all
	 * its children are laid out again
	 * 
	 * @param	containingBlockData
	 * @param	minimumWidth the width of the widest line of children laid out
	 * by this HTMLElement which will be the minimum width that should
	 * have this HTMLElement if it is shrinked to fit
	 */
	private function shrinkToFitIfNeeded(containingBlockData:ContainingBlockData, minimumWidth:Int, formattingContext:FormattingContext, firstPositionedAncestorData:FirstPositionedAncestorData, viewportData:ContainingBlockData):Void
	{		
		var shrinkedWidth:Int = _coreStyle.shrinkToFitIfNeeded(containingBlockData, minimumWidth, isReplaced());
		
		//if the computed width of the ElementRenderer was shrinked, then
		//a new layout must happen
		if (this.computedStyle.width != shrinkedWidth)
		{
		
			//store the new computed width
			this.computedStyle.width = shrinkedWidth;
			
			//update the structures used for the layout and starts a new layout
			var childrenFormattingContext:FormattingContext = getFormattingContext(formattingContext);
			var childrenContainingBlockData:ContainingBlockData = getContainerBlockData();
			var childFirstPositionedAncestorData:FirstPositionedAncestorData = getChildrenFirstPositionedAncestorData(firstPositionedAncestorData);
			doLayoutChildren(childrenContainingBlockData, viewportData, childFirstPositionedAncestorData, _coreStyle.fontMetrics, childrenFormattingContext);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Determine wether the children of this ElementRenderer
	 * are all block level or if they are all inline level
	 * elements
	 * 
	 * TODO : throw exception when there is a float in the children
	 * 
	 * @return true if all children are inline level ElementRenderer
	 */
	override public function childrenInline():Bool
	{		
		var childrenInline:Bool = true;
		for (i in 0..._childNodes.length)
		{
			var child:ElementRenderer = cast(_childNodes[i]);
			if (child.isInlineLevel() == false)
			{
				return false;
			}
		}
		return true;
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the dimensions data
	 * of the ElementRenderer
	 */
	private function getContainerBlockData():ContainingBlockData
	{
		return {
			width:this.computedStyle.width,
			isWidthAuto:this._coreStyle.width == Dimension.cssAuto,
			height:this.computedStyle.height,
			isHeightAuto:this._coreStyle.height == Dimension.cssAuto
		};
	}
	
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
	
	/**
	 * Return the right formatting context to layout this ElementRenderer's
	 * children by either creating a new formatting context
	 * or participating in the current . By default, it participates in the current
	 * formatting context. Only block box can establish new formatting context
	 */
	private function getFormattingContext(currentFormattingContext:FormattingContext):FormattingContext
	{
		return currentFormattingContext;
	}
}