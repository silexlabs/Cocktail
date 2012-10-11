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
import cocktail.core.css.CoreStyle;
import cocktail.core.layout.formatter.FormattingContext;
import cocktail.core.font.FontManager;
import haxe.Log;
import cocktail.core.geom.GeomData;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;
import cocktail.core.font.FontData;

/**
 * Renders a run of text by creating as many text line box
 * as necessary for each word/space. Also in charge of separating
 * the source text into an array of word, space, tab...
 * 
 * @author Yannick DOMINGUEZ
 */
class TextRenderer extends InvalidatingElementRenderer
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
	
	/**
	 * The current text line box rendering
	 * is invalid and text needs to be re rendered
	 */
	private var _textNeedsRendering:Bool;
	
	/**
	 * flag determining if the text token must
	 * be recreated, for instance after the value
	 * of the Text dom node changed
	 * 
	 * TODO 2 : should add invalidation reason for this
	 */
	private var _textTokensNeedParsing:Bool;
	
	/**
	 * Class constructor.
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_text = cast(node);
		_textNeedsRendering = true;
		_textTokensNeedParsing = true;
	}
	
		
	/**
	 * Overriden, as text use the style of 
	 * its parent in the DOM tree
	 */
	override private function initCoreStyle():Void
	{
		coreStyle = domNode.parentNode.coreStyle;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When laid out, text might recreate its text line
	 * box if they are now invalid
	 */
	override public function layout(forceLayout:Bool):Void
	{	
		if (_textNeedsRendering == true)
		{
			createTextLines();
			_textNeedsRendering = false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC INVALIDATION METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When invalidated, a TextRenderer set its text flag so that
	 * the text is re-rendered for next layout.
	 * Text rendering is invalidated for instance when its color changes
	 */
	override public function invalidate():Void
	{
		_textNeedsRendering = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC LAYOUT METHODS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Overriden as the bounds of a TextRenderer is formed
	 * by the bounds of its formatted text line boxes
	 */
	override public function updateBounds():Void
	{
		getLineBoxesBounds(lineBoxes, bounds);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
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
	
	/**
	 * Apply white space pre-processing tothe string
	 * of rendered text
	 * 
	 * TODO 2 : this is only a partial implementation 
	 * 
	 * TODO 1 : the whole white-space processing should be re-factored in this way :
		 * - when the update line box method is called, all line boxes are
		 * created. For text, the white space processing is applied before creating
		 * text line boxes
		 * - a line box tree is created afterwards (another method
		 * in HTMLDocument ?) (or should intead use rendering tree
		 * as line box tree will be modified during layout ?). It is used to further clean the line boxes,
		 * like for instance remove spaces following other spaces
		 * - during layout, when each line is laid out, apply final white space
		 * processing, like removing the spaces at the beggining and end
	 * 
	 */
	private function applyWhiteSpace(text:String, whiteSpace:CSSKeywordValue):String
	{
		switch (whiteSpace)
		{
			case NORMAL, NO_WRAP: // remove new lines, spaces and tab

			var er1 : EReg = ~/[ \t]+/;
			//TODO 3 : at this point, CR should have been normalised as LF
			var er2 : EReg = ~/\r+/g;
			var er3 : EReg = ~/\n+/g;
			var er4 : EReg = ~/\s+/g;
			
			text = er4.replace(er3.replace(er2.replace( er1.replace( text , " " ) , " " ), " "), " ");
			
			case PRE_LINE: // remove spaces

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
	private function applyTextTransform(text:String, textTransform:CSSKeywordValue):String
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
		if (_textTokensNeedParsing == true)
		{
			var processedText:String = _text.nodeValue;
			//apply white space processing, for instance to collapse
			//sequences of white spaces if needed
			processedText = applyWhiteSpace(processedText, coreStyle.getKeyword(coreStyle.whiteSpace));
	
			processedText = applyTextTransform(processedText, coreStyle.getKeyword(coreStyle.textTransform));
			
			_textTokens = doGetTextTokens(processedText);
		}
		
		lineBoxes = [];
		
		var fontMetrics:FontMetricsVO = coreStyle.fontMetrics;
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
	private function createTextLineBoxFromTextToken(textToken:TextToken, fontMetrics:FontMetricsVO, fontManager:FontManager):LineBox
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
}