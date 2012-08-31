/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port;


#if (flash9 || nme)
typedef FontLoader = cocktail.port.flash_player.FontLoader;
#else
typedef FontLoader = cocktail.port.server.FontLoader;
#end	
