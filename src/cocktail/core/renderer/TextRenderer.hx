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
	
	
	private var _text:Text;
	
	/**
	 * Class constructor.
	 */
	public function new(style:CoreStyle, text:Text) 
	{
		super(style);
		
		_text = text;
		
		init();
		
		
	}
	
	private function init():Void
	{
		_textFragments = doGetTextFragments(_text.nodeValue);
		
		for (i in 0..._textFragments.length)
		{
			lineBoxes.push(createTextLineBoxFromTextFragment(_textFragments[i]));
		}
		
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
	private function createTextLineBoxFromTextFragment(textFragment:TextFragmentData):TextLineBox
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
		
		var textLineBox:TextLineBox = new TextLineBox(this, text);
		
		return textLineBox;
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