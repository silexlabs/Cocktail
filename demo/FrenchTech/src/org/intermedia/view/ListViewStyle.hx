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
 * This class defines the default style used by a ListView
 * 
 * @author Raphael Harmel
 */

class ListViewStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setListStyle(node:HtmlDom):Void
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
		node.style.paddingBottom = "0px";
		
		//node.style.width = "auto";
		// set list width to 1/3 of the swippable list view
		//node.style.width = Std.string(100/3) + "%";
		node.style.width = Std.string(Lib.window.innerWidth) + "px";
		node.style.height = "100%";
		
		node.style.top = "0px";
		node.style.bottom = "0px";
		
		node.style.verticalAlign = "top";
		node.style.overflowX = "hidden";
		//node.style.overflowY = "scroll";
		node.style.overflowY = "auto";
		
		node.style.backgroundColor = Constants.LIST_BG_GREY_COLOR;
	}
	
	/**
	 * loader image style
	 * 
	 * @param	node
	 */
	public static function loaderImage(node:HtmlDom)
	{
		node.style.display = "block";
		
		node.style.marginLeft = "auto";
		node.style.marginRight = "auto";
		node.style.marginTop = "10px";
		node.style.marginBottom = Std.string(Constants.LIST_BOTTOM_LOADER_VERTICAL_MARGIN) + "px";
		
		node.style.top = Std.string(Lib.window.innerHeight) + "px";
		//node.style.zIndex = 1000;
	}
	
}
