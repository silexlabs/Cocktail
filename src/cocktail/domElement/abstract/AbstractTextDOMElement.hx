/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;
import cocktail.domElement.DOMElement;
import cocktail.domElement.TextNode;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.domElement.DOMElementData;
import cocktail.style.TextStyle;


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
	private var _children:Array<Dynamic>;
	public var children(getChildren, never):Array<Dynamic>;
	
	/**
	 * class contructor. Init the TextDOMElement with an empty text node
	 * if no NativeElement is provided
	 */
	public function new(nativeElement:NativeElement = null)
	{
		//stores the provided NativeElement as first child
		_children = new Array<Dynamic>();
		
		//create a text native element if none is provided
		if (nativeElement == null)
		{
			_children.push(NativeElementManager.createNativeTextNode(""));
			nativeElement = NativeElementManager.createNativeElement(text);
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
		_children.push(text);
	}
	
	/**
	 * Remove a text node from the current text content
	 */
	public function removeText(text:TextNode):Void
	{
		_children.remove(text);
	}
	
	/**
	 * Append a TextDOMElement to the current TextDOMElement which can
	 * in turn also have texrt node and TextDOMElement children
	 * @param	textDOMElement
	 */
	public function appendTextDOMElement(textDOMElement:AbstractTextDOMElement):Void
	{
		_children.push(textDOMElement);
	}
	
	/**
	 * Removes a TextDOMElement from the current text content
	 */
	public function removeTextDOMElement(textDOMElement:AbstractTextDOMElement):Void
	{
		_children.remove(textDOMElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function getChildren():Array<Dynamic>
	{
		return _children;
	}
	
}