/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.style.formatter;

import core.style.StyleData;
import core.geom.GeomData;
import core.HTMLElement;
import core.renderer.BlockBoxRenderer;
import core.renderer.ElementRenderer;
import core.renderer.FlowBoxRenderer;
import core.renderer.InlineBoxRenderer;
import haxe.Log;

/**
 * This formatting context place all formatted elements
 * in lines, called line box. As many line box as necessary
 * are created to contain all the elements.
 * 
 * The formatting of a line if done in 2 phases : 
 * - first the element (text, DOMElement, spaces...) are
 * added to the line and the white space rules of the element
 * are applied for instance to collapse sequences of white
 * spaces if necessary.
 * - when the line is full of elements, the x and yposition of 
 * each element in the line is computed, the x position using
 * the textAlign property of the DOMElement which started
 * the inline formatting context and the y position using
 * the vertical align property
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineFormattingContext extends FormattingContext
{

	/**
	 * The DOMElements in the current line. This array
	 * is reseted each time a new line starts
	 */
	private var _elementsInLineBox:Array<ElementRenderer>;
	
	/**
	 * Stores the currently unbreakable elements in the current line.
	 * Those element can' be broken on multiple lines, if they don't all
	 * fit on the current line then a new line is created to hold them.
	 * These array may for instance hold a sequence of space if the
	 * whiteSpace style of the space are "pre"
	 */
	private var _unbreakableLineBoxElements:Array<ElementRenderer>;
	
	/**
	 * The total width of the element in the _unbreakableLineBoxElements
	 * array used to check if they all fit in the current line or if a 
	 * new line should be created
	 */
	private var _unbreakableWidth:Int;


	
	private var _currentInlineBoxesData:Array<InlineBoxData>;
	

	
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(formattingContextRoot:BlockBoxRenderer) 
	{
		_elementsInLineBox = new Array<ElementRenderer>();
		_unbreakableLineBoxElements = new Array<ElementRenderer>();
		_unbreakableWidth = 0;
		_currentInlineBoxesData = new Array<InlineBoxData>();
		
		super(formattingContextRoot);
		
		//set the textIndent as an offset on the first line of text
		//insertElement(BoxElementValue.offset(_containingDOMElement.style.computedStyle.textIndent, _containingDOMElement));
	}
	
	
	override public function dispose():Void
	{
		super.dispose();
		_unbreakableLineBoxElements = null;
		_elementsInLineBox = null;
		_currentInlineBoxesData = null;
	}
	
	override private function doFormat(elementsInFormattingContext:Array<ElementRenderer>):Void
	{
		_elementsInLineBox = new Array<ElementRenderer>();
		_unbreakableLineBoxElements = new Array<ElementRenderer>();
		_unbreakableWidth = 0;
		
		_formattingContextRoot.removeLineBoxes();
		
		_currentInlineBoxesData = new Array<InlineBoxData>();
	
		
		super.doFormat(elementsInFormattingContext);
		
		insertBreakOpportunity(true, true);
	}
	
	
	/**
	 * Return the width remaining in the current line
	 * of the formatting context
	 */
	private function getRemainingLineWidth():Int
	{
		return _formattingContextRoot.style.computedStyle.width - _formattingContextData.x - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y, _formattingContextRoot.style.computedStyle.width);
	}
	
	
	// LINE MEASUREMENT METHODS
	// Those methods are used to determine what element to render
	// in a line and when to start a new line
