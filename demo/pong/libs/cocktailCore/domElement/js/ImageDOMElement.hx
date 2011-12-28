/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.js;

import cocktail.nativeElement.NativeElement;
import cocktailCore.domElement.abstract.AbstractImageDOMElement;
import haxe.Log;

/**
 * This is the JavaScript implementation of the Image DOMElement.
 * 
 * @author Yannick DOMINUGEZ
 */
class ImageDOMElement extends AbstractImageDOMElement
{

	/**
	 * This value smooth the bitmap
	 */
	private static inline var IMAGE_RENDERING_OPTIMIZE_QUALITY = "optimizeQuality";
	
	/**
	 * This value doesn't smooth the bitmap
	 */
	private static inline var IMAGE_RENDERING_OPTIMIZE_SPEED = "optimizeSpeed";
	
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Retrive the source url, width and
	 * height from the loaded picture
	 * @param	image
	 */
	override private function onLoadComplete(image:NativeElement):Void
	{	
		this._src = untyped image.src;
		this._intrinsicHeight = untyped image.naturalHeight;
		this._intrinsicWidth = untyped image.naturalWidth;
		this._intrinsicRatio = this._intrinsicWidth / this._intrinsicHeight;
		
		super.onLoadComplete(image);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Override to use the CSS to smooth/unsmooth the bitmap
	 * @param	value
	 * @return
	 */
	override private function setSmooth(value:Bool):Bool
	{
		super.setSmooth(value);
		
		//set the CSS influencing image quality rendering
		if (value == true)
		{
			untyped this._nativeElement.style.imageRendering = IMAGE_RENDERING_OPTIMIZE_QUALITY;
		}
		else
		{
			untyped this._nativeElement.style.imageRendering = IMAGE_RENDERING_OPTIMIZE_SPEED;
		}
		
		return value;
	}
	
}