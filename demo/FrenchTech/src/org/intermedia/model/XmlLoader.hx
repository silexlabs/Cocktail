/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/

/**
 * This class reads an xml
 * 
 * @author Raphael Harmel
 */

package org.intermedia.model;

import haxe.Http;
import org.intermedia.model.ApplicationModel;
import org.intermedia.model.Feed;

class XmlLoader
{
	// Defines onLoadSuccess callback, called when the xml feed is loaded
	private var onLoadSuccess : Feed->Xml->Void;

	// Defines onLoadError callback, called when the xml feed has not been loaded succesfully
	private var onLoadError : Feed->Dynamic->Void;
	
	// online/offline switch
	private var _online:Bool;

	/**
	 * Constuctor
	 * 
	 * @param	xmlUrl
	 * @param	online
	 * @param	successCallback
	 * @param	errorCallback
	 */
	public function new(xmlUrl:String, online:Bool, successCallback:Feed->Xml->Void, errorCallback:Feed->Dynamic->Void, ?feed:Feed) 
	{
		_online = online;
		
		// set the callbacks
		onLoadSuccess = successCallback;
		onLoadError = errorCallback;
		
		// load the xml feed
		loadXmlFeed(feed, xmlUrl);
	}
	
	/**
	 * Loads the xml
	 * 
	 * @param	xmlUrl
	 */
	private function loadXmlFeed(feed:Feed, xmlUrl:String):Void
	{
		var fullUrl:String = "";
		
		// build feed's full url
		fullUrl = "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl);

		// try to load the xml feed using a Silex labs proxy
		try
		{
			var httpRequest:Http = new Http(fullUrl);
			httpRequest.onData = function (xml:String) { onFeedLoaded(feed, xml); };
			httpRequest.onError = function(error:Dynamic) { onFeedLoadError(feed, error); };
			httpRequest.request(false);
		}
		// catch the error if any
		catch (error:Dynamic)
		{
			onFeedLoadError(feed, error);
		}
	}
	
	/**
	 * feeds loading error callback
	 * 
	 * @param	msg
	 */
	private function onFeedLoadError(feed:Feed, error:Dynamic):Void
	{
		// calls onLoad callback with xml
		if (onLoadError != null)
		{
			onLoadError(feed, error);
		}
	}
	
	/**
	 * feeds loading success callback
	 * 
	 * @param	response
	 */
	private function onFeedLoaded(feed:Feed, xmlString:String):Void
	{
		// parse the xml feed
		var xml:Xml =  Xml.parse(xmlString);

		// calls onLoadSuccess callback with xml
		if (onLoadSuccess != null)
		{
			onLoadSuccess(feed,xml);
		}
	}
	
}