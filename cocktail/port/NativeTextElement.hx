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
typedef NativeTextElement =  Dynamic;

#elseif flash9
typedef NativeTextElement =  flash.display.DisplayObject;

#elseif nme
typedef NativeTextElement =  Dynamic;

#else
typedef NativeTextElement =  Dynamic;
#end