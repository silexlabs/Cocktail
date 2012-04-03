/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style;

import cocktail.core.HTMLElement;
import haxe.Log;

#if (flash9 || nme)
import cocktail.port.flash_player.CoreStyle;

#elseif js
import cocktail.port.browser.CoreStyle;
#end

/**
 * This is the style implementation for embedded
 * HTMLElement. Embedded HTMLElement include external
 * content in the document, such as picture or video.
 * 
 * They can't have any children.
 * 
 * Doesn't add any behaviour as this is the default beahviour
 * implemented by the Style class
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractEmbeddedCoreStyle extends CoreStyle
{
	/**
	 * class constructor
	 */
	public function new(htmlElement:HTMLElement) 
	{
		super(htmlElement);
	}
}