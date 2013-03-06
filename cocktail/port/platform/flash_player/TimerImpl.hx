 /*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;
import cocktail.core.timer.AbstractTimerImpl;

/**
 * Timer implementation for flash and nme.
 * Actually use the flash frame rate
 * 
 * @author Yannick DOMINGUEZ
 */

class TimerImpl extends AbstractTimerImpl
{
	/**
	 * class constructor. Call the update
	 * callback on each frame
	 */
	public function new(updateCallback:Void->Void) 
	{
		super(updateCallback);
		flash.Lib.current.stage.addEventListener(flash.events.Event.ENTER_FRAME, function(e) {updateCallback(); } );
	}
}