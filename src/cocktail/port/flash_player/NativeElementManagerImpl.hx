/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.nativeElement.AbstractNativeElementManagerImpl;
import flash.display.DisplayObjectContainer;
import flash.display.Loader;
import flash.display.Sprite;
import cocktail.core.nativeElement.NativeElementData;
import cocktail.core.NativeElement;

/**
 * This is the flash AVM2 implementation of the native element
 * manager
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeElementManagerImpl extends AbstractNativeElementManagerImpl
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
	 * @param	nativeElementType the type of element to create (img, canvas...)
	 */
	override public function createNativeElement(nativeElementType:NativeElementTypeValue):NativeElement
	{
		var nativeElement:NativeElement;
		
		switch (nativeElementType)
		{
			//for image, library, the expected type is a Flash loader as they will be
			//used to load extenal resources
			case img, script:
				nativeElement = new Loader();
				
			//for other types, it is a Sprite	
			case canvas, anchor, input:
				nativeElement = new Sprite();
				
		}
		
		return nativeElement;
	}
	
}