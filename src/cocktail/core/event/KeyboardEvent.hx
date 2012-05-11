package cocktail.core.event;
import cocktail.core.html.HTMLElement;

/**
 * The KeyboardEvent interface provides specific contextual information associated with
 * keyboard devices. Each keyboard event references a key using a value.
 * Keyboard events are commonly directed at the element that has the focus.
 * 
 * The KeyboardEvent interface provides convenient attributes for some common
 * modifiers keys: KeyboardEvent.ctrlKey, KeyboardEvent.shiftKey, KeyboardEvent.altKey,
 * KeyboardEvent.metaKey. These attributes are equivalent to using the method
 * KeyboardEvent.getModifierState(keyArg) with 'Control', 'Shift', 'Alt', or 'Meta' respectively.
 * 
 * @author Yannick DOMINGUEZ
 */
class KeyboardEvent extends UIEvent
{
	
	//TODO : add keypress
	public static inline var KEY_DOWN:String = "keydown";
	
	public static inline var KEY_UP:String = "keyup";
	
	/**
	 * char holds the character value of the key pressed.
	 * 
	 * TODO : should be named char but prevent cpp
	 * compilation
	 */
	private var _keyChar:String;
	public var keyChar(get_keyChar, null):String;
	
	/**
	 * key holds the key value of the key pressed.
	 */
	private var _key:String;
	public var key(get_key, null):String;
	
	/**
	 * true if the 'Ctrl' (control) key modifier was active.
	 */
	private var _ctrlKey:Bool;
	public var ctrlKey(get_ctrlKey, null):Bool;
	
	/**
	 * true if the shift (Shift) key modifier was active.
	 */
	private var _shiftKey:Bool;
	public var shiftKey(get_shiftKey, null):Bool;
	
	/**
	 * true if the 'Alt' (alternative) or 'Option' key modifier was active.
	 */
	private var _altKey:Bool;
	public var altKey(get_altKey, null):Bool;
	
	
	public function new(type:String, target:HTMLElement, detail:Float, keyChar:String, key:String, ctrlKey:Bool, shiftKey:Bool, altKey:Bool) 
	{
		super(type, target, detail);
		
		_keyChar = keyChar;
		_key = key;
		_ctrlKey = ctrlKey;
		_shiftKey = shiftKey;
		_altKey = altKey;   
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
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
	
	private function get_keyChar():String 
	{
		return _keyChar;
	}
	
	private function get_key():String 
	{
		return _key;
	}
	
	
	
}