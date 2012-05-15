/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
	public static inline var CELL_TOP_MARGIN_PERCENT:Int = 8;
	
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
		node.style.marginTop = Std.string(CELL_TOP_MARGIN_PERCENT) + "%";
		node.style.marginLeft = "3%";

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
		
		node.style.marginTop = Std.string(Std.int(CELL_TOP_MARGIN_PERCENT/2)) + "%";
		node.style.marginLeft = "3%";
		
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
