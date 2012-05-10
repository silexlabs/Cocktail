package org.intermedia.view;

import js.Lib;
import js.Dom;
import org.intermedia.view.Constants;
import org.intermedia.model.ApplicationModel;
import org.intermedia.view.StyleModel;

/**
 * This class builds the static part of the home page
 * 
 * @author Raphael Harmel
 */

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
		// init style model
		var cellStyle:CellStyleModel = {
			cell:CellThumbText1BisStyle.setCellStyle,
			thumbnailMask:CellThumbStyle.setThumbnailMaskStyle,
			thumbnail:null,
			textBlock:null,
			title:null,
			author:null
		};
		
		// add custom cells to the homepage
		
		var cell0 = new CellThumb(1,cellStyle);
		cells.push(cell0);

		var cell1 = new CellThumb(2,cellStyle);
		cells.push(cell1);

		var cell2 = new CellThumb(2,cellStyle);
		cells.push(cell2);

		var cell3 = new CellThumb(2,cellStyle);
		cells.push(cell3);

		var cell4 = new CellThumb(2,cellStyle);
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
		
		for (i in 0...cells.length)
		{
			// fill cell with corresponding data
			cells[i].data = _data[i];
			// set mouseUp callback
			cells[i].node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cells[i].data); };
			// attach cell to homepage
			node.appendChild(cells[i].node);
		}

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