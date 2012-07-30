package cocktail.core.css;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class CSSStyleSheet 
{

	public var ownerRule(default, null):CSSRule;
	
	public var cssRules(default, null):CSSRuleList;
	
	public function new() 
	{
		
	}
	
	public function insertRule(rule:String, index:Int):Int
	{
		return -1;
	}
	
	public function deleteRule(index:Int):Void
	{
		
	}
	
}