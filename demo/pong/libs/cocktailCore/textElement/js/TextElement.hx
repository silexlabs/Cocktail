/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.textElement.js;

import cocktail.style.StyleData;
import cocktailCore.textElement.abstract.AbstractTextElement;
import cocktailCore.textElement.TextElementData;
import js.Lib;

/**
 * This is the JavaScript implementation of the TextElement.
 * 
 * In JavaScript, a text element is represented by an 
 * HTML text node object. 
 * 
 * This HTML text node object is created from
 * the text provided in the constructor.
 * It is wrapped in a NativeTextElement
 * 
 * @author Yannick DOMINGUEZ
 */
class TextElement extends AbstractTextElement
{
	/**
	 * class contructor
	 */
	public function new(text:String)
	{
		super(text);
		//create and store the native HTML text node
		_text = Lib.document.createTextNode(text);
	}
}