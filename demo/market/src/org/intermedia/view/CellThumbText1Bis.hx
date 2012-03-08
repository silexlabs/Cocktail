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

//class CellThumbText1Bis extends CellBase
class CellThumbText1Bis extends CellThumbText1
{

	override private function initCellStyle():Void
	{
		// init style model
		_cellStyle = {
			cell:CellThumbText1BisStyle.setCellStyle,
			thumbnail:CellThumbText1BisStyle.setThumbnailStyle,
			textBlock:CellThumbText1BisStyle.setTextBlockStyle,
			title:CellThumbText1BisStyle.setTitleStyle,
			author:CellThumbText1BisStyle.setAuthorStyle,
			line:CellThumbText1BisStyle.setLineStyle
		}
		
	}

}