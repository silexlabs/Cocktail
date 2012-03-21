package core.dom;

import core.dom.DOMData;

/**
 * The Element interface represents an element in an HTML or XML document.
 * Elements may have attributes associated with them; since the Element interface 
 * inherits from Node, the generic Node interface attribute attributes may be used
 * to retrieve the set of all attributes for an element. There are methods on the
 * Element interface to retrieve either an Attr object by name or an attribute
 * value by name. In XML, where an attribute value may contain entity references,
 * an Attr object should be retrieved to examine the possibly fairly complex sub-tree
 * representing the attribute value. On the other hand, in HTML, where all attributes 
 * have simple string values, methods to directly access an attribute value can
 * safely be used as a convenience.
 * 
 * @author Yannick DOMINGUEZ
 */
class Element extends Node
{

	/**
	 * The name of the element
	 */
	private var _tagName:String;
	public var tagName(get_tagName, set_tagName):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeName():String
	{
		return _tagName;
	}
	
	override private function get_nodeType():NodeType
	{
		return NodeType.ELEMENT_NODE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_tagName():String 
	{
		return _tagName;
	}
	
	private function set_tagName(value:String):String
	{
		return _tagName = value;
	}
}