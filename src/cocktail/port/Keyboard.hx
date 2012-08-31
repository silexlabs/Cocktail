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
 * Set the right runtime specific keyboard manager at compile-time
 */
#if (flash9 || nme)
typedef Keyboard =  cocktail.port.flash_player.Keyboard;

#else
typedef Keyboard = cocktail.port.server.Keyboard;

#end