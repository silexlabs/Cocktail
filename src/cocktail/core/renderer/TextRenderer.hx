/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.linebox.LineBox;
import cocktail.core.linebox.SpaceLineBox;
import cocktail.core.linebox.TextLineBox;
import cocktail.core.renderer.RendererData;
import cocktail.core.style.CoreStyle;
import cocktail.core.style.formatter.FormattingContext;
import cocktail.core.font.FontManager;
import haxe.Log;
import cocktail.core.geom.GeomData;
import cocktail.core.style.StyleData;
import cocktail.core.font.FontData;

/**
 * Renders a run of text by creating as many text line box
 * as necessary for each word/space. Also in charge of separating
 * the source text into an array of word, space, tab...
 * 
 * @author Yannick DOMINGUEZ
 */
class TextRenderer extends ElementRenderer
{
	/**
	 * An array where each item contains a text token,
	 * representing the kind of text contained (a word,
	 * a space, a tab...). For each, a Text Line Box
	 * is created
	 */
	private var _textTokens:Array<TextToken>;
	
	/**
	 * The unedited source text
	 */
	private var _text:Text;
	
	private var _textNeedsRendering:Bool;
	
	/**
	 * Class constructor.
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_text = cast(node);
		_textNeedsRendering = true;
	}
	
	override public function layout(forceLayout:Bool):Void
	{	
		if (_textNeedsRendering == true)
		{
			createTextLines();
			_textNeedsRendering = false;
		}
	}
	
	//TODO 1 IMPORTANT : setting lineBoxes to null causes runtime error in inline formatting context,
	//need to find a better way to refresh text
	override private function invalidateText():Void
	{
		_textNeedsRendering = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually convert a text into an array
	 * of text token.
	 */
	private function doGetTextTokens(text:String):Array<TextToken>
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
			else if (StringTools.isSpace(text, i) == true)
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
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Apply white space pre-processing tothe string
	 * of rendered text
	 * 
	 * TODO 2 : this is only a partial implementation 
	 */
	private function applyWhiteSpace(text:String, whiteSpace:WhiteSpace):String
	{
		switch (whiteSpace)
		{
			case normal, nowrap: // remove new lines, spaces and tab

			var er1 : EReg = ~/[ \t]+/;
			//TODO 3 : at this point, CR should have been normalised as LF
			var er2 : EReg = ~/\r+/g;
			var er3 : EReg = ~/\n+/g;
			var er4 : EReg = ~/\s+/g;
			
			text = er4.replace(er3.replace(er2.replace( er1.replace( text , " " ) , " " ), " "), " ");
			
			case preLine: // remove spaces

			var er1 : EReg = ~/ *$^ */m;
			var er2 : EReg = ~/[ \t]+/;

			text = er2.replace( er1.replace( text , "\n" ) , " " );

			default:
		}
		
		return text;
	}
		
	/**
	 * Transform a text letters into uppercase, lowercase
	 * or capitalise them (only the first letter of each word
	 * is transformed to uppercase)
	 */
	private function applyTextTransform(text:String, textTransform:TextTransform):String
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
	 * Capitalise a text (turn each word's first letter
	 * to uppercase)
	 */
	private function capitalizeText(text:String):String
	{
		var capitalizedText:String = "";
		
		/**
		 * concatenate each character and transform
		 * the first to upper case
		 */
		for (i in 0...text.length)
		{	
			if (i == 0)
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
	
	/**
	 * Separate the source text in an array of text token
	 * and create a text line box for each one
	 * 
	 * TODO 2 : shouldn't have to recreate text token unless
	 * node value changes
	 */
	private function createTextLines():Void
	{
		var processedText:String = _text.nodeValue;
		
		//apply white space processing, for instance to collapse
		//sequences of white spaces if needed
		processedText = applyWhiteSpace(processedText, computedStyle.whiteSpace);
		
		processedText = applyTextTransform(processedText, computedStyle.textTransform);
		
		_textTokens = doGetTextTokens(processedText);
		lineBoxes = [];
		
		var fontMetrics:FontMetricsData = _coreStyle.fontMetrics;
		var fontManager:FontManager = FontManager.getInstance();
		
		var length:Int = _textTokens.length;
		for (i in 0...length)
		{
			//create and store the line boxes
			lineBoxes.push(createTextLineBoxFromTextToken(_textTokens[i], fontMetrics, fontManager));
		}
	}
	
	/**
	 * Create and return a Text line box from a text token
	 */
	private function createTextLineBoxFromTextToken(textToken:TextToken, fontMetrics:FontMetricsData, fontManager:FontManager):LineBox
	{
		//the text of the created text line box
		var text:String;
		
		var textLineBox:TextLineBox;
		
		switch(textToken)
		{
			case word(value):
				text = value;
				textLineBox = new TextLineBox(this, text, fontMetrics, fontManager);
		
			case space:
				textLineBox = new SpaceLineBox(this, fontMetrics, fontManager);
				
			//TODO 5 : implement tab and line feed	
			case tab:
				textLineBox = new TextLineBox(this, "", fontMetrics, fontManager);
				
			case lineFeed:
				textLineBox = new TextLineBox(this, "", fontMetrics, fontManager);
		}
		
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
	
	override public function isInlineLevel():Bool
	{
		return true;
	}
	
	/////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	////////////////////////////////
	
	/**
	 * Overriden as the bounds of a TextRenderer is formed
	 * by the bounds of its formatted text line boxes
	 */
	override private function get_bounds():RectangleData
	{
		var textLineBoxesBounds:Array<RectangleData> = new Array<RectangleData>();
		var length:Int = lineBoxes.length;
		for (i in 0...length)
		{
			textLineBoxesBounds.push(lineBoxes[i].bounds);
		}
		
		return getChildrenBounds(textLineBoxesBounds);
	}
}