/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.js;
import cocktail.nativeReference.NativeReference;
import js.Dom;
import js.Lib;
import cocktail.domElement.base.TextDOMElementBase;

/**
 * This is the JavaScript implementation for the Text DOMElement
 * 
 * It adds the JavaScript specific behaviour of setting the HTML
 * of the reference to native DOM object
 * 
 * @author Yannick DOMINGUEZ
 */
class TextDOMElement extends TextDOMElementBase
{
	/**
	 * class constructor
	 */
	public function new(nativeReference:NativeReference = null) 
	{
		super(nativeReference);
	}
	
	/**
	 * Set the innerHTML of the reference to the native
	 * HTML tag with the provided text
	 * @param	text an HTML formatted text
	 */
	override public function setText(text:String):String
	{
		super.setText(text);
		this._nativeReference.innerHTML = text;
		return text;
	}
	
}