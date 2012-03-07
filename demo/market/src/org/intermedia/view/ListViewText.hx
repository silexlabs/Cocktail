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
		ListViewStyle.setListStyle(this);
	}
	
	/**
	 * update view
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

			// add cell to list
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