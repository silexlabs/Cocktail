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
	 * The callback called on mouse click (rapid mouse down and mouse up)
	 */
	public var onloadStart(default, set_onLoadStart):MouseEvent->Void;

	public function new() 
	{
		
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
	
	private function set_onLoadStart(value:Event->Void):Event->Void
	{
		updateCallbackListener(Event.LOAD_START, value, onvolumechange);
		return onvolumechange = value;
	}
}