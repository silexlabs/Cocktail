/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.formatter;

import cocktail.core.renderer.EmbeddedLineBox;
import cocktail.core.renderer.InlineBlockLineBox;
import cocktail.core.renderer.LineBox;
import cocktail.core.renderer.RootLineBox;
import cocktail.core.renderer.TextLineBox;
import cocktail.core.style.floats.FloatsManager;
import cocktail.core.style.StyleData;
import cocktail.core.geom.GeomData;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
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
	
	private var _unbreakableWidth:Float;
	
	//TODO : doc + should find a cleaner way for text indent
	private var _firstLineFormatted:Bool;
	
	/**
	 * class constructor. Init class attributes
	 */
	public function new(formattingContextRoot:BlockBoxRenderer) 
	{
		_unbreakableLineBoxes = new Array<LineBox>();
		_unbreakableWidth = 0.0;
		_firstLineFormatted = false;
		super(formattingContextRoot);
	}

	
	override private function startFormatting():Void
	{
		
		_unbreakableLineBoxes = new Array<LineBox>();
		var rootLineBoxes:Array<LineBox> = new Array<LineBox>();
		var initialRootLineBox:RootLineBox = new RootLineBox(_formattingContextRoot);
		rootLineBoxes.push(initialRootLineBox);
		
		//TODO : should implement text indent in a cleaner way
		_unbreakableWidth = _formattingContextRoot.coreStyle.computedStyle.textIndent;
		
		//_formattingContextData.y += _formattingContextRoot.bounds.y;
		_formattingContextData.x = _formattingContextRoot.coreStyle.computedStyle.textIndent;
		_formattingContextData.x += _floatsManager.getLeftFloatOffset(_formattingContextRoot.bounds.y);

		doFormat(_formattingContextRoot, initialRootLineBox, rootLineBoxes, []);

		//format the last line
		formatLine(rootLineBoxes[rootLineBoxes.length - 1], true);

		_formattingContextRoot.lineBoxes = rootLineBoxes;

		//apply formatting height to formatting context root if auto height
		if (_formattingContextRoot.coreStyle.height == Dimension.cssAuto)
		{
			_formattingContextRoot.bounds.height = _formattingContextData.y  + _formattingContextRoot.coreStyle.computedStyle.paddingBottom ;
			_formattingContextRoot.coreStyle.computedStyle.height = _formattingContextRoot.bounds.height - _formattingContextRoot.coreStyle.computedStyle.paddingBottom  - _formattingContextRoot.coreStyle.computedStyle.paddingTop;
		
		}
	}
	
	private function doFormat(elementRenderer:ElementRenderer, lineBox:LineBox, rootLineBoxes:Array<LineBox>, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		//loop in all the child of the container
		var length:Int = elementRenderer.childNodes.length;
		for (i in 0...length)
		{
			var child:ElementRenderer = elementRenderer.childNodes[i];
			
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
				lineBox = doFormat(child, childLineBox, rootLineBoxes, openedElementRenderers);
				
				//now that all of the child of the inline box renderer as been laid out,
				//remove the reference to this inline box renderer so that when a new line
				//is created, no line box pointing to this inline box renderer is created
				openedElementRenderers.pop();
				
				//The current line box must also be set to the parent line box so that no more
				//line boxes are added to this line box as it is done formatting its child line boxes
				lineBox = lineBox.parentNode;
				
				//The right margin and padding is added to the last generated line box of the current inline
				//box renderer
				child.lineBoxes[child.lineBoxes.length - 1].marginRight = child.coreStyle.computedStyle.marginRight;
				child.lineBoxes[child.lineBoxes.length - 1].paddingRight = child.coreStyle.computedStyle.paddingRight;
				_unbreakableWidth += child.coreStyle.computedStyle.marginRight + child.coreStyle.computedStyle.paddingRight;
			}
			//here the child is displayed as an inline-block as it starts a new formatting context
			//it generates only one line box 
			else if (child.establishesNewFormattingContext() == true)
			{
				child.bounds.width = child.coreStyle.computedStyle.width;
				child.bounds.height = child.coreStyle.computedStyle.height;
				
				var inlineBlockLineBox:LineBox = new InlineBlockLineBox(child);
				child.lineBoxes.push(inlineBlockLineBox);
				
				inlineBlockLineBox.marginLeft = child.coreStyle.computedStyle.marginLeft;
				inlineBlockLineBox.marginRight = child.coreStyle.computedStyle.marginRight;

				var childLineBoxes:Array<LineBox> = [inlineBlockLineBox];
				
				lineBox = insertIntoLine(childLineBoxes, lineBox, rootLineBoxes, openedElementRenderers);
			}
			
			//TODO : Text should not be considered embed, isEmbedded should be removed
			else if (child.isReplaced() == true && child.isText() == false)
			{
				var embeddedLineBox:LineBox = new EmbeddedLineBox(child);
				child.lineBoxes.push(embeddedLineBox);
				
				//TODO : should had left and right margin to line box, like for inline-block
				
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
	 * TODO : should take marginLeft and marginRight into account
	 */
	private function insertIntoLine(lineBoxes:Array<LineBox>, lineBox:LineBox, rootLineBoxes:Array<LineBox>, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		
		//loop in all the line boxes which must be added to the current line
		var length:Int = lineBoxes.length;
		for ( i in 0...length)
		{
			//store the line box in the unbreakable line box array, which is
			//a buffer preventing break between elements which are not supposed to
			//be break into several lines, for instance a non-breaking space
			_unbreakableLineBoxes.push(lineBoxes[i]);	
			
			//line boxes generated by absolutely positioned elements do not enter
			//into account when calculating line breaks
			if (lineBoxes[i].isAbsolutelyPositioned() == false || lineBoxes[i].isText() == true)
			{
				//the width of the line box is added to the total width which can't be broken
				_unbreakableWidth += lineBoxes[i].bounds.width + lineBox.marginLeft + lineBox.marginRight;
			}
		
				
			//get the remaining available space on the current line
			var remainingLineWidth:Float = getRemainingLineWidth();

			//if there isn't enough space to fit all the line box which can't be broken
			//TODO 1 : should apply white space processing model for line break here
			if (remainingLineWidth - _unbreakableWidth < 0)
			{
				//TODO : should be padding left instead ?
				//
				_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData.y + _formattingContextRoot.bounds.y, _unbreakableWidth,
				_formattingContextRoot.coreStyle.computedStyle.width);
				
				_formattingContextData.y -= _formattingContextRoot.bounds.y;
				
				_formattingContextData.x = _floatsManager.getLeftFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y);
				
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
			var unbreakableLength:Int = _unbreakableLineBoxes.length;
			for (j in 0...unbreakableLength)
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
		//TODO 1 : should apply white space processing to remove space at the end and beginning
		//of line here
		removeSpaces(rootLineBox);
		
		//format line boxes horizontally
		var lineBoxWidth:Float = alignLineBox(rootLineBox, isLastLine, getConcatenatedWidth(rootLineBox), getSpacesNumber(rootLineBox));
		
		if (lineBoxWidth > _formattingContextData.maxWidth)
		{
			_formattingContextData.maxWidth = lineBoxWidth;
		}
		
		//format line boxes vertically
		var lineBoxHeight:Float = computeLineBoxHeight(rootLineBox);
		
		//update the y of the formatting context so that the next line will start
		//below this one
		_formattingContextData.y += lineBoxHeight;
		_firstLineFormatted = true;
	
	}
	
	/**
	 * Compute the added width of all the line box in the line
	 */
	private function getConcatenatedWidth(lineBox:LineBox):Float
	{
		var concatenatedWidth:Float = 0.0;
		
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			if (child.hasChildNodes() == true && (child.isAbsolutelyPositioned() == false || child.isText() == true))
			{
				concatenatedWidth += getConcatenatedWidth(child);
			}
			
			if (child.isAbsolutelyPositioned() == false || child.isText() == true)
			{
				concatenatedWidth += child.bounds.width;
			}
			
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
			var child:LineBox = lineBox.childNodes[i];
			
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
	private function getRemainingLineWidth():Float
	{
		return _formattingContextRoot.coreStyle.computedStyle.width - _formattingContextData.x - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y, _formattingContextRoot.coreStyle.computedStyle.width);
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
	private function alignLineBox(rootLineBox:LineBox, isLastLine:Bool, concatenatedLength:Float, spaceInLine:Int):Float
	{	
		//determine the remaining space in the line once all the width of the HTMLElements
		//are substracted from the total available line width, and the x position where to 
		//insert the first HTMLElement of the line, which might be influenced for instance
		//by a float
		var remainingSpace:Float;
		var flowX:Float;
		
		remainingSpace = _formattingContextRoot.coreStyle.computedStyle.width - concatenatedLength - _floatsManager.getLeftFloatOffset(_formattingContextData.y) - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y, _formattingContextRoot.coreStyle.computedStyle.width);
		flowX = _formattingContextRoot.coreStyle.computedStyle.paddingLeft;
		
		
		if (_firstLineFormatted == false)
		{
			flowX += _formattingContextRoot.coreStyle.computedStyle.textIndent;
			remainingSpace -= _formattingContextRoot.coreStyle.computedStyle.textIndent;
		}
		
		//take the float into accounts and the padding of the containing HTMLElement
		flowX += _floatsManager.getLeftFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y);
		
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
					concatenatedLength = _formattingContextRoot.coreStyle.computedStyle.width;
					 
					alignJustify(flowX, remainingSpace, rootLineBox, spaceInLine);
				}
		}
		
		return concatenatedLength;
	}
	
	/**
	 * align the HTMLElements starting from the left edge of the containing HTMLElement
	 * 
	 * TODO 4 : margins are not used for embedded line boxes
	 * 
	 * TODO 4 : absolutely positioned line box should not add their width to the flowX,
	 * should also do it for align right, center and justify
	 * 
	 * @param	flowX the x position of the first HTMLElement
	 */
	private function alignLeft(flowX:Float, lineBox:LineBox):Float
	{

		flowX += lineBox.paddingLeft + lineBox.marginLeft;
		
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			//TODO 4 : doc + should also update alignRight, justify... in the same way
			if (child.hasChildNodes() == true && child.isAbsolutelyPositioned() == false)
			{
				flowX = alignLeft(flowX, child);
			}
			else
			{
				child.bounds.x = flowX + child.marginLeft;
				
				//TODO 4 : a bit hackish to require checking if is text
				if (child.isAbsolutelyPositioned() == false || child.isText() == true )
				{
					flowX += child.bounds.width + child.marginLeft + child.marginRight;
				}
			
			}
		}
		
		flowX += lineBox.paddingRight + lineBox.marginRight;
		
		return flowX;
	}
	

	/**
	 * Center the HTMLElements in the line by moving each to the right by half the remaining space
	 * 
	 * TODO 4 : flowX, remainingSpace should be passed by reference, not value
	 * 
	 * 
	 * @param	flowX the first availbable x position for the HTMLElement to the left most of the line box
	 * @param	remainingSpace the available width in the line box after all HTMLElements
	 * have been laid out
	 */
	private function alignCenter(flowX:Float, remainingSpace:Float, lineBox:LineBox):Float
	{
		flowX += lineBox.marginLeft + lineBox.paddingLeft;
		
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			if (child.hasChildNodes() == true)
			{
				flowX =  alignCenter(flowX, remainingSpace, child);
			}
			
			child.bounds.x = (remainingSpace / 2) + flowX;
			flowX += child.bounds.width;
		}
		
		flowX += lineBox.marginRight + lineBox.paddingRight;
		
		return flowX;
	}
	
	/**
	 * align the HTMLElements starting from the right edge to the left edge of the
	 * containing HTMLElement
	 * 
	 * TODO 4 : flowX, remainingSpace should be passed by reference, not value
	 * 
	 * @param	flowX the x position of the HTMLElement to left most of the line box
	 * @param	remainingSpace the available width in the line box after all HTMLElements
	 * have been laid out
	 */
	private function alignRight(flowX:Float, remainingSpace:Float, lineBox:LineBox):Float
	{
		flowX += lineBox.marginLeft + lineBox.paddingLeft;
		
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			if (child.hasChildNodes() == true)
			{
				flowX = alignRight(flowX, remainingSpace, child);
			}
			
			child.bounds.x = flowX + remainingSpace;
			flowX += child.bounds.width;
		}
		
		flowX += lineBox.marginRight + lineBox.paddingRight;
		
		return flowX;
	}
	
	/**
	 * Justify the HTMLElements in the line box by adjusting
	 * the width of the space characters
	 * 
	 * TODO 4 : flowX, remainingSpace and spacesInLine should be passed by reference, not value
	 * 
	 * @param	flowX
	 * @param	remainingSpace
	 */
	private function alignJustify(flowX:Float, remainingSpace:Float, lineBox:LineBox, spacesInLine:Int):Void
	{
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			if (child.isSpace() == true)
			{
				var spaceWidth:Float = (remainingSpace / spacesInLine);
				//TODO : should return nb of spaces as this is passed by value ?
				spacesInLine--;
				remainingSpace -= spaceWidth;
				flowX += spaceWidth;
			}
			
			child.bounds.x =  flowX;
			flowX += child.bounds.width;
			
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
	

	
	//TODO 2 : add doc, remove start and end spaces in a line
	private function removeSpaces(rootLineBox:LineBox):Void
	{
		
		var lineBoxes:Array<LineBox> = getLineBoxTreeAsArray(rootLineBox);
		
		if (lineBoxes.length == 0)
		{
			return;
		}
		
		var i:Int = 0;
		while (i < lineBoxes.length)
		{
			var lineBox:LineBox = lineBoxes[i];
			
			if (lineBox.isSpace() == true)
			{
				switch(lineBox.elementRenderer.coreStyle.computedStyle.whiteSpace)
				{
					case WhiteSpace.normal, WhiteSpace.nowrap, WhiteSpace.preLine:
						lineBox.parentNode.removeChild(lineBox);
					default:
						break;
				}
				
			}
			else
			{
				break;
			}
			
			i++;
		}
		
		
		lineBoxes = getLineBoxTreeAsArray(rootLineBox);
		
		if (lineBoxes.length == 0)
		{
			return;
		}
		
		
		var i:Int = lineBoxes.length - 1;
		while (i >= 0)
		{
			var lineBox:LineBox = lineBoxes[i];
			
		
			if (lineBox.isSpace() == true)
			{
				
				switch(lineBox.elementRenderer.coreStyle.computedStyle.whiteSpace)
				{
					case WhiteSpace.normal, WhiteSpace.nowrap, WhiteSpace.preLine:
						lineBox.parentNode.removeChild(lineBox);
						
					default:
						break;
				}
				
			}
			else
			{
				break;
			}
			
			i--;
		}
	}
	
	private function getLineBoxTreeAsArray(rootLineBox:LineBox):Array<LineBox>
	{
		var ret:Array<LineBox> = new Array<LineBox>();
		
		for (i in 0...rootLineBox.childNodes.length)
		{
			var child:LineBox = rootLineBox.childNodes[i];
			
			if (child.hasChildNodes() == true && child.isAbsolutelyPositioned() == false)
			{
				var children:Array<LineBox> = getLineBoxTreeAsArray(child);
			}
			else
			{
				ret.push(child);
			}
		}
		
		return ret;
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
	 * 
	 * TODO : On a block container element whose content is composed of inline-level
	 * elements, 'line-height' specifies the minimal height of line boxes
	 * within the element. The minimum height consists of a minimum
	 * height above the baseline and a minimum depth below it, exactly
	 * as if each line box starts with a zero-width inline box with t
	 * he element's font and line height properties. We call that imaginary box a "strut." (The name is inspired by TeX.). 
	 */
	private function computeLineBoxHeight(rootLineBox:LineBox):Float
	{
		setRootLineBoxMetrics(rootLineBox, rootLineBox, 0.0);
		
		alignLineBoxesVertically(rootLineBox, rootLineBox.leadedAscent, _formattingContextData.y, 0.0);

		//compute the line box height
		var lineBoxHeight:Float = rootLineBox.bounds.height;
		
		return lineBoxHeight;
	}
	
	private function setRootLineBoxMetrics(lineBox:LineBox, rootLineBox:LineBox, parentBaseLineOffset:Float):Void
	{
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			if (child.isAbsolutelyPositioned() == false || child.isText() == true)
			{
				var leadedAscent:Float = child.leadedAscent;
				var leadedDescent:Float = child.leadedDescent;
				var baselineOffset:Float = child.getBaselineOffset(parentBaseLineOffset, _formattingContextRoot.coreStyle.fontMetrics.xHeight);
				
				//TODO : should vertical align be added recursively ?
				if (leadedAscent + baselineOffset > rootLineBox.leadedAscent)
				{
					rootLineBox.leadedAscent = leadedAscent + baselineOffset;
				}
				
				if (leadedDescent + baselineOffset > rootLineBox.leadedDescent)
				{
					rootLineBox.leadedDescent = leadedDescent + baselineOffset;
				}
				
				if (child.hasChildNodes() == true)
				{
					setRootLineBoxMetrics(child, rootLineBox, baselineOffset);
				}
			}
			
		}
	}
	
	private function alignLineBoxesVertically(lineBox:LineBox, lineBoxAscent:Float, formattingContextY:Float, parentBaseLineOffset:Float):Void
	{
		var length:Int = lineBox.childNodes.length;
		for (i in 0...length)
		{
			var child:LineBox = lineBox.childNodes[i];
			
			var baselineOffset:Float = child.getBaselineOffset(parentBaseLineOffset, _formattingContextRoot.coreStyle.fontMetrics.xHeight);
			child.bounds.y = formattingContextY - baselineOffset + lineBoxAscent;
			//TODO 2 check if neccessary to remove ascent to all children
			child.bounds.y -= child.leadedAscent;

			if (child.hasChildNodes() == true)
			{
				alignLineBoxesVertically(child, lineBoxAscent, formattingContextY, baselineOffset);
			}
			
			if (child.establishesNewFormattingContext() == true || (child.elementRenderer.isReplaced() == true && child.elementRenderer.isText() == false))
			{
				//TODO 2 : hack 
				if (child.isAbsolutelyPositioned() == true)
				{
					child.bounds.y += child.leadedAscent;
				}
				
			}
		}
	}
	
}