package cocktail.domElement.abstract;

import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.Style;
import cocktail.style.StyleData;
import cocktail.style.TextStyle;

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