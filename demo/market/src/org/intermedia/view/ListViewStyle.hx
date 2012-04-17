/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
		//node.style.marginTop = Std.string(Constants.LIST_TOP) + "px";
		node.style.marginBottom = "0px";
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = "0px";
		node.style.paddingBottom = "0px";
		
		//node.style.width = Std.string(Lib.window.innerWidth) + "px";
		//node.style.width = Std.string(node.clientWidth) + "px";
		//node.style.width = "auto";
		// set list width to 1/3 of the swippable list view
		node.style.width = Std.string(100/3) + "%";
		node.style.height = Std.string(Lib.window.innerHeight) + "px";
		//node.style.height = Std.string(Lib.window.innerHeight - Constants.LIST_TOP) + "px";
		//node.style.height = Std.string( Lib.window.innerHeight - Constants.LIST_TOP ));
		//node.style.height = "auto";
		//node.style.height = "100%";
		
		node.style.top = "0px";
		node.style.bottom = "0px";
		
		node.style.verticalAlign = "top";
		node.style.overflowX = "hidden";
		node.style.overflowY = "scroll";
		//node.style.overflowY = "hidden";
		
		node.style.backgroundColor = Constants.LIST_BG_COLOR;
	}
	
	/**
	 * loader animation style
	 * 
	 * @param	node
	 */
	public static function loader(node:HtmlDom)
	{
		var VERTICAL_MARGIN:Int = 20;
		
		node.style.display = "block";
		
		node.style.marginLeft = "auto";
		node.style.marginRight = "auto";
		node.style.marginTop = Std.string(VERTICAL_MARGIN) + "px";
		node.style.marginBottom = Std.string(VERTICAL_MARGIN) + "px";
		
		node.style.top = Std.string(Lib.window.innerHeight) + "px";
		node.style.zIndex = 1000;
	}
	
}
