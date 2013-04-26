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
typedef NativeVideo =  cocktail.port.base.NativeMedia;

#elseif flash9
typedef NativeVideo =  cocktail.port.platform.flash_player.NativeVideo;

#else
typedef NativeVideo =  cocktail.port.base.NativeMedia;
#end