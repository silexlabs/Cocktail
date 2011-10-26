package cocktail.domElement.as3;

import cocktail.domElement.abstract.AbstractTextLineDOMElement;
import cocktail.domElement.DOMElement;
import cocktail.nativeElement.NativeElement;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextLineDOMElement extends AbstractTextLineDOMElement
{

	public function new(nativeElement:NativeElement) 
	{
		super(nativeElement);
	}
	
	override public function getOffsetWidth():Int
	{
		return untyped _nativeElement.textWidth;
	}
	

	override public function getOffsetHeight():Int
	{
		return untyped _nativeElement.textHeight;
	}
	
}