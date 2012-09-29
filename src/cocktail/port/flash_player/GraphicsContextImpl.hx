/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.geom.Matrix;
import cocktail.core.graphics.AbstractGraphicsContextImpl;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.layer.LayerRenderer;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import cocktail.port.NativeLayer;
import flash.display.Bitmap;
import cocktail.core.geom.GeomData;
import cocktail.core.css.CSSData;
import flash.display.BitmapData;
import flash.display.PixelSnapping;
import flash.display.Sprite;
import flash.geom.ColorTransform;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.Lib;


/**
 * The flash implementation of the graphics context. Use native
 * flash Sprite and Bitmap
 * 
 * @author Yannick DOMINGUEZ
 */
class GraphicsContextImpl extends AbstractGraphicsContextImpl
{
	/**
	 * The native flash BitmapData
	 */
	private var _nativeBitmap:Bitmap;
	
	/**
	 * The native flash Sprite, used a native
	 * layer
	 */
	private var _nativeLayer:Sprite;
	
	/**
	 * A container for the children layer of
	 * this GraphicContext. A container is necessary
	 * so that tha native Bitmap is always below the children
	 * layer
	 */
	private var _childrenNativeLayer:Sprite;
	
	/**
	 * the current width of the BitmapData
	 */
	private var _width:Int;
	
	/**
	 * the current height of the BitmapData
	 */
	private var _height:Int;
	
	/**
	 * A flash native rectanlge object, which
	 * is re-used for each bitmap drawing
	 */
	private var _flashRectangle:Rectangle;
	
	/**
	 * Same as above for flash native point
	 */
	private var _flashPoint:Point;
	
	/**
	 * Same as above for flash Matrix
	 */
	private var _flashMatrix:flash.geom.Matrix;
	
	/**
	 * A reuseable rectangle used for fillRect rectangle
	 */
	private var _fillRectRectangle:RectangleVO;
	
	/**
	 * A reuseable point used for fillRect rectangle
	 */
	private var _fillRectPoint:PointVO;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		_nativeLayer = new Sprite();
		
		
		_childrenNativeLayer = new Sprite();
		
