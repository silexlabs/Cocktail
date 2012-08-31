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
 * Set the right runtime specific video at compile-time
 */
#if flash9
typedef NativeVideo =  cocktail.port.flash_player.NativeVideo;
#else
typedef NativeVideo =  cocktail.port.server.NativeVideo;
#end