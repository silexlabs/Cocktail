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
typedef TouchListener = cocktail.port.base.TouchListenerBase;

#elseif (flash9 || nme)
typedef TouchListener =  cocktail.port.platform.flash_player.TouchListener;

#else
typedef TouchListener = cocktail.port.base.TouchListenerBase;
#end