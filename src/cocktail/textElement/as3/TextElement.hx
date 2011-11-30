package cocktail.textElement.as3;

import cocktail.style.StyleData;
import cocktail.textElement.abstract.AbstractTextElement;
import cocktail.textElement.TextElementData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class TextElement extends AbstractTextElement
{

	public function new(text:String) 
	{
		super(text);
		_text = text;
	}
	
	override public function getNativeText():String
	{
		return _text;
	}
}