package org.intermedia.view;

import haxe.Firebug;
import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.view.StyleModel;
import org.intermedia.model.ApplicationModel;
import org.intermedia.model.ApplicationModel;

import feffects.Tween;


/**
 * This class defines a CellThumb
 * 
 * @author Raphael Harmel
 */

class CellThumb extends CellBase
{
	// cell style
	//private var _cellStyle:CellStyleModel;
	
	// thumb mask
	private var _thumbMask:Size;
	
	// mask
	private var _mask:HtmlDom;
	
	// cell thumb image
	//private var _cellImage:HtmlDom;

	// cropping mask containing the image
	private var _croppedImage:CroppedImage;

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine			number of cells per line
	 * @param	?cellStyle				cell style
	 * @param	?thumbWidthPercent		thumb percentage of the cell
	 */
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellStyleModel, ?thumbWidthPercent:Int) 
	{
		super(cellPerLine);

		// apply cell style and gets the cell dimension, for image cropping
		//_thumbMask = _cellStyle.cell(this, cellPerLine, thumbWidthPercent);
		//_thumbMask = _cellStyle.cell(this, cellPerLine);
		_thumbMask = ImageUtils.computeMaskSize(cellPerLine);
	}
	
	/**
	 * initialize the default cell style
	 */
	override private function initCellStyle():Void
	{
		// init style model
		_cellStyle = {
			cell:CellThumbStyle.setCellStyle/*,
			thumbnailMask:CellThumbStyle.setThumbnailMaskStyle,
			thumbnail:CellThumbStyle.setThumbnailStyle*/
		}
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		// load thumb image
		if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			//var croppedImage:CroppedImage = new CroppedImage(_data.thumbUrl, _thumbMask);
			_croppedImage = new CroppedImage(_data.thumbUrl, _thumbMask);
			//var croppedImage:CroppedImage = new CroppedImage(node,_cellStyle);
			//var croppedImage:CroppedImage = new CroppedImage(_cellStyle);
			node.appendChild(_croppedImage.node);
			
			// create and initialise mask
			//_mask = Lib.document.createElement("div");
			//node.appendChild(_mask);
			//_cellStyle.thumbnailMask(_mask);
			//Firebug.trace(_mask.offsetWidth + "," + _mask.offsetHeight);
			//Timer.delay(function () { layoutSet(croppedImage);}  , 1);
		}
	}
	
	override public function refreshStyles():Void
	{
		_thumbMask = ImageUtils.computeMaskSize(_cellPerLine);
		_croppedImage.resetStyle( _thumbMask );
	}

}