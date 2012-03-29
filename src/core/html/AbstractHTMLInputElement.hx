/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package core.html;


#if (flash9 || cpp || nme)
import port.flash_player.HTMLElement;

#elseif js
import port.browser.HTMLElement;

#end

/**
 * Form control.
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractHTMLInputElement extends HTMLElement
{

	/**
	 * the html tag name for a form input
	 */
	private static inline var HTML_INPUT_TAG_NAME:String = "input";
	
	
	/**
	 * This callback is called when the text input loses
	 * focus if the value of the text input changed
	 */
	private var _onChange:Void->Void;
	public var onChange(get_onChange, set_onChange):Void->Void;
	
	/**
	 * The control is unavailable in this context.
	 */
	private var _disabled:Bool;
	public var disabled(get_disabled, set_disabled):Bool;
	
	/**
	 * Maximum number of characters for text fields, when type 
	 * has the value "text" or "password".
	 */
	private var _maxLength:Int;
	public var maxLength(get_maxLength, set_maxLength):Int;
	
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
	public var value(get_value, set_value):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTML_INPUT_TAG_NAME);
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
	
	private function set_onChange(value:Void->Void):Void->Void
	{
		return _onChange = value;
	}
	
	private function get_onChange():Void->Void
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
	
	private function set_disabled(value:Bool):Bool
	{
		return _disabled = value;
	}
	
	private function get_disabled():Bool
	{
		return _disabled;
	}
	
	private function set_maxLength(value:Int):Int
	{
		return _maxLength = value;
	}
	
	private function get_maxLength():Int
	{
		return _maxLength;
	}
	
	private function set_value(value:String):String
	{
		return _value = value;
	}
	
	private function get_value():String
	{
		return _value;
	}
	
}