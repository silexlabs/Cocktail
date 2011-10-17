package cocktail.style.computer;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.Style;
import cocktail.style.StyleData;

/**
 * This is a static class in charge of
 * computing the styles that affect how a
 * DOMElement will be laid out
 * 
 * @author Yannick DOMINGUEZ
 */

class PositionComputer 
{
	/**
	 * Class contructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute all the styles affecting layout by appliying CSS
	 * rules. Each of this style might affect the computed value
	 * of another style. For example, a DOMElement which is a float
	 * must have a display of 'block'
	 * 
	 * @param	style contain the styles definition of the 
	 * target DOMElement
	 * @return
	 */
	public static function compute(style:AbstractStyle):Void
	{
		//get a reference to the computed style structure
		//holding the used style value (the ones actually used)
		var computedStyle = style.computedStyle;
		
		//position
		computedStyle.position = getComputedPosition(style);
		
		//float
		computedStyle.float = getComputedFloat(style, computedStyle.position);
		
		//display
		computedStyle.display = getComputedDisplay(style, computedStyle.float);
		
		//clear
		computedStyle.clear = getComputedClear(style, computedStyle.position, computedStyle.display);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE STATIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Compute the 'position" style. It is the same as the defined style
	 * as no other style can affect the computed 'position' style value
	 */
	private static function getComputedPosition(style:AbstractStyle):PositionStyleValue
	{
		return style.position;
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
				case _inline, inlineBlock:
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
			ret = style.float;
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
		
		if (computedDisplay == DisplayStyleValue._inline || computedDisplay == DisplayStyleValue.inlineBlock)
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