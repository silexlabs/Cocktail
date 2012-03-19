/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.domElement.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.nativeElement.NativeElementManager;
import cocktailCore.style.EmbeddedStyle;

#if (flash9 || cpp || nme)
import cocktailCore.domElement.as3.DOMElement;
#elseif js
import cocktailCore.domElement.js.DOMElement;
#end

/**
 * This DOMElement is a one line form text input
 * 
 * @author Yannick DOMINGUEZ
 */
class AbstractTextInputDOMElement extends DOMElement
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
	public function new(nativeElement:NativeElement = null) 
	{
		if (nativeElement == null)
		{
			nativeElement = NativeElementManager.createNativeElement(textInput);
		}
		
		super(nativeElement);
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
	
	/**
	 * TextInputDOMElement are tab enabled by default
	 */
	override private function initFocus():Void
	{
		super.initFocus();
		_tabEnabled = true;
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