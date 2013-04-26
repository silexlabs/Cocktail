/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.NativeInputBase;

/**
 * This is the flash port of for the native button.
 * 
 * note : this is one possible implementation of a button
 * for flash. The idea here, is to set the inner html of
 * the input to the value, this way the button can be entirely
 * styled in CSS. An alternative solution might be to use 
 * a true flash button and attach it to the display list
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeButton extends NativeInputBase
{
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	override private function set_value(textValue:String):String 
	{
		_node.innerHTML = textValue;
		return textValue;
	}
}