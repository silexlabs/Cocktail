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
		
		computedStyle.fontWeight = getComputedFontWeight(style);
		
		computedStyle.fontStyle = getComputedFontStyle(style);
		
		computedStyle.fontFamily = getComputedFontFamily(style);
		
		computedStyle.fontVariant = getComputedFontVariant(style);
		
		computedStyle.textTransform = getComputedTextTransform(style);
		
		computedStyle.letterSpacing = getComputedLetterSpacing(style);
		
		computedStyle.wordSpacing = getComputedWordSpacing(style);
		
		computedStyle.color = getComputedColor(style);
		
	}
	
	private static function getComputedColor(style:AbstractStyle):Int
	{
		
	}
	
	private static function getComputedWordSpacing(style:AbstractStyle):Int
	{
		var wordSpacing:Int;
		
		switch (style.wordSpacing)
		{
			case normal:
				wordSpacing = 0;
				
			case length(unit):
				wordSpacing = Math.round(getValueFromLength(unit));
		}
		
		return wordSpacing;
	}
	
	private static function getComputedLineHeight(style:AbstractStyle):Float
	{
		var lineHeight:Float;
		
		switch (style.lineHeight)
		{
			case length(unit):
				lineHeight = getValueFromLength(unit);
				
			case normal:
				lineHeight = style.computedStyle.fontSize * 1.2;
				
			case percentage(value):
				lineHeight = style.computedStyle.fontSize * (value / 100);
				
			case number(value):
				lineHeight = style.computedStyle.fontSize * value;
		}
		
		return lineHeight;
	}
	
	private static function getComputedLetterSpacing(style:AbstractStyle):Int
	{
		var letterSpacing:Int;
		
		switch (style.letterSpacing)
		{
			case normal:
				letterSpacing = 0;
				
			case length(unit):
				letterSpacing = Math.round(getValueFromLength(unit));
		}
		
		return letterSpacing;
	}
	
	private static function getComputedTextTransform(style:AbstractStyle):TextTransformStyleValue
	{
		return style.textTransform;
	}
	
	private static function getComputedFontVariant(style:AbstractStyle):FontVariantStyleValue
	{
		return style.fontVariant;
	}
	
	private static function getComputedFontFamily(style:AbstractStyle):Array<FontFamilyStyleValue>
	{
		return style.fontFamily;
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
	
	private static function getComputedFontStyle(style:AbstractStyle):FontStyleStyleValue
	{
		return style.fontStyle;
	}
	
	private static function getComputedFontWeight(style:AbstractStyle):FontWeightStyleValue
	{
		return style.fontWeight;
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