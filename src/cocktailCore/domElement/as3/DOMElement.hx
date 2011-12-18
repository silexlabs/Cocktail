/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.as3;

import cocktail.nativeElement.NativeElement;
import flash.display.DisplayObjectContainer;
import flash.events.MouseEvent;
import haxe.Log;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.geom.Matrix;
import cocktail.domElement.DOMElementData;
import cocktail.geom.GeomData;

/**
 * This is the DOMElement implementation for FLASH AS3. 
 * It manipulates the native Flash DOM (the DisplayList)
 * 
 * @author Yannick DOMINGUEZ
 */
class DOMElement extends AbstractDOMElement
{
	/**
	 * Class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden transformation methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
		currentMatrix.translate(this.x, this.y);
		

		
	
		currentMatrix.concatenate(matrix);
		
		//get the data of the abstract matrix
		var matrixData:MatrixData = currentMatrix.data;
		
		//create a native matrix with the abstract matrix data
		var nativeTransformMatrix:flash.geom.Matrix  = new flash.geom.Matrix(matrixData.a, matrixData.b, matrixData.c, matrixData.d, matrixData.e, matrixData.f);
	
		
		this._nativeElement.transform.matrix = nativeTransformMatrix;
		
		
		return this._matrix;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN Z-INDEX SETTER/GETTER
	// Setter/Getter to manipulate a nativeElement z-index in the publication
	//////////////////////////////////////////////////////////////////////////////////////////

	override private function setZIndex(value:Int):Int
	{
		//if the value is outside of the children range, set it to the 
		//last children range
		if (value > _parent.children.length - 1)
		{
			value = _parent.children.length - 1;
		}
		
		//retrieve the parent Display Object, and use it to set
		//the new index on the current DisplayObject
		var parent:DisplayObjectContainer = this._nativeElement.parent;
		parent.setChildIndex(this._nativeElement, value);
		
		return value;
	}
	
	override private function getZIndex():Int 
	{
		//retrieve the parent Display object, and use it to retrieve the current
		//child index
		var parent:DisplayObjectContainer = this._nativeElement.parent;
		return parent.getChildIndex(this._nativeElement);
	}
	
}