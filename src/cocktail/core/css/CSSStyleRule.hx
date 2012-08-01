package cocktail.core.css;

import cocktail.core.css.CSSData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CSSStyleRule 
{

	public var selectorText:String;
	
	public var selector:SelectorData;
	
	public var style(default, null):CSSStyleDeclaration;
	
	public function new() 
	{
		
	}
	
}