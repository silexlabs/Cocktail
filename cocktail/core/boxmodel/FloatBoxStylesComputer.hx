/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.boxmodel;

import cocktail.core.css.CoreStyle;
import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSValueConverter;
import cocktail.core.font.FontData;

/**
 * this is the box computer for floated non-embedded HTMLElement
 * such as a floated ContainerHTMLElement.
 * 
 * @author Yannick DOMINGUEZ
 */
class FloatBoxStylesComputer extends InlineBlockBoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * for floated non-embedded HTMLElements, an auto width is computed as 'shrink-to-fit' once all the children
	 * have been laid out
	 */
	override private function getComputedAutoWidth(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		return 0.0;
	}

}