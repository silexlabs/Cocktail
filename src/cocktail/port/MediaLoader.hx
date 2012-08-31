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
#if (flash9 || nme)
typedef MediaLoader = cocktail.port.flash_player.MediaLoader;

#else 
typedef MediaLoader = cocktail.port.server.MediaLoader;
#end