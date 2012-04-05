/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.renderer;

import core.NativeElement;
import core.Style;
import core.dom.DOMData;
import haxe.Log;

/**
 * Renders a text
 * 
 * @author Yannick DOMINGUEZ
 */
class TextRenderer extends ElementRenderer
{

	/**
	 * The text token (word, space, tab...)
	 * used to generate the TextRenderer
	 */
	private var _textToken:TextTokenValue;
	
	private var _nativeElement:NativeElement;
	
	/**
	 * Class constructor. Set the width and height bounds
	 * to those of the generated text
	 * 
	 * @param htmlElement the generated text
	 */
	public function new(style:Style, nativeElement:NativeElement, textToken:TextTokenValue) 
	{
		_textToken = textToken;
		
		_nativeElement = nativeElement;
		
		super(style);
		
		#if (flash9 || nme)
		_bounds.width = getOffsetWidth();
		_bounds.height = getOffsetHeight();
		#end
	}
	
	
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	override public function dispose():Void
	{
		super.dispose();
		
		_textToken = null;
		_nativeElement = null;
	}
	
	/**
	 * Renders the text using runtime specific API and return
	 * the text NativeElement
	 */
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];
		#if flash9
		_nativeElement.x = _bounds.x;
		_nativeElement.y = _bounds.y;
		#elseif nme
		_nativeElement.x = _bounds.x;
		_nativeElement.y = _bounds.y - (_style.fontMetrics.ascent + _style.fontMetrics.descent);
		#end
		
		ret.push(_nativeElement);
		
		return ret;
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
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
			return _style.fontMetrics.spaceWidth + _style.computedStyle.letterSpacing + _style.computedStyle.wordSpacing;
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
		
		var ascent:Float =  _style.fontMetrics.ascent;
		var descent:Float = _style.fontMetrics.descent;
		
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = _style.computedStyle.lineHeight - (ascent + descent);
		
		//apply leading to the ascent and descent
		var leadedAscent:Float = (ascent + leading/2);
		var leadedDescent:Float = (descent + leading / 2);
		
		return Math.round(leadedAscent + leadedDescent);
		
		return 50;
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC HELPER METHODS
	////////////////////////////////
	
	override public function isFloat():Bool
	{
		return false;
	}
	
	override public function isPositioned():Bool
	{
		return false;
	}
	
	override public function isText():Bool
	{
		return true;
	}
	
	override public function isSpace():Bool
	{
		var isSpace:Bool;
		
		switch (_textToken)
		{
			case TextTokenValue.space:
				isSpace = true;
				
			default:
				isSpace = false;
		}
		
		return isSpace;
	}
	
	override public function isLineFeed():Bool
	{
		var isLineFeed:Bool;
		
		switch (_textToken)
		{
			case TextTokenValue.lineFeed:
				isLineFeed = true;
				
			default:
				isLineFeed = false;
		}
		
		return isLineFeed;
	}
	
	override public function isTab():Bool
	{
		var isTab:Bool;
		
		switch (_textToken)
		{
			case TextTokenValue.tab:
				isTab = true;
				
			default:
				isTab = false;
		}
		
		return isTab;
	}
	
	
	
}