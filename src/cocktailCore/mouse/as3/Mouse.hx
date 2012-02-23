/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.mouse.as3;

import flash.events.MouseEvent;
import cocktailCore.mouse.abstract.AbstractMouse;
import cocktail.nativeElement.NativeElement;

import cocktail.mouse.MouseData;

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
		_mouseDownEvent = MouseEvent.MOUSE_DOWN;
		_mouseUpEvent = MouseEvent.MOUSE_UP;
		_mouseOverEvent = MouseEvent.MOUSE_OVER;
		_mouseOutEvent = MouseEvent.MOUSE_OUT;
		_mouseDoubleClickEvent = MouseEvent.DOUBLE_CLICK;
		_mouseMoveEvent = MouseEvent.MOUSE_MOVE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN CALLBACK SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setOnMouseDoubleClick(value:MouseEventData->Void):MouseEventData->Void
	{
		if (value == null)
		{
			_nativeElement.doubleClickEnabled = false;
		}
		else
		{
			//In As3, a DisplayObject must be double click enabled to dispatch double click event
			_nativeElement.doubleClickEnabled = true;
		}
		
		super.setOnMouseDoubleClick(value);
		
		return this._onMouseDoubleClick = value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Actually remove and set listeners on the native flash DisplayObject. Listeners
	 * are always removed, as they must be removed if the user either removes the 
	 * listener or set a new one. Listeners are only added if the domElement callback
	 * is not null
	 */
	override private function updateListeners(mouseEvent:String, nativeCallback:Dynamic->Void, domElementCallback:MouseEventData->Void):Void
	{
		_nativeElement.removeEventListener(mouseEvent, nativeCallback);
		
		if (domElementCallback != null)
		{
			_nativeElement.addEventListener(mouseEvent, nativeCallback);
		}
	}
	
	/**
	 * Returns the current mouse data
	 * @param	event the native mouse event
	 * @return a sruct containing the mouse current data
	 */
	override private function getMouseData(event:Dynamic):MouseEventData
	{
		//cast as flash mouse event
		var typedEvent:MouseEvent = cast(event);
		
		//retrieve the position and keyboard state
		//from flash event
		var mousePosition:MousePositionData = {
			localX:typedEvent.localX,
			localY:typedEvent.localY,
			globalX:typedEvent.stageX,
			globalY:typedEvent.stageY
		}
		
		var mouseEventData:MouseEventData = {
			mousePosition:mousePosition,
			altKey:typedEvent.altKey,
			ctrlKey:typedEvent.ctrlKey,
			shiftKey:typedEvent.shiftKey
		}
		
		return mouseEventData;
	}
}