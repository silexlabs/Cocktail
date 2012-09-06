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
 * Set the right runtime specific NativeWindow at compile-time
 */
#if macro
typedef NativeWindow =  cocktail.port.platform.nativeWindow.AbstractNativeWindow;

#elseif (flash9 || nme)
typedef NativeWindow =  cocktail.port.flash_player.NativeWindow;
#else
typedef NativeWindow =  cocktail.port.platform.nativeWindow.AbstractNativeWindow;
#end