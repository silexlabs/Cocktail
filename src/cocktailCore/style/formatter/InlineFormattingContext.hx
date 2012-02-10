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
 * This formatting context place all formatted DOMElements
 * in lines, called line box. When the line is full and can't contain other
 * DOMElements, a new line is created
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineFormattingContext extends FormattingContext
{

	/**
	 * The DOMElements in the current line
	 */
	private var _elementsInLineBox:Array<LineBoxElementData>;
	
	private var _unbreakableLineBoxElements:Array<LineBoxElementData>;
	
	private var _unbreakableWidth:Int;

	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(domElement:DOMElement, previousFormattingContext:FormattingContext) 
	{
		_elementsInLineBox = new Array<LineBoxElementData>();
		_unbreakableLineBoxElements = new Array<LineBoxElementData>();
		_unbreakableWidth = 0;
		
		super(domElement, previousFormattingContext);
		
		insertOffset(_containingDOMElement.style.computedStyle.textIndent);
	}
	
	/**
	 * Called when the inline formatting context will
	 * be replaced by anohter. Used to ensure that the last line
	 * of DOMElements is laid out
	 */
	override public function destroy():Void
	{
		insertBreakOpportunity(true, true);
	}
	
//////////////////////////////////////////////////////////////////

	/**
	 * Insert a DOMElement in the formatting context's
	 * flow
	 */
	override public function insertDOMElement(domElement:DOMElement, parentDOMElement:DOMElement):Void
	{
		insertBreakOpportunity(false);
		
		_unbreakableLineBoxElements.push( {
			element:LineBoxElementValue.domElement(domElement, parentDOMElement, true),
			x:0,
			y:0 } );
			
		addWidth(domElement.offsetWidth);
			
		insertBreakOpportunity(false);
	}
	
	private function addWidth(width:Int):Void
	{
		_unbreakableWidth += width;
	}
	
	private function insertBreakOpportunity(forced:Bool, isLastLine:Bool = false):Void
	{
		var remainingLineWidth:Int = getRemainingLineWidth();
		
		if (isLastLine == true)
		{
			insertBreakOpportunity(false, false);
		}
		
		if ((remainingLineWidth - _unbreakableWidth < 0) || forced == true)
		{
			startNewLine(_unbreakableWidth, isLastLine);
		}
		
		for (i in 0..._unbreakableLineBoxElements.length)
		{
			_elementsInLineBox.push(_unbreakableLineBoxElements[i]);
		}
		
		_unbreakableLineBoxElements = new Array<LineBoxElementData>();
		_formattingContextData.x += _unbreakableWidth;
		_unbreakableWidth = 0;
		
	}
	
	override public function insertNonLaidOutDOMElement(domElement:DOMElement, parentDOMElement:DOMElement):Void
	{
			_unbreakableLineBoxElements.push( {
			element:LineBoxElementValue.domElement(domElement, parentDOMElement, false),
			x:0,
			y:0 } );
	}
	
	override public function insertText(domElement:DOMElement, parentDOMElement:DOMElement):Void
	{
		_unbreakableLineBoxElements.push( {
			element:LineBoxElementValue.text(domElement, parentDOMElement),
			x:0,
			y:0 } );
		
		addWidth(domElement.offsetWidth);
	}
	
	/**
	 * Insert a space character, wrapped in a DOMElement
	 * in the formatting context
	 */
	override public function insertSpace(whiteSpace:WhiteSpaceStyleValue, spaceWidth:Int):Void
	{
		//TODO : add isLastInsertedASpace
		if (isCollapsed(false, whiteSpace) == false)
		{
			_unbreakableLineBoxElements.push( {
			element:LineBoxElementValue.space(spaceWidth),
			x:0,
			y:0 } );
			
			addWidth(spaceWidth);
			
			insertBreakOpportunity(false);
		}
	}
	
	override public function insertOffset(offset:Int):Void
	{
		
		_unbreakableLineBoxElements.push( {
		element:LineBoxElementValue.offset(offset),
		x:0,
		y:0 } );
		
		addWidth(offset);
	
	}
	
	/**
	 * Insert a tab character, wrapped in a DOMElement
	 * in the formatting context
	 */
	override public function insertTab(whiteSpace:WhiteSpaceStyleValue, tabWidth:Int):Void
	{
		
		_unbreakableLineBoxElements.push( {
			element:LineBoxElementValue.tab(tabWidth),
			x:0,
			y:0 } );
			
		addWidth(tabWidth);
	}
	
	/**
	 * Start a new line by inserting a new line
	 * control character
	 */
	override public function insertLineFeed(whiteSpace:WhiteSpaceStyleValue):Void
	{
		if (isLineFeedAllowed(whiteSpace) == true)
		{
			insertBreakOpportunity(true);
		}
	}
	
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
	
	private function isCollapsed(isLastElementInsertedASpace:Bool, whiteSpace:WhiteSpaceStyleValue):Bool
	{
		var isCollapsed:Bool;
		
		if (isLastElementInsertedASpace == true)
		{
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
		}
		else
		{
			isCollapsed = false;
		}
		
		return isCollapsed;
	}
	
//////////////////////////////////////////////////////////////////	
	

	
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
					case LineBoxElementValue.domElement(domElement, parentDOMElement, position):
						
					var childTemporaryPositionData:ChildTemporaryPositionData = getChildTemporaryPositionData(
					domElement, _elementsInLineBox[i].x, _elementsInLineBox[i].y, position);
				

					
					getCurrentBoxesData(parentDOMElement)[0].children.push(childTemporaryPositionData);
				
				
					domElement.style.setNativeX(domElement, childTemporaryPositionData.x);
					domElement.style.setNativeY(domElement, childTemporaryPositionData.y);
					
					case LineBoxElementValue.text(domElement, parentDOMElement):
					
					var childTemporaryPositionData:ChildTemporaryPositionData = getChildTemporaryPositionData(
					domElement, _elementsInLineBox[i].x, _elementsInLineBox[i].y, true);
				
	
				
					getCurrentBoxesData(parentDOMElement)[0].children.push(childTemporaryPositionData);
				
				
					domElement.style.setNativeX(domElement, childTemporaryPositionData.x);
					domElement.style.setNativeY(domElement, childTemporaryPositionData.y);
					
					default:
				}
				
			}
			
			
			for (i in 0..._currentBoxesData.length)
			{
				_formattingBoxesData.push(_currentBoxesData[i]);
				
			}

			
			_currentBoxesData = new Array<BoxData>();
			
			_elementsInLineBox = new Array<LineBoxElementData>();
			
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
	
	override public function clearFloat(clear:ClearStyleValue, isFloat:Bool):Void
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
	
	private function getElementWidth(element:LineBoxElementValue):Int
	{
		var elementWidth:Int;
		
		switch (element)
			{
				case LineBoxElementValue.domElement(domElement, parentDOMElement, position):
					if (position == true)
					{
						elementWidth = domElement.offsetWidth;
					}
					else
					{
						elementWidth = 0;
					}
					
				case LineBoxElementValue.text(domElement, parentDOMElement):
					elementWidth = domElement.offsetWidth;
					
				case LineBoxElementValue.offset(value):
					elementWidth = value;
					
				case LineBoxElementValue.space(spaceWidth):
					elementWidth = spaceWidth;
					
				case LineBoxElementValue.tab(tabWidth):
					elementWidth = tabWidth;
			}
			
		return 	elementWidth;
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
				case LineBoxElementValue.space(spaceWidth):
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
				case LineBoxElementValue.space(width):
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
				case LineBoxElementValue.domElement(domElement, parentDOMElement, position):
				
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
				
				case LineBoxElementValue.text(domElement, parentDOMElement):
				
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
				case LineBoxElementValue.domElement(domElement, parentDOMElement, position):
				
				if (position == true)
				{
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
				}
				
				case LineBoxElementValue.text(domElement, parentDOMElement):
				
				if (true)
				{
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
				}
				
				
				default:
			}
		
		}
	
		return Math.round(lineBoxHeight);
	}
	


	
	
}