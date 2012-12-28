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
import org.intermedia.model.ApplicationModel;


/**
 * This class defines the styles used by the CellThumbText
 * 
 * @author Raphael Harmel
 */

class CellThumbText1Style
{
	static inline var CELL_TEXT_WIDTH_PERCENT:Int = 60;
	public static inline var CELL_THUMB_WIDTH_PERCENT:Int = 100 - CELL_TEXT_WIDTH_PERCENT - 6;
	public static inline var CELL_TOP_MARGIN_PIXELS:Int = 14;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 * @param	?cellPerLine
	 * @return	thumb mask size
	 */
	public static function setCellStyle(node:HtmlDom,?cellPerLine:Int=1):Void
	{
		CellStyle.setCellStyle(node,cellPerLine);
		
		node.style.verticalAlign = "middle";
		
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Float = CellStyle.computeWidthPercentage(cellPerLine,Constants.CELL_BORDER_WIDTH);
		node.style.width = Std.string(cellWidthPercent) + "%";

		node.style.height = Std.string(Constants.CELL_HEIGHT) + "px";
		node.style.maxHeight = Std.string(Constants.CELL_MAX_HEIGHT) + "px";

		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		
		// apply border
		CellStyle.addBorder(node,Constants.CELL_BORDER_WIDTH);
		
	}
	
	/**
	 * Defines image mask Style
	 * 
	 * @param	mask
	 */
	public static function setThumbnailMaskStyle(node:HtmlDom):Void
	{
		node.style.marginTop = Std.string(CELL_TOP_MARGIN_PIXELS) + "px";
		node.style.marginLeft = "2%";

		node.style.width = Std.string(CELL_THUMB_WIDTH_PERCENT) + "%";
		node.style.height = Std.string(70) + "%";
		
		// apply mask style so it can crop the image
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		node.style.display = "inline-block";
	}
	
	/**
	 * Defines cell text block Style
	 * 
	 * @param	node
	 */
	public static function setTextBlockStyle(node:HtmlDom):Void
	{
		//setCellStyle(node);
		node.style.display = "inline-block";
		
		node.style.marginTop = Std.string(Std.int(CELL_TOP_MARGIN_PIXELS/2)) + "px";
		node.style.marginLeft = "2%";
		
		node.style.verticalAlign = "top";
		node.style.width = Std.string(CELL_TEXT_WIDTH_PERCENT) + "%";
		
	}

	/**
	 * Defines cell text Style
	 * 
	 * @param	node
	 */
	private static function setTextStyle(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.color = Constants.CELL_FONT_COLOR;
		node.style.fontFamily = 'Arial, sans-serif';
	}

	/**
	 * Defines cell title Style
	 * 
	 * @param	node
	 */
	public static function setTitleStyle(node:HtmlDom):Void
	{
		setTextStyle(node);
		
		node.style.fontSize = "14px";
	}

}
