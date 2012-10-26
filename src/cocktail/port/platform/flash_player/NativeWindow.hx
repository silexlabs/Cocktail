/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.flash_player;

import cocktail.core.event.Event;
import cocktail.core.event.EventConstants;
import cocktail.core.event.UIEvent;
import cocktail.core.html.HTMLElement;
import cocktail.port.base.NativeWindowBase;
import cocktail.port.NativeBitmapData;
import cocktail.port.NativeElement;
import flash.display.Bitmap;
import flash.display.StageDisplayState;
import flash.Lib;
import flash.net.URLRequest;
import haxe.Log;

/**
 * This is the flash AVM2 implementation of the native window event manager.
 * Listens to flash native resize event on the flash Stage.
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeWindow extends NativeWindowBase
{
	/**
	 * The name of the attribute whose value to lookup on the flash Stage
	 * to determine wether fullscreen mode is allowed
	 */
	private static inline var ALLOW_FULLSCREEN_ATTRIBUTE:String = "allowsFullScreen";
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super();
		
		//in Flash, the Stage is always defined as no scale as the transformations
		//will be managed by Cocktail
		flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Open a new window using flash API
	 */
	override public function open(url:String, name:String):Void
	{
		flash.Lib.getURL(new URLRequest(url), name);
	}
		
	/**
	 * Uses flash fullscreen API
	 */
	override public function enterFullscreen():Void
	{
		flash.Lib.current.stage.displayState = StageDisplayState.FULL_SCREEN;
	}
	
	/**
	 * Uses flash fullscreen API
	 */
	override public function exitFullscreen():Void
	{
		flash.Lib.current.stage.displayState = StageDisplayState.NORMAL;
	}
	
	/**
	 * Look for the allowFullScreen attribute on the Stage
	 * to determine wether fullscreen is allowed.
	 * A bit hackish but no other way in flash
	 */
	override public function fullScreenEnabled():Bool
	{
		return Reflect.hasField(Lib.current.stage, ALLOW_FULLSCREEN_ATTRIBUTE);
	}
	
	/**
	 * uses flash fullscreen API
	 */
	override public function fullscreen():Bool
	{
		return flash.Lib.current.stage.displayState == StageDisplayState.FULL_SCREEN;
	}
	
	/**
	 * Return the flash Stage
	 */
	override public function getInitialNativeLayer():NativeElement
	{
		return flash.Lib.current;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden private utils methods
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Set resize listeners on the stage
	 */
	override private function setNativeListeners():Void
	{
		Lib.current.stage.addEventListener(flash.events.Event.RESIZE, onNativeResize);
		
		//not supported by nme
		#if flash9
		Lib.current.stage.addEventListener(flash.events.FullScreenEvent.FULL_SCREEN, onNativeFullScreenChange);
		#end
	}
	
	/**
	 * Remove resize listeners from the stage
	 */
	override private function removeNativeListeners():Void
	{
		Lib.current.stage.removeEventListener(flash.events.Event.RESIZE, onNativeResize);
		
		//not supported by nme
		#if flash9
		Lib.current.stage.removeEventListener(flash.events.FullScreenEvent.FULL_SCREEN, onNativeFullScreenChange);
		#end
	}
	
	/**
	 * Create and return a cross-platform resize event
	 * from the flash event
	 * 
	 * @param	event the native event
	 */
	override private function getUIEvent(event:Dynamic):UIEvent
	{
		var resizeEvent:UIEvent = new UIEvent();
		resizeEvent.initUIEvent(EventConstants.RESIZE, false, false, null, 0.0);
		
		return resizeEvent;
	}
	
	/**
	 * Create and return a cross-platform event
	 * from the dispatched native event
	 * 
	 * @param	event the native event
	 */
	override private function getEvent(event:Dynamic):Event
	{
		var fullScreenChangeEvent:Event = new Event();
		fullScreenChangeEvent.initEvent(EventConstants.FULL_SCREEN_CHANGE, false, false);
		
		return fullScreenChangeEvent;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// Overriden GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Return the flash Stage height
	 */
	override private function get_innerHeight():Int
	{
		return Lib.current.stage.stageHeight;
	}
	
	/**
	 * Return the flash Stage width
	 */
	override private function get_innerWidth():Int
	{
		return Lib.current.stage.stageWidth;
	}
	
}