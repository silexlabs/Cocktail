/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package ;


import js.Dom;
import js.Lib;

/**
 * This contains the utils methods
 * 
 * @author Raphael Harmel
 */

class Utils 
{

	/**
	 * Initializes a ContainerDOMElement
	 * 
	 * @return the initalized ContainerDOMElement
	 */
	public static function getContainer():HtmlDom
	{
		var ret = Lib.document.createElement("div");
		ret.style.display = "block";
		return ret;
	}
	
}