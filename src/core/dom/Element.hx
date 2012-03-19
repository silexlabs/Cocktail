package core.dom;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Element extends Node
{

	private var _tagName:String;
	public var tagName(get_tagName, null):String;
	
	public function new() 
	{
		super();
	}
	
	private function get_tagName():String 
	{
		return _tagName;
	}
}