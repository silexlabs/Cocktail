/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.style.computer;

import cocktail.core.style.ComputedStyle;
import cocktail.core.style.CoreStyle;
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
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle:ComputedStyle = style.computedStyle;
		
		//float
		computedStyle.cssFloat = getComputedFloat(style, computedStyle.position);
		
		//display
		computedStyle.display = getComputedDisplay(style, computedStyle.cssFloat, computedStyle.position);
		
		//clear
		computedStyle.clear = getComputedClear(style, computedStyle.position, computedStyle.display);
		
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'float' style which might be affect affected by the 'position'
	 * style, as an absolute positioned htmlElement can't be floated
	 * @param	style
	 * @param	computedPosition the computed value of position, computed before float
	 */
	private static function getComputedFloat(style:CoreStyle, computedPosition:Position):CSSFloat
	{
		var ret:CSSFloat;
		
		//if the htmlElement is absolute or fixed position,
		//it will act as an absolutely positioned htmlElement
		//and won't take the float style into account,
		//so it computes to none
		if (computedPosition == Position.absolute || computedPosition == Position.fixed)
		{
			ret = CSSFloat.none;
		}
		else
		{
			ret = style.cssFloat;
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
	private static function getComputedDisplay(style:CoreStyle, computedFloat:CSSFloat, computedPosition:Position):Display
	{
		var ret:Display;
		
		//if the htmlElement is a float, it can't
		//be an inline level element
		if (computedFloat != CSSFloat.none)
		{
			switch (style.display)
			{
				//for inline level value, default to block
				case cssInline, inlineBlock:
					ret = Display.block;
				
				//the value remains unchanged for other	
				default:
					ret = style.display;
			}	
		}
		//if the htmlElement is absolutely positioned, it can't
		//be inline
		else if (computedPosition == Position.absolute || computedPosition == Position.fixed)
		{
			switch (style.display)
			{
				//for inline level value, default to block
				case cssInline, inlineBlock:
					ret = Display.block;
				
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
	 * htmlElement can clear floats and they must
	 * also be 'in-flow' element (with a 'position' value
	 * of relative or static)
	 * 
	 * @param	style
	 * @param	computedPosition
	 * @param	computedDisplay
	 */
	private static function getComputedClear(style:CoreStyle, computedPosition:Position, computedDisplay:Display):Clear
	{
		var ret:Clear;
		
		if (computedDisplay == Display.cssInline || computedDisplay == Display.inlineBlock)
		{
			ret = Clear.none;
		}
		else if (computedPosition == Position.absolute || computedPosition == Position.fixed)
		{
			ret = Clear.none;
		}
		else
		{
			ret = style.clear;
		}
		
		return ret;
	}
	
}