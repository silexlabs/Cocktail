/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.js;

import cocktailCore.domElement.abstract.AbstractEmbeddedDOMElement;
import cocktail.nativeElement.NativeElement;
import haxe.Log;

/**
 * This is theJavaScript implementation of the Embedded DOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedDOMElement extends AbstractEmbeddedDOMElement
{
	public function new(nativeElement:NativeElement = null) 
	{
		super(nativeElement);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	// in JS, setting the width and height also set the width and height attribute of the
	// native replaced HTML element. For instance, for a picture, if the width is set to 300,
	// then the HTML corresponding tag will be : <img width="300" />
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function setWidth(value:Int):Int
	{
		super.setWidth(value);
		untyped this._nativeElement.width = value;
		return value;
	}
	
	override private function setHeight(value:Int):Int
	{
		super.setHeight(value);
		untyped this._nativeElement.height = value;
		return value;
	}
}