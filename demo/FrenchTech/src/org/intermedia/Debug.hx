package org.intermedia;
import haxe.Timer;

/**
 * Class used for debugging and for checking performance
 * 
 * @author Raphael Harmel
 */

class Debug 
{
	// timer
	private var _timer:Float;
	
	public function new() 
	{
		_timer = Timer.stamp();
	}
	
	/**
	 * function to trace execution length
	 * 
	 * @param	msg
	 */
	public function traceDuration(msg:String):Void
	{
		if (Settings.DEBUG)
		{
			trace(msg + ": " + (Timer.stamp() - _timer));
			_timer = Timer.stamp();
		}
	}
	
}