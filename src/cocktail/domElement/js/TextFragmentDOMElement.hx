package cocktail.domElement.js;

import cocktail.domElement.abstract.AbstractTextFragmentDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;
import cocktail.style.Style;

/**
 * This is the JavaScript implementation of the TextFragmentDOMElement.
 * It isn't used in this runtime, text display is handled by the browser
 * 
 * @author Yannick DOMINGUEZ
 */
class TextFragmentDOMElement extends AbstractTextFragmentDOMElement
{
	/**
	 * class constructor
	 */
	public function new(nativeElement:NativeElement, style:Style) 
	{
		super(nativeElement, style);
	}
	
}