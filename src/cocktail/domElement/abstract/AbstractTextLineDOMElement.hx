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
	
	private var _isLastLineOfTextBlock:Bool;
	public var isLastLineOfTextBlock(getIsLastLineOfTextBlock, never):Bool;
	
	public function new(nativeElement:NativeElement, style:Style, isLastLineOfTextBlock:Bool) 
	{
		super(nativeElement);
		
		this._isLastLineOfTextBlock = isLastLineOfTextBlock;
		this._style = style;
	}

	override private function initStyle():Void
	{
		
	}
	
	private function getIsLastLineOfTextBlock():Bool
	{
		return this._isLastLineOfTextBlock;
	}
	



	
}