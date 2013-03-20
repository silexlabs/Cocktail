/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.flash_player;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.NativeInputBase;

/**
 * This is the flash port of for the native button.
 * 
 * note : this is one possible implementation of a button
 * for flash. The idea here, is to set the inner html of
 * the input to the value, this way the button can be entirely
 * styled in CSS. An alternative solution might be to use 
 * a true flash button and attach it to the display list
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeButton extends NativeInputBase
{
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	override private function set_value(textValue:String):String 
	{
		_node.innerHTML = textValue;
		return textValue;
	}
}