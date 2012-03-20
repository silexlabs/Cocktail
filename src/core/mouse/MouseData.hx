/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.mouse;

import core.dom.HTMLImageElement;
import core.geom.GeomData;

/**
 * This file contains mouse related structures
 * and enums
 */

/**
 * Lists the different cursors which can
 * be set for the mouse pointer
 */
enum MouseCursorValue {
	/**
	 * uses a custom bitmap cursor set with
	 * an image dom element. The hotSpot is the registration
	 * point of the cursor.
	 */
	custom(htmlImageElement:HTMLImageElement, hotSpot:PointData);
	
	/**
	 * Let the browser manage the mouse cursor
	 */
	autoValue;
	
	/**
	 * Hides the mouse cursor
	 */
	none;
	
	/**
	 * Use a native OS mouse cursor
	 */
	native(nativeOSMouseCursorValue:NativeOSMouseCursorValue);
}

/**
 * Lists all the available native
 * OS mouse cursor
 */
enum NativeOSMouseCursorValue {
	
	/**
	 * represents a pointed hand
	 */
	pointer;
	
	/**
	 * represents an i-beam
	 */
	text;
}