/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.event;

import cocktail.event.*;

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
	public var onloadstart(default, set_onloadstart):ProgressEvent->Void;

	/**
	 * dispatched while sending and loading data
	 */
	public var onprogress(default, set_onprogress):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has been aborted. For instance, by invoking the abort() method
	 */
	public var onabort(default, set_onabort):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has failed.
	 */
	public var onerror(default, set_onerror):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has successfully completed.
	 */
	public var onload(default, set_onload):ProgressEvent->Void;
	
	/**
	 * dispatched when the author specified timeout has passed before the request could complete.
	 */
	public var ontimeout(default, set_ontimeout):ProgressEvent->Void;
	
	/**
	 * dispatched when the request has completed (either in success or failure).
	 */
	public var onloadend(default, set_onloadend):ProgressEvent->Void;
	
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
	private function updateCallbackListener(eventType:String, newListener:Dynamic->Void, oldListener:Dynamic->Void):Void
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
	
	private function set_onloadstart(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD_START, value, onloadstart);
		return onloadstart = value;
	}
	
	private function set_onprogress(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.PROGRESS, value, onprogress);
		return onprogress = value;
	}
	
	private function set_onabort(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.ABORT, value, onabort);
		return onabort = value;
	}
	
	private function set_onerror(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.ERROR, value, onerror);
		return onerror = value;
	}
	
	private function set_onload(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD, value, onload);
		return onload = value;
	}
	
	private function set_ontimeout(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.TIME_OUT, value, ontimeout);
		return ontimeout = value;
	}
	
	private function set_onloadend(value:ProgressEvent->Void):ProgressEvent->Void
	{
		updateCallbackListener(EventConstants.LOAD_END, value, onloadend);
		return onloadend = value;
	}
}
