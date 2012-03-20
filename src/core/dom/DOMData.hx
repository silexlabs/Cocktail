package core.dom;
import core.style.renderer.TextRenderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

 //TODO : add document node
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

/**
 * TextElement enum and struct
 */

/**
 * Lists all the different consituant
 * of a plain text, including 
 * controls characters
 */
enum TextTokenValue {
	
	/**
	 * a word, surrounded by
	 * spaces
	 */
	word(value:String);
	
	/**
	 * represents one
	 * space which can be 
	 * between 2 words or among
	 * a space sequence
	 */
	space;
	
	/**
	 * a tabulation
	 */
	tab;
	
	/**
	 * a line feed (starts
	 * a new line)
	 */
	lineFeed;
}

/**
 * Holds a text token and its visual
 * representation (a TextRenderer)
 */
typedef TextFragmentData = {
	var textToken:TextTokenValue;
	var textRenderer:TextRenderer;
}