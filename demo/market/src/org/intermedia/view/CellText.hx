<<<<<<< HEAD
package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;

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
		CellTextStyle.setCellStyle(node);
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
			CellTextStyle.setCellTextStyle(cellTextContainer);
			node.appendChild(cellTextContainer);
		}
			
		// add separation line
		/*var line:HtmlDom = Lib.document.createElement("div");
		// set image style
		CellTextStyle.setCellLineStyle(line);
		node.appendChild(line);
		line.src("assets/greyPixel.png");*/

	}

=======
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
	
>>>>>>> 4f33027baa975cee5dc78da15d39744ef9d29ade
}