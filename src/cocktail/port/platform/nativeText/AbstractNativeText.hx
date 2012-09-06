/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.nativeText;

import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.geom.GeomData;

/**
 * Wraps a native platform specific text element
 * and give access to its properties
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractNativeText 
{
	/**
	 * return the width of the text
	 */
	public var width(get_width, null):Float;
	
	/**
	 * The platform specific text element
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
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the bitmap data of the text for the
	 * given bounds
	 */
	public function getBitmap(bounds:RectangleVO):NativeBitmapData
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_width():Float
	{
		return 0.0;
	}
	
	
	
}