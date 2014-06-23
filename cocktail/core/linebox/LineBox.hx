/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.linebox;

import cocktail.core.css.CoreStyle;
import cocktail.geom.GeomUtils;
import cocktail.core.linebox.InlineBox;
import cocktail.core.renderer.BlockBoxRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.font.FontData;
import cocktail.geom.GeomData;
import cocktail.core.layout.LayoutData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class LineBox 
{
	private var _unbreakableInlineBoxes:Array<InlineBox>;
	
	public var unbreakableWidth(default, null):Int;
	
	public var rootInlineBox:InlineBox;
	
	private var _addedWidth:Float;
	
	public var bounds:RectangleVO;
	
	private var _isFirstLine:Bool;

	private var _elementRenderer:ElementRenderer;
	
	private var _spacesNumber:Int;
	
	private var _firstInlineBoxInserted:Bool;
	
	private var _layoutState:LayoutStateValue;
	
	private static var _childBounds:RectangleVO = new RectangleVO();
	
	private static var _inlineBoxesBounds:RectangleVO = new RectangleVO();
	
	/**
	 * Store the current width of all the
	 * spaces that would be removed if
	 * the white space processing was
	 * applied
	 */
	private var _trailingSpaceWidth:Float;
	
	public function new(elementRenderer:ElementRenderer, isFirstLine:Bool, layoutState:LayoutStateValue) 
	{
		_isFirstLine = isFirstLine;
		_elementRenderer = elementRenderer;
		_spacesNumber = 0;
		unbreakableWidth = 0;
		_addedWidth = 0;
		_firstInlineBoxInserted = false;
		_unbreakableInlineBoxes = new Array<InlineBox>();
		_layoutState = layoutState;
		_trailingSpaceWidth = 0;
		
		rootInlineBox = new InlineBox(elementRenderer, elementRenderer.getLeadedAscent(), elementRenderer.getLeadedDescent());
		bounds = new RectangleVO();
	}
	
	public function addUnbreakableWidth(width:Float):Void
	{
		unbreakableWidth += Math.floor(width);
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
		
		if (_addedWidth + width - _trailingSpaceWidth <= bounds.width)
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
			if (inlineBox.isSpace == true)
			{
				var inlineBoxCoreStyle:CoreStyle = inlineBox.elementRenderer.coreStyle;
				if (inlineBoxCoreStyle.hasNormalWhiteSpace == true || inlineBoxCoreStyle.hasPreWrapWhiteSpace == true 
				|| inlineBoxCoreStyle.hasNoWrapWhiteSpace)
				{
					return false;
				}
			}
			
			_firstInlineBoxInserted = true;
		}
		
		//increment spaces number which is needed
		//for text justification algorithm
		if (inlineBox.isSpace == true)
		{
			_spacesNumber++;
		}
		
		//add the new inline box to the unbreakable inline box buffer,
		//it will be added to the line if there is enough space or if
		//its white space prevents the line from breaking
		_unbreakableInlineBoxes.push(inlineBox);	
	
		var inlineBoxWidth:Float = inlineBox.bounds.width + inlineBox.marginLeft + inlineBox.marginRight;
		unbreakableWidth += Math.floor(inlineBoxWidth);
		
		//get the remaining available space on the current line
		var remainingLineWidth:Int = Math.floor(bounds.width - _addedWidth);

		//line box always break if the inline box represents a line feed
		if (inlineBox.isLineFeed == true)
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
		_unbreakableInlineBoxes = [];
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
		var inlineBoxCoreStyle:CoreStyle = inlineBox.elementRenderer.coreStyle;
		if (inlineBoxCoreStyle.hasPreWhiteSpace == true || inlineBoxCoreStyle.hasNoWrapWhiteSpace == true)
		{
			return false;
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
		if (isEmptyLineBox(rootInlineBox) == true)
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
			if (child.isEmbedded == false)
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
			if (child.isSpace == true)
			{
				var inlineBoxCoreStyle:CoreStyle = child.elementRenderer.coreStyle;
				if (inlineBoxCoreStyle.hasNormalWhiteSpace == true ||
				inlineBoxCoreStyle.hasNoWrapWhiteSpace == true || 
				inlineBoxCoreStyle.hasPreLineWhiteSpace == true)
				{
					child.parentNode.removeChild(child);
					
					//remove the space width from the total width of inlinebox in the line
					_addedWidth -= child.bounds.width;
					//there is one less space in the line
					_spacesNumber--;
				}
				else
				{
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
			if (child.isEmbedded == false)
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
			if (child.isSpace == true)
			{
				var inlineBoxCoreStyle:CoreStyle = child.elementRenderer.coreStyle;
				if (inlineBoxCoreStyle.hasNormalWhiteSpace == true ||
				inlineBoxCoreStyle.hasNoWrapWhiteSpace == true || 
				inlineBoxCoreStyle.hasPreLineWhiteSpace == true)
				{
					_trailingSpaceWidth += child.bounds.width;
				}
				else
				{
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
		 * 
		 * TODO : missing preseved white space and newlines condition
	 */
	private function isEmptyLineBox(rootInlineBox:InlineBox):Bool
	{
		var child:InlineBox = rootInlineBox.firstChild;
		while (child != null)
		{
			if (child.isText == true && child.isSpace == false)
			{
				return false;
			}
			else if (child.isEmbedded == true)
			{
				return false;
			}
			else
			{
				if (child.marginLeft != 0 || child.marginRight != 0
				|| child.paddingLeft != 0 || child.paddingLeft != 0
				|| child.borderLeft != 0 || child.borderRight != 0)
				{
					return false;
				}
				else
				{
					var isEmpty:Bool = isEmptyLineBox(child);
					if (isEmpty == false)
					{
						return false;
					}
				}
			}
			
			
			child = child.nextSibling;
		}
		
		return true;
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
		var remainingSpace:Float =  bounds.width - concatenatedLength;
		var x:Float = 0;
		
		//if this line box is the first of its containing block
		//, apply text indent
		if (_isFirstLine == true)
		{
			x += _elementRenderer.coreStyle.usedValues.textIndent;
			remainingSpace -= _elementRenderer.coreStyle.usedValues.textIndent;
		}
		
		//switch text alignement,
		//shortcut for left, the most common case
		if (_elementRenderer.coreStyle.isLeftAligned == true)
		{
			alignLeft(x, rootInlineBox);
		}
		else
		{
			switch (_elementRenderer.coreStyle.getKeyword(_elementRenderer.coreStyle.textAlign))
			{
				case RIGHT:
					//for right align, start from the right of the line box,
					//so start with the line box width
					x = bounds.width - x;
					alignRight(x, rootInlineBox);
					
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
								concatenatedLength = bounds.width;
								
								//justification is done by modifying the width of each space on the line.
								//Each space will have the same width once justified
								
								//first get the total width of all inline boxes which are not space
								var concatedWidthWithoutSpaces:Float = getConcatenatedWidthWithoutSpaces(rootInlineBox);
								
								//then deduce the width that each space should have, by taking the remaining available space
								//on the line once all non-space inline boxes width have been removed, and divising it
								//by the number of space in the line
								var spaceWidth:Float = (concatenatedLength - concatedWidthWithoutSpaces) /_spacesNumber;
								
								alignJustify(x, rootInlineBox, spaceWidth);
						}
						
					
					}
					
				default:
					throw 'Illegal value for text-align style';
			}
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
		x += inlineBox.paddingLeft + inlineBox.borderLeft + inlineBox.marginLeft;
		
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
		
		x += inlineBox.paddingRight + inlineBox.borderRight + inlineBox.marginRight;
		
		return x;
	}
	
	/**
	 * Align inline boxes of this line box
	 * by centering them in the line box
	 */
	private function alignCenter(x:Float, remainingSpace:Float, inlineBox:InlineBox):Float
	{
		x += inlineBox.marginLeft + inlineBox.borderLeft + inlineBox.paddingLeft;
		
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
		
		x += inlineBox.marginRight + inlineBox.borderRight + inlineBox.paddingRight;
		
		return x;
	}
	
	/**
	 * Align the inline boxes of this line
	 * box from right to left
	 */
	private function alignRight(x:Float, inlineBox:InlineBox):Float
	{
		x -= inlineBox.paddingRight + inlineBox.borderRight + inlineBox.marginRight;
		
		//inline box tree is traversed in reverse order, 
		//(it starts with the box at the right-most of the linebox)
		var child:InlineBox = inlineBox.lastChild;
		while(child != null)
		{
			if (child.lastChild != null)
			{
				x = alignRight(x, child);
			}
			else
			{
				child.bounds.x = x - child.bounds.width + child.marginLeft;
				x -= child.bounds.width + child.marginLeft + child.marginRight;
			}
			
			child = child.previousSibling;
		}
		
		x -= inlineBox.paddingLeft + inlineBox.borderLeft + inlineBox.marginLeft;
		
		return x;
	}
	
	/**
	 * Justifying is similar to left alignement, except that all
	 * space inline box are streched so that so whole line box gets
	 * filled. The width for the streched spaces is provided
	 */
	private function alignJustify(x:Float, inlineBox:InlineBox, spacesWidth:Float):Float
	{
		x += inlineBox.paddingLeft + inlineBox.borderLeft + inlineBox.marginLeft;
		
		var child:InlineBox = inlineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				x = alignJustify(x, child, spacesWidth);
			}
			else
			{
				//when space, use provided streched space width
				//instead of actual width of the space
				if (child.isSpace == true)
				{
					child.bounds.x = x;
					x += spacesWidth;
				}
				else
				{
					child.bounds.x = x + child.marginLeft;
					x += child.bounds.width + child.marginLeft + child.marginRight;
				}
			}
			
			child = child.nextSibling;
		}
		
		x += inlineBox.marginRight + inlineBox.borderRight + inlineBox.paddingRight;
		
		return x;
	}
	
	/**
	 * utils method returning the total space taken by inline boxes excluding
	 * the space inline box. This is used to determine the space of width 
	 * when justificating the line box
	 */
	private function getConcatenatedWidthWithoutSpaces(inlineBox:InlineBox):Float
	{
		var width:Float = 0;
		
		var child:InlineBox = inlineBox.firstChild;
		while(child != null)
		{
			if (child.firstChild != null)
			{
				width += getConcatenatedWidthWithoutSpaces(child);
			}
			else
			{
				if (child.isSpace == false)
				{
					width += child.bounds.width;
				}
			}
			
			child = child.nextSibling;
		}
		
		return width;
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
		
		_inlineBoxesBounds.x = 0;
		_inlineBoxesBounds.y = 0;
		_inlineBoxesBounds.width = 0;
		_inlineBoxesBounds.height = 0;
		
		_inlineBoxesBounds.height = _elementRenderer.coreStyle.usedValues.lineHeight;
		
		//TODO 2 : for now, 0 is passed for line box height, which will prevent
		//bottom aligned box from being properly aligned. It was modified because
		//the line box height should be computed after all the inline boxes
		//are placed relative to the line box and not before, so that the right bounds, notably
		//including leadings, can be found
		//
		//should split line height foud from top and bottom aligned box and
		//other line box height ?
		updateOffsetFromLineBox(rootInlineBox, 0, 0);
		
		var minimumTop:Float = getMinimumTop(rootInlineBox, 0);
		
		applyMinimumTop(rootInlineBox, minimumTop);
		
		getLineBoxHeight(rootInlineBox, _inlineBoxesBounds, 0);
		var lineBoxHeight:Float = _inlineBoxesBounds.height;
		
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
			if (child.isText == false && child.isEmbedded == false)
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
			_childBounds.x = child.bounds.x - child.marginLeft;
			_childBounds.y = child.bounds.y;
			_childBounds.width = child.bounds.width + child.marginRight + child.marginLeft;
			_childBounds.height = child.bounds.height;
			
			GeomUtils.addBounds(_childBounds, inlineBox.bounds);

			child = child.nextSibling;
		}
		
		//add paddings and borders of inline box
		inlineBox.bounds.width += inlineBox.paddingLeft + inlineBox.paddingRight + inlineBox.borderLeft + inlineBox.borderRight;
		inlineBox.bounds.x -= inlineBox.paddingLeft + inlineBox.borderLeft;
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
			
			//first check if baseline aligned, most common case
			if (childCoreStyle.isBaselineAligned == true)
			{
				var childLeadedAscent:Float = child.leadedAscent;
				
				//for embedded element such as picture, 
				//use margin box for leaded ascent
				if (child.isEmbedded == true)
				{
					childLeadedAscent = child.bounds.height + child.elementRenderer.coreStyle.usedValues.marginTop + child.elementRenderer.coreStyle.usedValues.marginBottom;
					
					//special case for non-replaced inline block box, if establish an inline formatting, use baseline
					//of last line box for its leaded ascent
					if (child.elementRenderer.isBlockContainer == true && child.elementRenderer.coreStyle.isInlineBlock == true)
					{
						if (child.elementRenderer.childrenInline() == true)
						{
							var blockBox:BlockBoxRenderer = cast(child.elementRenderer);
							childLeadedAscent =  blockBox.lineBoxes[blockBox.lineBoxes.length - 1].bounds.y + child.leadedAscent;
						}
					}
				}
				
				var yOffset:Float = childLeadedAscent - inlineBox.leadedAscent;
				child.offsetFromParentInlineBox.y = -yOffset;
			}
			else
			{
				//y position depends on the vertical alignement
				switch(childCoreStyle.verticalAlign)
				{
					case KEYWORD(value):
						switch(value)
						{
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
			}
			
			
			//update the child if the child inline box is a non-replaced inline
			//box with children
			if (child.isEmbedded == false)
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
			if (child.isEmbedded == false && child.isText == false)
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
	
	/**
	 * get the top position of the top most inline box
	 * in the line box. If this inline box is higher than
	 * the line box, the minimum top will be negative
	 */
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
				
				if (child.isEmbedded == false)
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
	
	/**
	 * Apply the miminum top by offsetting all inline boxes such
	 * as the inline box which set the minimum top is set to the 
	 * top of the line box and all the other inline boxes are offset
	 * by the minimum top
	 */
	private function applyMinimumTop(inlineBox:InlineBox, minimumTop:Float):Void
	{
		var child:InlineBox = inlineBox.firstChild;
		while (child != null)
		{
			if (isTopOrBottomAligned(child) == false)
			{
				child.bounds.y -= minimumTop;
				
				if (child.isEmbedded == false)
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
				//only embedded/inline-block box and text inline box height
				//is used, as ampty inlinebox arer not taken into account
				if (child.isEmbedded == true || child.isText == true)
				{
					_childBounds.x = 0;
					_childBounds.y = 0;
					_childBounds.width = 0;
					_childBounds.height = 0;
					
					_childBounds.y = child.bounds.y + addedY;
					_childBounds.height = child.bounds.height;
					
					GeomUtils.addBounds(_childBounds, lineBoxBounds);
				}
				
				//TODO : take vertical margin into account ?
				
				//for non-replaced inline boxes which are not
				//top or bottom aligned, call recursively
				if (child.isEmbedded == false)
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
	private inline function isTopOrBottomAligned(inlineBox:InlineBox):Bool
	{
		return (inlineBox.elementRenderer.coreStyle.isBottomAligned == true || inlineBox.elementRenderer.coreStyle.isTopAligned);
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of top
	 */
	private inline function isTopAligned(inlineBox:InlineBox):Bool
	{
		return inlineBox.elementRenderer.coreStyle.isTopAligned;
	}
	
	/**
	 * Return wether an inline box has a vertical align
	 * style of bottom
	 */
	private inline function isBottomAligned(inlineBox:InlineBox):Bool
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
