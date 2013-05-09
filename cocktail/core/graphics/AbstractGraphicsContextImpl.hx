/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.graphics;

import cocktail.core.geom.Matrix;
import cocktail.core.html.HTMLDocument;
import cocktail.core.layer.LayerRenderer;
import cocktail.core.renderer.ElementRenderer;
import cocktail.port.Bindings;

import cocktail.core.geom.GeomData;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSData;

/**
 * This is the base class for classes which 
 * actually implements the platform specific
 * API calls to draw and build the native display
 * list of the target platform.
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
	public var nativeLayer(get_nativeLayer, null):NativeLayer;
	
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
	 * A flag determining wether to use the
	 * provided transformations matrix when
	 * drawing to bitmap
	 */
	private var _useTransformations:Bool;
	
	/**
	 * The transformations matrix to use when
	 * drawing if the use transformations flag
	 * is true
	 */
	private var _matrix:Matrix;

	/**
	 * class constructor
	 */
	public function new()
	{
		_useTransparency = false;
		_useTransformations = false;
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
	
	/**
	 * Attach the native layer to the native display list
	 * 
	 * @param	graphicsContext the graphic context containing
	 * the native layer where this native layer should be attached
	 * @param	index the index of the graphic context owning this
	 * graphic context implemention in its parent's children list
	 */
	public function attach(graphicsContext:GraphicsContext, index:Int):Void
	{
		//abstract
	}
	
	/**
	 * Detach the native from the native display list
	 */
	public function detach(graphicsContext:GraphicsContext):Void
	{
		//abstract
	}
	
	/**
	 * Attach the native layer to the root
	 * of the native display list, used for
	 * the root graphics context
	 */
	public function attachToRoot(rootLayer:NativeLayer):Void
	{
		//abstract
	}
	
	/**
	 * Detach the native layer from
	 * the root of the native display list
	 */
	public function detachFromRoot():Void
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
	 * Clears a given rectangle of the bitmap data.
	 * The coordinate are provided in viewport space
	 */
	public function clear(x:Float, y:Float, width:Float, height:Float):Void
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
	 * Takes a region of the current bitmap matching rect,
	 * and duplicate it on the current at the x/y position
	 */
	public function copyRect(rect:RectangleVO, x:Float, y:Float):Void
	{
		//abstract
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
	 * When called, all subsequent calls to bitmap
	 * drawing methods draw using the provided transformation
	 * matrix, until endTransformations is called
	 */
	public function beginTransformations(matrix:Matrix):Void
	{
		_useTransformations = true;
		_matrix = matrix;
	}
	
	/**
	 * End the use of the transformation
	 * matrix when drawing
	 */
	public function endTransformations():Void
	{
		_matrix = null;
		_useTransformations = false;
	}
	
	/**
	 * Draw bitmap data onto the bitmap surface. Alpha is preserved 
	 * for transparent bitmap
	 * @param	bitmapData the source  bitmap data
	 * @param	matrix a transformation matrix to apply yo the bitmap data when drawing to 
	 * to the bitmap.
	 * @param	sourceRect defines the zone from the source bitmap data that must be copied onto the 
	 * native graphic dom element.
	 * @param clipRect define the zone in the drawn bitmap where pixels can be painted, all pixels
	 * outside of this rectangle are never painted
	 */
	public function drawImage(bitmapData:NativeBitmapData, matrix:Matrix, sourceRect:RectangleVO, clipRect:RectangleVO):Void
	{
		//abstract
	}
	
	/**
	 * fast pixel manipulation method used when no transformation is applied to the image
	 * @param	bitmapData the pixels to copy
	 * @param	sourceRect the area of the source bitmap data to use
	 * @param	destPoint the upper left corner of the rectangular aeaa where the new
	 * pixels are placed
	 * @param clipRect define the zone in the drawn bitmap where pixels can be painted, all pixels
	 * outside of this rectangle are never painted
	 */
	public function copyPixels(bitmapData:NativeBitmapData, sourceRect:RectangleVO, destPoint:PointVO, clipRect:RectangleVO):Void
	{
		//abstract
	}
	
	/**
	 * Fill a rect with the specified color
	 * @param rect the rectangle to fill
	 * @param color the rectangle's color
	 * @param clipRect define the zone in the drawn bitmap where pixels can be painted, all pixels
	 * outside of this rectangle are never painted
	 */
	public function fillRect(rect:RectangleVO, color:ColorVO, clipRect:RectangleVO):Void
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
	
	private function get_nativeLayer():NativeLayer
	{
		return null;
	}
	
}