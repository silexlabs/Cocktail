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
import cocktail.geom.GeomUtils;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.graphics.TextDrawer;
import cocktail.core.html.HTMLDocument;
import cocktail.core.html.HTMLElement;
import cocktail.core.linebox.InlineBox;
import cocktail.core.linebox.SpaceInlineBox;
import cocktail.core.linebox.TextInlineBox;
import cocktail.core.parser.PlainTextParser;
import cocktail.core.parser.ParserData;
import cocktail.core.css.CoreStyle;
import cocktail.core.font.FontManager;
import cocktail.geom.GeomData;
import cocktail.core.layout.LayoutData;
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
	public function new(domNode:Node, coreStyle:CoreStyle) 
	{
		super(domNode, coreStyle);
		_text = cast(domNode);
		_textNeedsRendering = true;
		_textTokensNeedParsing = true;
		
		_hasUnderline = false;
		_hasOverline = false;
		_hasLineThrough = false;
		_hasBlink = false;
		
		isText = true;
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
			processedText = PlainTextParser.applyWhiteSpaceProcessing(processedText, coreStyle.getKeyword(coreStyle.whiteSpace));
	
			processedText = PlainTextParser.applyTextTransform(processedText, coreStyle.getKeyword(coreStyle.textTransform));
			
			_textTokens = PlainTextParser.parse(processedText);
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
