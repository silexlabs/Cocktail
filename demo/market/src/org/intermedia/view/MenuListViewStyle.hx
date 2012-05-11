/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
		//node.style.position = "absolute";
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
<<<<<<< HEAD
		
		// unset background color to remove list default bahaviour
		node.style.backgroundColor = null;
=======
		
		// unset background color to remove list default bahaviour
		node.style.backgroundColor = null;
		
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
	
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setListStyle(node:HtmlDom):Void
	{
		node.style.display = "inline-block";
		//node.style.position = "absolute";
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
