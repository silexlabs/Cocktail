/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.style.computer.boxComputers;

import cocktail.core.style.CoreStyle;
import cocktail.core.style.StyleData;
import cocktail.core.unit.UnitManager;
import cocktail.core.font.FontData;

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
	 * vertical paddings don't apply to non-embedded inline HTMLElements
	 */
	override private function measureVerticalPaddings(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		//top
		style.computedStyle.paddingTop = 0;
		//bottom
		style.computedStyle.paddingBottom = 0;
	}
	
	/**
	 * vertical margins don't apply to non-embedded inline HTMLElements
	 */
	override private function measureAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		//the height is set to null by default
		var computedHeight:Float = getComputedAutoHeight(style, containingBlockData, fontMetrics);
		
		//left margin
		style.computedStyle.marginTop = 0.0;
		//right margin
		style.computedStyle.marginBottom = 0.0;
	
		return computedHeight;
	}
	
	/**
	 * vertical margins don't apply to non-embedded inline HTMLElements
	 */
	override private function measureHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		//get the computed height in pixel
		var computedHeight:Float = getComputedHeight(style, containingBlockData, fontMetrics);
		
		//left margin
		style.computedStyle.marginTop = 0.0;
		//right margin
		style.computedStyle.marginBottom = 0.0;
		
		return computedHeight;
	}
	
	/**
	 * auto margin compute to 0 for inline non-embedded HTMLElement
	 */
	override private function getComputedAutoMargin(marginStyleValue:Margin, opositeMargin:Margin, containingHTMLElementDimension:Float, computedDimension:Float, isDimensionAuto:Bool, computedPaddingsDimension:Float, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool):Float
	{	
		return 0.0;
	}
	
	/**
	 * for inline, non embedded HTMLElement, the width doesn't apply
	 */
	override private function getComputedWidth(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		return 0.0;
	}
	
	/**
	 * for inline, non embedded HTMLElement, the height doesn't apply
	 */
	override private function getComputedHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Float
	{
		return 0.0;
	}

	
}