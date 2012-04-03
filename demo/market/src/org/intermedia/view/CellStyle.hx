/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

// DOM
import cocktail.domElement.DOMElement;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;


/**
 * This class defines the styles used by the CellThumb
 * 
 * @author Raphael Harmel
 */

class CellStyle
{
	
	//static inline var CELL_RATIO:Float = 16/9;

	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 * @return	thumbNail mask size, here cell size
	 */
	public static function setCellStyle(domElement:DOMElement,?cellPerLine:Int=1):Void
	{
		domElement.style.display = DisplayStyleValue.inlineBlock;
		domElement.style.position = PositionStyleValue.staticStyle;
		
		domElement.style.marginLeft = MarginStyleValue.length(px(0));
		domElement.style.marginRight = MarginStyleValue.length(px(0));
		domElement.style.marginTop = MarginStyleValue.length(px(0));
		domElement.style.marginBottom = MarginStyleValue.length(px(0));
		
		domElement.style.paddingLeft = PaddingStyleValue.length(px(0));
		domElement.style.paddingRight = PaddingStyleValue.length(px(0));
		domElement.style.paddingTop = PaddingStyleValue.length(px(0));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Int = computeWidthPercentage(cellPerLine);
		domElement.style.width = DimensionStyleValue.percent(cellWidthPercent);
		//domElement.style.height = Std.int(maskPixelSize.width / CELL_RATIO);
		
		domElement.style.verticalAlign = VerticalAlignStyleValue.top;

		//domElement.style.overflow = { x:OverflowStyleValue.hidden, y:OverflowStyleValue.hidden };
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
	
	public static function addBorder(domElement:DOMElement):Void
	{
		// add border
		domElement.nativeElement.style.borderWidth = Constants.CELL_BORDER_WIDTH;
		domElement.nativeElement.style.borderColor = Constants.CELL_BORDER_COLOR;
		domElement.nativeElement.style.borderStyle = "solid";
	}
	
	public static function removeBorder(domElement:DOMElement):Void
	{
		domElement.nativeElement.style.borderStyle = "none";
	}
	
}
