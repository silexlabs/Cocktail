/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktail.domElement.ContainerDOMElement;
import core.nativeElement.NativeElement;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import core.style.ContainerStyle;
import cocktailCore.domElement.DOMElementData;
import cocktailCore.domElement.DOMElementData;
import cocktail.textElement.TextElement;
import core.renderer.TextRenderer;
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
	 * a reference to each of the ContainerDOMElement children which
	 * can be either of type DOMElement or TextElement.
	 * Their order is significant to the layout of the document
	 */
	private var _children:Array<ContainerDOMElementChildData>;
	public var children(getChildren, never):Array<ContainerDOMElementChildData>;
	
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
		
		super(nativeElement);
	}
	
	/**
	 * Override to instantiate a Container specific 
	 * style manager
	 */
	override private function initStyle():Void
	{
		//this._style = new ContainerStyle(this);
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
		//check if the DOMElement has already a parent. If it has
		//remove it form its current parent before adding it to this
		//ContainerDOMElement as a DOMElement can only have one parent.
		//Useful when the DOMElement is added to multiple ContainerDOMElement
		//in a row without being cleanly removed each time
		if (domElement.parent != null)
		{
			var parent:ContainerDOMElement = domElement.parent;
			parent.removeChild(domElement);
		}
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
		this._style.invalidate();
		
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
		_children.push( { child:textElement, type:ContainerDOMElementChildValue.textElement } );
		textElement.parent = cast(this);
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
			else
			{
				_children[i].child.parent = null;
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
}