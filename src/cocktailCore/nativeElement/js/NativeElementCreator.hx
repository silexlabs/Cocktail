/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.nativeElement.js;

import js.Lib;
import cocktail.nativeElement.NativeElementData;
import cocktail.nativeElement.NativeElement;
import cocktailCore.nativeElement.abstract.AbstractNativeElementCreator;

/**
 * This is the Javascript implementation of the native element
 * creator. It instantiate a native HTML element 
 * and returns it as a NativeElement
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeElementCreator extends AbstractNativeElementCreator
{

	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Instantiate a native HTML Element based on the requested type and returns a reference to it.
	 * @param	nativeElementType the type of element to create (graphic, text...)
	 */
	override public function createNativeElement(nativeElementType:NativeElementTypeValue):NativeElement
	{
		var nativeElement:NativeElement;
		
		switch (nativeElementType)
		{
			case image:
				nativeElement = Lib.document.createElement("img");
			
			case text:
				nativeElement = Lib.document.createElement("div");
				
			case neutral:
				nativeElement = Lib.document.createElement("div");
				
			case graphic:
				nativeElement = Lib.document.createElement("canvas");
				
			case custom(name):
				nativeElement = Lib.document.createElement(name);
				
			case library:
				nativeElement = Lib.document.createElement("script");
				
			case skin:
				nativeElement = Lib.document.createElement("div");
		}
		
		return nativeElement;
	}
	
}