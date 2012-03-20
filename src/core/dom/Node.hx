package core.dom;

import core.dom.DOMData;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

class Node 
{

	private var _nodeType:NodeType;
	public var nodeType(get_nodeType, null):NodeType;
	
	public var nodeValue(get_nodeValue, set_nodeValue):String;
	
	public var nodeName(get_nodeName, set_nodeName):String;
	
	private var _parentNode:Node;
	public var parentNode(get_parentNode, null):Node;
	
	private var _childNodes:Array<Node>;
	public var childNodes(get_childNodes, set_childNodes):Array<Node>;
	
	public function new() 
	{
		
	}
	
	//TODO : check what the return value must be
	public function removeChild(oldChild:Node):Node
	{
		oldChild.parentNode = null;
		
		var newChildNodes:Array<Node> = new Array<Node>();
		for (i in 0..._childNodes.length)
		{
			if (_childNodes[i] != oldChild)
			{
				newChildNodes.push(_childNodes[i]);
			}
		}
		this._childNodes = newChildNodes;
		
		return oldChild;
	}
	
	//TODO : check what the return value must be
	public function appendChild(newChild:Node):Node
	{
		if (newChild.parentNode != null)
		{
			var parentNode:Node = newChild.parentNode;
			parentNode.removeChild(newChild);
		}
		newChild.parentNode = this;
		_childNodes.push(newChild);
		
		return newChild;
	}
	
	private function get_nodeType():NodeType 
	{
		return _nodeType;
	}
	
	private function get_parentNode():Node 
	{
		return _parentNode;
	}
	
	private function get_childNodes():Array<Node> 
	{
		return _childNodes;
	}
	
	private function set_childNodes(value:Array<Node>):Array<Node> 
	{
		return _childNodes = value;
	}
	
	private function get_nodeValue():String 
	{
		return null;
	}
	
	private function set_nodeValue(value:String):String 
	{
		return value;
	}
	
	private function get_nodeName():String
	{
		return null;
	}
	
	private function set_nodeName(value:String):String
	{
		return value;
	}
	
	
}