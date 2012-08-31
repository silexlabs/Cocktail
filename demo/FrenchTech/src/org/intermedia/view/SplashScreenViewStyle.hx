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

class SplashScreenViewStyle
{
	/**
	 * Defines cell Style
	 * 
	 * @param	node
	 */
	public static function setLoadingStyle(node:HtmlDom):Void
	{
		//node.style.display = "block";
		node.style.position = "absolute";
		
		node.style.marginBottom = "0px";
		node.style.marginTop = "0px";
		node.style.marginLeft = "0px";
		node.style.marginRight = "0px";

		node.style.paddingBottom = "0px";
		node.style.paddingTop = "0px";
		node.style.paddingLeft = "0px";
		node.style.paddingRight = "0px";

		node.style.width = "100%";
		node.style.height = "100%";

		node.style.backgroundColor = Constants.LIST_BG_BLACK_COLOR;
		
		// select correct splash screen
		var splashScreenUrl:String = "";
		var userAgent:String = Lib.window.navigator.userAgent.toLowerCase();
		
		// if device is an iphone or an ipad
		if( (userAgent.indexOf('iphone') != -1) || (userAgent.indexOf('ipad') != -1) )
		{
			splashScreenUrl = Constants.SPLASHSCREEN_IOS;
		}
		// if device is an android
		else if (userAgent.indexOf('android') != -1)
		{
			splashScreenUrl = Constants.SPLASHSCREEN_ANDROID;
		}
		// if device is of any other type
		else
		{
			splashScreenUrl = Constants.SPLASHSCREEN_DEFAULT;
		}
		
		node.style.backgroundImage = 'url(' + splashScreenUrl + ')';
		node.style.backgroundRepeat = 'no-repeat';
		untyped { node.style.backgroundSize = "100% 100%"; };
		
		node.style.zIndex = 1000;
	}
	
}
