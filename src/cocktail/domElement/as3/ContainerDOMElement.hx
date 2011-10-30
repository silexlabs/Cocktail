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
import flash.text.engine.ElementFormat;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
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
			_textBlock = new TextBlock(convertStyle(new TextElement(textNode.text)));
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
	 * Takes a flash TextElement which is a model fro text containing a
	 * string of text and objects to format the text when rendered, and
	 * parametrise its text formatting using the styles of the ContainerDOMElement
	 * @param	textElement a textElement with a default flash element format
	 * @return a textElement with a flash element format matching the styles
	 * of the ContainerDOMElement
	 */
	private function convertStyle(textElement:TextElement):TextElement
	{
		//create a flash element format object and set its
		//attribute to match the styles defined in this ContainerDOMElement
		var elementFormat:ElementFormat = new ElementFormat();
		elementFormat.fontSize = _style.computedStyle.fontSize;
		
		
		//set the element format as the text element
		//element format
		textElement.elementFormat = elementFormat;
		
		return textElement;
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
	
	override public function setWidth(value:Int):Int
	{
		this._width = value;
		return this._width;
	}
	
	override public function setHeight(value:Int):Int
	{
		this._height = value;
		return this._height;
	}
	
}