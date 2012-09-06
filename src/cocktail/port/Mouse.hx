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
 * Set the right runtime specific mouse manager at compile-time
 */
#if macro
typedef Mouse = cocktail.port.platform.mouse.AbstractMouse;
#elseif (flash9 || nme)
typedef Mouse =  cocktail.port.flash_player.Mouse;

#else
typedef Mouse = cocktail.port.platform.mouse.AbstractMouse;

#end