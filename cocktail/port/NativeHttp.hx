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
typedef NativeHttp =  cocktail.port.base.NativeHttpBase;

#elseif nme
typedef NativeHttp =  cocktail.port.platform.nme.NativeHttp;

#elseif flash9
typedef NativeHttp =  cocktail.port.platform.flash_player.NativeHttp;

#else
typedef NativeHttp =  cocktail.port.base.NativeHttpBase;
#end