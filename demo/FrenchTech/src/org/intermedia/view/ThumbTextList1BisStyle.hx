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
 * This class defines the default style used by a ListView
 * 
 * @author Raphael Harmel
 */

class ThumbTextList1BisStyle
{
	/**
	 * Defines default Style
	 * 
	 * @param	node
	 */
	public static function setListStyle(node:HtmlDom):Void
	{
		ListViewStyle.setListStyle(node);
		
		node.style.backgroundColor = Constants.LIST_BG_BLACK_COLOR;
	}
	
}
