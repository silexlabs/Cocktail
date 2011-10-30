package cocktail.domElement.as3;

import cocktail.domElement.abstract.AbstractTextLineDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.StyleData;
import cocktail.style.Style;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextLineDOMElement extends AbstractTextLineDOMElement
{

	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement, style);
	}
	
	override public function getOffsetWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		
		return untyped _nativeElement.textWidth + computedStyle.paddingLeft + computedStyle.paddingRight + computedStyle.marginLeft + computedStyle.marginRight;

	}
	

	override public function getOffsetHeight():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		
		//return untyped _nativeElement.textHeight;
		return Math.round(computedStyle.lineHeight);
	}
	
	override private function getActualWidth():Int
	{
		var computedStyle:ComputedStyleData = this._style.computedStyle;
		return untyped _nativeElement.specifiedWidth + computedStyle.paddingLeft + computedStyle.paddingRight + computedStyle.marginLeft + computedStyle.marginRight;
	}
	
}