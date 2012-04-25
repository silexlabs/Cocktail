package org.intermedia.view;

import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.StyleModel;

/**
 * This class defines a BlockThumb, which corresponds to a cropped image (used in cells)
 * 
 * @author Raphael Harmel
 */

class BlockThumb extends ViewBase
{
	// cropping mask containing the image
	private var _croppedImage:CroppedImage;

	/**
	 * constructor
	 * 
	 * @param	?cellStyle		cell style
	 */
	//public function new(imageUrl:String, style:Dynamic) 
	public function new(style:Dynamic) 
	{
		super();
		_style = style;
		//createBlock(imageUrl, cellStyle);
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		createBlock();
	}
	
	
	/**
	 * update view
	 */
	//private function createBlock(imageUrl:String, cellStyle:CellStyleModel):Void
	private function createBlock():Void
	{
		// create cropped image
		_croppedImage = new CroppedImage();
		_croppedImage.onImageLoadSuccess = refreshStyles;
		_croppedImage.loadThumb(_data.thumbUrl);
		// apply style
		_style.thumbnailMask(_croppedImage.node);
		// attach it to hierarchy
		//node.appendChild(_croppedImage.node);
		node = _croppedImage.node;
	}
	
	/**
	 * Refreshes the styles, used when resizing
	 */
	public function refreshStyles():Void
	{
		// reset cropped image style
		_croppedImage.refreshStyles();
	}

}