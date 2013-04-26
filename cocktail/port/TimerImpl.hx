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
typedef TimerImpl = cocktail.core.timer.AbstractTimerImpl;

#elseif (flash9 || nme)
typedef TimerImpl =  cocktail.port.platform.flash_player.TimerImpl;

#else
typedef TimerImpl = cocktail.core.timer.AbstractTimerImpl;
#end