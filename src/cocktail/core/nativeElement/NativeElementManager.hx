/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.nativeElement;


import cocktail.core.nativeElement.NativeElementData;
import cocktail.core.NativeElement;
import cocktail.core.NativeElementManagerImpl;

/**
 * this class abstract and manages the interaction with a
 * native DOM element (e.g a DisplayObject in flash, an HTML element in JS...). Native elements are wrapped in 
 * NativeElement class instance.
 * 
 * It abstracts the creation of new native element by mimicking
 * the HTML way of creating new element.
 * 
 * This class proxies method call to runtime specific implementations
 * 
 * TODO : redo all the package's doc
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeElementManager 
{
	//TODO : redo all doc
	
	/**
	 * A reference to the runtime specific implementation of the class
	 * instantiating the new native elements
	 */
	static private var _nativeElementManagerImpl:NativeElementManagerImpl;
	
	/**
	 * Class constructor. Private as this class is meant to be used
	 * through its static methods
	 */
	private function new() 
	{
		
	}
	
	/**
	 * Returns the native DOM root of the current runtime, for instance
	 * the Body element in HTML, the Stage in Flash
	 */
	public static function getRoot():NativeElement
	{
		//instantiate the path manager if first use
		if (_nativeElementManagerImpl == null)
		{
			init();
		}
		return _nativeElementManagerImpl.getRoot();
	}
	
	/**
	 * Instantiate a native element and returns a reference to it
	 * @param	nativeElementType the type of element to create (graphic, text...)
	 */
	public static function createNativeElement(nativeElementType:NativeElementTypeValue):NativeElement
	{
		//instantiate the path manager if first use
		if (_nativeElementManagerImpl == null)
		{
			init();
		}
		return _nativeElementManagerImpl.createNativeElement(nativeElementType);
	}
	
	private static function init():Void
	{
		_nativeElementManagerImpl = new NativeElementManagerImpl();
	}
}