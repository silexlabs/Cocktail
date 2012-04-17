package org.intermedia.view;

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
	
	// thumb mask
	private var _thumbMask:Size;
	
	// cell style
	//private var _cellStyle:CellThumbText1StyleModel;
	
	// thumb
	//private var _thumb:CellThumb;

	/**
	 * constructor
	 * 
	 * @param	?cellPerLine	number of cells per line
	 */
	public function new(?cellPerLine:Int = 1, ?cellStyle:CellStyleModel) 
	{
		super(cellPerLine);
		
		// set cell thumb to 1/3 of the width of the cell
		//_thumb = new CellThumb(cellPerLine);
		//_thumb = new CellThumb(cellPerLine,_cellStyle);
		//CellStyle.removeBorder(_thumb);
		//node.appendChild(_thumb);
		_thumbMask = ImageUtils.computeMaskSize(cellPerLine,CellThumbText1Style.CELL_THUMB_WIDTH_PERCENT);
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
			thumbnail:CellThumbText1Style.setThumbnailStyle,
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
		//_thumb.data = _data;
		//var cellData:CellData = _data;
		//var cellData:CellData = super._data;
		
		// THUMBNAIL
		
		// image part
		/*if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			var cellImage:HtmlDom = Lib.document.createElement("div");
			// set image style
			//listStyle.cellThumbnail(cellImage,screenResolutionSize);
			_cellStyle.thumbnail(cellImage);
			// add image
			node.appendChild(cellImage);
			// load image
			cellImage.src(_data.thumbUrl);
		}*/
		
		// load thumb image
		if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			var croppedImage:CroppedImage = new CroppedImage(_data.thumbUrl, _thumbMask);
			//var croppedImage:CroppedImage = new CroppedImage(_data.thumbUrl, {width:50, height:50});
			node.appendChild(croppedImage.node);
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

	}

}