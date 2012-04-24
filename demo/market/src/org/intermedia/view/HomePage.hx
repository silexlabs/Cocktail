package org.intermedia.view;

/**
 * This class builds the static part of the home page
 * 
 * @author Raphael Harmel
 */

import js.Lib;
import js.Dom;
import org.intermedia.view.Constants;
import org.intermedia.view.StyleModel;
import org.intermedia.model.ApplicationModel;


//class HomePage extends ListViewBase
class HomePage extends ViewBase
{
	
	//Called when an item is selected.
	public var onListItemSelected:CellData->Void;
	
	// cells array
	public var cells:Array<CellBase>;
	
	public function new(initData:Dynamic) 
	{
		_data = initData;
		cells = new Array<CellBase>();
		super();
	}
	
	override private function buildView():Void
	{
		// add custom cells to the homepage
		
		var cell0Style:CellStyleModel = {
			//cell:CellThumbText1Style.setCellStyle,
			cell:CellThumbStyle.setCellStyle,
			//thumbnail:CellThumbStyle.setThumbnailStyle,
			thumbnail:null,
			textBlock:null,
			title:null,
			author:null,
			line:null
		};
		
		var cell0 = new CellThumb(1,cell0Style);
		cell0.data = _data[0];
		// set mouseUp callback
		cell0.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell0.data); };
		node.appendChild(cell0.node);
		cells.push(cell0);

		var cell1 = new CellThumb(2,cell0Style);
		cell1.data = _data[1];
		// set mouseUp callback
		cell1.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell1.data); };
		node.appendChild(cell1.node);
		cells.push(cell1);

		var cell2 = new CellThumb(2,cell0Style);
		cell2.data = _data[2];
		// set mouseUp callback
		cell2.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell2.data); };
		node.appendChild(cell2.node);
		cells.push(cell2);

		//var cell3 = new CellThumbText1(2);
		var cell3 = new CellThumb(2,cell0Style);
		cell3.data = _data[3];
		//trace(cell3.data);
		// set mouseUp callback
		cell3.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell3.data); };
		node.appendChild(cell3.node);
		cells.push(cell3);

		//var cell4 = new CellThumbText1(2);
		var cell4 = new CellThumb(2,cell0Style);
		cell4.data = _data[4];
		// set mouseUp callback
		cell4.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell4.data); };
		node.appendChild(cell4.node);
		cells.push(cell4);
		
		/*var cell5 = new CellThumbText1(2);
		cell5.data = _data[5];
		// set mouseUp callback
		cell5.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell5.data); };
		node.appendChild(cell5);
		
		var cell6 = new CellThumb(2,cell0Style);
		cell6.data = _data[6];
		// set mouseUp callback
		cell6.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell6.data); };
		node.appendChild(cell6);

		var cell7 = new CellThumbText1(2);
		cell7.data = _data[7];
		// set mouseUp callback
		cell7.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell7.data); };
		node.appendChild(cell7);
		
		var cell8 = new CellThumb(2,cell0Style);
		cell8.data = _data[8];
		// set mouseUp callback
		cell8.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell8.data); };
		node.appendChild(cell8);*/

	}
	
	/**
	 *  load thumb image
	 */
	private function loadThumb(url:String):HtmlDom
	{
		// THUMBNAIL
		var image:Image = cast Lib.document.createElement("img");
		// set image style
		image.style.verticalAlign = "middle";
		// add image
		node.appendChild(image);
		// load image
		image.src = url;
		
		return image;
	}

	/**
	 * onListItemSelected callback
	 * @param	cellData
	 */
	public function onListItemSelectedCallback(cellData:CellData)
	{
		if (onListItemSelected != null)
		{
			onListItemSelected(cellData);
		}
	}
	
	
}