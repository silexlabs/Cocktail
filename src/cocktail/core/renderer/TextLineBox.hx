/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.FontManager;
import cocktail.core.NativeElement;

/**
 * A special kind of line box used to render text. A
 * TextRenderer will create as many text line box
 * as there is word/space in the text to render
 * 
 * @author Yannick DOMINGUEZ
 */
class TextLineBox extends LineBox
{
	/**
	 * The text renderer by this 
	 * text line box
	 */
	private var _text:String;
	
	/**
	 * class constructor
	 */
	public function new(elementRenderer:ElementRenderer, text:String) 
	{
		super(elementRenderer);
		
		_text = text;
		//create and store a native text element, using the styles of the 
		//TextRenderer which created this TextLineBox
		_nativeElement = new FontManager().createNativeTextElement(text, elementRenderer.coreStyle.computedStyle);
		
		#if (flash9 || nme)
		//get the dimensions of the text
		_bounds.width = getTextWidth();
		_bounds.height = getTextHeight();
		#end
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden as TextLineBox might be
	 * wrapping a space character
	 */
	override public function isSpace():Bool
	{
		return _text == " ";
	}
	
	/**
	 * When rendering, return the generated native
	 * text element, and set the bounds of the
	 * text line box on it
	 * 
	 * TODO : should also render text decoration, or should
	 * be on TextRenderer ?
	 */
	override public function render():Array<NativeElement>
	{
		#if flash9
		_nativeElement.x = _bounds.x + _elementRenderer.globalOrigin.x;
		_nativeElement.y = _bounds.y + _elementRenderer.globalOrigin.y + leadedAscent / 2 - leadedDescent / 2;
		#elseif nme
		_nativeElement.x = _bounds.x;
		_nativeElement.y = _bounds.y - (_coreStyle.fontMetrics.ascent + _coreStyle.fontMetrics.descent);
		#end
		
		return [_nativeElement];
	}
	
	/**
	 * Return the leaded ascent of the generated text
	 */
	override private function get_leadedAscent():Float 
	{
		var ascent:Float = _elementRenderer.coreStyle.fontMetrics.ascent;
		var descent:Float = _elementRenderer.coreStyle.fontMetrics.descent;	
	
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = _elementRenderer.coreStyle.computedStyle.lineHeight - (ascent + descent);

		//apply leading to the ascent and descent
		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedAscent;
	}
	
	/**
	 * Return the leaded descent of the generated text
	 */
	override private function get_leadedDescent():Float 
	{
		var ascent:Float = _elementRenderer.coreStyle.fontMetrics.ascent;
		var descent:Float = _elementRenderer.coreStyle.fontMetrics.descent;	
	
		var leading:Float = _elementRenderer.coreStyle.computedStyle.lineHeight - (ascent + descent);

		var leadedAscent:Float = ascent + leading / 2;
		var leadedDescent:Float = descent + leading / 2;
		
		return leadedDescent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
			return _elementRenderer.coreStyle.fontMetrics.spaceWidth + _elementRenderer.coreStyle.computedStyle.letterSpacing + _elementRenderer.coreStyle.computedStyle.wordSpacing;
		}
		//in this case the text is a word, the text width is returned, it already
		//contains the letter spacing which was applied when the text was rendered
		//by the flash text engine
		else
		{
			return untyped _nativeElement.textWidth ;
		}	
	}

	/**
	 * return the generated text height, which is
	 * the addition of the leaded ascent and descent
	 */
	private function getTextHeight():Float
	{
		return leadedAscent + leadedDescent;
	}
	
	
}