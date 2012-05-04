package org.intermedia.view;

import haxe.Firebug;
import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.view.StyleModel;
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

	// blockThumb containing cropped image
	//private var _blockThumb:BlockThumb;

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine	number of cells per line
	 * @param	?style		cell style
	 */
	public function new(?cellPerLine:Int = 1, ?style:Dynamic) 
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
			//thumbnail:CellThumbStyle.setThumbnailStyle
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
			// create cropped image
			/*_croppedImage = new CroppedImage();
			_croppedImage.onImageLoadSuccess = refreshStyles;
			_croppedImage.loadThumb(_data.thumbUrl);
			// apply style
			_style.thumbnailMask(_croppedImage.node);
			// attach it to hierarchy
			node.appendChild(_croppedImage.node);*/
			
			// create blockThumb containing cropped thumb image
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