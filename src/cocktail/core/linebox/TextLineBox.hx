/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.linebox;

import cocktail.core.renderer.ElementRenderer;
import cocktail.core.style.ComputedStyle;
import cocktail.Lib;
import cocktail.core.font.FontManager;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;
import cocktail.core.font.FontData;
/**
 * A special kind of line box used to render text. 
 * Wrap a native text element which is platform
 * specific
 * 
 * @author Yannick DOMINGUEZ
 */
class TextLineBox extends LineBox
{
	/**
	 * A ref to the font metrics of the TextElementRenderer
	 */
	private var _fontMetrics:FontMetricsData;
	
	/**
	 * The native text element wrapped by this
	 * text line box
	 */
	private var _nativeElement:NativeElement;
	
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, text:String, fontMetrics:FontMetricsData, fontManager:FontManager) 
	{
		super(elementRenderer);
		
		_fontMetrics = fontMetrics;
		
		initNativeTextElement(text, fontManager, elementRenderer.coreStyle.computedStyle);
		
		//init the leaded ascent and desecent of the text
		//only need to be computed once, the text of this 
		//TextLineBox can't change after instanciation
		leadedAscent = getLeadedAscent();
		leadedDescent = getLeadedDescent();
		
		//get the dimensions of the text
		bounds.width = getTextWidth();
		bounds.height = getTextHeight();
	}
	
	/**
	 * Instantiate a platfor specific text rendering element
	 */
	private function initNativeTextElement(text:String, fontManager:FontManager, computedStyle:ComputedStyle):Void
	{
		//create and store a native text element, using the styles of the 
		//TextRenderer which created this TextLineBox
		_nativeElement = fontManager.createNativeTextElement(text, computedStyle);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render the text using the graphic context as canvas.
	 * 
	 * TODO 4 : should also render text decoration, or should
	 * be on TextRenderer ?
	 */
	override public function render(graphicContext:NativeElement, forceRendering:Bool):Void
	{
		#if (flash9 || nme)
		_nativeElement.x = bounds.x + elementRenderer.globalContainingBlockOrigin.x;
		_nativeElement.y = bounds.y + elementRenderer.globalContainingBlockOrigin.y  + leadedAscent;
		var containerGraphicContext:flash.display.DisplayObjectContainer = cast(graphicContext);
		containerGraphicContext.addChild(_nativeElement);
		#end
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function getBaselineOffset(parentBaselineOffset:Float, parentXHeight:Float):Float
	{
		return parentBaselineOffset;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Overriden as this is the text line box
	 */
	override public function isText():Bool
	{
		return true;
	}
	
	/**
	 * Overriden as a text line box is never
	 * considered absolutely positioned
	 */
	override public function isAbsolutelyPositioned():Bool
	{
		return false;
	}
	
	/**
	 * Overriden as a text line box never establishes
	 * a new formatting context
	 */
	override public function establishesNewFormattingContext():Bool
	{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the leaded ascent of the generated text
	 */
	private function getLeadedAscent():Float 
	{
		var ascent:Float = _fontMetrics.ascent;
		var descent:Float = _fontMetrics.descent;	
	
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = elementRenderer.coreStyle.computedStyle.lineHeight - (ascent + descent);

		//apply leading to the ascent and descent
		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedAscent;
	}
	
	/**
	 * Return the leaded descent of the generated text
	 */
	private function getLeadedDescent():Float 
	{
		var ascent:Float = _fontMetrics.ascent;
		var descent:Float = _fontMetrics.descent;	
	
		var leading:Float = elementRenderer.coreStyle.computedStyle.lineHeight - (ascent + descent);

		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedDescent;
	}
	
	/**
	 * return the generated text width
	 */
	private function getTextWidth():Float
	{
		//here the text is a space character
		if (isSpace() == true)
		{
			//for a space, the width of a space is retrieved from the font metrics, plus the letter spacing
			//which also apply to space and the word spacing which aplies only to text
			var computedStyle:ComputedStyle = elementRenderer.coreStyle.computedStyle;
			return _fontMetrics.spaceWidth + computedStyle.letterSpacing + computedStyle.wordSpacing;
		}
		//in this case the text is a word, the text width is returned, it already
		//contains the letter spacing which was applied when the text was rendered
		//by the flash text engine
		else
		{
			#if (flash9 || nme)
			return untyped _nativeElement.textWidth ;
			#else
			return 0.0;
			#end
		}	
	}

	/**
	 * return the generated text height, which is
	 * the addition of the leaded ascent and descent
	 * 
	 * TODO 4 : should be line height in some cases
	 */
	private function getTextHeight():Float
	{
		return leadedAscent + leadedDescent;
	}
	
	
}