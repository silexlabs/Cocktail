package org.intermedia.view;

import haxe.Firebug;
import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.view.StyleModel;
import org.intermedia.model.ApplicationModel;

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
	 * @param	?cellStyle		cell style
	 */
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellStyleModel) 
	{
		super(cellPerLine,cellStyle);
	}
	
	/**
	 * initialize the default cell style
	 */
	override private function initCellStyle():Void
	{
		// init style model
		_cellStyle = {
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
			_croppedImage = new CroppedImage();
			_croppedImage.onImageLoadSuccess = refreshStyles;
			_croppedImage.loadThumb(_data.thumbUrl);
			// apply style
			_cellStyle.thumbnailMask(_croppedImage.node);
			// attach it to hierarchy
			node.appendChild(_croppedImage.node);
		}
	}
	
	override public function refreshStyles():Void
	{
		// reset cropped image style
		_croppedImage.resetStyle();
	}

}