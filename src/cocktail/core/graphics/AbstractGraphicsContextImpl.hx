/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.graphics;

import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.core.dom.NodeBase;
import cocktail.core.geom.GeomData;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;


/**
 * This is the base class for classes which 
 * actually implement the platform specific
 * API calls to drw and build the native display
 * list ofthe target platform.
 * 
 * It is implemented for each graphic target platform
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractGraphicsContextImpl
{
	/**
	 * A reference to a native layer
	 */
	public var nativeLayer(get_nativeLayer, null):NativeElement;
	
	/**
	 * A reference to a native bitmap data object of the 
	 * underlying platform
	 */
	public var nativeBitmapData(get_nativeBitmapData, null):NativeBitmapData;
	
	/**
	 * A flag determining wether to use the specified alpha when drawing
	 * bitmap
	 */
	private var _useTransparency:Bool;
	
	/**
	 * The current used alpha when transparency is activated,
	 * as defined by the _useTransparency flag
	 */
	private var _alpha:Float;

	/**
	 * class constructor
	 * 
	 * @param isInitialGraphicContext wether this
	 * graphic context implementation is created by
	 * the root graphic context and should represent
	 * the root of the native display list
	 */
	public function new(isInitialGraphicContext:Bool)
	{
		_useTransparency = false;
		_alpha = 0.0;
	}
	
	/**
	 * Init the bitmap data with a given size
	 */
	public function initBitmapData(width:Int, height:Int):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function attach(parentNativeLayer:NativeElement):Void
	{
		//abstract
	}
	
	public function detach(parentNativeLayer:NativeElement):Void
	{
		//abstract
	}
	
	/**
	 * clean-up method, free memory used
	 * by graphics context
	 */
	public function dispose():Void
	{
		//abstract
	}
	
	/**
	 * Apply a transformation matrix to the layer
	 */
	public function transform(matrix:Matrix):Void
	{
		//abstract
	}
	
	/**
	 * Clears the bitmap data
	 */
	public function clear():Void
	{
		//abstract
	}
	
	/**
	 * When called, all subsequent calls to bitmap
	 * drawing methods draw transparent bitmap with
	 * the provided alpha, until endTransparency is called
	 */
	public function beginTransparency(alpha:Float):Void
	{
		_useTransparency = true;
		_alpha = alpha;
	}
	
	/**
	 * End the use of transparency when drawing 
	 * bitmaps
	 */
	public function endTransparency():Void
	{
		_useTransparency = false;
	}
	
	/**
	 * Draw bitmap data onto the bitmap surface. Alpha is preserved 
	 * for transparent bitmap
	 * @param	bitmapData the source  bitmap data
	 * @param	matrix a transformation matrix to apply yo the bitmap data when drawing to 
	 * to the bitmap. Defaults to an identity matrix
	 * @param	sourceRect defines the zone from the source bitmap data that must be copied onto the 
	 * native graphic dom element. Takes the whole bitmap data by default
	 */
	public function drawImage(bitmapData:NativeBitmapData, matrix:Matrix = null, sourceRect:RectangleVO = null):Void
	{
		//abstract
	}
	
	/**
	 * fast pixel manipulation method used when no transformation is applied to the image
	 * @param	bitmapData the pixels to copy
	 * @param	sourceRect the area of the source bitmap data to use
	 * @param	destPoint the upper left corner of the rectangular aeaa where the new
	 * pixels are placed
	 */
	public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleVO, destPoint:PointVO):Void
	{
		//abstract
	}
	
	/**
	 * Fill a rect with the specified color
	 * @param rect the rectangle to fill
	 * @param color the rectangle's color
	 */
	public function fillRect(rect:RectangleVO, color:ColorVO):Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_nativeBitmapData():NativeBitmapData
	{
		return null;
	}
	
	private function get_nativeLayer():NativeElement
	{
		return null;
	}
	
}