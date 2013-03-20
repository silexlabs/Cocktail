/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.http;

/**
 * Lists constants for the http (XMLHTTPRequest)
 * API
 * 
 * @author Yannick DOMINGUEZ
 */
class HTTPConstants 
{

	//states
	
	/**
	 * The object has been constructed.
	 */
	public static inline var UNSENT:Int = 0;
	
	/**
	 * The open() method has been successfully invoked. 
	 * During this state request headers can be set using 
	 * setRequestHeader() and the request can be made using the send() method.
	 */
	public static inline var OPENED:Int = 1;
	
	/**
	 * All redirects (if any) have been followed and all HTTP headers
	 * of the final response have been received. 
	 * Several response members of the object are now available.
	 */
	public static inline var HEADERS_RECEIVED:Int = 2;
	
	/**
	 * The response entity body is being received.
	 */
	public static inline var LOADING:Int = 3;
	
	/**
	 * The data transfer has been completed or something went
	 * wrong during the transfer (e.g. infinite redirects).
	 */
	public static inline var DONE:Int = 4;
	
	// http methods
	
	public static inline var CONNECT:String = "CONNECT";
	
	public static inline var DELETE:String = "DELETE";
	
	public static inline var GET:String = "GET";
	
	public static inline var HEAD:String = "HEAD";
	
	public static inline var OPTIONS:String = "OPTIONS";
	
	public static inline var POST:String = "POST";
	
	public static inline var PUT:String = "PUT";
	
	public static inline var TRACE:String = "TRACE";
	
	public static inline var TRACK:String = "TRACK";
	
	public static inline var FORM_SUBMIT_METHODS:Array<String> = [GET, POST];
	
	//encodings
	
	public static inline var URL_ENCODING:String = "application/x-www-form-urlencoded";
	
	public static inline var FORM_DATA:String = "multipart/form-data";
	
	public static inline var PLAIN_TEXT:String = "text/plain";
	
	public static inline var FORM_ENCODINGS:Array<String> = [URL_ENCODING, FORM_DATA, PLAIN_TEXT];
	
	// schemes
	
	public static inline var HTTP:String = "http";
	
	public static inline var HTTPS:String = "https";
	
	// http response type
	
	public static inline var TYPE_TEXT:String = "text";
	
	public static inline var TYPE_ARRAY_BUFFER:String = "arraybuffer";
	
	public static inline var TYPE_BLOB:String = "blob";
	
	public static inline var TYPE_DOCUMENT:String = "document";
	
	public static inline var TYPE_JSON:String = "json";
	
	// user-agent http headers
	
	public static inline var ACCEPT_CHARSET:String = "accept-charset";
	
	public static inline var ACCEPT_ENCODING:String = "accept-encoding";
	
	public static inline var ACCESS_CONTROL_REQUEST_HEADERS:String = "access-control-request-headers";
	
	public static inline var ACCESS_CONTROL_REQUEST_METHOD:String = "access-control-request-method";
	
	public static inline var CONNECTION:String = "connection";
	
	public static inline var CONTENT_LENGTH:String = "content-length";
	
	public static inline var COOKIE:String = "cookie";
	
	public static inline var COOKIE_2:String = "cookie2";
	
	public static inline var CONTENT_TRANSFER_ENCODING:String = "content-transfer-encoding";
	
	public static inline var DATE:String = "date";
	
	public static inline var EXPECT:String = "expect";
	
	public static inline var HOST:String = "host";
	
	public static inline var KEEP_ALIVE:String = "keep-alive";
	
	public static inline var ORIGIN:String = "origin";
	
	public static inline var REFERER:String = "referer";
	
	public static inline var TE:String = "te";
	
	public static inline var TRAILER:String = "trailer";
	
	public static inline var TRANSFER_ENCODING:String = "transfer-encoding";
	
	public static inline var UPGRADE:String = "upgrade";
	
	public static inline var USER_AGENT:String = "user-agent";
	
	public static inline var VIA:String = "via";
	
	// http header const
	
	public static inline var PROXY:String = "proxy-";
	
	public static inline var SEC:String = "sec-";
	
	private function new() 
	{
		
	}
	
}