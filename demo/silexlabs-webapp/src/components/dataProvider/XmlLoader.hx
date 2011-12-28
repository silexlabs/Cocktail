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

package components.dataProvider;

import cocktail.resource.ResourceLoaderManager;

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
		ResourceLoaderManager.loadString( "http://demos.silexlabs.org/cocktail/simple-webapp/XmlProxy.php?url=" + StringTools.urlEncode(xmlUrl), onXmlLoaded, onXmlError);
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