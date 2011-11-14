/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.abstract;

import cocktail.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.domElement.GraphicDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.TextLineDOMElement;
import cocktail.domElement.TextNode;
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
import cocktail.domElement.DOMElementData;

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
	override public function layout(containingDOMElementDimensions:ContainingDOMElementDimensions, lastPositionedDOMElement:AbsolutelyPositionedContainingDOMElementDimensions, rootDOMElement:AbsolutelyPositionedContainingDOMElementDimensions, containingDOMElementFontMetrics:FontMetrics):Void
	{
		flow(containingDOMElementDimensions, rootDOMElement, lastPositionedDOMElement, null);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Lay out all the children of the ContainerDOMElement
	 */
	override private function flowChildren(containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, lastPositionedDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, containingDOMElementFontMetrics:FontMetrics, formatingContext:FormattingContext = null):Void
	{
		//cast the ContainerDOMElement, as base DOMElement have no children attribute
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		containerDOMElement.resetTextLines();
		
		//compute all the styles of the children that will affect
		//their lay out (display, position, float, clear)
		//Those styles need to be computed when a new FormattingContext
		//is instantiated as the type of FormattingContext mainly
		//depends on the children computed 'display' style value
		for (i in 0...containerDOMElement.children.length)
		{
			//only DOMElement styles are computed, not TextNode element's.
			//TextNode don't influence which type of formatting context will
			//be used
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.computePositionStyle();
			}
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
		
		/**
		//the containing dimensions of the children
		//because those of the current ContainerDOMElement
		//as they will be placed inside it
		childrenContainingDOMElementDimensions = {
			width:this._computedStyle.width,
			height:this._computedStyle.height
		}*/
		
		var childrenContainingDOMElementDimensions:ContainingDOMElementDimensions = getChildrenContainingDOMElementDimensions();
		var childrenContainingDOMElementFontMetrics:FontMetrics = this.fontMetrics;
		
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
		
		//flow all children
		for (i in 0...containerDOMElement.children.length)
		{
			//if the children is a DOMElement, call its flow method
			if (isDOMElement(containerDOMElement.children[i]) == true)
			{
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				childrenDOMElement.style.flow(childrenContainingDOMElementDimensions, rootDOMElementDimensions, childLastPositionedDOMElementDimensions, childrenContainingDOMElementFontMetrics, childrenFormattingContext);
			}
			//else if it is a text node, call a specific method that will create TextLineDOMElement
			//and insert them into the document using the TextNode as text content
			else 
			{
				var childrenTextNode:TextNode = cast(containerDOMElement.children[i].child);
				insertTextNode(childrenTextNode, childrenFormattingContext, childrenContainingDOMElementDimensions, rootDOMElementDimensions, childLastPositionedDOMElementDimensions, containingDOMElementFontMetrics);
			}
		}
		childrenFormattingContext.startNewLine();
		
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
	
	/**
	 * Overriden as ContainerDOMElement is only added to the flow if it is not inline.
	 * If it is inline, only its children are added in the flow.
	 */
	override private function insertInFlowDOMElement(formattingContext:FormattingContext):Void
	{
		if (isInline() == false)
		{
			super.insertInFlowDOMElement(formattingContext);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Insert a text node ( a string of text without formatting ) by creating as many text lines as needed from it
	 * and inserting them into the document
	 * @param	textNode the string of text used as content for the created text lines
	 */
	private function insertTextNode(textNode:TextNode, formattingContext:FormattingContext, containingDOMElementDimensions:ContainingDOMElementDimensions, rootDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, lastPositionedDOMElementDimensions:AbsolutelyPositionedContainingDOMElementDimensions, containingDOMElementFontMetrics:FontMetrics):Void
	{
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);

		//create a text line of the available width remaining in the current line of the formatting context.
		//the created line might be smaller than the specified width if there is not enough text to render
		//in the TextNode
		var textLineDOMElement:TextLineDOMElement = containerDOMElement.createTextLine(formattingContext.getRemainingLineWidth(), textNode);
		
		//a flag determining if a new line must be started after that the current line was inserted into the
		// formatting context.
		var startNewLine:Bool = false;
		
		//create new TextLineDOMElements and insert them into the formatting context
		//until all the text in the TextNode has been rendered. A null TextLineDOMElement
		//will be created to signal that all the text was rendered
		while( textLineDOMElement != null)
		{

			
			//compute the styles (box model, text style...) of the newly created line of text
			textLineDOMElement.style.computeDOMElement(containingDOMElementDimensions, rootDOMElementDimensions, lastPositionedDOMElementDimensions, containingDOMElementFontMetrics);

			//insert the line of text in the document
			formattingContext.insert(textLineDOMElement);
			
			//if the line is not the last of its text block (the TextNode still has text
			//to render) then a new line must be started in the formatting context as 
			//the newly created line takes all the available space on the current line
			if (textLineDOMElement.isLastLineOfTextBlock == false)
			{
				startNewLine = true;
			}
			else
			{
				
				startNewLine = false;
			}
			
			//start a new line if neccessary
			if (startNewLine == true)
			{
				formattingContext.startNewLine();
			}
			
			//create the next line of text, return null if no text is left to render
			textLineDOMElement = containerDOMElement.createTextLine(formattingContext.getRemainingLineWidth(), textNode);
		}
				
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
	 * Lastly, if this container DOMElement is inline meaning it participates in
	 * an inline formatting context and the previous formatting context is already
	 * an inline formatting context, then this formatting context is used, none
	 * is instantiated. This case mainluy happens when block of text are formatted
	 * combining multiple elements (bold text, italic text...)
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
		
		if (isInline() && Std.is(previousFormatingContext, InlineFormattingContext))
		{
			ret = previousFormatingContext;
		}
		
		else if (childrenInline() == true)
		{
			ret = new InlineFormattingContext(containerDOMElement, previousFormatingContext);	
		}
		else
		{
			ret = new BlockFormattingContext(containerDOMElement, previousFormatingContext);
		}
		
		return ret;
	}
	
	private function getChildrenContainingDOMElementDimensions():ContainingDOMElementDimensions
	{
		if (isInline() == true)
		{
			return { width:this._computedStyle.width, height:Math.round(this._computedStyle.lineHeight) };
		}
		else if (isInline() == false && childrenInline() == true)
		{
			return { width:this._computedStyle.width, height:Math.round(this._computedStyle.lineHeight) };
		}
		else
		{
			return { width:this._computedStyle.width, height:this._computedStyle.height };
		}
	}
	
	/**
	 * Determine wether the children of this DOMElement
	 * are all block level or if they are all inline level
	 * elements
	 * @return true if all children are inline DOMElements
	 */
	private function childrenInline():Bool
	{
		var ret:Bool = true;
		
		var containerDOMElement:ContainerDOMElement = cast(this._domElement);
		for (i in 0...containerDOMElement.children.length)
		{
			
			if (isDOMElement(containerDOMElement.children[i]))
			{
				//if one of the children is a block level DOMElement, then the container
				//is block level
				var childrenDOMElement:DOMElement = cast(containerDOMElement.children[i].child);
				
				if (childrenDOMElement.style.computedStyle.display == block)
				{
					ret = false;
				}
			}
		}
		
		return ret;
	}
	
	/**
	 * Determine wether the given children is a 
	 * DOMElement or a TextNode
	 */
	private function isDOMElement(containerDOMElementChildData:ContainerDOMElementChildData):Bool
	{
		var ret:Bool = false;
		
		switch (containerDOMElementChildData.type)
		{
			case ContainerDOMElementChildValue.domElement:
				ret = true;
			
			case ContainerDOMElementChildValue.textNode:
				ret = false;
		}
		
		return ret;
	}
	
}