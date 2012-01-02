/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import cocktailCore.domElement.abstract.AbstractTextFragmentDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.StyleData;
import cocktailCore.style.Style;
import haxe.Log;

/**
 * This is the Flash AS3 implementation of the TextFragmentDOMElement
 * 
 * It uses the native flash text engine to return the width of the
 * created flash text line.
 * 
 * @author Yannick DOMINGUEZ
 */
class TextFragmentDOMElement extends AbstractTextFragmentDOMElement
{

	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement, style);
	}
	
	/**
	 * The offset width for a text fragment is the width of its
	 * text
	 */
	override private function getOffsetWidth():Int
	{
		//in this case the text fragment is a space, as the flash
		//text engine doesn't account for the width of space
		if (untyped _nativeElement.textWidth == 0)
		{
			//for a space, the width of a space is retrieved from the font metrics, plus the letter spacing
			//which also apply to space and the word spacing which aplies only to text
			return style.fontMetrics.spaceWidth + _style.computedStyle.letterSpacing + _style.computedStyle.wordSpacing;
		}
		//in this case the text fragment is a word, the text width is returned, it already
		//contains the letter spacing which was applied when the text was rendered
		else
		{
			return untyped _nativeElement.textWidth ;
		}				
	}

	/**
	 * the height of a text fragment is the addition
	 * of its leaded ascent and leaded descent
	 */
	override private function getOffsetHeight():Int
	{
		var ascent:Float =  style.fontMetrics.ascent;
		var descent:Float = style.fontMetrics.descent;
		
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = this._style.computedStyle.lineHeight - (ascent + descent);
		
		//apply leading to the ascent and descent
		var leadedAscent:Float = (ascent + leading/2);
		var leadedDescent:Float = (descent + leading / 2);
		
		return Math.round(leadedAscent + leadedDescent);
	}
	

	
}