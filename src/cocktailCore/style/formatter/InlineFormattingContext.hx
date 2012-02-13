/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.formatter;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.style.StyleData;
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
	private var _elementsInLineBox:Array<BoxElementData>;
	
	/**
	 * Stores the currently unbreakable elements in the current line.
	 * Those element can' be broken on multiple lines, if they don't all
	 * fit on the current line then a new line is created to hold them.
	 * These array may for instance hold a sequence of space if the
	 * whiteSpace style of the space are "pre"
	 */
	private var _unbreakableLineBoxElements:Array<BoxElementData>;
	
	/**
	 * The total width of the element in the _unbreakableLineBoxElements
	 * array used to check if they all fit in the current line or if a 
	 * new line should be created
	 */
	private var _unbreakableWidth:Int;

	/**
	 * a reference to the last inserted element in the line, used for 
	 * instance when a space is inserted to checkk if the previous
	 * element was also a space and if it should be collapsed
	 */
	private var _lastInsertedElement:BoxElementValue;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(domElement:DOMElement) 
	{
		_elementsInLineBox = new Array<BoxElementData>();
		_unbreakableLineBoxElements = new Array<BoxElementData>();
		_unbreakableWidth = 0;
		
		super(domElement);
		
		//set the textIndent as an offset on the first line of text
		//insertElement(BoxElementValue.offset(_containingDOMElement.style.computedStyle.textIndent, _containingDOMElement));
	}
	
	override public function format():Void
	{
		super.format();
		insertBreakOpportunity(true, true);
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
	 */
	override private function insertEmbeddedDOMElement(element:BoxElementValue):Void
	{
		insertBreakOpportunity(false);
		
		_unbreakableLineBoxElements.push( {
			element:element,
			x:0,
			y:0 } );
		_lastInsertedElement = element;
			
		addWidth(getElementWidth(element));
			
		insertBreakOpportunity(false);
	}
	
	/**
	 * Insert a DOMElement and instroduce the corresponding break opportunities
	 */
	override private function insertContainerDOMElement(element:BoxElementValue):Void
	{
		insertBreakOpportunity(false);
		
		_unbreakableLineBoxElements.push( {
			element:element,
			x:0,
			y:0 } );
		_lastInsertedElement = element;
			
		addWidth(getElementWidth(element));
			
		insertBreakOpportunity(false);
	}
	
	/**
	 * Insert a DOMElement which isn't laid out. For instance an inline level inline
	 * container is not laid out, its rendered x and y position will always be to the
	 * top left of its formatting context. This is necessary as its content might span
	 * multiple line boxes.
	 * 
	 * It must still be inserted into the formatting context to be in the array of
	 * elements to render
	 * TODO : shouldn't have to insert those elements 
	 * 
	 * @param	domElement
	 * @param	parentDOMElement
	 */
	override private function insertNonLaidOutContainerDOMElement(element:BoxElementValue):Void
	{
		_unbreakableLineBoxElements.push( {
		element:element,
		x:0,
		y:0 } );
	}
	
	/**
	 * Insert a text
	 * 
	 * TODO : text shouldn't be a DOMElement but a lighter structure
	 */
	override private function insertText(element:BoxElementValue):Void
	{
		_unbreakableLineBoxElements.push( {
			element:element,
			x:0,
			y:0 } );
		_lastInsertedElement = element;	
		
		addWidth(getElementWidth(element) );
	}
	
	/**
	 * Insert a space charachter. The space might not be actually
	 * inserted if for instance it must be collapsed because
	 * space sequances are not allowed for the whiteSpace
	 * value of the space
	 */
	override private function insertSpace(element:BoxElementValue, isNextElementALineFeed:Bool):Void
	{
		//only insert space if allowed
		if (shouldInsertSpace(getElementWhiteSpace(element), isNextElementALineFeed) == true)
		{
			
			_unbreakableLineBoxElements.push( {
			element:element,
			x:0,
			y:0 } );
			
			_lastInsertedElement = element;	
			
			addWidth(getElementWidth(element));
			
			insertBreakOpportunity(false);
		}
	}
	
	/**
	 * Insert a non-breakable offset which is used
	 * for instance to render the textIndent on
	 * the first line or the render the margin/padding/border
	 * of an inline level inline container
	 * 
	 * @param	offset the width of the offset
	 */
	override private function insertOffset(element:BoxElementValue):Void
	{
		_unbreakableLineBoxElements.push( {
		element:element,
		x:0,
		y:0 } );
		
		addWidth(getElementWidth(element));
	}
	
	/**
	 * Insert a tab character. Like the space charachter it might not
	 * actually be added or might also be converted to a space
	 */
	override private function insertTab(element:BoxElementValue, isNextElementALineFeed:Bool):Void
	{
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
			y:0 } );
			
		addWidth(addedWidth);
	}
	
	/**
	 * Might force a line break if line feed are allowed
	 * for the whiteSpace value of the line feed
	 */
	override private function insertLineFeed(element:BoxElementValue):Void
	{
		if (isLineFeedAllowed(getElementWhiteSpace(element)) == true)
		{
			insertBreakOpportunity(true);
		}
	}
	
	private function getElementWhiteSpace(element:BoxElementValue):WhiteSpaceStyleValue
	{
		var elementWhiteSpace:WhiteSpaceStyleValue;
		
		switch (element)
		{
			case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
				elementWhiteSpace = whiteSpace;
				
			case BoxElementValue.tab(whiteSpace, tabWidth, parentDOMElement):
				elementWhiteSpace = whiteSpace;
				
			case BoxElementValue.lineFeed(whiteSpace, parentDOMElement):
				elementWhiteSpace = whiteSpace;
				
			default:
				elementWhiteSpace = null;
		}
		
		return elementWhiteSpace;
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
		
		_unbreakableLineBoxElements = new Array<BoxElementData>();
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
	private function shouldTabBeConvertedToSpace(whiteSpace:WhiteSpaceStyleValue):Bool
	{
		var shouldTabBeConvertedToSpace:Bool;
		
		switch (whiteSpace)
		{
			case WhiteSpaceStyleValue.normal,
			WhiteSpaceStyleValue.nowrap,
			WhiteSpaceStyleValue.preLine:
				shouldTabBeConvertedToSpace = true;
				
			case WhiteSpaceStyleValue.pre,
			WhiteSpaceStyleValue.preWrap:
				shouldTabBeConvertedToSpace = false;
		}
		
		return shouldTabBeConvertedToSpace;
	}
	
	/**
	 * Determine wether line feed is allowed
	 * based on the whiteSpace property
	 */
	private function isLineFeedAllowed(whiteSpace:WhiteSpaceStyleValue):Bool
	{
		var lineFeedAllowed:Bool;
		
		switch (whiteSpace)
		{
			case WhiteSpaceStyleValue.normal,
			WhiteSpaceStyleValue.nowrap:
				lineFeedAllowed = false;
				
			case WhiteSpaceStyleValue.pre,
			WhiteSpaceStyleValue.preWrap,
			WhiteSpaceStyleValue.preLine:
				lineFeedAllowed = true;
		}
		
		return lineFeedAllowed;
	}
	
	/**
	 * Determine wheter a space should actually be inserted
	 */
	private function shouldInsertSpace(whiteSpace:WhiteSpaceStyleValue, isNexElementALineFeed:Bool):Bool
	{
		var shouldInsertSpace:Bool;
		
		switch (whiteSpace)
		{
			case WhiteSpaceStyleValue.normal,
			WhiteSpaceStyleValue.nowrap,
			WhiteSpaceStyleValue.preLine:
				shouldInsertSpace = isNexElementALineFeed == false;
				
			case WhiteSpaceStyleValue.preWrap,
			WhiteSpaceStyleValue.pre:
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
	private function isCollapsed(lastInsertedElement:BoxElementValue, whiteSpace:WhiteSpaceStyleValue):Bool
	{
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
					case WhiteSpaceStyleValue.normal,
					WhiteSpaceStyleValue.nowrap:
						isCollapsed = true;
						
					case WhiteSpaceStyleValue.preWrap,
					WhiteSpaceStyleValue.pre,
					WhiteSpaceStyleValue.preLine:
						isCollapsed = false;
				}
				
				default:
					isCollapsed = false;
			}
		}
		
		return isCollapsed;
	}
	
	override private function clearFloat(clear:ClearStyleValue, isFloat:Bool):Void
	{
		if (isFloat == true)
		{
			 _formattingContextData.y = _floatsManager.clearFloat(clear, _formattingContextData);
		}
	}
	
	override private function placeFloat(domElement:DOMElement, parentDOMElement:DOMElement, floatData:FloatData):Void
	{
		super.placeFloat(domElement, parentDOMElement, floatData);
		
		formattingContextData.x =  _floatsManager.getLeftFloatOffset(_formattingContextData.y);
		
	}
	
	
	
	// LINE LAYOUT METHODS
	// Those methods are used to determine the x and y position
	// of each element in the line
