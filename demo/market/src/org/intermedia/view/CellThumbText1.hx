package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import org.intermedia.model.ApplicationModel;
import cocktail.textElement.TextElement;
import cocktail.domElement.ImageDOMElement;

import org.intermedia.view.CellThumbText1Style;
import org.intermedia.view.StyleModel;

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
		//this.addChild(_thumb);
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
			trace(_data.thumbUrl);
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			//listStyle.cellThumbnail(cellImage,screenResolutionSize);
			_cellStyle.thumbnail(cellImage);
			// add image
			this.addChild(cellImage);
			// load image
			cellImage.load(_data.thumbUrl);
		}*/
		
		// load thumb image
		if (_data.thumbUrl != "" && _data.thumbUrl != null)
		{
			var croppedImage:CroppedImage = new CroppedImage(_data.thumbUrl, _thumbMask);
			//var croppedImage:CroppedImage = new CroppedImage(_data.thumbUrl, {width:50, height:50});
			this.addChild(croppedImage);
		}

		

		// TEXT
		
		// add text block
		var cellTextBlockContainer:ContainerDOMElement = new ContainerDOMElement();
		_cellStyle.textBlock(cellTextBlockContainer);
		//listStyle.cellTextBlock(cellTextBlockContainer);
		this.addChild(cellTextBlockContainer);
		
		// add title
		if (_data.title != "" && _data.title != null)
		{
			var text:String = _data.title;
			if (text.length > TITLE_LENGTH)
				text = text.substr(0, TITLE_LENGTH) + "...";
			var textElement:TextElement = new TextElement(text);
			var cellTitleContainer:ContainerDOMElement = new ContainerDOMElement();
			cellTitleContainer.addText(textElement);
			_cellStyle.title(cellTitleContainer);
			//listStyle.cellTitle(cellTitleContainer, screenResolutionSize);
			cellTextBlockContainer.addChild(cellTitleContainer);
		}
		
		// add author
		/*if (_data.author != "" && _data.author != null)
		{
			var cellAuthorContainer:ContainerDOMElement = new ContainerDOMElement();
			var textElement:TextElement = new TextElement(_data.author);
			cellAuthorContainer.addText(textElement);
			_cellStyle.author(cellAuthorContainer);
			//listStyle.cellComment(cellAuthorContainer, screenResolutionSize);
			cellTextBlockContainer.addChild(cellAuthorContainer);
		}*/
		
		
		// LINE
		
		// add separation line
		/*var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		_cellStyle.line(line);
		this.addChild(line);
		line.load("assets/greyPixel.png");*/

	}

}