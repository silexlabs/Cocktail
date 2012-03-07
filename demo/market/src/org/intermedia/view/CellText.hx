package org.intermedia.view;

import cocktail.domElement.ContainerDOMElement;
import org.intermedia.model.ApplicationModel;
import cocktail.textElement.TextElement;
import cocktail.domElement.ImageDOMElement;

/**
 * Base class for list cell. Each ListView has its own cell class inherited from this one.
 * 
 * @author Raphael Harmel
 */

class CellText extends CellBase
{

	public function new() 
	{
		super();
		CellTextStyle.setCellStyle(this);
	}
	
	/**
	 * build view
	 */
	//override private function buildView():Void
	override private function updateView():Void
	{
		var cellData:CellData = _data;
		
		// add text
		var cellTextContainer:ContainerDOMElement = new ContainerDOMElement();
		if (cellData.title != "" && cellData.title != null)
		{
			var textElement:TextElement = new TextElement(cellData.title);
			cellTextContainer.addText(textElement);
			CellTextStyle.setCellTextStyle(cellTextContainer);
			//cell.addChild(cellTextContainer);
			this.addChild(cellTextContainer);
		}
			
		// image part
		/*if (cellData.imagePath != "" && cellData.imagePath != null)
		{
			var cellImage:ImageDOMElement = new ImageDOMElement();
			// set image style
			listStyle.cellImage(cellImage);
			// add image
			//cell.addChild(cellImage);
			cellContent.push(cellImage);
			// load image
			cellImage.load(cellData.imagePath);
		}*/
		
		// LINE
		
		// add separation line
		var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		CellTextStyle.setCellLineStyle(line);
		this.addChild(line);
		line.load("assets/greyPixel.png");

	}

}