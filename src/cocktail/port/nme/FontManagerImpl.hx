/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.nme;

import cocktail.core.font.AbstractFontManagerImpl;
import cocktail.port.NativeElement;
import cocktail.core.style.ComputedStyle;
import flash.text.TextField;
import flash.text.TextFormat;
import haxe.Log;
import cocktail.core.font.FontData;
import flash.text.TextFieldAutoSize;
import cocktail.core.style.StyleData;

/**
 * This is the nme port for the FontManager
 * 
 * @author Yannick DOMINGUEZ
 */
class FontManagerImpl extends AbstractFontManagerImpl
{
	/**
	 * used to hold a runtime specific default
	 * font name for serif font
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
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden public virtual methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return font metrics for a given font
	 * at a given size using a Flash text field
	 * to measure it
	 */
	override public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsData
	{

		var textField:TextField = new TextField();
		textField.autoSize = TextFieldAutoSize.LEFT;
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.size = fontSize;
		textFormat.font = fontFamily;
		
		textField.setTextFormat(textFormat);
		
		textField.text = "x";
		
		var ascent:Float =  textField.textHeight / 2;

		textField.text = ",";
		
		var descent:Float = textField.textHeight / 2;
		
		textField.text = "x";
		
		var xHeight:Float = textField.textHeight;
	
		textField.text = "M";
		var spaceWidth:Float = textField.textWidth;
		
		var fontMetrics:FontMetricsData = {
			fontSize:fontSize,
			ascent:ascent,
			descent:descent,
			xHeight:xHeight,
			spaceWidth:spaceWidth,
			superscriptOffset:1.0,
			subscriptOffset:1.0,
			underlineOffset:1.0
		};
		
		return fontMetrics;
	}
	
	/**
	 * Create and return a flash text field
	 */
	override public function createNativeTextElement(text:String, computedStyle:ComputedStyle):NativeElement
	{
		text = applyTextTransform(text, computedStyle.textTransform);
		var textField:flash.text.TextField = new flash.text.TextField();
		textField.text = text;
		textField.selectable = false;
		textField.autoSize = TextFieldAutoSize.LEFT;
		textField.setTextFormat(getTextFormat(computedStyle));

		return textField;
		

	}	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	 * Return a flash TextFormat object, to be
	 * used on the created Text Field
	 */
	private function getTextFormat(computedStyle:ComputedStyle):TextFormat
	{
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.font = getNativeFontFamily(computedStyle.fontFamily);
		
		textFormat.letterSpacing = computedStyle.letterSpacing;
		textFormat.size = computedStyle.fontSize;
		
		var bold:Bool;
		
		switch (computedStyle.fontWeight)
		{
			case lighter, FontWeight.normal,
			css100, css200, css300, css400:
				bold = false;
				
			case FontWeight.bold, bolder, css500, css600,
			css700, css800, css900:
				bold = true;
		}
		
		textFormat.bold = bold;
		textFormat.italic = computedStyle.fontStyle == FontStyle.italic;
		
		textFormat.letterSpacing = computedStyle.letterSpacing;
		
		textFormat.color = computedStyle.color.color;
		return textFormat;
	}
}
