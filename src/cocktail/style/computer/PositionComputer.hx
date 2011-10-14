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
		
		computedStyle.position = style.position;
		computedStyle.display = style.display;
		computedStyle.float = style.float;
		computedStyle.clear = style.clear;
		
		return computedStyle;
	}
	
}