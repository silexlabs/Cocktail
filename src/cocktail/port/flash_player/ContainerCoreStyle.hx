/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.HTMLElement;
import cocktail.core.style.AbstractContainerCoreStyle;
import cocktail.core.style.AbstractCoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.Text;
import cocktail.core.dom.DOMData;
import cocktail.core.unit.UnitManager;
import cocktail.core.unit.UnitData;
import flash.text.TextFieldAutoSize;

import haxe.Log;

#if flash9

import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;

#elseif nme 
import flash.text.TextFormat;

#end

/**
 * This is the Flash AS3 implementation of the ContainerStyle.
 * 
 * This class implement the Flash specific text fragment creation
 * using the flash text engine introduced in flash player 10.
 * 
 * It's purpose is to create as many TextRenderer as necessary
 * to render every TextElement of the styled ContainerHTMLElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerCoreStyle extends AbstractContainerCoreStyle
{
	/**
	 * class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}
	
	#if flash9
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Overriden to create flash text lines. Uses the flash text engine introduced
	 * in flash player 10
	 */
	override private function doCreateTextRenderer(text:String, textToken:TextTokenValue):TextRenderer
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
		var text:TextLine = _textBlock.createTextLine(null, 10000, 0.0, true);
		
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
	
		//wrap the flash text line in a TextRenderer
		return new TextRenderer(this, text, textToken);
	
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
	 * ContainerHTMLElement will be converted to work
	 * with the flash TextElement
	 */
	private function getNativeTextElement(text:String):TextElement
	{
		//apply transformation to the text (toUppercase, toLowercase...)
		//before using it as a model
		var transformedText:String = cocktail.core.dom.Text.applyTextTransform(text, _computedStyle.textTransform);
		
		var textElement:TextElement = new TextElement(transformedText);
		
		//create a flash element format object and set its
		//attribute to match the styles defined in this ContainerHTMLElement
		var elementFormat:ElementFormat = new ElementFormat();
		
		//set font size
		elementFormat.fontSize = _computedStyle.fontSize;
		
		//set font weight, style (italique or not), and family
		var fontDescription:FontDescription = new FontDescription(); 
		fontDescription.fontWeight = getNativeFontWeight(_computedStyle.fontWeight);
		fontDescription.fontPosture = getNativeFontPosture(_computedStyle.fontStyle);
		fontDescription.fontName = getNativeFontFamily(_computedStyle.fontFamily);
		elementFormat.fontDescription = fontDescription;
		
		//color of the text
		elementFormat.color = _computedStyle.color.color;
	
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
	// PRIVATE STATIC HELPER METHODS
	////////////////////////////////
	
	/**
	 * Return a flash FontPosture object from
	 * the fontStyle style of the ContainerHTMLElement
	 */
	private static function getNativeFontPosture(fontStyle:FontStyle):FontPosture
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
	 * the font variant style of the ContainerHTMLElement
	 */
	private static function getNativeFontVariant(fontVariant:FontVariant):TypographicCase
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
	
	
	#elseif nme
	
	override private function doCreateTextRenderer(text:String, textToken:TextTokenValue):TextRenderer
	{
		
		text = cocktail.core.dom.Text.applyTextTransform(text, _computedStyle.textTransform);
		
		var textField:flash.text.TextField = new flash.text.TextField();
		textField.text = text;
		textField.selectable = false;
		textField.autoSize = TextFieldAutoSize.LEFT;
		textField.setTextFormat(getTextFormat());
		
		var textRenderer:TextRenderer = new TextRenderer(this, textField, textToken);

		//wrap the flash text line in a TextRenderer
		return textRenderer;
		

	}	
	
	private function getTextFormat():TextFormat
	{
		
		var textFormat:TextFormat = new TextFormat();
		textFormat.font = getNativeFontFamily(_computedStyle.fontFamily);
		
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
	
	#end

}