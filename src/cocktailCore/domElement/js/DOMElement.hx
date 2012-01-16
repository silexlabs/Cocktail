/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.js;

import cocktail.nativeElement.NativeElement;
import haxe.Log;
import js.Dom;
import cocktailCore.domElement.abstract.AbstractDOMElement;
import cocktail.domElement.DOMElementData;
import cocktail.geom.Matrix;
import cocktail.geom.GeomData;

/**
 * This is the DOMElement implementation for JavaScript. 
 * It manipulates the native HTML DOM
 * @author Yannick DOMINGUEZ
 */
class DOMElement extends AbstractDOMElement
{
	/////////////////////////////////
	// CONSTRUTOR & INIT
	/////////////////////////////////
	
	/**
	 * Class constructor
	 */
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
}