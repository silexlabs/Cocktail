package cocktail.style.computer;
import cocktail.style.abstract.AbstractStyle;
import cocktail.unit.UnitData;
import cocktail.style.StyleData;
import cocktail.unit.UnitManager;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class FontComputer 
{

	public function new() 
	{
		
	}
	
	public static function compute(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions, containingDOMElementFontMetrics:FontMetrics):Void
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
		
		computedStyle.textIndent = getComputedTextIndent(style, containingDOMElementDimensions);
		
		computedStyle.whiteSpace = getComputedWhiteSpace(style);
		
		computedStyle.textAlign = getComputedTextAlign(style);
		
		computedStyle.color = getComputedColor(style);
		
	}
	
	private static function getComputedTextAlign(style:AbstractStyle):TextAlignStyleValue
	{
		return style.textAlign;
	}
	
	private static function getComputedWhiteSpace(style:AbstractStyle):WhiteSpaceStyleValue
	{
		return style.whiteSpace;
	}
	
	private static function getComputedTextIndent(style:AbstractStyle, containingDOMElementDimensions:ContainingDOMElementDimensions):Int
	{
		var textIndent:Float;
		
		switch(style.textIndent)
		{
			case length(value):
				textIndent = UnitManager.getPixelFromLengthValue(value);
				
			case percentage(value):
				textIndent = UnitManager.getPixelFromPercent(value, containingDOMElementDimensions.width);
		}
		
		return Math.round(textIndent);
	}
	
	private static function getComputedVerticalAlign(style:AbstractStyle, containingDOMElementFontMetrics:FontMetrics):Float
	{
		
		//TO DO : must represent an offset from the inlinebox baseline
		var verticalAlign:Float;
		
		//To DO : move this to the box computer, will need to add either a ref to the containing dom element
		//or to its font metrics
		switch(style.verticalAlign)
		{
			case baseline:
				verticalAlign = 0;
				
			case middle:
				//! warning : containing dom element must be either an inline parent or the block which started inline context
				verticalAlign = style.domElement.offsetHeight / 2 + containingDOMElementFontMetrics.xHeight / 2;
			case sub:
				verticalAlign = containingDOMElementFontMetrics.subscriptOffset;
				
			case _super:
				verticalAlign = containingDOMElementFontMetrics.superscriptOffset;
				
			case textTop:
				verticalAlign = 0;
				//TO DO : Align the top of the box with the top of the parent's content area
				
			case textBottom:
				verticalAlign = 0;
				//TO DO : Align the bottom of the box with the bottom of the parent's content area 
				
			case percent(value):
				verticalAlign = UnitManager.getPixelFromPercent(value, Math.round(style.computedStyle.lineHeight));
				
			case length(value):
				verticalAlign = UnitManager.getPixelFromLengthValue(value);
				
			case top:
				verticalAlign = 0;
				//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
			case bottom:	
				verticalAlign = 0;
				//TO DO :  return a "null" value here. The eactual value will be calculated at formatting time
		}
		
		return verticalAlign;
	}
	
	private static function getComputedColor(style:AbstractStyle):Int
	{
		return UnitManager.getColorFromColorValue(style.color);
	}
	
	private static function getComputedWordSpacing(style:AbstractStyle):Int
	{
		var wordSpacing:Int;
		
		switch (style.wordSpacing)
		{
			case normal:
				wordSpacing = 0;
				
			case length(unit):
				wordSpacing = Math.round(UnitManager.getPixelFromLengthValue(unit));
		}
		
		return wordSpacing;
	}
	
	private static function getComputedLineHeight(style:AbstractStyle):Float
	{
		var lineHeight:Float;
		
		switch (style.lineHeight)
		{
			case length(unit):
				lineHeight = UnitManager.getPixelFromLengthValue(unit);
				
			case normal:
				lineHeight = style.computedStyle.fontSize * 1.2;
				
			case percentage(value):
				lineHeight = UnitManager.getPixelFromPercent(value, Math.round(style.computedStyle.fontSize));
				
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
				letterSpacing = Math.round(UnitManager.getPixelFromLengthValue(unit));
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
				fontSize = UnitManager.getPixelFromLengthValue(unit);
				
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
}