/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.textElement.abstract;

import cocktail.domElement.ContainerDOMElement;
import cocktailCore.textElement.NativeTextElement;
import cocktailCore.textElement.TextElementData;
import cocktail.style.StyleData;
import haxe.Log;

/**
 * A TextElement is an abstraction of an unformatted string of
 * plain text. A TextElement is attached to the DOM when it is
 * added to a ContainerDOMElement. The string of text is then
 * rendered using the styles of the ContainerDOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractTextElement 
{

	/**
	 * The raw text extracted from
	 * the native text element which can
	 * be get/set to change the text of
	 * this TextElement after its creation
	 */
	private var _text:String;
	public var text(getText, setText):String;
	
	/**
	 * The native text element, for instance
	 * in Flash it is just a String whereas in
	 * Js it is an HTML text node object
	 */
	private var _nativeText:NativeTextElement;
	public var nativeText(getNativeText, never):NativeTextElement;
	
	/**
	 * An array where each item contains a text token,
	 * representing the kind of text contained (a word,
	 * a space, a tab...) and the corresponding TextFragmentDOMElement,
	 * created when the text is rendered
	 */
	private var _textFragments:Array<TextFragmentData>;
	
	/**
	 * A reference to the parent ContainerDOMElement
	 * to which this TextElement is attached
	 */
	private var _parent:ContainerDOMElement;
	public var parent(getParent, setParent):ContainerDOMElement;
	
	
	/**
	 * class constructor
	 * @param	text the wrapped by this TextElement
	 */
	public function new(text:String) 
	{
		_textFragments = new Array<TextFragmentData>();
		this.text = text;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Remove a reference to every generated
	 * TextRenderer. Used when the content
	 * of the TextElement changes or when the style
	 * of its ContainerDOMElement changes
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
	// PUBLIC STATIC TEXT HELPER METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Transform a text letters into uppercase, lowercase
	 * or capitalise them (only the first letter of each word
	 * is transformed to uppercase), based on the textTransform
	 * style of this container DOMElement
	 */
	public static function applyTextTransform(text:String, textTransform:TextTransform):String
	{
		switch (textTransform)
		{
			case uppercase:
				text = text.toUpperCase();
				
			case lowercase:
				text = text.toLowerCase();
				
			case capitalize:
				text = capitalizeText(text);
				
			case none:
		}
		
		return text;
	}
	
	/**
	 * Capitalise a text (turn each first letter
	 * of a word to uppercase)
	 * 
	 * TODO : doesn't work
	 */
	public static function capitalizeText(text:String):String
	{
		var capitalizedText:String = text.charAt(0);
		
		/**
		 * loop in all charachter looking for word breaks
		 * and capitalize each word's first letter
		 */
		for (i in 1...text.length)
		{	
			if (text.charAt(i - 1) == " ")
			{
				capitalizedText += text.charAt(i).toUpperCase();
			}
			else
			{
				capitalizedText += text.charAt(i);
			}
		}
		return capitalizedText;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually convert a text into an array
	 * of text token. Each item of the array
	 * also has a null TextFragmentDOMElement,
	 * as it is only created once the text is laid
	 * out
	 * 
	 * TODO : fix
	 */
	private static function doGetTextFragments(text:String):Array<TextFragmentData>
	{
		var textFragments:Array<TextFragmentData> = new Array<TextFragmentData>();

		
		var textFragment:String = "";
		
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
	 * with a null textFragmentDOMElement
	 */
	private static function insertTextToken(textToken:TextTokenValue):TextFragmentData
	{
		return { textToken:textToken, textRenderer:null };
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setText(value:String):String
	{
		return _text = value;
	}
	
	private function getText():String
	{
		return _text;
	}
	
	private function getNativeText():NativeTextElement
	{
		return _nativeText;
	}
	
	private function setParent(value:ContainerDOMElement):ContainerDOMElement
	{
		return _parent = value;
	}
	
	private function getParent():ContainerDOMElement
	{
		return _parent;
	}
	
}