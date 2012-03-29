package org.intermedia.view;

/**
 * This class builds the static part of the home page
 * 
 * @author Raphael Harmel
 */

import cocktail.domElement.ImageDOMElement;

// Style
import cocktail.style.StyleData;
import cocktail.unit.UnitData;
import org.intermedia.view.Constants;
import cocktail.mouse.MouseData;
import org.intermedia.view.StyleModel;
import org.intermedia.model.ApplicationModel;


//class HomePage extends ListViewBase
class HomePage extends ViewBase
{
	
	//Called when an item is selected.
	public var onListItemSelected:CellData->Void;
	
	public function new(initData:Dynamic) 
	{
		_data = initData;
		super();
		//trace(initData);
	}
	
	override private function buildView():Void
	//override private function updateView():Void
	{
		// add custom cells to the homepage
		
		var cell0Style:CellThumbText1StyleModel = {
			cell:CellThumbText1Style.setCellStyle,
			thumbnail:CellThumbStyle2.setThumbnailStyle,
			textBlock:null,
			title:null,
			author:null,
			line:null
		};
		
		var cell0 = new CellThumb(1,cell0Style);
		cell0.data = _data[0];
		// set mouseUp callback
		cell0.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell0.data); };
		this.addChild(cell0);

		var cell1 = new CellThumb(2,cell0Style);
		cell1.data = _data[1];
		// set mouseUp callback
		cell1.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell1.data); };
		this.addChild(cell1);

		var cell2 = new CellThumb(2,cell0Style);
		cell2.data = _data[2];
		// set mouseUp callback
		cell2.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell2.data); };
		this.addChild(cell2);

		var cell3 = new CellThumbText1(2);
		cell3.data = _data[3];
		//trace(cell3.data);
		// set mouseUp callback
		cell3.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell3.data); };
		this.addChild(cell3);

		var cell4 = new CellThumbText1(2);
		cell4.data = _data[4];
		// set mouseUp callback
		cell4.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell4.data); };
		this.addChild(cell4);
		
		/*var cell5 = new CellThumbText1(2);
		cell5.data = _data[5];
		// set mouseUp callback
		cell5.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell5.data); };
		this.addChild(cell5);
		
		var cell6 = new CellThumb(2,cell0Style);
		cell6.data = _data[6];
		// set mouseUp callback
		cell6.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell6.data); };
		this.addChild(cell6);

		var cell7 = new CellThumbText1(2);
		cell7.data = _data[7];
		// set mouseUp callback
		cell7.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell7.data); };
		this.addChild(cell7);
		
		var cell8 = new CellThumb(2,cell0Style);
		cell8.data = _data[8];
		// set mouseUp callback
		cell8.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell8.data); };
		this.addChild(cell8);*/

	}
	
	/**
	 *  load thumb image
	 */
	private function loadThumb(url:String):ImageDOMElement
	{
		// THUMBNAIL
		var image = new ImageDOMElement();
		// set image style
		image.style.verticalAlign = middle;
		// add image
		this.addChild(image);
		// load image
		image.load(url);
		
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