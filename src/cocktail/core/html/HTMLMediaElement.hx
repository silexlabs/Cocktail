/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;

/**
 * This is an abstract base class for media elements,
 * such as video and audio
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLMediaElement extends EmbeddedElement
{
	/**
	 * The src content attribute on media elements gives the
	 * address of the media resource (video, audio)
	 * to show. The attribute, if present, must
	 * contain a valid non-empty URL potentially surrounded by spaces.
	 */
	public var src(get_src, set_src):String;
	
	//network state
	
	/**
	 * The element has not yet been initialized. All attributes are 
	 * in their initial states.
	 */
	public static inline var NETWORK_EMPTY:Int = 0;
	
	/**
	 * The element's resource selection algorithm is active and
	 * has selected a resource, but it is not actually using the network at this time.
	 */
	public static inline var NETWORK_IDLE:Int = 1;
	
	/**
	 * The user agent is actively trying to download data.
	 */
	public static inline var NETWORK_LOADING:Int = 2;
	
	/**
	 * The element's resource selection algorithm is active,
	 * but it has not yet found a resource to use.
	 */
	public static inline var NETWORK_NO_SOURCE:Int = 3;
	
	/**
	 * As media elements interact with the network,
	 * their current network activity is represented
	 * by the networkState attribute. On getting, it 
	 * returns the current network state of the
	 * element
	 */
	private var _networkState:Int;
	public var networkState(get_networkState, set_networkState):Int;
	
	//playback state
	
	/**
	 * on getting, return the media element's default playback start position, 
	 * unless that is zero, in which case it must return the element's official playback position.
	 * The returned value is expressed in seconds. 
	 */
	public var currentTime(get_currentTime, set_currentTime):Float;
	
	/**
	 * Return the length of the media resource, in seconds,
	 * assuming that the start of the media resource is
	 * at time zero
	 */
	public var duration(get_duration, never):Float;
	
	/**
	 * The paused attribute represents whether the media
	 * element is paused or not. The attribute is initially true.
	 */
	public var paused(get_paused,  never):Bool;
	
	/**
	 * Returns true if playback has reached the
	 * end of the media resource.
	 */
	public var ended(get_ended, never):Bool;
	
	/**
	 * When true, automatically begins playback of the media
	 */
	public var autoplay(get_autoplay, set_autoplay):Bool;
	
	/**
	 * Determines wether the media element is to seek
	 * back to the start of the media resource upon reaching the end.
	 */
	public var loop(get_loop, set_loop):Bool;
	
	/**
	 * class constructor
	 */
	public function new(tagName:String)
	{
		super(tagName);
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Sets the paused attribute to false, loading the media resource
	 * and beginning playback if necessary.
	 * If the playback had ended, will restart it from the start.
	 */
	public function play():Void
	{
		
	}
	
	/**
	 * Sets the paused attribute to true, 
	 * loading the media resource if necessary.
	 */
	public function pause():Void
	{
		
	}
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	private function get_src():String 
	{
		return null;
	}
	
	private function set_src(value:String):String 
	{
		return value;
	}
	
	private function get_networkState():Int 
	{
		return 0;
	}
	
	private function set_networkState(value:Int):Int 
	{
		return value;
	}
	
	private function get_currentTime():Float 
	{
		return 0;
	}
	
	private function set_currentTime(value:Float):Float 
	{
		return value;
	}
	
	private function get_duration():Float
	{
		return 0;
	}
	
	private function get_paused():Bool
	{
		return false;
	}
	
	private function get_ended():Bool 
	{
		return false;
	}
	
	private function get_autoplay():Bool
	{
		return false;
	}
	
	private function set_autoplay(value:Bool):Bool
	{
		return value;
	}
	
	private function get_loop():Bool
	{
		return false;
	}
	
	private function set_loop(value:Bool):Bool
	{
		return value;
	}
}