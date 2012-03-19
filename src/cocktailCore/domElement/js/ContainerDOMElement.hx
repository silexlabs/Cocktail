/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.js;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import core.nativeElement.NativeElement;
import core.nativeElement.NativeElementManager;
import core.nativeElement.NativeElementData;
import cocktail.textElement.TextElement;
import js.Lib;
import js.Dom;
import cocktailCore.domElement.abstract.AbstractContainerDOMElement;

/**
 * This is the JavaScript implementation of the container DOMElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerDOMElement extends AbstractContainerDOMElement
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// DOM
	// Overriden Public method to manipulate the DOM
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to attach the native HTML element to the HTML DOM and
	 * to set the CSS z-index of the newly attached children
	 * @param	domElement the html element to add to this container
	 */
	override public function addChild(domElement:DOMElement):Void
	{
		super.addChild(domElement);
		this._nativeElement.appendChild(domElement.nativeElement);
		//intialise z-index on the DOMElement, as it is null by default in JavaScript
		domElement.nativeElement.style.zIndex = _children.length - 1;
	}
	
	/**
	 * Overriden to remove the native HTML element from
	 * the HTML DOM
	 * @param domElement the html element to remove from this container
	 */
	override public function removeChild(domElement:DOMElement):Void
	{
		super.removeChild(domElement);
		this._nativeElement.removeChild(domElement.nativeElement);
	}
	
	/**
	 * Overriden to append the textElement's NativeTextElement (an 
	 * HTML textNode) to the HTML element of this container
	 * @param	text the text node to append
	 */
	override public function addText(textElement:TextElement):Void
	{
		super.addText(textElement);
		this.nativeElement.appendChild(textElement.nativeText);
	}
	
	/**
	 * Overriden to remove the native HTML text node from the HTML element of this
	 * container
	 * @param	text the text node to remove
	 */
	override public function removeText(textElement:TextElement):Void
	{
		super.removeText(textElement);
		this._nativeElement.removeChild(textElement.nativeText);
	}
}