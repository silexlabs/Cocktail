/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port;

/**
 * Set the right runtime specific NativeElement at compile-time
 */
#if flash9
typedef NativeElement =  flash.display.DisplayObject;

#elseif nme
typedef NativeElement =  Dynamic;

#else
typedef NativeElement =  Dynamic;
#end