/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer.boxComputers;
import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.computer.BoxStylesComputer;
import cocktail.style.StyleData;

/**
 * This is the box computer for inlineBlock non-embedded
 * DOMElement
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
	 * for inlineBlock non-embedded DOMElements, auto margin compute to 0
	 */
	override private function getComputedAutoMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool = false ):Int
	{
		return 0;
	}
	
	/**
	 * if the width is set to 'auto', then this method is called once all the children
	 * of the inlineBlock are laid out
	 */
	override public function shrinkToFit(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData, minimumWidth:Int):Int
	{
		var shrinkedWidth:Int;
		
		//if the minimum width that must use the inlineBlock
		//is not superior to the width of the containing
		//DOMElement, use the minimum width
		if (minimumWidth < containingDOMElementData.width)
		{
			shrinkedWidth = minimumWidth;
		}
		else
		{
			shrinkedWidth = containingDOMElementData.width;
		}
		
		return shrinkedWidth;
	}
	
}