//////////////////////////////////////////////////////////////////

	/////////////////////////////////
	// OVERRIDEN PRIVATE METHOD
	/////////////////////////////////

	override private function startNewLine(domElementWidth:Int, isLastLine:Bool = false):Void
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
			
			
			for (i in 0..._elementsInLineBox.length)
			{
				switch (_elementsInLineBox[i].element)
				{
					case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
						
						
					var childTemporaryPositionData:ChildTemporaryPositionData;
				
					
						childTemporaryPositionData = {
							element:_elementsInLineBox[i].element,
							x:_elementsInLineBox[i].x,
							y:_elementsInLineBox[i].y,
							width:domElement.offsetWidth,
							height:domElement.offsetHeight
						}

					
					getCurrentBoxesData(parentDOMElement)[0].children.push(childTemporaryPositionData);
				
				
					domElement.style.setNativeX(domElement, childTemporaryPositionData.x);
					domElement.style.setNativeY(domElement, childTemporaryPositionData.y);
					
					case BoxElementValue.containingBlockDOMElement(domElement, parentDOMElement):
						
						
					var childTemporaryPositionData:ChildTemporaryPositionData;
				
					
						childTemporaryPositionData = {
							element:_elementsInLineBox[i].element,
							x:_elementsInLineBox[i].x,
							y:_elementsInLineBox[i].y,
							width:domElement.offsetWidth,
							height:domElement.offsetHeight
						}

					
					getCurrentBoxesData(parentDOMElement)[0].children.push(childTemporaryPositionData);
				
				
					domElement.style.setNativeX(domElement, childTemporaryPositionData.x);
					domElement.style.setNativeY(domElement, childTemporaryPositionData.y);
					
					case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
						
						
					var childTemporaryPositionData:ChildTemporaryPositionData;
				

						childTemporaryPositionData = {
							element:_elementsInLineBox[i].element,
							x:0,
							y:0,
							width:0,
							height:0
						}
					
				
					getCurrentBoxesData(parentDOMElement)[0].children.push(childTemporaryPositionData);
				
				
					domElement.style.setNativeX(domElement, childTemporaryPositionData.x);
					domElement.style.setNativeY(domElement, childTemporaryPositionData.y);
					
					case BoxElementValue.text(domElement, parentDOMElement):
					
					var childTemporaryPositionData:ChildTemporaryPositionData = {
							element:_elementsInLineBox[i].element,
							x:_elementsInLineBox[i].x,
							y:_elementsInLineBox[i].y,
							width:domElement.offsetWidth,
							height:domElement.offsetHeight
						}
				
					getCurrentBoxesData(parentDOMElement)[0].children.push(childTemporaryPositionData);
				
				
					domElement.style.setNativeX(domElement, childTemporaryPositionData.x);
					domElement.style.setNativeY(domElement, childTemporaryPositionData.y);
					
				case BoxElementValue.offset(offsetWidth, parentDOMElement):
					
						var childTemporaryPositionData:ChildTemporaryPositionData = {
							element:_elementsInLineBox[i].element,
							x:_elementsInLineBox[i].x,
							y:_elementsInLineBox[i].y,
							width:offsetWidth,
							height:1
						}
				
					getCurrentBoxesData(parentDOMElement)[0].children.push(childTemporaryPositionData);
					
					default:
				}
				
				
			}
			
			
			for (i in 0..._currentBoxesData.length)
			{
				_formattingBoxesData.push(_currentBoxesData[i]);
				
			}

			
			_currentBoxesData = new Array<BoxData>();
			
			_elementsInLineBox = new Array<BoxElementData>();
			
			_formattingContextData.y += lineBoxHeight;
			
			_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData, domElementWidth, _containingDOMElementWidth);
			
			
			_formattingContextData.maxHeight = _formattingContextData.y;

			_formattingContextData.x =  _floatsManager.getLeftFloatOffset(_formattingContextData.y);
			
		}
		/**
		else
		{
			
			_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData, domElementWidth, _containingDOMElementWidth);
			

			_formattingContextData.x =  _floatsManager.getLeftFloatOffset(_formattingContextData.y);
			
			
			
		}*/
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
			case WhiteSpaceStyleValue.normal,
			WhiteSpaceStyleValue.nowrap,
			WhiteSpaceStyleValue.preLine:
				
				
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
				case WhiteSpaceStyleValue.normal,
				WhiteSpaceStyleValue.nowrap,
				WhiteSpaceStyleValue.preLine:
					
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
			concatenatedLength += getElementWidth(_elementsInLineBox[i].element);
		}
		
		//determine the remaining space in the line once all the width of the DOMElements
		//are substracted from the total avalable line width, and the x position where to 
		//insert the first DOMElement of the line, which might be influenced for instance
		//by a float
		var remainingSpace:Int;
		var flowX:Int;
		
		remainingSpace = _containingDOMElementWidth - concatenatedLength - _floatsManager.getLeftFloatOffset(_formattingContextData.y) - _floatsManager.getRightFloatOffset(_formattingContextData.y, _containingDOMElementWidth);
		flowX = 0;
		
		
		//take the float into accounts and the padding of the containing DOMElement
		flowX += _floatsManager.getLeftFloatOffset(_formattingContextData.y);
		
		//do align the DOMElements, the text align style of the containing DOMElement
		//determining the alignement to apply
		switch (_containingDOMElement.style.computedStyle.textAlign)
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
					concatenatedLength = _containingDOMElementWidth;
					
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
			_elementsInLineBox[i].x = flowX;
			flowX += getElementWidth(_elementsInLineBox[i].element);
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
			_elementsInLineBox[i].x = Math.round(remainingSpace / 2) + flowX;
			flowX += getElementWidth(_elementsInLineBox[i].element);
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
			_elementsInLineBox[i].x = flowX + remainingSpace;
			flowX += getElementWidth(_elementsInLineBox[i].element);
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
			switch (_elementsInLineBox[i].element)
			{
				case BoxElementValue.space(whiteSpace, spaceWidth, parentDOMElement):
					spacesNumber++;
					
				default:	
			}
		}
		
		//justify all DOMElements
		for (i in 0..._elementsInLineBox.length)
		{	
			//if the DOMElement is a space
			switch (_elementsInLineBox[i].element)
			{
				case BoxElementValue.space(whiteSpace, width, parentDOMElement):
					//each space has its width stretched to the same width,
					//all the concatenated width of the space fill the remaining
					//space of the line box
					var spaceWidth:Int = Math.round( (remainingSpace / spacesNumber));
					spacesNumber--;
					remainingSpace -= spaceWidth;
					flowX += spaceWidth;
					
					default:	
			}
			_elementsInLineBox[i].x = flowX ;
			flowX += getElementWidth(_elementsInLineBox[i].element);
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
			switch (_elementsInLineBox[i].element)
			{
				case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
				
				var domElementAscent:Int;
				var domElementDescent:Int;
				
				//the computed vertical align is the offset of the DOMElemenet relative
				//to the baseline
				var domElementVerticalAlign:Float = domElement.style.computedStyle.verticalAlign;
				

				
				//for embedded or inlineBlock elements, which have no baseline, the height above
				//the baseline is the offset height and they have no descent
				if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
				{
					domElementAscent = domElement.offsetHeight;
					domElementDescent = 0;
					
					switch (domElement.style.verticalAlign)
					{
						case top:
							domElementAscent = Math.round(lineBoxAscent);
							domElementDescent = Math.round(domElement.offsetHeight - lineBoxAscent);
							
						default:	
							
					}
				}
				//else retrieve the ascent and descent and apply leading to it
				else
				{
					domElementAscent = domElement.style.fontMetrics.ascent;
					domElementDescent = domElement.style.fontMetrics.descent;	
				
					//the leading is an extra height to apply equally to the ascent
					//and the descent when laying out lines of text
					var leading:Float = domElement.style.computedStyle.lineHeight - (domElementAscent + domElementDescent);
			
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
				
				case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
				
				var domElementAscent:Int;
				var domElementDescent:Int;
				
				//the computed vertical align is the offset of the DOMElemenet relative
				//to the baseline
				var domElementVerticalAlign:Float = domElement.style.computedStyle.verticalAlign;
				

				
				//for embedded or inlineBlock elements, which have no baseline, the height above
				//the baseline is the offset height and they have no descent
				if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
				{
					domElementAscent = domElement.offsetHeight;
					domElementDescent = 0;
					
					switch (domElement.style.verticalAlign)
					{
						case top:
							domElementAscent = Math.round(lineBoxAscent);
							domElementDescent = Math.round(domElement.offsetHeight - lineBoxAscent);
							
						default:	
							
					}
				}
				//else retrieve the ascent and descent and apply leading to it
				else
				{
					domElementAscent = domElement.style.fontMetrics.ascent;
					domElementDescent = domElement.style.fontMetrics.descent;	
				
					//the leading is an extra height to apply equally to the ascent
					//and the descent when laying out lines of text
					var leading:Float = domElement.style.computedStyle.lineHeight - (domElementAscent + domElementDescent);
			
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
				
				case BoxElementValue.text(domElement, parentDOMElement):
				
				var domElementAscent:Int;
				var domElementDescent:Int;
				
				//the computed vertical align is the offset of the DOMElemenet relative
				//to the baseline
				var domElementVerticalAlign:Float = domElement.style.computedStyle.verticalAlign;
				

				
				//for embedded or inlineBlock elements, which have no baseline, the height above
				//the baseline is the offset height and they have no descent
				if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
				{
					domElementAscent = domElement.offsetHeight;
					domElementDescent = 0;
					
					switch (domElement.style.verticalAlign)
					{
						case top:
							domElementAscent = Math.round(lineBoxAscent);
							domElementDescent = Math.round(domElement.offsetHeight - lineBoxAscent);
							
						default:	
							
					}
				}
				//else retrieve the ascent and descent and apply leading to it
				else
				{
					domElementAscent = domElement.style.fontMetrics.ascent;
					domElementDescent = domElement.style.fontMetrics.descent;	
				
					//the leading is an extra height to apply equally to the ascent
					//and the descent when laying out lines of text
					var leading:Float = domElement.style.computedStyle.lineHeight - (domElementAscent + domElementDescent);
			
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
				
				default:
			}
			
		
		}
		
		//compute the line box height
		var lineBoxHeight:Float = lineBoxAscent + lineBoxDescent;
		
		//for each DOMElement, place it vertically using the line box ascent and vertical align
		for (i in 0..._elementsInLineBox.length)
		{
			switch (_elementsInLineBox[i].element)
			{
				case BoxElementValue.embeddedDOMElement(domElement, parentDOMElement):
				
				
					var verticalAlign:Float;
					switch (domElement.style.verticalAlign)
					{
						case top:
							verticalAlign = 0;
							
							
						case bottom:
							verticalAlign = 0;
							
						default:
							verticalAlign = domElement.style.computedStyle.verticalAlign;
					}
					
					
					_elementsInLineBox[i].y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + _formattingContextData.y;
					//if the element is embedded or an inlineBlock, removes its offset height from its vertical position
					//so that its bottom margin touches the baseline
					if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
					{
						
						
						switch (domElement.style.verticalAlign)
						{
							case top:
								_elementsInLineBox[i].y = _formattingContextData.y;
							
							default:	
								_elementsInLineBox[i].y -= domElement.offsetHeight;
							
						}
						
						
					}
				
				case BoxElementValue.containerDOMElement(domElement, parentDOMElement):
				
				
					var verticalAlign:Float;
					switch (domElement.style.verticalAlign)
					{
						case top:
							verticalAlign = 0;
							
							
						case bottom:
							verticalAlign = 0;
							
						default:
							verticalAlign = domElement.style.computedStyle.verticalAlign;
					}
					
					
					_elementsInLineBox[i].y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + _formattingContextData.y;
					//if the element is embedded or an inlineBlock, removes its offset height from its vertical position
					//so that its bottom margin touches the baseline
					if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
					{
						
						
						switch (domElement.style.verticalAlign)
						{
							case top:
								_elementsInLineBox[i].y = _formattingContextData.y;
							
							default:	
								_elementsInLineBox[i].y -= domElement.offsetHeight;
							
						}
						
						
					}
				
				
				case BoxElementValue.text(domElement, parentDOMElement):
				
					var verticalAlign:Float;
					switch (domElement.style.verticalAlign)
					{
						case top:
							verticalAlign = 0;
							
							
						case bottom:
							verticalAlign = 0;
							
						default:
							verticalAlign = domElement.style.computedStyle.verticalAlign;
					}
					
					
					_elementsInLineBox[i].y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + _formattingContextData.y;
					//if the element is embedded or an inlineBlock, removes its offset height from its vertical position
					//so that its bottom margin touches the baseline
					if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
					{
						
						
						switch (domElement.style.verticalAlign)
						{
							case top:
								_elementsInLineBox[i].y = _formattingContextData.y;
							
							default:	
								_elementsInLineBox[i].y -= domElement.offsetHeight;
							
						}
						
						
					}
				
				
				
				default:
			}
		
		}
	
		return Math.round(lineBoxHeight);
	}
	


	
	
}