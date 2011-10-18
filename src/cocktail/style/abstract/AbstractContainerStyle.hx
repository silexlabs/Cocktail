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
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractContainerStyle extends Style
{

	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	
	
	override public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:AbsolutelyPositionedContainingDOMElementDimensions, rootDOMElement:AbsolutelyPositionedContainingDOMElementDimensions):Void
	{
		var rootDOMElementDimensions:ContainingDOMElementDimensions = {
			width : rootDOMElement.width,
			height : rootDOMElement.height
		}
		
		var lastPositionedDOMElementDimensions:ContainingDOMElementDimensions = {
			width : lastPositionedDOMElement.width,
			height : lastPositionedDOMElement.height
		}
		
		flow(containingDOMElementDimensions, rootDOMElementDimensions, lastPositionedDOMElementDimensions, null, true);
		positionElement(lastPositionedDOMElement, rootDOMElement);
	}
	
	
	
	/**
	 * TO DO : 
	 * The method called recursively on children should be layout, this way yhe positionElement method can be only defined for 
	 * Container DOMElement instead of all of them. Same for the flow method ?
	 */
	override public function flow(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElementDimensions:ContainingDOMElementDimensions, formatingContext:FormattingContext = null, initialContainer:Bool = false):Void
	{
		
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		computePositionStyle();
		
		computeBoxModelStyle(containingDOMElementDimensions, rootDOMElementDimensions, lastPositionedDOMElementDimensions);
		
		if (this._computedStyle.display == DisplayStyleValue.none)
		{
			/**
			 * TO DO : must the set the computed style value
			 * of 'visible' to false, not the visible property
			 */
			this._domElement.isVisible = false;
			return;
		}
		
		
		for (i in 0...containerDOMElement.children.length)
		{
			containerDOMElement.children[i].style.computePositionStyle();
		}
		
		var childrenFormattingContext:FormattingContext;
		
		if (initialContainer == true)
		{
			formatingContext = FormattingContext.getFormatingContext(containerDOMElement, formatingContext);
			childrenFormattingContext = formatingContext;
			

		}
		else if (formatingContext.beginNewFormattingContext(containerDOMElement))
		{
			childrenFormattingContext = FormattingContext.getFormatingContext(containerDOMElement, formatingContext);		
			
		
		}
		else
		{
			childrenFormattingContext = formatingContext;
		}
		
			containingDOMElementDimensions = {
			width:this._computedStyle.width,
			height:this._computedStyle.height
		}
		
		var childLastPositionedDOMElementDimensions:ContainingDOMElementDimensions = lastPositionedDOMElementDimensions;
		if (this.isPositioned() == true)
		{
			childLastPositionedDOMElementDimensions = {
				width:this._computedStyle.width,
				height:this._computedStyle.height
			}
		}
		
		
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].style.isFloat() == true)
			{
				childrenFormattingContext.insertFloat(containerDOMElement.children[i]);
			}
		}
		
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].style.isClear())
			{
				formatingContext.clearFloat(containerDOMElement.children[i].style.computedStyle.clear);
			}
			containerDOMElement.children[i].style.flow(containingDOMElementDimensions, rootDOMElementDimensions, childLastPositionedDOMElementDimensions, childrenFormattingContext);
		}
		
		if (isInline() == false && this._height == DimensionStyleValue.auto)
		{
			
			this._computedStyle.height = childrenFormattingContext.flowData.totalHeight;
		}
		
		this._domElement.width = this._computedStyle.width;
		this._domElement.height = this._computedStyle.height;
		
		
		if (isPositioned() == false || isRelativePositioned() == true)
		{
			formatingContext.insert(this._domElement);
		}
		
	}
	
	override public function positionElement(lastPositionedDOMElement:AbsolutelyPositionedContainingDOMElementDimensions, rootDOMElement:AbsolutelyPositionedContainingDOMElementDimensions):Void
	{
		super.positionElement(lastPositionedDOMElement, rootDOMElement);
		
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		var childrenLastPositionedDOM:AbsolutelyPositionedContainingDOMElementDimensions = {
				globalX:lastPositionedDOMElement.globalX,
				globalY:lastPositionedDOMElement.globalY,
				width:lastPositionedDOMElement.width,
				height:lastPositionedDOMElement.height
			}
			
		if (this.isPositioned() == true)
		{
			childrenLastPositionedDOM.width = this._domElement.width;
			childrenLastPositionedDOM.height = this._domElement.height;
			childrenLastPositionedDOM.globalX = this._domElement.globalX;
			childrenLastPositionedDOM.globalY = this._domElement.globalY;
		}
		
		for (i in 0...containerDOMElement.children.length)
		{
			var childDOMElement:DOMElement = containerDOMElement.children[i];
			
			childDOMElement.style.positionElement(childrenLastPositionedDOM, rootDOMElement);
		}
		
	}
	
	public function isInlineFlow():Bool
	{
		var ret:Bool = false;
		
		switch(this._computedStyle.display)
		{
			case _inline:
				ret = true;
				
			default:
				ret = childrenInline();
		}
		
		return ret;
	}
	
	public function childrenInline():Bool
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		
		var ret:Bool = true;
		for (i in 0...containerDOMElement.children.length)
		{
			if (containerDOMElement.children[i].style.computedStyle.display == block)
			{
				ret = true;
			}
		}
		
		return ret;
	}
	
}