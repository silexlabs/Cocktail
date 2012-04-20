package org.intermedia.view;

//import cocktail.Cocktail;
//import cocktail.node.HtmlDom;
//import cocktail.style.StyleData;
//import cocktail.textElement.TextElement;
//import cocktail.node.HtmlDom;

//import org.intermedia.view.CellThumbText1Style;
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
	
	// cell thumb image
	//private var _cellImage:HtmlDom;

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
		//if (cellStyle != null) _cellStyle = cellStyle;
		//else initCellStyle();
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
			cell:CellThumbStyle.setCellStyle,
			thumbnail:CellThumbStyle.setThumbnailStyle,
			textBlock:null,
			title:null,
			author:null,
			line:null
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
			var croppedImage:CroppedImage = new CroppedImage(_data.thumbUrl, _thumbMask);
			node.appendChild(croppedImage.node);
		}
	}

}
