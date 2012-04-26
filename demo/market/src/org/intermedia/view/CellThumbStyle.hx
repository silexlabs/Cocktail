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
 * This class defines the styles used by the CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumbStyle
{
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 * @return	thumbNail mask size, here cell size
	 */
	public static function setCellStyle(node:HtmlDom, ?cellPerLine:Int=1):Void
	{
		// use default style
		CellStyle.setCellStyle(node, cellPerLine);
		
		node.style.height = Std.string(Constants.CELL_HEIGHT) + "px";
		node.style.maxHeight = Std.string(Constants.CELL_MAX_HEIGHT) + "px";

		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		
		// apply border
		CellStyle.addBorder(node);
	}
	
	
	/**
	 * Defines image mask Style
	 * 
	 * @param	mask
	 */
	public static function setThumbnailMaskStyle(node:HtmlDom):Void
	{
		node.style.width = Std.string(100) + "%";
		node.style.height = Std.string(100) + "%";
		
		// apply mask style so it can crop the image
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		node.style.display = "inline-block";
		//untyped { node.style.borderRadius = "10px"; };
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	image
	 */
	/*public static function setThumbnailStyle(image:Image,maskSize:Size):Void
	{
		//var imageMaxWidth:Int = 200;
		
		image.style.display = "inline";
		
		image.style.verticalAlign = "middle";
		untyped { image.style.opacity = 0; };
		
		//zoomImage(node, maskSize);
		ImageUtils.cropImage(image, maskSize);
		
	}*/
	
	/**
	 * Automatically resizes and offsets the image so it adapts to the cell size
	 * 
	 * @param	node
	 * @param	maskSize
	 */
	/*public static function zoomImage(node:HtmlDom, maskSize:Size):Void
	{
		
		var imageRatio:Float = 0;
		if (node.intrinsicHeight != 0)
			imageRatio = node.intrinsicWidth / node.intrinsicHeight;
			
		var resizedImageSize:Size = { width:0, height:0 };

		// if imageRatio is bigger than cell ratio, set image height to cell height
		if(imageRatio > CELL_RATIO)
		{
			// compute new image size
			resizedImageSize.height = maskSize.height;
			resizedImageSize.width = Std.int(resizedImageSize.height * imageRatio);
	
			// resize image
			node.style.height = Std.string(resizedImageSize.height));
			
			// offsets image
			node.style.marginLeft = Std.string(-Math.abs((maskSize.width-resizedImageSize.width))/2));
		}
		// else, set image width to cell width
		else
		{
			// compute new image size
			resizedImageSize.width = maskSize.width;
			resizedImageSize.height = Std.int(resizedImageSize.width / imageRatio);
			
			// resize image
			node.style.width = Std.string(resizedImageSize.width));
			
			// offsets image
			node.style.marginTop = Std.string(-Math.abs((maskSize.height-resizedImageSize.height))/2));
		}
				
	}*/
	
}
