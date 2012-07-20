/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.nme;

import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.port.platform.nativeText.AbstractNativeText;
import cocktail.core.geom.GeomData;
import flash.display.BitmapData;
import flash.geom.Matrix;
import flash.text.TextField;

/**
 * This is the nme port of the class wrapping a native text element.
 * The native text element is a TextField object
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeText extends AbstractNativeText
{
	/**
	 * The native text element casted as a TextField
	 */
	private var _textField:TextField;
	
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement) 
	{
		super(nativeElement);
		_textField = cast(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * return the TextField bitmap data as a
	 * native flash BitmapData
	 */
	override public function getBitmap(bounds:RectangleData):NativeBitmapData
	{
		var bitmap:BitmapData = new BitmapData(Math.round(bounds.width), Math.round(bounds.height), true, 0x00000000);
		var matrix:Matrix = new Matrix();
		matrix.translate(bounds.x, 0.0);
		bitmap.draw(_nativeElement, matrix);
		
		return bitmap;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the TextField width
	 */
	override private function get_width():Float
	{
		return _textField.width;
	}
	
	
	
}