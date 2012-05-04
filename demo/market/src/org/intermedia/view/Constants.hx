/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

package org.intermedia.view;

/**
 * Defines the constants
 * 
 * @author Raphael Harmel
 */

class Constants
{
	// Global constants
	//public static inline var ONLINE:Bool = false;
	
	// production values
	public static inline var HEADER_BG_IMAGE_URL:String = "assets/tile_french-tech.png";
	public static inline var MENU_BG_IMAGE_URL:String = "assets/tile_french-tech2.png";
	public static inline var LIST_BG_GREY_COLOR:String = "#CCCCCC";
	public static inline var LIST_BG_BLACK_COLOR:String = "#191919";
	public static inline var CELL_BG_COLOR:String = "#FEFEFE";
	
	// Test values
	//public static inline var HEADER_BG_IMAGE_URL:String = "";
	//public static inline var MENU_BG_IMAGE_URL:String = "";
	//public static inline var LIST_BG_GREY_COLOR:String = "";
	//public static inline var LIST_BG_BLACK_COLOR:String = "";
	//public static inline var CELL_BG_COLOR:String = "";
	
	
	
	// set header constants
	public static inline var HEADER_HOME_TITLE:String = "French Tech";
	public static inline var HEADER_DETAIL_TITLE:String = "Infos";
	public static inline var HEADER_FONT_COLOR:String = '#EEEEEE';
	public static inline var HEADER_HEIGHT:Int = 43;
	public static inline var HEADER_WITH_SHADOW_HEIGHT:Int = 43;
	//public static inline var HEADER_IMAGE_URL:String = "assets/rss-icon.png";
	//public static inline var HEADER_IMAGE_URL:String = "";
	
	// set header constants
	public static inline var MENU_HEIGHT:Int = 35;
	public static inline var MENU_LATERAL_OFFSET:Int = 30;
	public static inline var MENU_FONT_COLOR:String = '#AAAAAA';
	
	// set swippable view constants
	public static inline var SWIP_HORIZONTAL_WIDTH_RATIO:Float = 0.1;	
	public static inline var SWIP_HORIZONTAL_TWEEN_DELAY:Int = 150;	
	
	// set lists constants
	public static inline var LIST_TOP:Int = HEADER_HEIGHT + MENU_HEIGHT;
	public static inline var LIST_BOTTOM_LOADER_VERTICAL_MARGIN:Int = 10;
	
	// set cells constants
	//public static inline var CELL_STYLE_REFRESH_DELAY:Int = 600;
	public static inline var CELL_VERTICAL_SPACE:Int = 2;
	public static inline var CELL_BORDER_WIDTH:Int = 1;
	public static inline var CELL_BORDER_WIDTH_LARGE:Int = 4;
	public static inline var CELL_BORDER_COLOR:String = "#CCCCCC";
	//public static inline var CELL_RATIO:Float = 16/9;
	public static inline var CELL_HEIGHT:Int = 90;
	public static inline var CELL_MAX_HEIGHT:Int = 160;
	public static inline var CELL_MIN_WIDTH:Int = 160;

	// set cells thumb constants
	public static inline var CELL_THUMB_APPARITION_DELAY:Int = 1500;
	
	// set cells thumb text constants
	public static inline var CELL_THUMB_TEXT_TITLE_LENGTH:Int = 42;
	
	
}