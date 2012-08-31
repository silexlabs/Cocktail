/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.style.computer.boxComputers;

/**
 * This is the box computer for floated embedded htmlElement,
 * such as a floated ImagdHTMLElement. It behaves the same
 * as the box computer for inline embedded htmlElement
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedFloatBoxStylesComputer extends EmbeddedInlineBoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
}