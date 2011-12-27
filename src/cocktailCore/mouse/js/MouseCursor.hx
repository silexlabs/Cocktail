/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.mouse.js;

import haxe.Log;
import js.Lib;
import cocktail.domElement.ImageDOMElement;
import cocktailCore.mouse.abstract.AbstractMouseCursor;
import cocktail.geom.GeomData;
import cocktail.mouse.MouseData;

/**
 * This is the JavaScript implementation of the mouse cursor
 * 
 * It exposes method to set and get the mouse cursor
 * 
 * @author Yannick DOMINGUEZ
 */
class MouseCursor extends AbstractMouseCursor
{
	/**
	 * CSS style for no mouse cursor
	 */
	private static inline var MOUSE_CURSOR_STYLE_NONE:String = "none";
	
	/**
	 * CSS style for hand with pointed finger cursor
	 */
	private static inline var MOUSE_CURSOR_STYLE_POINTER:String = "pointer";
	
	/**
	 * CSS style for i-beam
	 */
	private static inline var MOUSE_CURSOR_STYLE_TEXT:String = "text";
	
	/**
	 * CSS style for auto cursor (browser managed)
	 */
	private static inline var MOUSE_CURSOR_STYLE_AUTO:String = "auto";
	
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
	 * Set a bitmap as mouse cursor using CSS styling via JavaScript
	 */
	override private function setBitmapCursor(imageDOMElement:ImageDOMElement, hotSpot:PointData):Void
	{
		var cursorURL:String = untyped imageDOMElement.nativeElement.src;
		
		//init the hotSpot if null
		//to the top left of the cursor
		if (hotSpot == null)
		{
			hotSpot = { x:0.0, y:0.0 };
		}
		
		setCursorStyle("url(" + cursorURL + ") " + hotSpot.x +" " + hotSpot.y+", auto");
	}
	
	/**
	 * Hides the mouse cursor using CSS styling via JavaScript
	 */
	override private function hideCursor():Void
	{
		setCursorStyle(MOUSE_CURSOR_STYLE_NONE);
	}
	
	/**
	 * Set the default cursor using CSS styling via JavaScript
	 */
	override private function setDefaultCursor():Void
	{
		setCursorStyle(MOUSE_CURSOR_STYLE_AUTO);
	}
	
	/**
	 * Set an OS native cursor using CSS styling via JavaScript
	 */ 
	override private function setNativeOSCursor(value:NativeOSMouseCursorValue):Void 
	{
		switch (value)
		{
			case pointer: 
				setCursorStyle(MOUSE_CURSOR_STYLE_POINTER);
				
			case text:
				setCursorStyle(MOUSE_CURSOR_STYLE_TEXT);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private utils method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set the cursor style on the document's body
	 * @param	style the CSS formatted style
	 */
	private function setCursorStyle(style:String):Void
	{
		Lib.document.body.style.cursor = style;
	}
	
}