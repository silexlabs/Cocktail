/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.mouse;


//import the right runtime implementations
#if (flash9 || cpp || nme)
import cocktailCore.mouse.as3.MouseCursor;

#elseif js
import cocktailCore.mouse.js.MouseCursor;

#elseif doc
class MouseCursor extends cocktailCore.mouse.abstract.AbstractMouseCursor { }

#end

import cocktail.mouse.MouseData;

/**
 * This class manages the mouse cursor display.
 * The skin of the mouse cursor can be set with a custom
 * bitmap or a native OS mouse cursor.
 * 
 * If the cursor is set to a custom bitmap, its dimensions
 * should be at most 32x32, else it will be cropped
 * 
 * @author Yannick DOMINGUEZ
 */
class MouseCursorManager 
{
	/**
	 * This class is implemented for each runtime
	 * and actually manage the mouse cursor in
	 * a native runtime
	 */
	private static var _mouseCursor:MouseCursor;
	
	/**
	 * class constructor. Private as this class is
	 * meant to be manipulated through its static
	 * methods
	 */
	private function new() 
	{
		
	}
	
	/**
	 * Set the display of the mouse cursor with the provided setting
	 * @param	mouseCursorValue the requested mouse cursor, can be a custom
	 * bitmap cursor or a pre-determined OS cursor
	 */
	public static function setMouseCursor(mouseCursorValue:MouseCursorValue):Void
	{
		if (_mouseCursor == null)
		{
			_mouseCursor = new MouseCursor();
		}
		
		_mouseCursor.nativeMouseCursor = mouseCursorValue;
	}
	
	/**
	 * Return the value of the current 
	 * mouse cursor
	 */
	public static function getMousecursor():MouseCursorValue
	{
		if (_mouseCursor == null)
		{
			_mouseCursor = new MouseCursor();
		}
		
		return _mouseCursor.nativeMouseCursor;
	}
	
}