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
typedef FontManagerImpl = cocktail.port.macro.FontManagerImpl;
#elseif flash9
typedef FontManagerImpl = cocktail.port.flash_player.FontManagerImpl;
#elseif nme
typedef FontManagerImpl = cocktail.port.nme.FontManagerImpl;
#else
typedef FontManagerImpl = cocktail.core.font.AbstractFontManagerImpl;
#end	
