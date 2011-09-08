/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.nativeClass;

/**
 * Set the right runtime specific NativeInstance at compile-time
 */
#if flash9
typedef NativeInstance =  cocktail.nativeClass.as3.NativeInstance;

#elseif js
typedef NativeInstance =  cocktail.nativeClass.js.NativeInstance;

#elseif php
typedef NativeInstance =  cocktail.nativeClass.php.NativeInstance;

#else
	#error
#end

/**
 * This class exposes static method used to get instances of native class instance.
 * Those native class instance are wrapped in a NativeInstance object abstracting
 * instance manipulation
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeClass
{
	/**
	 * Private constructor. This class is meant to be accessed only
	 * through it's static methods
	 */
	private function new()
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Static instantiation methods. This is the recommended method to instantiate a NativeInstance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Intantiate a native class with it's name and wrap it in a
	 * NativeInstance object
	 * @param	className the name of the native class to instantiate
	 * @return  a NativeInstance object
	 */
	public static function getNativeInstanceByClassName(className:String):NativeInstance
	{
		return new NativeInstance(className);
	}
	
	/**
	 * Instantiate a native class from a class reference and wrap it in a 
	 * NativeInstance  object
	 * @param	classReference the class reference to instantiate
	 * @return a NativeInstance object
	 */
	public static function createInstanceOf(classReference:Class<Dynamic>):NativeInstance
	{
		return getNativeInstanceByClassName(Type.getClassName(classReference));
	}
}