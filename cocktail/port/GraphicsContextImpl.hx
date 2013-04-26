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
typedef GraphicsContextImpl = cocktail.core.graphics.AbstractGraphicsContextImpl;

#elseif (flash9 || nme)
typedef GraphicsContextImpl =  cocktail.port.platform.flash_player.GraphicsContextImpl;

#else
typedef GraphicsContextImpl = cocktail.core.graphics.AbstractGraphicsContextImpl;
#end