package core.dom;

/**
 * he Attr interface represents an attribute in an Element object
 * 
 * @author Yannick DOMINGUEZ
 */
class Attr extends Node
{
	/**
	 * Returns the name of this attribute.
	 * If Node.localName is different from null,
	 * this attribute is a qualified name.
	 * 
	 * TODO : implement localName
	 */
	private var _name:String;
	public var name(get_name, null):String;
	
	/**
	 * On retrieval, the value of the attribute is returned as a string.
	 * Character and general entity references are replaced with their values.
	 * On setting, this creates a Text node with the unparsed contents
	 * of the string, i.e. any characters
	 * that an XML processor would recognize as markup
	 * are instead treated as literal text.
	 * 
	 * TODO : create a Text node ?
	 */
	private var _value:String;
	public var value(get_value, set_value):String;
	
	/**
	 * True if this attribute was explicitly given a value in the instance document,
	 * false otherwise. If the application changed the value of this attribute
	 * node (even if it ends up having the same value as the default value)
	 * then it is set to true.
	 */
	private var _specified:Bool;
	public var specified(get_specified, never):Bool;
	
	/**
	 * class constructor
	 */
	public function new(name:String) 
	{
		_name = name;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_nodeName():String
	{
		return _name;
	}
	
	override private function get_nodeType():NodeType
	{
		return NodeType.ATTRIBUTE_NODE;
	}
	
	override private function get_nodeValue():String 
	{
		return _value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_name():String 
	{
		return _name;
	}
	
	private function get_value():String 
	{
		return _value;
	}
	
	private function set_value(value:String):String 
	{
		return _value = value;
	}
	
	private function get_specified():Bool 
	{
		return _specified;
	}
	
}