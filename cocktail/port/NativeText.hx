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
typedef NativeText =  cocktail.port.base.NativeTextBase;

#elseif flash9
typedef NativeText =  cocktail.port.platform.flash_player.NativeText;

#elseif nme
typedef NativeText =  cocktail.port.platform.nme.NativeText;

#else
typedef NativeText =  cocktail.port.base.NativeTextBase;
#end