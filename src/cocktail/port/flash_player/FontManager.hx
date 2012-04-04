/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.NativeElement;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;
import flash.text.Font;
import haxe.Log;
import cocktail.core.font.AbstractFontManager;
import cocktail.core.font.FontData;
import cocktail.core.style.StyleData;
import haxe.remoting.FlashJsConnection;


/**
 * This class is the manager for system and embedded fonts. Use it to load new fonts, or to check if a system font is supported, etc.
 * This is the implementation for the Flash AVM2 runtime. A font in Flash is embeded in a .swf
 * file. It is loaded like a library. The font can be used for a text, just set the HTML style attribute to "font-family=MyFontName"
 *
 * download flex sdk
 * > http://opensource.adobe.com/wiki/display/flexsdk/Flex+SDK
 *
 * create an embedded font with flex sdk
 * > http://rodneypillay.wordpress.com/2010/05/18/fontswf-utility-in-flex-sdk-4/
 * 
 * @author lexa
 */
class FontManager extends AbstractFontManager
{
	/**
	 * used to hold a runtime specific default
	 * font name for serif font
	 * 
	 * TODO : update doc
	 */
	private static inline var SERIF_GENERIC_FONT_NAME:String = "serif";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "sans";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font (like courier)
	 */
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "typewriter";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";
	
	/**
	 * The constructor is private as this class is meant to be accessed through static public method.
	 */
	override public function new() 
	{
		super();
	}
	/** 
	 * Returns a list of fonts which have been loaded.
	 */
	override public function getEmbeddedFonts() : Array<FontData>
	{
		// get a list of all the fonts
		var fontsArray : Array<flash.text.Font> = flash.text.Font.enumerateFonts(false);
		var resultArray : Array<FontData> = new Array();
		var idx : Int;

		// keep only the system fonts
		for (idx in 0...fontsArray.length)
				resultArray.push({name : fontsArray[idx].fontName, url : null, type : unknown});

		// returns result
		return resultArray;
	}
	/** 
	 * Returns a list of fonts which are installed on the current runtime.
	 */
	override public function getSystemFonts() : Array<FontData>
	{
		// get a list of all the fonts
		var fontsArray : Array<flash.text.Font> = flash.text.Font.enumerateFonts(true);
		var resultArray : Array<FontData> = new Array();
		var idx : Int;

		// keep only the system fonts
		for (idx in 0...fontsArray.length)
			if (fontsArray[idx].fontType == flash.text.FontType.DEVICE)
				resultArray.push({name : fontsArray[idx].fontName, url : null, type : system});

		// returns result
		return resultArray;
	}
	
	/**
	 * Returns a font metrics data object created using font metrics
	 * provided by the flash text engine. The font metrics are 
	 * processed using the styles of the HTMLElement. The
	 * font metrics are provided for a given font at a given size
	 */
	override public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsData
	{
		//the flash object used to access flash font metrics
		var elementFormat:ElementFormat = new ElementFormat();
	
		//set font name
		var fontDescription:FontDescription = new FontDescription();
		fontDescription.fontName = fontFamily;
		elementFormat.fontDescription = fontDescription;
		
		//set font size used for the font metrics 
		elementFormat.fontSize = fontSize;
		
		//get the ascent (height above the baseline) and descent (height
		//below the baseline) from the flash font metrics
		var ascent:Float = Math.abs(elementFormat.getFontMetrics().emBox.top);
		var descent:Float = Math.abs(elementFormat.getFontMetrics().emBox.bottom);
		
		//get the x height (the height of a lower-case "x")
		var xHeight:Int = getXHeight(elementFormat.clone());
	
		var spaceWidth:Int = getSpaceWidth(elementFormat.clone());
		
		var fontMetrics:FontMetricsData = {
			fontSize:fontSize,
			ascent:Math.round(ascent),
			descent:Math.round(descent),
			xHeight:xHeight,
			spaceWidth:spaceWidth,
			superscriptOffset:Math.round(elementFormat.getFontMetrics().superscriptOffset),
			subscriptOffset:Math.round(elementFormat.getFontMetrics().subscriptOffset),
			underlineOffset:Math.round(elementFormat.getFontMetrics().underlineOffset)
		};
		
		return fontMetrics;
	}
	
	/**
	 * return the x height of the font which is equal to 
	 * the height of a lower-case 'x'.
	 */
	private function getXHeight(elementFormat:ElementFormat):Int
	{
		var textBlock:TextBlock = new TextBlock();
		
		textBlock.content = new TextElement("x", elementFormat);
		var textLine:TextLine = textBlock.createTextLine(null, 10000);
		var descent:Float = textLine.descent;
		var top:Float = Math.abs(textLine.getAtomBounds(0).top);
		return Math.round(top - descent);
	}
	
