package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;

/**
 * Base class for text cell
 * 
 * @author Raphael Harmel
 */

class CellText extends CellBase
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
			cell:CellTextStyle.setCellStyle,
			thumbnailMask:null,
			thumbnail:null,
			textBlock:null,
			title:CellTextStyle.setCellTextStyle,
			author:null
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
			_style.title(cellTextContainer);
			node.appendChild(cellTextContainer);
		}
	}
	
}