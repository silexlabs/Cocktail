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