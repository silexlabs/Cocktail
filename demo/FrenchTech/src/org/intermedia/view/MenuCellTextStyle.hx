/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
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
	static inline var CELL_VERTICAL_SPACE:Int = 7;
	static inline var CELL_HORIZONTAL_PADDING:Int = 5;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 */
	public static function setCellStyle(node:HtmlDom,?cellPerLine:Int=1):Void
	{
		node.style.display = "inline-block";
		node.style.position = "absolute";
		
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		node.style.marginTop = "0px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";
		node.style.paddingTop = Std.string(CELL_VERTICAL_SPACE) + "px";
		node.style.paddingBottom = Std.string(CELL_VERTICAL_SPACE) + "px";
		
		node.style.width = "auto";

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
		node.style.fontStyle = "normal";
		node.style.fontFamily = 'Arial, sans-serif';
		node.style.fontVariant = "normal";
		node.style.textTransform = "none";
		node.style.letterSpacing = "normal";
		node.style.wordSpacing = "normal";
		node.style.textIndent = "0px";
		node.style.whiteSpace = "normal";
		
		node.style.verticalAlign = "middle";
		
		node.style.color = Constants.MENU_FONT_COLOR;
	}
	
}
