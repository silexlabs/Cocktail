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
typedef Platform =  cocktail.port.base.PlatformBase;

#elseif air
typedef Platform =  cocktail.port.platform.air.Platform;

#elseif (flash9 || nme)
typedef Platform =  cocktail.port.platform.flash_player.Platform;

#else
typedef Platform =  cocktail.port.base.PlatformBase;
#end