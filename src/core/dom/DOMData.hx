package core.dom;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

enum NodeType {
	ELEMENT_NODE;
	TEXT_NODE;
}

/**
 * Specifies where to open the linked document
 */
enum AnchorTarget {
	
	/**
	 * Opens the linked document in a new window or tab
	 */
	blank;
	
	/**
	 * Opens the linked document in the same frame as it was clicked (this is default)
	 */
	self;
	
	/**
	 * Opens the linked document in the parent frame
	 */
	parent;
	
	/**
	 * Opens the linked document in the full body of the window
	 */
	top;
}