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
typedef NativeTextInput = cocktail.port.base.NativeTextInputBase;

#elseif (flash9 || nme)
typedef NativeTextInput =  cocktail.port.platform.flash_player.NativeTextInput;

#else
typedef NativeTextInput = cocktail.port.base.NativeTextInputBase;
#end