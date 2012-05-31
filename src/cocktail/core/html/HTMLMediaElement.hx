/*
	This file is part of Cocktail http://www.silexlabs.org/groups/labs/cocktail/
	This project is © 2010-2011 Silex Labs and is released under the GPL License:
	This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License (GPL) as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. 
	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
	To read the license please visit http://www.gnu.org/copyleft/gpl.html
*/
package cocktail.core.html;
import cocktail.core.event.Event;
import cocktail.port.platform.nativeMedia.NativeMedia;

/**
 * This is an abstract base class for media elements,
 * such as video and audio
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLMediaElement extends EmbeddedElement
{
	/**
	 * When selecting the resource to load, mean that the src
	 * attribute value will be used as the media url
	 */
	public static inline var RESOURCE_SELECTION_ATTRIBUTE_MODE:Int = 0;
	
	/**
	 * When selecting the resource to load, mean that a child
	 * source element src attribute will be used as the media url
	 */
	public static inline var RESOURCE_SELECTION_CHILDREN_MODE:Int = 1;
	
	/**
	 * The name of the src attribute
	 */
	private static inline var HTML_SRC_ATTRIBUTE:String = "src";
	
	/////////////////////////////////
	// IDL ATTRIBUTES
	////////////////////////////////
	
	/**
	 * The src content attribute on media elements gives the
	 * address of the media resource (video, audio)
	 * to show. The attribute, if present, must
	 * contain a valid non-empty URL potentially surrounded by spaces.
	 */
	public var src(get_src, set_src):String;
	
	/**
	 * When true, automatically begins playback of the media
	 */
	public var autoplay(get_autoplay, set_autoplay):Bool;
	
	/**
	 * Determines wether the media element is to seek
	 * back to the start of the media resource upon reaching the end.
	 */
	public var loop(get_loop, set_loop):Bool;
	
	/////////////////////////////////
	// ATTRIBUTES
	////////////////////////////////
	
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
	public var networkState(get_networkState, never):Int;
	
	//ready state
	
	/**
	 * No information regarding the media resource
	 * is available. No data for the current playback 
	 * position is available. Media elements
	 * whose networkState attribute are set to NETWORK_EMPTY
	 * are always in the HAVE_NOTHING state.
	 */
	public static inline var HAVE_NOTHING:Int = 0;
	
	/**
	 * Enough of the resource has been obtained that the duration of
	 * the resource is available. In the case of a video element,
	 * the dimensions of the video are also available.
	 * The API will no longer throw an exception
	 * when seeking. No media data is available
	 * for the immediate current playback position.
	 */
	public static inline var HAVE_METADATA:Int = 1;
	
	/**
	 * Data for the immediate current playback position is available,
	 * but either not enough data is available that the user 
	 * agent could successfully advance the current playback position
	 * in the direction of playback at all without immediately
	 * reverting to the HAVE_METADATA state, or there is no more
	 * data to obtain in the direction of playback. For example,
	 * in video this corresponds to the user agent having data
	 * from the current frame, but not the next frame,
	 * when the current playback position is at the end
	 * of the current frame; and to when playback has ended.
	 */
	public static inline var HAVE_CURRENT_DATA:Int = 2;
	
	/**
	 * Data for the immediate current playback position is available,
	 * as well as enough data for the user agent to advance
	 * the current playback position in the direction
	 * of playback at least a little without immediately
	 * reverting to the HAVE_METADATA state, and the
	 * text tracks are ready. For example, in video
	 * this corresponds to the user agent having data
	 * for at least the current frame and the next frame
	 * when the current playback position is at the instant
	 * in time between the two frames, or to the user agent
	 * having the video data for the current frame and audio
	 * data to keep playing at least a little when the current
	 * playback position is in the middle of a frame. The user 
	 * agent cannot be in this state if playback has ended, 
	 * as the current playback position can never advance in this case.
	 */
	public static inline var HAVE_FUTURE_DATA:Int = 3;
	
	/**
	 * All the conditions described for the HAVE_FUTURE_DATA state 
	 * are met, and, in addition, the user agent estimates
	 * that data is being fetched at a rate where the current 
	 * playback position, if it were to advance at the effective
	 * playback rate, would not overtake the available data 
	 * before playback reaches the end of the media resource.
	 */
	public static inline var HAVE_ENOUGH_DATA:Int = 4;
	
	/**
	 * Returns a value that expresses the current state of the 
	 * element with respect to rendering the 
	 * current playback position, from the codes in the list below.
	 */
	private var _readyState:Int;
	public var readyState(get_readyState, never):Int;
	
	/**
	 * Returns true if the user agent is currently seeking.
	 */
	private var _seeking:Bool;
	public var seeking(get_seeking, never):Bool;
	
	//playback state
	
	/**
	 * on getting, return the media element's default playback start position, 
	 * unless that is zero, in which case it must return the element's official playback position.
	 * The returned value is expressed in seconds. 
	 */
	public var currentTime(get_currentTime, set_currentTime):Float;
	
	private var _currentSrc:String;
	public var currentSrc(get_currentSrc, null):String;
	
	/**
	 * Return the length of the media resource, in seconds,
	 * assuming that the start of the media resource is
	 * at time zero
	 */
	private var _duration:Float;
	public var duration(get_duration, never):Float;
	
	/**
	 * The paused attribute represents whether the media
	 * element is paused or not. The attribute is initially true.
	 */
	private var _paused:Bool;
	public var paused(get_paused,  never):Bool;
	
	/**
	 * Returns true if playback has reached the
	 * end of the media resource.
	 */
	private var _ended:Bool;
	public var ended(get_ended, never):Bool;
	
	/**
	 * a reference to the proxy class allowing
	 * access to runtime specific API for 
	 * video and audio
	 */
	private var _nativeMedia:NativeMedia;
	
	private var _initialPlaybackPosition:Float;
	
	private var _officialPlaybackPosition:Float;
	
	private var _currentPlaybackPosition:Float;
	
	private var _autoplaying:Bool;
	
	/**
	 * class constructor
	 */
	public function new(tagName:String)
	{
		super(tagName);
		
		_networkState = NETWORK_EMPTY;
		_ended = false;
		_duration = 0;
		_paused = false;
		_seeking = false;
		_readyState = HAVE_NOTHING;
		_autoplaying = true;
	}
	
	/**
	 * overriden to also init the native media
	 */
	override private function init():Void
	{
		initNativeMedia();
		super.init();
	}
	
	/**
	 * Instantiate the right native media
	 * manager
	 */
	private function initNativeMedia():Void
	{
		//abstract
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ATTRIBUTES METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTML_SRC_ATTRIBUTE)
		{
			src = value;
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	/////////////////////////////////
	// PUBLIC METHODS
	////////////////////////////////
	
	/**
	 * Sets the paused attribute to false, loading the media resource
	 * and beginning playback if necessary.
	 * If the playback had ended, will restart it from the start.
	 * 
	 * this method is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#dom-media-play
	 * 
	 * TODO 2 incomplete implementation
	 */
	public function play():Void
	{
		if (_networkState == NETWORK_EMPTY)
		{
			selectResource();
		}
		
		if (_ended == true)
		{
			seek(0);
		}
		
		if (_paused == true)
		{
			_paused = false;
			
			fireEvent(Event.PLAY, false, false);
			
			switch (_readyState)
			{
				case HAVE_NOTHING, HAVE_METADATA, HAVE_CURRENT_DATA:
					fireEvent(Event.WAITING, false, false);
					
				case HAVE_FUTURE_DATA, HAVE_ENOUGH_DATA:
					fireEvent(Event.PLAYING, false, false);
			}
		}
		
		_autoplaying = false;
		
		_nativeMedia.play();
	}
	
	/**
	 * Sets the paused attribute to true, 
	 * loading the media resource if necessary.
	 * 
	 * this method is an implementation of the following algorithm :
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#dom-media-pause
	 */
	public function pause():Void
	{
		if (_networkState == NETWORK_EMPTY)
		{
			selectResource();
		}
		
		_autoplaying = false;
		
		if (_paused == false)
		{
			_paused = true;
			
			fireEvent(Event.TIME_UPDATE, false, false);
			
			fireEvent(Event.PAUSE, false, false);
			
			_officialPlaybackPosition = _currentPlaybackPosition;
		}
		
		_nativeMedia.pause();
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Start the loading of a media element, this 
	 * is an implementation of the following alogithm :
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#media-element-load-algorithm
	 * 
	 * TODO 2 : implementation is incomplete
	 */
	private function loadResource():Void
	{
		switch (_networkState)
		{
			case NETWORK_LOADING, NETWORK_IDLE:
				fireEvent(Event.ABORT, false, false);
		}
		
		trace(_networkState == NETWORK_EMPTY);
		
		if (_networkState != NETWORK_EMPTY)
		{
			fireEvent(Event.EMPTIED, false, false);
			
			//TODO 1 : If a fetching process is in progress for the media element, the user agent should stop it.
			
			_networkState = NETWORK_EMPTY;
			
			
			_readyState = HAVE_NOTHING;
			
			_paused = true;
			
			_seeking = false;
			
			_currentPlaybackPosition = 0;
			
			if (_officialPlaybackPosition > 0)
			{
				_officialPlaybackPosition = 0;
				fireEvent(Event.TIME_UPDATE, false, false);
			}
			else
			{
				_officialPlaybackPosition = 0;
			}
			
			_initialPlaybackPosition = 0;
			
			//TODO 1 : supposed to be NaN but don't exist in Haxe ?
			_duration = 0;
		}
		
		selectResource();
	}
	
	/**
	 * Select a resource, from the src attribute of the
	 * node or from a child source node.
	 * 
	 * this is an implementation of the following alogithm :
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#media-element-load-algorithm
	 *
	 * TODO 2 : implementation is incomplete
	 */
	private function selectResource():Void
	{
		_networkState = NETWORK_NO_SOURCE;
		
		var mode:Int;
		
		if (src != null)
		{
			mode = RESOURCE_SELECTION_ATTRIBUTE_MODE;
		}
		//else
		//{
			//TODO 1 :  Otherwise, if the media element does not have a src attribute but has a source element child, then let mode be children and let candidate be the first such source element child in tree order.
		//}
		else
		{
			_networkState = NETWORK_EMPTY;
			
			//TODO 1 : should return ?
			return;
		}
		
		_networkState = NETWORK_LOADING;
		
		fireEvent(Event.TIME_UPDATE, false, false);
		
		if (mode == RESOURCE_SELECTION_ATTRIBUTE_MODE)
		{
			if (src == "")
			{
				//TODO 1 : Set the error attribute to a new MediaError object whose code attribute is set to MEDIA_ERR_SRC_NOT_SUPPORTED.
				
				//TODO 2 : Forget the media element's media-resource-specific text tracks.
				
				_networkState = NETWORK_NO_SOURCE;
				
				//TODO 2 : Queue a task to fire a simple event named error at the media element.
				
				return;
			}
			
			//TODO 2 : Let absolute URL be the absolute URL that would have resulted 
			//from resolving the URL specified by the src attribute's value relative
			//to the media element when the src attribute was last changed.
			
			_currentSrc = src;
			fetchResource(_currentSrc);	
		}
	}
	
	private function fetchResource(url:String):Void
	{
		//TODO 1 : should NativeMedia extends EventCallback ?
		//_nativeMedia.onError = onLoadingError;
		_nativeMedia.onLoadedMetaData = onLoadedMetaData;
		_nativeMedia.src = url;
	}
	
	private function seek(time:Float):Void
	{
		
	}
	
	/////////////////////////////////
	// RESOURCE CALLBACKS
	////////////////////////////////
	
	private function onLoadingError(error:Event):Void
	{
		selectResource();
	}
	
	private function onLoadedMetaData(e:Event):Void
	{
		_intrinsicHeight = _nativeMedia.height;
		_intrinsicWidth = _nativeMedia.width;
		_intrinsicRatio = _intrinsicHeight / _intrinsicWidth;
		
		trace(_nativeMedia.duration);
		_duration = _nativeMedia.duration;
		
		invalidateLayout();
		
		fireEvent(Event.LOADED_METADATA, false, false);
	}
	
	/////////////////////////////////
	// IDL GETTER/SETTER
	////////////////////////////////
	
	private function get_src():String 
	{
		return getAttribute(HTML_SRC_ATTRIBUTE);
	}
	
	private function set_src(value:String):String 
	{
		//TODO 2 : awkward to call super, but else infinite loop
		super.setAttribute(HTML_SRC_ATTRIBUTE, value);
		loadResource();
		return value;
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
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	private function get_currentSrc():String 
	{
		return _currentSrc;
	}
	
	private function get_networkState():Int 
	{
		return _networkState;
	}
	
	private function get_currentTime():Float 
	{
		return _officialPlaybackPosition;
	}
	
	private function set_currentTime(value:Float):Float 
	{
		seek(value);
		return value;
	}
	
	private function get_duration():Float
	{
		return _duration;
	}
	
	private function get_paused():Bool
	{
		return _paused;
	}
	
	private function get_ended():Bool 
	{
		return _ended;
	}
	
	private function get_readyState():Int
	{
		return _readyState;
	}
	
	private function get_seeking():Bool
	{
		return _seeking;
	}
}