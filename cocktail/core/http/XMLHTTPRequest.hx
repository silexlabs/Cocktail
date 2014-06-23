/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.http;

import cocktail.core.dom.Document;
import cocktail.core.dom.DOMException;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.EventTarget;
import cocktail.event.ProgressEvent;
import cocktail.core.event.XMLHttpRequestEventTarget;
import cocktail.core.resource.ResourceManager;
import cocktail.timer.Timer;
import cocktail.port.Bindings;
import cocktail.core.http.HTTPData;
import haxe.Http;

/**
 * 
 * @author Yannick DOMINGUEZ
 */
class XMLHTTPRequest extends XMLHttpRequestEventTarget
{
	/**
	 * Returns the current state.
	 */
	public var readyState(default, null):Int;
	
	/**
	 * Returns the response entity body.
	 */
	public var response(get_response, null):Dynamic;
	
	/**
	 * Returns the text response entity body.
	 */
	public var responseText(get_responseText, null):String;
	
	/**
	 * Returns the document response entity body.
	 */
	public var responseXML(get_responseXML, null):Document;
	
	/**
	 * Returns the response type.
	 * Can be set to change the response type. 
	 * Values are: the empty string (default), "arraybuffer", "blob", "document", "json", and "text".
	 */
	public var responseType(default, set_responseType):String;
	
	/**
	 * Returns the associated XMLHttpRequestUpload object.
	 */
	public var upload(default, null):XMLHttpRequestUpload;
	
	/**
	 * returns the HTTP status
	 */
	public var status(get_status, null):Int;
	
	/**
	 * Returns the HTTP status text.
	 */
	public var statusText(get_statusText, null):String;
	
	/**
	 * Called each time the status of the HTTP request
	 * changes
	 */
	public var onreadystatechange(default, set_onreadystatechange):Event->Void;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE ATTRIBUTES
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The interval in milliseconds between dispatching 2
	 * progress events while the XMLHttpRequest is
	 * loading a resource
	 */
	private static inline var PROGRESS_UPDATE_FREQUENCY:Int = 50;
	
	/**
	 * exposes native http capabilities of the 
	 * underlying platform 
	 */
	private var _nativeHttp:NativeHttp;
	
	/**
	 * The headers returned after an http request
	 */
	private var _responseHeaders:Map<String, String>;
	
	// states flags defined here : http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#states
	
	/**
	 * The send() flag indicates that the send() method has been invoked. 
	 * It is initially unset and is used during the OPENED state.
	 */
	private var _send:Bool;
	
	/**
	 * The error flag indicates some type of network error or request abortion.
	 * It is initially unset and is used during the DONE state.
	 */
	private var _error:Bool;
	
	// request flags, defined here : http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#request
	
	/**
	 * The HTTP method used in the request.
	 */
	private var _method:String;
	
	/**
	 * The resolved URL used in the request.
	 */
	private var _url:String;
	
	/**
	 * Set when fetching is done synchronously. Initially unset.
	 */
	private var _synchronous:Bool;
	
	/**
	 * The username used in the request or null if there is no username.
	 */
	private var _username:String;
	
	/**
	 * The password used in the request or null if there is no password.
	 */
	private var _password:String;
	
	/**
	 * A list consisting of HTTP header name/value pairs to be used in the request.
	 */
	private var _authorRequestHeaders:Map<String, String>;
	
	/**
	 * The entity body used in the request or null if there is no entity body.
	 */
	private var _requestEntityBody:Dynamic;
	
	/**
	 * Set when no more events are to be dispatched on the XMLHttpRequestUpload
	 * object. Initially unset.
	 */
	private var _uploadComplete:Bool;
	
	/**
	 * Set when event listeners are registered on the XMLHttpRequestUpload
	 * object to determine whether a preflight request is 
	 * needed. Initially unset.
	 */
	private var _uploadEvents:Bool;
	
	/**
	 * a timer used to schedule updates during network calls
	 */
	private var _timer:Timer;
	
