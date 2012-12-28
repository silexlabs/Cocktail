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
	public static function setCellStyle(node:HtmlDom,?cellPerLine:Int=1):Void
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

		node.style.backgroundColor = Constants.CELL_BG_COLOR;

		node.style.cursor = "pointer";
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
		
		node.style.fontSize = "16px";
		node.style.lineHeight = "normal";
		node.style.fontWeight = "normal";
		node.style.fontStyle = "normal";
		node.style.fontFamily = 'Arial, sans-serif';
		node.style.fontVariant = "normal";
		node.style.textTransform = "none";
		node.style.letterSpacing = "normal";
		node.style.wordSpacing = "normal";
		node.style.textIndent = "0px";
		node.style.whiteSpace = "normal";
		node.style.textAlign = "justify";
		
		node.style.verticalAlign = "middle";
		
		node.style.color = Constants.CELL_FONT_COLOR;
	}
	
}
