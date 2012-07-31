package cocktail.core.css;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

 //TODO 1 : should replace style adapter, must add all getter/setter on it
class CSSStyleDeclaration 
{

	public var cssText:String;
	
	public var length(default, null):Int;
	
	public var parentRule(default, null):CSSRule;
	
	public function new() 
	{
		
	}
	
	public function item(index:Int):String
	{
		
	}
	
	public function getPropertyValue(property:String):String
	{
		
	}
	
	public function getPropertyPriority(property:String):String
	{
		
	}
	
	public function setProperty(property:String, value:String, priority:String = null):Void
	{
		
	}
	
	public function removeProperty(property:String):String
	{
		
	}
}