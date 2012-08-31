/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
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
			_style.title(cellTextContainer);
		}
	}

	
}