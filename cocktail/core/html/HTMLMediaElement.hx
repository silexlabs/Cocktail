/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.core.dom.Node;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.port.base.NativeMedia;
import cocktail.core.html.HTMLData;
import cocktail.core.parser.ParserData;

/**
 * This is an abstract base class for media elements,
 * such as video and audio
 * 
 * TODO 3 : implement "metadata" value for preload
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
	 * the frequence in milliseconds between each dispatch of
	 * a timeupdate event when the media is playing
	 */
	private static inline var TIME_UPDATE_FREQUENCY:Int = 250;
	
	/**
	 * the frequence in milliseconds between each dispatch of
	 * a progress event when a media is loading
	 */
	private static inline var PROGRESS_FREQUENCY:Int = 350;
	
	/**
	 * The delta, in seconds, tht should exist between the current 
	 * playack position and the total duration of the media for the
	 * media to be considered ended. It is approximated as else, current
	 * playback position will never be exactly equal to duration
	 */
	private static inline var  PLAYBACK_END_DELTA:Float = 0.2;
	
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
	
	/**
	 * The preload attribute is intended to provide
	 * a hint to the user agent about what the author
	 * thinks will lead to the best user experience. 
	 */
	public var preload(get_preload, set_preload):String;
	
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
	public var networkState(default, null):Int;
	
	//can play constants
	
	/**
	 * return maybe if the user agent might support 
	 * the format
	 */
	public static inline var CAN_PLAY_TYPE_MAYBE:String = "maybe";
	
	/**
	 * return probably if the user agent is confident it 
	 * can play the format
	 */
	public static inline var CAN_PLAY_TYPE_PROBABLY:String = "probably";
	
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
	public var readyState(default, null):Int;
	
	/**
	 * Returns true if the user agent is currently seeking.
	 */
	public var seeking(default, null):Bool;
	
	//playback state
	
	/**
	 * on getting, return the media element's default playback start position, 
	 * unless that is zero, in which case it must return the element's official playback position.
	 * The returned value is expressed in seconds. 
	 */
	public var currentTime(get_currentTime, set_currentTime):Float;
	
	public var currentSrc(default, null):String;
	
	/**
	 * Return the length of the media resource, in seconds,
	 * assuming that the start of the media resource is
	 * at time zero
	 */
	public var duration(default, null):Float;
	
	/**
	 * return a new static normalized TimeRanges object that represents
	 * the ranges of the media resource, if any, that the user agent has buffered,
	 * at the time the attribute is evaluated.
	 * 
	 * TODO 2 : Users agents must accurately determine the ranges available, 
	 * even for media streams where this can only be determined by tedious inspection.
	 */
	public var buffered(get_buffered, never):TimeRanges;
	
	/**
	 * The paused attribute represents whether the media
	 * element is paused or not. The attribute is initially true.
	 */
	public var paused(default,  null):Bool;
	
	/**
	 * Returns true if playback has reached the
	 * end of the media resource.
	 */
	public var ended(default, null):Bool;
	
	/**
	 * Returns true if audio is muted, overriding the volume attribute,
	 * and false if the volume attribute is being honored. Can be set,
	 * to change whether the audio is muted or not.
	 */
	public var muted(default, set_muted):Bool;
	
	/**
	 * Returns the current playback volume, as a number in
	 * the range 0.0 to 1.0, where 0.0 is the quietest and
	 * 1.0 the loudest. Can be set, to change the volume.
	 */
	public var volume(default, set_volume):Float;
	
	/**
	 * a reference to the proxy class allowing
	 * access to runtime specific API for 
	 * video and audio
	 */
	public var nativeMedia(default, null):NativeMedia;
	
	/**
	 * Wether the loading of the media resource
	 * was stalled by the preload attribute.
	 * For instance if the preload attribute
	 * is "none", the resource won't be loaded
	 * until the play method is called explicitely
	 */
	private var _stalledByPreload:Bool;
	
	private var _initialPlaybackPosition:Float;
	
	private var _officialPlaybackPosition:Float;
	
	private var _currentPlaybackPosition:Float;
	
	private var _defaultPlaybackStartPosition:Float;
	
	private var _earliestPossiblePosition:Float;
	
	private var _loadedDataWasDispatched:Bool;
	
	private var _autoplaying:Bool;
	
	/**
	 * class constructor
	 */
	public function new(tagName:String)
	{
		super(tagName);
		
		networkState = NETWORK_EMPTY;
		ended = false;
		duration = 0;
		paused = true;
		seeking = false;
		readyState = HAVE_NOTHING;
		_autoplaying = true;
		volume = 1.0;
		muted = false;
		
		_stalledByPreload = false;
		_loadedDataWasDispatched = false;
		_defaultPlaybackStartPosition = 0;
		_officialPlaybackPosition = 0;
		_currentPlaybackPosition = 0;
		_initialPlaybackPosition = 0;
		_earliestPossiblePosition = 0;
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
	// OVERRIDEN NODE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to invoke the resource selection algorithm
	 * as needed if a source child is added
	 */
	override public function appendChild(newChild:Node):Node
	{
		super.appendChild(newChild);
		
		//if there is no source and no selected resource for
		//this media element
		if (src == null && networkState == NETWORK_EMPTY)
		{
			//invoke the select resource algorithm if a source
			//child was just added
			if (newChild.nodeName == HTMLConstants.HTML_SOURCE_TAG_NAME)
			{
				selectResource();
			}
		}
		
		return newChild;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ATTRIBUTES METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * overriden to call the right setter for 
	 * html media attributes
	 */
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTMLConstants.HTML_SRC_ATTRIBUTE_NAME)
		{
			src = value;
		}
		else if (name == HTMLConstants.HTML_PRELOAD_ATTRIBUTE_NAME)
		{
			preload = value;
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	/**
	 * overriden to call the right getter for 
	 * html media attributes
	 */
	override public function getAttribute(name:String):String
	{
		if (name == HTMLConstants.HTML_PRELOAD_ATTRIBUTE_NAME)
		{
			return preload;
		}
		else
		{
			return super.getAttribute(name);
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
		if (networkState == NETWORK_EMPTY)
		{
			selectResource();
		}
		
		if (ended == true)
		{
			ended = false;
			seek(0);
		}
		
		if (paused == true)
		{
			paused = false;
			
			fireEvent(EventConstants.PLAY, false, false);
			
			switch (readyState)
			{
				case HAVE_NOTHING, HAVE_METADATA, HAVE_CURRENT_DATA:
					fireEvent(EventConstants.WAITING, false, false);
					
				case HAVE_FUTURE_DATA, HAVE_ENOUGH_DATA:
					doPlay();
					fireEvent(EventConstants.PLAYING, false, false);
			}
		}
		
		_autoplaying = false;
		
		//preload attribute might have prevented
		//media resource loading. The resource
		//must be selected and fetched before
		//playing begins
		if (_stalledByPreload == true)
		{
			selectResource();
		}
		
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
		if (networkState == NETWORK_EMPTY)
		{
			selectResource();
		}
		
		_autoplaying = false;
		
		if (paused == false)
		{
			paused = true;
			
			fireEvent(EventConstants.TIME_UPDATE, false, false);
			
			fireEvent(EventConstants.PAUSE, false, false);
			
			_officialPlaybackPosition = _currentPlaybackPosition;
		}
		
		nativeMedia.pause();
	}
	
	/**
	 * Returns the empty string (a negative response), 
	 * "maybe", or "probably" based on how confident
	 * the user agent is that it can play media resources of the given type.
	 */
	public function canPlayType(type:String):String
	{
		return nativeMedia.canPlayType(type);
	}
	
	/////////////////////////////////
	// PRIVATE METHODS
	////////////////////////////////
	
	/**
	 * Actually start the native media playback
	 */
	private function doPlay():Void
	{
		nativeMedia.play();
		onTimeUpdateTick(0);
	}
	
	/**
	 * Start the loading of a media element, this 
	 * is an implementation of the following alogithm :
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#media-element-load-algorithm
	 * 
	 * TODO 2 : implementation is incomplete
	 */
	private function loadResource():Void
	{
		switch (networkState)
		{
			case NETWORK_LOADING, NETWORK_IDLE:
				fireEvent(EventConstants.ABORT, false, false);
		}
		
		if (networkState != NETWORK_EMPTY)
		{
			fireEvent(EventConstants.EMPTIED, false, false);
			
			nativeMedia.src = null;
			
			networkState = NETWORK_EMPTY;
			
			
			readyState = HAVE_NOTHING;
			
			paused = true;
			
			seeking = false;
			
			_currentPlaybackPosition = 0;
			
			if (_officialPlaybackPosition > 0)
			{
				_officialPlaybackPosition = 0;
				fireEvent(EventConstants.TIME_UPDATE, false, false);
			}
			else
			{
				_officialPlaybackPosition = 0;
			}
			
			_initialPlaybackPosition = 0;
			
			duration = Math.NaN;
		}
		
		_loadedDataWasDispatched = false;
		
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
		networkState = NETWORK_NO_SOURCE;
		
		//most of the actual algorithm is implemented asynchronously,
		//to await a stable state of the document so delay till next update.
		//
		//TODO 4 : stable state of the document is a larger concept
		//which will need to be implemented eventually : 
		//http://www.w3.org/TR/2012/CR-html5-20121217/webappapis.html#await-a-stable-state
		_ownerHTMLDocument.timer.delay(doSelectResource);
	}
	
	/**
	 * The actual select resource algorithm
	 */ 
	private function doSelectResource(time:Float):Void
	{
		var mode:Int;
		var candidate:HTMLSourceElement;
		if (src != null)
		{
			mode = RESOURCE_SELECTION_ATTRIBUTE_MODE;
		}
		else if (hasChildSourceElement() == true)
		{
			mode = RESOURCE_SELECTION_CHILDREN_MODE;
			
			//retrieve the first source child
			var length:Int = childNodes.length;
			for (i in 0...length)
			{
				if (childNodes[i].nodeName == HTMLConstants.HTML_SOURCE_TAG_NAME)
				{
					candidate = cast(childNodes[i]);
					break;
				}
			}
		}
		else
		{
			networkState = NETWORK_EMPTY;
			return;
		}
		
		networkState = NETWORK_LOADING;
		
		fireEvent(EventConstants.LOAD_START, false, false);
		
		if (mode == RESOURCE_SELECTION_ATTRIBUTE_MODE)
		{
			if (src == "")
			{
				//TODO 1 : Set the error attribute to a new MediaError object whose code attribute is set to MEDIA_ERR_SRC_NOT_SUPPORTED.
				
				networkState = NETWORK_NO_SOURCE;
				
				fireEvent(EventConstants.ERROR, false, false);
				
				return;
			}
			
			//TODO 2 : Let absolute URL be the absolute URL that would have resulted 
			//from resolving the URL specified by the src attribute's value relative
			//to the media element when the src attribute was last changed.
			currentSrc = src;
			fetchResource(currentSrc);	
		}
		else if (mode == RESOURCE_SELECTION_CHILDREN_MODE)
		{
			//TODO 2 : short cut for now, not implemented like the spec
			for (i in 0...childNodes.length)
			{
				if (childNodes[i].nodeName == HTMLConstants.HTML_SOURCE_TAG_NAME)
				{
					var sourceChild:HTMLSourceElement = cast(childNodes[i]);
					if (sourceChild.type != null)
					{
						if (canPlayType(sourceChild.type) == CAN_PLAY_TYPE_PROBABLY)
						{
							currentSrc = sourceChild.src;
							fetchResource(currentSrc);
							return;
						}
					}
					else if (sourceChild.src != null)
					{
						if (canPlayType(sourceChild.src) == CAN_PLAY_TYPE_PROBABLY)
						{
							currentSrc = sourceChild.src;
							fetchResource(currentSrc);
							return;
						}
					}
				}
			}
			
			networkState = NETWORK_EMPTY;
		}
	}
	
	/**
	 * Actually fetch a resource.
	 * 
	 * This is an implementation of the following
	 * algorithm : 
	 * http://www.w3.org/TR/html5/media-elements.html#concept-media-load-resource
	 */
	private function fetchResource(url:String):Void
	{
		//the preload attribute might prevent resource loading, until
		//the play method is explicitely called y script
		if (preload == HTMLConstants.PRELOAD_NONE && _stalledByPreload == false)
		{
			//the autoplay attribute might override
			//the preload attribute
			if (autoplay == false)
			{
				networkState = NETWORK_IDLE;
				fireEvent(EventConstants.SUSPEND, false, false);
				_stalledByPreload = true;
				return;
			}
		}
		nativeMedia.onLoadedMetaData = onNativeMediaLoadedMetaData;
		
		//convert to absolut if needed before loading
		var absoluteUrl:String = _ownerHTMLDocument.getAbsoluteURL(url);
		
		nativeMedia.src = absoluteUrl;
	}
	
	/**
	 * Seeks to a given position of the media
	 * 
	 * This is an implementation of the following
	 * algorithm :
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#dom-media-seeking
	 * 
	 * @param	newPlaybackPosition the time to seek to, in seconds
	 */
	private function seek(newPlaybackPosition:Float):Void
	{
		if (readyState == HAVE_NOTHING)
		{
			return;
		}
		
		if (seeking == true)
		{
			//TODO 1 : If the element's seeking IDL attribute is true, 
			//then another instance of this algorithm is already running. 
			//Abort that other instance of the algorithm without waiting for
			//the step that it is running to complete.
		}
		
		seeking = true;
		
		if (newPlaybackPosition > duration)
		{
			newPlaybackPosition = duration;
		}
		
		if (newPlaybackPosition < _earliestPossiblePosition)
		{
			newPlaybackPosition = 0;
		}
		
		//TODO 2 : If the (possibly now changed) new playback position is 
		//not in one of the ranges given in the seekable attribute, then let 
		//it be the position in one of the ranges given in the seekable
		//attribute that is the nearest to the new playback position. If 
		//two positions both satisfy that constraint (i.e. the new playback
		//position is exactly in the middle between two ranges in the seekable
		//attribute) then use the position that is closest to the current 
		//playback position. If there are no ranges given in the seekable 
		//attribute then set the seeking IDL attribute to false and abort these steps.
		
		fireEvent(EventConstants.SEEKING, false, false);
		
	
		_currentPlaybackPosition = newPlaybackPosition;
		nativeMedia.seek(newPlaybackPosition);
		
		//TODO 2 : Wait until the user agent has established whether or not 
		//the media data for the new playback position is available, and, if
		//it is, until it has decoded enough data to play back that position.
		
		fireEvent(EventConstants.TIME_UPDATE, false, false);
		
		fireEvent(EventConstants.SEEKED, false, false);
	}
	
	/**
	 * When the ready state of the media element
	 * changes, fire the right events.
	 * 
	 * This is an implementation of the following algorithm:
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#dom-media-load
	 */
	private function setReadyState(newReadyState:Int):Void
	{
		if (readyState == HAVE_NOTHING && newReadyState == HAVE_METADATA)
		{
			fireEvent(EventConstants.LOADED_METADATA, false, false);
		}
		
		if (readyState == HAVE_METADATA && (newReadyState == HAVE_CURRENT_DATA || newReadyState == HAVE_ENOUGH_DATA 
		|| newReadyState == HAVE_FUTURE_DATA) || (readyState == HAVE_FUTURE_DATA && newReadyState == HAVE_ENOUGH_DATA))
		{
			if (_loadedDataWasDispatched == false && readyState == HAVE_METADATA)
			{
				fireEvent(EventConstants.LOADED_DATA, false, false);
				_loadedDataWasDispatched = true;
			}
			
			if (newReadyState == HAVE_ENOUGH_DATA || newReadyState == HAVE_FUTURE_DATA)
			{
				if ((readyState >= HAVE_FUTURE_DATA && newReadyState <= HAVE_CURRENT_DATA))
				{
					if (isPotentiallyPlaying() == true)
					{
						fireEvent(EventConstants.TIME_UPDATE, false, false);
						fireEvent(EventConstants.WAITING, false, false);
					}
				}
				
				if (readyState <= HAVE_CURRENT_DATA && newReadyState == HAVE_FUTURE_DATA)
				{
					fireEvent(EventConstants.CAN_PLAY, false, false);
					
					if (paused == false)
					{
						doPlay();
						fireEvent(EventConstants.PLAYING, false, false);
					}
				}
				
				if (newReadyState == HAVE_ENOUGH_DATA)
				{
					if (readyState == HAVE_CURRENT_DATA)
					{
						fireEvent(EventConstants.CAN_PLAY, false, false);
						
						if (paused == false)
						{
							doPlay();
							fireEvent(EventConstants.PLAYING, false, false);
						}
					}
					
					if (_autoplaying == true)
					{
						if (paused == true)
						{
							if (autoplay == true)
							{
								paused = false;
								fireEvent(EventConstants.PLAY, false, false);
								doPlay();
								
								fireEvent(EventConstants.PLAYING, false, false);
							}
						}
					}
					
					fireEvent(EventConstants.CAN_PLAY_THROUGH, false, false);
				}
			}
		}
		
		readyState = newReadyState;
	}
	
	/**
	 * A media element is said to be potentially playing when
	 * its paused attribute is false, the element has not ended
	 * playback, playback has not stopped due to errors,
	 * the element either has no current media controller
	 * or has a current media controller but is not blocked
	 * on its media controller, and the element is not
	 * a blocked media element.
	 * 
	 * TODO 2 : incomplete
	 * 
	 */
	private function isPotentiallyPlaying():Bool
	{
		if (paused == true)
		{
			return false;
		}
		
		if (ended == true)
		{
			return false;
		}
		
		return true;
	}
	
	/**
	 * called after the metadata of the media
	 * have been loaded
	 * 
	 * This is an implementation of the following
	 * algorithm :
	 * http://www.w3.org/TR/2012/WD-html5-20120329/media-elements.html#concept-media-load-algorithm
	 */
	private function establishMediaTimeline():Void
	{
		_currentPlaybackPosition = 0;
		_initialPlaybackPosition = 0;
		_officialPlaybackPosition = 0;
		
		duration = nativeMedia.duration;
		fireEvent(EventConstants.DURATION_CHANGE, false, false);
		
		setReadyState(HAVE_METADATA);
		
		var jumped = false;
		
		if (_defaultPlaybackStartPosition > 0)
		{
			seek(_defaultPlaybackStartPosition);
			jumped = true;
		}
		
		_defaultPlaybackStartPosition = 0;
		
		//TODO 2 : If either the media resource or the address of the
		//current media resource indicate a particular start time,
		//then set the initial playback position to that time and,
		//if jumped is still false, seek to that time and let jumped be true.	
	}
	
	/**
	 * Utils method determining if the media element
	 * has at least one source element child
	 */
	private function hasChildSourceElement():Bool
	{
		for (i in 0...childNodes.length)
		{
			if (childNodes[i].nodeName == HTMLConstants.HTML_SOURCE_TAG_NAME)
			{
				return true;
			}
		}
		
		return false;
	}
	
	/////////////////////////////////
	// RESOURCE CALLBACKS
	////////////////////////////////
	
	private function onLoadingError(error:Event):Void
	{
		selectResource();
	}
	
	/**
	 * When the metadata of the media have been 
	 * loaded, update the intrinsic dimensions
	 * of the html element and all the attributes
	 * which can retrieved through this metadata
	 */
	private function onNativeMediaLoadedMetaData(e:Event):Void
	{
		intrinsicHeight = nativeMedia.height;
		intrinsicWidth = nativeMedia.width;
		intrinsicRatio = intrinsicHeight / intrinsicWidth;
		
		//update playback times and duration
		establishMediaTimeline();
		
		//refresh the layout
		invalidate();
		
		//start listening to loading event, as it begins
		//as soon as the metadata are loaded
		onProgressTick(0);
		
		//if the media resource was stalled by
		//the value of the preload attribute,
		//the metadata were loaded as a result
		//of an explicit call to play() and playback
		//can now begin
		if (_stalledByPreload == true)
		{
			_stalledByPreload = false;
			play();
		}
	}
	
	/**
	 * Called at a regular frequency while
	 * the media is playing
	 */
	private function onTimeUpdateTick(timeStamp:Float):Void
	{
		//stop dispatching time updates if the
		//media is paused
		if (paused == true)
		{
			return;
		}
		
		//update playback position
		_currentPlaybackPosition = nativeMedia.currentTime;
		_officialPlaybackPosition = _currentPlaybackPosition;
		
		//check if the end of the media is reached
		if (duration - _currentPlaybackPosition < PLAYBACK_END_DELTA)
		{
			//if looping is enabled, seek to the start
			//of the media, then restart playback
			if (loop == true)
			{
				seek(0);
				doPlay();
				return;
			}
			ended = true;
			
			//set current time to the total duration to reflect
			//the fact that the video reached ending
			_currentPlaybackPosition = duration;
			_officialPlaybackPosition = _currentPlaybackPosition;
			
			//should fire a last time update event
			fireEvent(EventConstants.TIME_UPDATE, false, false);
			
			//pause the media on reaching the ends
			if (paused == false)
			{
				paused = true;
				fireEvent(EventConstants.PAUSE, false, false);
			}
			
			fireEvent(EventConstants.ENDED, false, false);
			return;
		}
		
		fireEvent(EventConstants.TIME_UPDATE, false, false);
		
		//if the media has not ended playing,
		//set this method to be called again 
		_ownerHTMLDocument.timer.delay(onTimeUpdateTick, TIME_UPDATE_FREQUENCY);
	}
	
	/**
	 * Called at a regular frequency whild the media is
	 * being loaded
	 */
	private function onProgressTick(timeStamp:Float):Void
	{
		//dispatch a load progress event
		//TODO 4 : should it be dispatched before suspend ?
		fireEvent(EventConstants.PROGRESS, false, false);
		
		//TODO 3 : passing from one ready state to 
		//another should be improved
		if (readyState == HAVE_METADATA)
		{
			setReadyState(HAVE_FUTURE_DATA);
		}
		
		//check if all of the media has been loaded
		if (nativeMedia.bytesLoaded >= nativeMedia.bytesTotal)
		{
			setReadyState(HAVE_ENOUGH_DATA);
			
			networkState = NETWORK_IDLE;
			fireEvent(EventConstants.SUSPEND, false, false);
			
			return;
		}
		
		//if not all of the media has been loaded, dispatch
		//a progress event and set this method to be called again
		_ownerHTMLDocument.timer.delay(onProgressTick, PROGRESS_FREQUENCY);
	}
	
	/////////////////////////////////
	// IDL GETTER/SETTER
	////////////////////////////////
	
	private function get_src():String 
	{
		return getAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME);
	}
	
	private function set_src(value:String):String 
	{
		super.setAttribute(HTMLConstants.HTML_SRC_ATTRIBUTE_NAME, value);
		selectResource();
		return value;
	}
	
	private function get_autoplay():Bool
	{
		if (getAttribute(HTMLConstants.HTML_AUTOPLAY_ATTRIBUTE_NAME) != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private function set_autoplay(value:Bool):Bool
	{
		super.setAttribute(HTMLConstants.HTML_AUTOPLAY_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	private function get_loop():Bool
	{
		if (getAttribute(HTMLConstants.HTML_LOOP_ATTRIBUTE_NAME) != null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	private function set_loop(value:Bool):Bool
	{
		super.setAttribute(HTMLConstants.HTML_LOOP_ATTRIBUTE_NAME, Std.string(value));
		return value;
	}
	
	private function get_preload():String
	{
		var preloadValue:String = super.getAttribute(HTMLConstants.HTML_PRELOAD_ATTRIBUTE_NAME);
		
		//if a value is not provided for preload, 
		//the default missing value is defined as metadata
		if (preloadValue == null)
		{
			return HTMLConstants.PRELOAD_METADATA;
		}
		return preloadValue;
	}
	
	private function set_preload(value:String):String
	{
		//preload is an enumerated value,
		//every illegal values are replaced
		switch(value)
		{
			//empty string is valid and maps to auto
			case "":
				value = HTMLConstants.PRELOAD_AUTO;
				
			//valid values	
			case HTMLConstants.PRELOAD_AUTO, HTMLConstants.PRELOAD_METADATA,
			HTMLConstants.PRELOAD_NONE:
				
			//default missing value is metadata	
			default:
				value = HTMLConstants.PRELOAD_METADATA;
		}
		
		super.setAttribute(HTMLConstants.HTML_PRELOAD_ATTRIBUTE_NAME, value);
		return value;
	}
	
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	private function set_muted(value:Bool):Bool
	{
		muted = value;

        //end here if native media not initialised yet
        if (nativeMedia == null)
        {
            return value;
        }

		//update the volume of the native media
		//if sound is no longer muted
		if (value == false)
		{
			nativeMedia.volume = volume;
		}
		//muting consist on setting volume of native
		//media to 0
		else
		{
			nativeMedia.volume = 0;
		}
		
		fireEvent(EventConstants.VOLUME_CHANGE, false, false);
		
		return value;
	}
	
	private function set_volume(value:Float):Float
	{
		volume = value;

        //end here if native media not initialised yet
        if (nativeMedia == null)
        {
            return value;
        }

		if (muted == false)
		{
			nativeMedia.volume = value;
		}
		
		fireEvent(EventConstants.VOLUME_CHANGE, false, false);
		
		return value;
	}
	
	private function get_buffered():TimeRanges
	{
		var ranges:Array<Range> = new Array<Range>();
		
		//return one range which is the number of seconds
		//already loaded of the media
		ranges.push( {
			start : 0.0,
			end: duration * (nativeMedia.bytesLoaded / nativeMedia.bytesTotal)
		});
		
		var timeRanges:TimeRanges = new TimeRanges(ranges);
		return timeRanges;
	}
	
	private function get_currentTime():Float 
	{
		//if default playback position is different from 0,
		//it means that the media has not loaded yet, as it takes
		//the default playback start position and reset it as soon
		//as it is loaded
		if (_defaultPlaybackStartPosition != 0)
		{
			return _defaultPlaybackStartPosition;
		}
		
		return _officialPlaybackPosition;
	}
	
	private function set_currentTime(value:Float):Float 
	{
		switch(readyState)
		{
			//if current time is set before the media loading,
			//store in the default playback position which will
			//be applied as soon as the media is loaded
			case HAVE_NOTHING:
				_defaultPlaybackStartPosition = value;
				
			default:
				_officialPlaybackPosition = value;
				seek(value);
		}
		
		return value;
	}
}
