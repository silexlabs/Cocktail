/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.flash_player;

import cocktail.Config;
import cocktail.core.geom.GeomUtils;
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
import flash.display.StageQuality;
import flash.geom.ColorTransform;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.Lib;
import haxe.Stack;


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
	 * 
	 * static, only need one instance at a time
	 */
	private static var _flashRectangle:Rectangle;
	
	/**
	 * Same as above for flash native point
	 */
	private static var _flashPoint:Point;
	
	/**
	 * same as above, but used as point for alpha
	 */
	private static var _flashAlphaPoint:Point;
	
	/**
	 * Same as above for flash Matrix
	 */
	private static var _flashMatrix:flash.geom.Matrix;
	
	/**
	 * Same as above for flash color transform
	 */
	private static var _flashColorTransform:ColorTransform;
	
	/**
	 * A reuseable rectangle used for fillRect rectangle
	 */
	private var _fillRectRectangle:RectangleVO;
	
	/**
	 * A resusable rectangle used as clip rect for
	 * fillRect rectangle
	 */
	private var _clippedRectRectangle:RectangleVO;
	
	/**
	 * A reuseable point used for fillRect rectangle
	 */
	private static var _fillRectPoint:PointVO;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		//instantiate all static flash object on first use
		if (_flashRectangle == null)
		{
			_flashRectangle = new Rectangle();
			_flashPoint = new Point();
			_flashAlphaPoint = new Point();
			_flashMatrix = new flash.geom.Matrix();
			_fillRectRectangle = new RectangleVO();
			_fillRectPoint = new PointVO(0.0, 0.0);
			_flashColorTransform = new ColorTransform();
			_clippedRectRectangle = new RectangleVO();
		}
		
		_nativeLayer = new Sprite();
		_nativeLayer.mouseEnabled = false;
		
		_childrenNativeLayer = new Sprite();
		_childrenNativeLayer.mouseEnabled = false;
		
		_width = 0;
		_height = 0;

		//build native display list
		_childrenNativeLayer.addChild(_nativeLayer);
		
	}
	
	/**
	 * Create new BitmapData when the size of the window changes
	 */
	override public function initBitmapData(width:Int, height:Int):Void
	{
		//here the bitmap data is created for the first time
		if (_nativeBitmap == null)
		{
			_nativeBitmap = new Bitmap(new BitmapData(width, height, true, 0x00000000), PixelSnapping.AUTO, false);
			_childrenNativeLayer.addChildAt(_nativeBitmap, 0);
		}
		else
		{
			//no need to update if the size didn't change
			if (_width == width && _height == height)
			{
				return;
			}
			
			_nativeBitmap.bitmapData.dispose();
			_nativeBitmap.bitmapData = new BitmapData(width, height, true, 0x00000000);
		}
		
		_width = width;
		_height = height;
	}
	
	/**
	 * clear a rectangle of the BitmapData by filling it with
	 * transparent black
	 */
	override public function clear(x:Float, y:Float, width:Float, height:Float):Void
	{
		if (_nativeBitmap != null)
		{
			_flashRectangle.x = x;
			_flashRectangle.y = y;
			_flashRectangle.width = width;
			_flashRectangle.height = height;
			_nativeBitmap.bitmapData.fillRect(_flashRectangle, 0x00000000);
		}
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * clean-up flash native objects
	 */
	override public function dispose():Void
	{
		if (_nativeBitmap != null)
		{
			_nativeBitmap.bitmapData.dispose();
			_childrenNativeLayer.removeChild(_nativeBitmap);
			_nativeBitmap = null;
		}
		
		
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
		//_childrenNativeLayer.transform.matrix = new flash.geom.Matrix(matrix.a, matrix.b, matrix.c, matrix.d, matrix.e, matrix.f);
	}
	
	override public function attach(graphicsContext:GraphicsContext, index:Int):Void
	{
		graphicsContext.parentNode.nativeLayer.addChildAt(_childrenNativeLayer, index);
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
	override public function drawImage(bitmapData:NativeBitmapData, matrix:Matrix, sourceRect:RectangleVO, clipRect:RectangleVO):Void
	{	
		//convert the cross-platform rectangle into flash native one
		_flashRectangle.x = sourceRect.x + clipRect.x - matrix.e;
		_flashRectangle.y = sourceRect.y + clipRect.y - matrix.f;
		_flashRectangle.width = clipRect.width ;
		_flashRectangle.height = clipRect.height;
		
		_flashMatrix.a = matrix.a;
		_flashMatrix.b = matrix.b;
		_flashMatrix.c = matrix.c;
		_flashMatrix.d = matrix.d;
		_flashMatrix.tx = matrix.e;
		_flashMatrix.ty = matrix.f;
		
		if (_useTransformations == true)
		{
			_flashMatrix.tx += _matrix.e;
			_flashMatrix.ty += _matrix.f;
			_flashRectangle.width += _matrix.e ;
			_flashRectangle.height += _matrix.f ;
		}
		
		var colorTransform:ColorTransform = null;
		
		//use a colorTransform to apply the alphe if 
		//transparency is used
		if (_useTransparency == true)
		{
			colorTransform = _flashColorTransform;
			_flashColorTransform.alphaMultiplier = _alpha;
		}
		
		//draw the bitmap data onto the current bitmap data with the right transformations
		_nativeBitmap.bitmapData.draw(bitmapData, _flashMatrix, colorTransform, null, _flashRectangle, Config.ENABLE_BITMAP_SMOOTHING);
	}
	
	/**
	 * Uses flash native copyPixels method for fast pixel 
	 * manipulation
	 */
	override public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleVO, destPoint:PointVO, clipRect:RectangleVO):Void
	{
		_flashRectangle.x = sourceRect.x + clipRect.x - destPoint.x;
		_flashRectangle.y = sourceRect.y + clipRect.y - destPoint.y;
		_flashRectangle.width = clipRect.width ;
		_flashRectangle.height = clipRect.height;
		
		
		_flashPoint.x = clipRect.x;
		_flashPoint.y = clipRect.y;
		
		if (_useTransformations == true)
		{
			_flashPoint.x += _matrix.e;
			_flashPoint.y += _matrix.f;
			_flashRectangle.width -= _matrix.e ;
			_flashRectangle.height -= _matrix.f ;
		}
		
		
		//create a transparency bitmap data if transparency is
		//used
		if (_useTransparency == true)
		{
			var color:Int = 0x000000;
			var alpha:Int = Math.round(255 * _alpha);
			color += alpha << 24;
			
			var alphaBitmapData:BitmapData = new BitmapData(Math.round(clipRect.width), Math.round(clipRect.height), true, color);
			_flashAlphaPoint.x = 0;
			_flashAlphaPoint.y = 0;
			
			_nativeBitmap.bitmapData.copyPixels(bitmapData, _flashRectangle, _flashPoint, alphaBitmapData, _flashAlphaPoint, true);
			
			alphaBitmapData.dispose();
		}
		else
		{
			_nativeBitmap.bitmapData.copyPixels(bitmapData, _flashRectangle, _flashPoint, null, null, true);
		}
	}
	
	/**
	 * Uses flash native fillRect method for fast
	 * rectangle drawing
	 */
	override public function fillRect(rect:RectangleVO, color:ColorVO, clipRect:RectangleVO):Void
	{
		var argbColor:Int = color.color;
		var alpha:Int = Math.round(255 * color.alpha);
		argbColor += alpha << 24;

		//if the color is transparent, a new bitmap data
		//must be created to composite alpha
		if (color.alpha != 1.0 || _useTransparency == true)
		{
			_fillRectRectangle.width = rect.width;
			_fillRectRectangle.height = rect.height;
			_fillRectPoint.x = rect.x;
			_fillRectPoint.y = rect.y;
			
			var fillRectBitmapData:BitmapData = new BitmapData(Math.round(rect.width), Math.round(rect.height), true, argbColor);
			copyPixels(fillRectBitmapData, _fillRectRectangle, _fillRectPoint, clipRect );
			fillRectBitmapData.dispose();
		}
		//else, the faster native flash method can be used
		else
		{
			_clippedRectRectangle.x  = rect.x;
			_clippedRectRectangle.y  = rect.y;
			_clippedRectRectangle.width  = rect.width;
			_clippedRectRectangle.height  = rect.height;
			
			if (_useTransformations == true)
			{
				_clippedRectRectangle.x += _matrix.e;
				_clippedRectRectangle.y += _matrix.f;
			}
			
			GeomUtils.intersectBounds(_clippedRectRectangle, clipRect, _clippedRectRectangle);
			
			_flashRectangle.x = _clippedRectRectangle.x;
			_flashRectangle.y = _clippedRectRectangle.y;
			_flashRectangle.width = _clippedRectRectangle.width;
			_flashRectangle.height = _clippedRectRectangle.height;
			
			_nativeBitmap.bitmapData.fillRect(_flashRectangle, argbColor);
		}
	
	}
	
	/**
	 * Duplicate a region of the bitmap using flash API
	 */
	override public function copyRect(rect:RectangleVO, x:Float, y:Float):Void
	{
		_flashRectangle.x = rect.x;
		_flashRectangle.y = rect.y;
		_flashRectangle.width = rect.width;
		_flashRectangle.height = rect.height;
		
		_flashPoint.x = x;
		_flashPoint.y = y;
		
		_nativeBitmap.bitmapData.copyPixels(_nativeBitmap.bitmapData, _flashRectangle, _flashPoint, null, null, false);
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