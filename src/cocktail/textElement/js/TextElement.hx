package cocktail.textElement.js;

import cocktail.style.StyleData;
import cocktail.textElement.abstract.AbstractTextElement;
import cocktail.textElement.TextElementData;
import js.Lib;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextElement extends AbstractTextElement
{
	
	public function new(text:String)
	{
		super(text);
		_text = Lib.document.createTextNode(text);
	}
}