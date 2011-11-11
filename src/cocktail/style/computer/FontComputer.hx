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
	
	public static function compute(style:AbstractStyle, containingDOMElementFontMetrics:FontMetrics):Void
	{
		var computedStyle = style.computedStyle;
		
		computedStyle.fontSize = getComputedFontSize(style);
		
		computedStyle.lineHeight = getComputedLineHeight(style);
		
		computedStyle.verticalAlign = getComputedVerticalAlign(style, containingDOMElementFontMetrics);
		
		computedStyle.fontWeight = getComputedFontWeight(style);
		
		computedStyle.fontStyle = getComputedFontStyle(style);
		
		computedStyle.fontFamily = getComputedFontFamily(style);
		
		computedStyle.fontVariant = getComputedFontVariant(style);
		
		computedStyle.textTransform = getComputedTextTransform(style);
		
		computedStyle.letterSpacing = getComputedLetterSpacing(style);
		
		computedStyle.wordSpacing = getComputedWordSpacing(style);
		
		computedStyle.color = getComputedColor(style);
		
	}
	
	private static function getComputedVerticalAlign(style:AbstractStyle, containingDOMElementFontMetrics:FontMetrics):Int
	{
		var verticalAlign:Int;
		
		//To DO : move this to the box computer, will need to add either a ref to the containing dom element
			//or to its font metrics
			switch(domElementInLineBox[i].style.computedStyle.verticalAlign)
			{
				case baseline:
					baselineOffset = 0;
					
				case middle:
					//! warning : containing dom element must be either an inline parent or the block which started inline context
					baselineOffset = domElementInLineBox[i].offsetHeight / 2 + _containingDOMElement.fontMetrics.xHeight / 2;
					
				case sub:
					baselineOffset = _containingDOMElement.fontMetrics.subscriptOffset;
					
				case _super:
					baselineOffset = _containingDOMElement.fontMetrics.supercriptOffset;
					
				case textTop:
					baselineOffset = 0;
					//TO DO : Align the top of the box with the top of the parent's content area
					
				case textBottom:
					baselineOffset = 0;
					//TO DO : Align the bottom of the box with the bottom of the parent's content area 
					
				case percent(value):
					baselineOffset = domElementInLineBox[i].style.computedStyle.lineHeight * (value * 0.01);
					
				case length(value):
					baselineOffset = getValueFromLength(value);
					
				case top:
					baselineOffset = 0;
					//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
				case bottom:	
					baselineOffset = 0;
					//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
			}
	}
	
	private static function getComputedColor(style:AbstractStyle):Int
	{
		var color:Int;
		
		switch (style.color)
		{
			case numeric(value):
				color = getValueFromColor(value);
				
			case keyword(value):
				color = getValueFromColorKeyword(value);
		}
		
		
		return color;
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
	
	private static function getValueFromColor(value:ColorValue):Int
	{
		var color:Int;
		
		switch (value)
		{
			case RGB(red, green, blue):
				color = red;
				color = (color << 8) + green;
				color = (color << 8) + blue;
			
			case hex(value):
				color = Std.parseInt(StringTools.replace(value, "#", "0x"));

		}
		
		return color;
	}
	
	private static function getValueFromColorKeyword(value:ColorKeywordValue):Int
	{
		var hexColor:String;
		
		switch (value)
		{
			case aqua:
				hexColor = "#00FFFF";
				
			case black:
				hexColor = "#000000";
				
			case blue:
				hexColor = "#0000FF";
				
			case fuchsia:
				hexColor = "#FF00FF";
				
			case gray:
				hexColor = "#808080";
				
			case green:
				hexColor = "#008000";
				
			case lime:
				hexColor = "#00FF00";
				
			case maroon:
				hexColor = "#800000";
				
			case navy:
				hexColor = "#000080";
				
			case olive:
				hexColor = "#808000";
				
			case orange:
				hexColor = "#FFA500";
				
			case purple:
				hexColor = "#800080";
				
			case red:
				hexColor = "#FF0000";
				
			case silver:
				hexColor = "#C0C0C0";
				
			case teal:
				hexColor = "#008080";
				
			case white:
				hexColor = "#FFFFFF";
				
			case yellow:
				hexColor = "#FFFF00";
				
		}
		
		return getValueFromColor(ColorValue.hex(hexColor));
	}
}