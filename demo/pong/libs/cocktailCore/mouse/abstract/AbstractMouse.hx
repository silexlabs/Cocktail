/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.mouse.abstract;

import cocktail.nativeElement.NativeElement;

import cocktail.mouse.MouseData;

/**
 * This package is made to offer a simple API for mouse interactions.
 *
 * This class is the base class for mouse interaction. It listens to 
 * mouse events thanks to runtime specific implementations and calls
 * the appropriate registered callbacks.
 * 
 * It takes a target native element objects onto which the mouse
 * event will be listened.
 * 
 * The mouse event callbacks are called with a struct containing the mouse
 * current data
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractMouse 
{
	/**
	 * The callback to call when
	 * the native element is clicked
	 */
	private var _onMouseDown:MouseEventData->Void;
	public var onMouseDown(getOnMouseDown, setOnMouseDown):MouseEventData->Void;
	
	/**
	 * The callback to call when 
	 * the native element is released
	 */
	private var _onMouseUp:MouseEventData->Void;
	public var onMouseUp(getOnMouseUp, setOnMouseUp):MouseEventData->Void;
	
	/**
	 * the callback to call when the native element
	 * is hovered
	 */
	private var _onMouseOver:MouseEventData->Void;
	public var onMouseOver(getOnMouseOver, setOnMouseOver):MouseEventData->Void;
	
	/**
	 * The callback to call when the native element
	 * is moused out
	 */
	private var _onMouseOut:MouseEventData->Void;
	public var onMouseOut(getOnMouseOut, setOnMouseOut):MouseEventData->Void;
	
	/**
	 * The callback to call when the mouse move while
	 * over the native element
	 */
	private var _onMouseMove:MouseEventData->Void;
	public var onMouseMove(getOnMouseMove, setOnMouseMove):MouseEventData->Void;
	
	/**
	 * The callback to call when the native element
	 * is double-clicked
	 */
	private var _onMouseDoubleClick:MouseEventData->Void;
	public var onMouseDoubleClick(getOnMouseDoubleClick, setOnMouseDoubleClick):MouseEventData->Void;
	
	/**
	 * The NativeElement on which mouse event are listened to
	 */
	private var _nativeElement:NativeElement;
	
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement) 
	{
		_nativeElement = nativeElement;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native mouse event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACK SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function setOnMouseDown(value:MouseEventData->Void):MouseEventData->Void
	{
		return this._onMouseDown = value;
	}
	
	private function getOnMouseDown():MouseEventData->Void
	{
		return this._onMouseDown;
	}
	
	private function setOnMouseUp(value:MouseEventData->Void):MouseEventData->Void
	{
		return this._onMouseUp = value;
	}
	
	private function getOnMouseUp():MouseEventData->Void
	{
		return this._onMouseUp;
	}
	
	private function setOnMouseOver(value:MouseEventData->Void):MouseEventData->Void
	{
		return this._onMouseOver = value;
	}
	
	private function getOnMouseOver():MouseEventData->Void
	{
		return this._onMouseOver;
	}
	
	private function setOnMouseOut(value:MouseEventData->Void):MouseEventData->Void
	{
		return this._onMouseOut = value;
	}
	
	private function getOnMouseOut():MouseEventData->Void
	{
		return this._onMouseOut;
	}
	
	private function setOnMouseMove(value:MouseEventData->Void):MouseEventData->Void
	{
		return this._onMouseMove = value;
	}
	
	private function getOnMouseMove():MouseEventData->Void
	{
		return this._onMouseMove;
	}
	
	private function setOnMouseDoubleClick(value:MouseEventData->Void):MouseEventData->Void
	{
		return this._onMouseDoubleClick = value;
	}
	
	private function getOnMouseDoubleClick():MouseEventData->Void
	{
		return this._onMouseDoubleClick;
	}
}