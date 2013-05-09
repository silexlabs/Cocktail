/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.timer;

import cocktail.core.timer.TimerData;
import cocktail.port.Bindings;
import haxe.Log;
import haxe.Stack;

/**
 * Manages the event loop of the document.
 * Methods called asynchronously registers themselves
 * through it
 * 
 * @author Yannick DOMINGUEZ
 */
class Timer 
{
	/**
	 * Contain all the callback which need to be called asynchronously,
	 * each one knows when it should be called
	 */
	private var _pendingCallbacks:Array<TimerCallbackVO>;
	
	/**
	 * Keep track of the number of pending
	 * methods which needs to be called. 
	 * Allow to reduce methods call when 
	 * no method calls are pending
	 */
	private var _pendingCount:Int;
	
	/**
	 * Uses platform specific API to
	 * call the update method at regular interval
	 */
	private var _platformTimer:PlatformTimer;
	
	public function new() 
	{
		_pendingCallbacks = new Array<TimerCallbackVO>();
		_pendingCount = 0;
		
		//give the update callback to the timer implementation, it
		//will determine when to call it
		_platformTimer = new PlatformTimer(onUpdate);
	}
	
	/**
	 * clean up method
	 */
	public function dispose():Void
	{
		_pendingCallbacks = null;
		
		_platformTimer.dispose();
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Set up a method to be called after the provided
	 * delay has passed.
	 * 
	 * If no delay is given, the method will be called on next update
	 */
	public function delay(timerCallback:Float->Void, delay:Float = 0):Void
	{
		//increment global counter to be
		//sure this callback gets called
		_pendingCount++;
		
		//represents the absolute time in milliseconds when this
		//method should be called
		var callbackTime:Float = getTimer() + delay;
		
		//try to re-use a pending callback object
		var length:Int = _pendingCallbacks.length;
		for (i in 0...length)
		{
			var pendingCallback:TimerCallbackVO = _pendingCallbacks[i];
			//the object can be re-used once it has been called
			if (pendingCallback.called == true)
			{
				pendingCallback.called = false;
				pendingCallback.callbackTime = callbackTime;
				pendingCallback.timerCallback = timerCallback;
				return;
			}
		}
		
		//if no objects are re-usable, create one
		var newTimerCallback:TimerCallbackVO = new TimerCallbackVO();
		newTimerCallback.called = false;
		newTimerCallback.callbackTime = callbackTime;
		newTimerCallback.timerCallback = timerCallback;
		_pendingCallbacks.push(newTimerCallback);
	}
	
	/**
	 * Return the current timestamp
	 * in milliseconds
	 */
	public function getTimer():Float
	{
		return _platformTimer.getTimer();
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Update loop, constantly called, call 
	 * methods whose delay is completed
	 */
	private function onUpdate():Void
	{
		//do nothing if no callbacks are registered
		if (_pendingCount > 0)
		{
			var time:Float = getTimer();
			
			var length:Int = _pendingCallbacks.length;
			for (i in 0...length)
			{
				var pendingCallback:TimerCallbackVO = _pendingCallbacks[i];
				
				//check if the current time is superior to the target
				//time of the callback
				if (pendingCallback.callbackTime < time && pendingCallback.called == false)
				{
					//when the callback is called, it is given the current
					//time stamp
					pendingCallback.timerCallback(time);
					
					//mark the pending callback object
					//as re-usable
					pendingCallback.called = true;
					
					//decrement to prevent unecessary calls when no method
					//call is pending
					_pendingCount--;
				}
			}
		}
	}
}