/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSStyleDeclaration;
import cocktail.core.css.CSSValueConverter;
import cocktail.port.base.FontBuilderBase;
import cocktail.port.Bindings;

import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontMetrics;
import flash.text.engine.FontPosture;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;
import flash.text.Font;
import cocktail.core.font.FontData;
import cocktail.core.css.CSSData;
import cocktail.core.layout.LayoutData;


/**
 * This class can measure font metrics using flash API and create native flash text elements
 * 
 * @author lexa
 */
class FontBuilder extends FontBuilderBase
{
	/**
	 * used to hold a runtime specific default
	 * font name for serif font
	 */
	private static inline var SERIF_CSS_FONT_NAME:String = "SERIF";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private static inline var SANS_SERIF_CSS_FONT_NAME:String = "SANS-SERIF";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font (like courier)
	 */
	private static inline var MONOSPACE_CSS_FONT_NAME:String = "MONOSPACE";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";
	
	/**
	 * The character used to compute the x height of a font metrics
	 */
	private static inline var X_HEIGHT_CHARACTER:String =  "x";
	
	/**
	 * The character used to compute the space width of a font metrics
	 */
	private static inline var SPACE_WIDTH_CHARACTER:String = " ";
	
	/**
	 * An instance of the flash TextBlock which
	 * is a factory to create flash text line
	 * object.
	 */
	private var _textBlock:TextBlock;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		_textBlock = new TextBlock();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns a font metrics data object created using font metrics
	 * provided by the flash text engine. The
	 * font metrics are provided for a given font at a given size
	 */
	override public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsVO
	{
		//the flash object used to access flash font metrics
		var elementFormat:ElementFormat = new ElementFormat();
	
		//set font name
		var fontDescription:FontDescription = new FontDescription();
		fontDescription.fontName = fontFamily;
		elementFormat.fontDescription = fontDescription;
		
		//set font size used for the font metrics 
		elementFormat.fontSize = fontSize;
		
		var elementFormatFontMetrics:FontMetrics = elementFormat.getFontMetrics();
		
		//get the ascent (height above the baseline) and descent (height
		//below the baseline) from the flash font metrics
		var emBox:flash.geom.Rectangle = elementFormatFontMetrics.emBox;
		var ascent:Float = Math.abs(emBox.top);
		var descent:Float = Math.abs(emBox.bottom);

		//get the x height (roughly the height of a lower-case "x")
		var xHeight:Float = getXHeight(elementFormat.clone());
	
		//get the width of a space character
		var spaceWidth:Float = getSpaceWidth(elementFormat.clone());
		
		var fontMetrics:FontMetricsVO = new FontMetricsVO(fontSize, ascent, descent, xHeight, 
		elementFormatFontMetrics.subscriptOffset, elementFormatFontMetrics.superscriptOffset,
		elementFormatFontMetrics.underlineOffset, spaceWidth);
		
		return fontMetrics;
	}
	
	/**
	 * Overriden to create flash text lines. Uses the flash text engine introduced
	 * in flash player 10
	 */
	override public function createNativeTextElement(text:String, style:CoreStyle, fontFamily:String):NativeTextElement
	{
		//get a flash TextElement, used as the model for a flash textBlock
		_textBlock.content = getNativeTextElement(text, style, fontFamily);
		
		//create a native flash text line
		//by default, the width of the line to create is an 
		//'infinite' value (100000). It is used because in Cocktail
		//text is rendered word by word whereas the
		//standard way of using the flash text engine
		//is to create line by line. Creating text content
		//word by word allow for more control and allows some
		//use case that wouldn't be possible otherwise such
		//as setting the word spacing.
		//Setting an infinite value for the line width assures that
		//all the text content, which is only 1 word as the text is parsed
		//beforehand, will be created.
		var text:TextLine = _textBlock.createTextLine();
		
		cleanTextBlock(_textBlock);
		
		return text;
	}	
	
	/**
	 * Takes the array containing every font to apply to the
	 * text (ordered by priority, the first available font being
	 * used) and return a comma separated list containing the ordered
	 * font names
	 * 
	 * @return a comma separated list of font, generally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	override public function getNativeFontFamily(value:Array<String>):String
	{
		var fontFamily:String = "";
		
		var length:Int = value.length;
		for (i in 0...length)
		{
			var fontName:String = value[i];
			
			//check if the font name is a generic CSS font name,
			//in which case, it needs to be replaced with the corresponding
			//flash generic font name
			switch (fontName.toUpperCase())
			{
				case SERIF_CSS_FONT_NAME:
					fontName = SERIF_FLASH_FONT_NAME;
					
				case SANS_SERIF_CSS_FONT_NAME:
					fontName = SANS_SERIF_FLASH_FONT_NAME;
					
				case MONOSPACE_CSS_FONT_NAME:
					fontName = MONOSPACE_FLASH_FONT_NAME;
			}
			
			fontFamily += fontName;
			
			if (i < value.length - 1)
			{
				fontFamily += ",";
			}
		}
		
		return fontFamily;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the x height of the font which is equal to 
	 * the height of a lower-case 'x'.
	 */
	private function getXHeight(elementFormat:ElementFormat):Float
	{
		_textBlock.content = new TextElement(X_HEIGHT_CHARACTER, elementFormat);
		var textLine:TextLine = _textBlock.createTextLine();
		var descent:Float = textLine.descent;
		var top:Float = Math.abs(textLine.getAtomBounds(0).top);
		
		cleanTextBlock(_textBlock);
		
		return top - descent;
	}
	
