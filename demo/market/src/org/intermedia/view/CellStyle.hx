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
 * This class defines the styles used by the CellThumb
 * 
 * @author Raphael Harmel
 */

class CellStyle
{
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 * @return	thumbNail mask size, here cell size
	 */
	public static function setCellStyle(node:HtmlDom,?cellPerLine:Int=1):Void
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
		
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Float = computeWidthPercentage(cellPerLine);
		node.style.width = Std.string(cellWidthPercent) + "%";
		//node.style.height = Std.int(maskPixelSize.width / CELL_RATIO);
		
		// compute cell width in pixels depending on cellPerLine value
		// 2 pixels are removed so that adding borders does not mess up layout
		//var cellWidthPixels:Int = computeWidthPixels(cellPerLine);
		//node.style.width = Std.string(cellWidthPixels - (2 * Constants.CELL_BORDER_WIDTH)) + "px";
		//node.style.height = Std.int(maskPixelSize.width / CELL_RATIO);
		
		node.style.verticalAlign = "top";

		//node.style.overflow = "hidden";
		
		node.style.backgroundColor = Constants.CELL_BG_COLOR;
	}
	
	/**
	 * computes cell width percentage
	 * 
	 * @param	cellPerLine
	 * @return
	 */
	public static function computeWidthPercentage(cellPerLine):Float
	{
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Float = 100;
		
		if (cellPerLine != 0)
		{
			/*if (cellPerLine == 1)
			{
				// workaround so lines with 1 cell is aligned to those with two cells
				cellWidthPercent -= 2;
			}
			else
			{*/
				//cellWidthPercent = Std.int( 100 / cellPerLine);
				cellWidthPercent = 100 / cellPerLine;
				cellWidthPercent -= 1;
			//}
		}
		
		return cellWidthPercent;
	}
	
	/**
	 * Computes cell width in pixel
	 * 
	 * @param	cellPerLine
	 * @return
	 */
	public static function computeWidthPixels(cellPerLine):Int
	{
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPixels:Int = Lib.window.innerWidth;
		
		if (cellPerLine != 0)
		{
			cellWidthPixels = Std.int( cellWidthPixels / cellPerLine);
		}
		
		return cellWidthPixels;
	}
	
	/**
	 * Adds a border to the node, using CCS styles
	 * 
	 * @param	node
	 */
	public static function addBorder(node:HtmlDom):Void
	{
		// add border
	//	node.style.borderWidth = Std.string(Constants.CELL_BORDER_WIDTH) + "px";
	//	node.style.borderColor = Constants.CELL_BORDER_COLOR;
	//	node.style.borderStyle = "solid";
	}
	
	/**
	 * Removes a border to the node, using CCS styles
	 * 
	 * @param	node
	 */
	public static function removeBorder(node:HtmlDom):Void
	{
		//node.style.borderStyle = "none";
	}
	
}
