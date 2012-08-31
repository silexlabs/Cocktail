/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
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


enum InvalidationReason {
	styleChanged(styleName:String);
	childStyleChanged(styleName:String);
	positionedChildStyleChanged(styleName:String);
	needsImmediateLayout;
	backgroundImageLoaded;
	windowResize;
	other;
}