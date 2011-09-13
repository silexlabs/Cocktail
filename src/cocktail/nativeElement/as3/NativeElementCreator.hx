/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.nativeElement.as3;

import flash.display.DisplayObjectContainer;
import flash.display.Loader;
import flash.display.Sprite;
import cocktail.nativeElement.NativeElementData;
import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.base.NativeElementCreatorBase;

/**
 * This is the flash AVM2 implementation of the native element
 * creator. It instantiate a native flash display object 
 * and returns it as a NativeElement
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeElementCreator extends NativeElementCreatorBase
{

	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Instantiate a native flash display object based on the requested type and returns a reference to it.
	 * @param	nativeElementType the type of element to create (graphic, text...)
	 */
	override public function createNativeElement(nativeElementType:NativeElementTypeValue):NativeElement
	{
		var nativeElement:NativeElement;
		
		switch (nativeElementType)
		{
			//for image the expected type is a Flash loader
			case image:
				nativeElement = new Loader();
			
			//for other types, it is a Sprite	
			default:
				nativeElement = new Sprite();
				
		}
		
		return nativeElement;
	}
	
}