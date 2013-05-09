/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.nme;

import cocktail.core.css.CoreStyle;
import cocktail.core.font.AbstractFontManagerImpl;
import cocktail.core.css.CSSValueConverter;
import cocktail.port.NativeTextElement;

import flash.text.TextField;
import flash.text.TextFormat;
import haxe.Log;
import cocktail.core.font.FontData;
import flash.text.TextFieldAutoSize;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;

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
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "sans-serif";
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
	override public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsVO
	{

		var textField:TextField = new TextField();
		textField.autoSize = TextFieldAutoSize.LEFT;
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.size = fontSize;
		textFormat.font = fontFamily;
		
		textField.setTextFormat(textFormat);
		
		textField.text = "x";
		
		var ascent:Float =  textField.height / 2;

		textField.text = ",";
		
		var descent:Float = textField.height / 2;
		
		textField.text = "x";
		
		var xHeight:Float = textField.height;
	
		textField.text = " ";
		var spaceWidth:Float = textField.width;
		
		return new FontMetricsVO(fontSize, ascent, descent, xHeight, 1.0, 1.0, 1.0, spaceWidth);
	}
	
	/**
	 * Create and return a flash text field
	 */
	override public function createNativeTextElement(text:String, style:CoreStyle, fontFamily:String):NativeTextElement
	{
		var textField:flash.text.TextField = new flash.text.TextField();
		textField.text = text;
		textField.selectable = false;
		textField.autoSize = TextFieldAutoSize.LEFT;
		textField.setTextFormat(getTextFormat(style, fontFamily));

		return textField;
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return a flash TextFormat object, to be
	 * used on the created Text Field
	 */
	private function getTextFormat(style:CoreStyle, fontFamily:String):TextFormat
	{
		
		var usedValues:UsedValuesVO = style.usedValues;
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.font = fontFamily;
		
		textFormat.letterSpacing = usedValues.letterSpacing;
		textFormat.size = style.getAbsoluteLength(style.fontSize);
		
		var bold:Bool = false;
		
		switch (style.fontWeight)
		{
			case KEYWORD(value):
				switch(value)
				{
					case BOLD, BOLDER:
						bold = true;
						
					default:	
				}
				
			case INTEGER(value):
				if (value > 400)
				{
					bold = true;
				}
				
			default:	
		}
		
		textFormat.bold = bold;
		
		var fontStyle:CSSKeywordValue = style.getKeyword(style.fontStyle);
		
		textFormat.italic = fontStyle == ITALIC || fontStyle == OBLIQUE;
		
		textFormat.color = usedValues.color.color;
		return textFormat;
	}
}
