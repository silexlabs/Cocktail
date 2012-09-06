/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port;

/**
 * Set the right runtime specific ResourceLoader at compile-time
 */
#if macro
typedef Resource = cocktail.core.resource.AbstractResource;

#elseif (flash9 || nme)
typedef Resource = cocktail.core.resource.AbstractResource;

#else 
typedef Resource = cocktail.core.resource.AbstractResource;
#end