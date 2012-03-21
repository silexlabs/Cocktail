package core.html;
import core.HTMLElement;

/**
 * Form control.
 * 
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
	 * The control is unavailable in this context.
	 */
	private var _disabled:Bool;
	public var disabled(getDisabled, setDisabled):Bool;
	
	/**
	 * Maximum number of characters for text fields, when type 
	 * has the value "text" or "password".
	 */
	private var _maxLength:Int;
	public var maxLength(getMaxLength, setMaxLength):Int;
	
	/**
	 * When the type attribute of the element has the value "text",
	 * "file" or "password", this represents the current contents
	 * of the corresponding form control, in an interactive user
	 * agent. Changing this attribute changes the contents of the
	 * form control, but does not change the value of the HTML
	 * value attribute of the element. When the type attribute
	 * of the element has the value "button", "hidden", "submit",
	 * "reset", "image", "checkbox" or "radio", this represents 
	 * the HTML value attribute of the element.
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