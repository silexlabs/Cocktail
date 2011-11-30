package cocktail.textElement;
import cocktail.domElement.TextFragmentDOMElement;

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
	
	typedef TextFragmentData = {
		var textToken:TextTokenValue;
		var textFragmentDOMElement:TextFragmentDOMElement;
	}