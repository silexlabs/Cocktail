package cocktail.textElement.abstract;

import cocktail.textElement.NativeTextElement;
import cocktail.textElement.TextElementData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractTextElement 
{

	
	private var _text:NativeTextElement;
	public var text(getText, never):NativeTextElement;
	
	private var _textFragments:Array<TextFragmentData>;
	
	public function new(text:String) 
	{
		
	}
	
	public function reset():Void
	{
		for (i in 0..._textFragments.length)
		{
			_textFragments[i].textFragmentDOMElement = null;
		}
	}
	
	public function getTextFragments(text:String):Array<TextFragmentData>
	{
		if (_textFragments == null)
		{	
			_textFragments = doGetTextFragments(text);
		}
			return _textFragments;

	}
	
	public function getNativeText():String
	{
		return null;
	}
	
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
					if (text.charAt(i + 1) != null)
					{
						if (text.charAt(i + 1) == "n")
						{
							if (textFragment != null)
							{
								//push the word into the returned array
								textFragments.push(insertTextToken(word(textFragment)));
								textFragment = null;
							}
							textFragments.push(insertTextToken(lineFeed));
							i ++;
						}
						else if (text.charAt(i + 1) == "t")
						{
							if (textFragment != null)
							{
								//push the word into the returned array
								textFragments.push(insertTextToken(word(textFragment)));
								textFragment = null;
							}
							textFragments.push(insertTextToken(TextTokenValue.tab));
							i ++;
						}
					}
				}
				
				//If the charachter is a space
				else if (StringTools.isSpace(text, i) == true)
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
			if (textFragment != null)
			{
				textFragments.push(insertTextToken(word(textFragment)));
			}
		
		return textFragments;
	}
	
	private static function insertTextToken(textToken:TextTokenValue):TextFragmentData
	{
		return { textToken:textToken, textFragmentDOMElement:null };
	}
	
	private function getText():NativeTextElement
	{
		return _text;
	}
	
}