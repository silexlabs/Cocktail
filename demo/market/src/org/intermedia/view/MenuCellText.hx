package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;

/**
 * Base class for list cell. Each ListView has its own cell class inherited from this one.
 * 
 * @author Raphael Harmel
 */

class MenuCellText extends CellBase
{

	//public function new() 
	//public function new(?cellStyle:HtmlDom->Void) 
	public function new() 
	{
		super();
		MenuCellTextStyle.setCellStyle(node);
		//cellStyle(node);
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		var cellData:CellData = _data;
		
		// add text
		var cellTextContainer:HtmlDom = Lib.document.createElement("div");
		if (cellData.title != "" && cellData.title != null)
		{
			var textElement:HtmlDom = Lib.document.createTextNode(cellData.title);
			cellTextContainer.appendChild(textElement);
			node.appendChild(cellTextContainer);
			MenuCellTextStyle.setCellTextStyle(cellTextContainer);
		}
	}

	
}