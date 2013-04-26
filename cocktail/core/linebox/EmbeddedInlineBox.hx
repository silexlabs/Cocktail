/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.linebox;

import cocktail.core.renderer.ElementRenderer;

/**
 * An inline box wrapping an embedded element, such as a
 * picture 
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedInlineBox extends InlineBox
{

	public function new(elementRenderer:ElementRenderer, leadedAscent:Float, leadedDescent:Float) 
	{
		super(elementRenderer, leadedAscent, leadedDescent);
		isEmbedded = true;
	}
}