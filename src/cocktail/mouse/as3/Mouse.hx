/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.mouse.as3;

import flash.events.MouseEvent;
import cocktail.mouse.base.MouseBase;
import cocktail.nativeReference.NativeReference;

import cocktail.mouse.MouseData;

/**
 * This is the flash AVM2 implementation of the mouse event manager.
 * Listens to flash native mouse event on the provided
 * flash display object.
 * 
 * @author Yannick DOMINGUEZ
 */
class Mouse extends MouseBase
{
	
	/**
	 * class constructor.
	 */
	public function new(nativeReference:NativeReference) 
	{
		super(nativeReference);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Overriden private native mouse event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the listeners for native flash mouse events
	 */
	override private function setNativeMouseListeners(nativeReference:NativeReference):Void
	{
		nativeReference.addEventListener(MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		nativeReference.addEventListener(MouseEvent.MOUSE_UP, onNativeMouseUp);
		nativeReference.addEventListener(MouseEvent.ROLL_OVER, onNativeMouseOver);
		nativeReference.addEventListener(MouseEvent.ROLL_OUT, onNativeMouseOut);
		nativeReference.addEventListener(MouseEvent.MOUSE_MOVE, onNativeMouseMove);
		
		//In As3, a DisplayObject must be double click enabled to dispatch double click event
		nativeReference.doubleClickEnabled = true;
		nativeReference.addEventListener(MouseEvent.DOUBLE_CLICK, onNativeMouseDoubleClick);
	}
	
	/**
	 * remove the listeners for native flash mouse events
	 */
	override private function unsetNativeMouseListeners(nativeReference:NativeReference):Void
	{
		nativeReference.removeEventListener(MouseEvent.MOUSE_DOWN, onNativeMouseDown);
		nativeReference.removeEventListener(MouseEvent.MOUSE_UP, onNativeMouseUp);
		nativeReference.removeEventListener(MouseEvent.ROLL_OVER, onNativeMouseOver);
		nativeReference.removeEventListener(MouseEvent.ROLL_OUT, onNativeMouseOut);
		nativeReference.removeEventListener(MouseEvent.MOUSE_MOVE, onNativeMouseMove);
		nativeReference.removeEventListener(MouseEvent.DOUBLE_CLICK, onNativeMouseDoubleClick);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
		var mousePosition:MousePosition = {
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