/*This file is part of Silex - see http://projects.silexlabs.org/?/silex

Silex is © 2010-2011 Silex Labs and is released under the GPL License:

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.style.computer.boxComputers;

import cocktail.style.abstract.AbstractStyle;
import cocktail.style.computer.BoxStylesComputer;
import cocktail.style.StyleData;
import cocktail.unit.UnitManager;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */
class FloatBoxStylesComputer extends BoxStylesComputer
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
	

	override private function getComputedAutoHeight(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensionsData):Int
	{
		//TO DO : In certain cases (see, e.g., sections 10.6.4 and 10.6.6 above), the height of an element that establishes 
		//a block formatting context is computed as follows:If it only has inline-level children, the height is the distance
		//between the top of the topmost line box and the bottom of the bottommost line box. If it has block-level children, 
		//the height is the distance between the top margin-edge of the topmost block-level child box and the bottom margin-edge
		//of the bottommost block-level child box. Absolutely positioned children are ignored, and relatively positioned
		//boxes are considered without their offset. Note that the child box may be an anonymous block box. In addition,
		//if the element has any floating descendants whose bottom margin edge is below the element's bottom content edge,
		//then the height is increased to include those edges. Only floats that participate in this block formatting context
		//are taken into account, e.g., floats inside absolutely positioned descendants or other floats are not. 
		
		return 0;
	}
	
	
	
	override private function getComputedAutoWidth(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensionsData):Int
	{
		//TO DO : If 'width' is computed as 'auto', the used value is the "shrink-to-fit" width. Calculation
		//of the shrink-to-fit width is similar to calculating the width of a table cell using the automatic
		//table layout algorithm. Roughly: calculate the preferred width by formatting the content without
		//breaking lines other than where explicit line breaks occur, and also calculate the preferred minimum 
		//width, e.g., by trying all possible line breaks. CSS 2.1 does not define the exact algorithm. Thirdly,
		//find the available width: in this case, this is the width of the containing block minus the used values
		//of 'margin-left', 'border-left-width', 'padding-left', 'padding-right', 'border-right-width',
		//'margin-right', and the widths of any relevant scroll bars. Then the shrink-to-fit width is:
		//min(max(preferred minimum width, available width), preferred width).
		
		return 0;
	}
	
	
}