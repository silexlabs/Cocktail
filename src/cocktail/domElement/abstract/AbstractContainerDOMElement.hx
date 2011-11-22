/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;

import cocktail.domElement.TextLineDOMElement;
import cocktail.domElement.TextNode;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.style.ContainerStyle;
import cocktail.domElement.DOMElementData;
import haxe.Log;

#if flash9
import cocktail.domElement.as3.DOMElement;
#elseif js
import cocktail.domElement.js.DOMElement;
#end

/**
 * This is a DOMElement which can contain other both DOMElement and TextNode, it is in charge of building the DOMElement tree.
 * A ContainerDOMElement can receive any DOMElement as children.
 * A TextNode is a reference to a simple string of text which takes the style of its container. A TextNode can't have children.
 * It allows for setting semantic (node name) of the root node of the ContainerDOMElement.
 * 
 * When a ContainerDOMElement is laid out, it as many TextLineDOMObject as necessary each time one of its laid out children is
 * a TextNode. The TextNode is used as the model of the text, the generated TextLineDOMObjects are the view creating enough text line
 * to render all the text model. The TextLineDOMElements uses the ContainerDOMElement styles.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractContainerDOMElement extends DOMElement
{
	/**
	 * Store the node name (div, nav, header...) of the
	 * first node of the reference to the native DOM.
	 * This doesn't apply to Flash
	 */
	private var _semantic:String;
	public var semantic(getSemantic, setSemantic):String;
	
	/**
	 * a reference to each of the ContainerDOMElement children which
	 * can be either of type DOMElement or TextNode.
	 * Their order is significant to the layout of the document
	 */
	private var _children:Array<ContainerDOMElementChildData>;
	public var children(getChildren, never):Array<ContainerDOMElementChildData>;
	
	/**
	 * Stores each of the text lines generated at layout so they 
	 * can easily be removed when a new layout occurs.
	 */
	private var _textLineDOMElements:Array<TextLineDOMElement>;
	
	/**
	 * class constructor. Create a container NativeElement
	 * if none is provided
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		//get a neutral native element if none is provided (e.g a div in HTML or a
		//display object container in flash)
		if (nativeElement == null)
		{
			nativeElement = NativeElementManager.createNativeElement(neutral);
		}
		
		//init the children and text lines array
		_children = new Array<ContainerDOMElementChildData>();
		_textLineDOMElements = new Array<TextLineDOMElement>();
		
		super(nativeElement);
	}
	
	/**
	 * Override to instantiate a Container specific 
	 * style manager
	 */
	override private function initStyle():Void
	{
		this._style = new ContainerStyle(this);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM
	// Public method to manipulate the DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the current ContainerDOMElement as the parent of the added domElement, and 
	 * store it in the children array. Overriden by each runtime, to add the
	 * child to native DOM.
	 * @param	domElement the DOMElement to attach to this DOMElement
	 */
	public function addChild(domElement:DOMElement):Void
	{
		domElement.parent = this;
		_children.push({child:domElement, type:ContainerDOMElementChildValue.domElement});
	}
	
	/**
	 * Reset the parent of the removed child object as it no longer is attached
	 * to the DOM, remove it also from the children array. Overriden by each
	 * runtime to remove also from the native DOM
	 * @param	domElement the DOMElement to remove from this DOMElement
	 */
	public function removeChild(domElement:DOMElement):Void
	{
		domElement.parent = null;
		
		var newChildrenArray:Array<ContainerDOMElementChildData> = new Array<ContainerDOMElementChildData>();
		for (i in 0..._children.length)
		{
			if (_children[i].child != domElement)
			{
				newChildrenArray.push(_children[i]);
			}
		}
		this._children = newChildrenArray;
		
	}
	
	/**
	 * Add a TextNode as a children of the ContainerDOMElement. Overriden
	 * by each runtime to attach the text to their specific DOM
	 * @param	text a reference to a string of text
	 */
	public function addText(text:TextNode):Void
	{
		_children.push({child:text, type:ContainerDOMElementChildValue.textNode});
	}
	
	/**
	 * Removes a TextNode from the ContainerDOMElement. Overriden
	 * by each runtime to the detach the text from their
	 * specific DOM
	 * @param	text
	 */
	public function removeText(text:TextNode):Void
	{
		var newChildrenArray:Array<ContainerDOMElementChildData> = new Array<ContainerDOMElementChildData>();
		for (i in 0..._children.length)
		{
			if (_children[i].child != text)
			{
				newChildrenArray.push(_children[i]);
			}
		}
		this._children = newChildrenArray;
	}
	
	/**
	 * returns the children of this ContainerDOMElement
	 * @return an array containing any number of TextNode
	 * and DOMElements
	 */
	private function getChildren():Array<ContainerDOMElementChildData>
	{
		return _children;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TEXT LINE MANAGEMENT methods
	// used to add and remove TextLineDOMElements to the container
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a layout of this ContainerDOMElement occurs, all previously
	 * created text lines must be removed
	 */
	public function resetTextLines():Void
	{
		for (i in 0..._textLineDOMElements.length)
		{
			this.removeTextLine(_textLineDOMElements[i]);
		}
		_textLineDOMElements = new Array<TextLineDOMElement>();
	}
	
	/**
	 * Stores a reference to a generated TextLineDOMElement. Overriden by each runtime
	 * to attach the native text line to the native element of the container
	 */
	public function addTextLine(textLineDOMElement:TextLineDOMElement):Void
	{
		_textLineDOMElements.push(textLineDOMElement);
	}
	
	/**
	 * Removes a stored reference to a generated TextLineDOMElement. Overriden by each runtime
	 * to remove the native text line from the native element of the container
	 */
	private function removeTextLine(textLineDOMElement:TextLineDOMElement):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SEMANTIC methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the semantic name of the first native node
	 * @param	semantic an HTML tag name (div, nav, header...)
	 */
	private function setSemantic(semantic:String):String
	{
		this._semantic = semantic;
		return this._semantic;
	}
	
	/**
	 * Return the semantic name of the first native node
	 * @return	semantic an HTML tag name (div, nav, header...)
	 */
	private function getSemantic():String
	{
		return this._semantic;
	}
	
}