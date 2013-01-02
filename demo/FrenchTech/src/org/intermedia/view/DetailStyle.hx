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
import org.intermedia.view.ScreenResolution;

/**
 * This class defines the styles used by the detail view
 * 
 * @author Raphael Harmel
 */

class DetailStyle
{
	
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setDetailStyle(node:HtmlDom):Void
	{
		node.style.display = "inline-block";
		//node.style.position = "absolute";
		//node.style.position = "fixed";
		node.style.position = "static";
		
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";
		//node.style.marginTop = "0px";
		node.style.marginTop = Std.string(Constants.HEADER_HEIGHT) + "px";
		node.style.marginBottom = "0px";
		
		node.style.paddingLeft = Std.string(Constants.DETAIL_HORIZONTAL_PADDING_PERCENT) + "%";
		node.style.paddingRight = Std.string(Constants.DETAIL_HORIZONTAL_PADDING_PERCENT) + "%";
		node.style.paddingTop = Std.string(Constants.DETAIL_VERTICAL_PADDING_PIXELS) + "px";
		node.style.paddingBottom = Std.string(Constants.DETAIL_VERTICAL_PADDING_PIXELS) + "px";
		
		//node.style.width = "96%";
		node.style.width = Std.string(Constants.DETAIL_HORIZONTAL_PERCENT) + "%";
		//node.style.width = Std.string(Lib.window.innerWidth - 20) + "px";
		//node.style.height = Std.string(Lib.window.innerHeight) + "px";
		//node.style.height = "100%";
		node.style.height = "auto";
		//node.style.height = Std.string(Lib.window.innerHeight - Constants.HEADER_HEIGHT) + "px";
		
		node.style.top = Std.string(Constants.HEADER_HEIGHT) + "px";
		node.style.bottom = "0px";
		
		node.style.overflowX = "hidden";
		node.style.overflowY = "hidden";
		//node.style.overflowY = "scroll";
		//node.style.overflowY = "visible";
		//node.style.overflowY = "auto";
		
		node.style.backgroundColor = Constants.DETAIL_BG_COLOR;
		
		node.style.textAlign = "justify";

	}

	/**
	 * Defines thumblist Style
	 * 
	 * @param	node
	 */
	public static function setThumbnail(node:HtmlDom):Void
	{
		var IMAGE_MAX_HEIGHT:Int = 120;
		
		node.style.display = "block";
		
		node.style.marginLeft = "auto";
		node.style.marginRight = "auto";
		
		node.style.maxWidth = Std.string(Constants.DETAIL_HORIZONTAL_PERCENT) + "%";
		node.style.maxHeight = Std.string(IMAGE_MAX_HEIGHT) + "px";
	}
	
	/**
	 * Defines text Style
	 * 
	 * @param	node
	 */
	public static function setText(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.color = '#202020';
		node.style.fontFamily = 'Arial, sans-serif';
	}

	/**
	 * Defines cell title Style
	 * 
	 * @param	node
	 */
	public static function setTitle(node:HtmlDom):Void
	{
		setText(node);
		
		node.style.fontSize = "18px";
		node.style.fontWeight = "bold";
	}

	/**
	 * Defines cell comment Style
	 * 
	 * @param	node
	 */
	public static function setAuthor(node:HtmlDom):Void
	{
		setText(node);

		node.style.fontSize = "12px";
		node.style.fontWeight = "normal";
	}

	/**
	 * Defines cell description Style
	 * 
	 * @param	node
	 */
	public static function setDescription(node:HtmlDom):Void
	{
		setText(node);

		node.style.marginTop = Std.string(Constants.DETAIL_VERTICAL_PADDING_PIXELS) + "px";
		node.style.marginBottom = Std.string(Constants.DETAIL_VERTICAL_PADDING_PIXELS) + "px";
		
		node.style.fontSize = "14px";
	}
	
}
