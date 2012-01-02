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
	private var _domElementInLineBox:Array<LineBoxElementData>;
	
	/**
	 * Determine wheter the first line of the formatting context was
	 * already laid out. Used when applying text indent which is only
	 * applied to the first line of an inline formatting context
	 */
	private var _firstLineLaidOut:Bool;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(domElement:DOMElement, previousFormattingContext:FormattingContext) 
	{
		_firstLineLaidOut = false;
		_domElementInLineBox = new Array<LineBoxElementData>();
		
		super(domElement, previousFormattingContext);
	}
	
	/**
	 * Called when the inline formatting context will
	 * be replaced by anohter. Used to ensure that the last line
	 * of DOMElements is laid out
	 */
	override public function destroy():Void
	{
		startNewLine(0, true);
	}
	

	override public function insert(domElement:DOMElement):Void
	{
		
		var remainingWidth:Int = getRemainingLineWidth();
		
		if (_firstLineLaidOut == false)
		{
			remainingWidth -= _containingDOMElement.style.computedStyle.textIndent;
		}
		
		
		if (remainingWidth - domElement.offsetWidth < 0)
		{	
			switch(domElement.style.computedStyle.whiteSpace)
			{
				case WhiteSpaceStyleValue.normal,
				WhiteSpaceStyleValue.preLine:
					if (_firstLineLaidOut == false)
					{
						startNewLine(domElement.offsetWidth +  _containingDOMElement.style.computedStyle.textIndent );
					}
					else
					{
						startNewLine(domElement.offsetWidth);
					}
				default:	
					
			}
			
		}
		
		_domElementInLineBox.push({domElement:domElement, domElementType:InlineBoxValue.domElement});
		super.insert(domElement);
	}
	
	override public function insertSpace(domElement:DOMElement):Void
	{
		var remainingWidth:Int = getRemainingLineWidth();
		
		if (_firstLineLaidOut == false)
		{
			remainingWidth -= _containingDOMElement.style.computedStyle.textIndent;
		}
		
		if (remainingWidth - domElement.offsetWidth < 0)
		{	
			switch(domElement.style.computedStyle.whiteSpace)
			{
				case WhiteSpaceStyleValue.normal,
				WhiteSpaceStyleValue.preLine:
					startNewLine(domElement.offsetWidth);
				
				default:	
					
			}
		}
		_domElementInLineBox.push({domElement:domElement, domElementType:InlineBoxValue.space});
		
		super.insertSpace(domElement);
	}
	
	/**
	 * Overiden to imcrement the x position of the
	 * flowData with the placed DOMElement's offset width
	 */
	override private function place(domElement:DOMElement):Void
	{
		super.place(domElement);
		_flowData.x += domElement.offsetWidth;
	}
	
	override private function startNewLine(domElementWidth:Int, isLastLine:Bool = false):Void
	{
		if (_domElementInLineBox.length > 0)
		{
			removeSpaces();
			var lineBoxHeight:Int = computeLineBoxHeight();
		
			var lineWidth:Int = alignLineBox(_firstLineLaidOut == false, isLastLine);
			if (lineWidth > _flowData.maxWidth)
			{
				_flowData.maxWidth = lineWidth;
			}
			
			_domElementInLineBox = new Array<LineBoxElementData>();
			
			_flowData.y += lineBoxHeight;
			
			_flowData.y = _floatsManager.getFirstAvailableY(_flowData, domElementWidth, _containingDOMElementWidth);
			
			
			_flowData.totalHeight = _flowData.y;
			if (_floatsManager.getLeftFloatOffset(_flowData.y) > _flowData.xOffset)
			{
				
				flowData.x =  _floatsManager.getLeftFloatOffset(_flowData.y);
			}
			else
			{
				_flowData.x = _flowData.xOffset;
			}
			
			_firstLineLaidOut = true;
		}
		else
		{
			
			_flowData.y = _floatsManager.getFirstAvailableY(_flowData, domElementWidth, _containingDOMElementWidth);
			
			if (_floatsManager.getLeftFloatOffset(_flowData.y) > _flowData.xOffset)
			{
				
				flowData.x =  _floatsManager.getLeftFloatOffset(_flowData.y);
			}
			else
			{
				_flowData.x = _flowData.xOffset;
			}
			
			
		}
	}
	
	override public function clearFloat(clear:ClearStyleValue, isFloat:Bool):Void
	{
		if (isFloat == true)
		{
			 _flowData.y = _floatsManager.clearFloat(clear, _flowData);
		}
	}
	
	override private function placeFloat(domElement:DOMElement, floatData:FloatData):Void
	{
		super.placeFloat(domElement, floatData);
		
		if (_floatsManager.getLeftFloatOffset(_flowData.y) > _flowData.xOffset)
		{
			flowData.x =  _floatsManager.getLeftFloatOffset(_flowData.y);
		}
		else
		{
			_flowData.x = _flowData.xOffset;
		}
	}
	
	private function removeSpaces():Void
	{
		switch (_domElementInLineBox[0].domElement.style.computedStyle.whiteSpace)
		{
			case WhiteSpaceStyleValue.normal,
			WhiteSpaceStyleValue.nowrap,
			WhiteSpaceStyleValue.preLine:
				
				
				switch(_domElementInLineBox[0].domElementType)
				{
					case InlineBoxValue.space:
						_domElementInLineBox.shift();
						
					default:	
				}
				
								
			default:
		}
		
		if (_domElementInLineBox.length > 0)
		{
			switch (_domElementInLineBox[_domElementInLineBox.length - 1].domElement.style.computedStyle.whiteSpace)
			{
				case WhiteSpaceStyleValue.normal,
				WhiteSpaceStyleValue.nowrap,
				WhiteSpaceStyleValue.preLine:
					
				switch(	_domElementInLineBox[_domElementInLineBox.length - 1].domElementType)
				{
					case InlineBoxValue.space:
						_domElementInLineBox.pop();
						
					default:	
				}
				
				default:
			}
		}	
	}
	
	/////////////////////////////////
	// PRIVATE HORIZONTAL ALIGNEMENT METHODS
	/////////////////////////////////
	
	/**
	 * before a new line starts or before the inline
	 * formarring context get destroyed, align all the
	 * DOMElements in the current line horizontally
	 * @param	firstLine wether it is the first line which is laid out
	 * @param	isLastLine wheter it is the last line which is laid out
	 * @return returns the concantenated width of all the aligned DOMElelements.
	 * Used to determine the max line width used for shrink-to-fit algorithm
	 */
	private function alignLineBox(isFirstLine:Bool, isLastLine:Bool):Int
	{	
		//determine the added offset width of
		//all DOMElements in the line box
		var concatenatedLength:Int = 0;
		for (i in 0..._domElementInLineBox.length)
		{
			concatenatedLength += _domElementInLineBox[i].domElement.offsetWidth;
		}
		
		//determine the remaining space in the line once all the width of the DOMElements
		//are substracted from the total avalable line width, and the x position where to 
		//insert the first DOMElement of the line, which might be influenced for instance
		//by a float
		var remainingSpace:Int;
		var flowX:Int;
		
		//if the first line is being laid out,
		//then the textIndent must be taken into account
		//it only applies to the first line
		if (isFirstLine == true)
		{
			remainingSpace = _containingDOMElementWidth - concatenatedLength - _containingDOMElement.style.computedStyle.textIndent - _floatsManager.getLeftFloatOffset(_flowData.y) - _floatsManager.getRightFloatOffset(_flowData.y, _containingDOMElementWidth);
			flowX = _containingDOMElement.style.computedStyle.textIndent;
		}
		else
		{
			remainingSpace = _containingDOMElementWidth - concatenatedLength - _floatsManager.getLeftFloatOffset(_flowData.y) - _floatsManager.getRightFloatOffset(_flowData.y, _containingDOMElementWidth);
			flowX = 0;
		}
		
		//take the float into accounts and the padding of the containing DOMElement
		flowX += _floatsManager.getLeftFloatOffset(_flowData.y) + _flowData.xOffset;
		
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
		for (i in 0..._domElementInLineBox.length)
		{
			var domElement:DOMElement = _domElementInLineBox[i].domElement;
			domElement.style.setNativeX(domElement, flowX + domElement.style.computedStyle.marginLeft);
			flowX += domElement.offsetWidth;
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
		for (i in 0..._domElementInLineBox.length)
		{
			var domElement:DOMElement = _domElementInLineBox[i].domElement;
			domElement.style.setNativeX(domElement, Math.round(remainingSpace / 2) + flowX + domElement.style.computedStyle.marginLeft);
			flowX += domElement.offsetWidth;
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
		for (i in 0..._domElementInLineBox.length)
		{
			var domElement:DOMElement = _domElementInLineBox[i].domElement;
			domElement.style.setNativeX(domElement, flowX + domElement.style.computedStyle.marginLeft + remainingSpace);
			flowX += domElement.offsetWidth;
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
		//determine how many space there among the 
		//DOMElements of the line box
		var spacesNumber:Int = 0;
		for (i in 0..._domElementInLineBox.length)
		{
			switch (_domElementInLineBox[i].domElementType)
			{
				case space:
					spacesNumber++;
					
				default:	
			}
		}
		
		//justify all DOMElements
		for (i in 0..._domElementInLineBox.length)
		{
			var domElement:DOMElement = _domElementInLineBox[i].domElement;
			
			//if the DOMElement is a space
			switch (_domElementInLineBox[i].domElementType)
			{
				case space:
					//each space has its width strecth the the same width,
					//all the concatenated width of the space fill the remaining
					//space of the line box
					var spaceWidth:Int = Math.round( (remainingSpace / spacesNumber));
					spacesNumber--;
					remainingSpace -= spaceWidth;
					flowX += spaceWidth;
					
					default:	
			}
			//place the DOMElement
			domElement.style.setNativeX(domElement, flowX + domElement.style.computedStyle.marginLeft);
			
			flowX += domElement.offsetWidth;
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
		for (i in 0..._domElementInLineBox.length)
		{
			var domElement:DOMElement = _domElementInLineBox[i].domElement;
			var domElementAscent:Int;
			var domElementDescent:Int;
			
			//the computed vertical align is the offset of the DOMElemenet relative
			//to the baseline
			var domElementVerticalAlign:Float = domElement.style.computedStyle.verticalAlign;
			
			//for embedded or inlineBlock elements, which have no baseline, the height zabove
			//the baseline is the offset height and they have no descent
			if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
			{
				domElementAscent = domElement.offsetHeight;
				domElementDescent = 0;
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
		}
		
		//compute the line box height
		var lineBoxHeight:Float = lineBoxAscent + lineBoxDescent;
		
		//for each DOMElement, place it vertically using the line box ascent and vertical align
		for (i in 0..._domElementInLineBox.length)
		{
			var domElement:DOMElement = _domElementInLineBox[i].domElement;
			domElement.style.setNativeY(domElement, Math.round(lineBoxAscent) + Math.round(domElement.style.computedStyle.verticalAlign) + _flowData.y + domElement.style.computedStyle.marginTop);
			
			//if the element is embedded or an inlineBlock, removes its offset height from its vertical position
			//so that its bottom margin touches the baseline
			if (domElement.style.isEmbedded() == true || domElement.style.display == inlineBlock)
			{
				domElement.style.setNativeY(domElement, domElement.style.getNativeY() - domElement.offsetHeight);
			}
		}
		
		return Math.round(lineBoxHeight);
	}
	


	
	
}