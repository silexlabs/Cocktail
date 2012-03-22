package org.intermedia.view;

import cocktail.classInstance.ClassInstance;
import cocktail.domElement.DOMElementData;
import cocktail.domElement.ImageDOMElement;
import cocktail.mouse.MouseData;
import cocktail.viewport.Viewport;
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
	public var onListScrolled:String->Void;
	
	// display list end loader
	public var displayListBottomLoader:Bool;
	
	//Hold a ref to each created cells
	private var _cells:Array<CellBase>;
	
	// the list id feed, used to store the feedUrl
	public var id:String;
	
	// list bottom loader
	private var _listBottomLoader:ImageDOMElement;

	public function new()
	{
		super();
		
		displayListBottomLoader = true;
		_cells = new Array<CellBase>();
		
		_listBottomLoader = new ImageDOMElement();
		ListViewStyle.loader(_listBottomLoader);
		_listBottomLoader.load("assets/loading.gif");
		
		this.onScroll = onScrollCallback;
		
	}
	
	
	/**
	 * update view
	 */
	override private function updateView():Void
	{
		for (index in Reflect.fields(_data))
		{
			// build cell
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
		
		// if loader is attached to to list container, detach it
		if (_listBottomLoader.parent != null)
		{
			this.removeChild(_listBottomLoader);
		}
		// add loader at the bottom of the screen if there is still data to load
		if(displayListBottomLoader == true)
		{
			this.addChild(_listBottomLoader);
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
	
	/**
	 * list scroll callback
	 * @param	event
	 */
	override private function onScrollCallback(event:ScrollEventData):Void
	{
		// if the bottom of the list is reached via scrolling
		if (event.scrollTop >= event.scrollHeight - new Viewport().height)
		{
			// call callback
			onScrolledCallback(id);
		}
	}
	
	/**
	 * list fully scrolled callback
	 * @param	event
	 */
	private function onScrolledCallback(id:String):Void
	{
		// call callback
		if (onListScrolled != null)
		{
			onListScrolled(id);
		}
	}
	
}
