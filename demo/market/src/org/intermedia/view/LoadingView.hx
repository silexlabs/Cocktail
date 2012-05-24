package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;


/**
 * This class defines the loading view, containing a centered loading wheel
 * 
 * @author Raphael Harmel
 */

class LoadingView
{
	public var node:HtmlDom;
	
	private var _viewStyle:Dynamic;
	
	public function new() 
	{
		//super();
		node = Lib.document.createElement("div");
		
		LoadingViewStyle.setLoadingStyle(node);
		loadThumb();
	}
	
	/**
	 *  load thumb image
	 */
	private function loadThumb():Void
	{
		// THUMBNAIL
		var image:Image = cast Lib.document.createElement("img");
		// set image style
		LoadingViewStyle.setThumbnailStyle(image);
		// add image
		node.appendChild(image);
		// load image
		image.src = "assets/loading.gif";
	}
	
}
