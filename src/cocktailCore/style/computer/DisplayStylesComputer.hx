/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.style.computer;

import cocktailCore.style.abstract.AbstractStyle;
import cocktailCore.style.Style;
import cocktail.style.StyleData;

/**
 * This is a static class in charge of
 * computing the styles that affect how a
 * DOMElement will be displayed
 * 
 * @author Yannick DOMINGUEZ
 */
class DisplayStylesComputer 
{
	/**
	 * Class contructor. Private, as
	 * this class is meant to be accessed
	 * through its public static methods
	 */
	private function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute all the styles affecting display by applying CSS
	 * rules. Each of this style might affect the computed value
	 * of another style. For example, a DOMElement which is a float
	 * must have a display of 'block'.
	 * 
	 * Some computed style value are the same as the defined
	 * style values
	 * 
	 * @param	style contain the styles definition of the 
	 * target DOMElement
	 */
	public static function compute(style:AbstractStyle):Void
	{
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle:ComputedStyleData = style.computedStyle;
		
		//position
		computedStyle.position = getComputedPosition(style);
		
		//float
		computedStyle.floatValue = getComputedFloat(style, computedStyle.position);
		
		//display
		computedStyle.display = getComputedDisplay(style, computedStyle.floatValue);
		
		//clear
		computedStyle.clear = getComputedClear(style, computedStyle.position, computedStyle.display);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'position' style. It is the same as the defined style
	 * as no other style can affect the computed 'position' style value
	 */
	private static function getComputedPosition(style:AbstractStyle):PositionStyleValue
	{
		return style.position;
	}
	
	/**
	 * Compute the 'float' style which might be affect affected by the 'position'
	 * style, as an absolute positioned DOMElement can't be floated
	 * @param	style
	 * @param	computedPosition the computed value of position, computed before float
	 */
	private static function getComputedFloat(style:AbstractStyle, computedPosition:PositionStyleValue):FloatStyleValue
	{
		var ret:FloatStyleValue;
		
		//if the DOMElement is absolute or fixed position,
		//it will act as an absolutely positioned DOMElement
		//and won't take the float style into account,
		//so it computes to none
		if (computedPosition == PositionStyleValue.absolute || computedPosition == PositionStyleValue.fixed)
		{
			ret = FloatStyleValue.none;
		}
		else
		{
			ret = style.floatValue;
		}
		
		return ret;
	}
	
	/**
	 * Compute the 'display' style which might be affected by
	 * the defined 'float' style
	 * @param	style
	 * @param	computedFloat the computed value of the float which must be computed before this
	 * one
	 */
	private static function getComputedDisplay(style:AbstractStyle, computedFloat:FloatStyleValue):DisplayStyleValue
	{
		var ret:DisplayStyleValue;
		
		//if the DOMElement is a float, it can't
		//be an inline level element
		if (computedFloat != FloatStyleValue.none)
		{
			switch (style.display)
			{
				//for inline level value, default to block
				case inlineStyle, inlineBlock:
					ret = DisplayStyleValue.block;
				
				//the value remains unchanged for other	
				default:
					ret = style.display;
			}	
		}
		else
		{
			ret = style.display;
		}
		
		return ret;
	}
	
	/**
	 * Compute the clear style which might be affected by 
	 * the display and position style. Only block level
	 * DOMElement can clear floats and they must
	 * also be 'in-flow' element (with a 'position' value
	 * of relative or static)
	 * 
	 * @param	style
	 * @param	computedPosition
	 * @param	computedDisplay
	 */
	private static function getComputedClear(style:AbstractStyle, computedPosition:PositionStyleValue, computedDisplay:DisplayStyleValue):ClearStyleValue
	{
		var ret:ClearStyleValue;
		
		if (computedDisplay == DisplayStyleValue.inlineStyle || computedDisplay == DisplayStyleValue.inlineBlock)
		{
			ret = ClearStyleValue.none;
		}
		else if (computedPosition == PositionStyleValue.absolute || computedPosition == PositionStyleValue.fixed)
		{
			ret = ClearStyleValue.none;
		}
		else
		{
			ret = style.clear;
		}
		
		return ret;
	}
	
}