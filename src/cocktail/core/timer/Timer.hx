/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.timer;

import cocktail.core.timer.TimerData;

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
	
	public function new() 
	{
		_pendingCallbacks = new Array<TimerCallbackVO>();
		
		#if macro
		#else
		//TODO 3 : for now only support for flash runtime
		//use enter frame intead of timer, seems more efficient because
		//synchronised with screen refresh
		flash.Lib.current.stage.addEventListener(flash.events.Event.ENTER_FRAME, function(e) {flash.Lib.current.stage.invalidate(); } );
		flash.Lib.current.stage.addEventListener(flash.events.Event.RENDER, function(e) { onUpdate(); } );
		#end
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
	public function delay(timerCallback:Void->Void, delay:Float = 0):Void
	{
		//represents the absolute time in milliseconds when this
		//method should be called
		var callbackTime:Float = Date.now().getTime() + delay;
		
		_pendingCallbacks.push(new TimerCallbackVO(timerCallback, callbackTime));
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
		if (_pendingCallbacks.length > 0)
		{
			var time:Float = Date.now().getTime();
			
			//will hold called callback, can't remove them right away
			//during loop
			var completedCallbacks = new Array<TimerCallbackVO>();
			
			var length:Int = _pendingCallbacks.length;
			for (i in 0...length)
			{
				var pendingCallback:TimerCallbackVO = _pendingCallbacks[i];
				
				//check if the current time is superior to the target
				//time of the callback
				if (pendingCallback.callbackTime < time)
				{
					pendingCallback.timerCallback();
					completedCallbacks.push(pendingCallback);
				}
			}
			
			//now that loop is over, remove completed callbacks
			for (j in 0...completedCallbacks.length)
			{
				_pendingCallbacks.remove(completedCallbacks[j]);
			}
		}
	}
}