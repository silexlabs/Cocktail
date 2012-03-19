package cocktailCore.event;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class MouseEvent extends UIEvent
{	
	//TODO : add mouse click, remove double click for now ?
	public static inline var MOUSE_UP:String = "mouseup";
	
	public static inline var MOUSE_DOWN:String = "mousedown";
	
	public static inline var MOUSE_OVER:String = "mouseover";
	
	public static inline var MOUSE_OUT:String = "mouseout";
	
	public static inline var DOUBLE_CLICK:String = "dblclick";
	
	public static inline var MOUSE_MOVE:String = "mousemove";
	
	private var _screenX:Float;
	public var screenX(get_screenX, null):Float;
	
	private var _screenY:Float;
	public var screenY(get_screenY, null):Float;
	
	private var _clientX:Float;
	public var clientX(get_clientX, null):Float;
	
	private var _clientY:Float;
	public var clientY(get_clientY, null):Float;
	
	private var _ctrlKey:Bool;
	public var ctrlKey(get_ctrlKey, null):Bool;
	
	private var _shiftKey:Bool;
	public var shiftKey(get_shiftKey, null):Bool;
	
	private var _altKey:Bool;
	public var altKey(get_altKey, null):Bool;
	
	public function new(type:String, screenX:Float, screenY:Float, clientX:Float, clientY:Float, 
	ctrlKey:Bool, shiftKey:Bool, altKey:Bool) 
	{
		super(type);
		
		_screenX = screenX;
		_screenY = screenY;
		_clientX = clientX;
		_clientY = clientY;
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
	
	private function get_clientY():Float 
	{
		return _clientY;
	}
	
	private function get_clientX():Float 
	{
		return _clientX;
	}
	
	private function get_screenX():Float 
	{
		return _screenX;
	}
	
	private function get_screenY():Float 
	{
		return _screenY;
	}
	
}