		_nativeBitmap = new Bitmap(new BitmapData(1, 1, true, 0x00000000), PixelSnapping.AUTO, true);
		_flashRectangle = new Rectangle();
		_flashPoint = new Point();
		_flashMatrix = new flash.geom.Matrix();
		_fillRectRectangle = new RectangleVO(0.0, 0.0, 0.0, 0.0);
		_fillRectPoint = new PointVO(0.0, 0.0);
		_width = 0;
		_height = 0;
		
		
		//build native display list
		_childrenNativeLayer.addChild(_nativeBitmap);
		_childrenNativeLayer.addChild(_nativeLayer);
		
	}
	
	/**
	 * Create new BitmapData when the size of the window changes
	 */
	override public function initBitmapData(width:Int, height:Int):Void
	{
		_width = width;
		_height = height;
		
		_nativeBitmap.bitmapData.dispose();
		_nativeBitmap.bitmapData = new BitmapData(width, height, true, 0x00000000);
	}
	
	/**
	 * clear the BitmapData by filling it with
	 * transparent black
	 */
	override public function clear():Void
	{
		_flashRectangle.x = 0;
		_flashRectangle.y = 0;
		_flashRectangle.width = _width;
		_flashRectangle.height = _height;
		_nativeBitmap.bitmapData.fillRect(_flashRectangle, 0x00000000);
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * clean-up flash native objects
	 */
	override public function dispose():Void
	{
		_nativeBitmap.bitmapData.dispose();
		_childrenNativeLayer.removeChild(_nativeBitmap);
		_nativeBitmap = null;
		_childrenNativeLayer.removeChild(_nativeLayer);
		_nativeLayer = null;
		_childrenNativeLayer = null;
	}
	
	/**
	 * Apply a native flash trnasformation matrix to the 
	 * native layer Sprite
	 */
	override public function transform(matrix:Matrix):Void
	{
		var matrixData:MatrixData = matrix.data;
		_childrenNativeLayer.transform.matrix = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
	}
	
	override public function attach(graphicsContext:GraphicsContext):Void
	{
		graphicsContext.parentNode.nativeLayer.addChild(_childrenNativeLayer);
	}
	
	override public function detach(graphicsContext:GraphicsContext):Void
	{
		if (_childrenNativeLayer.parent != null)
		{
			graphicsContext.parentNode.nativeLayer.removeChild(_childrenNativeLayer);
		}
	}
	
	override public function attachToRoot():Void
	{
		Lib.current.addChild(_childrenNativeLayer);
	}
	
	override public function detachFromRoot():Void
	{
		if (_childrenNativeLayer.parent != null)
		{
			Lib.current.removeChild(_childrenNativeLayer);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden High level pixel manipulation method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw bitmap data into the bitmap display object.
	 */
	override public function drawImage(bitmapData:NativeBitmapData, matrix:Matrix = null, sourceRect:RectangleVO = null):Void
	{	
		//init destination point and sourceRect if null
		
		if (matrix == null)
		{
			matrix = new Matrix();
		}
		
		if (sourceRect == null)
		{
			var width:Float = bitmapData.width;
			var height:Float = bitmapData.height;
			sourceRect = new RectangleVO(0.0, 0.0, width, height);
		}
		
		//convert the cross-platform rectangle into flash native one
		_flashRectangle.x = sourceRect.x;
		_flashRectangle.y = sourceRect.y;
		_flashRectangle.width = sourceRect.width;
		_flashRectangle.height = sourceRect.height;
		
		var matrixData:MatrixData = matrix.data;
		
		_flashMatrix.a = matrixData.a;
		_flashMatrix.b = matrixData.b;
		_flashMatrix.c = matrixData.c;
		_flashMatrix.d = matrixData.d;
		_flashMatrix.tx = matrixData.e;
		_flashMatrix.ty = matrixData.f;
		
		var colorTransform:ColorTransform = null;
		
		//use a colorTransform to apply the alphe if 
		//transparency is used
		if (_useTransparency == true)
		{
			colorTransform = new ColorTransform(1.0, 1.0, 1.0, _alpha);
		}
		
		//draw the bitmap data onto the current bitmap data with the right transformations
		_nativeBitmap.bitmapData.draw(bitmapData, _flashMatrix, colorTransform, null, _flashRectangle, true);
	}
	
	/**
	 * Uses flash native copyPixels method for fast pixel 
	 * manipulation
	 */
	override public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleVO, destPoint:PointVO):Void
	{
		_flashRectangle.x = sourceRect.x;
		_flashRectangle.y = sourceRect.y;
		_flashRectangle.width = sourceRect.width;
		_flashRectangle.height = sourceRect.height;
		
		_flashPoint.x = destPoint.x;
		_flashPoint.y = destPoint.y;
		
		var alphaBitmapData:BitmapData = null;
		var alphaPoint:Point = null;
		
		//create a transparency bitmap data if transparency is
		//used
		if (_useTransparency == true)
		{
			var color:Int = 0x000000;
			var alpha:Int = Math.round(255 * _alpha);
			color += alpha << 24;
			
			alphaBitmapData = new BitmapData(Math.round(sourceRect.width), Math.round(sourceRect.height), true, color);
			alphaPoint = new Point(0,0);
		}
		
		_nativeBitmap.bitmapData.copyPixels(bitmapData, _flashRectangle, _flashPoint, alphaBitmapData, alphaPoint, true);
		
		if (alphaBitmapData != null)
		{
			alphaBitmapData.dispose();
		}
	}
	
	/**
	 * Uses flash native fillRect method for fast
	 * rectangle drawing
	 */
	override public function fillRect(rect:RectangleVO, color:ColorVO):Void
	{
		var argbColor:Int = color.color;
		var alpha:Int = Math.round(255 * color.alpha);
		argbColor += alpha << 24;
		
		//if the color is transparent, a new bitmap data
		//must be created to composite alpha
		if (color.alpha != 1.0)
		{
			_fillRectRectangle.width = rect.width;
			_fillRectRectangle.height = rect.height;
			_fillRectPoint.x = rect.x;
			_fillRectPoint.y = rect.y;
			
			var fillRectBitmapData:BitmapData = new BitmapData(Math.round(rect.width), Math.round(rect.height), true, argbColor);
			copyPixels(fillRectBitmapData, _fillRectRectangle, _fillRectPoint );
			fillRectBitmapData.dispose();
		}
		//else, the faster native flash method can be used
		else
		{
			_flashRectangle.x = rect.x;
			_flashRectangle.y = rect.y;
			_flashRectangle.width = rect.width;
			_flashRectangle.height = rect.height;
			_nativeBitmap.bitmapData.fillRect(_flashRectangle, argbColor);
		}
	
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nativeBitmapData():NativeBitmapData
	{
		return _nativeBitmap.bitmapData;
	}
	
	override private function get_nativeLayer():NativeLayer
	{
		return _nativeLayer;
	}
	
}