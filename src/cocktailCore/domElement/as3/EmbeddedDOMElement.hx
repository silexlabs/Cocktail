/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import cocktail.geom.Matrix;
import cocktail.geom.GeomData;
import cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
import cocktail.nativeElement.NativeElement;
import haxe.Log;

/**
 * This is the Flash AVM2 implementation of the Embedded DOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedDOMElement extends AbstractEmbeddedDOMElement
{
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	/**
	 * when the matrix is set, update also
	 * the values of the native flash matrix of the
	 * native DisplayObject
	 * @param	matrix
	 */
	override private function setMatrix(matrix:Matrix):Matrix
	{
		super.setMatrix(matrix);
		
		var currentMatrix:Matrix = new Matrix();
	
		currentMatrix.concatenate(matrix);
		currentMatrix.translate(this.x, this.y);
		currentMatrix.scale(this.width / this.intrinsicWidth, this.height / this.intrinsicHeight, { x:0.0, y:0.0} );
		
		//get the data of the abstract matrix
		var matrixData:MatrixData = currentMatrix.data;
			
		//create a native matrix with the abstract matrix data
		var nativeTransformMatrix:flash.geom.Matrix  = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
	
		
		this._nativeElement.transform.matrix = nativeTransformMatrix;
		
		
		return this._matrix;
	}
}