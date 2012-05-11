package org.intermedia.view;

import haxe.Firebug;
<<<<<<< HEAD
import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.view.StyleModel;
=======
import js.Lib;
import js.Dom;
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD

	// blockThumb containing cropped image
	//private var _blockThumb:BlockThumb;
=======
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine	number of cells per line
<<<<<<< HEAD
	 * @param	?cellStyle		cell style
	 */
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellStyleModel) 
	{
		super(cellPerLine,cellStyle);
=======
	 * @param	?style		cell style
	 */
	public function new(?cellPerLine:Int = 1, ?style:CellStyleModel)
	{
		super(cellPerLine,style);
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
			//thumbnail:CellThumbStyle.setThumbnailStyle
=======
			thumbnail:null,
			textBlock:null,
			title:null,
			author:null
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
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
<<<<<<< HEAD
			// create cropped image
			/*_croppedImage = new CroppedImage();
			_croppedImage.onImageLoadSuccess = refreshStyles;
			_croppedImage.loadThumb(_data.thumbUrl);
			// apply style
			_cellStyle.thumbnailMask(_croppedImage.node);
			// attach it to hierarchy
			node.appendChild(_croppedImage.node);*/
			
			// create blockThumb containing cropped thumb image
			_croppedImage = new CroppedImage(_cellStyle);
=======
			// create cropped thumb image
			_croppedImage = new CroppedImage(_style);
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
			_croppedImage.data = _data;
			node.appendChild(_croppedImage.node);
		}
	}
	
	/**
	 * Refreshes the styles, used when resizing
	 */
	override public function refreshStyles():Void
	{
<<<<<<< HEAD
=======
		super.refreshStyles();
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		// reset cropped image style
		_croppedImage.refreshStyles();
	}

}