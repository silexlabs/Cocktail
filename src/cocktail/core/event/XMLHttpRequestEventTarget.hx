/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.event;

/**
 * Base for XMLHttpRequest exposing
 * getters and setters for each event
 * dispatched by XMLHttpRequest. 
 * 
 * This class is separate from EventCallback
 * as some events defined in EventCallback
 * don't have the same signature as in this class.
 * For instance, 'onloadstart' take an Event object
 * in EventCallback and a ProgressEvent here
 * 
 * @author Yannick DOMINGUEZ
 */
class XMLHttpRequestEventTarget extends EventTarget
{
	
	/**
	 * dispatched when the request starts.
	 */
	public var onloadStart(default, set_onLoadStart):ProgressEvent->Void;

	/**
	 * dispatched while sending and loading data
	 */
	public var onprogress(default, set_onProgress):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has been aborted. For instance, by invoking the abort() method
	 */
	public var onabort(default, set_onAbort):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has failed.
	 */
	public var onerror(default, set_onError):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has successfully completed.
	 */
	public var onload(default, set_onLoad):ProgressEvent->Void;
	
	/**
	 * dispatched when the author specified timeout has passed before the request could complete.
	 */
	public var ontimeout(default, set_onTimeout):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has completed (either in success or failure).
	 */
	public var onloadend(default, set_onLoadEnd):ProgressEvent->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}

	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACK HELPER
	//////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Utils method to update the listener used by a callback
	 * 
	 * TODO 4 : this method is duplicated from EventCallBack, should create a 
	 * base class
	 */
	private function updateCallbackListener(eventType:String, newListener:Event->Void, oldListener:Event->Void):Void
	{
		//if the callback is alreay linked to an EventListener
		//remove the event listener
		if (oldListener != null)
		{
			removeEventListener(eventType, oldListener);
		}
		
		//add a new event listener if the callback is not null
		if (newListener != null)
		{
			addEventListener(eventType, newListener);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACKS SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function set_onLoadStart(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD_START, cast(value), cast(onloadStart));
		return onloadStart = value;
	}
	
	private function set_onProgress(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.PROGRESS, cast(value), cast(onprogress));
		return onprogress = value;
	}
	
	private function set_onAbort(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.ABORT, cast(value), cast(onabort));
		return onabort = value;
	}
	
	private function set_onError(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.ERROR, cast(value), cast(onerror));
		return onerror = value;
	}
	
	private function set_onLoad(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD, cast(value), cast(onload));
		return onload = value;
	}
	
	private function set_onTimeout(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.TIME_OUT, cast(value), cast(ontimeout));
		return ontimeout = value;
	}
	
	private function set_onLoadEnd(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD_END, cast(value), cast(onloadend));
		return onloadend = value;
	}
}