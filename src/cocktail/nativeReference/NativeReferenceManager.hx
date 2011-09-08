/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.nativeReference;

//import the right runtime implementations
#if flash9
import cocktail.nativeReference.as3.NativeReferenceCreator;
import cocktail.nativeReference.as3.NativeReferencePathManager;

#elseif js
import cocktail.nativeReference.js.NativeReferenceCreator;
import cocktail.nativeReference.js.NativeReferencePathManager;
#end

import cocktail.nativeReference.NativeReferenceData;
import cocktail.nativeReference.NativeReference;

/**
 * this class abstract and manages the interaction with a
 * native DOM. Native DOM element element are abstracted as 
 * NativeReference.
 * 
 * It manages the native references path, allowing to retrieve
 * native reference with path
 * 
 * It abstracts the creation of new native element by mimicking
 * the HTML way of creating new element.
 * 
 * This class proxies method call to runtime specific implementations
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeReferenceManager 
{
	/**
	 * A reference to the runtime specific implementation of the class
	 * instantiating the new native elements
	 */
	static private var _nativeReferenceCreator:NativeReferenceCreator;
	
	/**
	 * A reference to the runtime specific implementation of the class
	 * managing the native reference paths
	 */
	static private var _nativeReferencePathManager:NativeReferencePathManager;
	
	/**
	 * Class constructor. Private as this class is meant to be used
	 * through its static methods
	 */
	private function new() 
	{
		
	}
	
	/**
	 * Returns the native DOM root of the current runtime, for instance
	 * the Body element in HTML
	 */
	public static function getRoot():NativeReference
	{
		//instantiate the path manager if first use
		if (_nativeReferencePathManager == null)
		{
			_nativeReferencePathManager = new NativeReferencePathManager();
		}
		return _nativeReferencePathManager.getRoot();
	}
	
	/**
	 * Instantiate a native element and returns a reference to it
	 * @param	nativeReferenceType the type of element to create (graphic, text...)
	 */
	public static function createNativeReference(nativeReferenceType:NativeReferenceTypeValue):NativeReference
	{
		//instantiate the reference creator if first use
		if (_nativeReferenceCreator == null)
		{
			_nativeReferenceCreator = new NativeReferenceCreator();
		}
		
		return _nativeReferenceCreator.createNativeReference(nativeReferenceType);
	}
}