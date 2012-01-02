/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktailCore.domElement.TextFragmentDOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktailCore.style.ContainerStyle;
import cocktail.domElement.DOMElementData;
import cocktailCore.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import haxe.Log;

#if (flash9 || cpp || nme)
import cocktailCore.domElement.as3.DOMElement;
#elseif js
import cocktailCore.domElement.js.DOMElement;
#end

/**
 * This is a DOMElement which can contain both DOMElement and TextElement, it is in charge of building the DOMElement tree.
 * A ContainerDOMElement can receive any other type of DOMElement as children.
 * A TextElement is a reference to a simple string of text which takes the visual style of its ContainerDOMElement. A TextElement can't have children.
 * Each ContainerDOMElement represents a semantic element in the DOMElement tree.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractContainerDOMElement extends DOMElement
{
	/**
	 * Store the node name (div, nav, header...) of the
	 * first node of the reference to the native DOM.
	 */
	private var _semantic:String;
	public var semantic(getSemantic, setSemantic):String;
	
	/**
	 * a reference to each of the ContainerDOMElement children which
	 * can be either of type DOMElement or TextElement.
	 * Their order is significant to the layout of the document
	 */
	private var _children:Array<ContainerDOMElementChildData>;
	public var children(getChildren, never):Array<ContainerDOMElementChildData>;
	
	/**
	 * Stores each of the text fragments generated at layout so they 
	 * can easily be removed when the text content changes or when a
	 * text style of the ContainerDOMElement changes
	 */
	private var _textFragmentDOMElements:Array<TextFragmentDOMElement>;
	
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
		
		//init the children and text fragments array
		_children = new Array<ContainerDOMElementChildData>();
		_textFragmentDOMElements = new Array<TextFragmentDOMElement>();
		
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
	 * @param	domElement the DOMElement to attach to this ContainerDOMElement
	 */
	public function addChild(domElement:DOMElement):Void
	{
		domElement.parent = cast(this);
		_children.push( { child:domElement, type:ContainerDOMElementChildValue.domElement } );
		this._style.invalidate();
	}
	
	/**
	 * Reset the parent of the removed child object as it no longer is attached
	 * to the DOM, remove it also from the children array. Overriden by each
	 * runtime to remove also from the native DOM
	 * @param	domElement the DOMElement to remove from this ContainerDOMElement
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
	 * Add a TextElement as a children of the ContainerDOMElement.
	 * The TextElement will be rendered as textFragmentDOMElements, at
	 * layout time, as many as necessary to render the full TextElement's
	 * text
	 * @param	textElementData
	 */
	public function addText(textElement:TextElement):Void
	{
		_children.push({child:textElement, type:ContainerDOMElementChildValue.textElement});
	}
	
	/**
	 * Removes a TextElement from the ContainerDOMElement.
	 * @param	textElementData
	 */
	public function removeText(textElement:TextElement):Void
	{
		var newChildrenArray:Array<ContainerDOMElementChildData> = new Array<ContainerDOMElementChildData>();
		for (i in 0..._children.length)
		{
			if (_children[i].child != textElement)
			{
				newChildrenArray.push(_children[i]);
			}
		}
		this._children = newChildrenArray;
	}
	
	/**
	 * returns the children of this ContainerDOMElement
	 * @return an array containing any number of TextElement
	 * and DOMElements
	 */
	private function getChildren():Array<ContainerDOMElementChildData>
	{
		return _children;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// TEXT FRAGMENT MANAGEMENT methods
	// used to add and remove TextFragmentDOMElements generated by this
	// ContainerDOMElement TextElements
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Removes all the previously added text fragments. Occurs
	 * when the content of a textElement changes or a text style
	 * of the ContainerDOMElement changes, thus changing
	 * the textElement display
	 */
	public function resetTextFragments():Void
	{
		for (i in 0..._textFragmentDOMElements.length)
		{
			this.removeTextFragment(_textFragmentDOMElements[i]);
		}
		_textFragmentDOMElements = new Array<TextFragmentDOMElement>();
		
		for (i in 0..._children.length)
		{
			switch(_children[i].type)
			{
				case ContainerDOMElementChildValue.textElement:
					var textElement:TextElement = _children[i].child;
					textElement.reset();
					
				default:	
			}
		}
	}
	
	/**
	 * Stores a reference to a generated TextFragmentDOMElement. Overriden by each runtime
	 * to attach the native text line to the native element of the container
	 */
	public function addTextFragment(textFragmentDOMElement:TextFragmentDOMElement):Void
	{
		_textFragmentDOMElements.push(textFragmentDOMElement);
	}
	
	/**
	 * Removes a stored reference to a generated TextFragmentDOMElement. Overriden by each runtime
	 * to remove the native text line from the native element of the container
	 */
	private function removeTextFragment(textFragmentDOMElement:TextFragmentDOMElement):Void
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