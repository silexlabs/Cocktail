/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.mouse.as3;

import flash.display.BitmapData;
import flash.ui.MouseCursorData;
import flash.ui.Mouse;
import flash.Vector;
import cocktail.domElement.ImageDOMElement;
import cocktailCore.mouse.abstract.AbstractMouseCursor;
import cocktail.geom.GeomData;
import cocktail.mouse.MouseData;

/**
 * This is the flash AVM2 implementation of the mouse cursor
 * 
 * It exposes method to set and get the mouse cursor
 * 
 * @author Yannick DOMINGUEZ
 */
class MouseCursor extends AbstractMouseCursor
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private mouse cursor methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set a bitmap as mouse cursor using flash mouse API
	 */
	override private function setBitmapCursor(imageDOMElement:ImageDOMElement, hotSpot:PointData):Void
	{
		//init the hotSpot if null
		//to the top left of the cursor
		if (hotSpot == null)
		{
			hotSpot = { x:0.0, y:0.0 };
		}
		
		//draw the image dom element onto a 32x32 transparent bitmap data
		var mouseCursorBitmapData:BitmapData = new BitmapData(32, 32, true, 0x00FFFFFF);
		mouseCursorBitmapData.draw(imageDOMElement.nativeElement);
		
		//set the flash mouse cursor data with the drawn bitmap data
		//and the cursor hot spot
		var mouseCursorData:MouseCursorData = new MouseCursorData();
		mouseCursorData.data = new Vector<BitmapData>(1, true);
		mouseCursorData.data[0] = mouseCursorBitmapData;
		mouseCursorData.hotSpot = new flash.geom.Point(hotSpot.x, hotSpot.y);
		
		//generate a random ID for the new cursor
		var randomID:String = Std.string(Math.round(Math.random() * 1000));
		
		
		
		//register the cursor and set it
		Mouse.registerCursor(randomID, mouseCursorData);
		Mouse.cursor = randomID;
		
		//show the cursor if it was previously hidden
		Mouse.show();
	}
	
	/**
	 * Hides the mouse cursor using flash mouse API
	 */
	override private function hideCursor():Void
	{
		Mouse.hide();
	}
	
	/**
	 * Set the default cursor using flash mouse API
	 */
	override private function setDefaultCursor():Void
	{
		//show the cursor if it was previously hidden
		Mouse.show();
		Mouse.cursor = flash.ui.MouseCursor.AUTO;
	}
	
	/**
	 * Set an OS native cursor using flash mouse API
	 */ 
	override private function setNativeOSCursor(value:NativeOSMouseCursorValue):Void 
	{
		//show the cursor if it was previously hidden
		Mouse.show();
		
		switch value
		{
			case pointer:
				Mouse.cursor = flash.ui.MouseCursor.BUTTON;
				
			case text:
				Mouse.cursor = flash.ui.MouseCursor.IBEAM;
		}
	}
	
}