	/**
	 * class constructor.
	 */
	public function new() 
	{	
		super();
		
		_timer = new Timer();
		_nativeHttp = new NativeHttp(_timer);
		
		
		responseType = "";
		
		//set start state
		setReadyState(HTTPConstants.UNSENT);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Sets the request method, request URL, synchronous flag, request username, and request password.
	 * 
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-open-method
	 * 
	 * TODO 2 : most of the algorithm is missing
	 */
	public function open(method:String, url:String, async:Bool = true, user:String = null, password:String = null):Void
	{
		//TODO 2 : 
		//If there is an associated XMLHttpRequest document run these substeps:
		//If the XMLHttpRequest document is not fully active, throw an "InvalidStateError" exception and terminate the overall set of steps.
		//Let XMLHttpRequest base URL be the document base URL of the XMLHttpRequest document.
		//Let XMLHttpRequest origin be the origin of the XMLHttpRequest document and let it be a globally unique identifier if the anonymous flag is set.
		
		switch (method.toUpperCase())
		{
			//valid method names
			case HTTPConstants.DELETE, HTTPConstants.GET, HTTPConstants.HEAD,
			HTTPConstants.OPTIONS, HTTPConstants.POST, HTTPConstants.PUT:
				
			//valid but unauthorized method names	
			case HTTPConstants.CONNECT, HTTPConstants.TRACE, HTTPConstants.TRACK:
				throw DOMException.SECURITY_ERR;
				return;
				
			//invalid method name	
			default:	
			throw DOMException.SYNTAX_ERR;
			return;	
		}
		
		//TODO 2 : 
		//Let url be a URL with character encoding UTF-8. 
		//Resolve url relative to the XMLHttpRequest base URL. If the algorithm returns an error, throw a "SyntaxError" exception and terminate these steps.
		//Drop <fragment> from url.
		//If the "user:password" format in the userinfo production is not supported for the relevant <scheme> and url contains this format, throw a "SyntaxError" and terminate these steps.
		//If url contains the "user:password" format let temp user be the user part and temp password be the password part.
		//If url just contains the "user" format let temp user be the user part.
		//Let async be the value of the async argument or true if it was omitted.
		//If async is false, there is an associated XMLHttpRequest document and either the timeout attribute value is not zero, the withCredentials attribute value is true, or the responseType attribute value is not the empty string, throw an "InvalidAccessError" exception and terminate these steps.
		//If the user argument was not omitted follow these sub steps:
		//If user is not null and the origin of url is not same origin with the XMLHttpRequest origin, throw an "InvalidAccessError" exception and terminate the overall set of steps.
		//Let temp user be user.	
		//If the password argument was not omitted follow these sub steps:
		//If password is not null and the origin of url is not same origin with the XMLHttpRequest origin, throw an "InvalidAccessError" exception and terminate the overall set of steps.
		//Let temp password be password.
		
		_method = method;
		_url = url;
		
		if (async == false)
		{
			_synchronous = true;
		}
		
		//TODO 2 : 
		//Set the request username to temp user.
		//Set the request password to temp password.
		
		_authorRequestHeaders = new Map<String, String>();
		_send = false;
		response = null;
		
		setReadyState(HTTPConstants.OPENED);
	}
	
	/**
	 * Initiates the request. The optional argument provides the request entity body.
	 * The argument is ignored if request method is GET or HEAD
	 * 
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-send-method
	 * 
	 * TODO 4 : only text request entity body supported for now
	 * TODO 4 : only GET method supported for now
	 */
	public function send(data:String = null):Void
	{
		if (readyState != HTTPConstants.OPENED || _send == true )
		{
			throw DOMException.INVALID_STATE_ERR;
			return;
		}
		
		var useRequestEntityBody:Bool = data != null;
		
		//TODO 2 : should be case-sensitive match for
		//GET or HEAD
		switch(_method)
		{
			case HTTPConstants.GET, HTTPConstants.HEAD:
				useRequestEntityBody = false;
		}
		
		if (useRequestEntityBody == true)
		{
			//TODO 2 :
			//Otherwise, let encoding be null, mime type be null, and then follow these rules:
			//If data is a ArrayBuffer
			//Let the request entity body be the raw data represented by data.
			//If data is a Blob
			//If the object's type attribute is not the empty string let mime type be its value.
			//Let the request entity body be the raw data represented by data.
			//If data is a Document
			//Let encoding be the preferred MIME name of the character encoding of data. If encoding is UTF-16 change it to UTF-8.
			//Let mime type be "application/xml" or "text/html" if Document is an HTML document, followed by ";charset=", followed by encoding.
			//Let the request entity body be the result of getting the innerHTML attribute on data converted to Unicode and encoded as encoding. Re-throw any exception this throws.
			//In particular, if the document cannot be serialized an "InvalidStateError" exception is thrown.
			//Subsequent changes to the Document have no effect on what is transferred.
			//If data is a string
			//Let encoding be UTF-8.	
			//Let mime type be "text/plain;charset=UTF-8".	
			//Let the request entity body be data converted to Unicode and encoded as UTF-8.
			//If data is a FormData
			//Let the request entity body be the result of running the multipart/form-data encoding algorithm with data as form data set and with UTF-8 as the explicit character encoding.
			//Let mime type be the concatenation of "multipart/form-data;", a U+0020 SPACE character, "boundary=", and the multipart/form-data boundary string generated by the multipart/form-data encoding algorithm.
			//If a Content-Type header is in author request headers and its value is a valid MIME type that has a charset parameter whose value is not a case-insensitive match for encoding, and encoding is not null, set all the charset parameters of that Content-Type header to encoding.
			//If no Content-Type header is in author request headers and mime type is not null, append a Content-Type header with value mime type to author request headers.
		}
		
		if (_synchronous == true)
		{
			//TODO 2 : If the synchronous flag is set, release the storage mutex.
		}
		else if (_registeredEventListeners != null)
		{
			_uploadEvents = true;
		}
		
		_error = false;
		
		if (useRequestEntityBody == false || data == null)
		{
			_uploadComplete = true;
		}
		
		if (_synchronous == false)
		{
			_send = true;
			//Note : The state does not change. The event is dispatched for historical reasons.
			fireReadyStateChange();
			
			var loadStart:ProgressEvent = new ProgressEvent();
			loadStart.initEvent(EventConstants.LOAD_START, false, false);
			dispatchEvent(loadStart);
			
			if (_uploadComplete == false)
			{
				var uploadLoadStart:ProgressEvent = new ProgressEvent();
				uploadLoadStart.initEvent(EventConstants.LOAD_START, false, false);
				upload.dispatchEvent(uploadLoadStart);
			}
		}
		
		_nativeHttp.load(_url, _method, data, _authorRequestHeaders, DataFormatValue.TEXT);
		onHttpProgressTick(0);
	}
	
	/**
	 * Cancels any network activity.
	 */
	public function abort():Void
	{
		
	}
	
	/**
	 * Appends an header to the list of author request headers,
	 * or if header is already in the list of author request
	 * headers, combines its value with value.
	 * 
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-setrequestheader-method
	 */
	public function setRequestHeader(header:String, value:String):Void
	{
		if (readyState != HTTPConstants.OPENED || _send == true)
		{
			throw DOMException.INVALID_STATE_ERR;
			return;
		}
		
		//TODO 2 :
		//If any code point in header is higher than U+00FF LATIN SMALL 
		//LETTER Y WITH DIAERESIS or after deflating header it does not match 
		//the field-name production, throw a "SyntaxError" exception and terminate 
		//these steps. Otherwise let header be the result of deflating header.
		//if any code point in value is higher than U+00FF LATIN SMALL LETTER Y WITH DIAERESIS
		//or after deflating value it does not match the field-value production,
		//throw a "SyntaxError" exception and terminate these steps. Otherwise
		//let value be the result of deflating value.
		
		switch (header.toLowerCase())
		{
			case HTTPConstants.ACCEPT_CHARSET, HTTPConstants.ACCEPT_ENCODING, HTTPConstants.ACCESS_CONTROL_REQUEST_HEADERS,
			HTTPConstants.ACCESS_CONTROL_REQUEST_METHOD, HTTPConstants.CONNECTION, HTTPConstants.CONTENT_LENGTH, 
			HTTPConstants.COOKIE, HTTPConstants.COOKIE_2, HTTPConstants.CONTENT_TRANSFER_ENCODING, HTTPConstants.DATE,
			HTTPConstants.EXPECT, HTTPConstants.HOST, HTTPConstants.KEEP_ALIVE, HTTPConstants.ORIGIN, HTTPConstants.REFERER,
			HTTPConstants.TE, HTTPConstants.TRAILER, HTTPConstants.TRANSFER_ENCODING, HTTPConstants.UPGRADE, HTTPConstants.USER_AGENT,
			HTTPConstants.VIA:
				return;	
		}
		
		if (header.toLowerCase().substr(0, 6) == HTTPConstants.PROXY || header.toLowerCase().substr(0, 4) == HTTPConstants.SEC)
		{
			return;
		}
		
		if (_authorRequestHeaders.exists(header) == false)
		{
			_authorRequestHeaders.set(header, value);
		}
		else
		{
			//TODO 2 : If header is in the author request headers list either use multiple headers, combine the values or use a combination of those 
			_authorRequestHeaders.set(header, value);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Monitor loading of the resource once the
	 * send method is called. Manage changes
	 * of ready state
	 */
	private function onHttpProgressTick(timeStamp:Float):Void
	{
		//always update the http status
		status = _nativeHttp.status;
		
		//if there was an error between the last call to this method and this
		//call, stop monitoring progress
		if (_error == true)
		{
			return;
		}
		
		//dispatch progress events
		makeProgressNotification();
		makeUploadProgressNotification();
		
		//first state after send method call, wait for the response headers
		if (readyState == HTTPConstants.OPENED)
		{
			//Once all HTTP headers have been received, the synchronous flag is unset, 
			//and the HTTP status code of the response is not 301, 302, 303, or 307
			//
			//TODO 2 : and the HTTP status code of the response is not 301, 302, 303, or 307
			if (_nativeHttp.responseHeadersLoaded == true && _synchronous == false)
			{
				//Switch to the HEADERS_RECEIVED state.
				_responseHeaders = _nativeHttp.responseHeaders;
				setReadyState(HTTPConstants.HEADERS_RECEIVED);
			}
		}
		//once headers are received, wait for loading start of the content
		if (readyState == HTTPConstants.HEADERS_RECEIVED)
		{
			//Once the first byte (or more) of the response entity body has been received and the synchronous flag is unset
			//or if there is no response entity body and the synchronous flag is unset
			if (_synchronous == false)
			{
				//TODO 2 : or if there is no response entity body
				if (_nativeHttp.loaded > 0)
				{
					//Switch to the LOADING state.
					setReadyState(HTTPConstants.LOADING);
				}
			}
		}
		
		//when in loading state, await the complete load of the resource
		//also check if the resource is completely loaded in case where
		//it is loaded immediately for instance if it was cached
		if (readyState == HTTPConstants.LOADING || _nativeHttp.complete == true)
		{
			//Once the whole response entity body has been received
			//Or if there is no response entity body and the state is LOADING
			//Or if there is no response entity body and the synchronous flag is set
			if (_nativeHttp.complete == true)
			//|| (_responseEntityBody == null && readyState == HTTPConstants.LOADING)
			//|| (_responseEntityBody == null && _synchronous == true))
			{
				//TODO 2 : If the synchronous flag is set, update the response entity body.
				
				_synchronous = false;
				
				//store response now that it is fully loaded
				//TODO 2 : only manage text response for now
				response = _nativeHttp.response;
				responseText = _nativeHttp.response;
				
				//Switch to the DONE state.
				setReadyState(HTTPConstants.DONE);
				
				//TODO 2 : should init with right loaded and total bytes
				var loadEvent:ProgressEvent = new ProgressEvent();
				loadEvent.initEvent(EventConstants.LOAD, false, false);
				dispatchEvent(loadEvent);
				
				var loadEndEvent:ProgressEvent = new ProgressEvent();
				loadEndEvent.initEvent(EventConstants.LOAD_END, false, false);
				dispatchEvent(loadEndEvent);

				//return to prevent scheduling a call to this
				//method now that loading is complete
				return;
			}
		}
		
		//if the resource is not done loading, schedule a method call
		_timer.delay(onHttpProgressTick, PROGRESS_UPDATE_FREQUENCY);
	}
	
	/**
	 * When it is said to make progress notifications, while the download is progressing,
	 * queue a task to fire a progress event named progress
	 * about every 50ms or for every byte received, whichever 
	 * is least frequent.
	 */
	private function makeProgressNotification():Void
	{
		var progressEvent:ProgressEvent = new ProgressEvent();
		progressEvent.initProgressEvent(EventConstants.PROGRESS, false, false, _nativeHttp.total != 0, _nativeHttp.loaded, _nativeHttp.total);
		dispatchEvent(progressEvent);
	}
	
	/**
	 * Same as above for the upload object.
	 */
	private function makeUploadProgressNotification():Void
	{
		//TODO 2 : implement
	}
	
	/**
	 * Called when there was an error while fetching the resource
	 * preventing the resource from being used
	 * 
	 * This is an implementation of the following algorithm:
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#network-error
	 * 
	 * @param	error the code of the error which triggered
	 * this method call
	 * @param	event the type of the error event to dispatch
	 */
	private function requestError(error:Int, event:String):Void
	{
		_nativeHttp.close();
		
		_error = true;
		
		readyState = HTTPConstants.DONE;
		
		if (_synchronous == true)
		{
			throw error;
			return;
		}
		
		fireReadyStateChange();
		
		if (_uploadComplete == false)
		{
			_uploadComplete = true;
			
			var errorEvent:ProgressEvent = new ProgressEvent();
			errorEvent.initEvent(event, false, false);
			
			upload.dispatchEvent(errorEvent);
			
			var loadEnd:ProgressEvent = new ProgressEvent();
			loadEnd.initEvent(EventConstants.LOAD_END, false, false);
			
			upload.dispatchEvent(loadEnd);
		}
		
		var errorEvent:ProgressEvent = new ProgressEvent();
		errorEvent.initEvent(event, false, false);
		
		dispatchEvent(errorEvent);
		
		var loadEnd:ProgressEvent = new ProgressEvent();
		loadEnd.initEvent(EventConstants.LOAD_END, false, false);
		
		dispatchEvent(loadEnd);
	}
	
	/**
	 * change the state of the object and call the
	 * readystatechange callback if provided
	 */
	private function setReadyState(value:Int):Void
	{
		readyState = value;
		fireReadyStateChange();
	}
	
	/**
	 * Utils method to dispatch a ready state
	 * change event
	 */
	private function fireReadyStateChange():Void
	{
		var readyStateChangeEvent:Event = new Event();
		readyStateChangeEvent.initEvent(EventConstants.READY_STATE_CHANGE, false, false);
		dispatchEvent(readyStateChangeEvent);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#dom-xmlhttprequest-status
	 */
	private function get_status():Int
	{
		switch(readyState)
		{
			case HTTPConstants.UNSENT, HTTPConstants.OPENED:
				return 0;
				
			default:	
		}
		
		if (_error == true)
		{
			return 0;
		}
		
		return status;
	}
	
	/**
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#dom-xmlhttprequest-statustext
	 */
	private function get_statusText():String
	{
		switch(readyState)
		{
			case HTTPConstants.UNSENT, HTTPConstants.OPENED:
				return "";
				
			default:	
		}
		
		if (_error == true)
		{
			return "";
		}
		
		return statusText;
	}
		
	/**
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-response-attribute
	 */
	private function get_response():Dynamic
	{
		if (responseType == "" && responseType == HTTPConstants.TYPE_TEXT)
		{
			switch(readyState)
			{
				case HTTPConstants.LOADING, HTTPConstants.DONE:
					
				default:
					return "";
			}
			
			if (_error == true)
			{
				return "";
			}
			
			return responseText;
		}
		else
		{
			if (readyState != HTTPConstants.DONE)
			{
				return null;
			}
			
			if (_error == true)
			{
				return null;
			}
			
			//TODO 2 :
			//If responseType is "arraybuffer"
			//Return the arraybuffer response entity body.
			//If responseType is "blob"
			//Return the blob response entity body.
			//If responseType is "document"
			//Return the document response entity body.
			//If responseType is "json"
			//Return the JSON response entity body.
			return null;
		}
	}
	
	/**
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-responsetext-attribute
	 */
	private function get_responseText():String
	{
		if (responseType != "" && responseType != HTTPConstants.TYPE_TEXT)
		{
			throw DOMException.INVALID_STATE_ERR;
			return null;
		}
		
		switch(readyState)
		{
			case HTTPConstants.LOADING, HTTPConstants.DONE:
				
			default:
				return "";
		}
		
		if (_error == true)
		{
			return "";
		}
		
		return responseText;
	}
	
	/**
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-responsexml-attribute
	 */
	private function get_responseXML():Document
	{
		if (responseType != "" && responseType != HTTPConstants.TYPE_DOCUMENT)
		{
			throw DOMException.INVALID_STATE_ERR;
			return null;
		}
		
		if (readyState != HTTPConstants.DONE)
		{
			return null;
		}
		
		if (_error == true)
		{
			return null;
		}
		
		return responseXML;
	}
	
	/**
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-responsetype-attribute
	 * 
	 * TODO 2 : check for a valid value
	 */
	private function set_responseType(value:String):String 
	{
		switch(readyState)
		{
			case HTTPConstants.LOADING, HTTPConstants.DONE:
				throw DOMException.INVALID_STATE_ERR;
				return null;
				
			default:	
		}
		
		//TODO 2 : 
		//If there is an associated XMLHttpRequest document and the synchronous
		//flag is set, throw an "InvalidAccessError" exception and terminate these steps.
		
		return responseType = value;
	}
	
	private function set_onreadystatechange(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.READY_STATE_CHANGE, value, onreadystatechange);
		return onreadystatechange = value;
	}
}
