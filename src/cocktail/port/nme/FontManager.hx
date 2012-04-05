/*
This project is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.nme;

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
 * TODO : doc + make it work
 * 
 * @author lexa
 */
class FontManager extends AbstractFontManager
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
	
	override public function getFontMetrics(fontFamily:String, fontSize:Float):FontMetricsData
	{

		//create the font metrics object only if null,
		//else it is already cached
		if (_fontMetrics == null)
		{
			var textField:TextField = new TextField();
			textField.autoSize = TextFieldAutoSize.LEFT;
			
			var textFormat:TextFormat = new TextFormat();
			textFormat.size = _computedStyle.fontSize;
			//only one font is supported in nme
			textFormat.font = getNativeFontFamily(this._fontFamily[0]);
			
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
	
	override public function createNativeTextElement(text:String, computedStyle:ComputedStyleData):NativeElement
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private methods, font rendering and measure
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getTextFormat():TextFormat
	{
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.font = getNativeFontFamily(_computedStyle.fontFamily[0]);
		
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
	
	
}
