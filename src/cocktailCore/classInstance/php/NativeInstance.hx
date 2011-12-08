/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.nativeClass.php;

import cocktailCore.nativeClass.NativeInstanceBase;

/**
 * This is the implementation of the native class instance proxy for PHP. It implemenents
 * a class instantiation method specific to the PHP runtime
 * 
 * @author	Raphael HARMEL
 * @date	2011-08-03
 */
class NativeInstance extends NativeInstanceBase
{
	/**
	 * class constructor
	 */
	public function new(nativeInstanceClassName:Dynamic) 
	{
		super(nativeInstanceClassName);
		
		// instantiates a native PHP class and stores a reference to it
		
		// tests if the class can be resolved, meaning it was compiled with Haxe, then instanciate it
		if (Type.resolveClass(nativeInstanceClassName) != null)
		{
			_refToNativeClassInstance = Type.createInstance(Type.resolveClass(nativeInstanceClassName), []);
		}
		else
		{
			// else instantiate it with native PHP method
			// create instanciationString
			var instanciationString:String = 'new ' + nativeInstanceClassName + '();';
			// eval on instanciationString so that nativeInstanceClassName is evaluated correctly
			_refToNativeClassInstance = untyped __call__('eval', 'return ' + instanciationString );
		}
	}
	
}