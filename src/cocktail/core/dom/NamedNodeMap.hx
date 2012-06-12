package cocktail.core.dom;

/**
 * Objects implementing the NamedNodeMap interface are used to 
 * represent collections of nodes that can be accessed by name.
 * Note that NamedNodeMap does not inherit from NodeList;
 * NamedNodeMaps are not maintained in any particular order.
 * Objects contained in an object implementing NamedNodeMap may
 * also be accessed by an ordinal index, but this is simply to allow
 * convenient enumeration of the contents of a NamedNodeMap,
 * and does not imply that the DOM specifies an order to these Nodes.
 *  
 * @author Yannick DOMINGUEZ
 */
class NamedNodeMap 
{
	/**
	 * The stored nodes. Kept as an Array
	 * instead of an Hash to allow retrieval
	 * by ordinal index
	 */
	private var _nodes:Array<Node>;
	
	/**
	 * The number of nodes in this map.
	 */
	public var length(get_length, never):Int;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		_nodes = new Array<Node>();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Retrieves a node specified by name.
	 * 
	 * @param	name The nodeName of a node to retrieve.
	 * @return A Node (of any type) with the specified nodeName,
	 * or null if it does not identify any node in this map.
	 */
	public function getNamedItem(name:String):Node
	{
		var nodesLength:Int = _nodes.length;
		for (i in 0...nodesLength)
		{
			if (_nodes[i].nodeName == name)
			{
				return _nodes[i];
			}
		}
		
		return null;
	}
	
	/**
	 * Adds a node using its nodeName attribute. 
	 * If a node with that name is already present in this map,
	 * it is replaced by the new one. Replacing a node by itself has no effect.
	 * As the nodeName attribute is used to derive the name
	 * which the node must be stored under, multiple nodes
	 * of certain types (those that have a "special" string value)
	 * cannot be stored as the names would clash. This is seen
	 * as preferable to allowing nodes to be aliased.
	 * 
	 * @param	arg A node to store in this map. The node will 
	 * later be accessible using the value of its nodeName attribute.
	 * @return If the new Node replaces an existing node the
	 * replaced Node is returned, otherwise null is returned.
	 */
	public function setNamedItem(arg:Node):Node
	{
		var replacedNode:Node = getNamedItem(arg.nodeName);
		
		if (replacedNode != null)
		{
			for (i in 0...length)
			{
				if (_nodes[i].isSameNode(replacedNode) == true)
				{
					_nodes[i] = arg;
					return replacedNode;
				}
			}
		}
		else
		{
			_nodes.push(arg);
		}
		
		return replacedNode;
	}
	
	/**
	 * Removes a node specified by name. When this map contains
	 * the attributes attached to an element,
	 * if the removed attribute is known to have 
	 * a default value, an attribute immediately appears
	 * containing the default value as well as the
	 * corresponding namespace URI, local name,
	 * and prefix when applicable.
	 * 
	 * @param	name The nodeName of the node to remove.
	 * @return The node removed from this map if a node
	 * with such a name exists.
	 */
	public function removeNamedItem(name:String):Node
	{
		var removedNode:Node = getNamedItem(name);
		
		if (removedNode == null)
		{
			return null;
		}
		
		var newNodes:Array<Node> = new Array<Node>();
		
		for (i in 0...length)
		{
			if (_nodes[i].isSameNode(removedNode) == false)
			{
				newNodes.push(_nodes[i]);
			}
		}
		
		_nodes = newNodes;
		
		return removedNode;
	}
	
	/**
	 * Returns the indexth item in the map.
	 * If index is greater than or equal to the number of
	 * nodes in this map, this returns null.
	 * 
	 * @param	index Index into this map.
	 * @return The node at the indexth position in the map,
	 * or null if that is not a valid index.
	 */
	public function item(index:Int):Node
	{
		if (index > length - 1)
		{
			return null;
		}
		else
		{
			return _nodes[index];
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_length():Int
	{
		return _nodes.length;
	}
	
}