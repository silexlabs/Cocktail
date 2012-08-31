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

/**
 * Base class for thumb text list cell
 * 
 * @author Raphael Harmel
 */

import org.intermedia.view.CellBase;
import org.intermedia.view.StyleModel;

class CellThumbText1 extends CellBase
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
	 * cell style init
	 */
	override private function initStyle():Void
	{
		// init style model
		_style = {
			cell:CellThumbText1Style.setCellStyle,
			thumbnailMask:CellThumbText1Style.setThumbnailMaskStyle,
			thumbnail:null,
			textBlock:CellThumbText1Style.setTextBlockStyle,
			title:CellThumbText1Style.setTitleStyle,
			author:null
		}
		
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		super.updateView();
		
		// THUMBNAIL
		
		// load cropped thumb image
		if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			// create cropped thumb image
			_croppedImage = new CroppedImage(_style);
			_croppedImage.data = _data;
			node.appendChild(_croppedImage.node);	
		}

		
		// TEXT
		
		// add text block
		var cellTextBlockContainer:HtmlDom = Lib.document.createElement("div");
		_style.textBlock(cellTextBlockContainer);
		node.appendChild(cellTextBlockContainer);
		
		// add title
		if (_data.title != "" && _data.title != null)
		{
			var text:String = _data.title;
			// shorten title
			if (text.length > Constants.CELL_THUMB_TEXT_TITLE_LENGTH)
			{
				// shorten title to TITLE_LENGTH
				text = text.substr(0, Constants.CELL_THUMB_TEXT_TITLE_LENGTH);
				// then shorten it until the last space character and add "..." at the end
				text = text.substr(0, text.lastIndexOf(" ")) + "...";
			}
			var textElement:HtmlDom = Lib.document.createTextNode(text);
			var cellTitleContainer:HtmlDom = Lib.document.createElement("div");
			cellTitleContainer.appendChild(textElement);
			_style.title(cellTitleContainer);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
		
	}
	
	override public function refreshStyles():Void 
	{
		super.refreshStyles();
		// reset cropped image style
		_croppedImage.refreshStyles();
	}

}