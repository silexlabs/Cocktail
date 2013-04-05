/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

import cocktail.core.css.CSSValueConverter;
import cocktail.core.dom.Node;
import cocktail.core.dom.Text;
import cocktail.core.geom.GeomUtils;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.graphics.TextDrawer;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.linebox.InlineBox;
import cocktail.core.linebox.SpaceInlineBox;
import cocktail.core.linebox.TextInlineBox;
import cocktail.core.renderer.RendererData;
import cocktail.core.css.CoreStyle;
import cocktail.core.font.FontManager;
import haxe.Log;
import cocktail.core.geom.GeomData;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;
import cocktail.core.font.FontData;
import haxe.Stack;
using StringTools;

/**
 * Renders a run of text by creating as many text line box
 * as necessary for each word/space. Also in charge of separating
 * the source text into an array of word, space, tab...
 * 
 * @author Yannick DOMINGUEZ
 */
class TextRenderer extends InvalidatingElementRenderer
{
	//states used for text parsers
	
	private static inline var COPY:Int = 0;
	
	private static inline var BUFFER:Int = 1;
	
	private static inline var AFTER_LINE_FEED:Int = 2;
	
	private static inline var CONCATENATE:Int = 3;
	
	private static inline var CAPITALIZE_STATE:Int = 4;
	
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
	 */
	private var _textTokensNeedParsing:Bool;
	
	/**
	 * Wether an underline text decoration should
	 * apply the text inline box of this element
	 */
	private var _hasUnderline:Bool;
	
	/**
	 * Same for overline
	 */
	private var _hasOverline:Bool;
	
	/**
	 * Same for line through
	 */
	private var _hasLineThrough:Bool;
	
	/**
	 * Same for blink
	 */ 
	private var _hasBlink:Bool;
	
	/**
	 * A reusable rect used during rendering
	 */
	private static var _intersectBounds:RectangleVO = new RectangleVO();

