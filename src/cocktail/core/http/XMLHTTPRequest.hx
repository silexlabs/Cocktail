/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.http;

import cocktail.core.dom.Document;
import cocktail.core.dom.DOMException;
import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.EventTarget;
import cocktail.core.event.XMLHttpRequestEventTarget;
import haxe.Http;

/**
 * This class is a wrapper around the haxe Http class
 * using the XMLHTTPRequest API to load data as strings
 * 
 * TODO 5 : responseHeaders not implemented in flash and JS
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
	 * returns the HTTP status
	 */
	public var status(get_status, null):Int;
	
	/**
	 * Returns the HTTP status text.
	 */
	public var statusText(get_statusText, null):String 
	
	/**
	 * Called each time the status of the HTTP request
	 * changes
	 */
	public var onreadystatechange(default, set_onReadyStateChange):Event->Void;
	
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
	private var _authorRequestHeaders:Hash<String>;
	
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
	 * class constructer.
	 */
	public function new() 
	{	
		super();
		
		//set start state
		setReadyState(READY_STATE_UNSENT);
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
	public function open(method:String, url:String, async:Bool = false, user:String = null, password:String = null):Void
	{
		//TODO 2 : 
		//If there is an associated XMLHttpRequest document run these substeps:
		//If the XMLHttpRequest document is not fully active, throw an "InvalidStateError" exception and terminate the overall set of steps.
		//Let XMLHttpRequest base URL be the document base URL of the XMLHttpRequest document.
		//Let XMLHttpRequest origin be the origin of the XMLHttpRequest document and let it be a globally unique identifier if the anonymous flag is set.
		
		switch (method.toLowerCase())
		{
			//valid method names
			case HTTPConstants.DELETE, HTTPConstants.GET, HTTPConstants.HEAD,
			HTTPConstants.OPTIONS, HTTPConstants.POST, HTTPConstants.PUT:
				
			//valid but unauthorized method names	
			case HTTPConstants.CONNECT, HTTPConstants.TRACE, HTTPConstants.TRACK:
				throw DOMException.SECUTITY_ERROR;
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
		
		_authorRequestHeaders = new Hash<String>();
		_send = false;
		response = null;
		
		setReadyState(READY_STATE_OPENED);
	}
	
	/**
	 * Initiates the request. The optional argument provides the request entity body.
	 * The argument is ignored if request method is GET or HEAD
	 * 
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-send-method
	 * 
	 * TODO 4 :only text request entity body supported for now
	 */
	public function send(content:String = null):Void
	{
		var post:Bool = false;
		
		//determine wether request method is POST
		switch (_method.toUpperCase())
		{
			case "POST":
				post = true;
		}

		_http.request(post);
		
		setReadyState(READY_STATE_LOADING);
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
	 * called when HTTP Status are received
	 */
	private function onHTTPStatus(status:Int):Void
	{
		_status = status;
	}
	
	/**
	 * Called when request was succesffuly returned
	 */
	private function onHTTPData(data:String):Void
	{
		_responseText = data;
		setReadyState(READY_STATE_DONE);
	}
	
	/**
	 * Called when there was an error during request
	 */
	private function onHTTPError(data:String):Void
	{
		_responseText = data;
		setReadyState(READY_STATE_DONE);
	}
	
	/**
	 * change the state of the object and call the
	 * readystatechange callback if provided
	 */
	private function setReadyState(value:Int):Void
	{
		readyState = value;
		if (onReadyStateChange != null)
		{
			var readyStateChangeEvent:Event = new Event();
			readyStateChangeEvent.initEvent(EventConstants.READY_STATE_CHANGE, false, false);
			dispatchEvent(readyStateChangeEvent);
		}
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
				return 0;
				
			default:	
		}
		
		if (_error == true)
		{
			return 0;
		}
		
		return statusText;
	}
		
	/**
	 * This is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-XMLHttpRequest-20120117/#the-response-attribute
	 */
	private function get_response():Dynamic
	{
		if (responseType == "" || responseType == HTTPConstants.TYPE_TEXT)
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
		if (responseType != "" || responseType != HTTPConstants.TYPE_TEXT)
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
		if (responseType != "" || responseType != HTTPConstants.TYPE_DOCUMENT)
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
	private var set_responseType(value:String):String 
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
	
	private function set_onReadyStateChange(value:Event->Void):Event->Void
	{
		updateCallbackListener(EventConstants.READY_STATE_CHANGE, value, onreadystatechange);
		return onreadystatechange = value;
	}
}