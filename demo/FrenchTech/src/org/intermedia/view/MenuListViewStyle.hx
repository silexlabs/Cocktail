/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.view;

import js.Dom;
import org.intermedia.view.Constants;

/**
 * This class defines the default style used by a MenuListView
 * 
 * @author Raphael Harmel
 */

class MenuListViewStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setMenuStyle(node:HtmlDom):Void
	{
		node.style.position = "fixed";
		node.style.display = "block";
		
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = "0px";
		node.style.paddingBottom = "0px";
		
		node.style.minWidth = "100%";
		node.style.width = "100%";
		node.style.height = Std.string(Constants.MENU_HEIGHT) + "px";
		
		node.style.top = Std.string(Constants.HEADER_HEIGHT) + "px";
		node.style.bottom = "auto";
		
		// set to the forehead
		//node.style.zIndex = 1000;
		
		// unset background color to remove list default bahaviour
		node.style.backgroundColor = null;
		
		// add background image
		node.style.backgroundImage = 'url(' + Constants.MENU_BG_IMAGE_URL + ')';

		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
	}
	
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
		
		node.style.width = "100%";
		node.style.height = "100%";

		// unset background color
		node.style.backgroundColor = null;
	
	}
	
}
