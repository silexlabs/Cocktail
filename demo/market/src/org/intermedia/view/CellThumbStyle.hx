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
		
<<<<<<< HEAD
		node.style.height = Std.string(Constants.CELL_HEIGHT) + "px";
		node.style.maxHeight = Std.string(Constants.CELL_MAX_HEIGHT) + "px";

=======
		// compute cell width in percentage depending on cellPerLine value
		var cellWidthPercent:Float = CellStyle.computeWidthPercentage(cellPerLine,Constants.CELL_BORDER_WIDTH_LARGE);
		node.style.width = Std.string(cellWidthPercent) + "%";

		node.style.height = Std.string(Constants.CELL_HEIGHT) + "px";
		node.style.maxHeight = Std.string(Constants.CELL_MAX_HEIGHT) + "px";

>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		
		// apply border
<<<<<<< HEAD
		CellStyle.addBorder(node);
=======
		CellStyle.addBorder(node,Constants.CELL_BORDER_WIDTH);
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	}
	
	
	/**
	 * Defines image mask Style
<<<<<<< HEAD
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
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	 * 
	 * @param	mask
	 */
<<<<<<< HEAD
	/*public static function setThumbnailStyle(image:Image,maskSize:Size):Void
=======
	public static function setThumbnailMaskStyle(node:HtmlDom):Void
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	{
		node.style.width = Std.string(100) + "%";
		node.style.height = Std.string(100) + "%";
		
<<<<<<< HEAD
	}*/
=======
		// apply mask style so it can crop the image
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		node.style.display = "inline-block";
	}
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	
}
