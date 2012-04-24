/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.formatter;

import cocktail.core.renderer.EmbeddedLineBox;
import cocktail.core.renderer.LineBox;
import cocktail.core.renderer.RootLineBox;
import cocktail.core.renderer.TextLineBox;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.renderer.FlowBoxRenderer;
import cocktail.core.renderer.InlineBoxRenderer;
import haxe.Log;

/**
 * This formatting context place all formatted elements
 * in lines, called line box. As many line box as necessary
 * are created to contain all the elements.
 * 
 * The formatting of a line if done in 2 phases : 
 * - first the element (text, HTMLElement, spaces...) are
 * added to the line and the white space rules of the element
 * are applied for instance to collapse sequences of white
 * spaces if necessary.
 * - when the line is full of elements, the x and yposition of 
 * each element in the line is computed, the x position using
 * the textAlign property of the HTMLElement which started
 * the inline formatting context and the y position using
 * the vertical align property
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineFormattingContext extends FormattingContext
{
	/**
	 * Stores the currently unbreakable elements in the current line.
	 * Those element can' be broken on multiple lines, if they don't all
	 * fit on the current line then a new line is created to hold them.
	 * These array may for instance hold a sequence of space if the
	 * whiteSpace style of the space are "pre"
	 * 
	 * TODO : update doc
	 */
	private var _unbreakableLineBoxes:Array<LineBox>;
	
	private var _unbreakableWidth:Int;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(formattingContextRoot:BlockBoxRenderer) 
	{
		_unbreakableLineBoxes = new Array<LineBox>();
		_unbreakableWidth = 0;
		
		super(formattingContextRoot);
		
		//set the textIndent as an offset on the first line of text
		//insertElement(BoxElementValue.offset(_containingHTMLElement.style.computedStyle.textIndent, _containingHTMLElement));
	}
	
	
	override public function dispose():Void
	{
		super.dispose();
		_unbreakableLineBoxes = null;
	}
	
	override private function doFormat(staticPositionedElement:ElementRenderer = null):Void
	{
		super.doFormat(staticPositionedElement);
		
		_unbreakableLineBoxes = new Array<LineBox>();
		startFormat(staticPositionedElement);
		
		
	}
	
	/**
	 * When the element requesting its static position in an inline formatting
	 * context, return the bound of its first line box, as the element is an
	 * absolute element which generate only one line box
	 * 
	 * TODO : messy should the elementRenderer process its bounds whenever its 
	 * line boxes are set ?
	 */
	override public function getStaticPosition(element:ElementRenderer):PointData
	{
		doFormat(element);
		var x:Float = element.lineBoxes[0].bounds.x;
		var y:Float = element.lineBoxes[0].bounds.y;
		return {x:x, y:y};
	}
	
	private function startFormat(staticPositionedElement:ElementRenderer):Void
	{
		var rootLineBoxes:Array<LineBox> = new Array<LineBox>();
		
		var initialRootLineBox:RootLineBox = new RootLineBox(_formattingContextRoot);
		rootLineBoxes.push(initialRootLineBox);
		
		_unbreakableWidth = 0;
		
		doFormat2(_formattingContextRoot, initialRootLineBox, rootLineBoxes, []);

		//format the last line
		formatLine(rootLineBoxes[rootLineBoxes.length - 1], true);
		
		_formattingContextRoot.lineBoxes = rootLineBoxes;
	}
	
	private function doFormat2(elementRenderer:ElementRenderer, lineBox:LineBox, rootLineBoxes:Array<LineBox>, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		
		//loop in all the child of the container
		for (i in 0...elementRenderer.childNodes.length)
		{
			var child:ElementRenderer = cast(elementRenderer.childNodes[i]);
			
			
			//here the child is an inline box renderer, which will create one line box for each
			//line its children are in
			if (child.hasChildNodes() == true && child.establishesNewFormattingContext() == false)
			{
				//remove all the previous line boxes before creating new ones
				child.lineBoxes = new Array<LineBox>();
				
				//create the first line box for this inline box renderer
				var childLineBox:LineBox = createContainerLineBox(child);
				
				//the first line box created by an inline box renderer has a left margin and padding
				childLineBox.marginLeft = child.coreStyle.computedStyle.marginLeft;
				childLineBox.paddingLeft = child.coreStyle.computedStyle.paddingLeft;
				//the left margin and padding is added to the unbreakable width as the next line box in the line 
				//can't be separated from this margin and padding
				_unbreakableWidth += child.coreStyle.computedStyle.marginLeft + child.coreStyle.computedStyle.paddingLeft;
				
				//attach the line box to its parent line box
				lineBox.appendChild(childLineBox);

				//store the inline box renderer, each time a new line is created
				//by laying out a child of this inline box renderer, a new line box
				//with a reference to this inline box renderer will be created, so that
				//each line into which this inline box renderer is laid out can be
 				openedElementRenderers.push(child);
				
				//format all the children of the inline box renderer recursively
				//a reference to the last added line box is returned, so that it can
				//be used as a starting point when laying out the siblings of the 
				//inline box renderer
				lineBox = doFormat2(child, childLineBox, rootLineBoxes, openedElementRenderers);
				
				//now that all of the child of the inline box renderer as been laid out,
				//remove the reference to this inline box renderer so that when a new line
				//is created, no line box pointing to this inline box renderer is created
				openedElementRenderers.pop();
				
				//The right margin and padding is added to the last generated line box of the current inline
				//box renderer
				//
				//TODO : check if it works for multiple line child
				child.lineBoxes[child.lineBoxes.length - 1].marginRight = child.coreStyle.computedStyle.marginRight;
				child.lineBoxes[child.lineBoxes.length - 1].paddingRight = child.coreStyle.computedStyle.paddingRight;
				_unbreakableWidth += child.coreStyle.computedStyle.marginRight + child.coreStyle.computedStyle.paddingRight;
			}
			//here the child is displayed as an inline-block as it starts a new formatting context
			//it generates only one line box from the perspective of this inline formatting
			//context
			else if (child.establishesNewFormattingContext() == true)
			{
				//TODO : where should those value be set ?
				child.bounds.width = child.coreStyle.computedStyle.width;
				child.bounds.height = child.coreStyle.computedStyle.height;
				
				var embeddedLineBox:LineBox = new EmbeddedLineBox(child);
				child.lineBoxes.push(embeddedLineBox);
				var childLineBoxes:Array<LineBox> = [embeddedLineBox];
				
				lineBox = insertIntoLine(childLineBoxes, lineBox, rootLineBoxes, openedElementRenderers);
			}
			//here the child can be either a text renderer, an embedded asset, like a picture
			//or an element displayed as an inline-block
			else
			{
				//get all the line boxes of the element, for instance, for a TextRenderer it will be an array
				//of TextLineBox
				var childLineBoxes:Array<LineBox> = child.lineBoxes;

				//insert the array of created line boxes into the current line. It might create as many
				//new lines as necessary. Returns a reference to the last inserted line box, used as starting
				//point to lay out subsequent siblings and children
				lineBox = insertIntoLine(childLineBoxes, lineBox, rootLineBoxes, openedElementRenderers);
			}
		}
		return lineBox;
	}
	
	/**
	 * Compute the bounds of a line box in the space
	 * of the containing block establishing this formatting context
	 * 
	 * This method is only called for the line box which can have child
	 * line boxes.
	 * 
	 * @param	lineBox the line box whose bounds must be found
	 */
	private function getLineBoxBounds(lineBox:LineBox):RectangleData
	{
		var left:Float = 50000;
		var top:Float = 50000;
		var right:Float = -50000;
		var bottom:Float = -50000;
		
		//loop in all the children of the line box
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			
			//get the bounds of the child. If the child itself can have
			//children, its bounds would have beenalready computed
			var childBounds:RectangleData = child.bounds;
			
			if (childBounds.x < left)
			{
				left = childBounds.x;
			}
			if (childBounds.y < top)
			{
				top = childBounds.y - child.leadedAscent;
			}
			if (childBounds.x + childBounds.width > right)
			{
				right = childBounds.x + childBounds.width;
			}
			if (childBounds.y + childBounds.height  > bottom)
			{
				bottom = childBounds.y + childBounds.height - child.leadedAscent;
			}
			
			//add the left and right margin of the child to the bounds
			left -= child.marginLeft;
			right += child.marginRight;
		}
		
		//add the left and right paddings of the line box to it's bounds
		left -= lineBox.paddingLeft;
		right += lineBox.paddingRight;
			
		var bounds:RectangleData = {
			x:left,
			y:top,
			width : right - left,
			height :  bottom - top,
		};
		
		//need to implement better fix,
		//sould not be negative
		if (bounds.width < 0)
		{
			bounds.width = 0;
		}
		if (bounds.height < 0)
		{
			bounds.height = 0;
		}
		
		return bounds;
	}
	
	/**
	 * Create a new line box for an inline box renderer. One line box
	 * is created for each line the inline box renderer is in
	 */
	private function createContainerLineBox(child:ElementRenderer):LineBox
	{
		var lineBox:LineBox = new LineBox(child);
		//TODO : should be reseted at the start of a layout + messy to have cross reference
		child.lineBoxes.push(lineBox);
		return lineBox;
	}
	
	/**
	 * Insert an array of line boxes into the current line. If the line boxes
	 * can't all fit in the line, as many new line as necessary are created
	 * 
	 * TODO : call for each lin box instead of an array of line boxes ?
	 */
	private function insertIntoLine(lineBoxes:Array<LineBox>, lineBox:LineBox, rootLineBoxes:Array<LineBox>, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		//loop in all the line boxes which must be added to the current line
		for ( i in 0...lineBoxes.length)
		{
			//store the line box in the unbreakable line box array, which is
			//a buffer preventing break between elements which are not supposed to
			//be break into several lines, for instance a non-breaking space
			_unbreakableLineBoxes.push(lineBoxes[i]);	
			
			//the width of the line box is added to the total width which can't be broken
			_unbreakableWidth += Math.round(lineBoxes[i].bounds.width);
				
			//get the remaining available space on the current line
			var remainingLineWidth:Int = getRemainingLineWidth();
			
			//TODO : break opportunity is not supposed to always happen

			//if there isn't enough space to fit all the line box which can't be broken
			if (remainingLineWidth - _unbreakableWidth < 0)
			{
				//TODO : should be padding left instead ?
				//
				//reset the global formatting context for the next line
				_formattingContextData.x = 0;
				
				//format the current line which is currently the last in the line array
				//, now that all the line box in it are known
				//each of the line boxes will be placed in x and y on this line
				formatLine(rootLineBoxes[rootLineBoxes.length -1], false);
				
				//create a new root for the next line, and add it to the line array
				var rootLineBox:RootLineBox = new RootLineBox(_formattingContextRoot);
				rootLineBoxes.push(rootLineBox);
				
				//set the line box which will be used to layout the following children
				//as the new root line box
				lineBox = rootLineBox;

				//create new line boxes for all the inline box renderer which still have
				//children to format, and add them to the new line
				for (j in 0...openedElementRenderers.length)
				{
					//all line boxes are attached as child of the previous created line box
					//and not as sibling to respect the hierarchy of the previous line
					var childLineBox:LineBox = createContainerLineBox(openedElementRenderers[j]);
					lineBox.appendChild(childLineBox);
					lineBox = childLineBox;
				}
			}
			
			//now that a break opportunity can occur in the line, 
			//push all the elements in the unbreakable line box
			//in the current line
			for (j in 0..._unbreakableLineBoxes.length)
			{
				lineBox.appendChild(_unbreakableLineBoxes[j]);
			}
			
			//update position on current line where the next line boxes will be added
			_formattingContextData.x += _unbreakableWidth;
			
			//reset unbreakable line box now that they were added to the line
			_unbreakableLineBoxes = new Array<LineBox>();
			_unbreakableWidth = 0;
		}
		
		return lineBox;
	}
	
	/**
	 * Srtart the formatting of a line, starting from the root line box of
	 * the line
	 * @param	rootLineBox the top of the tree of line box of this line
	 * @param	isLastLine wheter this line is the last one of this
	 * formatting context
	 */
	private function formatLine(rootLineBox:LineBox, isLastLine:Bool):Void
	{
		//TODO : should be done when computing child in the line
		removeSpaces();
		
		//format line boxes horizontally
		var lineBoxWidth:Int = alignLineBox(rootLineBox, isLastLine, getConcatenatedWidth(rootLineBox), getSpacesNumber(rootLineBox));
		
		if (lineBoxWidth > _formattingContextData.maxWidth)
		{
			_formattingContextData.maxWidth = lineBoxWidth;
		}
				
		
		//format line boxes vertically
		var lineBoxHeight:Int = computeLineBoxHeight(rootLineBox);

		//set the bounds of all the container line boxes in the line, now
		//that all line boxes are laid out
		setLineBoxesBounds(rootLineBox);
		
		//update the y of the formatting context so that the next line will start
		//below this one
		_formattingContextData.y += lineBoxHeight;
	
	}
	
	/**
	 * Set the bounds of the container line boxes using the position
	 * and dimension of thei child line boxes
	 */
	private function setLineBoxesBounds(lineBox:LineBox):Void
	{
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			
			if (child.hasChildNodes() == true)
			{
				setLineBoxesBounds(child);
				child.bounds = getLineBoxBounds(child);
			}
		}
	}
	
	/**
	 * Compute the added width of all the line box in the line
	 */
	private function getConcatenatedWidth(lineBox:LineBox):Int
	{
		var concatenatedWidth:Int = 0;
		
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			
			if (child.hasChildNodes() == true)
			{
				concatenatedWidth += getConcatenatedWidth(child);
			}
			
			concatenatedWidth += Math.round(child.bounds.width);
		}
		
		return concatenatedWidth;
	}
	
	/**
	 * Compute the number of space character found in the current
	 * line. This is used when the text is justified
	 */
	private function getSpacesNumber(lineBox:LineBox):Int
	{
		var spacesNumber:Int = 0;
		
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			
			if (child.hasChildNodes() == true)
			{
				spacesNumber += getSpacesNumber(child);
			}
			
			if (child.isSpace() == true)
			{
				spacesNumber++;
			}
		}
		
		return spacesNumber;
		
	}
	
	/**
	 * Return the width remaining in the current line
	 * of the formatting context
	 */
	private function getRemainingLineWidth():Int
	{
		return _formattingContextRoot.coreStyle.computedStyle.width - _formattingContextData.x - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y, _formattingContextRoot.coreStyle.computedStyle.width);
	}
	
	/**
	 * before a new line starts or before the inline
	 * formarring context get destroyed, align all the
	 * HTMLElements in the current line horizontally
	 * @param	isLastLine wheter it is the last line which is laid out
	 * @return returns the concantenated width of all the aligned DOMElelements.
	 * Used to determine the max line width used for shrink-to-fit algorithm
	 * 
	 * TODO : update doc
	 */
	private function alignLineBox(rootLineBox:LineBox, isLastLine:Bool, concatenatedLength:Int, spaceInLine:Int):Int
	{	
		//determine the remaining space in the line once all the width of the HTMLElements
		//are substracted from the total available line width, and the x position where to 
		//insert the first HTMLElement of the line, which might be influenced for instance
		//by a float
		var remainingSpace:Int;
		var flowX:Int;
		
		remainingSpace = _formattingContextRoot.coreStyle.computedStyle.width - concatenatedLength - _floatsManager.getLeftFloatOffset(_formattingContextData.y) - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y, _formattingContextRoot.coreStyle.computedStyle.width);
		flowX = _formattingContextRoot.coreStyle.computedStyle.paddingLeft;
		
		//take the float into accounts and the padding of the containing HTMLElement
		flowX += _floatsManager.getLeftFloatOffset(_formattingContextData.y);
		
		//do align the HTMLElements, the text align style of the containing HTMLElement
		//determining the alignement to apply
		switch (_formattingContextRoot.coreStyle.computedStyle.textAlign)
		{
			case left:
				alignLeft(flowX, rootLineBox);
				
			case right:
				alignRight(flowX, remainingSpace, rootLineBox);
				
			case center:
				alignCenter(flowX, remainingSpace, rootLineBox);
				
			case justify:	
				//the last line of an inline formatting context
				//is not justified to avoid stretching too much
				//the space between HTMLElements if there are few of them
				if (isLastLine == true)
				{
					alignLeft(flowX, rootLineBox);
				}
				else
				{
					//when justified, the concatenated width of the HTMLElements
					//must take all the containing HTMLElement width
					//TODO : move to the place where concatenated length will be computed
					concatenatedLength = _formattingContextRoot.coreStyle.computedStyle.width;
					
					alignJustify(flowX, remainingSpace, rootLineBox, spaceInLine);
				}
		}
		
		return concatenatedLength;
	}
	
	/**
	 * align the HTMLElements starting from the left edge of the containing HTMLElement
	 * @param	flowX the x position of the first HTMLElement
	 */
	private function alignLeft(flowX:Int, lineBox:LineBox):Void
	{
		flowX += lineBox.marginLeft + lineBox.paddingLeft;
		for (i in 0...lineBox.childNodes.length)
		{
			
			var child:LineBox = cast(lineBox.childNodes[i]);
			child.bounds.x = flowX;
			flowX += Math.round(child.bounds.width);
			
			if (child.hasChildNodes() == true)
			{
				alignLeft(flowX, child);
			}
		}
		flowX += lineBox.marginRight + lineBox.paddingRight;
	}
	

	/**
	 * Center the HTMLElements in the line by moving each to the right by half the remaining space
	 * @param	flowX the first availbable x position for the HTMLElement to the left most of the line box
	 * @param	remainingSpace the available width in the line box after all HTMLElements
	 * have been laid out
	 */
	private function alignCenter(flowX:Int, remainingSpace:Int, lineBox:LineBox):Void
	{
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			child.bounds.x = Math.round(remainingSpace / 2) + flowX;
			flowX += Math.round(child.bounds.width);
			
			if (child.hasChildNodes() == true)
			{
				alignCenter(flowX, remainingSpace, child);
			}
		}
	}
	
	/**
	 * align the HTMLElements starting from the right edge to the left edge of the
	 * containing HTMLElement
	 * @param	flowX the x position of the HTMLElement to left most of the line box
	 * @param	remainingSpace the available width in the line box after all HTMLElements
	 * have been laid out
	 */
	private function alignRight(flowX:Int, remainingSpace:Int, lineBox:LineBox):Void
	{
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			child.bounds.x =  flowX + remainingSpace;
			flowX += Math.round(child.bounds.width);
			
			if (child.hasChildNodes() == true)
			{
				alignRight(flowX, remainingSpace, child);
			}
		}
	}
	
	/**
	 * Justify the HTMLElements in the line box by adjusting
	 * the width of the space characters
	 * @param	flowX
	 * @param	remainingSpace
	 */
	private function alignJustify(flowX:Int, remainingSpace:Int, lineBox:LineBox, spacesInLine:Int):Void
	{
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			
			if (child.isSpace() == true)
			{
				var spaceWidth:Int = Math.round( (remainingSpace / spacesInLine));
				//TODO : should return nb of spaces as this is passed by value ?
				spacesInLine--;
				remainingSpace -= spaceWidth;
				flowX += spaceWidth;
			}
			
			child.bounds.x =  flowX;
			flowX += Math.round(child.bounds.width);
			
			if (child.hasChildNodes() == true)
			{
				alignJustify(flowX, remainingSpace, child, spacesInLine);
			}
		}
	}
	
	
	// LINE MEASUREMENT METHODS
	// Those methods are used to determine what element to render
	// in a line and when to start a new line
