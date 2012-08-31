/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.renderer;

/**
 * 
 * A special case of EmbeddedLineBox which
 * wraps an ElementRenderer displayed as InlineBlock
 * 
 * TODO 4 : is it really useful ? EmbeddedLineBox might
 * be able to differientate with establishesNewFormattingContext
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBlockLineBox extends EmbeddedLineBox
{

	/**
	 * class cosntructor
	 */
	public function new(elementRenderer:ElementRenderer) 
	{
		super(elementRenderer);
	}
	
	//TODO 2 : should return ascent to the last line, if the inline block
	//establishes an inline formatting context
	override private function get_leadedAscent():Float 
	{
		return bounds.height + _elementRenderer.coreStyle.computedStyle.marginTop + _elementRenderer.coreStyle.computedStyle.marginBottom;
	}
	
}