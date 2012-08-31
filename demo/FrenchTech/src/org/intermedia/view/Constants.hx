/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.view;

/**
 * Defines the constants
 * 
 * @author Raphael Harmel
 */

class Constants
{
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
	
	// set spalsh screens
	public static inline var SPLASHSCREEN_IOS:String = "splashScreens/splashScreen-640x920.png";
	public static inline var SPLASHSCREEN_ANDROID:String = "splashScreens/splashScreen-480x800.png";
	public static inline var SPLASHSCREEN_DEFAULT:String = "splashScreens/splashScreen-640x960.png";

	// set header constants
	public static inline var HEADER_HOME_TITLE:String = "French Tech";
	public static inline var HEADER_DETAIL_TITLE:String = "Infos";
	public static inline var HEADER_FONT_COLOR:String = '#EEEEEE';
	public static inline var HEADER_HEIGHT:Int = 43;
	//public static inline var HEADER_IMAGE_URL:String = "";
	
	// set header constants
	public static inline var MENU_HEIGHT:Int = 35;
	public static inline var MENU_LATERAL_OFFSET:Int = 30;
	public static inline var MENU_FONT_COLOR:String = '#AAAAAA';
	
	// set swippable view constants
	public static inline var SWIP_HORIZONTAL_WIDTH_RATIO:Float = 0.06;	
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
	public static inline var CELL_FONT_COLOR:String = "#444444";
	public static inline var CELL_HEIGHT:Int = 90;
	public static inline var CELL_MAX_HEIGHT:Int = 160;
	public static inline var CELL_MIN_WIDTH:Int = 160;

	// set cells thumb constants
	public static inline var CELL_THUMB_APPARITION_DELAY:Int = 1500;
	
	// set cells thumb text constants
	public static inline var CELL_THUMB_TEXT_TITLE_LENGTH:Int = 42;
	
	// set detail constants
	public static inline var DETAIL_BG_COLOR:String = CELL_BG_COLOR;
	public static inline var DETAIL_HORIZONTAL_PADDING_PERCENT:Int = 2;
	public static inline var DETAIL_HORIZONTAL_PERCENT:Int = 100 - 2 * DETAIL_HORIZONTAL_PADDING_PERCENT;
	public static inline var DETAIL_VERTICAL_PADDING_PIXELS:Int = 10;
	
	
}