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
	
	private function new() 
	{
		
	}
	
}