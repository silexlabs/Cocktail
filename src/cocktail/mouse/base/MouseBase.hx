/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.mouse.base;

import cocktail.nativeElement.NativeElement;

import cocktail.mouse.MouseData;

/**
 * This package is made to offer a simple API for mouse interactions.
 *
 * This class is the base class for mouse interaction. It listens to 
 * mouse events thanks to runtime specific implementations and calls
 * the appropriate registered callbacks.
 * 
 * It takes a target native reference objects onto which the mouse
 * event will be listening.
 * 
 * The mouse event callbacks are called with a struct containing the mouse
 * current data
 * 
 * @author Yannick DOMINGUEZ
 */
class MouseBase 
{
	/**
	 * The callback to call when
	 * the native reference is clicked
	 */
	public var onMouseDown:MouseEventData->Void;
	
	/**
	 * The callback to call when 
	 * the native reference is released
	 */
	public var onMouseUp:MouseEventData->Void;
	
	/**
	 * the callback to call when the native reference
	 * is hovered
	 */
	public var onMouseOver:MouseEventData->Void;
	
	/**
	 * The callback to call when the native reference
	 * is moused out
	 */
	public var onMouseOut:MouseEventData->Void;
	
	/**
	 * The callback to call when the mouse move while
	 * over the native reference
	 */
	public var onMouseMove:MouseEventData->Void;
	
	/**
	 * The callback to call when the native reference
	 * is double-clicked
	 */
	public var onMouseDoubleClick:MouseEventData->Void;
	
	/**
	 * class constructor. Set the native
	 * mouse listeners 
	 */
	public function new(nativeElement:NativeElement) 
	{
		setNativeMouseListeners(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native mouse event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the listeners for native mouse events
	 */
	private function setNativeMouseListeners(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * remove the listeners for native mouse events
	 */
	private function unsetNativeMouseListeners(nativeElement:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * Calls the onMouseDown callback with the current mouse data
	 * @param	event the native mouse down event
	 */
	private function onNativeMouseDown(event:Dynamic):Void
	{
		if (onMouseDown != null)
		{
			onMouseDown(getMouseData(event));
		}
	}
	
	/**
	 * Calls the onMouseUp callback with the current mouse data
	 * @param	event the native mouse up event
	 */
	private function onNativeMouseUp(event:Dynamic):Void
	{
		if (onMouseUp != null)
		{
			onMouseUp(getMouseData(event));
		}
	}
	
	/**
	 * Calls the onMouseOver callback with the current mouse data
	 * @param	event the native mouse over event
	 */
	private function onNativeMouseOver(event:Dynamic):Void
	{
		if (onMouseOver != null)
		{
			onMouseOver(getMouseData(event));
		}
	}
	
	/**
	 * Calls the onMouseOut callback with the current mouse data
	 * @param	event the native mouse out event
	 */
	private function onNativeMouseOut(event:Dynamic):Void
	{
		if (onMouseOut != null)
		{
			onMouseOut(getMouseData(event));
		}
	}
	
	
	/**
	 * Calls the onMouseMove callback with the current mouse data
	 * @param	event the native mouse move event
	 */
	private function onNativeMouseMove(event:Dynamic):Void
	{
		if (onMouseMove != null)
		{
			onMouseMove(getMouseData(event));
		}
	}
	
	/**
	 * Calls the onMousedoubleClick callback with the current mouse data
	 * @param	event the native mouse double-click event
	 */
	private function onNativeMouseDoubleClick(event:Dynamic):Void
	{
		if (onMouseDoubleClick != null)
		{
			onMouseDoubleClick(getMouseData(event));
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private mouse utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Returns the current mouse data
	 * @param	event the native mouse event
	 * @return a sruct containing the mouse current data
	 */
	private function getMouseData(event:Dynamic):MouseEventData
	{
		return null;
	}
}