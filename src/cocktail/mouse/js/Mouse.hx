/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.mouse.js;

import cocktail.mouse.base.MouseBase;
import cocktail.nativeReference.NativeReference;

import cocktail.mouse.MouseData;

/**
 * This is the JavaScript implementation of the mouse event manager.
 * Listens to JavaScript native mouse event on the provided
 * HTML element object.
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
	 * Set the listeners for native JavaScript mouse events
	 */
	override private function setNativeMouseListeners(nativeReference:NativeReference):Void
	{
		nativeReference.onmousedown = onNativeMouseDown;
		nativeReference.onmouseup = onNativeMouseUp;
		nativeReference.onmouseover = onNativeMouseOver;
		nativeReference.onmouseout = onNativeMouseOut;
		nativeReference.onmousemove = onNativeMouseMove;
		nativeReference.ondblclick = onNativeMouseDoubleClick;
	}
	
	/**
	 * remove the listeners for native JavaScript mouse events
	 */
	override private function unsetNativeMouseListeners(nativeReference:NativeReference):Void
	{
		nativeReference.onmousedown = null;
		nativeReference.onmouseup = null;
		nativeReference.onmouseover = null;
		nativeReference.onmouseout = null;
		nativeReference.onmousemove = null;
		nativeReference.ondblclick = null;
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
		
		//retrieve the position and keyboard state
		//from JavaScript event
		var mousePosition:MousePosition = {
			localX:event.clientX,
			localY:event.clientY,
			globalX:event.screenX,
			globalY:event.screenY
		}
		
		var mouseEventData:MouseEventData = {
			mousePosition:mousePosition,
			altKey:event.altKey,
			ctrlKey:event.ctrlKey,
			shiftKey:event.shiftKey
		}
		
		return mouseEventData;
	}
}