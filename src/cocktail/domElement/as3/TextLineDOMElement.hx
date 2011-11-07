package cocktail.domElement.as3;

import cocktail.domElement.abstract.AbstractTextLineDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.StyleData;
import cocktail.style.Style;
import haxe.Log;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextLineDOMElement extends AbstractTextLineDOMElement
{

	public function new(nativeElement:NativeElement, style:Style, isLastLineOfTextBlock:Bool) 
	{
		super(nativeElement, style, isLastLineOfTextBlock);
	}
	
	override public function getOffsetWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		var relevantWidth:Float;
		
		if (untyped _nativeElement.textWidth == 0)
		{
			relevantWidth = untyped _nativeElement.getAtomBounds(0).width ;
			
		}
		else
		{

			relevantWidth = untyped _nativeElement.textWidth + _style.computedStyle.letterSpacing;
		}
		
		return untyped relevantWidth + computedStyle.paddingLeft + computedStyle.paddingRight + computedStyle.marginLeft + computedStyle.marginRight;

	}
	

	override public function getOffsetHeight():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		
		//return untyped _nativeElement.textHeight;
		return Math.round(computedStyle.lineHeight);
	}
	

	
}