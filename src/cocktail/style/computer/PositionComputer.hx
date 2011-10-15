package cocktail.style.computer;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.Style;
import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class PositionComputer 
{

	public function new() 
	{
		
	}
	
	public static function compute(style:AbstractStyle):ComputedStyleData
	{
		var computedStyle = style.computedStyle;
		
		computedStyle.position = getComputedPosition(style);
		
		computedStyle.float = getComputedFloat(style, computedStyle.position);
		
		computedStyle.display = getComputedDisplay(style, computedStyle.float);
		
		computedStyle.clear = getComputedClear(style, computedStyle.position, computedStyle.display);
		
		return computedStyle;
	}
	
	private static function getComputedPosition(style:AbstractStyle):PositionStyleValue
	{
		return style.position;
	}
	
	private static function getComputedDisplay(style:AbstractStyle, computedFloat:FloatStyleValue):DisplayStyleValue
	{
		var ret:DisplayStyleValue;
		
		if (computedFloat != FloatStyleValue.none)
		{
			switch (style.display)
			{
				case _inline, inlineBlock:
					ret = DisplayStyleValue.block;
					
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
	
	private static function getComputedFloat(style:AbstractStyle, computedPosition:PositionStyleValue):FloatStyleValue
	{
		var ret:FloatStyleValue;
		
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