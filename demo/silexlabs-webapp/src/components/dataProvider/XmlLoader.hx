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

package components.dataProvider;

import haxe.Http;

class XmlLoader
{
	// Defines onLoad callback, called when the xml feed is loaded
	public var onLoad : Xml->Void;

	/**
	 * Constuctor
	 * 
	 * @param	xmlFeedPath
	 */
	public function new(xmlUrl:String) 
	{
		// load the xml feed
		loadXmlFeed(xmlUrl);
	}
	
	/**
	 * Loads the xml
	 * 
	 * @param	xmlUrl
	 */
	private function loadXmlFeed(xmlUrl:String):Void
	{
		var http:Http = new Http("http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl));
		http.onData = onXmlLoaded;
		http.onError = onXmlError;
		http.request(false);
	}
	
	/**
	 * Xml feeds error callback
	 * 
	 * @param	msg
	 */
	private function onXmlError( msg : String ):Void
	{
		trace("Error while loading XML feed : " + msg);
	}
	
	/**
	 * Xml feeds success callback
	 * 
	 * @param	response
	 */
	private function onXmlLoaded(xmlString:String):Void
	{
		// parse the xml feed
		var xml:Xml =  Xml.parse(xmlString);

		// calls onLoad callback with xml
		if (onLoad != null)
		{
			onLoad(xml);
		}
	}
	
}