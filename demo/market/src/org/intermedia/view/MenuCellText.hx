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

	public function new() 
	{
		super();
	}
	
	/**
	 * initialize the default style
	 */
	override private function initStyle():Void
	{
		// init style model
		_style = {
			cell:MenuCellTextStyle.setCellStyle,
			text:MenuCellTextStyle.setCellTextStyle
		}
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
			_style.text(cellTextContainer);
		}
	}

	
}