/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.core.config.Config;
import cocktail.geom.GeomUtils;
import cocktail.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.layer.LayerRenderer;
import cocktail.port.base.GraphicsSurfaceBase;
import cocktail.port.Bindings;
import flash.display.Bitmap;
import cocktail.geom.GeomData;
import flash.display.BitmapData;
import flash.display.PixelSnapping;
import flash.display.Sprite;
import flash.display.StageQuality;
import flash.geom.ColorTransform;
import cocktail.css.CSSStyleData;
import flash.geom.Point;
import flash.geom.Rectangle;
import flash.Lib;



/**
 * The flash implementation of the graphics object. Use native
 * flash BitmapData to draw
 * 
 * @author Yannick DOMINGUEZ
 */
class GraphicsSurface extends GraphicsSurfaceBase
{
	/**
	 * A flash native rectangle object, which
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
	private static var _fillRectRectangle:RectangleVO;
	
	/**
	 * A resusable rectangle used as clip rect for
	 * fillRect rectangle
	 */
	private static var _clippedRectRectangle:RectangleVO;
	
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
	}
	
	/**
	 * Create new BitmapData when the size is updated
	 */
	override public function initBitmapData(width:Int, height:Int):Void
	{
		nativeBitmapData = new BitmapData(width, height, true, 0x00000000);
	}
	
	/**
	 * clear a rectangle of the BitmapData by filling it with
	 * transparent black
	 */
	override public function clear(x:Float, y:Float, width:Float, height:Float):Void
	{
		if (nativeBitmapData != null)
		{
			_flashRectangle.x = x;
			_flashRectangle.y = y;
			_flashRectangle.width = width;
			_flashRectangle.height = height;
			nativeBitmapData.fillRect(_flashRectangle, 0x00000000);
		}
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * set alpha on flash color transform object
	 */
	override public function beginTransparency(alpha:Float):Void
	{
		super.beginTransparency(alpha);
		_flashColorTransform.alphaMultiplier = alpha;
	}
	
	/**
	 * clean-up flash native objects
	 */
	override public function dispose():Void
	{
		if (nativeBitmapData != null)
		{
			nativeBitmapData.dispose();
			nativeBitmapData = null;
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
		//not ready to draw yet
		if (nativeBitmapData == null)
		{
			return;
		}
		
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
		
		roundFlashRect();
		
		//draw the bitmap data onto the current bitmap data with the right transformations and alpha
		if (_useTransparency == true)
		{
			nativeBitmapData.draw(bitmapData, _flashMatrix, _flashColorTransform, null, _flashRectangle, true);
		}
		else
		{
			nativeBitmapData.draw(bitmapData, _flashMatrix, null, null, _flashRectangle, true);
		}
	}
	
	/**
	 * Uses flash native copyPixels method for fast pixel 
	 * manipulation
	 */
	override public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleVO, destPoint:PointVO, clipRect:RectangleVO):Void
	{
		//not ready to draw yet
		if (nativeBitmapData == null)
		{
			return;
		}
		
		_flashRectangle.x = sourceRect.x;
		_flashRectangle.y = sourceRect.y;
		_flashRectangle.width = sourceRect.width;
		_flashRectangle.height = sourceRect.height;
		
		_flashPoint.x = destPoint.x;
		_flashPoint.y = destPoint.y;
		
		//TODO : should be done before this method
		if (destPoint.x + sourceRect.width > clipRect.x + clipRect.width)
		{
			_flashRectangle.width += (clipRect.x + clipRect.width) - (destPoint.x + sourceRect.width);
		}
		
		if (destPoint.x < clipRect.x)
		{
			_flashRectangle.x += clipRect.x - destPoint.x;
			_flashPoint.x += clipRect.x - destPoint.x;
			_flashRectangle.width -= clipRect.x - destPoint.x;
		}
		
		if (destPoint.y + sourceRect.height > clipRect.y + clipRect.height)
		{
			_flashRectangle.height += (clipRect.y + clipRect.height) - (destPoint.y + sourceRect.height);
		}
		if (destPoint.y < clipRect.y)
		{
			_flashRectangle.y += clipRect.y - destPoint.y;
			_flashPoint.y += clipRect.y - destPoint.y;
			_flashRectangle.height -= clipRect.y - destPoint.y;
		}
		
		if (_useTransformations == true)
		{
			_flashPoint.x += _matrix.e;
			_flashPoint.y += _matrix.f;
		}
		
		roundFlashRect();
		roundFlashPoint();
		
		//use draw method for transparency, as color transform is needed
		if (_useTransparency == true)
		{
			_flashMatrix.identity();
			_flashMatrix.tx = Math.floor(destPoint.x);
			_flashMatrix.ty = Math.floor(destPoint.y);
			
			nativeBitmapData.draw(bitmapData, _flashMatrix, _flashColorTransform, null, null, false);
		}
		else
		{
			nativeBitmapData.copyPixels(bitmapData, _flashRectangle, _flashPoint, null, null, true);
		}
	}
	
	/**
	 * Uses flash native fillRect method for fast
	 * rectangle drawing
	 */
	override public function fillRect(rect:RectangleVO, color:ColorVO, clipRect:RectangleVO):Void
	{
		//not ready to draw yet
		if (nativeBitmapData == null)
		{
			return;
		}
		
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
			
			roundFlashRect();
			
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
			
			roundFlashRect();
			
			nativeBitmapData.fillRect(_flashRectangle, argbColor);
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
		
		roundFlashRect();
		roundFlashPoint();
		
		nativeBitmapData.copyPixels(nativeBitmapData, _flashRectangle, _flashPoint, null, null, false);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Private helper method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * 	Flash structure need to be rounded before calling native drawing API's,
	 *  else during animation, flash seems to round randomly and make the
	 *  animation seems shaky
	 */
	private static inline function roundFlashRect():Void
	{
		_flashRectangle.x = Math.round(_flashRectangle.x);
		_flashRectangle.y = Math.round(_flashRectangle.y);
		_flashRectangle.width = Math.round(_flashRectangle.width);
		_flashRectangle.height = Math.round(_flashRectangle.height);
	}
	
	/**
	 * Same as above for flash point
	 */
	private static inline function roundFlashPoint():Void
	{
		_flashPoint.x = Math.round(_flashPoint.x);
		_flashPoint.y = Math.round(_flashPoint.y);
	}
}
