/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.layout.formatter;

using cocktail.core.utils.Utils;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.linebox.EmbeddedLineBox;
import cocktail.core.linebox.LineBox;
import cocktail.core.linebox.RootLineBox;
import cocktail.core.linebox.StaticPositionLineBox;
import cocktail.core.linebox.TextLineBox;
import cocktail.core.linebox.SpaceLineBox;

import cocktail.core.layout.floats.FloatsManager;
import cocktail.core.layout.LayoutData;
import cocktail.core.geom.GeomData;
import cocktail.core.html.HTMLElement;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.font.FontData;
import cocktail.core.renderer.InlineBoxRenderer;
import cocktail.core.css.CSSData;
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
	 * Used to store the current line box
	 * tree as an array
	 */
	private var _lineBoxesAsArray:Array<LineBox>;
	
	/**
	 * During formatting keep track of the inline
	 * element renderer which are formatting their
	 * children and might need to create new line box
	 * if formatted on multiple lines
	 */
	private var _openedElementRenderers:Array<ElementRenderer>;
	
	/**
	 * class constructor.
	 */
	public function new(floatsManager:FloatsManager) 
	{
		super(floatsManager);
		_lineBoxesAsArray = new Array<LineBox>();
		_unbreakableLineBoxes = new Array<LineBox>();
		_openedElementRenderers = new Array<ElementRenderer>();
	}

	override private function startFormatting():Void
	{
		
		_unbreakableLineBoxes = _unbreakableLineBoxes.clear();
		_openedElementRenderers = _openedElementRenderers.clear();
		
		_unbreakableWidth = 0.0;
		_firstLineFormatted = false;
		
		_formattingContextRoot.resetRootLineBoxes();
		
		var initialRootLineBox:RootLineBox = _formattingContextRoot.getRootLineBox();

		_firstLineFormatted = false;
		
		//TODO : should implement text indent in a cleaner way
		_unbreakableWidth = _formattingContextRoot.coreStyle.usedValues.textIndent;
		
		//_formattingContextData.y += _formattingContextRoot.bounds.y;
		_formattingContextData.x = _formattingContextRoot.coreStyle.usedValues.textIndent;
		_formattingContextData.x += _floatsManager.getLeftFloatOffset(_formattingContextRoot.bounds.y);
		
		doFormat(_formattingContextRoot, initialRootLineBox, _openedElementRenderers);

		//format the last line
		formatLine(_formattingContextRoot.getLastRootLineBox(), true);

		var formattingContextCoreStyle:CoreStyle = _formattingContextRoot.coreStyle;
		//apply formatting height to formatting context root if auto height
		if (formattingContextCoreStyle.isAuto(formattingContextCoreStyle.height) == true)
		{
			var formattingContextUsedValues:UsedValuesVO =  _formattingContextRoot.coreStyle.usedValues;
			_formattingContextRoot.bounds.height = _formattingContextData.y  + formattingContextUsedValues.paddingBottom ;
			formattingContextUsedValues.height = _formattingContextData.y - formattingContextUsedValues.paddingTop;
		}
	}
	
	private function doFormat(elementRenderer:ElementRenderer, lineBox:LineBox, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		//loop in all the child of the container
		var child:ElementRenderer = elementRenderer.firstChild;
		while(child != null)
		{
			//here the child is absolutely positioned, its static position must be calculated
			//so that it can be used if the child's left, right, top or bottom attribute are 'auto'.
			//A dummy 'StaticLineBox' is created which will be formatting instead of the child.
			//the static line box itself does'nt influence formatting, its height and width are not
			//added during formatting, it is only used to retrieve the coordinate where the
			//absolutely positioned should be placed
			if (child.isPositioned() == true && child.isRelativePositioned() == false)
			{
				var staticLineBox:LineBox = child.lineBoxes[0];
				child.bounds.x = 0;
				child.bounds.y = 0;
				child.bounds.width = child.coreStyle.usedValues.width+ child.coreStyle.usedValues.paddingLeft + child.coreStyle.usedValues.paddingRight ;
				child.bounds.height = child.coreStyle.usedValues.height + child.coreStyle.usedValues.paddingTop + child.coreStyle.usedValues.paddingBottom;
				staticLineBox.marginLeft = child.coreStyle.usedValues.marginLeft;
				staticLineBox.marginRight = child.coreStyle.usedValues.marginRight;
				
				lineBox = insertIntoLine(staticLineBox, lineBox, openedElementRenderers);
			}
			//here the child either starts a new formatting context, meaning it is displayed
			//has an inline-block and it has children, or it is replaced/embedded, such as
			//an ImageRenderer. For all thoses cases, only one line box is created for each child
			//as it is atomic from the point of view of the inline formatting context
			//(it doesn't know what's inside those child when formatting)
			else if (child.establishesNewFormattingContext() == true || child.isReplaced() == true)
			{
				var childUsedValues:UsedValuesVO = child.coreStyle.usedValues;
				
				//set the bounds of the corresponding InlineBoxRenderer
				var childBounds:RectangleVO = child.bounds;
				child.bounds.x = 0;
				child.bounds.y = 0;
				childBounds.width = childUsedValues.width + childUsedValues.paddingLeft + childUsedValues.paddingRight;
				childBounds.height = childUsedValues.height + childUsedValues.paddingTop + childUsedValues.paddingBottom;
				
				//create the embedded line box representing the InlineBoxRenderer in
				//the inline formatting context
				var embeddedLineBox:LineBox = child.lineBoxes[0];
				
				embeddedLineBox.marginLeft = childUsedValues.marginLeft;
				embeddedLineBox.marginRight = childUsedValues.marginRight;
				
				lineBox = insertIntoLine(embeddedLineBox, lineBox, openedElementRenderers);
			}
			//here the child is an inline box renderer, which will create one line box for each
			//line its children are in
			else if (child.firstChild != null)
			{
				//remove all the previous line boxes before creating new ones
				//if needed
				if (child.lineBoxes.length > 0)
				{
					child.lineBoxes = new Array<LineBox>();
				}
			
				//create the first line box for this inline box renderer
				var childLineBox:LineBox = createContainerLineBox(child);
				
				var childUsedValues:UsedValuesVO = child.coreStyle.usedValues;
				
				//the first line box created by an inline box renderer has a left margin and padding
				childLineBox.marginLeft = childUsedValues.marginLeft;
				childLineBox.paddingLeft = childUsedValues.paddingLeft;
				//the left margin and padding is added to the unbreakable width as the next line box in the line 
				//can't be separated from this margin and padding
				_unbreakableWidth += childUsedValues.marginLeft + childUsedValues.paddingLeft;
				
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
				lineBox = doFormat(child, childLineBox, openedElementRenderers);
				
				//now that all of the child of the inline box renderer as been laid out,
				//remove the reference to this inline box renderer so that when a new line
				//is created, no line box pointing to this inline box renderer is created
				openedElementRenderers.pop();
				
				//The current line box must also be set to the parent line box so that no more
				//line boxes are added to this line box as it is done formatting its child line boxes
				lineBox = lineBox.parentNode;
				
				//The right margin and padding is added to the last generated line box of the current inline
				//box renderer
				var lastLineBox:LineBox = child.lineBoxes[child.lineBoxes.length - 1];
				lastLineBox.marginRight = childUsedValues.marginRight;
				lastLineBox.paddingRight = childUsedValues.paddingRight;
				_unbreakableWidth += childUsedValues.marginRight + childUsedValues.paddingRight;
			}
			//here the child is a TextRenderer, which has as many text line box
			//as needed to reperesent all the content of the TextRenderer
			else
			{
				//insert the array of created line boxes into the current line. It might create as many
				//new lines as necessary. Returns a reference to the last inserted line box, used as starting
				//point to lay out subsequent siblings and children
				var textLength:Int = child.lineBoxes.length;
				for (j in 0...textLength)
				{
					lineBox = insertIntoLine(child.lineBoxes[j], lineBox, openedElementRenderers);
				}
			}
			
			child = child.nextSibling;
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
	 * Insert a line boxe into the current line. If the line boxe
	 * can't fit in the line, create a new line 
	 */
	private function insertIntoLine(childLineBox:LineBox, lineBox:LineBox, openedElementRenderers:Array<ElementRenderer>):LineBox
	{
		//store the line box in the unbreakable line box array, which is
		//a buffer preventing break between elements which are not supposed to
		//be break into several lines, for instance a non-breaking space
		_unbreakableLineBoxes.push(childLineBox);	
		
		//line boxes generated by absolutely positioned elements do not enter
		//into account when calculating line breaks
		if (childLineBox.isStaticPosition() == false)
		{
			//the width of the line box is added to the total width which can't be broken
			_unbreakableWidth += childLineBox.bounds.width + childLineBox.marginLeft + childLineBox.marginRight;
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
			_formattingContextRoot.coreStyle.usedValues.width);
			
			_formattingContextData.y -= _formattingContextRoot.bounds.y;
			
			_formattingContextData.x = _floatsManager.getLeftFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y);
			
			//format the current line which is currently the last in the line array
			//, now that all the line box in it are known
			//each of the line boxes will be placed in x and y on this line
			formatLine(_formattingContextRoot.getLastRootLineBox(), false);
			
			//create a new root for the next line, and add it to the line array
			var rootLineBox:RootLineBox = _formattingContextRoot.getRootLineBox();
			
			//set the line box which will be used to layout the following children
			//as the new root line box
			lineBox = rootLineBox;

			//create new line boxes for all the inline box renderer which still have
			//children to format, and add them to the new line
			var length:Int = openedElementRenderers.length;
			for (j in 0...length)
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
		_unbreakableLineBoxes = _unbreakableLineBoxes.clear();
		_unbreakableWidth = 0;
		
		return lineBox;
	}
	
	/**
	 * Start the formatting of a line, starting from the root line box of
	 * the line
	 * @param	rootLineBox the top of the tree of line box of this line
	 * @param	isLastLine wheter this line is the last one of this
	 * formatting context
	 */
	private function formatLine(rootLineBox:LineBox, isLastLine:Bool):Void
	{
		if (rootLineBox.firstChild != null)
		{
			removeSpaces(rootLineBox);
		}
		
		//format line boxes horizontally
		var lineBoxWidth:Float = alignLineBox(rootLineBox, isLastLine, getConcatenatedWidth(rootLineBox));
		
		if (lineBoxWidth > _formattingContextData.width)
		{
			_formattingContextData.width = lineBoxWidth;
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
	 * 
	 * TODO 2 : should be added in insertIntoLine
	 */
	private function getConcatenatedWidth(lineBox:LineBox):Float
	{
		var concatenatedWidth:Float = 0.0;
		
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
			if (child.isStaticPosition() == false)
			{
				if (child.firstChild != null)
				{
					concatenatedWidth += getConcatenatedWidth(child);
				}
			
				concatenatedWidth += child.bounds.width;
			}
			
			child = child.nextSibling;
		}
		
		return concatenatedWidth;
	}
	
	/**
	 * Compute the number of space character found in the current
	 * line. This is used when the text is justified
	 * 
	 * TODO 2 : should be added in insertIntoLine
	 */
	private function getSpacesNumber(lineBox:LineBox):Int
	{
		var spacesNumber:Int = 0;
		
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				spacesNumber += getSpacesNumber(child);
			}
			
			if (child.isSpace() == true)
			{
				spacesNumber++;
			}
			
			child = child.nextSibling;
		}
		
		return spacesNumber;
		
	}
	
	/**
	 * Return the width remaining in the current line
	 * of the formatting context
	 */
	private function getRemainingLineWidth():Float
	{
		return _formattingContextRoot.coreStyle.usedValues.width - _formattingContextData.x - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y, _formattingContextRoot.coreStyle.usedValues.width);
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
	private function alignLineBox(rootLineBox:LineBox, isLastLine:Bool, concatenatedLength:Float):Float
	{	
		//determine the remaining space in the line once all the width of the HTMLElements
		//are substracted from the total available line width, and the x position where to 
		//insert the first HTMLElement of the line, which might be influenced for instance
		//by a float
		var remainingSpace:Float;
		var flowX:Float;
		
		var formattingContextRootUsedValues:UsedValuesVO = _formattingContextRoot.coreStyle.usedValues;
		
		remainingSpace = formattingContextRootUsedValues.width - concatenatedLength - _floatsManager.getLeftFloatOffset(_formattingContextData.y) - 
		_floatsManager.getRightFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y, formattingContextRootUsedValues.width);
		flowX = formattingContextRootUsedValues.paddingLeft;
		
		if (_firstLineFormatted == false)
		{
			flowX += formattingContextRootUsedValues.textIndent;
			remainingSpace -= formattingContextRootUsedValues.textIndent;
		}
		
		//take the float into accounts and the padding of the containing HTMLElement
		flowX += _floatsManager.getLeftFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y);
		
		//do align the HTMLElements, the text align style of the containing HTMLElement
		//determining the alignement to apply
		switch (_formattingContextRoot.coreStyle.getKeyword(_formattingContextRoot.coreStyle.textAlign))
		{
			case LEFT:
				alignLeft(flowX, rootLineBox);
				
			case RIGHT:
				alignRight(flowX, remainingSpace, rootLineBox);
				
			case CENTER:
				alignCenter(flowX, remainingSpace, rootLineBox);
				
			case JUSTIFY:	
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
					concatenatedLength = formattingContextRootUsedValues.width;
					alignJustify(flowX, remainingSpace, rootLineBox, getSpacesNumber(rootLineBox));
				}
				
			default:
				throw 'Illegal value for text-align style';
		}
		
		return concatenatedLength;
	}
	
	/**
	 * align the HTMLElements starting from the left edge of the containing HTMLElement
	 * 
	 * @param	flowX the x position of the first HTMLElement
	 */
	private function alignLeft(flowX:Float, lineBox:LineBox):Float
	{
		flowX += lineBox.paddingLeft + lineBox.marginLeft;
		
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null && child.isStaticPosition() == false)
			{
				flowX = alignLeft(flowX, child);
			}
			else
			{
				child.bounds.x = flowX + child.marginLeft;
				
				if (child.isStaticPosition() == false)
				{
					flowX += child.bounds.width + child.marginLeft + child.marginRight;
				}
			
			}
			
			child = child.nextSibling;
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
		
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				flowX =  alignCenter(flowX, remainingSpace, child);
			}
			
			child.bounds.x = (remainingSpace / 2) + flowX;
			flowX += child.bounds.width;
			
			child = child.nextSibling;
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
		
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				flowX = alignRight(flowX, remainingSpace, child);
			}
			
			child.bounds.x = flowX + remainingSpace;
			flowX += child.bounds.width;
			
			child = child.nextSibling;
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
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
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
			
			if (child.firstChild != null)
			{
				alignJustify(flowX, remainingSpace, child, spacesInLine);
			}
			
			child = child.nextSibling;
		}
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
		_lineBoxesAsArray = _lineBoxesAsArray.clear();
		getLineBoxTreeAsArray(rootLineBox, _lineBoxesAsArray);
		
		if (_lineBoxesAsArray.length == 0)
		{
			return;
		}
		
		var i:Int = 0;
		var length:Int = _lineBoxesAsArray.length;
		
		while (i < length)
		{
			var lineBox:LineBox = _lineBoxesAsArray[i];
			
			if (lineBox.isSpace() == true)
			{
				var coreStyle:CoreStyle = lineBox.elementRenderer.coreStyle;
				switch(coreStyle.getKeyword(coreStyle.whiteSpace))
				{
					case NORMAL, NO_WRAP, PRE_LINE:
						lineBox.parentNode.removeChild(lineBox);
						
					default:
						break;
				}
				
			}
			else
			{
				//absolute line box do not influence this
				if (lineBox.isStaticPosition() == false)
				{
					if (lineBox.isEmbedded() == true)
					{
						break;
					}
					else
					{
						//if child only contains spaces, don't break the
						//line
						var child:LineBox = lineBox.firstChild;
						while (child != null)
						{
							if (child.isSpace() == false)
							{
								break;
							}
							child = child.nextSibling;
						}
					}
				}
				
				
			}
			
			i++;
		}
		_lineBoxesAsArray = _lineBoxesAsArray.clear();
		getLineBoxTreeAsArray(rootLineBox, _lineBoxesAsArray);
		
		if (_lineBoxesAsArray.length == 0)
		{
			return;
		}
		
		
		var i:Int = _lineBoxesAsArray.length - 1;
		while (i >= 0)
		{
			var lineBox:LineBox = _lineBoxesAsArray[i];
		
			if (lineBox.isSpace() == true)
			{
				var coreStyle:CoreStyle = lineBox.elementRenderer.coreStyle;
				switch(coreStyle.getKeyword(coreStyle.whiteSpace))
				{
					case NORMAL, NO_WRAP, PRE_LINE:
						lineBox.parentNode.removeChild(lineBox);
						
					default:
						break;
				}
				
			}
			else
			{
				if (lineBox.isStaticPosition() == false)
				{
					break;
				}
			}
			
			i--;
		}
	}
	
	private function getLineBoxTreeAsArray(rootLineBox:LineBox, lineBoxes:Array<LineBox>):Void
	{
		var child:LineBox = rootLineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null && child.isStaticPosition() == false)
			{
				getLineBoxTreeAsArray(child, lineBoxes);
			}
			else
			{
				lineBoxes.push(child);
			}
			
			child = child.nextSibling;
		}
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
		var formattingContextFontMetrics:FontMetricsVO = _formattingContextRoot.coreStyle.fontMetrics;
		setRootLineBoxMetrics(rootLineBox, rootLineBox, 0.0, formattingContextFontMetrics);
		
		alignLineBoxesVertically(rootLineBox, rootLineBox.leadedAscent, _formattingContextData.y, 0.0, formattingContextFontMetrics);

		//compute the line box height
		var lineBoxHeight:Float = rootLineBox.bounds.height;
		
		return lineBoxHeight;
	}
	
	private function setRootLineBoxMetrics(lineBox:LineBox, rootLineBox:LineBox, parentBaseLineOffset:Float, formattingContextFontMetrics:FontMetricsVO):Void
	{
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
			if (child.isStaticPosition() == false)
			{
				var leadedAscent:Float = child.leadedAscent;
				var leadedDescent:Float = child.leadedDescent;
				var baselineOffset:Float = child.getBaselineOffset(parentBaseLineOffset, formattingContextFontMetrics.xHeight);
				//TODO : should vertical align be added recursively ?
				if (leadedAscent + baselineOffset > rootLineBox.leadedAscent)
				{
					rootLineBox.leadedAscent = leadedAscent + baselineOffset;
				}
				
				if (leadedDescent + baselineOffset > rootLineBox.leadedDescent)
				{
					rootLineBox.leadedDescent = leadedDescent + baselineOffset;
				}
				
				if (child.firstChild != null)
				{
					setRootLineBoxMetrics(child, rootLineBox, baselineOffset, formattingContextFontMetrics);
				}
			}
			
			child = child.nextSibling;
			
		}
	}
	
	/**
	 * Align all the line boxes in one line vertically
	 */
	private function alignLineBoxesVertically(lineBox:LineBox, lineBoxAscent:Float, formattingContextY:Float, parentBaseLineOffset:Float, formattingContextFontMetrics:FontMetricsVO):Void
	{
		var child:LineBox = lineBox.firstChild;
		while(child != null)
		{
			var baselineOffset:Float = child.getBaselineOffset(parentBaseLineOffset, formattingContextFontMetrics.xHeight);
			
			var childCoreStyle:CoreStyle = child.elementRenderer.coreStyle;
			switch(childCoreStyle.getKeyword(childCoreStyle.verticalAlign))
			{
				case TOP:
					child.bounds.y = formattingContextY;
					
				default:	
					
					child.bounds.y = formattingContextY - baselineOffset ;
					
					//TODO 2 : actually should apply to all but linebox
					//
					//for all child line box but container line box, 
					//add the global ascent of the line and remove own ascent
					if (child.firstChild != null)
					{
						child.bounds.y += lineBoxAscent;
						child.bounds.y -= child.leadedAscent;
					}
					
					
			}
			
			if (child.firstChild != null)
			{
				alignLineBoxesVertically(child, lineBoxAscent, formattingContextY, baselineOffset, formattingContextFontMetrics);
			}
			//line box which wrap replaced element or establishes new formatting context apply their
			//top margin to their bounds here
			else if (child.isStaticPosition() == true || child.elementRenderer.isReplaced() == true || child.elementRenderer.establishesNewFormattingContext() == true)
			{
				child.bounds.y += child.elementRenderer.coreStyle.usedValues.marginTop;
			}
			
			child = child.nextSibling;
		}
	}
	
}