/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.platform.nativeMedia;

import cocktail.core.event.Event;
import cocktail.core.NativeElement;

/**
 * This is a base class proxying access to 
 * platform specific media API for video and
 * audio
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeMedia
{
	/**
	 * get the duration in second of the
	 * native media, available as soon as 
	 * the meta data are loaded
	 */
	public var duration(get_duration, never):Float;
	
	/**
	 * set the volume of the native media
	 */
	public var volume(never, set_volume):Float;
	
	/**
	 * set the source of th native media, starting loading
	 * it
	 */
	public var src(never, set_src):String;
	
	/**
	 * return the instrinsic width of
	 * the native media
	 */
	public var width(get_width, never):Null<Int>;
	
	/**
	 * return the instrinsic height of
	 * the native media
	 */
	public var height(get_height, never):Null<Int>;
	
	/**
	 * Return the current playhead time, in
	 * seconds
	 */
	public var currentTime(get_currentTime, never):Float;

	/**
	 * A reference to the nativeElement of the native media, used to attach
	 * it to the rendering tree
	 */
	public var nativeElement(get_nativeElement, never):NativeElement;
	
	/**
	 * get the currently loaded number of bytes of the 
	 * media
	 */
	public var bytesLoaded(get_bytesLoaded, never):Float;
	
	/**
	 * get the total number of bytes of the media. Used
	 * with bytesLoaded to estimate the load progress of
	 * the media
	 */
	public var bytesTotal(get_bytesTotal, never):Float;
	
	/**
	 * Listen to the native event dispatched when the metadata
	 * of the native media are loaded
	 */
	private var _onLoadedMetaData:Event->Void;
	public var onLoadedMetaData(get_onLoadedMetaData, set_onLoadedMetaData):Event->Void;
	
	/**
	 * Listen to tick native event dispatched by the native media
	 * while playing
	 */
	private var _onTimeUpdate:Event->Void;
	public var onTimeUpdate(get_onTimeUpdate, set_onTimeUpdate):Event->Void;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * play/resume the the native media
	 */
	public function play():Void
	{
		//abstract
	}
	
	/**
	 * pause the native media
	 */
	public function pause():Void
	{
		//abstract
	}
	
	/**
	 * Seek to the specified time in the 
	 * native media
	 * @param	time the time to seek to,
	 * in seconds
	 */
	public function seek(time:Float):Void
	{
		//abstract
	}
	
	/**
	 * Ask the native media if it can play 
	 * the requested type
	 */
	public function canPlayType(type:String):String
	{
		return null;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// EVENTS
	// Private native video event handler method
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * When a native event is dispatching signaling that the
	 * meata data of the native media are loaded, dispatch
	 * a cross-platform metadata loaded event
	 */
	private function onNativeLoadedMetaData():Void
	{
		if (_onLoadedMetaData != null)
		{
			var loaddedMetadataEvent:Event = new Event();
			loaddedMetadataEvent.initEvent(Event.LOADED_METADATA, false, false);
			_onLoadedMetaData(loaddedMetadataEvent);
		}
	}
	
	/**
	 * When a native tick event is dispatched by the native
	 * media, dispatch a cross-platform tick event
	 */
	private function onNativeTimeUpdate(event:Dynamic):Void
	{
		if (_onTimeUpdate != null)
		{
			var timeUpdateEvent:Event = new Event();
			timeUpdateEvent.initEvent(Event.TIME_UPDATE, false, false);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CALLBACKS SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_onLoadedMetaData():Event->Void
	{
		return _onLoadedMetaData;
	}
	
	private function set_onLoadedMetaData(value:Event->Void):Event->Void
	{
		return _onLoadedMetaData = value;
	}
	
	private function get_onTimeUpdate():Event->Void
	{
		return _onTimeUpdate;
	}
	
	private function set_onTimeUpdate(value:Event->Void):Event->Void
	{
		return _onTimeUpdate = value;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// SETTERS/GETTERS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	private function get_bytesTotal():Float
	{
		return 0;
	}
	
	private function get_bytesLoaded():Float
	{
		return 0;
	}
	
	private function get_currentTime():Float
	{
		return 0;
	}
	
	private function get_height():Null<Int>
	{
		return null;
	}
	
	private function get_width():Null<Int>
	{
		return null;
	}
	
	private function get_nativeElement():NativeElement
	{
		return null;
	}
	
	private function get_duration():Float
	{
		return 0;
	}
	
	private function set_src(value:String):String
	{
		return value;
	}
	private function set_volume(value:Float):Float
	{
		return value;
	}
}