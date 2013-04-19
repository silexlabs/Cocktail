/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port;

#if macro
typedef Mouse = cocktail.port.base.MouseListenerBase;

#elseif (flash9 || nme)
typedef Mouse =  cocktail.port.platform.flash_player.Mouse;

#else
typedef Mouse = cocktail.port.base.MouseListenerBase;
#end