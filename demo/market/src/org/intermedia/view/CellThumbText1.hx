package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import org.intermedia.model.ApplicationModel;
import cocktail.textElement.TextElement;
import cocktail.domElement.ImageDOMElement;

import org.intermedia.view.CellThumbText1Style;

/**
 * Base class for list cell. Each ListView has its own cell class inherited from this one.
 * 
 * @author Raphael Harmel
 */

class CellThumbText1 extends CellBase
{

	public function new() 
	{
		super();
		//CellTextStyle.setCellStyle(this);
		
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		var cellData:CellData = _data;
		
		
		// THUMBNAIL
		
		// image part
		if (cellData.thumbUrl != "" && cellData.thumbUrl != null)
		{
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			//listStyle.cellThumbnail(cellImage,screenResolutionSize);
			CellThumbText1Style.setThumbnailStyle(cellImage);
			// add image
			this.addChild(cellImage);
			// load image
			cellImage.load(cellData.thumbUrl);
		}
		

		// TEXT
		
		// add text block
		var cellTextBlockContainer:ContainerDOMElement = new ContainerDOMElement();
		CellThumbText1Style.setTextBlockStyle(cellTextBlockContainer);
		//listStyle.cellTextBlock(cellTextBlockContainer);
		this.addChild(cellTextBlockContainer);
		
		// add title
		if (cellData.title != "" && cellData.title != null)
		{
			var cellTitleContainer:ContainerDOMElement = new ContainerDOMElement();
			var textElement:TextElement = new TextElement(cellData.title);
			cellTitleContainer.addText(textElement);
			CellThumbText1Style.setTitleStyle(cellTitleContainer);
			//listStyle.cellTitle(cellTitleContainer, screenResolutionSize);
			cellTextBlockContainer.addChild(cellTitleContainer);
		}
		
		// add author
		if (cellData.author != "" && cellData.author != null)
		{
			var cellAuthorContainer:ContainerDOMElement = new ContainerDOMElement();
			var textElement:TextElement = new TextElement(cellData.author);
			cellAuthorContainer.addText(textElement);
			CellThumbText1Style.setAuthorStyle(cellAuthorContainer);
			//listStyle.cellComment(cellAuthorContainer, screenResolutionSize);
			cellTextBlockContainer.addChild(cellAuthorContainer);
		}
		
		
		// LINE
		
		// add separation line
		var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		CellTextStyle.setCellLineStyle(line);
		this.addChild(line);
		line.load("assets/greyPixel.png");

	}

}