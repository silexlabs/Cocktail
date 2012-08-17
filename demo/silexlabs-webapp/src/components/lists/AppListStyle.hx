/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package components.lists;

import js.Lib;
import js.Dom;

import Constants;

/**
 * This class defines the styles used by an App cell,
 * i.e. a list with each cell containing an image over a text, and having each cell next to the previous one

 * @author Raphael Harmel
 */

class AppListStyle
{
	static inline var cellWidth:Int = 62;
	static inline var cellHeight:Int = 43;
	
	/**
	 * Defines default Style
	 * 
	 * @param	domElement
	 */
	public static function getListStyle(domElement:HtmlDom):Void
	{
		domElement.style.position = "fixed";
		domElement.style.display = "inline-block";
		
		domElement.style.marginLeft = "0";
		domElement.style.marginRight = "0";
		domElement.style.marginTop = "0";
		domElement.style.marginBottom = "0";
		
		domElement.style.paddingLeft = "0";
		domElement.style.paddingRight ="0";
		domElement.style.paddingTop ="0";
		domElement.style.paddingBottom = "0";

		domElement.style.top = "auto";
		domElement.style.bottom = "0";
		domElement.style.left = "auto";
		domElement.style.right = "auto";
		domElement.style.minWidth = "100%";
		domElement.style.width = "100%";
		domElement.style.height = Constants.footerHeight + "px";

		domElement.style.textAlign = "center";

	}
	
	/**
	 * Defines cell Style
	 * 
	 * @param	domElement
	 */
	public static function getCellStyle(domElement:HtmlDom):Void
	{
		domElement.style.display = "inline-block";
		
		domElement.style.marginLeft = "0";
		domElement.style.marginRight = "0";
		domElement.style.marginTop = "2px";
		//domElement.style.marginBottom = MarginStyleValue.length(px(10));
		
		domElement.style.width = cellWidth + "px";
		domElement.style.height = cellHeight + "px";
		domElement.style.color = '#BDBDCE';
		
		// workaround for Samsung TVs
		//domElement.style.textAlign = TextAlignStyleValue.center;
	}
	
	/**
	 * Defines selected menu item image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellSelectedStyle(domElement:Image):Void
	{
		domElement.style.position = "absolute";
		domElement.style.display = "block";
		
		domElement.style.marginLeft = "0";
		domElement.style.marginRight = "0";
		domElement.style.marginTop = "0";
		domElement.style.marginBottom = "0";

		domElement.style.paddingLeft = "0";
		domElement.style.paddingRight = "0";
		domElement.style.paddingTop = "0";
		domElement.style.paddingBottom = "0";

		domElement.style.width = cellWidth  + "px" ;
		domElement.style.height = cellHeight + "px";
		domElement.style.bottom = "2px";
	}
	
	/**
	 * Defines cell image Style
	 * 
	 * @param	domElement
	 */
	public static function getCellImageStyle(domElement:HtmlDom):Void
	{
		domElement.style.display = "block";
		domElement.style.marginLeft = "auto";
		domElement.style.marginRight = "auto";
		domElement.style.height = "31px";
		domElement.style.marginBottom = "0";
	}
	
	/**
	 * Defines cell text Style
	 * 
	 * @param	domElement
	 */
	public static function getCellTextStyle(domElement:HtmlDom):Void
	{
		domElement.style.display = "block";
		domElement.style.marginTop = "0";
		domElement.style.color = '#999999';
		domElement.style.fontFamily = "HelveticaNeue, Sans-Serif";
		
		domElement.style.fontSize = "10px";
		domElement.style.fontWeight = "bold";
		domElement.style.textAlign = "center";
	}

	/**
	 * Defines mouse over Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOverStyle(domElement:HtmlDom):Void
	{

	}
	
	/**
	 * Defines mouse out Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseOutStyle(domElement:HtmlDom):Void
	{
	}
	
	/**
	 * Defines mouse down Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseDownStyle(domElement:HtmlDom):Void
	{
	}
	
	/**
	 * Defines mouse up Style
	 * 
	 * @param	domElement
	 */
	public static function getCellMouseUpStyle(domElement:HtmlDom):Void
	{
	}
}