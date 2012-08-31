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
 * This class defines the styles used by a SwippableListView
 * 
 * @author Raphael Harmel
 */

class SwippableListViewStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setSwippableListStyle(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.position = "static";
		
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = Std.string(Constants.LIST_TOP) + "px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = "0px";

		node.style.width = "100%";
		node.style.height = Std.string(Lib.window.innerHeight - Constants.LIST_TOP) + "px";
		
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";

	}
	
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setListsContainerStyle(node:HtmlDom):Void
	{
		node.style.display = "inline-block";
		node.style.position = "static";
		
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = "0px";
		
		node.style.width = "300%";
		node.style.height = "100%";
	}

}
