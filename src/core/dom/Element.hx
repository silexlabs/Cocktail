package core.dom;

import core.dom.DOMData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Element extends Node
{

	private var _tagName:String;
	public var tagName(get_tagName, set_tagName):String;
	
	public function new() 
	{
		super();
	}
	
	private function get_tagName():String 
	{
		return _tagName;
	}
	
	private function set_tagName(value:String):String
	{
		return _tagName = value;
	}
	
	override private function get_nodeName():String
	{
		return _tagName;
	}
	
	override private function get_nodeType():NodeType
	{
		return NodeType.ELEMENT_NODE;
	}
}