package cocktail.core.linebox;
import cocktail.core.linebox.InlineBox;
import cocktail.core.renderer.ElementRenderer;
import cocktail.core.font.FontData;
import cocktail.core.geom.GeomData;
using cocktail.core.utils.Utils;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class LineBox 
{
	private var _unbreakableInlineBoxes:Array<InlineBox>;
	
	private var _unbreakableWidth:Float;
	
	public var rootInlineBox:InlineBox;
	
	private var _addedWidth:Float;
	
	private var _availableWidth:Float;
	
	public var bounds:RectangleVO;
	
	private var _isFirstLine:Bool;

	private var _elementRenderer:ElementRenderer;
	
	private var _spacesNumber:Int;
	
	private var _minimumHeight:Float;
	
	public function new(elementRenderer:ElementRenderer, availableWidth:Float, minimumHeight:Float, isFirstLine:Bool) 
	{
		//TODO : if first line, apply text indent to _addedWidth
		_availableWidth = availableWidth;
		_isFirstLine = isFirstLine;
		_elementRenderer = elementRenderer;
		_spacesNumber = 0;
		_unbreakableWidth = 0;
		_addedWidth = 0;
		_minimumHeight = minimumHeight;
		_unbreakableInlineBoxes = new Array<InlineBox>();
		rootInlineBox = new InlineBox(elementRenderer);
		bounds = new RectangleVO();
	}
	
	
	public function addUnbreakableWidth(width:Float):Void
	{
		_unbreakableWidth += width;
		_addedWidth += width;
	}
	
	//TODO : keep track of inserted spaces number
	//TODO : remove space inserted at beginning
	public function insert(inlineBox:InlineBox, parentInlineBox:InlineBox):Bool
	{
		_unbreakableInlineBoxes.push(inlineBox);	
	
		var inlineBoxWidth:Float = inlineBox.bounds.width + inlineBox.marginLeft + inlineBox.marginRight;
		
		_unbreakableWidth += inlineBoxWidth;
	
		//TODO : if it is a space which make line break, remove the space
		if (introduceBreakOpportunity(inlineBox) == true)
		{
			//get the remaining available space on the current line
			var remainingLineWidth:Float = _availableWidth - _addedWidth;

			//if there isn't enough space to fit all the line box which can't be broken
			//TODO 1 : should apply white space processing model for line break here
			if (remainingLineWidth - _unbreakableWidth < 0)
			{
				return true;
			}
			else
			{
				_addedWidth += _unbreakableWidth;
				
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
				_unbreakableWidth = 0;
			}
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
			_addedWidth += _unbreakableWidth;
				
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
	}
	
	
	private function alignLineBox(rootInlineBox:InlineBox, isLastLine:Bool, concatenatedLength:Float):Float
	{	
		var remainingSpace:Float =  _availableWidth - concatenatedLength;
		var x:Float = 0;
		
		remainingSpace = _availableWidth - concatenatedLength;
		
		if (_isFirstLine == true)
		{
			x += _elementRenderer.coreStyle.usedValues.textIndent;
			remainingSpace -= _elementRenderer.coreStyle.usedValues.textIndent;
		}
		
		switch (_elementRenderer.coreStyle.getKeyword(_elementRenderer.coreStyle.textAlign))
		{
			case LEFT:
				alignLeft(x, rootInlineBox);
				
			case RIGHT:
				alignRight(x, remainingSpace, rootInlineBox);
				
			case CENTER:
				alignCenter(x, remainingSpace, rootInlineBox);
				
			case JUSTIFY:
				if (isLastLine == true)
				{
					alignLeft(x, rootInlineBox);
				}
				else
				{
					concatenatedLength = _availableWidth;
					alignJustify(x, remainingSpace, rootInlineBox, _spacesNumber);
				}
				
			default:
				throw 'Illegal value for text-align style';
		}
		
		return concatenatedLength;
	}
	
	
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