	/**
	 * Return the width of a space character for the given font
	 * at the given size
	 */
	private function getSpaceWidth(elementFormat:ElementFormat):Int
	{
		var textBlock:TextBlock = new TextBlock();
		
		textBlock.content = new TextElement(" ", elementFormat);
		
		return Math.round(textBlock.createTextLine(null, 10000, 0.0, true).getAtomBounds(0).width);
	}
	
	/**
	 * Overriden to create flash text lines. Uses the flash text engine introduced
	 * in flash player 10
	 */
	override public function createNativeTextElement(text:String, computedStyle:ComputedStyleData):NativeElement
	{
		var textBlock:TextBlock = new TextBlock();
		
		//get a flash TextElement used as the model for a flash textBlock
		textBlock.content = getNativeTextElement(text, computedStyle);
		
		//create a native flash text line
		//set the width of the line to create to an 
		//'infinite' value (10000) because in Cocktail
		//text is rendered word by word whereas the
		//standard way of using the flash text engine
		//is to create line by line. Creating text content
		//word by word allow for more control and allows some
		//use case that wouldn't be possible otherwise such
		//as setting the word spacing.
		//Setting an infinite value for the line width assures that
		//all the text content (only 1 word) will be created.
		//
		//The 'fitSomething' parameters is alos set to true
		//otherwise, when creating only a space charcter, no
		//flash text line would be created
		var text:TextLine = textBlock.createTextLine(null, 10000, 0.0, true);
		
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
		
		return text;
	}	
	
	/**
	 * Takes a String of text and create a flash TextElement
	 * from it which is used as a model by a flash textBlock
	 * to create flash textLines. The TextElement contains
	 * both a string of text and the display properties
	 * to apply to it when rendered. The styles of the
	 * ContainerHTMLElement will be converted to work
	 * with the flash TextElement
	 */
	private function getNativeTextElement(text:String, computedStyle:ComputedStyleData):TextElement
	{
		//apply transformation to the text (toUppercase, toLowercase...)
		//before using it as a model
		var transformedText:String = applyTextTransform(text, computedStyle.textTransform);
		
		var textElement:TextElement = new TextElement(transformedText);
		
		//create a flash element format object and set its
		//attribute to match the styles defined in this ContainerHTMLElement
		var elementFormat:ElementFormat = new ElementFormat();
		
		//set font size
		elementFormat.fontSize = computedStyle.fontSize;
		
		//set font weight, style (italique or not), and family
		var fontDescription:FontDescription = new FontDescription(); 
		fontDescription.fontWeight = getNativeFontWeight(computedStyle.fontWeight);
		fontDescription.fontPosture = getNativeFontPosture(computedStyle.fontStyle);
		fontDescription.fontName = getNativeFontFamily(computedStyle.fontFamily);
		elementFormat.fontDescription = fontDescription;
		
		//color of the text
		elementFormat.color = computedStyle.color.color;
	
		//normal or small caps
		elementFormat.typographicCase = getNativeFontVariant(computedStyle.fontVariant);
		
		//space between each letter
		elementFormat.trackingRight = computedStyle.letterSpacing;
		
		
		//set the element format as the text element
		//element format
		textElement.elementFormat = elementFormat;
		
		return textElement;
	}
	
	/////////////////////////////////
	// PRIVATE STATIC HELPER METHODS
	////////////////////////////////
	
	/**
	 * Return a flash FontPosture object from
	 * the fontStyle style of the ContainerHTMLElement
	 */
	private static function getNativeFontPosture(fontStyle:FontStyle):FontPosture
	{
		var nativeFontPosture:FontPosture;
		
		switch (fontStyle)
		{
			case normal:
				nativeFontPosture = FontPosture.NORMAL;
				
			case italic:
				nativeFontPosture = FontPosture.ITALIC;
		}
		
		return nativeFontPosture;
	}
	
	/**
	 * Return a flash TypographicCase object from
	 * the font variant style of the ContainerHTMLElement
	 */
	private static function getNativeFontVariant(fontVariant:FontVariant):TypographicCase
	{
		var nativeFontVariant:TypographicCase;
		
		switch (fontVariant)
		{
			case normal:
				nativeFontVariant = TypographicCase.DEFAULT;
				
			case smallCaps:
				nativeFontVariant = TypographicCase.CAPS_AND_SMALL_CAPS;		
		}
		
		return nativeFontVariant;
	}
	
