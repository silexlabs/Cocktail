/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.abstract;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.computer.BlockBoxComputer;
import cocktail.style.computer.BoxComputer;
import cocktail.style.computer.InLineBoxComputer;
import cocktail.style.computer.NoneBoxComputer;
import cocktail.style.formatter.BlockFormattingContext;
import cocktail.style.formatter.FormattingContext;
import cocktail.style.formatter.InlineFormattingContext;
import cocktail.style.positioner.AbsolutePositioner;
import cocktail.style.positioner.BoxPositioner;
import cocktail.style.positioner.FixedPositioner;
import cocktail.style.positioner.RelativePositioner;
import cocktail.style.StyleData;

#if flash9
import cocktail.style.as3.Style;
#elseif js
import cocktail.style.js.Style;
#end

import haxe.Log;

/**
 * This is the style implementation for ContainerDOMElement.
 * 
 * ContainerDOMElement can have children, and when laid out,
 * also start the layout on each of its children
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractContainerStyle extends Style
{
	/**
	 * class constructor
	 * @param	domElement
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * This method is overriden to start a recursive layout when called on a ContainerDOMElement. The ContainerDOMElement
	 * will be measured and placed as well as all its children
	 */
	override public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:AbsolutelyPositionedContainingDOMElementDimensions, rootDOMElement:AbsolutelyPositionedContainingDOMElementDimensions):Void
	{
		flow(containingDOMElementDimensions, rootDOMElement, lastPositionedDOMElement, null);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerDOMElement
	 */
	override private function flowChildren(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, lastPositionedDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, formatingContext:FormattingContext = null):Void
	{
		//cast the ContainerDOMElement, as base DOMElement have no children attribute
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		//compute all the styles of the children that will affect
		//their lay out (display, position, float, clear)
		//Those styles need to be computed whzen a new FormattingContext
		//is instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0...containerDOMElement.children.length)
		{
			containerDOMElement.children[i].style.computePositionStyle();
		}
		
		//a new FormattingContext must be created for the children of the 
		//ContainerDOMElement as they will be placed inside the ContainerDOMElement 
		//using its width and height
		var childrenFormattingContext:FormattingContext;
		
		//if the FormattingContext is null, this ContainerDOMElement
		//is the first to be lay out
		if (formatingContext == null)
		{
			formatingContext = getFormatingContext();
			childrenFormattingContext = getFormatingContext();
		}
		else
		{
			childrenFormattingContext = getFormatingContext(formatingContext);
		}
		
		//the containing dimensions of the children
		//because those of the current ContainerDOMElement
		//as they will be placed inside it
		containingDOMElementDimensions = {
			width:this._computedStyle.width,
			height:this._computedStyle.height
		}
		
		
		var childLastPositionedDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions = lastPositionedDOMElementDimensions;
		
		//if the ContainerDOMElement is positioned, it becomes the first positioned for the children it
		//will layout, and will be used as origin for absolutely positioned children
		if (this.isPositioned() == true)
		{
			childLastPositionedDOMElementDimensions = {
				width:this._computedStyle.width,
				height:this._computedStyle.height,
				globalX:this._domElement.globalX,
				globalY:this._domElement.globalY
			}
		}
		
		//call the flow method of all children
		for (i in 0...containerDOMElement.children.length)
		{
			containerDOMElement.children[i].style.flow(containingDOMElementDimensions, rootDOMElementDimensions, childLastPositionedDOMElementDimensions, childrenFormattingContext);
		}
		
		//if the 'height' style of this ContainerDOMElement is 
		//defined as 'auto', then it depends on its content width
		//and it must now be adjusted to the total height
		//of its children before the ContainerDOMElement is actually
		//sized
		if (this._height == DimensionStyleValue.auto)
		{
			this._computedStyle.height = childrenFormattingContext.flowData.totalHeight;
		}
		
		//insert the ContainerDOMElement into the document
		insertDOMElement(formatingContext, lastPositionedDOMElementDimensions, rootDOMElementDimensions);

		//retrieve the floats overflowing from the children of this ContainerDOMElement, 
		//that will also affect the position of its following siblings
		formatingContext.retrieveFloats(childrenFormattingContext);
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate the right formatting context for this ContainerDOMElement.
	 * 
	 * If the container DOMElement itself is an inline level DOMElement, all
	 * its children must be formatted as inline and thus an Inline formatting 
	 * context is returned
	 * 
	 * If the container DOMElement itself is a block level DOMElement, if all its
	 * children are inline level, an inline formatting context is instantiated, else
	 * if all its children are block level, a block level formatting context is
	 * instantiated. If its children mix inline and block level DOMElement, 
	 * block formatting context is the default
	 * 
	 * 
	 * @param	previousFormatingContext the formatting context of the parent of this
	 * Container DOMElement, used to retrieve floats position from it which might also
	 * apply to this container DOMElement
	 * 
	 * @return an inline or block formatting context
	 */
	private function getFormatingContext(previousFormatingContext:FormattingContext = null):FormattingContext
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		var ret:FormattingContext;
		
		if (childrenInline() == true)
		{
			ret = new InlineFormattingContext(containerDOMElement, previousFormatingContext);
		}
		else
		{
			ret = new BlockFormattingContext(containerDOMElement, previousFormatingContext);
		}
		
		return ret;
	}
	
	/**
	 * Determine wether the children of this DOMElement
	 * are all block level or if they are all inline level
	 * elements
	 * @return true if all children are inline DOMElements
	 */
	private function childrenInline():Bool
	{
		var ret:Bool = false;
		
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].style.computedStyle.display == _inline ||
			containerDOMElement.children[i].style.computedStyle.display == inlineBlock)
			{
				ret = true;
			}
		}
		
		return ret;
	}
	
	
}