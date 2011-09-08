/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.nativeReference.js;

import js.Lib;
import cocktail.nativeReference.NativeReferenceData;
import cocktail.nativeReference.NativeReference;
import cocktail.nativeReference.base.NativeReferenceCreatorBase;

/**
 * This is the Javascript implementation of the native reference
 * creator. It instantiate a native HTML element 
 * and returns it as a NativeReference
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeReferenceCreator extends NativeReferenceCreatorBase
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
	 * @param	nativeReferenceType the type of element to create (graphic, text...)
	 */
	override public function createNativeReference(nativeReferenceType:NativeReferenceTypeValue):NativeReference
	{
		var nativeReference:NativeReference;
		
		switch (nativeReferenceType)
		{
			case image:
				nativeReference = Lib.document.createElement("img");
			
			case text:
				nativeReference = Lib.document.createElement("div");
				
			case neutral:
				nativeReference = Lib.document.createElement("div");
				
			case graphic:
				nativeReference = Lib.document.createElement("canvas");
		}
		
		return nativeReference;
	}
	
}