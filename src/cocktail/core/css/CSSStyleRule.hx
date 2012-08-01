package cocktail.core.css;

import cocktail.core.css.CSSData;
/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CSSStyleRule extends CSSRule
{

	public var selectorText:String;
	
	public var selector:SelectorData;
	
	public var style(default, null):CSSStyleDeclaration;
	
	public function new() 
	{
		super();
		style = new CSSStyleDeclaration(this);
		selector = {
			combinators:[],
			pseudoElement:PseudoElementSelectorValue.NONE
		}
	}
	
	override private function get_type():Int
	{
		return CSSRule.STYLE_RULE;
	}
	
}