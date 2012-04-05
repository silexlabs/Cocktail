/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

import cocktail.domElement.DOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.viewport.Viewport;
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.model.ApplicationModel;


/**
 * This class defines the styles used by the CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumbStyle
{
	static inline var CELL_VERTICAL_SPACE:Int = Constants.CELL_VERTICAL_SPACE;
	static inline var CELL_RATIO:Float = 16/9;
	static inline var CELL_MAX_HEIGHT:Float = 150;
	static inline var CELL_HEIGHT:Float = 100;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 * @return	thumbNail mask size, here cell size
	 */
	//public static function setCellStyle(domElement:DOMElement, ?cellPerLine:Int=1, ?thumbWidthPercent:Int=100):Size
	public static function setCellStyle(domElement:DOMElement, ?cellPerLine:Int=1):Size
	{
		// use default style
		CellStyle.setCellStyle(domElement, cellPerLine);
		
		//domElement.style.display = DisplayStyleValue.inlineBlock;
		//domElement.style.position = PositionStyleValue.staticStyle;
		//
		//domElement.style.marginLeft = MarginStyleValue.length(px(0));
		//domElement.style.marginRight = MarginStyleValue.length(px(0));
		//domElement.style.marginTop = MarginStyleValue.length(px(0));
		//domElement.style.marginBottom = MarginStyleValue.length(px(0));
		//
		//domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		//domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(CELL_VERTICAL_SPACE));
		//domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		
		//domElement.style.verticalAlign = VerticalAlignStyleValue.top;

		// compute cell width in percentage depending on cellPerLine value
		//var cellWidthPercent:Int = CellStyle.computeWidthPercentage(cellPerLine);
		//domElement.style.width = DimensionStyleValue.percent(cellWidthPercent);
		
		
		// compute cell size in pixel depending on cellPerLine value
		//var cellSize:Size = computeMaskSize(cellPerLine, thumbWidthPercent);
		var cellSize:Size = ImageUtils.computeMaskSize(cellPerLine);
		
		domElement.style.height = DimensionStyleValue.length(px(cellSize.height));
		//domElement.style.maxHeight = ConstrainedDimensionStyleValue.length(px(CELL_MAX_HEIGHT));

		domElement.style.overflow = { x:OverflowStyleValue.hidden, y:OverflowStyleValue.hidden };
		
		// apply border
		CellStyle.addBorder(domElement);
		
		return cellSize;
	}
	
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function setThumbnailStyle(domElement:ImageDOMElement,maskSize:Size):Void
	{
		//var imageMaxWidth:Int = 200;
		
		domElement.style.display = DisplayStyleValue.inlineStyle;
		
		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;
		domElement.style.opacity = OpacityStyleValue.number(0);
		
		//zoomImage(domElement, maskSize);
		ImageUtils.cropImage(domElement, maskSize);
		
	}
	
	/**
	 * Automatically resizes and offsets the image so it adapts to the cell size
	 * 
	 * @param	domElement
	 * @param	maskSize
	 */
	/*public static function zoomImage(domElement:ImageDOMElement, maskSize:Size):Void
	{
		
		var imageRatio:Float = 0;
		if (domElement.intrinsicHeight != 0)
			imageRatio = domElement.intrinsicWidth / domElement.intrinsicHeight;
			
		var resizedImageSize:Size = { width:0, height:0 };

		// if imageRatio is bigger than cell ratio, set image height to cell height
		if(imageRatio > CELL_RATIO)
		{
			// compute new image size
			resizedImageSize.height = maskSize.height;
			resizedImageSize.width = Std.int(resizedImageSize.height * imageRatio);
	
			// resize image
			domElement.style.height = DimensionStyleValue.length(px(resizedImageSize.height));
			
			// offsets image
			domElement.style.marginLeft = MarginStyleValue.length(px(-Math.abs((maskSize.width-resizedImageSize.width))/2));
		}
		// else, set image width to cell width
		else
		{
			// compute new image size
			resizedImageSize.width = maskSize.width;
			resizedImageSize.height = Std.int(resizedImageSize.width / imageRatio);
			
			// resize image
			domElement.style.width = DimensionStyleValue.length(px(resizedImageSize.width));
			
			// offsets image
			domElement.style.marginTop = MarginStyleValue.length(px(-Math.abs((maskSize.height-resizedImageSize.height))/2));
		}
				
	}*/
	
}
