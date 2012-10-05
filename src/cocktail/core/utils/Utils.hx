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
	
	public static function clear<T>(array:Array<T>):Void
	{
		#if flash
		untyped array.length = 0;
		#else
		array = [];
		#end
	}
	
}