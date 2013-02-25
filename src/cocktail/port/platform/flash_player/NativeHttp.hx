/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.flash_player;

import cocktail.core.http.HTTPConstants;
import cocktail.port.base.NativeHttpBase;
import flash.display.Loader;
import flash.events.Event;
import flash.events.HTTPStatusEvent;
import flash.events.IOErrorEvent;
import flash.events.ProgressEvent;
import flash.events.SecurityErrorEvent;
import flash.net.URLLoader;
import flash.net.URLLoaderDataFormat;
import flash.net.URLRequest;
import cocktail.core.http.HTTPData;

/**
 * This is the implementation of the http class
 * for the flash platform
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeHttp extends NativeHttpBase
{
	/**
	 * The flash URLLoader, used for 
	 * http request on the flash platform
	 */
	private var _urlLoader:URLLoader;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		_urlLoader = new URLLoader();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to stop resource loading
	 */
	override public function close():Void
	{
		_urlLoader.close();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Overriden to use flash native URLLoader for the http request
	 * 
	 * TODO 2 : implement custom request header
	 */
	override private function doLoad(url:String, method:String, data:Dynamic, authorRequestHeaders:Hash<String>, dataFormat:DataFormatValue):Void
	{
		super.doLoad(url, method, data, authorRequestHeaders, dataFormat);
		
		//create a flash URLRequest, storing each parameters of the request
		var urlRequest:URLRequest = new URLRequest(url);
		urlRequest.method = method;
		urlRequest.data = data;
		
		//set the loaded data format
		switch(dataFormat)
		{
			case DataFormatValue.TEXT:
				_urlLoader.dataFormat = URLLoaderDataFormat.TEXT;
				
			case DataFormatValue.BINARY:
				_urlLoader.dataFormat = URLLoaderDataFormat.BINARY;
		}
		
		//listen for update on the request
		_urlLoader.addEventListener(HTTPStatusEvent.HTTP_STATUS, onHttpStatus);
		_urlLoader.addEventListener(IOErrorEvent.IO_ERROR, onIOError);
		_urlLoader.addEventListener(Event.COMPLETE, onNativeLoadComplete);
		_urlLoader.addEventListener(SecurityErrorEvent.SECURITY_ERROR, onSecurityError);
		
		//actually starts the request
		_urlLoader.load(urlRequest);
		
		//there is no way in flash (except for AIR) to get the response header,
		//so they are considered instantly loaded
		responseHeadersLoaded = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the error flag
	 */
	private function onIOError(event:IOErrorEvent):Void
	{
		error = true;
	}
	
	/**
	 * Set the complete flag, store the loaded resource
	 */
	private function onNativeLoadComplete(event:Event):Void
	{
		response = _urlLoader.data;
		complete = true;
	}
	
	/**
	 * Update the http status code
	 */
	private function onHttpStatus(event:HTTPStatusEvent):Void
	{
		status = event.status;
	}
	
	/**
	 * Called when there is a cross-domain loading issue.
	 * 
	 * This can happen when a swf is loaded from another domain.
	 * Restart the load with a specialised SWF loader which can
	 * circumvent those errors, 
	 * this is hackish, main hack is that it assumes that this is
	 * a swf which is loaded
	 */
	private function onSecurityError(event:SecurityErrorEvent):Void
	{
		var resource:SWFResource = new SWFResource(_url);
		resource.addEventListener("load", function(e) {
			var swfLoader:Loader = resource.nativeResource;
			response = swfLoader;
			complete = true;
			
			//send the event instantaneously in this case, to prevent
			//from missing init event dispatched by the loaded swf, close
			//the loading to prevent scheduling another progress update which
			//would dispatch another load event
			close();
			onLoadProgress(0);
			
		});
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTERS/SETTERS
	// return data from the URLLoader
	//////////////////////////////////////////////////////////////////////////////////////////

	override private function get_total():Int
	{
		return _urlLoader.bytesTotal;
	}
	
	override private function get_loaded():Int
	{
		return _urlLoader.bytesLoaded;
	}
	
}