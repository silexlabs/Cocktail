/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
	 * Stores each value of this 3x3 matrix
	 */
	private var _data:MatrixData;
	public var data(getData, setData):MatrixData;
	
	/**
	 * Class constructor. Creates a 3x3 matrix with the given parameters.
	 * It defaults to an identity matrix (no transformations), if the given
	 * matrix data are null.
	 */
	public function new(data:MatrixData = null) 
	{
		this.data = data;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Low level matrix manipulation methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Reset the matrix to an identity matrix (no transformations)
	 */
	public function identity():Void
	{
		_data = {
			a : 1.0,
			b : 0.0, 
			c : 0.0,
			d : 1.0,
			e : 0.0,
			f : 0.0
		};
	}
	
	/**
	 * Set the values of this 3x3 matrix, fall back to an
	 * identity matrix if null
	 * 
	 * @param contains 6 values
	 */
	private function setData(data:MatrixData):MatrixData
	{
		_data = data;
		
		//init the null matrix as an identity matrix
		if (_data == null)
		{
			identity();
		}
		
		return _data;
	}
	
	/**
	 * Return this matrix data
	 * @return the 6 values of this 3x3 matrix
	 */
	private function getData():MatrixData
	{
		return _data;
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
		//get a ref to current and target matrix data
		var currentMatrixData:MatrixData = _data;
		var targetMatrixData:MatrixData = matrix.data;
		
		//multiply the two matrix data values
		var a:Float = currentMatrixData.a * targetMatrixData.a + currentMatrixData.c * targetMatrixData.b;
		var b:Float = currentMatrixData.b * targetMatrixData.a + currentMatrixData.d * targetMatrixData.b;
		var c:Float = currentMatrixData.a * targetMatrixData.c + currentMatrixData.c * targetMatrixData.d;
		var d:Float = currentMatrixData.b * targetMatrixData.c + currentMatrixData.d * targetMatrixData.d;
		var e:Float = currentMatrixData.a * targetMatrixData.e + currentMatrixData.c * targetMatrixData.f + currentMatrixData.e;
		var f:Float = currentMatrixData.b * targetMatrixData.e + currentMatrixData.d * targetMatrixData.f + currentMatrixData.f;
		
		//concatenate the result
		var concatenatedMatrixData:MatrixData = {
			a : a,
			b : b,
			c : c,
			d : d,
			e : e,
			f : f
		};
		
		//then set it as this matrix data
		this.data = concatenatedMatrixData;
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
		//create the matrix data corresponding to an identity matrix
		//translated by x and y
		var translationMatrixData:MatrixData = {
			a:1.0,
			b:0.0,
			c:0.0,
			d:1.0,
			e:x,
			f:y
		}
		
		//create the corresponding matrix
		var translationMatrix:Matrix = new Matrix(translationMatrixData);
		
		//concatenate the translation to the current matrix to prevent
		//losing any previous translation
		concatenate(translationMatrix);
	}
	
	/**
	 * Apply a transformation rotating the matrix using the specified angle (in rad)
	 * 
	 * @param angle the rotation angle in rad
	 */
	public function rotate(angle:Float):Void
	{
		//the matrix that will be rotated. It will be
		//concatenated with the current matrix. Default to an identity matrix
		var rotatedMatrix:Matrix = new Matrix();
		
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
		var rotationMatrixData:MatrixData = {
			a:a,
			b:b,
			c:c * -1.0,
			d:d,
			e:0.0,
			f:0.0
		};
		
		//and set it to a matrix
		var rotationMatrix:Matrix = new Matrix(rotationMatrixData);
		
		//concatenate the 2 matrices to obtain a matrix rotated around
		//the transform origin
		rotatedMatrix.concatenate(rotationMatrix);
		
		//concatenate the rotated matrix to the current matrix to
		//prevent losing any previous transformation
		concatenate(rotatedMatrix);
	}
	
	/**
	 * Apply a transformation scaling the matrix by the "scaleX" and "scaleY" factor
	 * 
	 * @param scaleX horizontal scale factor
	 * @param scaleY vertical scale factor
	 */
	public function scale(scaleX:Float, scaleY:Float):Void
	{	
		//the matrix that will be scaled . It will be
		//concatenated with the current matrix. Default to an identity matrix
		var scaledMatrix:Matrix = new Matrix();
		
		//create the matrix data corresponding to an identity matrix
		//scaled by the scaleX and scaleY factors
		var scalingMatrixData:MatrixData = {
			a:scaleX,
			b:0.0,
			c:0.0,
			d:scaleY,
			e:0.0,
			f:0.0
		};
		
		//and set it to a matrix
		var scalingMatrix:Matrix = new Matrix(scalingMatrixData);
		
		//concatenate the 2 matrices to obtain a matrix scaled around
		//the transform origin point
		scaledMatrix.concatenate(scalingMatrix);
		
		//concatenate the scaled matrix to the current matrix to
		//prevent losing any previous transformation
		concatenate(scaledMatrix);
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
		//the matrix that will be skewed. It will be
		//concatenated with the current matrix. Default to an identity matrix
		var skewedMatrix:Matrix = new Matrix();
		
		//create the matrix data corresponding to an identity matrix
		//skewed by the skewX and skewY factors
		var skewingMatrixData:MatrixData = {
			a:1.0,
			b:Math.tan(skewY),
			c:Math.tan(skewX),
			d:1.0,
			e:0.0,
			f:0.0
		};
		
		//and set it to a matrix
		var skewingMatrix:Matrix = new Matrix(skewingMatrixData);
		
		//concatenate the 2 matrices to obtain a matrix skewed around
		//the transform origin point
		skewedMatrix.concatenate(skewingMatrix);
		
		//concatenate the skewed matrix to the current matrix to
		//prevent losing any previous transformation
		concatenate(skewedMatrix);
	}
}