	/**
	 * Return the width of a space character for the given font
	 * at the given size
	 */
	private function getSpaceWidth(elementFormat:ElementFormat):Float
	{
		_textBlock.content = new TextElement(SPACE_WIDTH_CHARACTER, elementFormat);
		
		//note : when creating just a space, the 'fitSomethind' attribute must
		//be set to true, else no text is rendered
		var spaceWidth:Float = _textBlock.createTextLine(null, 10000, 0.0, true).getAtomBounds(0).width;
		
		cleanTextBlock(_textBlock);
		
		return spaceWidth;
	}
	
	/**
	 * Takes a String of text and create a flash TextElement
	 * from it which is used as a model by a flash textBlock
	 * to create flash textLines. The TextElement contains
	 * both a string of text and the display properties
	 * to apply to it when rendered. A computedStyle
	 * is provided to render the text
	 */
	private function getNativeTextElement(text:String, style:CoreStyle, fontFamily:String):TextElement
	{	
		var textElement:TextElement = new TextElement(text);
		
		var usedValues:UsedValuesVO = style.usedValues;
		
		//create a flash element format object and set its
		//attribute to match the styles defined in the computedStyle reference
		var elementFormat:ElementFormat = new ElementFormat();
		
		//set font size
		elementFormat.fontSize = style.getAbsoluteLength(style.fontSize);
		
		//set font weight, style (italique or not), and family
		var fontDescription:FontDescription = new FontDescription(); 
		fontDescription.fontWeight = getNativeFontWeight(style.fontWeight);
		fontDescription.fontPosture = getNativeFontPosture(style.getKeyword(style.fontStyle));
		fontDescription.fontName = fontFamily;
		elementFormat.fontDescription = fontDescription;
		
		//color of the text
		elementFormat.color = usedValues.color.color;

		//normal or small caps
		elementFormat.typographicCase = getNativeFontVariant(style.getKeyword(style.fontVariant));
		
		//space between each letter
		elementFormat.trackingRight = style.usedValues.letterSpacing;
		
		//set the element format as the text element
		//element format
		textElement.elementFormat = elementFormat;
		
		return textElement;
	}
	
	/**
	 * Return a flash FontPosture object from
	 * a FontStyle
	 */
	private function getNativeFontPosture(fontStyle:CSSKeywordValue):FontPosture
	{
		var nativeFontPosture:FontPosture;
		
		switch (fontStyle)
		{
			case NORMAL:
				nativeFontPosture = FontPosture.NORMAL;
				
			case ITALIC, OBLIQUE:
				nativeFontPosture = FontPosture.ITALIC;
				
			default:
				nativeFontPosture = null;
		}
		
		return nativeFontPosture;
	}
	
	/**
	 * Return a flash TypographicCase object from
	 * a FontVariant
	 */
	private function getNativeFontVariant(fontVariant:CSSKeywordValue):TypographicCase
	{
		var nativeFontVariant:TypographicCase;
		
		switch (fontVariant)
		{
			case NORMAL:
				nativeFontVariant = TypographicCase.DEFAULT;
				
			case SMALL_CAPS:
				nativeFontVariant = TypographicCase.CAPS_AND_SMALL_CAPS;		
				
			default:
				nativeFontVariant = null;
		}
		
		return nativeFontVariant;
	}
	
	/**
	 * Return a flash FontWeight object from
	 * a FontWeight
	 */
	private function getNativeFontWeight(fontWeight:CSSPropertyValue):flash.text.engine.FontWeight
	{
		var nativeFontWeight:flash.text.engine.FontWeight;
		
		switch (fontWeight)
		{
			case INTEGER(value):
				if (value > 400)
				{
					nativeFontWeight = flash.text.engine.FontWeight.BOLD;
				}
				else
				{
					nativeFontWeight = flash.text.engine.FontWeight.NORMAL;
				}
				
			case KEYWORD(value):
				switch(value)
				{
					case BOLD, BOLDER:
						nativeFontWeight = flash.text.engine.FontWeight.BOLD;
						
					case NORMAL, LIGHTER:	
						nativeFontWeight = flash.text.engine.FontWeight.NORMAL;
						
					default:
						nativeFontWeight = null;
				}
			
			default:
				throw 'Illegal value for font weight style';
		}
		
		return nativeFontWeight;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private helper methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Call clean up method of text block to
	 * help garbage collection
	 */
	private static function cleanTextBlock(textBlock:TextBlock):Void
	{
		//help free memory
		textBlock.releaseLineCreationData();
		
		//In the flash text engine,
		//create lines are linked to the 
		//textBlock that created them, it
		//is useful to recreate text lines
		//efficiently
		//It is of no use in Cocktail
		//so we break the bond to free memory
		if (textBlock.firstLine != null)
		{	
			textBlock.releaseLines(textBlock.firstLine, textBlock.lastLine );
		}
	}
}
