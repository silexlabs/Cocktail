/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
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
	override private function measureAutoHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		//the height is set to null by default
		style.computedStyle.height = getComputedAutoHeight(style, containingBlockData, fontMetrics);
		
		//left margin
		style.computedStyle.marginTop = 0.0;
		//right margin
		style.computedStyle.marginBottom = 0.0;
	
	}
	
	/**
	 * vertical margins don't apply to non-embedded inline HTMLElements
	 */
	override private function measureHeight(style:CoreStyle, containingBlockData:ContainingBlockData, fontMetrics:FontMetricsData):Void
	{
		//get the computed height in pixel
		style.computedStyle.height = getComputedHeight(style, containingBlockData, fontMetrics);
		
		//left margin
		style.computedStyle.marginTop = 0.0;
		//right margin
		style.computedStyle.marginBottom = 0.0;
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