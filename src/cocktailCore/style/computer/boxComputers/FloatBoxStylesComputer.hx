/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer.boxComputers;

import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktail.style.StyleData;
import cocktailCore.style.StyleData;
import cocktailCore.unit.UnitManager;

/**
 * this is the box computer for floated non-embedded DOMElement
 * such as a floated ContainerDOMElement
 * 
 * @author Yannick DOMINGUEZ
 */
class FloatBoxStylesComputer extends BoxStylesComputer
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	/**
	 * for floated non-embedded DOMElements, auto margin compute to 0
	 */
	override private function getComputedAutoMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool = false ):Int
	{
		return 0;
	}
	
	/**
	 * for floated non-embedded DOMElements, an auto width is computed as 'shrink-to-fit' once all the children
	 * have been laid out
	 */
	override private function getComputedAutoWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return 0;
	}
	
	override public function shrinkToFit(computedStyles:ComputedStyleData, availableWidth:Int, minimumWidth:Int):Int
	{
		var shrinkedWidth:Int;
		
		if (minimumWidth < availableWidth)
		{
			shrinkedWidth = minimumWidth;
		}
		else
		{
			shrinkedWidth = availableWidth;
		}
		
		return shrinkedWidth;
	}
	

	
	
	
}