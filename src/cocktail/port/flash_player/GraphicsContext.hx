package cocktail.port.flash_player;

import cocktail.core.geom.Matrix;
import cocktail.core.graphics.AbstractGraphicsContext;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import flash.display.Bitmap;
import cocktail.core.geom.GeomData;
import cocktail.core.unit.UnitData;
import flash.display.BitmapData;
import flash.display.Sprite;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class GraphicsContext extends AbstractGraphicsContext
{
	private var _nativeBitmap:Bitmap;
	
	private var _nativeLayer:Sprite;
	
	private var _childrenNativeLayer:Sprite;
	
	private var _width:Int;
	
	private var _height:Int;
	
	public function new(nativeLayer:NativeElement = null) 
	{
		super();
		
		if (nativeLayer == null)
		{
			nativeLayer = new Sprite();
		}
		trace(nativeLayer);
		_nativeLayer = cast(nativeLayer);
		
		_childrenNativeLayer = new Sprite();
		
		_nativeBitmap = new Bitmap(new BitmapData(1,1, true, 0x00000000));
		
		_width = 0;
		_height = 0;
		
		_nativeLayer.addChild(_nativeBitmap);
		_nativeLayer.addChild(_childrenNativeLayer);
	}
	
	override public function initBitmapData(width:Int, height:Int):Void
	{
		_width = width;
		_height = height;
		
		_nativeBitmap.bitmapData.dispose();
		_nativeBitmap.bitmapData = new BitmapData(width, height, true, 0x00000000);
	}
	
	override public function clear():Void
	{
		_nativeBitmap.bitmapData.fillRect(new flash.geom.Rectangle(0, 0, _width, _height), 0x00000000);
	}
	
	/////////////////////////////////
	// OVERRIDEN PUBLIC METHODS
	////////////////////////////////
	
	override public function appendChild(newChild:AbstractGraphicsContext):AbstractGraphicsContext
	{
		super.appendChild(newChild);
		
		_childrenNativeLayer.addChild(newChild.nativeLayer);
		
		return newChild;
	}
	
	override public function removeChild(oldChild:AbstractGraphicsContext):AbstractGraphicsContext
	{
		super.removeChild(oldChild);
	
		_childrenNativeLayer.removeChild(oldChild.nativeLayer);
		
		return oldChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden High level pixel manipulation method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Draw bitmap data into the bitmap display object.
	 */
	override public function drawImage(bitmapData:NativeBitmapData, matrix:Matrix = null, sourceRect:RectangleData = null):Void
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
			sourceRect = {
				x:0.0,
				y:0.0,
				width:width,
				height:height
			};
		}
		
		//convert the cross-platform rectangle and point into flash natives one
		var nativeSourceRect:flash.geom.Rectangle = new flash.geom.Rectangle(sourceRect.x, sourceRect.y, sourceRect.width, sourceRect.height);
		
		var matrixData:MatrixData = matrix.data;
		var nativeMatrix:flash.geom.Matrix = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
		
		//draw the bitmap data onto the current bitmap data with the right transformations
		_nativeBitmap.bitmapData.draw(bitmapData, nativeMatrix, null, null, nativeSourceRect, true);
	}
	
	/**
	 * Uses flash native copyPixels method for fast pixel 
	 * manipulation
	 */
	override public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleData, destPoint:PointData):Void
	{
		var nativeSourceRect:flash.geom.Rectangle = new flash.geom.Rectangle(sourceRect.x, sourceRect.y, sourceRect.width, sourceRect.height);
		var nativeDestPoint:flash.geom.Point = new flash.geom.Point(destPoint.x, destPoint.y);
		_nativeBitmap.bitmapData.copyPixels(bitmapData, nativeSourceRect, nativeDestPoint, null, null, true);
	}
	
	/**
	 * Uses flash native fillRect method for fast
	 * rectangle drawing
	 */
	override public function fillRect(rect:RectangleData, color:ColorData):Void
	{
		trace("fillRect : " + rect);
		trace(color);
		var nativeSourceRect:flash.geom.Rectangle = new flash.geom.Rectangle(rect.x, rect.y, rect.width, rect.height);

		var argbColor:Int = color.color;
		var alpha:Int = Math.round(255 * color.alpha);
		argbColor += alpha << 24;
		
		var fillRectBitmapData:BitmapData = new BitmapData(Math.round(rect.width), Math.round(rect.height), true, argbColor);
		copyPixels(fillRectBitmapData, { x:0.0, y:0.0, width:rect.width, height:rect.height }, { x:rect.x, y:rect.y } );
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nativeBitmapData():NativeBitmapData
	{
		return _nativeBitmap.bitmapData;
	}
	
	override private function get_nativeLayer():NativeElement
	{
		return _nativeLayer;
	}
	
}