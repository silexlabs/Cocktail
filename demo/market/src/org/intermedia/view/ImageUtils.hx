/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.model.ApplicationModel;
import cocktail.viewport.Viewport;

/**
 * This class defines a cropped image, i.e. an image cropped by a containerDOM used as a mask
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
			maskPixelSize.width = Std.int(new Viewport().width * thumbWidthPercent / (cellPerLine * 100));
			//maskPixelSize.width = Std.int(new Viewport().width / cellPerLine );
		}
		else
		{
			//maskWidthPercent = thumbWidthPercent;
			maskPixelSize.width = Std.int(new Viewport().width * thumbWidthPercent / 100);
			//maskPixelSize.width = Std.int(new Viewport().width);
		}
		
		// compute height depending on the width
		//maskPixelSize.height = Std.int(maskPixelSize.width / CELL_RATIO);
		maskPixelSize.height = Constants.CELL_HEIGHT;

		return maskPixelSize;
		
	}
	
	/**
	 * Automatically crops an image so it fits in the mask size
	 * 
	 * @param	domElement
	 * @param	maskSize
	 */
	public static function cropImage(image:ImageDOMElement, maskSize:Size):ContainerDOMElement
	{
		// create and set mask image container
		var mask:ContainerDOMElement = new ContainerDOMElement();
		mask.style.width = DimensionStyleValue.length(px(maskSize.width));
		mask.style.height = DimensionStyleValue.length(px(maskSize.height));
		
		// aply mask style so it can crop the image
		mask.style.overflow = { x:OverflowStyleValue.hidden, y:OverflowStyleValue.hidden };
		mask.style.display = DisplayStyleValue.inlineBlock;

		// mask ratio
		var maskRatio:Float = maskSize.width / maskSize.height;
		
		// image ratio
		var imageRatio:Float = 0;
		if (image.intrinsicHeight != 0)
			imageRatio = image.intrinsicWidth / image.intrinsicHeight;
			
		var resizedImageSize:Size = { width:0, height:0 };

		// if imageRatio is bigger than cell ratio, set image height to cell height
		if(imageRatio > maskRatio)
		{
			// compute new image size
			resizedImageSize.height = maskSize.height;
			resizedImageSize.width = Std.int(resizedImageSize.height * imageRatio);
	
			// resize image
			image.style.height = DimensionStyleValue.length(px(resizedImageSize.height));
			
			// offsets image
			image.style.marginLeft = MarginStyleValue.length(px(-Math.abs((maskSize.width-resizedImageSize.width))/2));
		}
		// else, set image width to cell width
		else
		{
			// compute new image size
			resizedImageSize.width = maskSize.width;
			resizedImageSize.height = Std.int(resizedImageSize.width / imageRatio);
			
			// resize image
			image.style.width = DimensionStyleValue.length(px(resizedImageSize.width));
			
			// offsets image
			image.style.marginTop = MarginStyleValue.length(px(-Math.abs((maskSize.height-resizedImageSize.height))/2));
		}
		
		// attach image to mask
		mask.addChild(image);
		
		return mask;
	}
	
}
