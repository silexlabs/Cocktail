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
	 * @param	node
	 */
	public static function setLoadingStyle(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.position = "absolute";
		
		//node.style.width = "100%";
		node.style.width = Std.string(Lib.window.innerWidth) + "px";
		//node.style.height = "100%";
		node.style.height = Std.string(Lib.window.innerHeight) + "px";
		
		node.style.textAlign = "center";
		
		node.style.top = "0px";
		node.style.bottom = "0px";
		
		//node.style.backgroundImage = [BackgroundImageStyleValue.image(ImageValue.url("assets/headerGrey.jpg"))];
		//node.style.backgroundColor = BackgroundColorStyleValue.colorValue(ColorValue.rgba(255, 255, 255, 1));
		node.style.color = '#FFFFFF';
		
		//node.style.zIndex = 1000;
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	node
	 */
	public static function setThumbnailStyle(node:HtmlDom):Void
	{
		node.style.position = "relative";
		
		node.style.marginTop = "auto";
		node.style.marginBottom = "auto";
		node.style.marginLeft = "auto";
		node.style.marginRight = "auto";
		
		node.style.top = "45%";
		
	}
	
}
