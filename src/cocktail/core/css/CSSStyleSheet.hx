package cocktail.core.css;

import cocktail.core.css.CSSData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CSSStyleSheet extends StyleSheet
{

	public var ownerRule(default, null):CSSRule;
	
	public var cssRules(default, null):CSSRuleList;
	
	public function new() 
	{
		super();
		cssRules = new CSSRuleList();
	}
	
	public function insertRule(rule:String, index:Int):Int
	{
		return -1;
	}
	
	public function deleteRule(index:Int):Void
	{
		
	}
	
}