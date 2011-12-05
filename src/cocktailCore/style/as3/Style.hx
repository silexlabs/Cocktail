/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.as3;

import cocktail.domElement.DOMElement;
import cocktailCore.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import cocktailCore.style.StyleData;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TypographicCase;
import haxe.Log;

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
	
	/**
	 * The flash text block used to create the 
	 * flash text line that will be wrapped in
	 * TextFragmentDOMElement
	 */
	private var _textBlock:TextBlock;
	
	
	public function new(domElement:DOMElement) 
	{
	   _textBlock = new TextBlock();
		
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC DIMENSION AND POSITION METHODS
	// apply and retrieve the properties from the native flash DisplayObject
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function applyComputedX(domElement:DOMElement, x:Int):Void
	{
		domElement.nativeElement.x = x;
	}
	
	override public function applyComputedY(domElement:DOMElement, y:Int):Void
	{
		domElement.nativeElement.y = y;
	}
	
	override public function applyComputedWidth(domElement:DOMElement, width:Int):Void
	{
		domElement.nativeElement.width = width;
	}
	
	override public function applyComputedHeight(domElement:DOMElement, height:Int):Void
	{
		domElement.nativeElement.height = height;
	}
	
	override public function getComputedX(domElement:DOMElement):Int
	{
		return Math.round(domElement.nativeElement.x);
	}
	
	override public function getComputedY(domElement:DOMElement):Int
	{
		return Math.round(domElement.nativeElement.y);
	}
	
	override public function getComputedWidth(domElement:DOMElement):Int
	{
		return Math.round(domElement.nativeElement.width);
	}
	
	override public function getComputedHeight(domElement:DOMElement):Int
	{
		return Math.round(domElement.nativeElement.height);
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Returns a font metrics data object created using font metrics
	 * provided by the flash text engine. The font metrics are 
	 * processed using the styles of the DOMElement. The
	 * font metrics are provided for a given font at a given size
	 */
	override private function getFontMetricsData():FontMetricsData
	{
		//create the font metrics object only if null,
		//else it is already cached
		if (_fontMetrics == null)
		{
			//the flash object used to access flash font metrics
			var elementFormat:ElementFormat = new ElementFormat();
			
			//set font name
			var fontDescription:FontDescription = new FontDescription();
			fontDescription.fontName = getNativeFontFamily(this._fontFamily);
			elementFormat.fontDescription = fontDescription;
			
			//set font size used for the font metrics 
			elementFormat.fontSize = this._computedStyle.fontSize;
			
			//get the ascent (height above the baseline) and descent (height
			//below the baseline) from the flash font metrics
			var ascent:Float = Math.abs(elementFormat.getFontMetrics().emBox.top);
			var descent:Float = Math.abs(elementFormat.getFontMetrics().emBox.bottom);
			
			//the leading is an extra height to apply equally to the ascent
			//and the descent when laying out lines of text
			var leading:Float = _computedStyle.lineHeight - (ascent + descent);
			
			//apply leading to the ascent and descent
			var leadedAscent:Float = (ascent + leading/2) ;
			var leadedDescent:Float = (descent + leading / 2) ;
			
			//get the x height (the height of a lower-case "x")
			var xHeight:Int = getXHeight(elementFormat.clone());
			
			var spaceWidth:Int = getSpaceWidth(elementFormat.clone());
			
			_fontMetrics = {
				fontSize:_computedStyle.fontSize,
				ascent:Math.round(leadedAscent),
				descent:Math.round(leadedDescent),
				xHeight:xHeight,
				spaceWidth:spaceWidth,
				superscriptOffset:Math.round(elementFormat.getFontMetrics().superscriptOffset),
				subscriptOffset:Math.round(elementFormat.getFontMetrics().subscriptOffset),
				underlineOffset:Math.round(elementFormat.getFontMetrics().underlineOffset)
			};
		}
		
		return _fontMetrics;
	}
	
	/////////////////////////////////
	// PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * Return a flash FontWeight object from
	 * the font weight style of the DOMElement
	 */
	private function getNativeFontWeight(fontWeight:FontWeightStyleValue):FontWeight
	{
		var nativeFontWeight:FontWeight;
		
		switch (fontWeight)
		{
			case bold:
				nativeFontWeight = FontWeight.BOLD;
				
			case normal:
				nativeFontWeight = FontWeight.NORMAL;
		}
		
		return nativeFontWeight;
	}
	
	/**
	 * Takes the array containing every font to apply to the
	 * text (ordered by priority, the first available font being
	 * used) and return a comma separated list containing the ordered
	 * font names.
	 * @param	value an array which may contain any combination of generic
	 * font family name and font family name
	 * @return a comma separated list of font, generally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	private function getNativeFontFamily(value:Array<FontFamilyStyleValue>):String
	{
		var fontFamily:String = "";
		
		for (i in 0...value.length)
		{
			var fontName:String;
			
			switch (value[i])
			{
				case FontFamilyStyleValue.familyName(name):
					fontName = name;
				
				case FontFamilyStyleValue.genericFamily(genericName):
					switch (genericName)
					{
						case GenericFontFamilyValue.serif:
							fontName = SERIF_GENERIC_FONT_NAME;
						
						case GenericFontFamilyValue.sansSerif:
							fontName = SANS_SERIF_GENERIC_FONT_NAME;
							
						case GenericFontFamilyValue.monospace:
							fontName = MONOSPACE_GENERIC_FONT_NAME;
					}
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
	 * return the x height of the font which is equal to 
	 * the height of a lower-case 'x'
	 */
	private function getXHeight(elementFormat:ElementFormat):Int
	{
		_textBlock.content = new TextElement("x", elementFormat);
		
		return Math.round(_textBlock.createTextLine(null, 10000).textHeight);
	}
	
	/**
	 * Return the width of a space character for the given font
	 * at the given size
	 */
	private function getSpaceWidth(elementFormat:ElementFormat):Int
	{
		_textBlock.content = new TextElement(" ", elementFormat);
		
		return Math.round(_textBlock.createTextLine(null, 10000, 0.0, true).getAtomBounds(0).width);
	}
}