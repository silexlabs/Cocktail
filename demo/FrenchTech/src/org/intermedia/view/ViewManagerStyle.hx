/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.view.Constants;

/**
 * Contains all style applied to ViewManager
 * 
 * @author Raphael Harmel
 */

class ViewManagerStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setBodyStyle(node:HtmlDom):Void
	{
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = "0px";
		node.style.paddingBottom = "0px";
		
		node.style.width = "100%";
		node.style.height = "100%";
		
		node.style.overflowX = "hidden";
		node.style.overflowY = "auto";
	}
	
}

