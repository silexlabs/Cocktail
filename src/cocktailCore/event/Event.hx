package cocktailCore.event;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Event 
{
	public static inline var SCROLL:String = "scroll";
	
	public static inline var LOAD:String = "load";
	
	//TODO : add target and current target
	
	private var _type:String;
	public var type(get_type, null):String;
	
	public function new(type:String) 
	{
		_type = type;
	}
	
	private function get_type():String 
	{
		return _type;
	}
}