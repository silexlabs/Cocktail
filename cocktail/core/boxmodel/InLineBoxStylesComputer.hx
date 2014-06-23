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
import cocktail.css.CSSStyleData;

/**
 * The is the box style computer for inline non-embedded
 * HTMLElement, such as a fragment of text
 * 
 * @author Yannick DOMINGUEZ
 */
class InLineBoxStylesComputer extends BoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * vertical margins don't apply to non-embedded inline HTMLElements
	 */
	override private function measureAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		//the height is set to null by default
		var computedHeight:Float = getComputedAutoHeight(style, containingBlockData);
		
		//left margin
		style.usedValues.marginTop = 0.0;
		//right margin
		style.usedValues.marginBottom = 0.0;
	
		return computedHeight;
	}
	
	/**
	 * vertical margins don't apply to non-embedded inline HTMLElements
	 */
	override private function measureHeight(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		//get the computed height in pixel
		var computedHeight:Float = getComputedHeight(style, containingBlockData);
		
		//left margin
		style.usedValues.marginTop = 0.0;
		//right margin
		style.usedValues.marginBottom = 0.0;
		
		return computedHeight;
	}
	
	/**
	 * auto margin compute to 0 for inline non-embedded HTMLElement
	 */
	override private function getComputedAutoMargin(marginStyleValue:CSSPropertyValue, opositeMargin:CSSPropertyValue, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsAndBordersDimension:Float, isHorizontalMargin:Bool):Float
	{	
		return 0.0;
	}
	
	/**
	 * for inline, non embedded HTMLElement, the width doesn't apply
	 */
	override private function getComputedWidth(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		return 0.0;
	}
	
	/**
	 * for inline, non embedded HTMLElement, the height doesn't apply
	 */
	override private function getComputedHeight(style:CoreStyle, containingBlockData:ContainingBlockVO):Float
	{
		return 0.0;
	}

	
}
