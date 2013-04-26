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
typedef NativeButton = cocktail.port.base.NativeInputBase;

#elseif (flash9 || nme)
typedef NativeButton =  cocktail.port.platform.flash_player.NativeButton;

#else
typedef NativeButton = cocktail.port.base.NativeInputBase;
#end