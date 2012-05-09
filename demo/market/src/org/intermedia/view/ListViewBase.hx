package org.intermedia.view;

import haxe.Firebug;
import js.Lib;
import js.Dom;
import org.intermedia.model.ApplicationModel;
import haxe.Timer;
import org.intermedia.Settings;

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
	
	// list bottom loader image container
	private var _listBottomLoader:HtmlDom;

	// list bottom loader image
	var _bottomLoaderImage:Image;

	// _time is used to compute execution time for analysing performance
	//private var _time:Float;
	
	public function new()
	{
		super();
		
		// init style
		//if (_style == null) initStyle();
		initStyle();
		
		// apply style
		_style.list(node);

		displayListBottomLoader = true;
		_cells = new Array<CellBase>();
		
		buildBottomLoader();
		
		node.onscroll = onScrollCallback;
		
		//_time = Timer.stamp();
		
	}
	
	/**
	 * initialize the default style
	 */
	private function initStyle():Void
	{
		// init style model
		_style = {
			list:ListViewStyle.setListStyle,
			//bottomLoaderImage:ListViewStyle.loaderImage,
			//bottomLoaderCell:CellStyle.setCellStyle
		}
	}
	
	/**
	 * Bottom loader builder
	 */
	private function buildBottomLoader():Void
	{
		_bottomLoaderImage = cast Lib.document.createElement("img");
		//_style.bottomLoaderImage(_bottomLoaderImage);
		ListViewStyle.loaderImage(_bottomLoaderImage);
		_bottomLoaderImage.src = "assets/loading.gif";
		_listBottomLoader = Lib.document.createElement("div");
		_listBottomLoader.appendChild(_bottomLoaderImage);
		//_style.bottomLoaderCell(_listBottomLoader);
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
		
		//haxe.Firebug.trace("List " + id + " updated in " + Std.string((Timer.stamp() - _time) * 1000).substr(0, 5) + "ms");
		//trace("List " + id + " updated in " + Std.string((Timer.stamp() - _time) * 1000).substr(0, 5) + "ms");
		
		// if list is attached to body
		if(node.parentNode.parentNode != null)
		{
			// if list content height is not filling the totality of the screen's height
			// removed as now list update is done without beeing attached, and as a result scrollHeight equals 0
			/*Firebug.trace("node.scrollHeight: " + node.scrollHeight);
			if (node.scrollHeight <= (Lib.window.innerHeight - Constants.LIST_TOP) + Constants.LIST_BOTTOM_LOADER_VERTICAL_MARGIN)
			{
				// request more data
				onDataRequestCallback(id);
			}*/
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
	private function onScrollCallback(event:Event):Void
	{
		// if the bottom of the loading screen is reached via scrolling
		if (node.scrollTop >= node.scrollHeight - (Lib.window.innerHeight - Constants.LIST_TOP) - Constants.LIST_BOTTOM_LOADER_VERTICAL_MARGIN)
		{
			// if using online data
			if(Settings.ONLINE)
			{
				// call callback
				onDataRequestCallback(id);
			}
			// if using local data
			else
			{
				// instead of calling onDataRequestCallback(id), we reload the same data again (way faster !)
				data = _data;
			}
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
			// if list has not already requested new data, request new data
			onDataRequest(id);
		}
	}
	
	/**
	 * Refresh list styles
	 */
	public function refreshStyles():Void
	{
		// apply style
		_style.list(node);
		//ListViewStyle.setListStyle(node);
		for (cell in _cells)
		{
			cell.refreshStyles();
		}
	}


}
