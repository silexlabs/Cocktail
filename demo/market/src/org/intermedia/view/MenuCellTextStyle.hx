/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import haxe.Firebug;
import js.Lib;
import js.Dom;


/**
 * This class defines the styles used by the CellText
 * 
 * @author Raphael Harmel
 */

class MenuCellTextStyle
{
	static inline var CELL_VERTICAL_SPACE:Int = 5;
	static inline var CELL_HORIZONTAL_PADDING:Int = 5;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 */
	public static function setCellStyle(node:HtmlDom):Void
	{
		node.style.display = "inline-block";
		//node.style.position = "static";
		node.style.position = "absolute";
		
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = Std.string(CELL_VERTICAL_SPACE) + "px";
		node.style.paddingBottom = "0px";
		
		//node.style.width = Std.string(100/3) + "%";
		node.style.width = "auto";
		//node.style.width = "100%";
		//node.style.minWidth = "33%";

		// remove border
		CellStyle.removeBorder(node);
		node.style.backgroundColor = null;
	}
	
	/**
	 * Defines cell text Style
	 * 
	 * @param	node
	 */
	public static function setCellTextStyle(node:HtmlDom):Void
	{
		node.style.display = "inline";
		node.style.position = "relative";

		node.style.paddingRight = Std.string(CELL_HORIZONTAL_PADDING) + "px";
		node.style.paddingLeft = Std.string(CELL_HORIZONTAL_PADDING) + "px";
		
		node.style.fontSize = "16px";
		node.style.lineHeight = "normal";
		//node.style.fontWeight = "bold";
		node.style.fontStyle = "normal";
		node.style.fontFamily = 'Arial, sans-serif';
		node.style.fontVariant = "normal";
		node.style.textTransform = "none";
		node.style.letterSpacing = "normal";
		node.style.wordSpacing = "normal";
		node.style.textIndent = "0px";
		node.style.whiteSpace = "normal";
		
		node.style.verticalAlign = "middle";
		
		node.style.color = '#444444';
		
	}
	
}