//////////////////////////////////////////////////////////////////
	
	
	//////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LINE MEASUREMENT METHODS
	//////////////////////////////////////////////////////////////////
	
	
	/**
	 * Insert a DOMElement and instroduce the corresponding break opportunities
	 * 
	 * TODO : move addWidth to insertElement ?
	 */
	override private function insertEmbeddedElement(element:ElementRenderer):Void
	{
		insertBreakOpportunity(false);
		
		_unbreakableLineBoxElements.push(element);
		_lastInsertedElement = element;
			
		addWidth(Math.round(element.bounds.width));
			
		insertBreakOpportunity(false);
		
	}
	
	/**
	 * Insert a DOMElement and instroduce the corresponding break opportunities
	 */
	override private function insertFormattingContextRootElement(element:ElementRenderer):Void
	{
		element.bounds.width = element.style.htmlElement.offsetWidth;
		element.bounds.height = element.style.htmlElement.offsetHeight;
		
		insertBreakOpportunity(false);
		
		_unbreakableLineBoxElements.push(element);
		_lastInsertedElement = element;
			
		addWidth(Math.round(element.bounds.width));
			
		insertBreakOpportunity(false);
		
	}

	override private function insertContainerElement(element:ElementRenderer):Void
	{
		_unbreakableLineBoxElements.push(element);
	}
	
	/**
	 * Insert a text
	 */
	override private function insertText(element:ElementRenderer):Void
	{
		_unbreakableLineBoxElements.push(element);
		_lastInsertedElement = element;	
		
		addWidth(Math.round(element.bounds.width));
	}
	
	/**
	 * Insert a space charachter. The space might not be actually
	 * inserted if for instance it must be collapsed because
	 * space sequances are not allowed for the whiteSpace
	 * value of the space
	 */
	override private function insertSpace(element:ElementRenderer, isNextElementALineFeed:Bool):Void
	{
		//only insert space if allowed
		//if (shouldInsertSpace(getElementWhiteSpace(element), isNextElementALineFeed) == true)
	//	{
			
			_unbreakableLineBoxElements.push(element);
			
			_lastInsertedElement = element;	
			
			addWidth(Math.round(element.bounds.width));
			
			insertBreakOpportunity(false);
		//}
		
	}
	
	/**
	 * Insert a non-breakable offset which is used
	 * for instance to render the textIndent on
	 * the first line or the render the margin/padding/border
	 * of an inline level inline container
	 * 
	 * @param	offset the width of the offset
	 */
	override private function insertHorizontalOffset(element:ElementRenderer):Void
	{
		/**
		_unbreakableLineBoxElements.push( {
		element:element,
		x:0,
		y:0,
		width:getElementWidth(element),
		height:getElementHeight(element)} );
		
		addWidth(getElementWidth(element));
		*/
	}
	
	/**
	 * Insert a tab character. Like the space charachter it might not
	 * actually be added or might also be converted to a space
	 */
	override private function insertTab(element:ElementRenderer, isNextElementALineFeed:Bool):Void
	{
		/**
		var insertedElement:BoxElementValue;
		var addedWidth:Int;
		
		//here the tab is converted to a space
		if (shouldTabBeConvertedToSpace(getElementWhiteSpace(element)) == true)
		{
			insertedElement = BoxElementValue.space(getElementWhiteSpace(element), Math.round(getElementWidth(element) / 8), getElementParent(element));
			addedWidth = Math.round(getElementWidth(element) / 8);
		}
		else
		{
			insertedElement = element;
			addedWidth = getElementWidth(element);
		}
		_unbreakableLineBoxElements.push( {
			element:insertedElement,
			x:0,
			y:0,
			width:getElementWidth(element),
			height:getElementHeight(element)} );
			
		addWidth(addedWidth);
		*/
	}
	
	/**
	 * Might force a line break if line feed are allowed
	 * for the whiteSpace value of the line feed
	 */
	override private function insertLineFeed(element:ElementRenderer):Void
	{
		/**
		if (isLineFeedAllowed(getElementWhiteSpace(element)) == true)
		{
			insertBreakOpportunity(true);
		}
		*/
	}
	
	//////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LINE MEASUREMENT METHODS
	//////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////
	// PRIVATE LINE MEASUREMENT METHODS
	//////////////////////////////////////////////////////////////////
	
	
	
	/**
	 * Inserting a break opportunity signals the the current line
	 * might be broken and a new line started if there are too
	 * many element to fit in the current line's width
	 * 
	 * @param	forced a break opportunity might be forced, for instance
	 * with a line feed
	 * @param	isLastLine if the line is the last, it might be neccesaary
	 * to flush the array of unbreakable elements
	 */
	private function insertBreakOpportunity(forced:Bool, isLastLine:Bool = false):Void
	{
		var remainingLineWidth:Int = getRemainingLineWidth();
		
		//flush the array of unbreakable elements into the array of element
		//in the line to be sure to not left out any element
		if (isLastLine == true)
		{
			insertBreakOpportunity(false, false);
		}
		
		//if there is not enough width left in the line to fit all the 
		//unbreakable elements width, or if a line break is force, 
		//start a new line
		if ((remainingLineWidth - _unbreakableWidth < 0) || forced == true)
		{
			startNewLine(_unbreakableWidth, isLastLine);
		}
		
		//push all the unbreakable element into the elements in line array.
		//they can either be pushed into the current line or a new one
		//if there wasn't enough width in the previous line to fit them
		for (i in 0..._unbreakableLineBoxElements.length)
		{
			_elementsInLineBox.push(_unbreakableLineBoxElements[i]);
		}
		
		_unbreakableLineBoxElements = new Array<ElementRenderer>();
		_formattingContextData.x += _unbreakableWidth;
	
		_unbreakableWidth = 0;
	}

	/**
	 * Increment the unbreakable width
	 */
	private function addWidth(width:Int):Void
	{
		_unbreakableWidth += width;
	}
	
	/**
	 * Determine wether a tab should be converted to
	 * a space based on the whiteSpace property
	 */
	private function shouldTabBeConvertedToSpace(whiteSpace:WhiteSpace):Bool
	{
		var shouldTabBeConvertedToSpace:Bool;
		
		switch (whiteSpace)
		{
			case WhiteSpace.normal,
			WhiteSpace.nowrap,
			WhiteSpace.preLine:
				shouldTabBeConvertedToSpace = true;
				
			case WhiteSpace.pre,
			WhiteSpace.preWrap:
				shouldTabBeConvertedToSpace = false;
		}
		
		return shouldTabBeConvertedToSpace;
	}
	
	/**
	 * Determine wether line feed is allowed
	 * based on the whiteSpace property
	 */
	private function isLineFeedAllowed(whiteSpace:WhiteSpace):Bool
	{
		var lineFeedAllowed:Bool;
		
		switch (whiteSpace)
		{
			case WhiteSpace.normal,
			WhiteSpace.nowrap:
				lineFeedAllowed = false;
				
			case WhiteSpace.pre,
			WhiteSpace.preWrap,
			WhiteSpace.preLine:
				lineFeedAllowed = true;
		}
		
		return lineFeedAllowed;
	}
	
	/**
	 * Determine wheter a space should actually be inserted
	 */
	private function shouldInsertSpace(whiteSpace:WhiteSpace, isNexElementALineFeed:Bool):Bool
	{
		var shouldInsertSpace:Bool;
		
		switch (whiteSpace)
		{
			case WhiteSpace.normal,
			WhiteSpace.nowrap,
			WhiteSpace.preLine:
				shouldInsertSpace = isNexElementALineFeed == false;
				
			case WhiteSpace.preWrap,
			WhiteSpace.pre:
				shouldInsertSpace = true;
		}
			
		if (shouldInsertSpace == true)
		{
			shouldInsertSpace != isCollapsed(_lastInsertedElement, whiteSpace);
		}
		
		
		return shouldInsertSpace;
	}
	
	/**
	 * Determine wheter a space should be collapsed
	 * when it belong to a sequence of spaces
	 */
	private function isCollapsed(lastInsertedElement:ElementRenderer, whiteSpace:WhiteSpace):Bool
	{
		/**
		var isCollapsed:Bool;
		
		if (lastInsertedElement == null)
		{
			isCollapsed = false;
		}
		else
		{
			switch (lastInsertedElement)
			{
				case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
				
				switch (whiteSpace)
				{
					case WhiteSpace.normal,
					WhiteSpace.nowrap:
						isCollapsed = true;
						
					case WhiteSpace.preWrap,
					WhiteSpace.pre,
					WhiteSpace.preLine:
						isCollapsed = false;
				}
				
				default:
					isCollapsed = false;
			}
		}
		
		return isCollapsed;
		*/
		return false;
	}

	
	
	
	// LINE LAYOUT METHODS
	// Those methods are used to determine the x and y position
	// of each element in the line
