package org.intermedia.view;

import cocktail.mouse.MouseData;
import org.intermedia.model.ApplicationModel;

/**
 * Base class for list views. Inherithed by the 3 ListViews.
 * 
 * @author Raphael Harmel
 */

class ListViewBase extends ViewBase
{

	//Called when an item is selected.
	public var onListItemSelected:CellData->Void;
	
	//Called when the user has scrolled to the bottom of the list, and
	//more cell data might need to be fetched
	public var onListScrolled:Void->Void;
	
	//Hold a ref to each created cells
	private var _cells:Array<CellBase>;

	//public function new(?listItemSelectedCallback:CellData->Void = null) 
	public function new() 
	{
		super();
		_cells = new Array<CellBase>();
		
		/*if (listItemSelectedCallback != null)
		{
			onListItemSelected = listItemSelectedCallback;
		}*/
	}
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		for (index in Reflect.fields(_data))
		{
			// build cell
			//var cell:CellThumbText1 = new CellThumbText1();
			var cell:CellBase = createCell();
			
			// set cell data
			cell.data = Reflect.field(_data, index);
			
			// set mouseUp callback
			cell.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell.data); };
			
			// push created cell to _cells
			_cells.push(cell);

			// add cell to list
			this.addChild(cell);
		}
	}
	
	/**
	 * Creates a cell of the correct type
	 * To be overriden in child classes
	 * 
	 * @return
	 */
	private function createCell():CellBase
	{
		var cell:CellBase = new CellBase();
		return cell;
	}
	
	/*private function onCellSelected(cellData:CellData):Void
	{
		if (onListItemSelected != null)
		{
			onListItemSelected(cellData);
		}
	}*/
	
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
