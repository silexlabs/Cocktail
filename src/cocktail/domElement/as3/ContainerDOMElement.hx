/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.as3;
import cocktail.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.TextNode;
import cocktail.nativeElement.NativeElement;
import cocktail.domElement.abstract.AbstractContainerDOMElement;
import flash.text.engine.BreakOpportunity;
import flash.text.engine.CFFHinting;
import flash.text.engine.ContentElement;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.GroupElement;
import flash.text.engine.LineJustification;
import flash.text.engine.SpaceJustifier;
import flash.text.engine.TextBaseline;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import cocktail.style.StyleData;
import flash.text.engine.TypographicCase;
import flash.Vector;
import haxe.Log;

/**
 * This is the Flash implementation of the container DOMElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerDOMElement extends AbstractContainerDOMElement
{

	/**
	 * A reference to the current flash TextBlock used to render
	 * text line. This is the model of the created text lines,
	 * used to create text line display object by providing a
	 * text line width
	 */
	private var _textBlock:TextBlock;
	
	/**
	 * A reference to the last created flash TextLine,
	 * used by the flash TextBlock when creating lines
	 * so that it can keep track of all its lines
	 */
	private var _previousTextLine:TextLine;
	
	/**
	 * A reference to the TextNode whose text is currently
	 * being rendered as flash text lines
	 */
	private var _currentTextNode:TextNode;
	
	/**
	 * Generic font families names
	 */
	private static var SERIF_GENERIC_FONT_NAME:String = "_serif";
	private static var SANS_SERIF_GENERIC_FONT_NAME:String = "_sans";
	private static var MONOSPACE_GENERIC_FONT_NAME:String = "_typewriter";
	
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Override public method to manipulate the DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to add the native flash display object as a 
	 * child of the native display object of this container
	 * @param domElement the flash display object to add to this 
	 * container
	 */
	override public function addChild(domElement:DOMElement):Void
	{
		super.addChild(domElement);
		this._nativeElement.addChild(domElement.nativeElement);
	}
	
	/**
	 * Overriden to remove the native flash display object from
	 * the native display object of this container
	 * @param domElement the flash display object to remove from
	 * this container
	 */
	override public function removeChild(domElement:DOMElement):Void
	{
		super.removeChild(domElement);
		this._nativeElement.removeChild(domElement.nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN TEXT LINE CREATION methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to clean up the native flash TextBlock
	 * object before removing all the text lines. It removes
	 * the link between text lines and their text block and
	 * allow garbage collection
	 */
	override public function resetTextLines():Void
	{
		if (_textBlock != null)
		{
			if (_textBlock.firstLine != null)
			{
				_textBlock.releaseLines(_textBlock.firstLine, _textBlock.lastLine);
				_textBlock.releaseLineCreationData();
			}
			
			_currentTextNode = null;
			_previousTextLine = null;
		}
		super.resetTextLines();
	}
	
	/**
	 * Overriden to create flash text lines. Uses the flash text engine introduced
	 * in flash player 10
	 */
	override private function doCreateTextLine(width:Int, textNode:TextNode):TextLineDOMElement
	{
		//line can't be created with null or negative width
		if (width <= 0)
		{
			return null;
		}
		
		//the TextNode used to create the lines must be determined
		//if there is currently no TextNode used, the provided textNode
		//is used
		//else if the provided textNode is different from the currently
		//used textNode, then a new block of text is being rendered and
		//a new flash TextBlock model must be created
		//else it means the current textNode still has text to render
		if (_currentTextNode == null || _currentTextNode != textNode)
		{
			_currentTextNode = textNode;
			
			//create a new flash TextBlock using the TextNode as content
			_textBlock = new TextBlock(getBrokenTextElements(textNode.text));
			_previousTextLine = null;
		}
		
		//create a native flash text line
		var textLine:TextLine = _textBlock.createTextLine(_previousTextLine, width);
		_previousTextLine = textLine;
		
		//if the text line is not null (meaning that the current TextNode still had text to render)
		//the flash text line is wrapped in a TextLineDOMObject so that it can be inserted
		//into the document
		if (textLine != null)
		{
			//ths styles of this ContainerDOMElement are also used by 
			//each text line it creates
			return new TextLineDOMElement(textLine, this._style, getIsLastLineOftextBlock());
		}
		//return a null text line if all of the current TextNode text was already rendered as 
		//text lines
		else
		{
			return null;
		}
	}
	
	/**
	 * Stores a reference to a generated TextLineDOMElement. Overriden by each runtime
	 * to attach the native text line to the native element of the container
	 */
	override private function addTextLine(textLineDOMElement:TextLineDOMElement):Void
	{
		super.addTextLine(textLineDOMElement);
		this._nativeElement.addChild(textLineDOMElement.nativeElement);
	}
	
	/**
	 * Removes a stored reference to a generated TextLineDOMElement. Overriden by each runtime
	 * to remove the native text line from the native element of the container
	 */
	override private function removeTextLine(textLineDOMElement:TextLineDOMElement):Void
	{		
		super.removeTextLine(textLineDOMElement);
		
		if (textLineDOMElement != null)
		{
			this._nativeElement.removeChild(textLineDOMElement.nativeElement);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE TEXT LINE CREATION methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Broke a text into word and spaces. Treating a text as a combination
	 * of words and spaces allows for more control of its layout, e.g a
	 * "word spacing" style can be applied to the block of text.
	 * 
	 * Each word and space is wrapped in a native Flash ContentElement
	 * which is the model used by a Flash TextBlock
	 */
	private function getBrokenTextElements(text:String):GroupElement
	{
		var textElements:Vector<ContentElement> = new Vector<ContentElement>();
		
		var textFragment:String = "";
		
		
		//Loop in all the text charachters
		for (i in 0...text.length)
		{
			
			//If the charachter is a space
			if (StringTools.isSpace(text, i) == true)
			{
				
				//If a word was being formed by concatenating
				//characters
				if (textFragment != null)
				{
					//push the word into the returned array
					textElements.push(getTextElement(textFragment, false));
					textFragment = null;
				}
				
				//push the space in the returned array
				textElements.push(getTextElement(text.charAt(i), true));
			}
			//else the charachter belongs to a word
			//and is added to the word which is being
			//concatenated
			else
			{
				if (textFragment == null)
				{
					textFragment = "";
				}
				textFragment += text.charAt(i);
			}
		}
		
		//push the remaining word if text doesn't end by a space
		if (textFragment != null)
		{
			textElements.push(getTextElement(textFragment, false));
		}
		
		
		return new GroupElement(textElements);
	}
	
	/**
	 * Takes a flash TextElement which is a model for text containing a
	 * string of text and objects to format the text when rendered, and
	 * parametrise its text formatting using the styles of the ContainerDOMElement
	 * @param	textElement a textElement with a default flash element format
	 * @return a textElement with a flash element format matching the styles
	 * of the ContainerDOMElement
	 */
	private function getTextElement(text:String, isSpace:Bool):TextElement
	{
		var textElement:TextElement = new TextElement(text);
		
		//create a flash element format object and set its
		//attribute to match the styles defined in this ContainerDOMElement
		var elementFormat:ElementFormat = new ElementFormat();
		elementFormat.fontSize = _style.computedStyle.fontSize;
		
		var fontDescription:FontDescription = new FontDescription();
		
		var fontWeightValue:FontWeight;
		
		switch (_style.computedStyle.fontWeight)
		{
			case bold:
				fontWeightValue = FontWeight.BOLD;
				
			case normal:
				fontWeightValue = FontWeight.NORMAL;
		}
		
		var fontPostureValue:FontPosture;
		
		switch (_style.computedStyle.fontStyle)
		{
			case normal:
				fontPostureValue = FontPosture.NORMAL;
				
			case italic:
				fontPostureValue = FontPosture.ITALIC;
		}
		
		fontDescription.fontWeight = fontWeightValue;
		fontDescription.fontPosture = fontPostureValue;
		fontDescription.fontName = getFontFamilyValue(_style.computedStyle.fontFamily);
		
		elementFormat.fontDescription = fontDescription;
		
		elementFormat.color = _style.computedStyle.color;
		
	
		
		var typographicCase:TypographicCase;
		
		switch (_style.computedStyle.fontVariant)
		{
			case normal:
				typographicCase = TypographicCase.DEFAULT;
				
			case smallCaps:
				typographicCase = TypographicCase.CAPS_AND_SMALL_CAPS;
				
		}
		
		
		elementFormat.typographicCase = typographicCase;
		
		if (isSpace == false)
		{
			elementFormat.trackingRight = _style.computedStyle.letterSpacing;
		}
		else
		{
			elementFormat.trackingRight = _style.computedStyle.wordSpacing;
		}
		
		textElement.replaceText(0, textElement.text.length, applyTextTransform(textElement.text));
		
		
		//set the element format as the text element
		//element format
		textElement.elementFormat = elementFormat;
		
		return textElement;
	}
	
	/**
	 * Transform a text letters into uppercase, lowercase
	 * or capitalise them (only the first letter of each word
	 * is transformed to uppercase), based on the textTransform
	 * style of this container DOMElement
	 * @param	text the text to transform
	 * @return the transformed text
	 */
	private function applyTextTransform(text:String):String
	{
		switch (_style.computedStyle.textTransform)
		{
			case uppercase:
				text = text.toUpperCase();
				
			case lowercase:
				text = text.toLowerCase();
				
			case capitalize:
				text = capitalizeText(text);
				
			case none:
		}
		
		return text;
	}
	
	/**
	 * Capitalise a text (turn each first letter
	 * of a word to uppercase)
	 * @param	text the text to capitaliee
	 * @return the capitalized
	 */
	private function capitalizeText(text:String):String
	{
		var capitalizedText:String = text.charAt(0);
		
		/**
		 * loop in all charachter looking for word breaks
		 * and capitalize each word's first letter
		 */
		for (i in 1...text.length)
		{	
			if (text.charAt(i - 1) == " ")
			{
				capitalizedText += text.charAt(i).toUpperCase();
			}
			else
			{
				capitalizedText += text.charAt(i);
			}
		}
		return capitalizedText;
	}
	
	/**
	 * Takes the array containing every font to apply to the
	 * text (ordered by priority, the first available font being
	 * used) and return a comma separated list containing the ordered
	 * font names.
	 * @param	value an array which may contain any combination of generic
	 * font family name and font family name
	 * @return a comma separated list of font, genrally ordered from most
	 * specific to most generic, e.g "Universe,Arial,_sans"
	 */
	private function getFontFamilyValue(value:Array<FontFamilyStyleValue>):String
	{
		var fontFamilyValue:String = "";
		
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
			
			if (fontName.indexOf(" ") != -1)
			{
				fontName = "'" + fontName + "'";
			}
			
			fontFamilyValue += fontName;
			
			if (i < value.length - 1)
			{
				fontFamilyValue += ",";
			}
		}
		
		return fontFamilyValue;
	}
	
	/**
	 * Determine wether the last created line of text is the last 
	 * of the current text block (meaning the text block ran out of
	 * text to render)
	 * @return true if the created line is the last of the text block
	 */
	private function getIsLastLineOftextBlock():Bool
	{
		//will stores all the length of text (the number of charachters)
		//for all the lines generated by the text block to see if it is 
		//the same number as the text block raw length meaning all the 
		//charachters have been rendered
		var addedRawTextLength:Int = 0;

		
		var firstLine:TextLine = _textBlock.firstLine;
		addedRawTextLength = firstLine.rawTextLength;
		
		var nextLine:TextLine = firstLine.nextLine;
		//loop in all the lines and add their length to the total
		//text length
		while (nextLine != null)
		{
			addedRawTextLength += nextLine.rawTextLength;
			nextLine = nextLine.nextLine;
		}
		
		//if the total text length of the lines is the same as their
		//text block, then all text was rendered
		if (addedRawTextLength == _textBlock.content.rawText.length)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden getter/setter
	// The width and height setter/getter are overriden to prevent setting the width and height
	// of the native Flash DisplayObjectContainer. In as3, when the width or height is set on a
	// container, the content of the container is scaled
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setWidth(value:Int):Int
	{
		this._width = value;
		return this._width;
	}
	
	override private function setHeight(value:Int):Int
	{
		this._height = value;
		return this._height;
	}
	
}