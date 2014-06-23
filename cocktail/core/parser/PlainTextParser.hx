/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.parser;

import cocktail.core.parser.ParserData;
import cocktail.css.CSSStyleData;

using StringTools;

/**
 * Contains static method to parse plain text as well
 * as some text treatements
 * 
 * @author Yannick DOMINGUEZ
 */
class PlainTextParser 
{
	//states used for text parsers
	
	private static inline var COPY:Int = 0;
	
	private static inline var BUFFER:Int = 1;
	
	private static inline var AFTER_LINE_FEED:Int = 2;
	
	private static inline var CONCATENATE:Int = 3;
	
	private static inline var CAPITALIZE_STATE:Int = 4;
	
	/**
	 * class cosntructor. Private, as
	 * only static method are exposed
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TEXT PARSING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * parse plain text
	 */
	public static function parse(text:String):Array<TextToken>
	{
		var textTokens:Array<TextToken> = new Array<TextToken>();

		var textToken:String = null;
		
		//wether the last inserted token was a space
		var lastCharacterIsSpace:Bool = false;
		
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
						if (textToken != null)
						{
							//push the current word into the returned array
							textTokens.push(word(textToken));
							textToken = null;
						}
						//then push a line feed
						textTokens.push(lineFeed);
						i++;
					}
					//if a tab is found
					else if (text.charAt(i + 1) == "t")
					{
						if (textToken != null)
						{
							//push the word into the returned array
							textTokens.push(word(textToken));
							textToken = null;
						}
						//then push a tab
						textTokens.push(TextToken.tab);
						i++;
					}
				}
			}
			//If the character is a space
			else if (text.fastCodeAt(i) == ' '.code)
			{
				
				//If a word was being formed by concatenating
				//characters
				if (textToken != null)
				{
					//push the word into the returned array
					textTokens.push(word(textToken));
					textToken = null;
				}
				
				//push the space in the returned array
				textTokens.push(TextToken.space);
				lastCharacterIsSpace = true;
			}
			//else the charachter belongs to a word
			//and is added to the word which is being
			//concatenated
			else
			{
				lastCharacterIsSpace = false;
				
				if (textToken == null)
				{
					textToken = "";
				}
				textToken += text.charAt(i);
			}
			
			i++;
		}
		
		//push the remaining word if text doesn't end with a space
		//or control character
		if (textToken != null)
		{
			textTokens.push(word(textToken));
		}
		
		return textTokens;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// WHITE SPACE PROCESSING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply white space pre-processing to the string
	 * of rendered text. subsequent white space processing
	 * is applied once the line boxes have been laid out
	 */
	public static function applyWhiteSpaceProcessing(text:String, whiteSpace:CSSKeywordValue):String
	{
		switch (whiteSpace)
		{
			case NORMAL, NO_WRAP: 
				
				//flag to prevent unecessary processing
				var hasLineFeed:Bool = text.indexOf("\n") != -1;
				if (hasLineFeed == true)
				{
					text = removeControlCharactersSurroundingLineFeed(text);
					text = convertLineFeedsToSpaces(text);
				}
				
				var hasTab:Bool = text.indexOf("\t") != -1;
				if (hasTab == true)
				{
					text = convertTabToSpaces(text);
				}
				
				var hasSpace:Bool = text.indexOf(" ") != -1;
				if (hasSpace == true)
				{
					text = concatenateSpaces(text);
				}
			
			case PRE_LINE: 
				text = removeControlCharactersSurroundingLineFeed(text);
				text = convertTabToSpaces(text);
				text = concatenateSpaces(text);
				
			case PRE, PRE_WRAP:
				//TODO : If 'white-space' is set to 'pre' or 'pre-wrap', 
				//any sequence of spaces (U+0020) unbroken by an element 
				//boundary is treated as a sequence of non-breaking spaces.
				//However, for 'pre-wrap', a line breaking opportunity exists 
				//at the end of the sequence. 

			default:
		}
		
		return text;
	}
	
	/**
	 * remove all tab, carriage return, and spaces
	 * surrounding a line feed
	 */
	private static function removeControlCharactersSurroundingLineFeed(sourceText:String):String
	{
		var state:Int = COPY;
		
		var position:Int = 0;
		var c:Int = sourceText.fastCodeAt(position);
		
		//the returned cleaned text
		var outputText:String = "";
		
		//when spaces, carriage return and tabs are encountered
		//they are buffered before being added to the output string
		//to be sure that they don't surround a line feed
		var buffer:String = "";
		
		//loop in all character of the text
		while (!StringTools.isEof(c))
		{
			switch (state)
			{
				//in this state, regular charachter are copied
				//to the output string
				case COPY:
					switch(c)
					{
						//when a tab, space or carirage return encountered
						//it is buffered, as it is not yet certain that
						//it should be added to the output
						case '\t'.code, ' '.code, '\r'.code:
							buffer += sourceText.charAt(position);
							state = BUFFER;
						
						case '\n'.code:
							outputText += sourceText.charAt(position);
							state = AFTER_LINE_FEED;
							
						default:	
							outputText += sourceText.charAt(position);
					}
					
				case BUFFER:	
					switch(c)
					{
						//if buffered tab, space or carriage return
						//are followed by line feed, they are not added
						case '\n'.code:
							buffer = "";
							outputText += sourceText.charAt(position);
							state = AFTER_LINE_FEED;
							
						case '\t'.code, ' '.code, '\r'.code:
							buffer += sourceText.charAt(position);
						
						//here buffer added to output text when regular character found	
						default:
							outputText += buffer;
							buffer = "";
							outputText += sourceText.charAt(position);
							state = COPY;
					}
					
				//after a line feed, all tab, space and
				//carriage return immediately following
				//are not added to output
				case AFTER_LINE_FEED:
					switch(c)
					{
						case '\t'.code, ' '.code, '\r'.code:
							
						case '\n'.code:
							outputText += sourceText.charAt(position);
							
						default:
							outputText += sourceText.charAt(position);
							state = COPY;
					}
			}
			
			c = sourceText.fastCodeAt(++position);
		}
		
		//add last buffered charachter if text
		//ends with space tab or carriage return
		outputText += buffer;
		
		return outputText;
	}
	
	/**
	 * Concatenate spaces of text, i.e if multiple space
	 * are following ony one remains
	 * 
	 * TODO : should be aware wether last charachter of previous
	 * inline in rendering tree is also space, if it does it should
	 * start in state CONCATENATE
	 */
	private static function concatenateSpaces(sourceText:String):String
	{
		var state:Int = COPY;
		
		var position:Int = 0;
		var c:Int = sourceText.fastCodeAt(position);
		
		//the returned text with concatenated space
		var outputText:String = "";
		
		while (!StringTools.isEof(c))
		{
			switch (state)
			{
				//in this state copy all charachter to output until space is
				//found
				case COPY:
					switch(c)
					{
						case ' '.code:
							outputText += sourceText.charAt(position);
							state = CONCATENATE;
							
						default:
							outputText += sourceText.charAt(position);
					}
					
				//in this state omit to copy all subsequent spaces to output	
				case CONCATENATE:
					switch(c)
					{
						case ' '.code:
							
						default:
							outputText += sourceText.charAt(position);
							state = COPY;
					}
			}
			
			c = sourceText.fastCodeAt(++position);
		}
		
		return outputText;
	}
	
	/**
	 * Remove line feeds from source text
	 */
	private static function convertLineFeedsToSpaces(sourceText:String):String
	{
		var er : EReg = ~/\n/g;
		return er.replace(sourceText, " ");
	}
	
	/**
	 * Convert all tab characters into spaces
	 */
	private static function convertTabToSpaces(sourceText:String):String
	{
		var er : EReg = ~/\t/g;
		return er.replace(sourceText, " ");
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TEXT TRANSFORM METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Transform a text letters into uppercase, lowercase
	 * or capitalise them (only the first letter of each word
	 * is transformed to uppercase)
	 */
	public static function applyTextTransform(text:String, textTransform:CSSKeywordValue):String
	{
		switch (textTransform)
		{
			case UPPERCASE:
				text = text.toUpperCase();
				
			case LOWERCASE:
				text = text.toLowerCase();
				
			case CAPITALIZE:
				text = capitalizeText(text);
				
			case NONE:
				
			default:	
		}
		
		return text;
	}
	
	/**
	 * Capitalise a text (turn each word's first letter
	 * to uppercase)
	 */
	private static function capitalizeText(sourceText:String):String
	{
		var state:Int = CAPITALIZE_STATE;
		var position:Int = 0;
		var c:Int = sourceText.fastCodeAt(position);
		
		//the returned text with capitalised words
		var outputText:String = "";
		
		while (!StringTools.isEof(c))
		{
			switch (state)
			{
				//in this state copy all charachter to output until space is
				//found
				case COPY:
					switch(c)
					{
						case ' '.code:
							outputText += sourceText.charAt(position);
							state = CAPITALIZE_STATE;
							
						default:
							outputText += sourceText.charAt(position);
					}
					
				//in this state, copy all spaces until a word begins
				//and capitalize the first letter
				case CAPITALIZE_STATE:
					switch(c)
					{
						case ' '.code:
							outputText += sourceText.charAt(position);
							
						default:
							outputText += sourceText.charAt(position).toUpperCase();
							state = COPY;
					}
			}
			
			c = sourceText.fastCodeAt(++position);
		}
		
		return outputText;
	}
	
}
