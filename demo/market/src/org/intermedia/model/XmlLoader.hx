/*
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/

/**
 * This class reads an xml
 * 
 * @author Raphael Harmel
 */

package org.intermedia.model;

import haxe.Http;
import org.intermedia.model.ApplicationModel;

class XmlLoader
{
	// Defines onLoadSuccess callback, called when the xml feed is loaded
	private var onLoadSuccess : String->Xml->Void;

	// Defines onLoadError callback, called when the xml feed has not been loaded succesfully
	private var onLoadError : Dynamic->Void;
	
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
	public function new(xmlUrl:String, online:Bool, successCallback:String->Xml->Void, errorCallback:Dynamic->Void, ?listId:String="") 
	{
		_online = online;
		
		// set the callbacks
		onLoadSuccess = successCallback;
		onLoadError = errorCallback;
		
		// load the xml feed
		loadXmlFeed(listId, xmlUrl);
	}
	
	/**
	 * Loads the xml
	 * 
	 * @param	xmlUrl
	 */
	private function loadXmlFeed(listId:String, xmlUrl:String):Void
	{
		var fullUrl:String = "";
		
		// build feed's full url
		fullUrl = "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl);

		// try to load the xml feed using a Silex labs proxy
		try
		{
			var httpRequest:Http = new Http(fullUrl);
			httpRequest.onData = function (xml:String) { onXmlLoaded(listId, xml); };
			httpRequest.onError = onXmlError;
			httpRequest.request(false);
		}
		// catch the error if any
		catch (error:Dynamic)
		{
			onXmlError(error);
		}
	}
	
	/**
	 * Xml feeds error callback
	 * 
	 * @param	msg
	 */
	private function onXmlError(error:Dynamic):Void
	{
		// calls onLoad callback with xml
		if (onLoadError != null)
		{
			onLoadError(error);
		}
	}
	
	/**
	 * Xml feeds success callback
	 * 
	 * @param	response
	 */
	private function onXmlLoaded(listId:String, xmlString:String):Void
	{
		// parse the xml feed
		var xml:Xml =  Xml.parse(xmlString);

		// calls onLoadSuccess callback with xml
		if (onLoadSuccess != null)
		{
			onLoadSuccess(listId,xml);
		}
	}
	
}