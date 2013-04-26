/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.air;

import cocktail.core.config.Config;
import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.UIEvent;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.PlatformBase;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import flash.display.Bitmap;
import flash.display.StageDisplayState;
import flash.display.StageQuality;
import flash.Lib;
import flash.net.URLRequest;
import haxe.Log;

/**
 * This is the air port of the native platform.
 * 
 * In addition to the flash player platform class,
 * it listens to screen orientation events for mobile
 * and tablet devices
 * 
 * @author Yannick DOMINGUEZ
 */
class Platform extends cocktail.port.platform.flash_player.Platform
{
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * add orientation change listener
	 */
	override private function setNativeListeners():Void
	{
		super.setNativeListeners();
		flash.Lib.current.stage.addEventListener(flash.events.StageOrientationEvent.ORIENTATION_CHANGE, onNativeOrientationChange);
	}
	
	/**
	 * remove orientation change listener
	 */
	override private function removeNativeListeners():Void
	{
		super.removeNativeListeners();
		flash.Lib.current.stage.removeEventListener(flash.events.StageOrientationEvent.ORIENTATION_CHANGE, onNativeOrientationChange);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden events method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When orientation changes, the hit testing Sprite
	 * must be updated
	 */
	override private function onNativeOrientationChange(event:Dynamic):Void
	{
		updateHitTestingSprite();
		super.onNativeOrientationChange(event);
	}
}