package cocktail.core.linebox;
import cocktail.core.css.CoreStyle;
import cocktail.core.geom.GeomUtils;
import cocktail.core.linebox.InlineBox;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.font.FontData;
import cocktail.core.geom.GeomData;
using cocktail.core.utils.Utils;
import cocktail.core.css.CSSData;
import cocktail.core.layout.LayoutData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class LineBox 
{
	private var _unbreakableInlineBoxes:Array<InlineBox>;
	
	public var unbreakableWidth(default, null):Float;
	
	public var rootInlineBox:InlineBox;
	
	private var _addedWidth:Float;
	
	private var _availableWidth:Float;
	
	public var bounds:RectangleVO;
	
	private var _isFirstLine:Bool;

	private var _elementRenderer:ElementRenderer;
	
	private var _spacesNumber:Int;
	
	private var _firstInlineBoxInserted:Bool;
	
	private var _layoutState:LayoutStateValue;
	
	/**
	 * Store the current width of all the
	 * spaces that would be removed if
	 * the white space processing was
	 * applied
	 */
	private var _trailingSpaceWidth:Float;
	
	public function new(elementRenderer:ElementRenderer, availableWidth:Float, isFirstLine:Bool, layoutState:LayoutStateValue) 
	{
		_availableWidth = availableWidth;
		_isFirstLine = isFirstLine;
		_elementRenderer = elementRenderer;
		_spacesNumber = 0;
		unbreakableWidth = 0;
		_addedWidth = 0;
		_firstInlineBoxInserted = false;
		_unbreakableInlineBoxes = new Array<InlineBox>();
		_layoutState = layoutState;
		_trailingSpaceWidth = 0;
		
		rootInlineBox = new InlineBox(elementRenderer);
		bounds = new RectangleVO();
	}
	
	public function addUnbreakableWidth(width:Float):Void
	{
		unbreakableWidth += width;
	}
	
	/**
	 * Utils method returning wether there is enough
	 * horizontal space on the line to insert an element
	 * with the given width. 
	 * 
	 * It doesn't take white space into account, just remaining
	 * space on the line
	 */
	public function widthCanFit(width:Float):Bool
	{
		//remove the width of all the spaces that would be removed
		//if the line was layout now
		_trailingSpaceWidth = 0;
		getTrailingSpacesWidth(rootInlineBox);
		
		if (_addedWidth + width - _trailingSpaceWidth <= _availableWidth)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	public function insert(inlineBox:InlineBox, parentInlineBox:InlineBox, force:Bool):Bool
	{
		//spaces at the beginning of the line are removed if they
		//have the right white space
		if (_firstInlineBoxInserted == false)
		{
			if (inlineBox.isSpace() == true)
			{
				switch(inlineBox.elementRenderer.coreStyle.getKeyword(inlineBox.elementRenderer.coreStyle.whiteSpace))
				{
					case NORMAL, NO_WRAP, PRE_WRAP:
						return false;
						
					default:	
				}
			}
			
			_firstInlineBoxInserted = true;
		}
		
		//increment spaces number which is needed
		//for text justification algorithm
		if (inlineBox.isSpace() == true)
		{
			_spacesNumber++;
		}
		
		//add the new inline box to the unbreakable inline box buffer,
		//it will be added to the line if there is enough space or if
		//its white space prevents the line from breaking
		_unbreakableInlineBoxes.push(inlineBox);	
	
		var inlineBoxWidth:Float = inlineBox.bounds.width + inlineBox.marginLeft + inlineBox.marginRight;
		unbreakableWidth += inlineBoxWidth;
		
		//get the remaining available space on the current line
		var remainingLineWidth:Float = _availableWidth - _addedWidth;

		//line box always break if the inline box represents a line feed
		if (inlineBox.isLineFeed() == true)
		{
			return true;
		}
		//if there isn't enough space to fit all the inline box which can't be broken
		else if (remainingLineWidth - unbreakableWidth < 0)
		{
			//if the new inline box introduce a break opportunity, break the line,
			//unless the new inline box is forced to belong to this inline box, for instance
			//if it already couldn't fit in the previous line box
			if (introduceBreakOpportunity(inlineBox) == true && force == false)
			{
				return true;
			}
			//else add all the unbreakable inline boxes to the line box
			else
			{
				_addedWidth += unbreakableWidth;
				addUnbreakableInlineBoxesToLineBox(parentInlineBox);
			}
		}
		//if there is still enough space and the inline box
		//introduce a break opportunity or is forced to belong to
		//this line box, add all the unbreakable
		//inline boxes to the this line box
		else if (introduceBreakOpportunity(inlineBox) == true || force == true)
		{
			_addedWidth += unbreakableWidth;
			addUnbreakableInlineBoxesToLineBox(parentInlineBox);
		}
		
		//if a shrink to fit preferred minimum width is computed, then a break
		//must happen between each inline box
		if (_layoutState == LayoutStateValue.SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH)
		{
			return true;
		}

		return false;
	}
	
	/**
	 * Attach all current unbreakable inline boxes to the
	 * line box, for instance when a breaking opportunity
	 * happens
	 */
	private function addUnbreakableInlineBoxesToLineBox(parentInlineBox:InlineBox):Void
	{
		var unbreakableLength:Int = _unbreakableInlineBoxes.length;
		for (i in 0...unbreakableLength)
		{
			_unbreakableInlineBoxes[i].lineBox = this;
			parentInlineBox.appendChild(_unbreakableInlineBoxes[i]);
		}
		
		//reset unbreakable inline box now that they were added to the line
		_unbreakableInlineBoxes = _unbreakableInlineBoxes.clear();
		unbreakableWidth = 0;
	}
	
	/**
	 * Return wether the inlineBox introduce a break opportunity
	 */
	private function introduceBreakOpportunity(inlineBox:InlineBox):Bool
	{
		//TODO : if inline box is line feed, should always return true
		
		//if a shrink-to-fit preferred width is being computed, only
		//break at line feed
		if (_layoutState == LayoutStateValue.SHRINK_TO_FIT_PREFERED_WIDTH)
		{
			return false;
		}
		
		//pre and no-wrap white space value prevent line breaks
		switch(inlineBox.elementRenderer.coreStyle.getKeyword(inlineBox.elementRenderer.coreStyle.whiteSpace))
		{
			case PRE, NO_WRAP:
				return false;
				
			default:	
		}
		
		return true;
	}
	
	/**
	 * Layout the line box, which consist in placing all its inline box
	 * x/y position relative to the top left of the line box
	 * 
	 * @param	isLastLine
	 * @param	parentInlineBox
	 */
	public function layout(isLastLine:Bool, parentInlineBox:InlineBox):Void
	{
		//TODO : messy
		//called to insert remaining child for last line, should be separate method ?
		if (isLastLine == true)
		{
			_addedWidth += unbreakableWidth;
				
			//now that a break opportunity can occur in the line, 
			//push all the elements in the unbreakable line box
			//in the current line
			var unbreakableLength:Int = _unbreakableInlineBoxes.length;
			for (i in 0...unbreakableLength)
			{
				_unbreakableInlineBoxes[i].lineBox = this;
				parentInlineBox.appendChild(_unbreakableInlineBoxes[i]);
			}
		}
		
		//remove all spaces at the end of the line box tree if needed
		removeTrailingSpaces(rootInlineBox);
		
		//align all the inline box in the x-axis and return the total horizontal space
		//taken by the aligned inline boxes
		bounds.width = alignInlineBoxesHorizontally(rootInlineBox, isLastLine, _addedWidth);
		
		//update the width and height bounds of the non-replaced inline
		//boxes of the line box
		updateInlineBoxesBounds(rootInlineBox);
		
		//align the inline boxes vertically and return the total height taken 
		//by the aligned inline boxes
		bounds.height = alignInlineBoxesVertically();
		
		//an empty line box has a 0 height
		if (isEmptyLineBox() == true)
		{
			bounds.height = 0;
		}
	}
	
	/**
	 * Remove all the spaces at the end of the line if
	 * those space have a white space value of normal, nowrap
	 * or preline.
	 * @return wether space can be further removed or a non-space
	 * or a space with another white space value was found
	 */
	private function removeTrailingSpaces(inlineBox:InlineBox):Bool
	{
		//start with the end of the line box tree
		var child:InlineBox = inlineBox.lastChild;
		while (child != null)
		{
			//first call recursively to remove spaces at the end
			//of line box tree
			if (child.isEmbedded() == false)
			{
				if (child.firstChild != null)
				{
					var canRemoveSpacesFurther:Bool = removeTrailingSpaces(child);
					//if false, a non-space or with a wrong white space was found
					//and there is non need to remove other spaces
					if (canRemoveSpacesFurther == false)
					{
						return false;
					}
				}
			}
			
			//store previous sibling before in case where child remove
			//from line box tree
			var previousSibling:InlineBox = child.previousSibling;
			
			//if child is a space with the right white space, remove it
			if (child.isSpace() == true)
			{
				switch(child.elementRenderer.coreStyle.getKeyword(child.elementRenderer.coreStyle.whiteSpace))
				{
					case NORMAL, NO_WRAP, PRE_LINE:
						child.parentNode.removeChild(child);
					
					default:
						return false;
				}
			}
			//else stop removing spaces
			else
			{
				return false;
			}
			
			child = previousSibling;
		}
		
		return true;
	}
	
	/**
	 * Get the added width of all the trailing spacesthat would
	 * be removed if the line box were layout now, taking white space
	 * into accounts. This is use to deduce the current width that the line
	 * box would have if it were layout immediately.
	 * 
	 * Works similar to removeTrailingSpaces
	 */
	private function getTrailingSpacesWidth(inlineBox:InlineBox):Bool
	{
		//start with the end of the line box tree
		var child:InlineBox = inlineBox.lastChild;
		while (child != null)
		{
			//first call recursively to add all spaces width at the end
			//of line box tree
			if (child.isEmbedded() == false)
			{
				if (child.firstChild != null)
				{
					var canAddSpacesWidthFurther:Bool = getTrailingSpacesWidth(child);
					//if false, a non-space or with a wrong white space was found
					//and there is no need to add other spaces width
					if (canAddSpacesWidthFurther == false)
					{
						return false;
					}
				}
			}
			
			//if child is a space with the right white space, add its width
			if (child.isSpace() == true)
			{
				switch(child.elementRenderer.coreStyle.getKeyword(child.elementRenderer.coreStyle.whiteSpace))
				{
					case NORMAL, NO_WRAP, PRE_LINE:
						_trailingSpaceWidth += child.bounds.width;
					
					default:
						return false;
				}
			}
			//else stop adding width
			else
			{
				return false;
			}
			
			child = child.previousSibling;
		}
		
		return true;
	}
	
	/**
	 * Determine wether the line box is empty.
	 * An empty line box has a 0 height.
	 * 
	 * The definition of an empty line box (from the CSS 2.1 spec) :
		 * Line boxes that contain no text, no preserved white space,
		 * no inline elements with non-zero margins, padding, or borders,
		 * and no other in-flow content (such as images, inline blocks or 
		 * inline tables), and do not end with a preserved newline must be treated
		 * as zero-height line boxes for the purposes of determining the positions 
		 * of any elements inside of them, and must be treated as not
		 * existing for any other purpose. 
	 */
	private function isEmptyLineBox():Bool
	{
		//TODO : implement all conditions
		if (rootInlineBox.firstChild == null)
		{
			return true;
		}
		
		return false;
	}
	
	/////////////////////////////////
	// PRIVATE HORIZONTAL ALIGNEMENT METHODS
	/////////////////////////////////
	
	/**
	 * compute the x position for all the inline boxes in
	 * this line box
	 * 
	 * return the total width occupied by inline boxes once
	 * they are properly aligned
	 */
	private function alignInlineBoxesHorizontally(rootInlineBox:InlineBox, isLastLine:Bool, concatenatedLength:Float):Float
	{	
		//get the remaining space left on the line after
		//withdrawing all inline boxes length
		//this space is used when centering inline boxes
		var remainingSpace:Float =  _availableWidth - concatenatedLength;
		var x:Float = 0;
		
		//if this line box is the first of its containing block
		//, apply text indent
		if (_isFirstLine == true)
		{
			x += _elementRenderer.coreStyle.usedValues.textIndent;
			remainingSpace -= _elementRenderer.coreStyle.usedValues.textIndent;
		}
		
		//switch alignement of text
		switch (_elementRenderer.coreStyle.getKeyword(_elementRenderer.coreStyle.textAlign))
		{
			case LEFT:
				alignLeft(x, rootInlineBox);
				
			case RIGHT:
				alignRight(x, remainingSpace, rootInlineBox);
				
			case CENTER:
				alignCenter(x, remainingSpace, rootInlineBox);
				
			case JUSTIFY:
				//last line of a block is not justified to 
				//prevent streching white space too much
				if (isLastLine == true)
				{
					alignLeft(x, rootInlineBox);
				}
				else
				{
					//pre and pre-wrap value for whitespace prevent altering white space width,
					//thus preventing justification
					switch(_elementRenderer.coreStyle.getKeyword(_elementRenderer.coreStyle.whiteSpace))
					{
						case PRE, PRE_WRAP:
							alignLeft(x, rootInlineBox);
							
						default:	
							//when justifying, inline boxes takes the whole
							//line box width
							concatenatedLength = _availableWidth;
							alignJustify(x, remainingSpace, rootInlineBox, _spacesNumber);
					}
					
				
				}
				
			default:
				throw 'Illegal value for text-align style';
		}
		
		//return the total width ocuppied by inline boxes
		return concatenatedLength;
	}
	
	/**
	 * Align all the inline box in this
	 * line box starting from left to right
	 */
	private function alignLeft(x:Float, inlineBox:InlineBox):Float
	{
		x += inlineBox.paddingLeft + inlineBox.marginLeft;
		
		var child:InlineBox = inlineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				x = alignLeft(x, child);
			}
			else
			{
				child.bounds.x = x + child.marginLeft;
				x += child.bounds.width + child.marginLeft + child.marginRight;
			}
			
			child = child.nextSibling;
		}
		
		x += inlineBox.paddingRight + inlineBox.marginRight;
		
		return x;
	}
	
	/**
	 * Align inline boxes of this line box
	 * by centering them in the line box
	 */
	private function alignCenter(x:Float, remainingSpace:Float, inlineBox:InlineBox):Float
	{
		x += inlineBox.marginLeft + inlineBox.paddingLeft;
		
		var child:InlineBox = inlineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				x =  alignCenter(x, remainingSpace, child);
			}
			
			child.bounds.x = (remainingSpace / 2) + x;
			x += child.bounds.width;
			
			child = child.nextSibling;
		}
		
		x += inlineBox.marginRight + inlineBox.paddingRight;
		
		return x;
	}
	
	/**
	 * Align the inline boxes of this line
	 * box from right to left
	 */
	private function alignRight(x:Float, remainingSpace:Float, inlineBox:InlineBox):Float
	{
		x += inlineBox.marginLeft + inlineBox.paddingLeft;
		
		var child:InlineBox = inlineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				x = alignRight(x, remainingSpace, child);
			}
			
			child.bounds.x = x + remainingSpace;
			x += child.bounds.width;
			
			child = child.nextSibling;
		}
		
		x += inlineBox.marginRight + inlineBox.paddingRight;
		
		return x;
	}
	
	/**
	 * Justify inline boxes of this line
	 * box by stretching each white space equally
	 * so that inline boxes fill the whole line box
	 */
	private function alignJustify(x:Float, remainingSpace:Float, inlineBox:InlineBox, spacesInLine:Int):Void
	{
		var child:InlineBox = inlineBox.firstChild;
		while(child != null)
		{
			if (child.isSpace() == true)
			{
				var spaceWidth:Float = (remainingSpace / spacesInLine);
				
				spacesInLine--;
				remainingSpace -= spaceWidth;
				x += spaceWidth;
			}
			
			child.bounds.x = x;
			x += child.bounds.width;
			
			if (child.firstChild != null)
			{
				alignJustify(x, remainingSpace, child, spacesInLine);
			}
			
			child = child.nextSibling;
		}
	}
	
	/////////////////////////////////
	// PRIVATE VERTICAL ALIGNEMENT METHODS
	/////////////////////////////////
	
	/**
	 * Compute and return the height of the line box
	 * which is the height from the top of its top-most
	 * inline box and the bottom of its bottom-most
	 * inline box
	 */
	private function alignInlineBoxesVertically():Float
	{
		updateOffsetFromParentInlineBox(rootInlineBox);
		
		var lineBoxBounds:RectangleVO = new RectangleVO();
		lineBoxBounds.height = _elementRenderer.coreStyle.usedValues.lineHeight;
		
		getLineBoxHeight(rootInlineBox, lineBoxBounds, 0);
		var lineBoxHeight:Float = lineBoxBounds.height;
		
		updateOffsetFromLineBox(rootInlineBox, lineBoxHeight, 0);
		
		var minimumTop:Float = getMinimumTop(rootInlineBox, 0);
		
		applyMinimumTop(rootInlineBox, minimumTop);
		
		return lineBoxHeight;
	}
	
	/**
	 * Update the width and height bounds of all the non-replaced
	 * inline boxes of the line box
	 */
	private function updateInlineBoxesBounds(inlineBox:InlineBox):Void
	{
		var child:InlineBox = inlineBox.firstChild;
		while (child != null)
		{
			if (child.isText() == false && child.isEmbedded() == false)
			{
				updateInlineBoxesBounds(child);
				updateInlineBoxBounds(child);
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Update the bound of a container inline box whose
	 * bounds depends on its descendant inline boxes
	 */
	private function updateInlineBoxBounds(inlineBox:InlineBox):Void
	{
		inlineBox.bounds.x = 50000;
		inlineBox.bounds.y = 50000;
		inlineBox.bounds.width = 0;
		inlineBox.bounds.height = 0;
		
		var child:InlineBox = inlineBox.firstChild;

		//reset bounds if the inline box has no child
		if (child == null)
		{
			inlineBox.bounds.x = 0;
			inlineBox.bounds.y = 0;
		}
		
		while (child != null)
		{
			//should use margin bounds of the children
			var childBounds:RectangleVO = new RectangleVO();
			childBounds.x = child.bounds.x - child.marginLeft;
			childBounds.y = child.bounds.y;
			childBounds.width = child.bounds.width + child.marginRight + child.marginLeft;
			childBounds.height = child.bounds.height;
			
			GeomUtils.addBounds(childBounds, inlineBox.bounds);
			child = child.nextSibling;
		}
		
		//add paddings of inline box
		inlineBox.bounds.width += inlineBox.paddingLeft + inlineBox.paddingRight;
		inlineBox.bounds.x -= inlineBox.paddingLeft;
	}
	
	/**
	 * All inline boxes have an x/y position relative to their parent inline box,
	 * or to the strut if the parent is the root inline box.
	 * 
	 * This method update the y position of all the inline boxes by traversing
	 * the inline box tree recursivley. This position is influenced by the 
	 * vertical-align style of the inline box
	 */
	private function updateOffsetFromParentInlineBox(inlineBox:InlineBox):Void
	{
		var child:InlineBox = inlineBox.firstChild;
		while (child != null)
		{
			var childCoreStyle:CoreStyle = child.elementRenderer.coreStyle;
			//y position depends on the vertical alignement
			switch(childCoreStyle.verticalAlign)
			{
				case KEYWORD(value):
					switch(value)
					{
						//align baseline of child to baseline of parent
						case BASELINE:
							var yOffset:Float = childCoreStyle.fontMetrics.ascent - inlineBox.elementRenderer.coreStyle.fontMetrics.ascent;
							child.offsetFromParentInlineBox.y = -yOffset;
						
						//align the vertical mid-point of the child to the
						//baseline of the parent + half its x-height
						case MIDDLE:
							var yOffset:Float = (childCoreStyle.fontMetrics.ascent + (child.bounds.height / 2)) - (inlineBox.leadedAscent + (inlineBox.elementRenderer.coreStyle.fontMetrics.xHeight / 2));
							child.offsetFromParentInlineBox.y = -yOffset;
							
						case TEXT_BOTTOM:
							//TODO
						case TEXT_TOP:
							//TODO
						case SUB:
							//TODO
						case SUPER:	
							//TODO
							
						//top and bottom inline box can only 
						//be aligned once the line box height is known
						case TOP, BOTTOM:	
							child.offsetFromParentInlineBox.y = 0;
							
						default:	
					}
					
				case ABSOLUTE_LENGTH(value):
					var offsetFromBaseline:Float = childCoreStyle.fontMetrics.ascent - inlineBox.elementRenderer.coreStyle.fontMetrics.ascent;
					child.offsetFromParentInlineBox.y = -value;
					
				case PERCENTAGE(value):
					
				default:	
					
			}
			
			//update the child if the child inline box is a non-replaced inline
			//box with children
			if (child.isEmbedded() == false)
			{
				if (child.firstChild != null)
				{
					updateOffsetFromParentInlineBox(child);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * The x/y bounds position of each inline box is defined in the space of 
	 * the line box. This methods compute the y bounds position of all inline box.
	 * 
	 * The total line box height (the height bounds of all the inline boxes) must
	 * be known so that inline boxes aligned to the top or bottom of the line box
	 * can be placed
	 * 
	 * Traverse the inline box tree recursively
	 * 
	 * @param	inlineBox
	 * @param	lineBoxHeight the total line box height
	 * @param	addedY thr current added y of all the ancestor inline boxes up to the root
	 * inline boxes
	 */
	private function updateOffsetFromLineBox(inlineBox:InlineBox, lineBoxHeight:Float, addedY:Float):Void
	{
		var child:InlineBox = inlineBox.firstChild;
		while (child != null)
		{
			//top aligned child are always placed at 0 (top of the line box)
			if (isTopAligned(child))
			{
				child.bounds.y = 0;
			}
			//bottom aligned child align the bottom of their aligned sub tree
			//to the bottom of the line box
			else if (isBottomAligned(child))
			{
				child.bounds.y = lineBoxHeight - getAlignedSubTreeHeight(child, child.bounds.height, 0, false);
			}
			else
			{
				child.bounds.y = addedY + child.offsetFromParentInlineBox.y;
			}
			
			//call recursively for non-replaced inline boxes
			if (child.isEmbedded() == false && child.isText() == false)
			{
				//inline boxes add global y
				child.bounds.y += addedY;
				
				if (child.firstChild != null)
				{
					updateOffsetFromLineBox(child, lineBoxHeight, child.bounds.y);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	private function getMinimumTop(inlineBox:InlineBox, minimumTop:Float):Float
	{
		var child:InlineBox = inlineBox.firstChild;
		while (child != null)
		{
			if (isTopOrBottomAligned(child) == false)
			{
				if (child.bounds.y < minimumTop)
				{
					minimumTop = child.bounds.y;
				}
				
				if (child.isEmbedded() == false)
				{
					if (child.firstChild != null)
					{
						minimumTop = getMinimumTop(child, minimumTop);
					}
				}
			}
			
			child = child.nextSibling;
		}
		
		return minimumTop;
	}
	
	private function applyMinimumTop(inlineBox:InlineBox, minimumTop:Float):Void
	{
		var child:InlineBox = inlineBox.firstChild;
		while (child != null)
		{
			if (isTopOrBottomAligned(child) == false)
			{
				child.bounds.y -= minimumTop;
				
				if (child.isEmbedded() == false)
				{
					if (child.firstChild != null)
					{
						applyMinimumTop(child, minimumTop);
					}
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Compute the line box bounds, including its height which is the height bounds
	 * of all the inline boxes in it, once those inline boxes
	 * have been vertically aligned
	 * 
	 * @param	inlineBox
	 * @param	lineBoxBounds the current bounds of the line box
	 */
	private function getLineBoxHeight(inlineBox:InlineBox, lineBoxBounds:RectangleVO, addedY:Float):Void
	{
		var child:InlineBox = inlineBox.firstChild;
		while (child != null)
		{
			//when computing line box height, top and bottom aligned
			//inline boxes are assumed to be at a y position of 0 and
			//their height bounds is the bounds of their aligned subtree
			//which includes all their descendant inline box except those
			//which are also top or bottom aligned
			if (isTopOrBottomAligned(child) == true)
			{
				//if this child inline box also has top or bottom aligned descendant, they 
				//will be added to the line box height computation
				var alignedSubTreeHeight:Float = getAlignedSubTreeHeight(child, child.bounds.height, 0, true);
				
				//TODO : re-implement with bounds
				//if (alignedSubTreeHeight > lineBoxHeight)
				//{
					//lineBoxHeight = alignedSubTreeHeight;
				//}
			}
			else 
			{
				var childBounds:RectangleVO = new RectangleVO();
				childBounds.y = child.offsetFromParentInlineBox.y + addedY;
				childBounds.height = child.bounds.height;
				
				GeomUtils.addBounds(childBounds, lineBoxBounds);
				
				//for non-replaced inline boxes which are not
				//top or bottom aligned, call recursively
				if (child.isEmbedded() == false)
				{
					if (child.firstChild != null)
					{
						getLineBoxHeight(child, lineBoxBounds, addedY + child.offsetFromParentInlineBox.y);
					}
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of either top or bottom
	 */
	private function isTopOrBottomAligned(inlineBox:InlineBox):Bool
	{
		return (inlineBox.elementRenderer.coreStyle.isBottomAligned == true || inlineBox.elementRenderer.coreStyle.isTopAligned);
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of top
	 */
	private function isTopAligned(inlineBox:InlineBox):Bool
	{
		return inlineBox.elementRenderer.coreStyle.isTopAligned;
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of bottom
	 */
	private function isBottomAligned(inlineBox:InlineBox):Bool
	{
		return inlineBox.elementRenderer.coreStyle.isBottomAligned;
	}
	
	/**
	 * For an inline box with a vertical
	 * align style of either top or bottom,
	 * returns the height of the bounds of 
	 * itself and its vertically aligned
	 * descendant. This height is used when
	 * computed the line box height
	 * 
	 * Traverse the inline box tree recursively
	 * starting from the top/botom inline box
	 * 
	 * @param	inlineBox
	 * @param	alignedSubTreeHeight the max height found 
	 * in the aligned subtree
	 * @param	addedY the current added y of all the parent inline boxes
	 * @param	includeChildTopAndBottomInlineBoxes when a descendant is also 
	 * top or bottom aligned, wether to include its own aligned sub tree height
	 * in the computation
	 * @return the height bounds of the top/bottom inline box and all its descendant
	 */
	private function getAlignedSubTreeHeight(inlineBox:InlineBox, alignedSubTreeHeight:Float, addedY:Float, includeChildTopAndBottomInlineBoxes:Bool):Float
	{
		//TODO : implement
		return alignedSubTreeHeight;
	}
	
}