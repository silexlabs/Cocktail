/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.drawing;
import cocktail.core.html.HTMLCanvasElement;
import cocktail.core.html.HTMLElement;
import cocktail.core.html.HTMLImageElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CanvasRenderingContext2D 
{
	/**
	 * Returns the current line width.
	 * Can be set, to change the line width. Values that are not finite values greater than zero are ignored.
	 */
	private var _lineWidth:Float;
	public var lineWidth(get_lineWidth, set_lineWidth):Float;
	
	/**
	 * Returns the current line cap style.
	 * Can be set, to change the line cap style.
	 * The possible line cap styles are butt, round, and square.
	 */
	private var _lineCap:LineCap;
	public var lineCap(get_lineCap, set_lineCap):LineCap;

	/**
	 * Returns the current line join style. 
	 * Can be set, to change the line join style.
	 * The possible line join styles are bevel, round, and miter.
	 */
	private var _lineJoin:LineJoin;
	public var lineJoin(get_lineJoin, set_lineJoin):LineJoin;
	
	/**
	 * Returns the current miter limit ratio.
	 * Can be set, to change the miter limit ratio. Values that are not finite values greater than zero are ignored.
	 */
	private var _miterLimit:Float;
	public var miterLimit(get_miterLimit, set_miterLimit):Float;
	
	/**
	 * Returns the canvas element.
	 */
	private var _canvas:HTMLCanvasElement;
	public var canvas(get_canvas, never):HTMLCanvasElement;
	
	/**
	 * class constructor
	 */
	public function new(canvas:HTMLCanvasElement) 
	{
		_canvas = canvas;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC RECTS METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Clears all pixels on the canvas in the given rectangle to transparent black.
	 */
	public function clearRect(x:Float, y:Float, w:Float, h:Float):Void
	{
		
	}
	
	/**
	 * Paints the given rectangle onto the canvas, using the current fill style.
	 */
	public function fillRect(x:Float, y:Float, w:Float, h:Float):Void
	{
		
	}
	
	/**
	 * Paints the box that outlines the given rectangle onto the canvas, using the current stroke style.
	 */
	public function strokeRect(x:Float, y:Float, w:Float, h:Float):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC PATH METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Resets the current path.
	 */
	public function beginPath():Void
	{
		
	}
	
	/**
	 * Marks the current subpath as closed, and starts a 
	 * new subpath with a point the same as the start and end of the newly closed subpath.
	 */
	public function closePath():Void
	{
		
	}
	
	/**
	 * Creates a new subpath with the given point.
	 */
	public function moveTo(x:Float, y:Float):Void
	{
		
	}
	
	/**
	 * Adds the given point to the current subpath, 
	 * connected to the previous one by a straight line.
	 */
	public function lineTo(x:Float, y:Float):Void
	{
		
	}
	
	/**
	 * Adds the given point to the current subpath, connected to
	 * the previous one by a quadratic Bézier curve with the given control point.
	 */
	public function quadraticCurveTo(cpx:Float, cpy:Float, x:Float, y:Float):Void
	{
		
	}
	
	/**
	 * Adds a new closed subpath to the path, representing the given rectangle.
	 */
	public function rect(x:Float, y:Float, w:Float, h:Float):Void
	{
		
	}
	
	/**
	 * Fills the subpaths with the current fill style.
	 */
	public function fill():Void
	{
		
	}
	
	/**
	 * Strokes the subpaths with the current stroke style.
	 */
	public function stroke():Void
	{
		
	}
	
	/**
	 * Further constrains the clipping region to the given path.
	 */
	public function clip():Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC IMAGE DRAWING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	
	@:overload(function(i:Bool):Void { trace("over"); } )
	public function drawImage(image:HTMLElement, sx:Float, sy:Float, sw:Float, sh:Float, dx:Float, dy:Float, dw:Float, dh:Float):Void
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC PIXEL MANIPULATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	public function createImageData(sw:Float, sh:Float):ImageData
	{
		
	}
	
	public function getImageData(sx:Float, sy:Float, sw:Float, sh:Float):ImageData
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC TRANSFORMATION METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Changes the transformation matrix to apply a scaling transformation with the given characteristics.
	 */
	public function scale(x:Float, y:Float):Void
	{
		
	}
	
	/**
	 * Changes the transformation matrix to apply a rotation transformation with the given characteristics.
	 * The angle is in radians.
	 */
	public function rotate(angle:Float):Void
	{
		
	}
	
	/**
	 * Changes the transformation matrix to apply a translation 
	 * transformation with the given characteristics.
	 */
	public function translate(x:Float, y:Float):Void
	{
		
	}
	
	/**
	 * Changes the transformation matrix to apply the matrix given
	 * by the arguments as described below.
	 */
	public function transform(a:Float, b:Float, c:Float, d:Float, e:Float, f:Float):Void
	{
		
	}
	
	/**
	 * Changes the transformation matrix to the matrix given by the arguments as described below.
	 */
	public function setTransform(a:Float, b:Float, c:Float, d:Float, e:Float, f:Float):Void
	{
		
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_miterLimit():Float 
	{
		return _miterLimit;
	}
	
	private function set_miterLimit(value:Float):Float 
	{
		return _miterLimit = value;
	}
	
	private function get_lineJoin():LineJoin 
	{
		return _lineJoin;
	}
	
	private function set_lineJoin(value:LineJoin):LineJoin 
	{
		return _lineJoin = value;
	}
	
	private function get_lineCap():LineCap 
	{
		return _lineCap;
	}
	
	private function set_lineCap(value:LineCap):LineCap 
	{
		return _lineCap = value;
	}
	
	private function get_lineWidth():Float 
	{
		return _lineWidth;
	}
	
	private function set_lineWidth(value:Float):Float 
	{
		return _lineWidth = value;
	}
	
	private function get_canvas():HTMLCanvasElement 
	{
		return _canvas;
	}
	
	
}