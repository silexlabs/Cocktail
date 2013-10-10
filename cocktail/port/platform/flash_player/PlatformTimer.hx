 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;
import cocktail.port.base.PlatformTimerBase;
import flash.events.Event;

/**
 * Timer implementation for flash and openfl.
 * Actually use the flash frame rate
 * 
 * @author Yannick DOMINGUEZ
 */

class PlatformTimer extends PlatformTimerBase
{
	/**
	 * store a ref to the enter frame callback
	 */
	private var _callback:Event->Void;
	
	/**
	 * called on enter frame
	 */
	private var _updateCallback:Void->Void;
	
	/**
	 * class constructor. Call the update
	 * callback on each frame
	 */
	public function new(updateCallback:Void->Void) 
	{
		super(updateCallback);
		_callback = onEnterFrame;
		_updateCallback = updateCallback;
		flash.Lib.current.stage.addEventListener(flash.events.Event.ENTER_FRAME, _callback );
	}
	
	/**
	 * clean up method
	 */
	override public function dispose():Void 
	{
		 super.dispose();
		 flash.Lib.current.stage.removeEventListener(flash.events.Event.ENTER_FRAME, _callback );
		 _callback = null;
		 _updateCallback = null;
	}
	
	/**
	 * Return flash current timestamp
	 */
	override public function getTimer():Float
	{
		return flash.Lib.getTimer();
	}
	
	/**
	 * call update method on enter frame
	 */
	private function onEnterFrame(e:Event):Void
	{
		_updateCallback();
	}
}
