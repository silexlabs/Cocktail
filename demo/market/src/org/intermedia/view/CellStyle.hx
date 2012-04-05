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
		var cellWidthPercent:Int = computeWidthPercentage(cellPerLine);
		node.style.width = Std.string(cellWidthPercent) + "%";
		//node.style.height = Std.int(maskPixelSize.width / CELL_RATIO);
		
		node.style.verticalAlign = "top";

		//node.style.overflow = "hidden";
	}
	
	public static function computeWidthPercentage(cellPerLine):Int
	{
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Int = 100;
		
		if (cellPerLine != 0)
		{
			cellWidthPercent = Std.int( 100 / cellPerLine);
		}
		
		return cellWidthPercent;
	}
	
	public static function addBorder(node:HtmlDom):Void
	{
		// add border
		node.style.borderWidth = Constants.CELL_BORDER_WIDTH;
		node.style.borderColor = Constants.CELL_BORDER_COLOR;
		node.style.borderStyle = "solid";
	}
	
	public static function removeBorder(node:HtmlDom):Void
	{
		node.style.borderStyle = "none";
	}
	
}
