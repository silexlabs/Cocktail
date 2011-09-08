/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.domObject.base;

import cocktail.domObject.DOMObject;
import cocktail.domObject.DOMObjectData;
import cocktail.nativeReference.NativeReference;
import haxe.Log;

/**
 * This DOMObject is in charge of displaying a picture of 
 * type .jpg, .png or .gif
 * 
 * @author Yannick DOMINGUEZ
 */
class ImageDOMObjectBase extends DOMObject
{

	/**
	 * class constructor
	 */
	public function new(initialNativeReference:NativeReference = null) 
	{
		super(initialNativeReference);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden hierarchy methods
	// The addChild and removeChild method are not implemented for this 
	// DOMObject, as it is a leaf DOMObject (can't have children)
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function addChild(domObject:DOMObjectBase):Void
	{
		
	}
	
	override public function removeChild(domObject:DOMObjectBase):Void
	{
		
	}
	
}