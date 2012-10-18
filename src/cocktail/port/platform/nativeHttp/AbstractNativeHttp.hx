/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.nativeHttp;

import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.EventTarget;
import cocktail.core.event.ProgressEvent;
import cocktail.port.platform.nativeHttp.NativeHTTPData;

/**
 * This class is a base abstract class used
 * to make http request. NAtive API calls
 * are implemented for each platform
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractNativeHttp extends EventTarget
{
	/**
	 * The interval in milliseconds between dispatching 2
	 * progress events while loading a resource
	 */
	private static inline var PROGRESS_UPDATE_FREQUENCY:Int = 50;
	
	/**
	 * The last returned http status code
	 */
	public var status(default, null):Int;
	
	/**
	 * The total number of bytes of the loaded
	 * resource
	 */
	public var total(get_total, null):Int;
	
	/**
	 * The current number of loaded bytes for
	 * the loaded resource
	 */
	public var loaded(get_loaded, null):Int;
	
	/**
	 * The response headers of the http request
	 */
	public var responseHeaders(default, null):Hash<String>;
	
	/**
	 * The response from the http request which might be
	 * text or binaries
	 */
	public var response(default, null):Dynamic;
	
	/**
	 * A flag determining wether the response headers
	 * have bee loaded yet
	 */
	public var responseHeadersLoaded(default, null):Bool;
	
	/**
	 * A flag determining wether a networking error occured while 
	 * loading
	 */
	public var error(default, null):Bool;
	
	/**
	 * A flag determining wether the resource is completely
	 * and successfuly loaded
	 */
	public var complete(default, null):Bool;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Start the loading of a resource
	 * 
	 * @param	url the url to load
	 * @param	method the http method to use
	 * @param	data the data to send with the request
	 * @param	authorRequestHeaders the author defined http headers
	 * to use with the request
	 * @param	dataFormat wether the data is received as text or binary data
	 */
	public function load(url:String, method:String, data:Dynamic, authorRequestHeaders:Hash<String>, dataFormat:DataFormatValue):Void
	{
		//reset all class attributes before loading
		status = 0;
		total = 0;
		loaded = 0;
		responseHeaders = new Hash<String>();
		responseHeadersLoaded = false;
		response = null;
		error = false;
		complete = false;
		
		doLoad(url, method, data, authorRequestHeaders, dataFormat);
		
		//start dispatching progress events
		Lib.document.timer.delay(onLoadProgress, PROGRESS_UPDATE_FREQUENCY);
	}
	
	/**
	 * Stops any networking activity
	 */
	public function close():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually starts loading the resource, overriden by each platform 
	 */
	private function doLoad(url:String, method:String, data:Dynamic, authorRequestHeaders:Hash<String>, dataFormat:DataFormatValue):Void
	{
		//abstract
	}
	
	/**
	 * Dispatched at regular interval while
	 * loading, keeps track of currently
	 * loaded number of bytes.
	 *
	 *  Responsible for determining if the loading
	 * is complete or if there was error while loading
	 */
	private function onLoadProgress(time:Float):Void
	{
		//if there was an error, stop update and dispatched
		//error event
		if (error == true)
		{
			var errorEvent:Event = new Event();
			errorEvent.initEvent(EventConstants.ERROR, false, false);
			dispatchEvent(errorEvent);
		}
		//here load was successful
		else if (complete == true)
		{
			var loadEvent:Event = new Event();
			loadEvent.initEvent(EventConstants.LOAD, false, false);
			dispatchEvent(loadEvent);
		}
		//here load still in progress, dispatched progress event
		//then delay another call to this method
		else
		{
			var progressEvent:ProgressEvent = new ProgressEvent();
			progressEvent.initProgressEvent(EventConstants.PROGRESS, false, false, false, loaded, total);
			dispatchEvent(progressEvent);
			
			Lib.document.timer.delay(onLoadProgress, PROGRESS_UPDATE_FREQUENCY);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_total():Int
	{
		return -1;
	}
	private function get_loaded():Int
	{
		return -1;
	}
	
}