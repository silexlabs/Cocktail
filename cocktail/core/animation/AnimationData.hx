/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.animation;

import cocktail.core.parser.ParserData;

/**
 * Animation and transition struct
 * 
 * @author Yannick DOMINGUEZ
 */
	
/**
 * Holds all the data necessary to start a transition.
 * It it said to be a pending animation, as it is stored
 * when the value of a CSS property changes, but the animation
 * is actually started on next layout
 */
class PendingAnimationVO {
	public var propertyIndex:Int;
	public var startValue:Float;
	public function new():Void
	{
		
	}
}