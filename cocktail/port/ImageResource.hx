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
typedef ImageResource = cocktail.core.resource.AbstractResource;

#elseif nme
typedef ImageResource = cocktail.port.platform.nme.ImageResource;

#elseif flash9
typedef ImageResource = cocktail.port.platform.flash_player.ImageResource;

#else 
typedef ImageResource = cocktail.core.resource.AbstractResource;
#end