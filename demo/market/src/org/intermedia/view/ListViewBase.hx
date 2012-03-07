package org.intermedia.view;

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
