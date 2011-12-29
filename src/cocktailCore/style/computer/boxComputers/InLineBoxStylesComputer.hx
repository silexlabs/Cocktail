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
import cocktailCore.unit.UnitManager;

/**
 * The is the box style computer for inline non-embedded
 * DOMElement, such as a fragment of text
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
	 * auto margin compute to 0 for inline non-embedded DOMElement
	 */
	override private function getComputedAutoMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool = false ):Int
	{	
		return 0;
	}
	
	/**
	 * for inline, non embedded DOMElement, the width doesn't apply
	 */
	override private function getComputedWidth(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return 0;
	}
	
	/**
	 * for inline, non embedded DOMElement, the height doesn't apply
	 */
	override private function getComputedHeight(style:AbstractStyle, containingDOMElementData:ContainingDOMElementData):Int
	{
		return 0;
	}

	
}