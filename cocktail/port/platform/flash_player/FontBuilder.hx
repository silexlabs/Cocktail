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
import cocktail.core.css.CSSValueConverter;
import cocktail.port.base.FontBuilderBase;
import cocktail.port.Bindings;

import flash.text.TextField;
import flash.text.TextFormat;
import cocktail.core.font.FontData;
import flash.text.TextFieldAutoSize;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSCascadeData;
import cocktail.css.CSSStyleData;

/**
 * This class measure font metrics and draw native flash text using 
 * the flash text field
 */
class FontBuilder extends FontBuilderBase
{
	/**
	 * holds CSS and flash generic serif names
	 */
	private static inline var SERIF_CSS_FONT_NAME:String = "SERIF";
	private static inline var SERIF_FLASH_FONT_NAME:String = "_serif";
	
	/**
	 * holds CSS and flash generig sans serif names
	 */
	private static inline var SANS_SERIF_CSS_FONT_NAME:String = "SANS-SERIF";
	private static inline var SANS_SERIF_FLASH_FONT_NAME:String = "_sans";
	
	/**
	 * holds CSS and flash generic monospace names
	 */
	private static inline var MONOSPACE_CSS_FONT_NAME:String = "MONOSPACE";
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
		textField.text = "X";
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.size = fontSize;
		textFormat.font = fontFamily;
		textField.setTextFormat(textFormat);
		
		var fontMetricsVO:FontMetricsVO = new FontMetricsVO(fontSize, 0, 0, 0, 0, 0, 0, 0, 0);
		
		setAscentAndDescent(textField, fontMetricsVO, textFormat);
		
		textField.text = "x";
		textField.setTextFormat(textFormat);
		fontMetricsVO.xHeight = textField.textHeight;
	
		textField.text = " ";
		textField.setTextFormat(textFormat);
		#if flash
		fontMetricsVO.spaceWidth = textField.textWidth;
		//for openfl textWidth don't seem to work when only space
		#else
		fontMetricsVO.spaceWidth = textField.width;
		#end
		
		return fontMetricsVO;
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
		
		
		#if openfl
		//when building with openfl/nme, font might have been embedded with 
		//the project, so use embedded font if present
		#if nme	if (nme.Assets.hasFont(fontFamily)) #end
		{
			var embeddedFont:flash.text.Font = openfl.Assets.getFont(fontFamily);
			if (embeddedFont != null)
			{
				fontFamily = embeddedFont.fontName;
				//must explicitely activate embedded fonts
				textField.embedFonts = true;
			}
		}
		#end
		
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
	 * find the ascent and descent of the measured font and set it
	 * on the font metrics object
	 * @param	textField
	 * @param	fontMetrics
	 */
	private function setAscentAndDescent(textField:TextField, fontMetrics:FontMetricsVO, textFormat:TextFormat):Void
	{
		var textLineMetrics:flash.text.TextLineMetrics = textField.getLineMetrics(0);
		fontMetrics.ascent = textLineMetrics.ascent;
		fontMetrics.descent = textLineMetrics.descent;
	}
	
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
