/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.geom;

import cocktail.core.geom.GeomData;

/**
 * This class is an implementation of a 3x3 matrix. It is meant to be
 * cross-platform and as such doesn't rely on any runtime specific API.
 * 
 * It exposes method to create and manipulate a matrix which can then be 
 * used to apply 2d transformations to an htmlElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class Matrix 
{
	/**
	 * matrix data for 3x3
	 */
	public var a:Float;
	
	public var b:Float;
	
	public var c:Float;
	
	public var e:Float;
	
	public var d:Float;
	
	public var f:Float;
	
	/**
	 * Used internally when an helper
	 * method is called, like rotation,
	 * to represent the matrix of this
	 * transformation.
	 * 
	 * static, only one instance needed for
	 * all matrices
	 */
	private static var _concatenationMatrix:Matrix;
	
	/**
	 * Class constructor. Creates a 3x3 matrix with the given parameters.
	 * It defaults to an identity matrix (no transformations), if the given
	 * matrix data are null.
	 */
	public function new(a:Float = 1.0, b:Float = 0.0, c:Float = 0.0, d:Float = 1.0, e:Float = 0.0, f:Float = 0.0) 
	{
		this.a = a;
		this.b = b;
		this.c = c;
		this.d = d;
		this.e = e;
		this.f = f;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Low level matrix manipulation methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reset the matrix to an identity matrix (no transformations)
	 */
	public function identity():Void
	{
		a = 1.0;
		b = 0.0;
		c = 0.0;
		d = 1.0;
		e = 0.0;
		f = 0.0;
	}
	
	/**
	 * Concatenate the matrix values by multiplying them.
	 * 
	 * @example If matrix1 rotate an object by 45
	 * degrees and matrix2 scale an object by a factor of 2,
	 * then the resulting concatenated matrix
	 * will both rotate and scale the object with the same values.
	 * 
	 * @param	matrix the matrix to concatenate with the current
	 * matrix
	 */
	public function concatenate(matrix:Matrix):Void
	{
		//multiply the two matrix data values
		this.a = a * matrix.a + c * matrix.b;
		this.b = b * matrix.a + d * matrix.b;
		this.c = a * matrix.c + c * matrix.d;
		this.d = b * matrix.c + d * matrix.d;
		this.e = a * matrix.e + c * matrix.f + e;
		this.f = b * matrix.e + d * matrix.f + f;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// High level matrix manipulation methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Apply a transformation translating the matrix with the given x and y offsets.
	 * 
	 * @param	x the translation along the x axis
	 * @param	y the translation along the y axis
	 */
	public function translate(x:Float, y:Float):Void
	{
		//create the matrix corresponding to an identity matrix
		//translated by x and y.
		//concatenate the translation matrix to the current matrix to prevent
		//losing any previous translation
		concatenate(getConcatenationMatrix(1.0, 0.0, 0.0, 1.0, x, y  ));
	}
	
	/**
	 * Apply a transformation rotating the matrix using the specified angle (in rad)
	 * 
	 * @param angle the rotation angle in rad
	 */
	public function rotate(angle:Float):Void
	{
		var a:Float = 0.0;
		var b:Float = 0.0;
		var c:Float = 0.0;
		var d:Float = 0.0;
		
		//check for special angles
		
		if (angle == Math.PI / 2)
		{
			a = d = 0.0;
			c = b = 1.0;
			
		}
		else if (angle == Math.PI)
		{
			a = d = -1.0;
			c = b = 0.0;
		}
		else if (angle == (Math.PI * 3) / 2)
		{
			a = d = 0.0;
			c = b = -1.0;
		}
		else
		{
			a = d = Math.cos(angle);
			c = b = Math.sin(angle);
		}
		
		//create the matrix data corresponding to an identity matrix
		//rotated by the angle
		//concatenate the rotation matrix to the current matrix to
		//prevent losing any previous transformation
		concatenate(getConcatenationMatrix(a, b, c * -1.0, d, 0.0, 0.0));
	}
	
	/**
	 * Apply a transformation scaling the matrix by the "scaleX" and "scaleY" factor
	 * 
	 * @param scaleX horizontal scale factor
	 * @param scaleY vertical scale factor
	 */
	public function scale(scaleX:Float, scaleY:Float):Void
	{	
		//create the matrix data corresponding to an identity matrix
		//scaled by the scaleX and scaleY factors
		//concatenate the scaled matrix to the current matrix to
		//prevent losing any previous transformation
		concatenate(getConcatenationMatrix(scaleX, 0.0, 0.0, scaleY, 0.0, 0.0));
	}
	
	/**
	 * Apply a transformation skewing the matrix by the "skewX" and "skewY"
	 * factor
	 * 
	 * @param skewX the horizontal skew factor
	 * @param skewY the vertical skew factor
	 */
	public function skew(skewX:Float, skewY:Float):Void
	{
		//create the matrix data corresponding to an identity matrix
		//skewed by the skewX and skewY factors
		//concatenate the skewed matrix to the current matrix to
		//prevent losing any previous transformation
		concatenate(getConcatenationMatrix(1.0, Math.tan(skewY), Math.tan(skewY), 1.0, 0.0, 0.0));
	}
	
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC UTILS METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the matrix instance 
	 * used for concatenation. Instantiate
	 * it if needed, and set its value as
	 * given
	 */
	private static function getConcatenationMatrix(a:Float, b:Float, c:Float, d:Float, e:Float, f:Float):Matrix
	{
		if (_concatenationMatrix == null)
		{
			_concatenationMatrix = new Matrix();
		}
		
		_concatenationMatrix.a = a;
		_concatenationMatrix.b = b;
		_concatenationMatrix.c = c;
		_concatenationMatrix.d = d;
		_concatenationMatrix.e = e;
		_concatenationMatrix.f = f;
		
		return _concatenationMatrix;
	}
	
}