	/**
	 * Takes the array containing every font to apply to the
	 * text (ordered by priority, the first available font being
	 * used) and return a comma separated list containing the ordered
	 * font names.
	 * @param	value an array which may contain any combination of generic
	 * font family name and font family name
	 * 
	 * TODO : update doc
	 * 
	 * @return a comma separated list of font, generally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	private static function getNativeFontFamily(value:Array<String>):String
	{
		var fontFamily:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String = value[i];
			
			switch (fontName)
			{
				case SERIF_GENERIC_FONT_NAME:
					fontName = SERIF_FLASH_FONT_NAME;
					
				case SANS_SERIF_GENERIC_FONT_NAME:
					fontName = SANS_SERIF_FLASH_FONT_NAME;
					
				case MONOSPACE_GENERIC_FONT_NAME:
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
	
	/**
	 * Return a flash FontWeight object from
	 * the font weight style of the HTMLElement
	 */
	private function getNativeFontWeight(fontWeight:FontWeight):flash.text.engine.FontWeight
	{
		var nativeFontWeight:flash.text.engine.FontWeight;
		
		switch (fontWeight)
		{
			case bold:
				nativeFontWeight = flash.text.engine.FontWeight.BOLD;
				
			case normal:
				nativeFontWeight = flash.text.engine.FontWeight.NORMAL;
				
			case bolder:
				nativeFontWeight = flash.text.engine.FontWeight.BOLD;
				
			case lighter:
				nativeFontWeight = flash.text.engine.FontWeight.NORMAL;
				
			case css100, css200, css300, css400:
				nativeFontWeight = flash.text.engine.FontWeight.NORMAL;
				
			case css500, css600, css700, css800, css900:
				nativeFontWeight = flash.text.engine.FontWeight.BOLD;
		}
		
		return nativeFontWeight;
	}
	
	
	//TODO : implement in nme
	
	#if nme
	override private function getFontMetrics():FontMetricsData
	{

		//create the font metrics object only if null,
		//else it is already cached
		if (_fontMetrics == null)
		{
			var textField:TextField = new TextField();
			textField.autoSize = TextFieldAutoSize.LEFT;
			
			var textFormat:TextFormat = new TextFormat();
			textFormat.size = _computedStyle.fontSize;
			textFormat.font = getNativeFontFamily(this._fontFamily);
			
			textField.setTextFormat(textFormat);
			
			textField.text = "x";
			
			var ascent:Float =  textField.textHeight / 2;
			Log.trace(ascent);
			textField.text = ",";
			
			var descent:Float = textField.textHeight / 2;
			
			textField.text = "x";
			
			var xHeight:Int = Math.round(textField.textHeight);
		
			textField.text = "M";
			var spaceWidth:Int = Math.round(textField.textWidth);
			
			
			_fontMetrics = {
				fontSize:_computedStyle.fontSize,
				ascent:Math.round(ascent),
				descent:Math.round(descent),
				xHeight:xHeight,
				spaceWidth:spaceWidth,
				superscriptOffset:1,
				subscriptOffset:1,
				underlineOffset:1
			};
		}
		
		return _fontMetrics;
		
	}
	
	/**
	 * redefined as in nme only one font is supported
	 */
	private function getNativeFontFamily(value:Array<String>):String
	{
		var fontFamily:String = "";
		
		var fontName:String = value[0];
		
		switch (fontName)
		{
			case SERIF_GENERIC_FONT_NAME:
				fontName = SERIF_FLASH_FONT_NAME;
				
			case SANS_SERIF_GENERIC_FONT_NAME:
				fontName = SANS_SERIF_FLASH_FONT_NAME;
				
			case MONOSPACE_GENERIC_FONT_NAME:
				fontName = MONOSPACE_FLASH_FONT_NAME;
		}
		
		return fontName;
	}
	
		
	override private function doCreateTextRenderer(text:String, textToken:TextTokenValue):TextRenderer
	{
		
		text = applyTextTransform(text, _computedStyle.textTransform);
		
		var textField:flash.text.TextField = new flash.text.TextField();
		textField.text = text;
		textField.selectable = false;
		textField.autoSize = TextFieldAutoSize.LEFT;
		textField.setTextFormat(getTextFormat());
		
		var textRenderer:TextRenderer = new TextRenderer(this, textField, textToken);

		//wrap the flash text line in a TextRenderer
		return textRenderer;
		

	}	
	
	private function getTextFormat():TextFormat
	{
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.font = getNativeFontFamily(_computedStyle.fontFamily);
		
		textFormat.letterSpacing = _computedStyle.letterSpacing;
		textFormat.size = _computedStyle.fontSize;
		
		var bold:Bool;
		
		switch (_computedStyle.fontWeight)
		{
			case lighter, FontWeight.normal,
			css100, css200, css300, css400:
				bold = false;
				
			case FontWeight.bold, bolder, css500, css600,
			css700, css800, css900:
				bold = true;
		}
		
		textFormat.bold = bold;
		textFormat.italic = _computedStyle.fontStyle == FontStyle.italic;
		
		textFormat.letterSpacing = _computedStyle.letterSpacing;
		
		textFormat.color = _computedStyle.color.color;
		return textFormat;
		
	}
	
	#end
	
}
