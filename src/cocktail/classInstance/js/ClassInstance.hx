/*
This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.classInstance.js;

import js.Lib;
import cocktail.classInstance.base.ClassInstanceBase;

/**
 * This is the implementation of the native class instance proxy for JavaScript. It implemenents
 * a class instantiation method specific to the JavaScript runtime
 * @author Yannick DOMINGUEZ
 */
class ClassInstance extends ClassInstanceBase
{
	/**
	 * class constructor
	 */
	public function new(nativeInstanceClassName:String) 
	{
		super(nativeInstanceClassName);
		
		//instantiate a native JS "class" and store a reference to it
		
		//tests if the class can be resolved, meaning it was compiled with Haxe, then instanciate it
		if (Type.resolveClass(nativeInstanceClassName) != null)
		{
			_nativeInstance = Type.createInstance(Type.resolveClass(nativeInstanceClassName), []);
		}
		else
		{
			//else instantiate it with native JavaScript method
			_nativeInstance = Lib.eval("new " + nativeInstanceClassName + "()");
		}
	}
	
}