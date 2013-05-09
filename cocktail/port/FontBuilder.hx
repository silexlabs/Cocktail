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
typedef FontBuilder = cocktail.port.base.FontBuilderBase;
#elseif flash9
typedef FontBuilder = cocktail.port.platform.flash_player.FontBuilder;
#elseif nme
typedef FontBuilder = cocktail.port.platform.nme.FontBuilder;
#else
typedef FontBuilder = cocktail.core.font.FontBuilderBase;
#end	
