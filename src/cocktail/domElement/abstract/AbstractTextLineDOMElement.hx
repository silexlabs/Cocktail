package cocktail.domElement.abstract;

import cocktail.nativeElement.NativeElement;
import cocktail.style.Style;
import cocktail.style.StyleData;

#if flash9
import cocktail.domElement.as3.DOMElement;
#elseif js
import cocktail.domElement.js.DOMElement;
#end

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractTextLineDOMElement extends DOMElement
{
	
	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement);
		this._style = style;
	}

	override private function initStyle():Void
	{
		
	}
	
}