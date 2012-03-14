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
	 * update view
	 */
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
			this.addChild(cellTextContainer);
		}
			
		// add separation line
		var line:ImageDOMElement = new ImageDOMElement();
		// set image style
		CellTextStyle.setCellLineStyle(line);
		this.addChild(line);
		line.load("assets/greyPixel.png");

	}

}