//////////////////////////////////////////////////////////////////
	
	
	//////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LINE MEASUREMENT METHODS
	//////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////
	// PRIVATE LINE MEASUREMENT METHODS
	//////////////////////////////////////////////////////////////////
	
	
	
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
			//shouldInsertSpace != isCollapsed(_lastInsertedElement, whiteSpace);
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
				case BoxElementValue.space(whiteSpace, spaceWidth, parentHTMLElement):
				
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
	// PRIVATE METHODS
	/////////////////////////////////
	

	
	//TODO : re-implement
	private function removeSpaces():Void
	{
		/**
		switch (_elementsInLineBox[0].htmlElement.style.computedStyle.whiteSpace)
		{
			case WhiteSpace.normal,
			WhiteSpace.nowrap,
			WhiteSpace.preLine:
				
				
				switch(_elementsInLineBox[0].htmlElementType)
				{
					case InlineBoxValue.space:
						_elementsInLineBox.shift();
						
					default:	
				}
				
								
			default:
		}
		
		if (_elementsInLineBox.length > 0)
		{
			switch (_elementsInLineBox[_elementsInLineBox.length - 1].htmlElement.style.computedStyle.whiteSpace)
			{
				case WhiteSpace.normal,
				WhiteSpace.nowrap,
				WhiteSpace.preLine:
					
				switch(	_elementsInLineBox[_elementsInLineBox.length - 1].htmlElementType)
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
	// PRIVATE VERTICAL ALIGNEMENT METHODS
	/////////////////////////////////
	
	/**
	 * When a line box is full and a new line will
	 * be created, compute the height of the current line
	 * box and place its HTMLElement vertically.
	 * 
	 * A line box height corresponds to the addition 
	 * of the highest ascent and descent of its
	 * HTMLElement above the baseline
	 * 
	 * TODO : finish implementation of verticalAlign
	 * 
	 * TODO : update doc
	 */
	private function computeLineBoxHeight(rootLineBox:LineBox):Int
	{
		setRootLineBoxMetrics(rootLineBox, rootLineBox);
		alignLineBoxesVertically(rootLineBox, rootLineBox.leadedAscent, _formattingContextData.y);
		
		//compute the line box height
		var lineBoxHeight:Float = rootLineBox.leadedAscent + rootLineBox.leadedDescent;
		
		return Math.round(lineBoxHeight);
	}
	
	private function setRootLineBoxMetrics(lineBox:LineBox, rootLineBox:LineBox):Void
	{
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			if (child.hasChildNodes() == true)
			{
				setRootLineBoxMetrics(child, rootLineBox);
			}
			
			var leadedAscent:Float = child.leadedAscent;
			var leadedDescent:Float = child.leadedDescent;
			var verticalAlign:Float = child.verticalAlign;
			if (leadedAscent - verticalAlign > rootLineBox.leadedAscent)
			{
				rootLineBox.leadedAscent = leadedAscent - verticalAlign;
			}
			
			if (leadedDescent + verticalAlign > rootLineBox.leadedDescent)
			{
				rootLineBox.leadedDescent = leadedDescent + verticalAlign;
			}
		}
	}
	
	private function alignLineBoxesVertically(lineBox:LineBox, lineBoxAscent:Float, formattingContextY:Int):Void
	{
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			
			if (child.hasChildNodes() == true)
			{
				alignLineBoxesVertically(child, lineBoxAscent, formattingContextY);
			}

			child.bounds.y = lineBoxAscent + formattingContextY + child.verticalAlign;
			
			//TODO : used for embedded or inline block but implement better
			if (child.establishesNewFormattingContext() == true)
			{
				child.bounds.y -= child.leadedAscent;
			}
		}
	}
	
}