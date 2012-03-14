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
import cocktail.viewport.Viewport;

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

class LoadingViewStyle
{
	static inline var CELL_VERTICAL_SPACE:Int = 5;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function setLoadingStyle(domElement:DOMElement):Void
	{
		domElement.style.display = DisplayStyleValue.block;
		domElement.style.position = PositionStyleValue.absolute;
		
		domElement.style.width = DimensionStyleValue.percent(100);
		domElement.style.height = DimensionStyleValue.percent(100);
		
		domElement.style.textAlign = TextAlignStyleValue.center;
		
		domElement.style.top = PositionOffsetStyleValue.length(px(0));
		domElement.style.bottom = PositionOffsetStyleValue.length(px(0));
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function setThumbnailStyle(domElement:DOMElement):Void
	{
		domElement.style.position = PositionStyleValue.relative;
		
		domElement.style.marginTop = MarginStyleValue.autoValue;
		domElement.style.marginBottom = MarginStyleValue.autoValue;
		domElement.style.marginLeft = MarginStyleValue.autoValue;
		domElement.style.marginRight = MarginStyleValue.autoValue;
		
		domElement.style.top = PositionOffsetStyleValue.percent(45);
		
	}
	
}
