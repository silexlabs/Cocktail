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

/**
 * This is a "neutral" DOMElement used for instance when a skin (.swf in Flash, .html in HTML)
 * is loaded. It allows for setting semantic of the root node of the DOMElement (not implemented for
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
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
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