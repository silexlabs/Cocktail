package core.dom;
import core.NativeElement;

import core.dom.DOMData;
import core.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Text extends CharacterData
{
	/**
	 * The native text element, for instance
	 * in Flash it is just a String whereas in
	 * Js it is an HTML text node object
	 */
	private var _nativeElement:NativeElement;
	public var nativeElement(get_nativeElement, never):NativeElement;
	
	/**
	 * An array where each item contains a text token,
	 * representing the kind of text contained (a word,
	 * a space, a tab...) and the corresponding TextFragmentDOMElement,
	 * created when the text is rendered
	 * 
	 * TODO : should be on text renderer instead
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
	
	private function get_nativeElement():NativeElement
	{
		return _nativeElement;
	}
	
	override private function get_nodeValue():String 
	{
		return _data;
	}
	
	override private function set_nodeValue(value:String):String 
	{
		return data = value;
	}
}