package core.event;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class KeyboardEvent extends UIEvent
{
	
	//TODO : add keypress
	public static inline var KEY_DOWN:String = "keydown";
	
	public static inline var KEY_UP:String = "keyup";

	
	//TODO : should be String
	private var _char:Int;
	public var char(get_char, null):Int;
	
	//TODO : should be String
	private var _key:Int;
	public var key(get_key, null):Int;
	
	private var _ctrlKey:Bool;
	public var ctrlKey(get_ctrlKey, null):Bool;
	
	private var _shiftKey:Bool;
	public var shiftKey(get_shiftKey, null):Bool;
	
	private var _altKey:Bool;
	public var altKey(get_altKey, null):Bool;
	
	
	public function new(type:String, char:Int, key:Int, ctrlKey:Bool, shiftKey:Bool, altKey:Bool) 
	{
		super(type);
		
		_char = char;
		_key = key;
		_ctrlKey = ctrlKey;
		_shiftKey = shiftKey;
		_altKey = altKey;   
	}
	
	private function get_altKey():Bool 
	{
		return _altKey;
	}
	
	private function get_shiftKey():Bool 
	{
		return _shiftKey;
	}
	
	private function get_ctrlKey():Bool 
	{
		return _ctrlKey;
	}
	
	private function get_char():Int 
	{
		return _char;
	}
	
	private function get_key():Int 
	{
		return _key;
	}
	
	
	
}