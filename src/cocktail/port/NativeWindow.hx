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
typedef NativeWindow =  cocktail.port.base.NativeWindowBase;

#elseif air
typedef NativeWindow =  cocktail.port.platform.air.NativeWindow;

#elseif (flash9 || nme)
typedef NativeWindow =  cocktail.port.platform.flash_player.NativeWindow;

#else
typedef NativeWindow =  cocktail.port.base.NativeWindowBase;
#end