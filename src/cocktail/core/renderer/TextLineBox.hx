package cocktail.core.renderer;
import cocktail.core.FontManager;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextLineBox extends LineBox
{

	public function new(elementRenderer:ElementRenderer, text:String) 
	{
		super(elementRenderer);
		
		_nativeElement = new FontManager().createNativeTextElement(text, elementRenderer.coreStyle.computedStyle);
		
		#if (flash9 || nme)
		_bounds.width = getOffsetWidth();
		_bounds.height = getOffsetHeight();
		#end
		
	}
	
	
	#if flash9
	
	/**
	 * The offset width for a text fragment is the width of its
	 * text
	 */
	private function getOffsetWidth():Int
	{
		
		//in this case the text fragment is a space, as the flash
		//text engine doesn't account for the width of space
		if (untyped _nativeElement.textWidth == 0)
		{
			//for a space, the width of a space is retrieved from the font metrics, plus the letter spacing
			//which also apply to space and the word spacing which aplies only to text
			return _elementRenderer.coreStyle.fontMetrics.spaceWidth + _elementRenderer.coreStyle.computedStyle.letterSpacing + _elementRenderer.coreStyle.computedStyle.wordSpacing;
		}
		//in this case the text fragment is a word, the text width is returned, it already
		//contains the letter spacing which was applied when the text was rendered
		else
		{
			return untyped _nativeElement.textWidth ;
		}	
	}
	
	#elseif nme
	/**
	 * The offset width for a text fragment is the width of its
	 * text
	 */
	private function getOffsetWidth():Int
	{
		//TODO : shouldn't be here but in a Document class
		flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
		
		var ret:Int = _nativeElement.textWidth;
		
		return ret;
		
		
	}
	
	#end

	/**
	 * the height of a text fragment is the addition
	 * of its leaded ascent and leaded descent
	 */
	private function getOffsetHeight():Int
	{
		
		var ascent:Float =  _elementRenderer.coreStyle.fontMetrics.ascent;
		var descent:Float = _elementRenderer.coreStyle.fontMetrics.descent;
		
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = _elementRenderer.coreStyle.computedStyle.lineHeight - (ascent + descent);
		
		//apply leading to the ascent and descent
		var leadedAscent:Float = (ascent + leading/2);
		var leadedDescent:Float = (descent + leading / 2);
		
		return Math.round(leadedAscent + leadedDescent);
	}
	
	
}