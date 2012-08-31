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
 * This class defines the styles used by the Cells
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
	 * Adds a border to the node, using workaround as not supported by cocktail yet
	 * 
	 * @param	node
	 */
	public static function addBorder(node:HtmlDom, borderWidth:Int):Void
	{
		// add border using margin and background as not supported by cocktail yet
		node.style.marginBottom = Std.string(borderWidth) + "px";
		node.style.marginLeft = Std.string(borderWidth) + "px";
	}
	
	/**
	 * Adds a border to the node, using CCS styles
	 * 
	 * @param	node
	 */
	/*public static function addBorderCss(node:HtmlDom):Void
	{
		// add border
		node.style.borderWidth = Std.string(Constants.CELL_BORDER_WIDTH) + "px";
		node.style.borderColor = Constants.CELL_BORDER_COLOR;
		node.style.borderStyle = "solid";
	}*/
	
	/**
	 * Removes the border of the node, using workaround as not supported by cocktail yet
	 * 
	 * @param	node
	 */
	public static function removeBorder(node:HtmlDom):Void
	{
		// remove border using margin as not supported by cocktail yet
		node.style.marginBottom = "0px";
		node.style.marginTop = "0px";
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
	}
	
	/**
	 * Removes the border of the node, using CCS styles
	 * 
	 * @param	node
	 */
	/*public static function removeBorderCss(node:HtmlDom):Void
	{
		// remove border
		node.style.borderStyle = "none";
	}*/
	
}
