/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domObject.js;

import cocktail.nativeReference.NativeReference;
import cocktail.domObject.base.ImageDOMObjectBase;

/**
 * This is the JavaScript implementation of the Image DOMObject.
 * 
 * @author Yannick DOMINUGEZ
 */
class ImageDOMObject extends ImageDOMObjectBase
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
	public function new(nativeReference:NativeReference = null) 
	{
		super(nativeReference);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Override to use the CSS to smooth/unsmooth the bitmap
	 * @param	value
	 * @return
	 */
	override public function setSmooth(value:Bool):Bool
	{
		super.setSmooth(value);
		
		//set the CSS influencing image quality rendering
		if (value == true)
		{
			untyped this._nativeReference.style.imageRendering = IMAGE_RENDERING_OPTIMIZE_QUALITY;
		}
		else
		{
			untyped this._nativeReference.style.imageRendering = IMAGE_RENDERING_OPTIMIZE_SPEED;
		}
		
		return value;
	}
	
}