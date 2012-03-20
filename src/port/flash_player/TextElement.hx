/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package port.flash_player;

import core.style.StyleData;
import core.textElement.AbstractTextElement;
import core.dom.DOMData;
import haxe.Log;

/**
 * This is the Flash As3 implementation of the TextElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class TextElement extends AbstractTextElement
{
	/**
	 * class constructor
	 */
	public function new(text:String) 
	{
		super(text);
	}
	
	/**
	 * Clean up the generated text fragments
	 * and invalidate the parent to cause the
	 * creation of the new text
	 */
	override private function setText(value:String):String
	{
		_text = value;
		_nativeText = value;
		
		reset();
		_textFragments = new Array<TextFragmentData>();
		
		if (_parent != null)
		{
			_parent.style.invalidateText();
		}
	
		return value;
	}
}