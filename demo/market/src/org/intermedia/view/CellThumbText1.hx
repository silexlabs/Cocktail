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

class CellThumbText1 extends CellThumb
{
	// cell style
	//private var _cellStyle:CellThumbText1StyleModel;

	/**
	 * 
	 * 
	 * @param	?cellPerLine	number of cells per line
	 */
	/*public function new(?cellPerLine:Int = 1) 
	{
		super();
		initCellStyle();
		_cellStyle.cell(this,cellPerLine);
	}*/
	
	override private function initCellStyle():Void
	{
		// init style model
		_cellStyle = {
			cell:CellThumbText1Style.setCellStyle,
			thumbnail:CellThumbStyle.setThumbnailStyle,
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
		//var cellData:CellData = _data;
		//var cellData:CellData = super._data;
		
		// THUMBNAIL
		
		// image part
		/*if (cellData.thumbUrl != "" && cellData.thumbUrl != null)
		{
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			//listStyle.cellThumbnail(cellImage,screenResolutionSize);
			_cellStyle.thumbnail(cellImage);
			// add image
			this.addChild(cellImage);
			// load image
			cellImage.load(cellData.thumbUrl);
		}*/
		

		// TEXT
		
		// add text block
		var cellTextBlockContainer:ContainerDOMElement = new ContainerDOMElement();
		_cellStyle.textBlock(cellTextBlockContainer);
		//listStyle.cellTextBlock(cellTextBlockContainer);
		this.addChild(cellTextBlockContainer);
		
		// add title
		if (_data.title != "" && _data.title != null)
		{
			var cellTitleContainer:ContainerDOMElement = new ContainerDOMElement();
			var textElement:TextElement = new TextElement(_data.title);
			cellTitleContainer.addText(textElement);
			_cellStyle.title(cellTitleContainer);
			//listStyle.cellTitle(cellTitleContainer, screenResolutionSize);
			cellTextBlockContainer.addChild(cellTitleContainer);
		}
		
		// add author
		if (_data.author != "" && _data.author != null)
		{
			var cellAuthorContainer:ContainerDOMElement = new ContainerDOMElement();
			var textElement:TextElement = new TextElement(_data.author);
			cellAuthorContainer.addText(textElement);
			_cellStyle.author(cellAuthorContainer);
			//listStyle.cellComment(cellAuthorContainer, screenResolutionSize);
			cellTextBlockContainer.addChild(cellAuthorContainer);
		}
		
		
		// LINE
		
		// add separation line
		var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		_cellStyle.line(line);
		this.addChild(line);
		line.load("assets/greyPixel.png");

	}

}