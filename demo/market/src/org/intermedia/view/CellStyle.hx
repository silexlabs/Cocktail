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
		
		node.style.verticalAlign = "top";

		//node.style.overflowX = "hidden";
		//node.style.overflowY = "hidden";
		
		node.style.backgroundColor = Constants.CELL_BG_COLOR;
	}
	
	/**
	 * computes cell width percentage
	 * 
	 * @param	cellPerLine
	 * @return
	 */
	public static function computeWidthPercentage(cellPerLine:Int, ?borderWidth:Int=0):Float
	{
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Float = 100;
		
		if (cellPerLine != 0)
		{
			// cell width percent equals to 100/cellPerLine - left border - last right border
			cellWidthPercent = (100 / cellPerLine)
				- ( borderWidth * 100 / Lib.window.innerWidth)
				- ( borderWidth * 100 / (Lib.window.innerWidth * cellPerLine)) ;
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
	public static function addBorder(node:HtmlDom, borderWidth:Int):Void
	{
		// add border using margin and background as not supported by cocktail yet
		node.style.marginTop = Std.string(borderWidth) + "px";
		node.style.marginLeft = Std.string(borderWidth) + "px";
		// reduce width accordingly
		// if unit is %
		/*if (node.style.width.substr(-1) == "%")
		{
			//Firebug.trace(node.style.width);
			//Firebug.trace(node.style.width.substr(0, -1));
			node.style.width = Std.string( Std.parseInt(node.style.width.substr(0, -1)) - (borderWidth/Lib.window.innerWidth) ) + "%";
			Firebug.trace(node.style.width);
		}
		// if unit is px
		else if (node.style.width.substr( -2) == "px")
		{
			node.style.width = Std.string( Std.parseInt(node.style.width.substr(0, -2)) - borderWidth ) + "px";
		}*/
		
	}
	
	/*public static function addBorderCss(node:HtmlDom):Void
	{
		// add border
		node.style.borderWidth = Std.string(Constants.CELL_BORDER_WIDTH) + "px";
		node.style.borderColor = Constants.CELL_BORDER_COLOR;
		node.style.borderStyle = "solid";
	}*/
	
	/**
	 * Removes a border to the node, using CCS styles
	 * 
	 * @param	node
	 */
	public static function removeBorder(node:HtmlDom):Void
	{
		// remove border
		//node.style.borderStyle = "none";
		
		// remove border using margin as not supported by cocktail yet
		node.style.margin = "0px";
	}
	
}
