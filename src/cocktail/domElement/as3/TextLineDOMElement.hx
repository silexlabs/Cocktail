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

	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement, style);
		
		if (_nativeElement != null)
		{
			if (untyped _nativeElement.textWidth == 0)
			{
			
				this._width = untyped _nativeElement.getAtomBounds(0).width;
			}
		}
	
	}
	
	override private function getOffsetWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		var relevantWidth:Float;
		
		if (untyped _nativeElement.textWidth == 0)
		{
			//return this._width;
			//relevantWidth = untyped _nativeElement.getAtomBounds(0).width;
			return this._width + _style.computedStyle.letterSpacing + _style.computedStyle.wordSpacing;
		}
		else
		{

			relevantWidth = untyped _nativeElement.textWidth ;
		}
		
		return untyped relevantWidth + computedStyle.paddingLeft + computedStyle.paddingRight + computedStyle.marginLeft + computedStyle.marginRight + _style.computedStyle.letterSpacing;
				
		
		
	}
	

	override private function getOffsetHeight():Int
	{
		
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		
		//return untyped _nativeElement.textHeight;
		return Math.round(computedStyle.lineHeight);
	}
	

	
}