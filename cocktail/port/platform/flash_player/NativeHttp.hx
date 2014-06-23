/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.event.EventConstants;
import cocktail.core.html.HTMLDocument;
import cocktail.core.http.HTTPConstants;
import cocktail.timer.Timer;
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
	public function new(timer:Timer) 
	{
		super(timer);
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
	override private function doLoad(url:String, method:String, data:Dynamic, authorRequestHeaders:Map<String, String>, dataFormat:DataFormatValue):Void
	{
		super.doLoad(url, method, data, authorRequestHeaders, dataFormat);
		
		//if built with openfl, the text might have been
		//embedded at compile-time
		//TODO : also support bytes
		#if openfl
		if (url.indexOf("http://") == -1 && url.indexOf("https://") == -1) {

			var asset:String = openfl.Assets.getText(url);
			
			//if the asset was embbedded, store it
			if (asset != null)
			{
				response = asset;
				complete = true;
				responseHeadersLoaded = true;
				return;
			}
		}
		#end
		
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
