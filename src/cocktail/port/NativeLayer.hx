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
typedef NativeLayer =  Dynamic;

#elseif (flash || nme)
typedef NativeLayer =  flash.display.DisplayObjectContainer;

#else
typedef NativeElement =  Dynamic;
#end