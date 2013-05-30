/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.dom;

/**
 * TODO : for now NodeList is an array but it can
 * also be implemented using an abstract type which
 * enables operator overloading. This way it could
 * both be accessed as an array and have the 
 * standard item() method
 */
typedef NodeList = Array<Node>;