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
