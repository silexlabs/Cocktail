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
import org.intermedia.view.ScreenResolution;
import org.intermedia.model.ApplicationModel;


/**
 * This class defines the styles used by the CellThumbText
 * 
 * @author Raphael Harmel
 */

class CellThumbText1BisStyle
{
	private static inline var CELL_TEXT_WIDTH_PERCENT:Int = 60;
	private static inline var CELL_THUMB_WIDTH_PERCENT:Int = 100 - CELL_TEXT_WIDTH_PERCENT - 5;
	
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
		
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Float = CellStyle.computeWidthPercentage(cellPerLine,Constants.CELL_BORDER_WIDTH_LARGE);
		node.style.width = Std.string(cellWidthPercent) + "%";

		node.style.height = Std.string(Constants.CELL_HEIGHT) + "px";
		node.style.maxHeight = Std.string(Constants.CELL_MAX_HEIGHT) + "px";

		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		
		// apply border
		CellStyle.addBorder(node,Constants.CELL_BORDER_WIDTH_LARGE);
		
	}
	
}
