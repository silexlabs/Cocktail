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
import org.intermedia.model.ApplicationModel;

/**
 * This class defines utilities methods for images
 * 
 * @author Raphael Harmel
 */

class ImageUtils
{

	/**
	 * computes the thumb mask size
	 * 
	 * @param	?cellPerLine				number of cells per line
	 * @param	?thumbWidthPercent = 100	thumb percentage of the cell
	 * @return
	 */
	public static function computeMaskSize(cellPerLine:Int, ?thumbWidthPercent:Int=100):Size
	{
		var maskPixelSize:Size = { width:0, height:0 };
		
		// compute cell width depending on cellPerLine value
		//var maskWidthPercent:Int = 100;
		if (cellPerLine != 0)
		{
			//maskWidthPercent = Std.int(thumbWidthPercent / cellPerLine);
			maskPixelSize.width = Std.int(Lib.window.innerWidth * thumbWidthPercent / (cellPerLine * 100));
			//maskPixelSize.width = Std.int(Lib.window.innerWidth / cellPerLine );
		}
		else
		{
			//maskWidthPercent = thumbWidthPercent;
			maskPixelSize.width = Std.int(Lib.window.innerWidth * thumbWidthPercent / 100);
			//maskPixelSize.width = Std.int(Lib.window.innerWidth);
		}
		
		// compute height depending on the width
		//maskPixelSize.height = Std.int(maskPixelSize.width / CELL_RATIO);
		maskPixelSize.height = Constants.CELL_HEIGHT;

		return maskPixelSize;
		
	}
	
	/**
	 * Automatically crops an image so it fits in the mask size
	 * 
	 * @param	node
	 * @param	maskSize
	 */
	public static function cropImage(image:Image, maskSize:Size):Image
	{
		// compute mask ratio
		var maskRatio:Float = maskSize.width / maskSize.height;
		
		// image ratio
		var imageRatio:Float = 0;
		if ((untyped { image.naturalHeight; }) != 0)
			imageRatio = (untyped { image.naturalWidth / image.naturalHeight; } );
			
		var resizedImageSize:Size = { width:0, height:0 };

		// if imageRatio is bigger than cell ratio, set image height to cell height
		if(imageRatio > maskRatio)
		{
			// compute new image size
			resizedImageSize.height = maskSize.height;
			resizedImageSize.width = Std.int(resizedImageSize.height * imageRatio);
	
			// resize image
			image.style.width = Std.string(resizedImageSize.width) + "px";
			image.style.height = Std.string(resizedImageSize.height) + "px";
			
			// offsets image
			image.style.marginTop = "0px";
			image.style.marginLeft = Std.string(-Math.abs((maskSize.width-resizedImageSize.width))/2) + "px";
		}
		// else, set image width to cell width
		else
		{
			// compute new image size
			resizedImageSize.width = maskSize.width;
			resizedImageSize.height = Std.int(resizedImageSize.width / imageRatio);
			
			// resize image
			image.style.width = Std.string(resizedImageSize.width) + "px";
			image.style.height = Std.string(resizedImageSize.height) + "px";
			
			// offsets image
			image.style.marginTop = Std.string( -Math.abs((maskSize.height - resizedImageSize.height)) / 2) + "px";
			image.style.marginLeft = "0px";
		}
		
		//return image;
		return image;
	}
	
}
