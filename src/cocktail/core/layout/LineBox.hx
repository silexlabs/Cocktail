package cocktail.core.layout;
import cocktail.core.linebox.InlineBox;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.font.FontData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class LineBox 
{
	private var _unbreakableLineBoxes:Array<InlineBox>;
	
	private var _unbreakableWidth:Float;
	
	public var rootLineBox:InlineBox;
	
	private var _x:Float;

	public function new(elementRenderer:ElementRenderer, availableWidth:Float, minimumHeight:Float, isFirstLine:Bool) 
	{
		
	}
	//
	//private function insertIntoLine(inlineBox:InlineBox, parentInlineBox:InlineBox):Bool
	//{
		//_unbreakableLineBoxes.push(inlineBox);	
		//
		//_unbreakableWidth += childLineBox.bounds.width + childLineBox.marginLeft + childLineBox.marginRight;
	//
			//
		//get the remaining available space on the current line
		//var remainingLineWidth:Float = getRemainingLineWidth();
//
		//if there isn't enough space to fit all the line box which can't be broken
		//TODO 1 : should apply white space processing model for line break here
		//if (remainingLineWidth - _unbreakableWidth < 0)
		//{
			//TODO : should be padding left instead ?
			//
			//_formattingContextData.y = _floatsManager.getFirstAvailableY(_formattingContextData.y + _formattingContextRoot.bounds.y, _unbreakableWidth,
			//_formattingContextRoot.coreStyle.usedValues.width);
			//
			//_formattingContextData.y -= _formattingContextRoot.bounds.y;
			//
			//_formattingContextData.x = _floatsManager.getLeftFloatOffset(_formattingContextData.y + _formattingContextRoot.bounds.y);
			//
			//format the current line which is currently the last in the line array
			//, now that all the line box in it are known
			//each of the line boxes will be placed in x and y on this line
			//formatLine(_formattingContextRoot.getLastRootLineBox(), false);
			//
			//create a new root for the next line, and add it to the line array
			//var rootLineBox:RootLineBox = _formattingContextRoot.getRootLineBox();
			//
			//set the line box which will be used to layout the following children
			//as the new root line box
			//lineBox = rootLineBox;
//
			//create new line boxes for all the inline box renderer which still have
			//children to format, and add them to the new line
			//var length:Int = openedElementRenderers.length;
			//for (j in 0...length)
			//{
				//all line boxes are attached as child of the previous created line box
				//and not as sibling to respect the hierarchy of the previous line
				//var childLineBox:LineBox = createContainerLineBox(openedElementRenderers[j]);
				//lineBox.appendChild(childLineBox);
				//lineBox = childLineBox;
			//}
		//}
		//
		//now that a break opportunity can occur in the line, 
		//push all the elements in the unbreakable line box
		//in the current line
		//var unbreakableLength:Int = _unbreakableLineBoxes.length;
		//for (j in 0...unbreakableLength)
		//{
			//lineBox.appendChild(_unbreakableLineBoxes[j]);
		//}
		//
		//update position on current line where the next line boxes will be added
		//_formattingContextData.x += _unbreakableWidth;
		//
		//reset unbreakable line box now that they were added to the line
		//_unbreakableLineBoxes = _unbreakableLineBoxes.clear();
		//_unbreakableWidth = 0;
		//
		//return lineBox;
	//}
	//
	///**
	 //* Start the formatting of a line, starting from the root line box of
	 //* the line
	 //* @param	rootLineBox the top of the tree of line box of this line
	 //* @param	isLastLine wheter this line is the last one of this
	 //* formatting context
	 //*/
	//public function layout(isLastLine:Bool):Void
	//{
		//if (rootLineBox.firstChild != null)
		//{
			//removeSpaces();
		//}
		//
		//format line boxes horizontally
		//var lineBoxWidth:Float = alignLineBox(rootLineBox, isLastLine, getConcatenatedWidth(rootLineBox));
		//
		//format line boxes vertically
		//var lineBoxHeight:Float = computeLineBoxHeight(rootLineBox);
		//
	//}
	//
	///**
	 //* Compute the added width of all the line box in the line
	 //* 
	 //* TODO 2 : should be added in insertIntoLine
	 //*/
	//private function getConcatenatedWidth(lineBox:LineBox):Float
	//{
		//var concatenatedWidth:Float = 0.0;
		//
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//if (child.isStaticPosition() == false)
			//{
				//if (child.firstChild != null)
				//{
					//concatenatedWidth += getConcatenatedWidth(child);
				//}
			//
				//concatenatedWidth += child.bounds.width;
			//}
			//
			//child = child.nextSibling;
		//}
		//
		//return concatenatedWidth;
	//}
	//
	///**
	 //* Compute the number of space character found in the current
	 //* line. This is used when the text is justified
	 //* 
	 //* TODO 2 : should be added in insertIntoLine
	 //*/
	//private function getSpacesNumber(lineBox:LineBox):Int
	//{
		//var spacesNumber:Int = 0;
		//
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//if (child.firstChild != null)
			//{
				//spacesNumber += getSpacesNumber(child);
			//}
			//
			//if (child.isSpace() == true)
			//{
				//spacesNumber++;
			//}
			//
			//child = child.nextSibling;
		//}
		//
		//return spacesNumber;
		//
	//}
	//
	///**
	 //* Return the width remaining in the current line
	 //* of the formatting context
	 //*/
	//private function getRemainingLineWidth():Float
	//{
		//return _availableWidth - _x;
	//}
	//
	///**
	 //* before a new line starts or before the inline
	 //* formarring context get destroyed, align all the
	 //* HTMLElements in the current line horizontally
	 //* @param	isLastLine wheter it is the last line which is laid out
	 //* @return returns the concantenated width of all the aligned DOMElelements.
	 //* Used to determine the max line width used for shrink-to-fit algorithm
	 //* 
	 //* TODO : update doc
	 //*/
	//private function alignLineBox(rootLineBox:LineBox, isLastLine:Bool, concatenatedLength:Float):Float
	//{	
		//var remainingSpace:Float =  _availableWidth - concatenatedLength;
		//var flowX:Float = 0;
		//
		//remainingSpace = _availableWidth - concatenatedLength;
		//
		//if (_isFirstLine == true)
		//{
			//flowX += _elementRenderer.coreStyle.usedValues.textIndent;
			//remainingSpace -= _elementRenderer.coreStyle.usedValues.textIndent;
		//}
		//
		//switch (_elementRenderer.coreStyle.getKeyword(_elementRenderer.coreStyle.textAlign))
		//{
			//case LEFT:
				//alignLeft(flowX, rootLineBox);
				//
			//case RIGHT:
				//alignRight(flowX, remainingSpace, rootLineBox);
				//
			//case CENTER:
				//alignCenter(flowX, remainingSpace, rootLineBox);
				//
			//case JUSTIFY:	
				//the last line of an inline formatting context
				//is not justified to avoid stretching too much
				//the space between HTMLElements if there are few of them
				//if (isLastLine == true)
				//{
					//alignLeft(flowX, rootLineBox);
				//}
				//else
				//{
					//when justified, the concatenated width of the HTMLElements
					//must take all the containing HTMLElement width
					//concatenatedLength = _availableWidth;
					//alignJustify(flowX, remainingSpace, rootLineBox, getSpacesNumber(rootLineBox));
				//}
				//
			//default:
				//throw 'Illegal value for text-align style';
		//}
		//
		//return concatenatedLength;
	//}
	//
	///**
	 //* align the HTMLElements starting from the left edge of the containing HTMLElement
	 //* 
	 //* @param	flowX the x position of the first HTMLElement
	 //*/
	//private function alignLeft(flowX:Float, lineBox:LineBox):Float
	//{
		//flowX += lineBox.paddingLeft + lineBox.marginLeft;
		//
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//if (child.firstChild != null)
			//{
				//flowX = alignLeft(flowX, child);
			//}
			//else
			//{
				//child.bounds.x = flowX + child.marginLeft;
				//flowX += child.bounds.width + child.marginLeft + child.marginRight;
			//}
			//
			//child = child.nextSibling;
		//}
		//
		//flowX += lineBox.paddingRight + lineBox.marginRight;
		//
		//return flowX;
	//}
	//
//
	///**
	 //* Center the HTMLElements in the line by moving each to the right by half the remaining space
	 //* 
	 //* TODO 4 : flowX, remainingSpace should be passed by reference, not value
	 //* 
	 //* 
	 //* @param	flowX the first availbable x position for the HTMLElement to the left most of the line box
	 //* @param	remainingSpace the available width in the line box after all HTMLElements
	 //* have been laid out
	 //*/
	//private function alignCenter(flowX:Float, remainingSpace:Float, lineBox:LineBox):Float
	//{
		//flowX += lineBox.marginLeft + lineBox.paddingLeft;
		//
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//if (child.firstChild != null)
			//{
				//flowX =  alignCenter(flowX, remainingSpace, child);
			//}
			//
			//child.bounds.x = (remainingSpace / 2) + flowX;
			//flowX += child.bounds.width;
			//
			//child = child.nextSibling;
		//}
		//
		//flowX += lineBox.marginRight + lineBox.paddingRight;
		//
		//return flowX;
	//}
	//
	///**
	 //* align the HTMLElements starting from the right edge to the left edge of the
	 //* containing HTMLElement
	 //* 
	 //* TODO 4 : flowX, remainingSpace should be passed by reference, not value
	 //* 
	 //* @param	flowX the x position of the HTMLElement to left most of the line box
	 //* @param	remainingSpace the available width in the line box after all HTMLElements
	 //* have been laid out
	 //*/
	//private function alignRight(flowX:Float, remainingSpace:Float, lineBox:LineBox):Float
	//{
		//flowX += lineBox.marginLeft + lineBox.paddingLeft;
		//
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//if (child.firstChild != null)
			//{
				//flowX = alignRight(flowX, remainingSpace, child);
			//}
			//
			//child.bounds.x = flowX + remainingSpace;
			//flowX += child.bounds.width;
			//
			//child = child.nextSibling;
		//}
		//
		//flowX += lineBox.marginRight + lineBox.paddingRight;
		//
		//return flowX;
	//}
	//
	///**
	 //* Justify the HTMLElements in the line box by adjusting
	 //* the width of the space characters
	 //* 
	 //* TODO 4 : flowX, remainingSpace and spacesInLine should be passed by reference, not value
	 //* 
	 //* @param	flowX
	 //* @param	remainingSpace
	 //*/
	//private function alignJustify(flowX:Float, remainingSpace:Float, lineBox:LineBox, spacesInLine:Int):Void
	//{
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//if (child.isSpace() == true)
			//{
				//var spaceWidth:Float = (remainingSpace / spacesInLine);
				//TODO : should return nb of spaces as this is passed by value ?
				//spacesInLine--;
				//remainingSpace -= spaceWidth;
				//flowX += spaceWidth;
			//}
			//
			//child.bounds.x =  flowX;
			//flowX += child.bounds.width;
			//
			//if (child.firstChild != null)
			//{
				//alignJustify(flowX, remainingSpace, child, spacesInLine);
			//}
			//
			//child = child.nextSibling;
		//}
	//}
	//
	//
	// LINE LAYOUT METHODS
	// Those methods are used to determine the x and y position
	// of each element in the line
//////////////////////////////////////////////////////////////////
//
	//
	/////////////////////////////////
	// PRIVATE METHODS
	/////////////////////////////////
	//
//
	//
	//TODO 2 : add doc, remove start and end spaces in a line
	//private function removeSpaces(rootLineBox:LineBox):Void
	//{
		//_lineBoxesAsArray = _lineBoxesAsArray.clear();
		//getLineBoxTreeAsArray(rootLineBox, _lineBoxesAsArray);
		//
		//if (_lineBoxesAsArray.length == 0)
		//{
			//return;
		//}
		//
		//var i:Int = 0;
		//var length:Int = _lineBoxesAsArray.length;
		//
		//while (i < length)
		//{
			//var lineBox:LineBox = _lineBoxesAsArray[i];
			//
			//if (lineBox.isSpace() == true)
			//{
				//var coreStyle:CoreStyle = lineBox.elementRenderer.coreStyle;
				//switch(coreStyle.getKeyword(coreStyle.whiteSpace))
				//{
					//case NORMAL, NO_WRAP, PRE_LINE:
						//lineBox.parentNode.removeChild(lineBox);
						//
					//default:
						//break;
				//}
				//
			//}
			//else
			//{
				//absolute line box do not influence this
				//if (lineBox.isStaticPosition() == false)
				//{
					//if (lineBox.isEmbedded() == true)
					//{
						//break;
					//}
					//else
					//{
						//if child only contains spaces, don't break the
						//line
						//var child:LineBox = lineBox.firstChild;
						//while (child != null)
						//{
							//if (child.isSpace() == false)
							//{
								//break;
							//}
							//child = child.nextSibling;
						//}
					//}
				//}
				//
				//
			//}
			//
			//i++;
		//}
		//_lineBoxesAsArray = _lineBoxesAsArray.clear();
		//getLineBoxTreeAsArray(rootLineBox, _lineBoxesAsArray);
		//
		//if (_lineBoxesAsArray.length == 0)
		//{
			//return;
		//}
		//
		//
		//var i:Int = _lineBoxesAsArray.length - 1;
		//while (i >= 0)
		//{
			//var lineBox:LineBox = _lineBoxesAsArray[i];
		//
			//if (lineBox.isSpace() == true)
			//{
				//var coreStyle:CoreStyle = lineBox.elementRenderer.coreStyle;
				//switch(coreStyle.getKeyword(coreStyle.whiteSpace))
				//{
					//case NORMAL, NO_WRAP, PRE_LINE:
						//lineBox.parentNode.removeChild(lineBox);
						//
					//default:
						//break;
				//}
				//
			//}
			//else
			//{
				//if (lineBox.isStaticPosition() == false)
				//{
					//break;
				//}
			//}
			//
			//i--;
		//}
	//}
	//
	//private function getLineBoxTreeAsArray(rootLineBox:LineBox, lineBoxes:Array<LineBox>):Void
	//{
		//var child:LineBox = rootLineBox.firstChild;
		//while(child != null)
		//{
			//if (child.firstChild != null && child.isStaticPosition() == false)
			//{
				//getLineBoxTreeAsArray(child, lineBoxes);
			//}
			//else
			//{
				//lineBoxes.push(child);
			//}
			//
			//child = child.nextSibling;
		//}
	//}
	//
	/////////////////////////////////
	// PRIVATE VERTICAL ALIGNEMENT METHODS
	/////////////////////////////////
	//
	///**
	 //* When a line box is full and a new line will
	 //* be created, compute the height of the current line
	 //* box and place its HTMLElement vertically.
	 //* 
	 //* A line box height corresponds to the addition 
	 //* of the highest ascent and descent of its
	 //* HTMLElement above the baseline
	 //* 
	 //* TODO : finish implementation of verticalAlign
	 //* 
	 //* TODO : update doc
	 //* 
	 //* TODO : On a block container element whose content is composed of inline-level
	 //* elements, 'line-height' specifies the minimal height of line boxes
	 //* within the element. The minimum height consists of a minimum
	 //* height above the baseline and a minimum depth below it, exactly
	 //* as if each line box starts with a zero-width inline box with t
	 //* he element's font and line height properties. We call that imaginary box a "strut." (The name is inspired by TeX.). 
	 //*/
	//private function computeLineBoxHeight(rootLineBox:LineBox):Float
	//{
		//var formattingContextFontMetrics:FontMetricsVO = _formattingContextRoot.coreStyle.fontMetrics;
		//setRootLineBoxMetrics(rootLineBox, rootLineBox, 0.0, formattingContextFontMetrics);
		//
		//alignLineBoxesVertically(rootLineBox, rootLineBox.leadedAscent, _formattingContextData.y, 0.0, formattingContextFontMetrics);
//
		//compute the line box height
		//var lineBoxHeight:Float = rootLineBox.bounds.height;
		//
		//return lineBoxHeight;
	//}
	//
	//private function setRootLineBoxMetrics(lineBox:LineBox, rootLineBox:LineBox, parentBaseLineOffset:Float, formattingContextFontMetrics:FontMetricsVO):Void
	//{
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//var leadedAscent:Float = child.leadedAscent;
			//var leadedDescent:Float = child.leadedDescent;
			//var baselineOffset:Float = child.getBaselineOffset(parentBaseLineOffset, formattingContextFontMetrics.xHeight);
			//TODO : should vertical align be added recursively ?
			//if (leadedAscent + baselineOffset > rootLineBox.leadedAscent)
			//{
				//rootLineBox.leadedAscent = leadedAscent + baselineOffset;
			//}
			//
			//if (leadedDescent + baselineOffset > rootLineBox.leadedDescent)
			//{
				//rootLineBox.leadedDescent = leadedDescent + baselineOffset;
			//}
			//
			//if (child.firstChild != null)
			//{
				//setRootLineBoxMetrics(child, rootLineBox, baselineOffset, formattingContextFontMetrics);
			//}
			//
			//child = child.nextSibling;
			//
		//}
	//}
	//
	///**
	 //* Align all the line boxes in one line vertically
	 //*/
	//private function alignLineBoxesVertically(lineBox:LineBox, lineBoxAscent:Float, formattingContextY:Float, parentBaseLineOffset:Float, formattingContextFontMetrics:FontMetricsVO):Void
	//{
		//var child:LineBox = lineBox.firstChild;
		//while(child != null)
		//{
			//var baselineOffset:Float = child.getBaselineOffset(parentBaseLineOffset, formattingContextFontMetrics.xHeight);
			//
			//var childCoreStyle:CoreStyle = child.elementRenderer.coreStyle;
			//switch(childCoreStyle.getKeyword(childCoreStyle.verticalAlign))
			//{
				//case TOP:
					//child.bounds.y = formattingContextY;
					//
				//default:	
					//
					//child.bounds.y = formattingContextY - baselineOffset ;
					//
					//TODO 2 : actually should apply to all but linebox
					//
					//for all child line box but container line box, 
					//add the global ascent of the line and remove own ascent
					//if (child.firstChild != null)
					//{
						//child.bounds.y += lineBoxAscent;
						//child.bounds.y -= child.leadedAscent;
					//}
					//
					//
			//}
			//
			//if (child.firstChild != null)
			//{
				//alignLineBoxesVertically(child, lineBoxAscent, formattingContextY, baselineOffset, formattingContextFontMetrics);
			//}
			//line box which wrap replaced element or establishes new formatting context apply their
			//top margin to their bounds here
			//else if (child.isStaticPosition() == true || child.elementRenderer.isReplaced() == true || child.elementRenderer.establishesNewBlockFormattingContext() == true)
			//{
				//child.bounds.y += child.elementRenderer.coreStyle.usedValues.marginTop;
			//}
			//
			//child = child.nextSibling;
		//}
	//}
	//
}