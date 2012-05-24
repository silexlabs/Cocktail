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
 * It also create flash TextLine object using the flash text engine introduced in Flash Player 10
 * 
 * @author lexa
 */
class FontManager extends AbstractFontManager
{
	/**
	 * used to hold a runtime specific default
	 * font name for serif font
	 */
	private static inline var SERIF_CSS_FONT_NAME:String = "Serif";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private static inline var SANS_SERIF_CSS_FONT_NAME:String = "Sans-Serif";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font (like courier)
	 */
	private static inline var MONOSPACE_CSS_FONT_NAME:String = "Monospace";
	private static inline var MONOSPACE_FLASH_FONT_NAME:String = "_typewriter";
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden public virtual methods
	//////////////////////////////////////////////////////////////////////////////////////////
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden virtual methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns a font metrics data object created using font metrics
	 * provided by the flash text engine. The
	 * font metrics are provided for a given font at a given size
	 */
	override private function doGetFontMetrics(fontFamily:String, fontSize:Float):FontMetricsData
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

		//get the x height (roughly the height of a lower-case "x")
		var xHeight:Float = getXHeight(elementFormat.clone());
	
		//get the width of a space character
		var spaceWidth:Float = getSpaceWidth(elementFormat.clone());
		
		var fontMetrics:FontMetricsData = {
			fontSize:fontSize,
			ascent:ascent,
			descent:descent,
			xHeight:xHeight,
			spaceWidth:spaceWidth,
			superscriptOffset:elementFormat.getFontMetrics().superscriptOffset,
			subscriptOffset:elementFormat.getFontMetrics().subscriptOffset,
			underlineOffset:elementFormat.getFontMetrics().underlineOffset
		};
		
		return fontMetrics;
	}
	
	/**
	 * Overriden to create flash text lines. Uses the flash text engine introduced
	 * in flash player 10
	 */
	override public function createNativeTextElement(text:String, computedStyle:ComputedStyleData):NativeElement
	{
		//a TextBlock is a factory for flash TextLines
		var textBlock:TextBlock = new TextBlock();
		
		//get a flash TextElement, used as the model for a flash textBlock
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
		//all the text content, which is only 1 word as the text is parsed
		//beforehand, will be created.
		//
		//The 'fitSomething' parameters is also set to true,
		//otherwise, when creating only a space character, no
		//flash text line would be created
		//
		//TODO : this method shouldn't be called for space charachter
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the x height of the font which is equal to 
	 * the height of a lower-case 'x'.
	 */
	private function getXHeight(elementFormat:ElementFormat):Float
	{
		var textBlock:TextBlock = new TextBlock();
		
		textBlock.content = new TextElement("x", elementFormat);
		var textLine:TextLine = textBlock.createTextLine(null, 10000);
		var descent:Float = textLine.descent;
		var top:Float = Math.abs(textLine.getAtomBounds(0).top);
		return top - descent;
	}
	
	/**
	 * Return the width of a space character for the given font
	 * at the given size
	 */
	private function getSpaceWidth(elementFormat:ElementFormat):Float
	{
		var textBlock:TextBlock = new TextBlock();
		
		textBlock.content = new TextElement(" ", elementFormat);
		
		return textBlock.createTextLine(null, 10000, 0.0, true).getAtomBounds(0).width;
	}
	
	/**
	 * Takes a String of text and create a flash TextElement
	 * from it which is used as a model by a flash textBlock
	 * to create flash textLines. The TextElement contains
	 * both a string of text and the display properties
	 * to apply to it when rendered. A computedStyle
	 * is provided to render the text
	 */
	private function getNativeTextElement(text:String, computedStyle:ComputedStyleData):TextElement
	{
		//apply transformation to the text (toUppercase, toLowercase...)
		//before using it as a model
		var transformedText:String = applyTextTransform(text, computedStyle.textTransform);
		
		var textElement:TextElement = new TextElement(transformedText);
		
		//create a flash element format object and set its
		//attribute to match the styles defined in the computedStyle reference
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
	
	/**
	 * Return a flash FontPosture object from
	 * a FontStyle
	 */
	private function getNativeFontPosture(fontStyle:FontStyle):FontPosture
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
	 * a FontVariant
	 */
	private function getNativeFontVariant(fontVariant:FontVariant):TypographicCase
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
	 * font names
	 * 
	 * @return a comma separated list of font, generally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	private function getNativeFontFamily(value:Array<String>):String
	{
		var fontFamily:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String = value[i];
			
			//check if the font name is a generic CSS font name,
			//in which case, it needs to be replaced with the corresponding
			//flash generic font name
			switch (fontName.toUpperCase())
			{
				case SERIF_CSS_FONT_NAME.toUpperCase():
					fontName = SERIF_FLASH_FONT_NAME;
					
				case SANS_SERIF_CSS_FONT_NAME.toUpperCase():
					fontName = SANS_SERIF_FLASH_FONT_NAME;
					
				case MONOSPACE_CSS_FONT_NAME.toUpperCase():
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
	 * a FontWeight
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
}
