/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.nme;

import core.geom.Matrix;
import core.geom.GeomData;
import core.nativeElement.NativeElement;
import core.HTMLElement;
import core.style.AbstractStyle;
import core.style.StyleData;
import flash.text.TextFieldAutoSize;

import haxe.Log;

import flash.text.TextField;
import flash.text.TextFormat;

/**
 * This is the Flash AS3 implementation of the Style object.
 * 
 * It constructs the font metrics object using Flash text engine
 * font metrics. It uses the style object font size and font family
 * value to determine the font metrics
 * 
 * @author Yannick DOMINGUEZ
 */
class Style extends AbstractStyle
{
	
	/**
	 * used to hold a runtime specific default
	 * font name for serif font
	 */
	private static inline var SERIF_GENERIC_FONT_NAME:String = "_serif";
	
	/**
	 * used to hold a runtime specific default
	 * font name for sans-serif font
	 */
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "_sans";
	
	/**
	 * used to hold a runtime specific default
	 * font name for monospace font (like courier)
	 */
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "_typewriter";
	
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}

	override private function getFontMetricsData():FontMetricsData
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
	private function getNativeFontFamily(value:Array<FontFamily>):String
	{
		var fontFamily:String = "";
		

		var fontName:String;
		
		switch (value[0])
		{
			case FontFamily.familyName(name):
				fontName = name;
			
			case FontFamily.genericFamily(genericName):
				switch (genericName)
				{
					case GenericFontFamily.serif:
						fontName = SERIF_GENERIC_FONT_NAME;
					
					case GenericFontFamily.sansSerif:
						fontName = SANS_SERIF_GENERIC_FONT_NAME;
						
					case GenericFontFamily.monospace:
						fontName = MONOSPACE_GENERIC_FONT_NAME;
				}
		}
		
		
		
		return fontName;
	}
}