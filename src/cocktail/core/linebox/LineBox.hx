package cocktail.core.linebox;
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
	
	private var _minimumHeight:Float;
	
	private var _firstInlineBoxInserted:Bool;
	
	private var _layoutState:LayoutStateValue;
	
	public function new(elementRenderer:ElementRenderer, availableWidth:Float, minimumHeight:Float, isFirstLine:Bool, layoutState:LayoutStateValue) 
	{
		//TODO : if first line, apply text indent to _addedWidth
		_availableWidth = availableWidth;
		_isFirstLine = isFirstLine;
		_elementRenderer = elementRenderer;
		_spacesNumber = 0;
		unbreakableWidth = 0;
		_addedWidth = 0;
		_firstInlineBoxInserted = false;
		_minimumHeight = minimumHeight;
		_unbreakableInlineBoxes = new Array<InlineBox>();
		_layoutState = layoutState;
		
		rootInlineBox = new InlineBox(elementRenderer);
		bounds = new RectangleVO();
	}
	
	
	public function addUnbreakableWidth(width:Float):Void
	{
		unbreakableWidth += width;
		_addedWidth += width;
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
	
	public function layout(isLastLine:Bool, parentInlineBox:InlineBox):Void
	{
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
		
		bounds.width = alignLineBox(rootInlineBox, isLastLine, _addedWidth);
		
		bounds.height = computeLineBoxHeight(rootInlineBox);
		
		if (bounds.height < _minimumHeight)
		{
			bounds.height = _minimumHeight;
		}
		
		//TODO : need better implementation :
		// from spec : 
		//Line boxes that contain no text, no preserved white space,
		//no inline elements with non-zero margins, padding, or borders,
		//and no other in-flow content (such as images, inline blocks or 
		//inline tables), and do not end with a preserved newline must be treated
		//as zero-height line boxes for the purposes of determining the positions 
		//of any elements inside of them, and must be treated as not existing for any other purpose. 
		if (rootInlineBox.firstChild == null)
		{
			bounds.height = 0;
		}
	}
	
	/**
	 * Align the inline boxes of this line 
	 * box horizontally
	 * 
	 * return the total occupied by inline boxes once
	 * they are properly aligned
	 */
	private function alignLineBox(rootInlineBox:InlineBox, isLastLine:Bool, concatenatedLength:Float):Float
	{	
		//get the remaining space left on the line after
		//withdrawing all inline boxes length
		//this space isused when centering inline boxes
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
	//
	//
	// LINE LAYOUT METHODS
	// Those methods are used to determine the x and y position
	// of each element in the line
//////////////////////////////////////////////////////////////////


	/////////////////////////////////
	// PRIVATE VERTICAL ALIGNEMENT METHODS
	/////////////////////////////////
	
	/**
	 * 
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
	private function computeLineBoxHeight(rootInlineBox:InlineBox):Float
	{
		//var formattingContextFontMetrics:FontMetricsVO = _elementRenderer.coreStyle.fontMetrics;
		//setRootLineBoxMetrics(rootLineBox, rootLineBox, 0.0, formattingContextFontMetrics);
		//
		//alignLineBoxesVertically(rootLineBox, rootLineBox.leadedAscent, _formattingContextData.y, 0.0, formattingContextFontMetrics);

		//compute the line box height
		var lineBoxHeight:Float = rootInlineBox.bounds.height;
		
		return lineBoxHeight;
	}
	
	private function updateOffsetFromParentInlineBox(rootInlineBox:InlineBox):Void
	{
		var child:InlineBox = rootInlineBox.firstChild;
		while (child != null)
		{
			switch(child.elementRenderer.coreStyle.verticalAlign)
			{
				case BASELINE:
					child.offsetFromParentInlineBox.y = 
			}
			
			child = child.nextSibling;
		}
	}
	
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