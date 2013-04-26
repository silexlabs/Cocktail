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
typedef NativeAudio =  cocktail.port.base.NativeMedia;

#elseif nme
typedef NativeAudio =  cocktail.port.platform.nme.NativeAudio;

#elseif flash
typedef NativeAudio =  cocktail.port.platform.flash_player.NativeAudio;

#else
typedef NativeAudio =  cocktail.port.base.NativeMedia;
#end