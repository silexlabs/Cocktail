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
typedef NativeBitmapData =  Dynamic;
#elseif (flash9 || nme)
typedef NativeBitmapData =  flash.display.BitmapData;
#else
typedef NativeBitmapData =  Dynamic;
#end