/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.browser;
import cocktail.core.html.AbstractHTMLInputElement;


/**
 * This is the JavaScript implementation of the text input. Use
 * a native HTML text input
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLInputElement extends AbstractHTMLInputElement
{
	/**
	 * class constructor
	 * @param	nativeElement
	 */
	public function new() 
	{
		super();
	}
	
	/////////////////////////////////
	// OVERRIDEN CHANGE SETTER/GETTER
	/////////////////////////////////
	
	/**
	 * When the user onchange callback is set, set
	 * a native JavaScript listener on the text text
	 * input
	 */
	override private function set_onChange(value:Void->Void):Void->Void
	{
		//first always remove previous listener
		untyped _nativeElement.removeEventListener("change", onNativeChange);
		
		_onChange = value;
		
		//only add listener if user callback is not null
		if (_onChange != null)
		{
			untyped _nativeElement.addEventListener("change", onNativeChange);
		}
		
		return value;
	}
	
	/**
	 * called when a native javascript change event is emitted
	 * by the HTML text input
	 */
	private function onNativeChange(event:Dynamic):Void
	{
		onChangeCallback();
	}
	
	/////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	// overidden to get/set the attribute from the
	// native HTML text input
	/////////////////////////////////
	
	override private function set_disabled(value:Bool):Bool
	{
		untyped _nativeElement.disabled = value;
		return _disabled = value;
	}
	
	override private function set_maxLength(value:Int):Int
	{
		untyped _nativeElement.maxLength = value;
		return _maxLength = value;
	}
	
	override private function set_value(value:String):String
	{
		untyped _nativeElement.value = value;
		return _value = value;
	}
	
	override private function get_value():String
	{
		//update the stored value of the text input when requested
		//as it might have changed meanwhile because of user interaction
		_value = untyped _nativeElement.value;
		return _value;
	}
}