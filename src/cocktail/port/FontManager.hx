/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port;


#if flash9
typedef FontManager = cocktail.port.flash_player.FontManager;
#elseif nme
typedef FontManager = cocktail.port.nme.FontManager;
#else
typedef FontManager = cocktail.port.server.FontManager;
#end	
