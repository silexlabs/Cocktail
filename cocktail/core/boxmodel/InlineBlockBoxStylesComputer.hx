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
import cocktail.css.CSSStyleData;

/**
 * This is the box computer for inlineBlock non-embedded
 * HTMLElement
 * 
 * @author Yannick DOMINGUEZ
 */
class InlineBlockBoxStylesComputer extends BoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * for inlineBlock non-embedded HTMLElements, auto margin compute to 0
	 */
	override private function getComputedAutoMargin(marginStyleValue:CSSPropertyValue, opositeMargin:CSSPropertyValue, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsAndBordersDimension:Float, isHorizontalMargin:Bool):Float
	{
		return 0.0;
	}
}
