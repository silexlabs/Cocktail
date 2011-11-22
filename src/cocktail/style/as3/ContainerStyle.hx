/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.as3;

import cocktail.domElement.DOMElement;
import cocktail.domElement.TextLineDOMElement;
import cocktail.domElement.TextNode;
import cocktail.style.abstract.AbstractContainerStyle;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import flash.text.engine.CFFHinting;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;
import haxe.Log;



/**
 * ...
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
	

	
	public function new(domElement:DOMElement) 
	{
		_serifFontName = SERIF_GENERIC_FONT_NAME;
	
	   _sansSerifFontName = SANS_SERIF_GENERIC_FONT_NAME;
	
	   _monospaceFontName = MONOSPACE_GENERIC_FONT_NAME;
		
		super(domElement);
	}
	
	/////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	////////////////////////////////
	
	override private function getFontMetrics():FontMetrics
	{
		var elementFormat:ElementFormat = new ElementFormat();
		
		var fontDescription:FontDescription = new FontDescription(getFontFamilyValue(this._fontFamily));


		var fontWeightValue:FontWeight;
		
		switch (_computedStyle.fontWeight)
		{
			case bold:
				fontWeightValue = FontWeight.BOLD;
				
			case normal:
				fontWeightValue = FontWeight.NORMAL;
		}
		
		fontDescription.fontWeight = fontWeightValue;
		
		elementFormat.fontDescription = fontDescription;
	
		
		elementFormat.fontSize = this._computedStyle.fontSize;

		var ascent:Float = Math.abs(elementFormat.getFontMetrics().emBox.top);
		var descent:Float = Math.abs(elementFormat.getFontMetrics().emBox.bottom);
		
		var leading:Float = _computedStyle.lineHeight - (ascent + descent);
		
		var leadedAscent:Float = ascent + leading/2;
		var leadedDescent:Float = descent + leading/2;
		
		return {
			ascent:Math.round(leadedAscent),
			descent:Math.round(leadedDescent),
			xHeight:0,
			superscriptOffset:0,
			subscriptOffset:0,
			underlineOffset:Math.round(elementFormat.getFontMetrics().underlineOffset)
		};
	}
	
	/**
	 * Overriden to create flash text lines. Uses the flash text engine introduced
	 * in flash player 10
	 */
	override private function doCreateTextLine(text:String):TextLineDOMElement
	{

		var textBlock:TextBlock = new TextBlock(getTextElement(text));
		
		//create a native flash text line
		var textLine:TextLine = textBlock.createTextLine(null, 10000, 0.0, true);

		textBlock.releaseLineCreationData();
		if (textBlock.firstLine != null)
		{	
			textBlock.releaseLines(textBlock.firstLine, textBlock.lastLine );
		}
	
		
		return new TextLineDOMElement(textLine, this);
	
	}
	
	override private function getNativeText(textNode:TextNode):String
	{
		return textNode.text;
	}
	
	/**
	 * Takes a flash TextElement which is a model for text containing a
	 * string of text and objects to format the text when rendered, and
	 * parametrise its text formatting using the styles of the ContainerDOMElement
	 * @param	textElement a textElement with a default flash element format
	 * @return a textElement with a flash element format matching the styles
	 * of the ContainerDOMElement
	 */
	private function getTextElement(text:String):TextElement
	{
		var textElement:TextElement = new TextElement(text);
		
		//create a flash element format object and set its
		//attribute to match the styles defined in this ContainerDOMElement
		var elementFormat:ElementFormat = new ElementFormat();
		elementFormat.fontSize = _computedStyle.fontSize;
		
		var fontDescription:FontDescription = new FontDescription();
		
		var fontWeightValue:FontWeight;
		
		switch (_computedStyle.fontWeight)
		{
			case bold:
				fontWeightValue = FontWeight.BOLD;
				
			case normal:
				fontWeightValue = FontWeight.NORMAL;
		}
		
		var fontPostureValue:FontPosture;
		
		switch (_computedStyle.fontStyle)
		{
			case normal:
				fontPostureValue = FontPosture.NORMAL;
				
			case italic:
				fontPostureValue = FontPosture.ITALIC;
		}
		
		fontDescription.fontWeight = fontWeightValue;
		fontDescription.fontPosture = fontPostureValue;
		fontDescription.fontName = getFontFamilyValue(_computedStyle.fontFamily);
		
		elementFormat.fontDescription = fontDescription;
		
		elementFormat.color = _computedStyle.color;
		
	
		
		var typographicCase:TypographicCase;
		
		switch (_computedStyle.fontVariant)
		{
			case normal:
				typographicCase = TypographicCase.DEFAULT;
				
			case smallCaps:
				typographicCase = TypographicCase.CAPS_AND_SMALL_CAPS;
				
		}
		
		
		elementFormat.typographicCase = typographicCase;
		

		elementFormat.trackingRight = _computedStyle.letterSpacing;
		
		textElement.replaceText(0, textElement.text.length, applyTextTransform(textElement.text));
		
		
		//set the element format as the text element
		//element format
		textElement.elementFormat = elementFormat;
		
		return textElement;
	}
	
	
	

}