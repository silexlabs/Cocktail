/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.resource;

import core.dom.EventTarget;
import core.event.Event;
import haxe.Http;

/**
 * This class is a wrapper around the haxe Http class
 * using the XMLHTTPRequest API to load data as strings
 * 
 * TODO : EventTarget should be interface, this class shouldn't
 * have Element methods
 * 
 * TODO : responseHeaders not implemented in flash and JS
 * 
 * @author Yannick DOMINGUEZ
 */
class XMLHTTPRequest extends EventTarget
{
	//ready states
	
	/**
	 * The object has been constructed.
	 */
	public static inline var READY_STATE_UNSENT:Int = 0;
	
	/**
	 * The open() method has been successfully invoked. 
	 * During this state request headers can be set using 
	 * setRequestHeader() and the request can be made using the send() method.
	 */
	public static inline var READY_STATE_OPENED:Int = 1;
	
	/**
	 * All redirects (if any) have been followed and all HTTP headers
	 * of the final response have been received. 
	 * Several response members of the object are now available.
	 */
	public static inline var READY_STATE_HEADERS_RECEIVED:Int = 2;
	
	/**
	 * The response entity body is being received.
	 */
	public static inline var READY_STATE_LOADING:Int = 3;
	
	/**
	 * The data transfer has been completed or something went
	 * wrong during the transfer (e.g. infinite redirects).
	 */
	public static inline var READY_STATE_DONE:Int = 4;

	/**
	 * Returns the current state.
	 */
	private var _readyState:Int;
	public var readyState(get_readyState, never):Int;
	
	/**
	 * Returns the text response entity body.
	 */
	private var _responseText:String;
	public var responseText(get_responseText, never):String;
	
	/**
	 * returns the HTTP status
	 */
	private var _status:Int;
	public var status(get_status, never):Int;
	
	/**
	 * Called each time the status of the HTTP request
	 * changes
	 */
	public var onReadyStateChange:Event->Void;
	
	/**
	 * The haxe Http class used to abstract
	 * String loading on all  haxe targets
	 */
	private var _http:Http;
	
	/**
	 * The method of the HTTP request,
	 * GET or POST
	 */
	private var _method:String;
	
	/**
	 * class constructer. init callbacks
	 */
	public function new() 
	{
		//TODO : should not inherit any class but only implement
		//EventTarget
		super("");
		
		_http = new Http("");
		
		_http.onData = onHTTPData;
		_http.onStatus = onHTTPStatus;
		_http.onError = onHTTPError;
		setReadyState(READY_STATE_UNSENT);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Sets the request method, request URL
	 * 
	 * TODO : async in Http not implemented in flash and JS
	 * 
	 */
	public function open(method:String, url:String):Void
	{
		_http.url = url;
		_method = method;
		setReadyState(READY_STATE_OPENED);
	}
	
	/**
	 * Initiates the request. The optional argument provides the request entity body.
	 * The argument is ignored if request method is GET
	 * 
	 * TODO : POST params not supported yet
	 */
	public function send(content:String = null):Void
	{
		var post:Bool = false;
		
		//determine wrther request method is POST
		switch (_method.toUpperCase())
		{
			case "POST":
				post = true;
		}

		_http.request(post);
		
		setReadyState(READY_STATE_LOADING);
	}
	
	/**
	 * add an header to the list of request headers
	 */
	public function setRequestHeader(name:String, value:String):Void
	{
		_http.setHeader(name, value);
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
		_readyState = value;
		if (onReadyStateChange != null)
		{
			onReadyStateChange(new Event(Event.READY_STATE_CHANGE, this));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS/SETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_readyState():Int 
	{
		return _readyState;
	}
	
	private function get_status():Int
	{
		return _status;
	}
	
	private function get_responseText():String 
	{
		return _responseText;
	}
}