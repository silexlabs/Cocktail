/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.EventTarget;
import cocktail.event.ProgressEvent;
import cocktail.core.html.HTMLDocument;
import cocktail.core.http.HTTPData;
import cocktail.timer.Timer;

/**
 * This class is a base abstract class used
 * to make http request. NAtive API calls
 * are implemented for each platform
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeHttpBase extends EventTarget
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
	public var responseHeaders(default, null):Map<String, String>;
	
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
	 * Store the last loaded url
	 */
	private var _url:String;
	
	/**
	 * Set to true when close is called
	 */
	private var _closed:Bool;
	
	/**
	 * a reference to a timer used to delay calls
	 */
	private var _timer:Timer;
	
	/**
	 * class constructor
	 */
	public function new(timer:Timer) 
	{
		super();
		_timer = timer;
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
	public function load(url:String, method:String, data:Dynamic, authorRequestHeaders:Map<String, String>, dataFormat:DataFormatValue):Void
	{
		//reset all class attributes before loading
		status = 0;
		total = 0;
		loaded = 0;
		responseHeaders = new Map<String, String>();
		responseHeadersLoaded = false;
		response = null;
		error = false;
		complete = false;
		_closed = false;
		
		_url = url;
		
		doLoad(url, method, data, authorRequestHeaders, dataFormat);
		
		//start dispatching progress events
		_timer.delay(onLoadProgress, PROGRESS_UPDATE_FREQUENCY);
	}
	
	/**
	 * Stops any networking activity
	 */
	public function close():Void
	{
		_closed = true;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually starts loading the resource, overriden by each platform 
	 */
	private function doLoad(url:String, method:String, data:Dynamic, authorRequestHeaders:Map<String, String>, dataFormat:DataFormatValue):Void
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
		//then delay another call to this method, unless the loading
		//was explicitely stopped by the user
		else if (_closed == false)
		{
			var progressEvent:ProgressEvent = new ProgressEvent();
			progressEvent.initProgressEvent(EventConstants.PROGRESS, false, false, false, loaded, total);
			dispatchEvent(progressEvent);
			
			_timer.delay(onLoadProgress, PROGRESS_UPDATE_FREQUENCY);
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
