/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import js.Lib;
import js.Dom;


/**
 * This class defines the styles used by the CellText
 * 
 * @author Raphael Harmel
 */

class CellTextStyle
{
	static inline var CELL_VERTICAL_SPACE:Int = 4;
	static inline var CELL_HORIZONTAL_SPACE:Int = 2;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 */
	public static function setCellStyle(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.position = "relative";
		
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = Std.string(CELL_HORIZONTAL_SPACE) + "%";
		node.style.paddingRight = Std.string(CELL_HORIZONTAL_SPACE) + "%";
		node.style.paddingTop = Std.string(CELL_VERTICAL_SPACE) + "px";
		node.style.paddingBottom = Std.string(CELL_VERTICAL_SPACE) + "px";
		
		node.style.width = Std.string(100 - 2*CELL_HORIZONTAL_SPACE) + "%";
		
		// apply border
		CellStyle.addBorder(node,Constants.CELL_BORDER_WIDTH);
		//node.style.borderStyle = "none none solid none";

		node.style.backgroundColor = Constants.CELL_BG_COLOR;

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

		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		
		node.style.fontSize = "15px";
		node.style.lineHeight = "normal";
		node.style.fontWeight = "bold";
		node.style.fontStyle = "normal";
		node.style.fontFamily = 'Arial, sans-serif';
		node.style.fontVariant = "normal";
		node.style.textTransform = "none";
		node.style.letterSpacing = "normal";
		node.style.wordSpacing = "normal";
		node.style.textIndent = "0px";
		node.style.whiteSpace = "normal";
		node.style.textAlign = "left";
		
		node.style.verticalAlign = "middle";
		
		node.style.color = '#666666';
	}
	
	/**
	 * Defines cell line Style
	 * 
	 * @param	node
	 */
	public static function setCellLineStyle(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.position = "relative";

		node.style.width = "100%";
		node.style.height = Std.string(1) + "px";
		node.style.marginTop = Std.string(CELL_VERTICAL_SPACE) + "px";
	}
	
}
