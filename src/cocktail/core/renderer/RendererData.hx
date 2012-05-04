package cocktail.core.renderer;

/**
 * ...
 * @author Yannick DOMINGUEZ
 */

/**
 * Lists all the different constituant
 * of a plain text, including 
 * controls characters
 */
enum TextToken {
	
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