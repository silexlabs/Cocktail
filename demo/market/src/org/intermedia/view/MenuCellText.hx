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

class MenuCellText extends CellBase
{

	public function new() 
	{
		super();
		MenuCellTextStyle.setCellStyle(this);
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
			MenuCellTextStyle.setCellTextStyle(cellTextContainer);
			this.addChild(cellTextContainer);
		}
			
	}

}