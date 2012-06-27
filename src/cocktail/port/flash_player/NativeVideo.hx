/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.html.HTMLMediaElement;
import cocktail.port.NativeElement;
import cocktail.port.platform.nativeMedia.NativeMedia;
import flash.events.AsyncErrorEvent;
import flash.events.Event;
import flash.Lib;
import flash.media.SoundTransform;
import flash.media.Video;
import flash.net.NetConnection;
import flash.net.NetStream;
import flash.events.NetStatusEvent;

/**
 * This is the flash as3 port of the native video,
 * allowing displaying an flv or mp4 video using
 * flash native video capabilities
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeVideo extends NativeMedia
{
	//supported flash video types

	private static inline var MP4_EXTENSION:String = "mp4";
	
	private static inline var FLV_EXTENSION:String = "flv";
	
	// net status info code
	
	private static inline var NET_CONNECTION_CONNECT_SUCCESS:String = "NetConnection.Connect.Success";

	/**
	 * a reference to the native flash video
	 * player
	 */
	private var _video:Video;
	
	/**
	 * The flash net stream object, 
	 * connecting to the video stream
	 */
	private var _netStream:NetStream;
	
	/**
	 * The native flash net connection object
	 */
	private var _nc:NetConnection;
	
	/**
	 * The metadata of the loaded net stream, used
	 * for instance to retrieve video dimensions or
	 * duration
	 */
	private var _metaData:Dynamic;
	
	/**
	 * The url of the played video
	 */
	private var _src:String;
	
	/**
	 * class constructor. Init video
	 */
	public function new() 
	{
		super();
		
		_video = new Video();
		_video.smoothing = true;
		
		_nc = new NetConnection();
		_nc.addEventListener(NetStatusEvent.NET_STATUS, onNetStatus);
		_nc.connect(null); 
		
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * call the resume method on the
	 * flash NetStream object
	 */
	override public function play():Void
	{
		_netStream.resume();
	}
	
	/**
	 * call the native pause method
	 * on the NetStream object
	 */
	override public function pause():Void
	{
		_netStream.pause();
	}
	
	/**
	 * Call the native seek method of
	 * the NetStream object
	 */
	override public function seek(time:Float):Void 
	{
		_netStream.seek(time);
	}
	
	/**
	 * Determine wether the given type can be played
	 * by the flash player
	 */
	override public function canPlayType(type:String):String
	{
		if (type.indexOf(MP4_EXTENSION) != -1)
		{
			return HTMLMediaElement.CAN_PLAY_TYPE_PROBABLY;
		}
		
		if (type.indexOf(FLV_EXTENSION) != -1)
		{
			return HTMLMediaElement.CAN_PLAY_TYPE_PROBABLY;
		}
		
		//not a supported video format
		return HTMLMediaElement.CAN_PLAY_TYPE_MAYBE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Callback for async error. Retry to play the stream
	 * when happens
	 * 
	 * TODO 3 : really hackish but sometimes video doesn't start.
	 * Might have missed something in flash video API
	 */
	private function onAsyncError(event:AsyncErrorEvent):Void
	{
		src = _src;
	}
	
	/**
	 * Wait for the NetConnection object to connect before initialising
	 * the net stream
	 */
	private function onNetStatus(event:NetStatusEvent):Void
	{
		switch (event.info.code)
		{
			case NET_CONNECTION_CONNECT_SUCCESS:
				connectStream();
				
			case "NetStream.Seek.Notify":
		}
	}
	
	/**
	 * init the net stream and attach
	 * it to the video object
	 */
	private function connectStream():Void
	{
		_netStream = new NetStream(_nc);
		
		_netStream.client = {
			onMetaData:onNetStreamMetaData
		}
		
		_netStream.addEventListener(NetStatusEvent.NET_STATUS, onNetStatus);
		_netStream.addEventListener(AsyncErrorEvent.ASYNC_ERROR, onAsyncError);
		
		_video.attachNetStream(_netStream);
	}
	
	/**
	 * Store the metadata of the stream when retrieved
	 * and dispatch the metadata event
	 */
	private function onNetStreamMetaData(data:Dynamic):Void
	{
		//this flag is used to ensure that the metadata event
		//is only dispatched the first time metadata are received
		//for the video, as with NetStream, for instance seeking
		//will dispatch a metadata event
		var metaWasNull:Bool = _metaData == null;
		
		if (metaWasNull == true)
		{
			_metaData = data;
					
			//pause video by default, play must be explicitely
			//called
			_netStream.pause();
			
			onNativeLoadedMetaData();
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function set_volume(value:Float):Float
	{
		_netStream.soundTransform = new SoundTransform(value, 0);
		return value;
	}
	
	override private function get_bytesTotal():Float
	{
		return _netStream.bytesTotal;
	}
	
	override private function get_bytesLoaded():Float
	{
		return _netStream.bytesLoaded;
	}
	
	override private function get_duration():Float
	{
		return _metaData.duration;
	}
	
	override private function get_currentTime():Float
	{
		return _netStream.time;
	}
	
	override private function get_height():Null<Int>
	{
		//return null if metadata not yet loaded
		if (_metaData == null)
		{
			return null;
		}
		return _video.videoHeight;
	}
	
	override private function get_width():Null<Int>
	{
		if (_metaData == null)
		{
			return null;
		}
		
		return _video.videoWidth;
	}
	
	/**
	 * start net stream play
	 */
	override private function set_src(value:String):String
	{
		//reset metadata
		_metaData = null;
		
		_src = value;
		_netStream.play(value);
		
		return value;
	}
	
	override private function get_nativeElement():NativeElement
	{
		return _video;
	}
	
}