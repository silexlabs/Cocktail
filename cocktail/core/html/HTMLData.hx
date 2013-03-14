/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;

/**
 * struct and enums for the html package
 * @author Yannick DOMINGUEZ
 */

 
/**
 * Represent a range (period) of
 * time
 */
typedef Range = {
	var start:Float;
	var end:Float;
}

/**
 * For an input element, lists
 * the different mode which can apply
 * to the "value" IDL attribute
 * 
 * note : weird name
 */
enum ValueModeValue {
	
	/**
	 * On getting, it must return the current value of 
	 * the element. On setting, it must set the element's
	 * value to the new value, set the element's dirty
	 * value flag to true, invoke the value sanitization
	 * algorithm, if the element's type attribute's
	 * current state defines one, and then, if the
	 * element has a text entry cursor position, 
	 * should move the text entry cursor position to
	 * the end of the text field, unselecting any
	 * selected text and resetting the selection direction to none.
	 */
	VALUE;
	
	/**
	 * On getting, if the element has a value attribute, it must
	 * return that attribute's value; otherwise, it must
	 * return the empty string. On setting, it must set the
	 * element's value attribute to the new value.
	 */
	DEFAULT;
	
	/**
	 * On getting, if the element has a value attribute,
	 * it must return that attribute's value; otherwise,
	 * it must return the string "on". On setting, it must
	 * set the element's value attribute to the new value.
	 */
	DEFAULT_ON;
	
	/**
	 * On getting, it must return the string "C:\fakepath\" 
	 * followed by the filename of the first file in the list of
	 * selected files, if any, or the empty string if the list is empty.
	 * On setting, if the new value is the empty string, it must empty
	 * the list of selected files; otherwise, it must throw an
	 * InvalidStateError exception.
	 */
	FILENAME;
}