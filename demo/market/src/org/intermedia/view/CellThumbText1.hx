package org.intermedia.view;

import haxe.Firebug;
import haxe.Timer;
import js.Lib;
import js.Dom;
import org.intermedia.view.CellThumbText1Style;
import org.intermedia.view.StyleModel;
import org.intermedia.model.ApplicationModel;

/**
 * Base class for list cell. Each ListView has its own cell class inherited from this one.
 * 
 * @author Raphael Harmel
 */

//class CellThumbText1 extends CellThumb
class CellThumbText1 extends CellBase
{
	static inline var TITLE_LENGTH:Int = 40;
	
	// mask
	private var _mask:HtmlDom;
	
	// cropping mask containing the image
	private var _croppedImage:CroppedImage;

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine	number of cells per line
	 */
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellStyleModel) 
	{
		super(cellPerLine);
	}

	/**
	 * cell style init
	 */
	override private function initCellStyle():Void
	{
		// init style model
		_cellStyle = {
			//cell:CellThumbText1Style.setCellStyle,
			//thumbnail:CellThumbText1Style.setThumbnailStyle,
			cell:CellThumbText1Style.setCellStyle,
			thumbnailMask:CellThumbText1Style.setThumbnailMaskStyle,
			//thumbnail:CellThumbText1Style.setThumbnailStyle,
			textBlock:CellThumbText1Style.setTextBlockStyle,
			title:CellThumbText1Style.setTitleStyle,
			author:CellThumbText1Style.setAuthorStyle,
			line:CellThumbText1Style.setLineStyle
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
			// create cropped image
			_croppedImage = new CroppedImage(_data.thumbUrl);
			// apply style
			_cellStyle.thumbnailMask(_croppedImage.node);
			// attach it to hierarchy
			node.appendChild(_croppedImage.node);
		}

		
		// TEXT
		
		// add text block
		var cellTextBlockContainer:HtmlDom = Lib.document.createElement("div");
		_cellStyle.textBlock(cellTextBlockContainer);
		//listStyle.cellTextBlock(cellTextBlockContainer);
		node.appendChild(cellTextBlockContainer);
		
		// add title
		if (_data.title != "" && _data.title != null)
		{
			var text:String = _data.title;
			if (text.length > TITLE_LENGTH)
				text = text.substr(0, TITLE_LENGTH) + "...";
			var textElement:HtmlDom = Lib.document.createTextNode(text);
			var cellTitleContainer:HtmlDom = Lib.document.createElement("div");
			cellTitleContainer.appendChild(textElement);
			_cellStyle.title(cellTitleContainer);
			//listStyle.cellTitle(cellTitleContainer, screenResolutionSize);
			cellTextBlockContainer.appendChild(cellTitleContainer);
		}
		
		// add author
		/*if (_data.author != "" && _data.author != null)
		{
			var cellAuthorContainer:HtmlDom = Lib.document.createElement("div");
			var textElement:HtmlDom = Lib.document.createTextNode(_data.author);
			cellAuthorContainer.appendChild(textElement);
			_cellStyle.author(cellAuthorContainer);
			//listStyle.cellComment(cellAuthorContainer, screenResolutionSize);
			cellTextBlockContainer.appendChild(cellAuthorContainer);
		}*/
		
		
		// LINE
		
		// add separation line
		/*var line:HtmlDom = Lib.document.createElement("div");
		// set image style
		_cellStyle.line(line);
		node.appendChild(line);
		line.src("assets/greyPixel.png");*/

		Timer.delay(refreshStyles, Constants.CELL_REFRESH_STYLE_DELAY);
	}
	
	override public function refreshStyles():Void 
	{
		// reset cropped image style
		_croppedImage.resetStyle();
	}

}