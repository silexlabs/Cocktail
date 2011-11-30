package cocktail.domElement.js;

import cocktail.domElement.abstract.AbstractTextLineDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.Style;

/**
 * This is the JavaScript implementation of the TextLineDOMElement.
 * It isn't used in this runtime, text display is handled by the browser
 * 
 * @author Yannick DOMINGUEZ
 */
class TextLineDOMElement extends AbstractTextLineDOMElement
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement, style);
	}
	
}