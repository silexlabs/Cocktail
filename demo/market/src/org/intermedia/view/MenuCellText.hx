package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;

/**
 * Base class for menu cell
 * 
 * @author Raphael Harmel
 */

class MenuCellText extends CellBase
{

<<<<<<< HEAD
	//public function new() 
	//public function new(?cellStyle:HtmlDom->Void) 
	public function new() 
	{
		super();
		MenuCellTextStyle.setCellStyle(node);
		//cellStyle(node);
=======
	public function new() 
	{
		super();
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
	}
	
	/**
	 * initialize the default style
	 */
	override private function initStyle():Void
	{
		// init style model
		_style = {
			cell:MenuCellTextStyle.setCellStyle,
			thumbnailMask:null,
			thumbnail:null,
			textBlock:null,
			title:MenuCellTextStyle.setCellTextStyle,
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
			node.appendChild(cellTextContainer);
<<<<<<< HEAD
			MenuCellTextStyle.setCellTextStyle(cellTextContainer);
=======
			_style.title(cellTextContainer);
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
		}
	}

	
}