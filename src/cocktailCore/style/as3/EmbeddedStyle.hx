/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.as3;

import cocktail.domElement.DOMElement;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.geom.Matrix;
import cocktailCore.style.abstract.AbstractEmbeddedStyle;
import cocktailCore.style.abstract.AbstractStyle;

/**
 * This is the Flash AS3 implementation of the EmbeddedStyle.
 * 
 * Only present to allow compilation
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedStyle extends AbstractEmbeddedStyle
{
	public function new(domElement:DOMElement) 
	{
		super(domElement);
	}
	
	/////////////////////////////////
	// OVERRIDEN PRIVATE HELPER METHODS
	////////////////////////////////
	
	/**
	 * When concatenating the base Matrix of an embedded element, it must also
	 * be scaled using the intrinsic width and height of the DOMElement as reference
	 */
	override private function getConcatenatedMatrix(matrix:Matrix):Matrix
	{
		var currentMatrix:Matrix = new Matrix();
		
		var embeddedDOMElement:EmbeddedDOMElement = cast (this._domElement);
		
		currentMatrix.concatenate(matrix);
		currentMatrix.translate(this._nativeX, this._nativeY);
		currentMatrix.scale(this._nativeWidth / embeddedDOMElement.intrinsicWidth, this._nativeHeight / embeddedDOMElement.intrinsicHeight, { x:0.0, y:0.0} );
		return currentMatrix;
	}
}