	/**
	 * Class constructor.
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_text = cast(node);
		_textNeedsRendering = true;
		_textTokensNeedParsing = true;
		
		_hasUnderline = false;
		_hasOverline = false;
		_hasLineThrough = false;
		_hasBlink = false;
		
		isText = true;
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
	// OVERRIDEN PUBLIC RENDERING METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * update text elements used 
	 * for rendering
	 */
	override public function updateText():Void
	{
		var child:ElementRenderer = firstChild;
		while (child != null)
		{
			child.updateText();
			child = child.nextSibling;
		}
		
		if (_textNeedsRendering == true)
		{
			createTextLines();
			_textNeedsRendering = false;
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Render all the text inline boxes of
	 * this text renderer with the 
	 * provided graphics context
	 */
	override public function render(graphicContext:GraphicsContext, clipRect:RectangleVO, scrollOffset:PointVO):Void
	{	
		//check wether text is supposed to be rendered
		if (coreStyle.isVisible == false)
		{
			return;
		}
		
		//check wether text will be displayed on screen
		_intersectBounds.x = hitTestingBounds.x;
		_intersectBounds.y = hitTestingBounds.y;
		_intersectBounds.width = hitTestingBounds.width;
		_intersectBounds.height = hitTestingBounds.height;
		
		
		GeomUtils.intersectBounds(_intersectBounds, clipRect, _intersectBounds);
		if (_intersectBounds.width == 0 || _intersectBounds.height == 0)
		{
			return;
		}
		
		TextDrawer.draw(graphicContext, this, _hasUnderline, _hasOverline, _hasLineThrough, _hasBlink, scrollOffset, clipRect);
	}
	
	/**
	 * Store which text decorations apply to the text inline
	 * boxes of this element
	 */
	override public function updateTextDecorations(inheritUnderline:Bool, 
	inheritOverline:Bool, inheritLineThrough:Bool, inheritBlink:Bool):Void
	{
		_hasUnderline = inheritUnderline;
		_hasOverline = inheritOverline;
		_hasLineThrough = inheritLineThrough;
		_hasBlink = inheritBlink;
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
	
	/**
	 * Apply white space pre-processing to the string
	 * of rendered text. subsequent white space processing
	 * is applied once the line boxes have been laid out
	 */
	private function applyWhiteSpaceProcessing(text:String, whiteSpace:CSSKeywordValue):String
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
	private function removeControlCharactersSurroundingLineFeed(sourceText:String):String
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
		while (!c.isEOF())
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
	private function concatenateSpaces(sourceText:String):String
	{
		var state:Int = COPY;
		
		var position:Int = 0;
		var c:Int = sourceText.fastCodeAt(position);
		
		//the returned text with concatenated space
		var outputText:String = "";
		
		while (!c.isEOF())
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
	private function convertLineFeedsToSpaces(sourceText:String):String
	{
		var er : EReg = ~/\n/g;
		return er.replace(sourceText, " ");
	}
	
	/**
	 * Convert all tab characters into spaces
	 */
	private function convertTabToSpaces(sourceText:String):String
	{
		var er : EReg = ~/\t/g;
		return er.replace(sourceText, " ");
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
	private function capitalizeText(sourceText:String):String
	{
		var state:Int = CAPITALIZE_STATE;
		var position:Int = 0;
		var c:Int = sourceText.fastCodeAt(position);
		
		//the returned text with capitalised words
		var outputText:String = "";
		
		while (!c.isEOF())
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
			processedText = applyWhiteSpaceProcessing(processedText, coreStyle.getKeyword(coreStyle.whiteSpace));
	
			processedText = applyTextTransform(processedText, coreStyle.getKeyword(coreStyle.textTransform));
			
			_textTokens = doGetTextTokens(processedText);
		}
		
		inlineBoxes = [];
		
		var fontMetrics:FontMetricsVO = coreStyle.fontMetrics;
		
		var htmlDocument:HTMLDocument = cast(domNode.ownerDocument);
		var fontManager:FontManager = htmlDocument.fontManager;
		
		//return the font family for the text inline box as a string, formatted for
		//the native platform
		var fontFamily:String = fontManager.getNativeFontFamily(CSSValueConverter.getFontFamilyAsStringArray(coreStyle.fontFamily));
		
		//the width of a space is retrieved from the font metrics, plus the letter spacing
		//which also apply to space and the word spacing which applies only to space
		var letterSpacing:Float = coreStyle.usedValues.letterSpacing;
		var wordSpacing:Float = coreStyle.getAbsoluteLength(coreStyle.wordSpacing);
		var spaceWidth:Float = fontMetrics.spaceWidth + letterSpacing + wordSpacing;
		
		//get the leading for the inline boxes
		var leadedAscent:Float = getLeadedAscent();
		var leadedDescent:Float = getLeadedDescent();
		
		var length:Int = _textTokens.length;
		for (i in 0...length)
		{
			//create and store the inline boxes
			inlineBoxes.push(createInlineBoxFromTextToken(_textTokens[i], leadedAscent, leadedDescent, fontMetrics, fontManager, fontFamily, spaceWidth));
		}
	}
	
	/**
	 * Create and return an inline box from a text token
	 */
	private function createInlineBoxFromTextToken(textToken:TextToken, leadedAscent:Float, leadedDescent:Float, fontMetrics:FontMetricsVO, fontManager:FontManager, fontFamily:String, spaceWidth:Float):InlineBox
	{
		switch(textToken)
		{
			case word(value):
				return new TextInlineBox(this, leadedAscent, leadedDescent, value, fontMetrics, fontManager, fontFamily);
		
			case space:
				return new SpaceInlineBox(this, leadedAscent, leadedDescent, spaceWidth);
				
			//TODO 5 : implement tab and line feed	
			case tab:
				return new TextInlineBox(this, leadedAscent, leadedDescent, "", fontMetrics, fontManager, fontFamily);
				
			case lineFeed:
				return new TextInlineBox(this, leadedAscent, leadedDescent, "", fontMetrics, fontManager, fontFamily);
		}
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
	
	override public function isInlineLevel():Bool
	{
		return true;
	}
}