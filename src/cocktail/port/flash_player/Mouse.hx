/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.event.MouseEvent;
import cocktail.core.html.HTMLElement;
import cocktail.core.mouse.AbstractMouse;
import cocktail.core.NativeElement;

import cocktail.core.mouse.MouseData;

/**
 * This is the flash AVM2 implementation of the mouse event manager.
 * Listens to flash native mouse event on the provided
 * flash display object.
 * 
 * @author Yannick DOMINGUEZ
 */
class Mouse extends AbstractMouse
{
	
	/**
	 * class constructor.
	 */
	public function new(nativeElement:NativeElement) 
	{
		super(nativeElement);
		
		//set the Flash event types
		_clickEvent = flash.events.MouseEvent.CLICK;
		_mouseDownEvent = flash.events.MouseEvent.MOUSE_DOWN;
		_mouseUpEvent = flash.events.MouseEvent.MOUSE_UP;
		_mouseOverEvent = flash.events.MouseEvent.MOUSE_OVER;
		_mouseOutEvent = flash.events.MouseEvent.MOUSE_OUT;
		_mouseMoveEvent = flash.events.MouseEvent.MOUSE_MOVE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually remove and set listeners on the native flash DisplayObject. Listeners
	 * are always removed, as they must be removed if the user either removes the 
	 * listener or set a new one. Listeners are only added if the htmlElement callback
	 * is not null
	 */
	override private function updateListeners(mouseEvent:String, nativeCallback:Dynamic->Void, htmlElementCallback:MouseEvent->Void):Void
	{
		_nativeElement.removeEventListener(mouseEvent, nativeCallback);
		
		if (htmlElementCallback != null)
		{
			_nativeElement.addEventListener(mouseEvent, nativeCallback);
		}
	}
	
	/**
	 * Returns the current mouse data
	 * @param	event the native mouse event
	 * @return a sruct containing the mouse current data
	 */
	override private function getMouseEvent(event:Dynamic):MouseEvent
	{
		//cast as flash mouse event
		var typedEvent:flash.events.MouseEvent = cast(event);
		
		var eventType:String;
		
		switch (typedEvent.type)
		{
			case flash.events.MouseEvent.CLICK:
				eventType = MouseEvent.CLICK;
			
			case flash.events.MouseEvent.MOUSE_DOWN:
				eventType = MouseEvent.MOUSE_DOWN;
				
			case flash.events.MouseEvent.MOUSE_UP:
				eventType = MouseEvent.MOUSE_UP;	
				
			case flash.events.MouseEvent.MOUSE_OVER:
				eventType = MouseEvent.MOUSE_OVER;
				
			case flash.events.MouseEvent.MOUSE_OUT:
				eventType = MouseEvent.MOUSE_OUT;	
				
			case flash.events.MouseEvent.MOUSE_MOVE:
				eventType = MouseEvent.MOUSE_MOVE;	
				
			default:
				eventType = typedEvent.type;	
		}
		
		//TODO : the target is now null, should be determined by HTMLDocument
		var mouseEvent:MouseEvent = new MouseEvent(eventType, null, 0.0, typedEvent.stageX, typedEvent.stageY,
		typedEvent.localX, typedEvent.localY, typedEvent.ctrlKey, typedEvent.shiftKey, typedEvent.altKey);
		
		return mouseEvent;
	}
}