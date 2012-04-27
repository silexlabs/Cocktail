/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
	static inline var CELL_TEXT_WIDTH_PERCENT:Int = 60;
	public static inline var CELL_THUMB_WIDTH_PERCENT:Int = 100 - CELL_TEXT_WIDTH_PERCENT - 5;
	
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
	
	/**
	 * Defines image mask Style
	 * 
	 * @param	mask
	 */
/*	public static function setThumbnailMaskStyle(node:HtmlDom):Void
	{
		node.style.width = Std.string(CELL_THUMB_WIDTH_PERCENT) + "%";
		node.style.height = Std.string(100) + "%";
		
		// apply mask style so it can crop the image
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		node.style.display = "inline-block";
		//untyped { node.style.borderRadius = "10px"; };
	}
	
	/**
	 * Defines cell text block Style
	 * 
	 * @param	node
	 */
/*	public static function setTextBlockStyle(node:HtmlDom):Void
	{
		//setCellStyle(node);
		
		node.style.display = "inline-block";
		node.style.marginLeft = "2%";
		node.style.verticalAlign = "top";
		node.style.width = Std.string(CELL_TEXT_WIDTH_PERCENT) + "%";
		
	}*/

}
