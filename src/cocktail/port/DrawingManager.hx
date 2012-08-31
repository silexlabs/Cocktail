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
 * Set the right runtime specific drawing manager at compile-time
 */
#if (flash9 || nme)
typedef DrawingManager =  cocktail.port.flash_player.DrawingManager;

#else
typedef DrawingManager = cocktail.port.server.DrawingManager;
#end