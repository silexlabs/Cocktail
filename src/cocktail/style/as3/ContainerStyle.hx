/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.as3;

import cocktail.domElement.DOMElement;
import cocktail.domElement.TextFragmentDOMElement;
import cocktail.style.abstract.AbstractContainerStyle;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import cocktail.unit.UnitManager;
import flash.text.engine.CFFHinting;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;
import cocktail.unit.UnitData;
import haxe.Log;

/**
 * This is the Flash AS3 implementation of the ContainerStyle.
 * 
 * This class implement the Flash specific text fragment creation
 * using the flash text engine introduced in flash player 10.
 * 
 * It's purpose is to create as many TextFragmentDOMElement as necessary
 * to render every TextElement of the styledContainerDOMElement.
 * 
 * It also constructs the font metrics object using Flash text engine
 * font metrics
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerStyle extends AbstractContainerStyle
{
	/**
	 * Generic font families names
	 */
	private static inline var SERIF_GENERIC_FONT_NAME:String = "_serif";
	private static inline var SANS_SERIF_GENERIC_FONT_NAME:String = "_sans";
	private static inline var MONOSPACE_GENERIC_FONT_NAME:String = "_typewriter";
	
	/**
	 * The flash text block used to create the 
	 * flash text line that will be wrapped in
	 * TextFragmentDOMElement
	 */
	private var _textBlock:TextBlock;
	
	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		//apply flash specific generic font name
		_serifFontName = SERIF_GENERIC_FONT_NAME;
	   _sansSerifFontName = SANS_SERIF_GENERIC_FONT_NAME;
	   _monospaceFontName = MONOSPACE_GENERIC_FONT_NAME;
		
	   _textBlock = new TextBlock();
	   
		super(domElement);
	}
	
	/////////////////////////////////
	// OVERRIDEN METHODS
	////////////////////////////////
	
	/**
	 * Overriden to create flash text lines. Uses the flash text engine introduced
	 * in flash player 10
	 */
	override private function doCreateTextFragment(text:String):TextFragmentDOMElement
	{
		//get a flash TextElement used as the model for a flash textBlock
		_textBlock.content = getNativeTextElement(text);
		
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
		var textLine:TextLine = _textBlock.createTextLine(null, 10000, 0.0, true);
		
		//help free memory
		_textBlock.releaseLineCreationData();
		
		//In the flash text engine,
		//create lines are linked to the 
		//textBlock that created them, it
		//is useful to recreate text lines
		//efficiently
		//It is of no use in Cocktail
		//so we break the bond to free memory
		if (_textBlock.firstLine != null)
		{	
			_textBlock.releaseLines(_textBlock.firstLine, _textBlock.lastLine );
		}
	
		//wrap the flash text line in a TextFragmentDOMElement
		return new TextFragmentDOMElement(textLine, this);
	
	}
	
	/**
	 * Returns a font metrics data object created using font metrics
	 * provided by the flash text engine. The font metrics are 
	 * processed using the styles of the ContainerDOMElement. The
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
			fontDescription.fontName = getFontFamilyValue(this._fontFamily);
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
			var xHeight:Int = getXHeight(elementFormat);
			
			_fontMetrics = {
				fontSize:_computedStyle.fontSize,
				ascent:Math.round(leadedAscent),
				descent:Math.round(leadedDescent),
				xHeight:xHeight ,
				superscriptOffset:Math.round(elementFormat.getFontMetrics().superscriptOffset),
				subscriptOffset:Math.round(elementFormat.getFontMetrics().subscriptOffset),
				underlineOffset:Math.round(elementFormat.getFontMetrics().underlineOffset)
			};
		}
		
		return _fontMetrics;
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Takes a String of text and create a flash TextElement
	 * from it which is used as a model by a flash textBlock
	 * to create flash textLines. The TextElement contains
	 * both a string of text and the display properties
	 * to apply to it when rendered. The styles of the
	 * ContainerDOMElement will be converted to work
	 * with the flash TextElement
	 */
	private function getNativeTextElement(text:String):TextElement
	{
		//apply transformation to the text (toUppercase, toLowercase...)
		//before using it as a model
		var transformedText:String = applyTextTransform(text);
		
		var textElement:TextElement = new TextElement(transformedText);
		
		//create a flash element format object and set its
		//attribute to match the styles defined in this ContainerDOMElement
		var elementFormat:ElementFormat = new ElementFormat();
		
		//set font size
		elementFormat.fontSize = _computedStyle.fontSize;
		
		//set font weight, style (italique or not), and family
		var fontDescription:FontDescription = new FontDescription(); 
		fontDescription.fontWeight = getNativeFontWeight(_computedStyle.fontWeight);
		fontDescription.fontPosture = getNativeFontPosture(_computedStyle.fontStyle);
		fontDescription.fontName = getFontFamilyValue(_computedStyle.fontFamily);
		elementFormat.fontDescription = fontDescription;
		
		//color of the text
		elementFormat.color = _computedStyle.color;
	
		//normal or small caps
		elementFormat.typographicCase = getNativeFontVariant(_computedStyle.fontVariant);
		
		//space between each letter
		elementFormat.trackingRight = _computedStyle.letterSpacing;
		
		
		//set the element format as the text element
		//element format
		textElement.elementFormat = elementFormat;
		
		return textElement;
	}
	
	/////////////////////////////////
	// PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * Return a flash FontWeight object from
	 * the font weight style of the ContainerDOMElement
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
	 * Return a flash FontPosture object from
	 * the fontStyle style of the ContainerDOMElement
	 */
	private function getNativeFontPosture(fontStyle:FontStyleStyleValue):FontPosture
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
	 * the font variant style of the ContainerDOMElement
	 */
	private function getNativeFontVariant(fontVariant:FontVariantStyleValue):TypographicCase
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
	 * return the x height of the font which is equal to 
	 * the height of a lower-case 'x'
	 */
	private function getXHeight(elementFormat:ElementFormat):Int
	{
		var textBlock:TextBlock = new TextBlock(new TextElement("x", elementFormat));
		
		return Math.round(textBlock.createTextLine(null, 10000).textHeight);
	}
	

}