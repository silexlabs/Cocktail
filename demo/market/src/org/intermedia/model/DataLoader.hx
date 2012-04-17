package org.intermedia.model;

//import cocktail.Cocktail;
//import org.intermedia.model.XmlLoader;
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

	/*private function onLoadingError(unknown:Dynamic):Void
	{
		trace("error in DataLoader");
	}*/
	
	//public function new(?itemsToLoad:Int = 10, ?pageIndex:Int = 1, ?online:Bool=true)
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
			
			fullUrl = feed + "?posts_per_page=" + itemsPerPage + "&paged=" + pageIndex;
			//haxe.Log.trace(fullUrl);
			// handle page index
			//_pageIndex++;
			
		}
		// prepare local feed url
		else
		{
			//fullUrl = "data/silex_plugins.rss";
			if (feed == Feeds.FEED_1.url)
				fullUrl = "data/feed1.rss";
			else if (feed == Feeds.FEED_2.url)
				fullUrl = "data/feed2.rss";
			else if (feed == Feeds.FEED_3.url)
				fullUrl = "data/feed3.rss";
		}
		
		// load xml feed
		var xmlLoader:XmlLoader = new XmlLoader(fullUrl, _online, onCellsXmlLoaded, onLoadingError, feed);
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
		if (_online) fullUrl = "http://www.silexlabs.org/feed/ep_get_item_info?format=rss2&p=" + cellData.id;
		// prepare local feed url
		else fullUrl = "data/detail.rss";
		
		// load xml feed
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
		onCellDataLoaded({id:listId ,cells:ThumbTextListRssStandard.rss2Cells(xml)});
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
