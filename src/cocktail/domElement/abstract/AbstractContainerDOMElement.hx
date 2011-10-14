/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.abstract;

import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;
import cocktail.style.ContainerStyle;

/**
 * This is a DOMElement hich can contain other DOMElement, it is in charge of building the DOMElement tree.
 * It can receive any DOMElement as children.
 * It allows for setting semantic of the root node of the DOMElement (not implemented for
 * Flash)
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
	 *  a reference to each of the DOMElement childs, stored by
	 *  z-index
	 */
	private var _children:Array<DOMElement>;
	public var children(getChildren, never):Array<DOMElement>;
	
	/**
	 * class constructor. Create a container NativeElement
	 * if none is provided
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		//get a neutral native element if none is provided (correspond to a div in HTML)
		if (nativeElement == null)
		{
			nativeElement = NativeElementManager.createNativeElement(neutral);
		}
		
		//init the children array
		_children = new Array<DOMElement>();
		
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
		domElement.attach();
		_children.push(domElement);
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
		domElement.detach();
		_children.remove(domElement);
	}
	
	/**
	 * returns the children of this DOMElement
	 * @return an array of DOMElement
	 */
	public function getChildren():Array<DOMElement>
	{
		return _children;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SEMANTIC methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the semantic name of the first native node
	 * @param	semantic an HTML tag name (div, nav, header...)
	 */
	public function setSemantic(semantic:String):String
	{
		this._semantic = semantic;
		return this._semantic;
	}
	
	/**
	 * Return the semantic name of the first native node
	 * @return	semantic an HTML tag name (div, nav, header...)
	 */
	public function getSemantic():String
	{
		return this._semantic;
	}
	
}