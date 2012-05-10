package org.intermedia.model;

import js.Lib;
import haxe.Firebug;
import org.intermedia.model.ApplicationModel;

/**
 * Loads a rss feed and parses it either to a CellData or a DetailData returned to the ApplicationModel
 * 
 * @author Raphael Harmel
 */

class DataLoader 
{

	// Defines onLoad callback, called when the xml feed is loaded
	private var onCellDataLoaded : ListData->Void;
	private var onCellDetailLoaded : DetailData->Void;
	private var onLoadingError : Dynamic->Void;
	
	// online/offline switch
	private var _online:Bool;
	
	// quantity of rss items to load
	private var _itemsToLoad:Int;
	
	// page index containing _itemsToLoad items
	private var _pageIndex:Int;

	// feed page index Hash containing page index for each already requested list
	private var _pageIndexHash:Hash<Int>;

	public function new(?online:Bool=true)
	{
		// init private attributes
		_pageIndex = 1;
		_pageIndexHash = new Hash<Int>();
		_online = online;
		
	}
	
	/**
	 * Starts loading an RSS feed, construct the URL with the right GET params to load the CellData.
	 * @param	startIndex
	 * @param	endIndex
	 * @param	?callBack
	 */
	public function loadCellData(feed:String, itemsPerPage:Int, successCallback:ListData->Void, errorCallback:Dynamic->Void):Void
	{
		// set callbacks
		onCellDataLoaded = successCallback;
		onLoadingError = errorCallback;
		
		var fullUrl:String = "";
		
		// prepare online feed url
		if (_online)
		{			
			// current list page index
			var pageIndex:Int = 1;
			
			// handle page index
			if (_pageIndexHash.exists(feed))
			{
				pageIndex = _pageIndexHash.get(feed) + 1;
			}
			_pageIndexHash.set(feed,pageIndex);
			
			// build feed's full Url 
			fullUrl = feed + "?posts_per_page=" + itemsPerPage + "&paged=" + pageIndex;
			
			// load xml feed
			var xmlLoader:XmlLoader = new XmlLoader(fullUrl, _online, onCellsXmlLoaded, onLoadingError, feed);
		}
		// prepare local feed url
		else
		{
			// depending on the feed, load corresponding local xml ressource, parse it and call callback 
			if (feed == Feeds.FEED_1.url)
			{
				onCellsXmlLoaded(feed, Xml.parse(haxe.Resource.getString("feed1")));
			}
			else if (feed == Feeds.FEED_2.url)
			{
				onCellsXmlLoaded(feed, Xml.parse(haxe.Resource.getString("feed2")));
			}
			else if (feed == Feeds.FEED_3.url)
			{
				onCellsXmlLoaded(feed, Xml.parse(haxe.Resource.getString("feed3")));
			}
		}
		
	}
	
	/**
	 * Same as above for detail data
	 * @param	cellData
	 * @param	?callBack
	 */
	public function loadDetailData(cellData:CellData, successCallback:DetailData->Void, errorCallback:Dynamic->Void):Void
	{
		// set callbacks
		onCellDetailLoaded = successCallback;
		onLoadingError = errorCallback;
		
		// Delegate callback
		var onLoadSuccessDelegate:String->Xml->Void = function(listId:String, xml:Xml) { onCellDetailXmlLoaded(xml, cellData); };
		
		var fullUrl:String = "";
		
		// prepare online feed url
		if (_online)
		{
			fullUrl = "http://www.silexlabs.org/feed/ep_get_item_info?format=rss2&p=" + cellData.id;
			
			// load xml feed
			var xmlLoader:XmlLoader = new XmlLoader(fullUrl, _online, onLoadSuccessDelegate, onLoadingError);
		}
		// prepare local feed url
		else
		{
			// load local xml ressource, parse it and call callback 
			onCellDetailXmlLoaded(Xml.parse(haxe.Resource.getString("detail")),cellData);
		}
		
		var xmlLoader:XmlLoader = new XmlLoader(fullUrl, _online, onLoadSuccessDelegate, onLoadingError);
	}
	
	/**
	 * cells rss loaded callback
	 * converts the xml to an Array<CellData>
	 * 
	 * @param	xml
	 */
	private function onCellsXmlLoaded(listId:String, xml:Xml):Void
	{
		onCellDataLoaded({id:listId ,cells:ThumbTextListRssStandard.rss2Cells(xml,listId)});
	}	
	
	/**
	 * cell detail rss loaded callback
	 * converts the xml to DetailData
	 * 
	 * @param	xml
	 */
	private function onCellDetailXmlLoaded(xml:Xml,cellData:CellData):Void
	{
		onCellDetailLoaded(CellDetailsRss.rss2CellDetail(xml,cellData));
	}
	
}
