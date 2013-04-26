/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;
import cocktail.core.html.HTMLElement;
import cocktail.port.NativePasswordInput;

/**
 * This is an input renderer in charge of
 * rendering a password form control, very
 * similar to regualr text input renderer
 * 
 * @author Yannick DOMINGUEZ
 */
class PasswordInputRenderer extends TextInputRenderer
{
	/**
	 * class constructor
	 * @param	node
	 */
	public function new(node:HTMLElement) 
	{
		super(node);
	}
	
	/**
	 * Instantiate a password native input
	 */
	override private function createNativeInput():Void
	{
		nativeTextInput = new NativePasswordInput(domNode);
		nativeInput = nativeTextInput;
	} 
}