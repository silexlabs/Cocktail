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
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden transformation methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When concatenating the base Matrix of an embedded element, it must also
	 * be scaled using the intrinsic width and height of the DOMElement as reference
	 * 
	 */
	override private function getConcatenatedMatrix(matrix:Matrix):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		currentMatrix.concatenate(matrix);
		currentMatrix.translate(this.x, this.y);
		currentMatrix.scale(this.width / this.intrinsicWidth, this.height / this.intrinsicHeight, { x:0.0, y:0.0} );
		return currentMatrix;
	}
}