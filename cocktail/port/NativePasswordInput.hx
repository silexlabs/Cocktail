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
typedef NativePasswordInput = cocktail.port.base.NativeTextInputBase;

#elseif (flash9 || nme)
typedef NativePasswordInput =  cocktail.port.platform.flash_player.NativePasswordInput;

#else
typedef NativePasswordInput = cocktail.port.base.NativeTextInputBase;
#end