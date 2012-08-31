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

/**
 * This class defines the styles used by the CellThumb
 * 
 * @author Raphael Harmel
 */

class LoadingViewStyle
{
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 */
	public static function setLoadingStyle(node:HtmlDom):Void
	{
		node.style.display = "block";
		node.style.position = "absolute";
		
		node.style.width = Std.string(Lib.window.innerWidth) + "px";
		node.style.height = Std.string(Lib.window.innerHeight) + "px";
		
		node.style.textAlign = "center";
		
		node.style.top = "0px";
		node.style.bottom = "0px";
		
		node.style.color = '#FFFFFF';
		
		node.style.zIndex = 1000;
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
