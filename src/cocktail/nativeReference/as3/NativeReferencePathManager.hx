/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.nativeReference.as3;

import flash.Lib;
import cocktail.nativeReference.base.NativeReferencePathManagerBase;
import cocktail.nativeReference.NativeReference;

/**
 * This is the flash AVM2 implementation for the path manager. 
 * It returns the flash Stage
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeReferencePathManager extends NativeReferencePathManagerBase
{
	/**
	 * class contructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * Returns a reference to the Flash Stage
	 */
	override public function getRoot():NativeReference
	{
		return Lib.current.stage;
	}
	
}