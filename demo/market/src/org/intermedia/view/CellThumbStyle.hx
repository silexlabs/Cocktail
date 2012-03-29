/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

// DOM
import cocktail.domElement.DOMElement;
import cocktail.domElement.ContainerDOMElement;
import cocktail.domElement.ImageDOMElement;
import cocktail.domElement.GraphicDOMElement;

// Native Elements
import cocktail.nativeElement.NativeElementManager;
import cocktail.nativeElement.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.view.ScreenResolution;


/**
 * This class defines the styles used by the CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumbStyle
{
	static inline var CELL_VERTICAL_SPACE:Int = Constants.CELL_VERTICAL_SPACE;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
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
		//domElement.style.paddingLeft = PaddingStyleValue.percent(1);
		//domElement.style.paddingRight = PaddingStyleValue.percent(1);
		domElement.style.paddingTop = PaddingStyleValue.length(px(CELL_VERTICAL_SPACE));
		domElement.style.paddingBottom = PaddingStyleValue.length(px(0));
		
		// compute cell width depending on cellPerLine value
		var cellPercentWidth:Int = 0;
		//if (cellPerLine != 0) cellPercentWidth = Std.int(100 / cellPerLine) - 1;
		if (cellPerLine != 0) cellPercentWidth = Std.int(100 / cellPerLine);
		else cellPercentWidth = 100;
		domElement.style.width = DimensionStyleValue.percent(cellPercentWidth);
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function setThumbnailStyle(domElement:DOMElement):Void
	{
		var imageMaxWidth:Int = 200;
		
		//setCellStyle(domElement);
		
		domElement.style.display = DisplayStyleValue.inlineStyle;
		
		//domElement.style.paddingLeft = PaddingStyleValue.percent(0);
		//domElement.style.paddingRight = PaddingStyleValue.percent(0);
		//domElement.style.paddingLeft = PaddingStyleValue.length(px(5));
		//domElement.style.paddingRight = PaddingStyleValue.length(px(5));

		domElement.style.verticalAlign = VerticalAlignStyleValue.middle;

		domElement.style.maxWidth = ConstrainedDimensionStyleValue.length(px(imageMaxWidth));
		domElement.style.maxHeight = ConstrainedDimensionStyleValue.percent(50);
		domElement.style.width = DimensionStyleValue.percent(100);	

		domElement.style.opacity = OpacityStyleValue.number(0);
		
	}
	
}
