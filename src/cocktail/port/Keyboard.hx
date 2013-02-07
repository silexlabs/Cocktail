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
typedef Keyboard = cocktail.port.base.KeyboardListenerBase;

#elseif (flash9 || nme)
typedef Keyboard =  cocktail.port.platform.flash_player.Keyboard;

#else
typedef Keyboard = cocktail.port.base.KeyboardListenerBase;
#end