/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;
import cocktail.domElement.DOMElement;
import cocktail.domElement.TextDOMElement;
import cocktail.domElement.TextNode;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.domElement.DOMElementData;
import cocktail.style.TextStyle;
import haxe.Log;


/**
 * This is a DOMElement in charge of displaying an 
 * HTML text. The text is stored as a series of text node
 * and TextDOMElements.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractTextDOMElement extends DOMElement
{

	/**
	 * Stores the children of this TextDOMElement, which can
	 * be either text nodes or other TextDOMElements
	 */
	private var _children:Array<TextDOMElementChildrenData>;
	public var children(getChildren, never):Array<TextDOMElementChildrenData>;
	
	private var _textDOMElementParent:AbstractTextDOMElement;
	public var textDOMElementParent(getTextDOMElementParent, setTextDOMElementParent):AbstractTextDOMElement;
	
	public var textBlockCompletionValue(getTextBlockCompletionValue, never):TextBlockCompletionValue;
	
	/**
	 * class contructor. Init the TextDOMElement with an empty text node
	 * if no NativeElement is provided
	 */
	public function new(nativeElement:NativeElement = null)
	{
		//stores the provided NativeElement as first child
		_children = new Array<TextDOMElementChildrenData>();
		
		//create a text native element if none is provided
		if (nativeElement == null)
		{
			_children.push({children:NativeElementManager.createNativeTextNode(""), type:TextDOMElementChildrenValue.textNode});
			//nativeElement = NativeElementManager.createNativeElement(text);
			initStyle();
		}
		else
		{
			//_children.push(nativeElement);
		}
		
		super(nativeElement);
	}
	
	public function createTextLine(width:Int):TextLineDOMElement
	{
		return null;
	}
	
	public function reset():Void
	{
		
	}
	
	/**
	 * Override to instantiate a Text DOMElement specific 
	 * style manager
	 */
	override private function initStyle():Void
	{
		this._style = new TextStyle(this);
	}
	
	
	/**
	 * Append a text node to the current text content.
	 * @param	text a raw string of text
	 */
	public function appendText(text:TextNode):Void
	{
		_children.push({children:text, type:TextDOMElementChildrenValue.textNode});
	}
	
	/**
	 * Remove a text node from the current text content
	 */
	public function removeText(text:TextNode):Void
	{
		for (i in 0..._children.length)
		{
			if (_children[i].children == text)
			{
				_children.remove(_children[i]);
			}
		}	
	}
	
	/**
	 * Append a TextDOMElement to the current TextDOMElement which can
	 * in turn also have texrt node and TextDOMElement children
	 * @param	textDOMElement
	 */
	public function appendTextDOMElement(textDOMElement:AbstractTextDOMElement):Void
	{
		_children.push({children:textDOMElement, type:TextDOMElementChildrenValue.textDOMElement});
		textDOMElement.textDOMElementParent = this;
	}
	
	/**
	 * Removes a TextDOMElement from the current text content
	 */
	public function removeTextDOMElement(textDOMElement:AbstractTextDOMElement):Void
	{
		for (i in 0..._children.length)
		{
			if (_children[i].children == textDOMElement)
			{
				_children.remove(_children[i]);
			}
		}
		
		textDOMElement.textDOMElementParent = null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getChildren():Array<TextDOMElementChildrenData>
	{
		return _children;
	}
	
	private function setTextDOMElementParent(value:AbstractTextDOMElement):AbstractTextDOMElement
	{
		return this._textDOMElementParent = value;
	}
	
	private function getTextDOMElementParent():AbstractTextDOMElement
	{
		return this._textDOMElementParent;
	}
	
	private function getTextBlockCompletionValue():TextBlockCompletionValue
	{
		return null;
	}
	
}