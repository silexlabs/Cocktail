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
typedef NativeElement =  Dynamic;

#elseif flash9
typedef NativeElement =  flash.display.DisplayObject;

//TODO 1 : shouldn't be dynamic for nme
#elseif nme
typedef NativeElement =  Dynamic;

#else
typedef NativeElement =  Dynamic;
#end