package core.dom;

/**
 * The CharacterData interface extends Node with a set of attributes and methods for accessing character data in the DOM.
 * For clarity this set is defined here rather than on each object that uses these attributes and methods.
 * No DOM objects correspond directly to CharacterData, though Text and others do inherit the interface from it.
 * 
 * @author Yannick DOMINGUEZ
 */
class CharacterData extends Node
{
	/**
	 * The character data of the node that implements this interface. The DOM implementation 
	 * may not put arbitrary limits on the amount of data that may be stored in a CharacterData node.
	 * However, implementation limits may mean that the entirety of a node's data may not fit into
	 * a single DOMString. In such cases, the user may call substringData
	 * to retrieve the data in appropriately sized pieces
	 * 
	 * TODO : use DOMString ? implement substringData
	 */
	private var _data:String;
	public var data(get_data, set_data):String;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_data():String 
	{
		return _data;
	}
	
	private function set_data(value:String):String 
	{
		return _data = value;
	}
}