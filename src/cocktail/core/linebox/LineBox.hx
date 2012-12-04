package cocktail.core.linebox;
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
		
		rootInlineBox = new InlineBox(elementRenderer);
		bounds = new RectangleVO();
	}
	
	
	public function addUnbreakableWidth(width:Float):Void
	{
		unbreakableWidth += width;
	}
	
	//TODO : keep track of inserted spaces number
	//TODO : remove space inserted at beginning
	public function insert(inlineBox:InlineBox, parentInlineBox:InlineBox):Bool
	{
		//TODO : implement cleanly, remove space at beginning of line
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
		
		if (inlineBox.isSpace() == true)
		{
			_spacesNumber++;
		}
		
		_unbreakableInlineBoxes.push(inlineBox);	
	
		var inlineBoxWidth:Float = inlineBox.bounds.width + inlineBox.marginLeft + inlineBox.marginRight;
		
		unbreakableWidth += inlineBoxWidth;
		//TODO : if it is a space which make line break, remove the space
		if (introduceBreakOpportunity(inlineBox) == true)
		{
			//get the remaining available space on the current line
			var remainingLineWidth:Float = _availableWidth - _addedWidth;

			//if there isn't enough space to fit all the line box which can't be broken
			//TODO 1 : should apply white space processing model for line break here
			if (remainingLineWidth - unbreakableWidth < 0)
			{
				//TODO : should still break for line feed
				if (_layoutState != LayoutStateValue.SHRINK_TO_FIT_PREFERED_WIDTH)
				{
					return true;
				}
			}
			else
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
				//reset unbreakable line box now that they were added to the line
				_unbreakableInlineBoxes = _unbreakableInlineBoxes.clear();
				unbreakableWidth = 0;
			}
		}
		
		if (_layoutState == LayoutStateValue.SHRINK_TO_FIT_PREFERED_MINIMUM_WIDTH)
		{
			return true;
		}

		return false;
	}
	
	//TODO : implement
	private function introduceBreakOpportunity(inlineBox:InlineBox):Bool
	{
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
					//when justifying, inline boxes takes the whole
					//line box width
					concatenatedLength = _availableWidth;
					
					alignJustify(x, remainingSpace, rootInlineBox, _spacesNumber);
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
		
		var lineBoxHeight:Float = getLineBoxHeight(rootInlineBox, _elementRenderer.coreStyle.usedValues.lineHeight, 0);
		
		updateOffsetFromLineBox(rootInlineBox, lineBoxHeight, 0);
		
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
		while (child != null)
		{
			GeomUtils.addBounds(child.bounds, inlineBox.bounds);
			child = child.nextSibling;
		}
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
			//y position depends on the vertical alignement
			switch(child.elementRenderer.coreStyle.verticalAlign)
			{
				case KEYWORD(value):
					switch(value)
					{
						//align baseline of child to baseline of parent
						case BASELINE:
							var yOffset:Float = child.elementRenderer.coreStyle.fontMetrics.ascent - inlineBox.elementRenderer.coreStyle.fontMetrics.ascent;
							child.offsetFromParentInlineBox.y = yOffset;
						
						//align the vertical mid-point of the child to the
						//baseline of the parent + half its x-height
						case MIDDLE:
							var yOffset:Float = (child.bounds.height / 2) - (inlineBox.leadedAscent + inlineBox.elementRenderer.coreStyle.fontMetrics.xHeight);
							
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
					
				case LENGTH(value):
					
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
			if (child.isEmbedded() == false)
			{
				if (child.firstChild != null)
				{
					updateOffsetFromLineBox(child, lineBoxHeight, child.bounds.y);
				}
			}
			
			child = child.nextSibling;
		}
	}
	
	/**
	 * Compute the line box height which is the height bounds
	 * of all the inline boxes in it, once those inline boxes
	 * have been vertically aligned
	 * 
	 * @param	inlineBox
	 * @param	lineBoxHeight the current max height bounds that were found
	 * @param	addedY the added y position of the ancestors inline boxes relative
	 * to the line boxe
	 * @return	the max inline box height bounds found
	 */
	private function getLineBoxHeight(inlineBox:InlineBox, lineBoxHeight:Float, addedY:Float):Float
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
				
				if (alignedSubTreeHeight > lineBoxHeight)
				{
					lineBoxHeight = alignedSubTreeHeight;
				}
			}
			else 
			{
				//check wether y position of the inline box + its height is superior to the current max height
				if (child.offsetFromParentInlineBox.y + addedY + child.bounds.height > lineBoxHeight)
				{
					lineBoxHeight = child.offsetFromParentInlineBox.y + addedY + child.bounds.height;
				}
				
				//for non-replaced inline boxes which are not
				//top or bottom aligned, call recursively
				if (child.isEmbedded() == false)
				{
					if (child.firstChild != null)
					{
						lineBoxHeight = getLineBoxHeight(child, lineBoxHeight, addedY + child.offsetFromParentInlineBox.y);
					}
				}
			}
			
			child = child.nextSibling;
		}
		
		return lineBoxHeight;
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of either top or bottom
	 */
	private function isTopOrBottomAligned(inlineBox:InlineBox):Bool
	{
		switch(inlineBox.elementRenderer.coreStyle.verticalAlign)
		{
			case KEYWORD(value):
				switch(value)
				{
					case TOP, BOTTOM:	
						return true;
						
					default:	
				}
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of top
	 */
	private function isTopAligned(inlineBox:InlineBox):Bool
	{
		switch(inlineBox.elementRenderer.coreStyle.verticalAlign)
		{
			case KEYWORD(value):
				switch(value)
				{
					case TOP:	
						return true;
						
					default:	
				}
				
			default:	
		}
		
		return false;
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of bottom
	 */
	private function isBottomAligned(inlineBox:InlineBox):Bool
	{
		switch(inlineBox.elementRenderer.coreStyle.verticalAlign)
		{
			case KEYWORD(value):
				switch(value)
				{
					case BOTTOM:	
						return true;
						
					default:	
				}
				
			default:	
		}
		
		return false;
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