/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.nativeInstance;

import cocktail.classInstance.ClassInstance;

/**
 * This class exposes static method used to get instances of native class.
 * Those native class instance are wrapped in a ClassInstance object abstracting
 * instance manipulation
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeInstanceManager
{
	/**
	 * Private constructor. This class is meant to be accessed only
	 * through it's static methods
	 */
	private function new()
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Static instantiation methods. This is the recommended method to instantiate a ClassInstance
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Intantiate a native class with it's name and wrap it in a
	 * ClassInstance object
	 * @param	className the name of the native class to instantiate
	 * @return  a ClassInstance object
	 */
	public static function getClassInstanceByClassName(className:String):ClassInstance
	{
		return new ClassInstance(className);
	}
	
	/**
	 * Instantiate a native class from a class reference and wrap it in a 
	 * ClassInstance  object
	 * @param	classReference the class reference to instantiate
	 * @return a ClassInstance object
	 */
	public static function createInstanceOf(classReference:Class<Dynamic>):ClassInstance
	{
		return getClassInstanceByClassName(Type.getClassName(classReference));
	}
}