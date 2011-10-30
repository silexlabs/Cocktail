/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.as3;
import cocktail.domElement.TextNode;
import cocktail.nativeElement.NativeElement;
import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.errors.ScriptTimeoutError;
import flash.text.engine.BreakOpportunity;
import flash.text.engine.ContentElement;
import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.GroupElement;
import flash.text.engine.Kerning;
import flash.text.engine.TextBaseline;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TextLineCreationResult;
import flash.text.TextField;
import flash.Vector;
import flash.Vector;
import haxe.Log;
import cocktail.domElement.abstract.AbstractTextDOMElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.domElement.DOMElementData;

/**
 * This is the Text DOMElement implementation for Flash.
 * 
 * @author Yannick DOMINGUEZ
 */
class TextDOMElement extends AbstractTextDOMElement
{

	private var _textBlock:TextBlock;
	
	private var _previousTextLine:TextLine;
	
	private var _textLineDOMElements:Array<TextLineDOMElement>;
	
	private var _textBlocks:Array<TextBlockWrapperData>;
	
	private var _textBlocksIndex:Int;
	
	private var _textLineContainer:Sprite;
	
	public function new(nativeElement:NativeElement = null) 
	{
		if (nativeElement ==  null)
		{
			nativeElement = NativeElementManager.createNativeElement(neutral);
		}
		super(nativeElement);
		
		_textLineContainer = new Sprite();
		_textLineDOMElements = new Array<TextLineDOMElement>();
	}
	


	
	override public function reset():Void
	{
		for (i in 0..._textLineDOMElements.length)
		{
			_nativeElement.removeChild(_textLineDOMElements[i].nativeElement);
		}
		
		_textLineDOMElements = new Array<TextLineDOMElement>();
		_textBlocks = null;
		_previousTextLine = null;
		_textBlocksIndex = 0;
	}
	
	override public function createTextLine(width:Int):TextLineDOMElement
	{
		
		if (_textBlocks == null)
		{
			_textBlocks = getTextBlocks();
			
			_textBlocksIndex = 0;
		}
		
	
		var textLine:TextLine = _textBlocks[_textBlocksIndex].textBlock.createTextLine(_previousTextLine, width);
		
		if (textLine != null)
		{

			
			_previousTextLine = textLine;
			

			
			_nativeElement.addChild(textLine);
			
			var textLineDOMElement:TextLineDOMElement = new TextLineDOMElement(textLine, _textBlocks[_textBlocksIndex].style, false);
		
			_textLineDOMElements.push(textLineDOMElement);
			
			return textLineDOMElement;
		}
		else if (_textBlocksIndex < _textBlocks.length - 1)
		{
			_textBlocksIndex++;
			_previousTextLine = null;
			
			return createTextLine(width);
		}
		else 
		{
			return null;
		}
	}
	
	
	public function getTextBlocks():Array<TextBlockWrapperData>
	{
		var textBlocks:Array<TextBlockWrapperData> = new Array<TextBlockWrapperData>();
		
		for (i in 0..._children.length)
		{
			if (_children[i].type == TextDOMElementChildrenValue.textDOMElement)
			{
				var childrenTextBlocks:Array<TextBlockWrapperData> = _children[i].children.getTextBlocks();
				for (j in 0...childrenTextBlocks.length)
				{
					textBlocks.push(childrenTextBlocks[j]);
				}
	
			}
			else
			{
				var textBlock:TextBlock = new TextBlock(convertStyle(new TextElement(_children[i].children.text)));
				
				textBlocks.push({textBlock:textBlock, style:this._style});
			}
		}
		
		return textBlocks;
	}
	
	private function convertStyle(textNode:TextElement):TextElement
	{
		var elementFormat:ElementFormat = new ElementFormat();
		elementFormat.fontSize = _style.computedStyle.fontSize;
		
		textNode.elementFormat = elementFormat;
		
		return textNode;
	}
	
	override private function getTextBlockCompletionValue():TextBlockCompletionValue
	{
		var addedRawTextLength:Int = 0;
		var currentTextBlock:TextBlock = _textBlocks[_textBlocksIndex].textBlock;
		
		var firstLine:TextLine = currentTextBlock.firstLine;
		if (firstLine == null)
		{
			return incomplete;
		}
		
		addedRawTextLength = firstLine.rawTextLength;
		
		var nextLine:TextLine = firstLine.nextLine;
		
		while (nextLine != null)
		{
			addedRawTextLength += nextLine.rawTextLength;
			nextLine = nextLine.nextLine;
		}
		
		
		if (addedRawTextLength == currentTextBlock.content.rawText.length)
		{
			return complete;
		}
		else
		{
			return incomplete;
		}
		
	}
	
	


}