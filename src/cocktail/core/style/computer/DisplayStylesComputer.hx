/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.style.computer;

import cocktail.core.css.CSSStyleDeclaration;

import cocktail.core.css.CoreStyle;
import cocktail.core.css.CSSData;
import cocktail.core.style.StyleData;

/**
 * This is a static class in charge of
 * computing the styles that affect how a
 * htmlElement will be displayed
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
	 * of another style. For example, an htmlElement which is a float
	 * must have a display of 'block'.
	 * 
	 * Some computed style value are the same as the defined
	 * style values
	 * 
	 * @param	style contain the styles definition of the 
	 * target htmlElement
	 */
	public static function compute(style:CoreStyle):Void
	{
		
		//float
		//style.cssFloat = getComputedFloat(style, style.position);
		
		//display
		//style.display = getComputedDisplay(style, style.cssFloat, style.position);
		
		
	}
	//
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'float' style which might be affect affected by the 'position'
	 * style, as an absolute positioned htmlElement can't be floated
	 * @param	style
	 * @param	computedPosition the computed value of position, computed before float
	 */
	public static function getComputedFloat(style:CoreStyle, computedPosition:CSSPropertyValue):CSSPropertyValue
	{
		var ret:CSSPropertyValue = style.cssFloat;
		
		switch(computedPosition)
		{
			case CSSPropertyValue.KEYWORD(value):
				switch (value)
				{
					//if the htmlElement is absolute or fixed position,
					//it will act as an absolutely positioned htmlElement
					//and won't take the float style into account,
					//so it computes to none
					case CSSKeywordValue.ABSOLUTE, CSSKeywordValue.FIXED:
						ret = CSSPropertyValue.KEYWORD(CSSKeywordValue.NONE);
						
					default:
				}
				
			default:	
		}
		
		return ret;
	}
	
	/**
	 * Compute the 'display' style which might be affected by
	 * the defined 'float' style
	 * 
	 * @param	style
	 * @param	computedFloat the computed value of the float which must be computed before this
	 * one
	 * @param computedPosition the computed value of the position which must be computed before
	 * this one
	 */
	public static function getComputedDisplay(style:CoreStyle, computedFloat:CSSPropertyValue, computedPosition:CSSPropertyValue):CSSPropertyValue
	{
		var ret:CSSPropertyValue = style.specifiedValues.getTypedProperty("display").typedValue;
		
		if (style.isNone(computedFloat) == false)
		{
			//TODO : should be specified style ?
			switch (style.specifiedValues.getTypedProperty("display").typedValue)
			{
				case KEYWORD(value):
					switch(value)
					{
						case INLINE, INLINE_BLOCK:
							ret = KEYWORD(BLOCK);
							
						default:	
					}
				default:
			}	
		}
		else
		{
			switch(computedPosition)
			{
				case KEYWORD(value):
					switch(value)
					{
						case FIXED, ABSOLUTE:
							//TODO : should be specified style ?
							switch (style.specifiedValues.getTypedProperty("display").typedValue)
							{
								case KEYWORD(value):
									switch(value)
									{
										case INLINE, INLINE_BLOCK:
											ret = KEYWORD(BLOCK);
											
										default:
											
									}
								default:
							}	
							
						default:	
					}
				default:	
			}
		}
		
		return ret;
	}
}