/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package org.intermedia.view;

import haxe.Firebug;
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.StyleModel;

/**
 * This class defines a CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumb extends CellBase
{
	// cropping mask containing the image
	private var _croppedImage:CroppedImage;

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine	number of cells per line
	 * @param	?style		cell style
	 */
	public function new(?cellPerLine:Int = 1, ?style:CellStyleModel)
	{
		super(cellPerLine,style);
	}
	
	/**
	 * initialize the default cell style
	 */
	override private function initStyle():Void
	{
		// init style model
		_style = {
			cell:CellThumbStyle.setCellStyle,
			thumbnailMask:CellThumbStyle.setThumbnailMaskStyle,
			thumbnail:null,
			textBlock:null,
			title:null,
			author:null
		}
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		// load cropped thumb image
		if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			// create cropped thumb image
			_croppedImage = new CroppedImage(_style);
			_croppedImage.data = _data;
			node.appendChild(_croppedImage.node);
		}
	}
	
	/**
	 * Refreshes the styles, used when resizing
	 */
	override public function refreshStyles():Void
	{
		super.refreshStyles();
		// reset cropped image style
		_croppedImage.refreshStyles();
	}

}