//////////////////////////////////////////////////////////////////

	/////////////////////////////////
	// OVERRIDEN PRIVATE METHOD
	/////////////////////////////////

	private function getParentInlineBoxesData(parent:InlineBoxRenderer):InlineBoxData
	{
		var inlineBoxData:InlineBoxData = {
				element:parent,
				children:[]
		};
		
		var flagFound:Bool = false;
		for (i in 0..._currentInlineBoxesData.length)
		{
			if (_currentInlineBoxesData[i].element == parent)
			{
				inlineBoxData = _currentInlineBoxesData[i];
				flagFound = true;
			}
		}
		
		if (flagFound == false)
		{
			_currentInlineBoxesData.push(inlineBoxData);
		}
		
		return inlineBoxData;
	}
	
	private function startNewLine(elementWidth:Int, isLastLine:Bool):Void
	{
		if (_elementsInLineBox.length > 0)
		{
			removeSpaces();
			var lineBoxHeight:Int = computeLineBoxHeight();
		
			var lineWidth:Int = alignLineBox(isLastLine);
			
			if (lineWidth > _formattingContextData.maxWidth)
			{
				_formattingContextData.maxWidth = lineWidth;
			}
			
			var lineBoxElements:Array<ElementRenderer> = new Array<ElementRenderer>();
			
			_formattingContextRoot.addLineBox(lineBoxElements);
			
			for (i in 0..._elementsInLineBox.length)
			{
				if (_elementsInLineBox[i].parent != _formattingContextRoot.style.elementRenderer)
				{
				
					getParentInlineBoxesData(cast(_elementsInLineBox[i].parent)).children.push(_elementsInLineBox[i]);
				}
				else
				{
					lineBoxElements.push(_elementsInLineBox[i]);
				}
			}
			
			for (i in 0..._currentInlineBoxesData.length)
			{		
				for (j in 0..._currentInlineBoxesData[i].children.length)
				{
				
					lineBoxElements.push(_currentInlineBoxesData[i].children[j]);
				}
				
				
			}
			
			var inlineBoxes:Array<InlineBoxRenderer> = new Array<InlineBoxRenderer>();
			
			for (i in 0..._currentInlineBoxesData.length)
			{		
			
				var inlineBoxRenderer:InlineBoxRenderer = new InlineBoxRenderer(_currentInlineBoxesData[i].element.style);
				inlineBoxRenderer.layerRenderer = _currentInlineBoxesData[i].element.layerRenderer;
				inlineBoxRenderer.bounds = getBounds(_currentInlineBoxesData[i].children);
				inlineBoxes.push(inlineBoxRenderer);
			}
			
			//TODO : awkward + line box are in wrong z-order (the last one should be on top of
			//the other, correct here or in LayerRenderer ?
			
			inlineBoxes.reverse();
			
			for (i in 0...inlineBoxes.length)
			{
				lineBoxElements.push(inlineBoxes[i]);
			}
			
		
			
			_currentInlineBoxesData = new Array<InlineBoxData>();
			_elementsInLineBox = new Array<ElementRenderer>();
			
		
			if (isLastLine == false)
			{
				_formattingContextData.y += lineBoxHeight;
				
				_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData, elementWidth, _formattingContextRoot.style.computedStyle.width);
				
				if (_formattingContextData.y  + lineBoxHeight > _formattingContextData.maxHeight)
				{
					_formattingContextData.maxHeight = _formattingContextData.y + lineBoxHeight;
				}
				

				_formattingContextData.x =  _floatsManager.getLeftFloatOffset(_formattingContextData.y);
			}
			//TODO : layoutlastline should be false when called from getStaticPosition
			else if (_layOutLastLine == true)
			{
				_formattingContextData.y += lineBoxHeight;
				
				_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData, elementWidth, _formattingContextRoot.style.computedStyle.width);
				
				
				if (_formattingContextData.y  > _formattingContextData.maxHeight)
				{
					_formattingContextData.maxHeight = _formattingContextData.y ;
				}

				_formattingContextData.x =  _floatsManager.getLeftFloatOffset(_formattingContextData.y);
			}
			//
			
		}
	}
	
	
	
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	

	
	//TODO : re-implement
	private function removeSpaces():Void
	{
		/**
		switch (_elementsInLineBox[0].domElement.style.computedStyle.whiteSpace)
		{
			case WhiteSpace.normal,
			WhiteSpace.nowrap,
			WhiteSpace.preLine:
				
				
				switch(_elementsInLineBox[0].domElementType)
				{
					case InlineBoxValue.space:
						_elementsInLineBox.shift();
						
					default:	
				}
				
								
			default:
		}
		
		if (_elementsInLineBox.length > 0)
		{
			switch (_elementsInLineBox[_elementsInLineBox.length - 1].domElement.style.computedStyle.whiteSpace)
			{
				case WhiteSpace.normal,
				WhiteSpace.nowrap,
				WhiteSpace.preLine:
					
				switch(	_elementsInLineBox[_elementsInLineBox.length - 1].domElementType)
				{
					case InlineBoxValue.space:
						_elementsInLineBox.pop();
						
					default:	
				}
				
				default:
			}
		}	
		*/
	}
	
	/////////////////////////////////
	// PRIVATE HORIZONTAL ALIGNEMENT METHODS
	/////////////////////////////////
	
	/**
	 * before a new line starts or before the inline
	 * formarring context get destroyed, align all the
	 * DOMElements in the current line horizontally
	 * @param	isLastLine wheter it is the last line which is laid out
	 * @return returns the concantenated width of all the aligned DOMElelements.
	 * Used to determine the max line width used for shrink-to-fit algorithm
	 */
	private function alignLineBox(isLastLine:Bool):Int
	{	
		//determine the added offset width of
		//all DOMElements in the line box
		var concatenatedLength:Int = 0;
		for (i in 0..._elementsInLineBox.length)
		{
			concatenatedLength += Math.round(_elementsInLineBox[i].bounds.width);
		}
		
		
		//determine the remaining space in the line once all the width of the DOMElements
		//are substracted from the total avalable line width, and the x position where to 
		//insert the first DOMElement of the line, which might be influenced for instance
		//by a float
		var remainingSpace:Int;
		var flowX:Int;
		
		remainingSpace = _formattingContextRoot.style.computedStyle.width - concatenatedLength - _floatsManager.getLeftFloatOffset(_formattingContextData.y) - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y, _formattingContextRoot.style.computedStyle.width);
		flowX = _formattingContextRoot.style.computedStyle.marginLeft + _formattingContextRoot.style.computedStyle.paddingLeft;
		
		
		//take the float into accounts and the padding of the containing DOMElement
		flowX += _floatsManager.getLeftFloatOffset(_formattingContextData.y);
		
		//do align the DOMElements, the text align style of the containing DOMElement
		//determining the alignement to apply
		switch (_formattingContextRoot.style.computedStyle.textAlign)
		{
			case left:
				alignLeft(flowX);
				
			case right:
				alignRight(flowX, remainingSpace);
				
			case center:
				alignCenter(flowX, remainingSpace);
				
			case justify:	
				//the last line of an inline formatting context
				//is not justified to avoid stretching too much
				//the space between DOMElements if there are few of them
				if (isLastLine == true)
				{
					alignLeft(flowX);
				}
				else
				{
					//when justified, the concatenated width of the DOMElements
					//must take all the containing DOMElement width
					concatenatedLength = _formattingContextRoot.style.computedStyle.width;
					
					alignJustify(flowX, remainingSpace);
				}
		}
		
		return concatenatedLength;
	}
	
	/**
	 * align the DOMElements starting from the left edge of the containing DOMElement
	 * @param	flowX the x position of the first DOMElement
	 */
	private function alignLeft(flowX:Int):Void
	{
		for (i in 0..._elementsInLineBox.length)
		{
			_elementsInLineBox[i].bounds.x = flowX;
			flowX += Math.round(_elementsInLineBox[i].bounds.width);
		}
	}
	

	/**
	 * Center the DOMElements in the line by moving each to the right by half the remaining space
	 * @param	flowX the first availbable x position for the DOMElement to the left most of the line box
	 * @param	remainingSpace the available width in the line box after all DOMElements
	 * have been laid out
	 */
	private function alignCenter(flowX:Int, remainingSpace:Int):Void
	{
		for (i in 0..._elementsInLineBox.length)
		{
			_elementsInLineBox[i].bounds.x = Math.round(remainingSpace / 2) + flowX;
			flowX += Math.round(_elementsInLineBox[i].bounds.width);
		}
	}
	
	/**
	 * align the DOMElements starting from the right edge to the left edge of the
	 * containing DOMElement
	 * @param	flowX the x position of the DOMElement to left most of the line box
	 * @param	remainingSpace the available width in the line box after all DOMElements
	 * have been laid out
	 */
	private function alignRight(flowX:Int, remainingSpace:Int):Void
	{
		for (i in 0..._elementsInLineBox.length)
		{
			_elementsInLineBox[i].bounds.x = flowX + remainingSpace;
			flowX += Math.round(_elementsInLineBox[i].bounds.width);
		}
	}
	
	/**
	 * Justify the DOMElements in the line box by adjusting
	 * the width of the space characters
	 * @param	flowX
	 * @param	remainingSpace
	 */
	private function alignJustify(flowX:Int, remainingSpace:Int):Void
	{
		//determine how many space there are among the 
		//DOMElements of the line box
		var spacesNumber:Int = 0;
		for (i in 0..._elementsInLineBox.length)
		{
			if (_elementsInLineBox[i].isSpace() == true)
			{
				spacesNumber++;
			}
		}
		
		//justify all DOMElements
		for (i in 0..._elementsInLineBox.length)
		{	
			if (_elementsInLineBox[i].isSpace() == true)
			{
					var spaceWidth:Int = Math.round( (remainingSpace / spacesNumber));
					spacesNumber--;
					remainingSpace -= spaceWidth;
					flowX += spaceWidth;
			}
			
			_elementsInLineBox[i].bounds.x = flowX ;
			flowX += Math.round(_elementsInLineBox[i].bounds.width);
			
		}
	}
	
	/////////////////////////////////
	// PRIVATE VERTICAL ALIGNEMENT METHODS
	/////////////////////////////////
	
	/**
	 * When a line box is full and a new line will
	 * be created, compute the height of the current line
	 * box and place its DOMElement vertically.
	 * 
	 * A line box height corresponds to the addition 
	 * of the highest ascent and descent of its
	 * DOMElement above the baseline
	 * 
	 * TODO : finish implementation of verticalAlign + duplicated
	 * code
	 */
	private function computeLineBoxHeight():Int
	{
		//init the ascent and descent of the line box
		var lineBoxAscent:Float = 0;
		var lineBoxDescent:Float = 0;
		
		//loop in all DOMElement in the line box to find
		//the highest ascent and descent among them
		for (i in 0..._elementsInLineBox.length)
		{
			//TODO : shouldn't need an html element here, only style
			var htmlElement:HTMLElement = _elementsInLineBox[i].style.htmlElement;
			
			var domElementAscent:Int;
			var domElementDescent:Int;
			
			//the computed vertical align is the offset of the DOMElemenet relative
			//to the baseline
			var domElementVerticalAlign:Float = htmlElement.style.computedStyle.verticalAlign;
			
			//for embedded or inlineBlock elements, which have no baseline, the height above
			//the baseline is the offset height and they have no descent
			if (_elementsInLineBox[i].isEmbedded() == true && _elementsInLineBox[i].isText() == false ||
			_elementsInLineBox[i].establishesNewFormattingContext() == true)
			{
				domElementAscent = htmlElement.offsetHeight + _elementsInLineBox[i].style.computedStyle.marginTop + _elementsInLineBox[i].style.computedStyle.marginBottom;
				
				domElementDescent = 0;
				
				switch (htmlElement.style.verticalAlign)
				{
					case top:
						domElementAscent = Math.round(lineBoxAscent);
						domElementDescent = Math.round(htmlElement.offsetHeight - lineBoxAscent);
						
					default:	
						
				}
			}
			//else retrieve the ascent and descent and apply leading to it
			else
			{
				domElementAscent = htmlElement.style.fontMetrics.ascent;
				domElementDescent = htmlElement.style.fontMetrics.descent;	
			
				//the leading is an extra height to apply equally to the ascent
				//and the descent when laying out lines of text
				var leading:Float = htmlElement.style.computedStyle.lineHeight - (domElementAscent + domElementDescent);
		
				//apply leading to the ascent and descent
				domElementAscent = Math.round((domElementAscent + leading / 2));
				domElementDescent = Math.round((domElementDescent + leading / 2));
			}
			
			//if the ascent or descent is superior to the current maximum
			//ascent or descent, it becomes the line box ascent/descent
			if (domElementAscent - domElementVerticalAlign > lineBoxAscent)
			{
				lineBoxAscent = domElementAscent - domElementVerticalAlign;
			}
			
			if (domElementDescent + domElementVerticalAlign > lineBoxDescent)
			{
				lineBoxDescent = domElementDescent + domElementVerticalAlign;
			}
		
		}
		
		//compute the line box height
		var lineBoxHeight:Float = lineBoxAscent + lineBoxDescent;
		
		//for each DOMElement, place it vertically using the line box ascent and vertical align
		for (i in 0..._elementsInLineBox.length)
		{
			
			var htmlElement:HTMLElement = _elementsInLineBox[i].style.htmlElement;
			
			var verticalAlign:Float;
			switch (htmlElement.style.verticalAlign)
			{
				case top:
					verticalAlign = 0;
					
					
				case bottom:
					verticalAlign = 0;
					
				default:
					verticalAlign = htmlElement.style.computedStyle.verticalAlign;
			}
			
			_elementsInLineBox[i].bounds.y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + _formattingContextData.y + 
			_formattingContextRoot.style.computedStyle.marginTop + _formattingContextRoot.style.computedStyle.paddingTop;
			

			
			//if the element is embedded or an inlineBlock, removes its offset height from its vertical position
			//so that its bottom margin touches the baseline
			
			if (_elementsInLineBox[i].isEmbedded() == true && _elementsInLineBox[i].isText() == false ||
			_elementsInLineBox[i].establishesNewFormattingContext() == true)
			{	
				
				switch (htmlElement.style.verticalAlign)
				{
					case top:
						_elementsInLineBox[i].bounds.y = _formattingContextData.y;
					
					default:	
						_elementsInLineBox[i].bounds.y -= htmlElement.offsetHeight + _elementsInLineBox[i].style.computedStyle.marginTop + _elementsInLineBox[i].style.computedStyle.marginBottom;
					
				}
				
				
			}
		}
	
		return Math.round(lineBoxHeight);
	}
	
}