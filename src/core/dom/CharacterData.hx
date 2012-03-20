package core.dom;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CharacterData extends Node
{

	private var _data:String;
	public var data(get_data, set_data):String;
	
	public function new() 
	{
		super();
	}
	
	private function get_data():String 
	{
		return _data;
	}
	
	private function set_data(value:String):String 
	{
		return _data = value;
	}
}