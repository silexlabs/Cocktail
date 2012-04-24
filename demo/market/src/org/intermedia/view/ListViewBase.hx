package org.intermedia.view;

import js.Lib;
import js.Dom;
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
	//public var onListScrolled:String->Void;
	
	// called when the list is requesting more data to be loaded
	public var onDataRequest:String->Void;
	
	// display list end loader
	public var displayListBottomLoader:Bool;
	
	//Hold a ref to each created cells
	private var _cells:Array<CellBase>;
	
	// the list id feed, used to store the feedUrl
	public var id:String;
	
	// list bottom loader
	//private var _listBottomLoader:Image;
	private var _listBottomLoader:HtmlDom;

	public function new()
	{
		super();
		
		ListViewStyle.setListStyle(node);
		
		displayListBottomLoader = true;
		_cells = new Array<CellBase>();
		
		buildBottomLoader();
		
		//node.onScroll = onScrollCallback;
		node.onscroll = onScrollCallback;
		
	}
	
	/**
	 * Bottom loader builder
	 */
	private function buildBottomLoader():Void
	{
		var bottomLoaderImage:Image = cast Lib.document.createElement("img");
		ListViewStyle.loaderImage(bottomLoaderImage);
		bottomLoaderImage.src = "assets/loading.gif";
		_listBottomLoader = Lib.document.createElement("div");
		_listBottomLoader.appendChild(bottomLoaderImage);
		CellStyle.setCellStyle(_listBottomLoader);
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
			//cell.onMouseUp = function(mouseEventData:MouseEventData) { onListItemSelectedCallback(cell.data); };
			cell.node.onmouseup = function(mouseEventData:Event) { onListItemSelectedCallback(cell.data); };
			
			// push created cell to _cells
			_cells.push(cell);

			// add cell to list
			node.appendChild(cell.node);
		}
		
		// if loader is attached to to list container, detach it
		if (_listBottomLoader.parentNode != null)
		{
			node.removeChild(_listBottomLoader);
		}
		// add loader at the bottom of the screen if there is still data to load
		if(displayListBottomLoader == true)
		{
			node.appendChild(_listBottomLoader);
		}
		
		
		// if list is not attached to body
		//if(this.parentNode.parentNode != null)
		//{
			// if list content height is not filling the totality of the screen's height
			//if (node.scrollHeight < Lib.window.innerHeight && node.scrollHeight != 0)
			/*if (node.scrollHeight < Lib.window.innerHeight)
			{
				// request more data
				onDataRequestCallback(id);
			}*/
		//}
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
	//override private function onScrollCallback(event:ScrollEventData):Void
	private function onScrollCallback(event:Event):Void
	{
		// if the bottom of the list is reached via scrolling
		//if (event.scrollTop >= event.scrollHeight - Lib.window.innerHeight)
		if (node.scrollTop >= node.scrollHeight - Lib.window.innerHeight)
		{
			// call callback
			onDataRequestCallback(id);
		}
	}
	
	/**
	 * load more data request callback
	 * @param	event
	 */
	private function onDataRequestCallback(id:String):Void
	{
		// call callback
		if (onDataRequest != null)
		{
			onDataRequest(id);
		}
	}
	
	/**
	 * Refresh list styles
	 */
	public function refreshStyles():Void
	{
		for (cell in _cells)
		{
			cell.refreshStyles();
		}
	}


}
