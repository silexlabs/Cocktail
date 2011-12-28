/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import cocktail.nativeElement.NativeElement;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.display.Loader;
import haxe.Log;
import cocktailCore.domElement.abstract.AbstractImageDOMElement;

/**
 * This is the image DOMElement implementation for Flash.
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageDOMElement extends AbstractImageDOMElement
{
	/**
	 * class constructor
	 * @param	nativeElement
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Retrieve the source url, width and
	 * height from the loaded picture
	 * @param	image
	 */
	override private function onLoadComplete(image:NativeElement):Void
	{
		var typedimage:Loader = cast(image);
		this._src = typedimage.contentLoaderInfo.url;
		this._intrinsicHeight = typedimage.contentLoaderInfo.height;
		this._intrinsicWidth = typedimage.contentLoaderInfo.width;
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
		
		super.onLoadComplete(image);
		
		//rest the scale of the loaded picture and reaffect its computed
		//dimensions to it
		typedimage.scaleX = 1;
		typedimage.scaleY = 1;
		typedimage.width = this.width;
		typedimage.height = this.height;
		
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Override to use the flash API to smooth/unsmooth bitmap
	 * @param	value
	 * @return
	 */
	override private function setSmooth(value:Bool):Bool
	{
		super.setSmooth(value);
		
		//cast the native element as a loader
		// and retrieve its bitmap content
		var typedNativeElement:Loader = cast(this._nativeElement);
		var bitmap:Bitmap = cast(typedNativeElement.content);
		
		if (bitmap != null)
		{
			//activate/deactivate picture smoothing
			bitmap.smoothing = value;
		}
		
		return value;
	}
	
}