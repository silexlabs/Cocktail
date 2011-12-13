/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.mouse.js;

import cocktailCore.mouse.abstract.AbstractMouse;
import cocktail.nativeElement.NativeElement;

import cocktail.mouse.MouseData;

/**
 * This is the JavaScript implementation of the mouse event manager.
 * Listens to JavaScript native mouse event on the provided
 * HTML element object.
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
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN CALLBACK SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setOnMouseDown(value:MouseEventData->Void):MouseEventData->Void
	{
		if (value == null)
		{
			_nativeElement.onmousedown = null;
		}
		else
		{
			_nativeElement.onmousedown = onNativeMouseDown;
		}
		
		return this._onMouseDown = value;
	}
	
	override private function setOnMouseUp(value:MouseEventData->Void):MouseEventData->Void
	{
		if (value == null)
		{
			_nativeElement.onmouseup = null;
		}
		else
		{
			_nativeElement.onmouseup = onNativeMouseUp;
		}
		return this._onMouseUp = value;
	}
	
	override private function setOnMouseOver(value:MouseEventData->Void):MouseEventData->Void
	{
		if (value == null)
		{
			_nativeElement.onmouseover = null;
		}
		else
		{
			_nativeElement.onmouseover = onNativeMouseOver;
		}
		return this._onMouseOver = value;
	}
	
	override private function setOnMouseOut(value:MouseEventData->Void):MouseEventData->Void
	{
		if (value == null)
		{
			_nativeElement.onmouseout = null;
		}
		else
		{
			_nativeElement.onmouseout = onNativeMouseOut;
		}
		return this._onMouseOut = value;
	}
	
	override private function setOnMouseMove(value:MouseEventData->Void):MouseEventData->Void
	{
		if (value == null)
		{
			_nativeElement.onmousemove = null;
		}
		else
		{
			_nativeElement.onmousemove = onNativeMouseMove;
		}
		return this._onMouseMove = value;
	}
	
	override private function setOnMouseDoubleClick(value:MouseEventData->Void):MouseEventData->Void
	{
		if (value == null)
		{
			_nativeElement.ondblclick = null;
		}
		else
		{
			_nativeElement.ondblclick = onNativeMouseDoubleClick;
		}
		return this._onMouseDoubleClick = value;
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
		var mousePosition:MousePositionData = {
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