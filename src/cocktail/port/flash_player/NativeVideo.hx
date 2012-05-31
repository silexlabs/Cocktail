/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.port.flash_player;

import cocktail.core.NativeElement;
import cocktail.port.platform.nativeMedia.NativeMedia;
import flash.events.Event;
import flash.Lib;
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
	 * The metadata of the loaded net stream, used
	 * for instance to retrieve video dimensions or
	 * duration
	 */
	private var _metaData:Dynamic;
	
	/**
	 * class constructor. Init video
	 */
	public function new() 
	{
		super();
		init();
	}
	
	/**
	 * init video to a state where it can 
	 * be played by setting an url
	 */
	private function init():Void
	{
		_video = new Video();
		
		var nc = new NetConnection();
		nc.connect(null);
		_netStream = new NetStream(nc);
		
		initListenerObject(_netStream);
		
		_video.attachNetStream(_netStream);
	}
	
	/**
	 * listens to native event on net stream object.
	 * For some reason, it uses old style listener object
	 * instead of event listener
	 */
	private function initListenerObject(netStream:NetStream):Void
	{
		var listener:Dynamic = {
			onMetaData:onNetStreamMetaData
		}
		
		netStream.client = listener;
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
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Store the metadata of the stream when retrieved
	 * and dispatch the metadata event
	 */
	private function onNetStreamMetaData(data:Dynamic):Void
	{
		_metaData = data;
		onNativeLoadedMetaData();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function get_duration():Float
	{
		return _metaData.duration;
	}
	
	override private function get_currentTime():Float
	{
		return _netStream.time;
	}
	
	override private function get_height():Float
	{
		return _video.videoHeight;
	}
	
	override private function get_width():Float
	{
		return _video.videoWidth;
	}
	
	/**
	 * start net stream connection
	 */
	override private function set_src(value:String):String
	{
		_netStream.play(value);
		return value;
	}
	
	override private function get_nativeElement():NativeElement
	{
		return _video;
	}
	
}