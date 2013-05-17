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
import cocktail.core.css.CSSValueConverter;
import cocktail.port.Bindings;
import cocktail.port.platform.flash_player.FlashFontBuilderBase;

import flash.text.TextField;
import flash.text.TextFormat;
import haxe.Log;
import cocktail.core.font.FontData;
import flash.text.TextFieldAutoSize;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;

/**
 * This is the nme port for the FontBuilder
 * 
 * @author Yannick DOMINGUEZ
 */
class FontBuilder extends FlashFontBuilderBase
{
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
