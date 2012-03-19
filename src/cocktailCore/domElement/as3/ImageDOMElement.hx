/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import core.nativeElement.NativeElement;
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
	 * Smooth the picture once loaded
	 * @param	image
	 */
	override private function onLoadComplete(image:NativeElement):Void
	{ 
		super.onLoadComplete(image);
		smoothPicture();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * apply a bilinear filtering to the loaded picture
	 * 
	 * TODO : should be applied during rendering
	 */
	private function smoothPicture():Void
	{
		//cast the native element as a loader
		// and retrieve its bitmap content
		var typedNativeElement:Loader = cast(this._embeddedAsset);
		var bitmap:Bitmap = cast(typedNativeElement.content);
		
		if (bitmap != null)
		{
			//activate picture smoothing
			bitmap.smoothing = true;
		}
	}
	
}