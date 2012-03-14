package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import cocktail.style.StyleData;
import org.intermedia.model.ApplicationModel;
import cocktail.textElement.TextElement;
import cocktail.domElement.ImageDOMElement;

import org.intermedia.view.CellThumbText1Style;
import org.intermedia.view.StyleModel;

import feffects.Tween;


/**
 * This class defines the loading view, containing a centered loading wheel
 * 
 * @author Raphael Harmel
 */

class LoadingView extends ContainerDOMElement
{
	private var _viewStyle:Dynamic;
	
	public function new() 
	{
		super();
		LoadingViewStyle.setLoadingStyle(this);
		loadThumb();
	}
	
	/**
	 *  load thumb image
	 */
	private function loadThumb():Void
	{
		// THUMBNAIL
		var image = new ImageDOMElement();
		// set image style
		LoadingViewStyle.setThumbnailStyle(image);
		// add image
		this.addChild(image);
		// load image
		image.load("assets/loading.gif");
		//image.load("assets/loading2.gif");
	}
	
}
