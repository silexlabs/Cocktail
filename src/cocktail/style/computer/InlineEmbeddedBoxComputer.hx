/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.computer;
import cocktail.domElement.EmbeddedDOMElement;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.computer.BlockEmbeddedBoxComputer;
import cocktail.style.computer.BlockEmbeddedBoxComputer;
import cocktail.style.StyleData;
import cocktail.unit.UnitManager;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class InlineEmbeddedBoxComputer extends BlockEmbeddedBoxComputer
{
	private static var NULL:Int = -1;

	public function new() 
	{
		super();
	}
	
	override private function getComputedMargin(marginStyleValue:MarginStyleValue, opositeMarginStyleValue:MarginStyleValue, containingDOMElementDimension:Int, computedDimension:Int, isDimensionAuto:Bool, computedPaddingsDimension:Int, fontSize:Float, xHeight:Float, isHorizontalMargin:Bool = false ):Int
	{
		//the return value
		var computedMargin:Int;
		
		//check which type of value is defined
		switch (marginStyleValue)
		{
			//it's a length (an absolute value
			//with a unit)
			case length(value):
				computedMargin = UnitManager.getPixelFromLengthValue(value, fontSize, xHeight);
			
			//It's a percentage, compute it from the containing dimension
			case percent(value): 
				
				//margin default to 0 if containing dimension is undefined
				if (containingDOMElementDimension == NULL)
				{
					computedMargin = 0;
				}
				else
				{
					computedMargin = Math.round(UnitManager.getPixelFromPercent(value, containingDOMElementDimension));
				}
			
			case auto:	
				computedMargin = 0;
		}
		
		return computedMargin;
	}
	
}