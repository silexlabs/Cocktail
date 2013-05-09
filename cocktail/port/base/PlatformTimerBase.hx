 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

/**
 * An abstract timer implementation. Overriden
 * for each target platform. It is given
 * an update callback and use platform specific
 * API to determine when to call it
 * 
 * By default, never calls the update callback.
 * Used for instance for stateless server target
 * 
 * @author Yannick DOMINGUEZ
 */
class PlatformTimerBase 
{
	/**
	 * class constructor
	 * 
	 * @param	updateCallback the callback to
	 * call at regular time interval
	 */
	public function new(updateCallback:Void->Void) 
	{
		
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		
	}
	
	/**
	 * Return the current timestamp, in millisecond
	 */
	public function getTimer():Float
	{
		return -1;
	}
}