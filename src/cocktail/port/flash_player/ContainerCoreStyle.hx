/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.HTMLElement;
import cocktail.core.style.AbstractContainerCoreStyle;
import cocktail.core.style.AbstractCoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.renderer.TextRenderer;
import cocktail.core.Text;
import cocktail.core.dom.DOMData;
import cocktail.core.unit.UnitManager;
import cocktail.core.unit.UnitData;
import flash.text.TextFieldAutoSize;

import haxe.Log;

#if flash9

import flash.text.engine.ElementFormat;
import flash.text.engine.FontDescription;
import flash.text.engine.FontPosture;
import flash.text.engine.FontWeight;
import flash.text.engine.TextBlock;
import flash.text.engine.TextElement;
import flash.text.engine.TextLine;
import flash.text.engine.TypographicCase;

#elseif nme 
import flash.text.TextFormat;

#end

/**
 * This is the Flash AS3 implementation of the ContainerStyle.
 * 
 * This class implement the Flash specific text fragment creation
 * using the flash text engine introduced in flash player 10.
 * 
 * It's purpose is to create as many TextRenderer as necessary
 * to render every TextElement of the styled ContainerHTMLElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class ContainerCoreStyle extends AbstractContainerCoreStyle
{
	/**
	 * class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}

}