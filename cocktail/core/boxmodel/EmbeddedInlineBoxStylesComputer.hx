/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.boxmodel;

import cocktail.core.layout.LayoutData;
import cocktail.core.css.CSSValueConverter;
import cocktail.css.CSSStyleData;

/**
 * This is the box computer for inline embedded HTMLElement,
 * such as for instance an ImageHTMLElement inserted in a
 * text
 * 
 * @author Yannick DOMINGUEZ
 */
class EmbeddedInlineBoxStylesComputer extends EmbeddedBlockBoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * for inline embedded HTMLElement, auto margins compute to 0
	 */
	override private function getComputedAutoMargin(marginStyleValue:CSSPropertyValue, opositeMargin:CSSPropertyValue, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsAndBordersDimension:Float, isHorizontalMargin:Bool):Float
	{
		return 0.0;
	}
	
}
