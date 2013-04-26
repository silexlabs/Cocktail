/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.timer;

/**
 * struct for timer
 * @author Yannick DOMINGUEZ
 */

 /**
  * hold a callback and the absolute time where it should
  * be called
  */
class TimerCallbackVO 
{
	public var timerCallback:Float->Void;
	
	public var callbackTime:Float;
	
	/**
	 * wether the current callback was called, in
	 * which case it can be re-used for another 
	 * callback
	 */
	public var called:Bool;
	
	public function new() 
	{
		callbackTime = 0;
		called = false;
	}
	
}