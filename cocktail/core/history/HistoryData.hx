/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.history;

/**
 * structure used to store 
 * The title is purely advisory. User agents might use the title in the user interface.
 */
typedef StateData = {
	state:Dynamic, 
	title:String,
	url:Null<String>,
}