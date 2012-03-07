package org.intermedia.model;

import org.intermedia.model.XmlLoader;
import org.intermedia.model.ApplicationModel;

/**
 * Load RSS and parse them into CellData or DetailData returned to the ApplicationModel
 * 
 * @author Raphael Harmel
 */

class DataLoader 
{

	// Defines onLoad callback, called when the xml feed is loaded
	private var onCellDataLoaded : Array<CellData>->Void;
	private var onCellDetailLoaded : DetailData->Void;
	private var onLoadingError : Dynamic->Void;
	
	// online/offline switch
	private var _online:Bool;

	/*private function onLoadingError(unknown:Dynamic):Void
	{
		trace("error in DataLoader");
	}*/
	
	public function new(?online:Bool=true)
	{
		_online = online;
	}
	
	/**
	 * Starts loading an RSS feed, construct the URL with the right GET params to load the CellData.
	 * @param	startIndex
	 * @param	endIndex
	 * @param	?callBack
	 */
	public function loadCellData(startIndex:Int, endIndex:Int, successCallback:Array<CellData>->Void, errorCallback:Dynamic->Void):Void
	{
		// set callbacks
		onCellDataLoaded = successCallback;
		onLoadingError = errorCallback;
		
		var fullUrl:String = "";
		
		// prepare online feed url
		if (_online) fullUrl = "http://www.silexlabs.org/feed/ep_posts_small/?cat=657&format=rss2";
		// prepare local feed url
		else fullUrl = "data/silex_plugins.rss";
		
		// load xml feed
		var xmlLoader:XmlLoader = new XmlLoader(fullUrl, _online, onCellsXmlLoaded, onLoadingError);
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
		//var onLoadDelegate:Xml->CellData->Void = onCellDetailXmlLoaded;
		//xmlLoader.onLoad = function(xml:Xml) { onLoadDelegate(xml, cellData); };
		//xmlLoader.onLoadSuccess = function(xml:Xml) { onCellDetailXmlLoaded(xml, cellData); };
		var onLoadSuccessDelegate:Xml->Void = function(xml:Xml) { onCellDetailXmlLoaded(xml, cellData); };
		
		//var rssPath:String = "http://www.silexlabs.org/feed/ep_posts_in_category/?p=" + 81290 + "&format=rss2";
		//var rssPath:String = "http://www.silexlabs.org/feed/ep_posts_in_category/?p=" + cellData.id + "&format=rss2";
		//var rssPath:String = "http://www.silexlabs.org/feed/?p=" + cellData.id + "&format=rss2";
		//var rssPath:String = "http://www.silexlabs.org/feed/?s=" + cellData.id + "&format=rss2";
		//var rssPath:String = "http://www.silexlabs.org/feed/ep_posts_in_category/?s=" + cellData.id + "&format=rss2";
		//var xmlLoader:XmlLoader = new XmlLoader(rssPath);

		//var rssPath:String = "http://www.silexlabs.org/feed/?s=" + cellData.title.substr(0,cellData.title.indexOf(" ")) + "&format=rss2";
		//var xmlLoader:XmlLoader = new XmlLoader(rssPath, onLoadSuccessDelegate, onLoadingError);
		
		var fullUrl:String = "";
		
		// prepare online feed url
		if (_online) fullUrl = "http://www.silexlabs.org/feed/?s=" + cellData.title.substr(0,cellData.title.indexOf(" ")) + "&format=rss2";
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
	private function onCellsXmlLoaded(xml:Xml):Void
	{
		//trace("onCellsXmlLoaded");
		onCellDataLoaded(ThumbTextListRss.rss2Cells(xml));
	}	
	
	/**
	 * cell detail rss loaded callback
	 * converts the xml to DetailData
	 * 
	 * @param	xml
	 */
	private function onCellDetailXmlLoaded(xml:Xml,cellData:CellData):Void
	{
		//trace("onCellDetailXmlLoaded");
		onCellDetailLoaded(CellDetailsRss.rss2CellDetail(xml,cellData));
	}
	
}
