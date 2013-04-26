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

/**
 * This is the flash port of for the native password input,
 * similar to flahs native text input
 * 
 * @author Yannick DOMINGUEZ
 */
class NativePasswordInput extends NativeTextInput
{
	/**
	 * class constructor
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
		_textField.displayAsPassword = true;
	}
}