package org.intermedia.view;

import cocktail.mouse.MouseData;
import org.intermedia.model.ApplicationModel;

/**
 * Text list view
 * 
 * @author Raphael Harmel
 */

class ListViewText extends ListViewBase
{

	public function new() 
	{
		super();
		ListViewTextStyle.setListStyle(this);
	}
	
	/**
	 * build view
	 */
	/*override private function buildView():Void
	{
		//for (cellData in _data)
		for (index in Reflect.fields(_data))
		{
			// build cell
			var cell:CellText = new CellText();
			
			// set cell data
			//trace(Reflect.field(_data, index));
			cell.data = Reflect.field(_data, index);
			
			// set mouseUp callback
			cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellSelected(cell.data); };
			
			// push created cell to _cells
			_cells.push(cell);
			this.addChild(cell);
		}
	}*/
	
	/**
	 * build view
	 */
	override private function updateView():Void
	{
		for (index in Reflect.fields(_data))
		{
			// build cell
			var cell:CellText = new CellText();
			
			// set cell data
			cell.data = Reflect.field(_data, index);
			
			// set mouseUp callback
			cell.onMouseUp = function(mouseEventData:MouseEventData) { onCellSelected(cell.data); };
			
			// push created cell to _cells
			_cells.push(cell);
			this.addChild(cell);
		}
	}
	
	private function onCellSelected(cellData:CellData):Void
	{
		if (onListItemSelected != null)
		{
			onListItemSelected(cellData);
		}
	}
	
}