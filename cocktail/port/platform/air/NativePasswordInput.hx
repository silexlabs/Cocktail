/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.air;
import cocktail.core.html.HTMLElement;

/**
 * This is the air port of for the native password input,
 * similar to an air stage text
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
		_stageText.displayAsPassword = true;
	}
}