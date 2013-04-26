/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.utils;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Utils 
{

	public function new() 
	{
		
	}
	
	public static function clear<T>(array:Array<T>):Array<T>
	{
		#if flash
		untyped array.length = 0;
		#else
		array = [];
		#end
		return array;
	}
	
}