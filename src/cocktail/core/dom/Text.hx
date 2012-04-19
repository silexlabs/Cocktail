/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.dom;

import cocktail.core.event.Event;
import cocktail.core.event.KeyboardEvent;
import cocktail.core.event.MouseEvent;
import cocktail.core.html.HTMLElement;
import cocktail.core.NativeElement;
import cocktail.core.style.adapter.Style;

import cocktail.core.dom.DOMData;
import cocktail.core.style.StyleData;

/**
 * The Text interface inherits from CharacterData and represents the textual
 * content (termed character data in XML) of an Element or Attr. 
 * If there is no markup inside an element's content, the text is contained 
 * in a single object implementing the Text interface that is the only child of 
 * the element. If there is markup, it is parsed into the information items
 * (elements, comments, etc.) and Text nodes that form the list of children of
 * the element.
 * 
 * When a document is first made available via the DOM,
 * there is only one Text node for each block of text. Users may create
 * adjacent Text nodes that represent the contents of a given element
 * without any intervening markup, but should be aware that there is no way
 * to represent the separations between these nodes in XML or HTML, so they
 * will not (in general) persist between DOM editing sessions. 
 * The Node.normalize() method merges any such adjacent Text objects into a
 * single node for each block of text.
 * 
 * No lexical check is done on the content of a Text node and, depending
 * on its position in the document, some characters must be escaped 
 * during serialization using character references; e.g. the characters "<&" if
 * the textual content is part of an element or of an attribute, the character
 * sequence "]]>" when part of an element, the quotation mark character " or 
 * the apostrophe character ' when part of an attribute.
 * 
 * @author Yannick DOMINGUEZ
 */
class Text extends CharacterData
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
	 * class constructor
	 * @param	text the wrapped by this TextElement
	 */
	public function new() 
	{
		super();
		_textFragments = new Array<TextFragmentData>();
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeValue():String 
	{
		return _data;
	}
	
	override private function set_nodeValue(value:String):String 
	{
		return data = value;
	}
}