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
	
	override private function get_nodeName():String
	{
		return _tagName;
	}
	
	//TODO : throw DOMException ?
	override private function set_nodeName(value:String):String
	{
		return value;
	}
}