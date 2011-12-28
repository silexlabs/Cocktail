/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.as3;

import cocktail.domElement.DOMElement;
import cocktailCore.domElement.TextFragmentDOMElement;
import cocktailCore.style.abstract.AbstractContainerStyle;
import cocktailCore.style.abstract.AbstractStyle;
import cocktail.style.StyleData;
import cocktailCore.textElement.abstract.AbstractTextElement;
import cocktailCore.unit.UnitManager;
import cocktail.unit.UnitData;
import haxe.Log;

#if (flash9)
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;
#end

/**
 * This is the Flash AS3 implementation of the ContainerStyle.
 * 
 * This class implement the Flash specific text fragment creation
 * using the flash text engine introduced in flash player 10.
 * 
 * It's purpose is to create as many TextFragmentDOMElement as necessary
 * to render every TextElement of the styled ContainerDOMElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerStyle extends AbstractContainerStyle
{
	/**
	 * class constructor
	 */
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN NATIVE SETTERS
	// In Flash the width and height are not applied to the native DisplayObject
	// of the ContainerDOMElement, as it would scale its content. It is however
	// stored in the native width and height attributes to be returned when 
	// width or height are requested instead of returning 0 (the actual width/height)
	// of the native DisplayObject
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the width of the NativeElement of the
	 * target DOMElement
	 */
	override public function setNativeWidth(width:Int):Void
	{
		this._nativeWidth = width;
	}
	
	/**
	 * Set the height of the NativeElement of the
	 * target DOMElement
	 */
	override public function setNativeHeight(height:Int):Void
	{
		this._nativeHeight = height;
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	////////////////////////////////
	
#if (flash9)
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
		var transformedText:String = AbstractTextElement.applyTextTransform(text, _computedStyle.textTransform);
		
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
		fontDescription.fontName = getNativeFontFamily(_computedStyle.fontFamily);
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
	// PRIVATE STATIC HELPER METHODS
	////////////////////////////////
	
	/**
	 * Return a flash FontPosture object from
	 * the fontStyle style of the ContainerDOMElement
	 */
	private static function getNativeFontPosture(fontStyle:FontStyleStyleValue):FontPosture
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
	private static function getNativeFontVariant(fontVariant:FontVariantStyleValue):TypographicCase
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
#end

}