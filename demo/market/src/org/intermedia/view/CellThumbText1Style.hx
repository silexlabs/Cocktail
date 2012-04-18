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

class CellThumbText1Style
{
	static inline var CELL_VERTICAL_SPACE:Int = Constants.CELL_VERTICAL_SPACE;
	static inline var CELL_TEXT_WIDTH_PERCENT:Int = 60;
	public static inline var CELL_THUMB_WIDTH_PERCENT:Int = 100 - CELL_TEXT_WIDTH_PERCENT - 5;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 * @param	?cellPerLine
	 * @return	thumb mask size
	 */
	public static function setCellStyle(node:HtmlDom,?cellPerLine:Int=1):Size
	{
		CellStyle.setCellStyle(node,cellPerLine);
		
		// compute cell size in pixel depending on cellPerLine value
		//var cellSize:Size = computeMaskSize(cellPerLine, thumbWidthPercent);
		var cellSize:Size = ImageUtils.computeMaskSize(cellPerLine,CELL_THUMB_WIDTH_PERCENT);
		
		node.style.height = Std.string(cellSize.height) + "px";
		//node.style.maxHeight = Std.string(CELL_MAX_HEIGHT) + "px";

		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		
		// apply border
		CellStyle.addBorder(node);
		
		return cellSize;

	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	image
	 */
	public static function setThumbnailStyle(image:Image,maskSize:Size):Void
	{
		CellThumbStyle.setThumbnailStyle(image,maskSize);
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
		node.style.color = '#202020';
		node.style.fontFamily = 'Arial, sans-serif';
	}

	/**
	 * Defines cell title Style
	 * 
	 * @param	node
	 */
	public static function setTitleStyle(node:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	{
		setTextStyle(node);
		
		if (screenResolutionSize == null)
			screenResolutionSize = ScreenResolutionSize.small;
		
		var fontSize:Int = 14;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 14;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 16;
		else  fontSize = 18;
		
		node.style.fontSize = Std.string(fontSize) + "px";
		//node.style.fontWeight = "bold";
	}

	/**
	 * Defines cell comment Style
	 * 
	 * @param	node
	 */
	public static function setAuthorStyle(node:HtmlDom,?screenResolutionSize:ScreenResolutionSize):Void
	{
		setTextStyle(node);

		var fontSize:Int = 10;
		if (screenResolutionSize == ScreenResolutionSize.small) fontSize = 10;
		else if (screenResolutionSize == ScreenResolutionSize.normal) fontSize = 11;
		else  fontSize = 12;
		
		node.style.fontSize = Std.string(fontSize) + "px";
		node.style.fontWeight = "normal";
	}
	
	/**
	 * Defines cell line Style
	 * 
	 * @param	node
	 */
	public static function setLineStyle(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.position = "relative";

		node.style.width = "100%";
		node.style.height = "1px";
		node.style.marginTop = Std.string(CELL_VERTICAL_SPACE) + "px";	
	}
	
}
