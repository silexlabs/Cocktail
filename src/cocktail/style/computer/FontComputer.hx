package cocktail.style.computer;
import cocktail.style.abstract.AbstractStyle;
import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class FontComputer 
{

	public function new() 
	{
		
	}
	
	public static function compute(style:AbstractStyle):Void
	{
		var computedStyle = style.computedStyle;
		
		computedStyle.fontSize = getComputedFontSize(style);
		
		computedStyle.lineHeight = getComputedLineHeight(style);
		
	}
	
	private static function getComputedLineHeight(style:AbstractStyle):Float
	{
		var lineHeight:Float;
		
		switch (style.lineHeight)
		{
			case length(unit):
				lineHeight = getValueFromLength(unit);
		}
		
		return lineHeight;
	}
	
	private static function getComputedFontSize(style:AbstractStyle):Float
	{
		var fontSize:Float;
		
		switch (style.fontSize)
		{
			case length(unit):
				fontSize = getValueFromLength(unit);
				
		}
		
		return fontSize;
	}
	
	private static function getValueFromLength(length:LengthValue):Float
	{
		var lengthValue:Float;
		
		switch (length)
		{
			case px(value):
				lengthValue = value;
				
			case mm(value):
				lengthValue = (value * ((72 * (1 / 0.75)) / 2.54)) / 10;
				
			case cm(value):
				lengthValue = value * ((72 * (1/0.75)) / 2.54);
				
			case pt(value):
				lengthValue = value * 1/0.75;	
				
			case _in(value):
				lengthValue = value * (72 * (1/0.75));
				
			case pc(value):
				lengthValue = value * (12 * (1/0.75));	
		}
		
		return lengthValue;
	}
	
}