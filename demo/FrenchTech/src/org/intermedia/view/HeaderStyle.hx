/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.view.Constants;

/**
 * Defines the style of the header
 * 
 * @author Raphael Harmel
 */

class HeaderStyle 
{
	/**
	 * Defines header Style
	 * 
	 * @param	node
	 */
	public static function setHeaderStyle(node:HtmlDom):Void
	{
		node.style.position = "fixed";
		node.style.display = "block";
		
		node.style.top = "0px";
		node.style.bottom = "auto";
		node.style.left = "0px";
		node.style.top = "0px";
		
		node.style.minWidth = "100%";
		node.style.width = "100%";
		node.style.height = Std.string(Constants.HEADER_HEIGHT) + "px";
		
		// set to the forehead
		//node.style.zIndex = 1000;
		
		node.style.backgroundImage = 'url(' + Constants.HEADER_BG_IMAGE_URL + ')';
	}

	/**
	 * Defines header title text Style
	 * 
	 * @param	node
	 */
	public static function setHeaderTextStyle(node:HtmlDom):Void
	{
		node.style.position = "absolute";

		node.style.color = Constants.HEADER_FONT_COLOR;
		node.style.fontSize = "20px";
		node.style.fontWeight = "bold";
		node.style.fontStyle = "normal";
		node.style.fontFamily = 'Arial, sans-serif';

		node.style.textAlign = "center";
		node.style.paddingTop = "10px";
	
		node.style.minWidth = "100%";
		node.style.top = "0px";
		node.style.width = "100%";
		node.style.height = "100%";
		node.style.verticalAlign = "middle";
	}

	/**
	 * Defines back button Style
	 * 
	 * @param	node
	 */
	public static function setBackButtonStyle(node:HtmlDom):Void
	{
		node.style.position = "absolute";
		node.style.paddingTop = "6px";
		node.style.paddingLeft = "10px";
		node.style.top = "0px";
	}

	/**
	 * Defines back button text Style
	 * 
	 * @param	node
	 */
	public static function setBackButtonTextStyle(node:HtmlDom):Void
	{
		node.style.position = "absolute";
		node.style.color = '#EEEEEE';

		node.style.fontSize = "14px";
		node.style.lineHeight = "normal";
		node.style.fontWeight = "bold";
		node.style.fontStyle = "normal";
		node.style.fontFamily = 'Arial, sans-serif';
		node.style.textAlign = "center";

		node.style.paddingTop = "12px";
		node.style.paddingLeft = "30px";
		node.style.top = "0px";
		node.style.left = "0px";
	}

	/**
	 * Defines back button image Style
	 * 
	 * @param	node
	 */
	public static function setBackButtonImageStyle(node:HtmlDom):Void
	{
		node.style.display = "inline";
		node.style.position = "relative";
		node.style.top = "0px";
		node.style.left = "0px";
	}
	
	/**
	 * Defines back button image Style
	 * 
	 * @param	node
	 */
	public static function setThumbImageStyle(node:HtmlDom):Void
	{
		var THUMB_MARGIN:Int = 5;
		
		node.style.display = "inline";
		node.style.position = "relative";
		node.style.top = Std.string(THUMB_MARGIN) + "px";
		node.style.left = Std.string(2*THUMB_MARGIN) + "px";
		node.style.width = Std.string(Constants.HEADER_HEIGHT - 2 * THUMB_MARGIN) + "px";
		node.style.height = Std.string(Constants.HEADER_HEIGHT - 2 * THUMB_MARGIN) + "px";
		
		
	}
	
}