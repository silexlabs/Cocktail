package cocktailCore.event;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Event 
{
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