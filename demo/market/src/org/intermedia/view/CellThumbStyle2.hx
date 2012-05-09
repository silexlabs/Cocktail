/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

// DOM
import cocktail.node.DOMElement;
import cocktail.node.HtmlDom;
import cocktail.node.HtmlDom;
import cocktail.node.GraphicDOMElement;

// Native Elements
import cocktail.NativeElementManager;
import cocktail.NativeElementData;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.view.ScreenResolution;


/**
 * This class defines the styles used by the CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumbStyle2
{
	static inline var CELL_VERTICAL_SPACE:Int = Constants.CELL_VERTICAL_SPACE;
	
	/**
	 * Defines cell Style
	 * 
	 * @param	node
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
		node.style.paddingTop = Std.string(CELL_VERTICAL_SPACE) + "px";
		node.style.paddingBottom = "0px";
		
		// compute cell width depending on cellPerLine value
		var cellPercentWidth:Int = 0;
		//if (cellPerLine != 0) cellPercentWidth = Std.int(100 / cellPerLine) - 1;
		if (cellPerLine != 0) cellPercentWidth = Std.int(100 / cellPerLine);
		else cellPercentWidth = 100;
		node.style.width = Std.string(cellPercentWidth) + "%";
		node.style.height = Std.string(70)) + "%";
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	node
	 */
	public static function setThumbnailStyle(node:HtmlDom):Void
	{
		node.style.display = "inline";
		
		node.style.verticalAlign = "middle";

		//node.style.maxHeight = ConstrainedStd.string(156));
		//node.style.width = "100%";
		

		node.style.opacity = OpacityStyleValue.number(0);
		
	}
	
}
