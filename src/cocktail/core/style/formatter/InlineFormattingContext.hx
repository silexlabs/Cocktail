/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.formatter;

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
 * TODO : re-implement to use parse element in formatting context
 * as a tree, like in block formatting context
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
		_unbreakableLineBoxes = new Array<LineBox>();
		startFormat(staticPositionedElement);
		return;
		
	
		
		super.doFormat(staticPositionedElement);
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
				//create the first line box for this inline box renderer
				var childLineBox:LineBox = createContainerLineBox(child);
				
				//attach the line box to its parent line box
				lineBox.appendChild(childLineBox);

				//store the inline box renderer, each time a new line is created
				//by laying out a child of this inline box renderer, a new line box
				//with a reference to this inline box renderer will be created, so that
				//each line into which this inline box renderer is laid out can be
 				openedElementRenderers.push(child);
				
				//TODO : here add left margin to current unbreakable line
				
				//format all the children of the inline box renderer recursively
				//a reference to the last added line box is returned, so that it can
				//be used as a starting point when laying out the siblings of the 
				//inline box renderer
				lineBox = doFormat2(child, childLineBox, rootLineBoxes, openedElementRenderers);
				
				//now that all of the child of the inline box renderer as been laid out,
				//remove the reference to this inline box renderer so that when a new line
				//is created, no line box pointing to this inline box renderer is created
				openedElementRenderers.pop();
				
				//TODO : here add right margin to current unbreakable line
			}
			//here the child can be either a text renderer, an embedded asset, like a picture
			//or an element displayed as an inline-block
			else
			{
				//get all the line boxes of the element
				var childLineBoxes:Array<LineBox> = child.lineBoxes;
		
				//insert the array of created line boxes into the current line. It might create as many
				//new lines as necessary. Returns a reference to the last inserted line box, used as starting
				//point to lay out subsequent siblings and children
				lineBox = insertIntoLine(childLineBoxes, lineBox, rootLineBoxes, openedElementRenderers);
			}
		}
		
		return lineBox;
	}
	
	//TODO  : attach the created line box to its container ? this way,inline element
	//have array of line box and block box has the tree ? For rendering, LayerRenderer use
	//line box tree or rendering tree ?
	private function createContainerLineBox(child:ElementRenderer):LineBox
	{
		return new LineBox(child);
	}
	
	private function insertIntoLine(lineBoxes:Array<LineBox>, lineBox:LineBox, rootLineBoxes:Array<LineBox>, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		//loop in all the line boxes which must be added to the current line
		for ( i in 0...lineBoxes.length)
		{
			//TODO : here, added width of all element should be computed and also 
			//nb of spaces for horizontal align
			
			
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
				//reset the global formatting context for the next line
				_formattingContextData.x = 0;
				
				//format the current line which is currently the last in the line array
				//, now that all the line box in it are known
				//each of the line box will be placed in x and y on this line
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
	
	private function formatLine(rootLineBox:LineBox, isLastLine:Bool):Void
	{
		//TODO : should be done when computing child in the line
		removeSpaces();
		
		//TODO : compute concatenated length and space numbers
		alignLineBox2(rootLineBox, isLastLine, 100, 5);
		var lineBoxHeight:Int = computeLineBoxHeight();
		
		_formattingContextData.y += lineBoxHeight;
				
		//_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData, elementWidth, _formattingContextRoot.coreStyle.computedStyle.width);
		
		if (_formattingContextData.y  + lineBoxHeight > _formattingContextData.maxHeight)
		{
			_formattingContextData.maxHeight = _formattingContextData.y + lineBoxHeight;
		}
		

		_formattingContextData.x =  _floatsManager.getLeftFloatOffset(_formattingContextData.y);
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
	 */
	private function alignLineBox2(rootLineBox:LineBox, isLastLine:Bool, concatenatedLength:Int, spaceInLine:Int):Void
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
				alignLeft2(flowX, rootLineBox);
				
			case right:
				alignRight2(flowX, remainingSpace, rootLineBox);
				
			case center:
				alignCenter2(flowX, remainingSpace, rootLineBox);
				
			case justify:	
				//the last line of an inline formatting context
				//is not justified to avoid stretching too much
				//the space between HTMLElements if there are few of them
				if (isLastLine == true)
				{
					alignLeft2(flowX, rootLineBox);
				}
				else
				{
					//when justified, the concatenated width of the HTMLElements
					//must take all the containing HTMLElement width
					//TODO : move to the place where concatenated length will be computed
					concatenatedLength = _formattingContextRoot.coreStyle.computedStyle.width;
					
					alignJustify2(flowX, remainingSpace, rootLineBox, spaceInLine);
				}
		}
	}
	
	/**
	 * align the HTMLElements starting from the left edge of the containing HTMLElement
	 * @param	flowX the x position of the first HTMLElement
	 */
	private function alignLeft2(flowX:Int, lineBox:LineBox):Void
	{
		for (i in 0...lineBox.childNodes.length)
		{
			var child:LineBox = cast(lineBox.childNodes[i]);
			child.bounds.x = flowX;
			flowX += Math.round(child.bounds.width);
			
			if (child.hasChildNodes() == true)
			{
				alignLeft2(flowX, child);
			}
		}
	}
	

	/**
	 * Center the HTMLElements in the line by moving each to the right by half the remaining space
	 * @param	flowX the first availbable x position for the HTMLElement to the left most of the line box
	 * @param	remainingSpace the available width in the line box after all HTMLElements
	 * have been laid out
	 */
	private function alignCenter2(flowX:Int, remainingSpace:Int, rootLineBox:LineBox):Void
	{
		//for (i in 0..._elementsInLineBox.length)
		//{
			//_elementsInLineBox[i].bounds.x = Math.round(remainingSpace / 2) + flowX;
			//flowX += Math.round(_elementsInLineBox[i].bounds.width);
		//}
	}
	
	/**
	 * align the HTMLElements starting from the right edge to the left edge of the
	 * containing HTMLElement
	 * @param	flowX the x position of the HTMLElement to left most of the line box
	 * @param	remainingSpace the available width in the line box after all HTMLElements
	 * have been laid out
	 */
	private function alignRight2(flowX:Int, remainingSpace:Int, rootLineBox:LineBox):Void
	{
		//for (i in 0..._elementsInLineBox.length)
		//{
			//_elementsInLineBox[i].bounds.x = flowX + remainingSpace;
			//flowX += Math.round(_elementsInLineBox[i].bounds.width);
		//}
	}
	
	/**
	 * Justify the HTMLElements in the line box by adjusting
	 * the width of the space characters
	 * @param	flowX
	 * @param	remainingSpace
	 */
	private function alignJustify2(flowX:Int, remainingSpace:Int, rootLineBox:LineBox, spaceInLine:Int):Void
	{
		//TODO :add isSpace on TextLineBox
		/**
		//determine how many space there are among the 
		//HTMLElements of the line box
		var spacesNumber:Int = 0;
		for (i in 0..._elementsInLineBox.length)
		{
			if (_elementsInLineBox[i].isSpace() == true)
			{
				spacesNumber++;
			}
		}
		
		//justify all HTMLElements
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
		*/
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
	 * TODO : finish implementation of verticalAlign + duplicated
	 * code
	 */
	private function computeLineBoxHeight():Int
	{
		//init the ascent and descent of the line box
		var lineBoxAscent:Float = 0;
		var lineBoxDescent:Float = 0;
		/**
		//loop in all HTMLElement in the line box to find
		//the highest ascent and descent among them
		//TODO : should be done when computing child in the line
		for (i in 0..._elementsInLineBox.length)
		{
			//TODO : shouldn't need an html element here, only style
			var htmlElement:HTMLElement = _elementsInLineBox[i].coreStyle.htmlElement;
			
			var htmlElementAscent:Int;
			var htmlElementDescent:Int;
			
			//the computed vertical align is the offset of the DOMElemenet relative
			//to the baseline
			var htmlElementVerticalAlign:Float = htmlElement.coreStyle.computedStyle.verticalAlign;
			
			//for embedded or inlineBlock elements, which have no baseline, the height above
			//the baseline is the offset height and they have no descent
			if (_elementsInLineBox[i].isEmbedded() == true && _elementsInLineBox[i].isText() == false ||
			_elementsInLineBox[i].establishesNewFormattingContext() == true)
			{
				htmlElementAscent = htmlElement.coreStyle.computedStyle.height +  htmlElement.coreStyle.computedStyle.paddingTop + htmlElement.coreStyle.computedStyle.paddingBottom
				+ _elementsInLineBox[i].coreStyle.computedStyle.marginTop + _elementsInLineBox[i].coreStyle.computedStyle.marginBottom;
				
				htmlElementDescent = 0;
				
				switch (htmlElement.coreStyle.verticalAlign)
				{
					case top:
						htmlElementAscent = Math.round(lineBoxAscent);
						htmlElementDescent = Math.round(htmlElement.coreStyle.computedStyle.height +  htmlElement.coreStyle.computedStyle.paddingTop + htmlElement.coreStyle.computedStyle.paddingBottom
				 - lineBoxAscent);
						
					default:	
						
				}
			}
			//else retrieve the ascent and descent and apply leading to it
			else
			{
				htmlElementAscent = htmlElement.coreStyle.fontMetrics.ascent;
				htmlElementDescent = htmlElement.coreStyle.fontMetrics.descent;	
			
				//the leading is an extra height to apply equally to the ascent
				//and the descent when laying out lines of text
				var leading:Float = htmlElement.coreStyle.computedStyle.lineHeight - (htmlElementAscent + htmlElementDescent);
		
				//apply leading to the ascent and descent
				htmlElementAscent = Math.round((htmlElementAscent + leading / 2));
				htmlElementDescent = Math.round((htmlElementDescent + leading / 2));
			}
			
			//if the ascent or descent is superior to the current maximum
			//ascent or descent, it becomes the line box ascent/descent
			if (htmlElementAscent - htmlElementVerticalAlign > lineBoxAscent)
			{
				lineBoxAscent = htmlElementAscent - htmlElementVerticalAlign;
			}
			
			if (htmlElementDescent + htmlElementVerticalAlign > lineBoxDescent)
			{
				lineBoxDescent = htmlElementDescent + htmlElementVerticalAlign;
			}
		
		}
		
		//compute the line box height
		var lineBoxHeight:Float = lineBoxAscent + lineBoxDescent;
		
		//for each HTMLElement, place it vertically using the line box ascent and vertical align
		for (i in 0..._elementsInLineBox.length)
		{
			
			var htmlElement:HTMLElement = _elementsInLineBox[i].coreStyle.htmlElement;
			
			var verticalAlign:Float;
			switch (htmlElement.coreStyle.verticalAlign)
			{
				case top:
					verticalAlign = 0;
					
					
				case bottom:
					verticalAlign = 0;
					
				default:
					verticalAlign = htmlElement.coreStyle.computedStyle.verticalAlign;
			}
			
			_elementsInLineBox[i].bounds.y = Math.round(lineBoxAscent) + Math.round(verticalAlign) + _formattingContextData.y;

			
			//if the element is embedded or an inlineBlock, removes its offset height from its vertical position
			//so that its bottom margin touches the baseline
			
			if (_elementsInLineBox[i].isEmbedded() == true && _elementsInLineBox[i].isText() == false ||
			_elementsInLineBox[i].establishesNewFormattingContext() == true)
			{	
				
				switch (htmlElement.coreStyle.verticalAlign)
				{
					case top:
						
						_elementsInLineBox[i].bounds.y = _formattingContextData.y;
					
					default:	
						_elementsInLineBox[i].bounds.y -= htmlElement.coreStyle.computedStyle.height +  htmlElement.coreStyle.computedStyle.paddingTop + htmlElement.coreStyle.computedStyle.paddingBottom
				 + _elementsInLineBox[i].coreStyle.computedStyle.marginTop + _elementsInLineBox[i].coreStyle.computedStyle.marginBottom;
					
				}
				
				
			}
			
			
		}
	*/
		return 0;
		//return Math.round(lineBoxHeight);
	}
	
}