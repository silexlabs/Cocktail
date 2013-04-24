/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.flash_player;

import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.NativeTextInputBase;
import cocktail.port.NativeElement;
import flash.display.DisplayObjectContainer;
import flash.display.Sprite;
import flash.geom.Rectangle;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.text.TextFieldType;
import cocktail.core.geom.GeomData;

/**
 * This is the flash port of for the native text area,
 * which in flash is a multiline text area
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeTextArea extends NativeTextInput
{
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_textField.multiline = true;
		_textField.wordWrap = true;
	}
}