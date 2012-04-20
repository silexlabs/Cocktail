/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.renderer;

import cocktail.core.dom.Text;
import cocktail.core.NativeElement;
import cocktail.core.dom.DOMData;
import cocktail.core.style.CoreStyle;
import haxe.Log;

/**
 * Renders a text
 * 
 * @author Yannick DOMINGUEZ
 */
class TextRenderer extends ElementRenderer
{
	/**
	 * An array where each item contains a text token,
	 * representing the kind of text contained (a word,
	 * a space, a tab...) and the corresponding TextFragmentHTMLElement,
	 * created when the text is rendered
	 * 
	 * TODO : should be on text renderer instead
	 * Text should create its own TextRenderer ?
	 */
	private var _textFragments:Array<TextFragmentData>;
	
	/**
	 * Class constructor.
	 */
	public function new(style:CoreStyle, text:Text) 
	{
		super(style);
		
		#if (flash9 || nme)
		//_bounds.width = getOffsetWidth();
		//_bounds.height = getOffsetHeight();
		#end
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Renders the text using runtime specific API and return
	 * the text NativeElement
	 */
	override public function render():Array<NativeElement>
	{
		
		var ret:Array<NativeElement> = [];/**
		#if flash9
		_nativeElement.x = _bounds.x;
		_nativeElement.y = _bounds.y;
		#elseif nme
		_nativeElement.x = _bounds.x;
		_nativeElement.y = _bounds.y - (_coreStyle.fontMetrics.ascent + _coreStyle.fontMetrics.descent);
		#end
		
		ret.push(_nativeElement);
		*/
		return ret;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Remove a reference to every generated
	 * TextRenderer. Used when the content
	 * of the TextElement changes or when the style
	 * of its ContainerHTMLElement changes
	 */
	public function reset():Void
	{
		for (i in 0..._textFragments.length)
		{
			_textFragments[i].textRenderer = null;
		}
	}
	
	/**
	 * Takes a string of plain text and create an array of text
	 * token from it
	 */
	public function getTextFragments(text:String):Array<TextFragmentData>
	{
		//create only the first time or each time
		//the text content is changed
		if (_textFragments.length == 0)
		{	
			_textFragments = doGetTextFragments(text);
		}
		
		return _textFragments;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually convert a text into an array
	 * of text token. Each item of the array
	 * also has a null TextFragmentHTMLElement,
	 * as it is only created once the text is laid
	 * out
	 * 
	 * TODO : fix
	 */
	private static function doGetTextFragments(text:String):Array<TextFragmentData>
	{
		var textFragments:Array<TextFragmentData> = new Array<TextFragmentData>();

		var textFragment:String = null;
		
		var i:Int = 0;
		
		//Loop in all the text charachters
		while (i < text.length)
		{
			if (text.charAt(i) == "\\")
			{
				if (i <text.length - 1)
				{
					//if a line feed is found
					if (text.charAt(i + 1) == "n")
					{
						if (textFragment != null)
						{
							//push the current word into the returned array
							textFragments.push(insertTextToken(word(textFragment)));
							textFragment = null;
						}
						//then push a line feed
						textFragments.push(insertTextToken(lineFeed));
						i++;
					}
					//if a tab is found
					else if (text.charAt(i + 1) == "t")
					{
						if (textFragment != null)
						{
							//push the word into the returned array
							textFragments.push(insertTextToken(word(textFragment)));
							textFragment = null;
						}
						//then push a tab
						textFragments.push(insertTextToken(TextTokenValue.tab));
						i++;
					}
				}
			}
			
			//If the character is a space
			if (StringTools.isSpace(text, i) == true)
			{
				
				//If a word was being formed by concatenating
				//characters
				if (textFragment != null)
				{
					//push the word into the returned array
					textFragments.push(insertTextToken(word(textFragment)));
					textFragment = null;
				}
				
				//push the space in the returned array
				textFragments.push(insertTextToken(TextTokenValue.space));
			}
			//else the charachter belongs to a word
			//and is added to the word which is being
			//concatenated
			else
			{
				if (textFragment == null)
				{
					textFragment = "";
				}
				textFragment += text.charAt(i);
			}
			
			i++;
		}
		
		//push the remaining word if text doesn't end with a space
		//or control character
		if (textFragment != null)
		{
			textFragments.push(insertTextToken(word(textFragment)));
		}

		return textFragments;
	}
	
	/**
	 * Utils method wrapping a textToken into a textFragmentData
	 * with a null textFragmentHTMLElement
	 */
	private static function insertTextToken(textToken:TextTokenValue):TextFragmentData
	{
		return { textToken:textToken, textRenderer:null };
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Create and return a TextRenderer from a TextFragmentData
	 */
	private function createTextRendererFromTextFragment(textFragment:TextFragmentData):TextRenderer
	{
		//the text of the created TextRenderer
		var text:String;
		
		switch(textFragment.textToken)
		{
			case word(value):
				text = value;
		
			case space:
				text = " ";
				
			//TODO : implement tab and line feed	
			case tab:
				text = "";
				
			case lineFeed:
				text = "";
		}
		
		var textRenderer:TextRenderer = getTextRenderer(textFragment, text);
		
		return textRenderer;
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
			return _coreStyle.fontMetrics.spaceWidth + _coreStyle.computedStyle.letterSpacing + _coreStyle.computedStyle.wordSpacing;
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
		
		var ascent:Float =  _coreStyle.fontMetrics.ascent;
		var descent:Float = _coreStyle.fontMetrics.descent;
		
		//the leading is an extra height to apply equally to the ascent
		//and the descent when laying out lines of text
		var leading:Float = _coreStyle.computedStyle.lineHeight - (ascent + descent);
		
		//apply leading to the ascent and descent
		var leadedAscent:Float = (ascent + leading/2);
		var leadedDescent:Float = (descent + leading / 2);
		
		return Math.round(leadedAscent + leadedDescent);
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
	
	
	
}