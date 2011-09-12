/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domElement.as3;

import cocktail.nativeElement.NativeElement;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Loader;
import haxe.Log;
import cocktail.domElement.base.ImageDOMElementBase;

/**
 * This is the Image DOMElement implementation for Flash.
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageDOMElement extends ImageDOMElementBase
{

	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Override to use the flash API to smooth/unsmooth bitmap
	 * @param	value
	 * @return
	 */
	override public function setSmooth(value:Bool):Bool
	{
		super.setSmooth(value);
		
		//cast the native element as a loader
		// and retrieve its bitmap content
		var typedNativeElement:Loader = cast(this._nativeElement);
		var bitmap:Bitmap = cast(typedNativeElement.content);
		//activate/deactivate picture smoothing
		bitmap.smoothing = value;
		
		return value;
	}
	
}