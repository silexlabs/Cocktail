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
import org.intermedia.model.ApplicationModel;


/**
 * This class defines the loading view, containing a centered loading wheel
 * 
 * @author Raphael Harmel
 */

class SplashScreenView
{
	public var node:HtmlDom;
	
	private var _viewStyle:Dynamic;
	
	public function new() 
	{
		node = Lib.document.createElement("div");
		
		SplashScreenViewStyle.setLoadingStyle(node);
		
	}
	
}
