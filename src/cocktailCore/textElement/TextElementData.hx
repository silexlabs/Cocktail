/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktailCore.textElement;

import cocktailCore.domElement.TextFragmentDOMElement;

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
 * representation (a TextFragmentDOMElement)
 */
typedef TextFragmentData = {
	var textToken:TextTokenValue;
	var textFragmentDOMElement:TextFragmentDOMElement;
}