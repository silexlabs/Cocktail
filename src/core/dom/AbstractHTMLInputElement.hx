package core.dom;
import core.HTMLElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractHTMLInputElement extends HTMLElement
{


	/**
	 * This callback is called when the text input loses
	 * focus if the value of the text input changed
	 */
	private var _onChange:Void->Void;
	public var onChange(getOnChange, setOnChange):Void->Void;
	
	/**
	 * enable/disable the text input
	 */
	private var _disabled:Bool;
	public var disabled(getDisabled, setDisabled):Bool;
	
	/**
	 *set/get the max number of charachters the text
	 * input can hold
	 */
	private var _maxLength:Int;
	public var maxLength(getMaxLength, setMaxLength):Int;
	
	/**
	 * set/get the current text value of the text input
	 */
	private var _value:String;
	public var value(getValue, setValue):String;
	
	/**
	 * class constructor. Create a native text input
	 * if none is provided
	 */
	public function new() 
	{
		super();
	}
	
	/////////////////////////////////
	// OVERRIDEN INIT METHODS
	/////////////////////////////////
	
	/**
	 * init text input class attributes
	 * 
	 * TODO : init maxLength ? what is the default
	 * value, null ?
	 */
	override private function init():Void
	{	
		super.init();
		
		_disabled = false;
		_value = "";
	}
	
	/**
	 * init the style of the text input
	 * 
	 * TODO : implement a separate style
	 * for form control ?
	 */
	override private function initStyle():Void
	{
		_style = new EmbeddedStyle(this);
	}
	
	
	/////////////////////////////////
	// CHANGE SETTER/GETTER
	/////////////////////////////////
	
	private function setOnChange(value:Void->Void):Void->Void
	{
		return _onChange = value;
	}
	
	private function getOnChange():Void->Void
	{
		return _onChange;
	}
	
	/**
	 * called when a native change event is
	 * emitted, called the user on change
	 * callback if any
	 */
	private function onChangeCallback():Void
	{
		if (_onChange != null)
		{
			_onChange();
		}
	}
	
	/////////////////////////////////
	// SETTER/GETTER
	/////////////////////////////////
	
	private function setDisabled(value:Bool):Bool
	{
		return _disabled = value;
	}
	
	private function getDisabled():Bool
	{
		return _disabled;
	}
	
	private function setMaxLength(value:Int):Int
	{
		return _maxLength = value;
	}
	
	private function getMaxLength():Int
	{
		return _maxLength;
	}
	
	private function setValue(value:String):String
	{
		return _value = value;
	}
	
	private function getValue():String
	{
		return _value;
	}
	
}