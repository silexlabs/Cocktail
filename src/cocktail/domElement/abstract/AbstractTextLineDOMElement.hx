package cocktail.domElement.abstract;

import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.Style;
import cocktail.style.StyleData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class AbstractTextLineDOMElement extends DOMElement
{

	public function new(nativeElement:NativeElement) 
	{
		super(nativeElement);
	}

	override private function initStyle():Void
	{
		this._style = new Style(this);
	}


	
}