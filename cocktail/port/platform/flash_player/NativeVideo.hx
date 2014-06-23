/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;

import cocktail.core.config.Config;
import cocktail.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.core.html.HTMLMediaElement;
import cocktail.port.base.NativeMedia;
import flash.display.DisplayObjectContainer;
import flash.events.AsyncErrorEvent;
import flash.events.Event;
import flash.events.StageVideoAvailabilityEvent;
import flash.geom.Rectangle;
import flash.Lib;
import flash.media.SoundTransform;
import flash.media.StageVideo;
import flash.media.StageVideoAvailability;
import flash.media.Video;
import flash.net.NetConnection;
import flash.net.NetStream;
import flash.events.NetStatusEvent;
import cocktail.geom.GeomData;

/**
 * This is the flash as3 port of the native video,
 * allowing displaying an flv or mp4 video using
 * flash native video capabilities.
 * 
 * It can either use flash "new" (flash player 10.2) StageVideo API 
 * for GPU accelerated video rendering if available, or the classic
 * software rendered video
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
	
	private static inline var NET_STREAM_SEEK_NOTIFY:String = "NetStream.Seek.Notify";
	
	/**
	 * a reference to the native software flash video
	 * player
	 */
	private var _video:Video;
	
	/**
	 * a reference to the native hardware flash
	 * video player. It might not always be
	 * available based on the hardaware and how
	 * the flash movie is embedded
	 */
	private var _stageVideo:StageVideo;
	
	/**
	 * keep track of wether a StageVideo object
	 * is currently available to be used, might
	 * change during playback
	 */
	private var _stageVideoAvailable:Bool;
	
	/**
	 * Keep track of wether hardware rendering is currently
	 * used for the video. This might change during
	 * playback of the video, for instance switching
	 * to fullscreen mode might make the video switch
	 * from sotware to hardware.
	 * 
	 * If false, can either mean that hardware video is 
	 * not available or that no video is currently displayed
	 */
	private var _usesStageVideo:Bool;
	
	/**
	 * Same as above for software video.
	 * If true, means that video is currently displayed
	 * with software rendering, if false, video might either
	 * be not displayed or displayed with hardware rendering
	 */
	private var _usesSoftwareVideo:Bool;
	
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
	 * When seek method is called, store the seek time.
	 * This fix is here to circumvent a bug in NetStream
	 * where the time attribute is not immediately updated
	 * when seeking
	 */
	private var _currentTime:Float;
	
	/**
	 * Wether a seek is currently in progress, seeking NetStrem
	 * is an asynchronous process, and a NetStatusEvent is dispatched
	 * when seeking is complete
	 */
	private var _seeking:Bool;
	
	/**
	 * Store wether the video or stage video is currently
	 * supposed to be attached to the stage
	 */
	private var _isAttachedToStage:Bool;
	
	/**
	 * class constructor. Init video
	 */
	public function new() 
	{
		super();
		
		_stageVideoAvailable = false;
		_usesSoftwareVideo = false;
		_usesStageVideo = false;
		_isAttachedToStage = false;
		
		initVideo();
		_currentTime = 0.0;
		_seeking = false;
		initNetConnection();
		_nc.addEventListener(NetStatusEvent.NET_STATUS, onNetStatus);
		_nc.connect(null); 
		viewport = new RectangleVO();
	}
	
	/**
	 * Init the flash NetConnection object
	 */
	private function initNetConnection():Void
	{
		_nc = new NetConnection();
	}
	
	/**
	 * Init the flash NetStream object
	 */
	private function initNetStream():Void
	{
		_netStream = new NetStream(_nc);
	}
	
	/**
	 * Init software and hardware video object.
	 * 
	 * Software is always instantiated, as even if
	 * hardware is available, during playback video
	 * might fallback to software if hardware loses
	 * os focus
	 */
	private function initVideo():Void
	{
		_video = new Video();
		_video.smoothing = true;
		
		//hardware video not instantiated but made available asynchronously on stage object
		Lib.current.stage.addEventListener(StageVideoAvailabilityEvent.STAGE_VIDEO_AVAILABILITY, onStageVideoState);
	}
	
	/**
	 * Called each time StageVideo determined to be available 
	 * or not
	 */
	private function onStageVideoState(event:StageVideoAvailabilityEvent):Void
	{
		//store wether available or not
		_stageVideoAvailable = event.availability == StageVideoAvailability.AVAILABLE;
		toggleStageVideo();
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
		//seeking is asynchronous, prevent from
		//calling seek method too much, seek
		//method is very expensive
		if (_seeking == false)
		{
			//store seek time so that it can be immediatley
			//return if current time is requested
			_seeking = true;
			_currentTime = time;
			_netStream.seek(time);
		}
		
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
	
	/**
	 * Attach the flash video object to the flash display list
	 */
	override public function attach(graphicContext:GraphicsContext):Void
	{
		//prevent too much attach
		if (_isAttachedToStage == true)
		{
			return;
		}
		
		_isAttachedToStage = true;
		
		var containerGraphicContext:DisplayObjectContainer = cast(graphicContext.nativeLayer.platformLayer);
		
		//video might be added below cocktail's bitmap when compositing is disabled
		if (Config.getInstance().enableCompositing == false && Config.getInstance().videoBelowWhenNoCompositing == true)
		{
			//TODO 3 : messy to reference parent, should cocktail instead provide right surface
			//in this method ?
			containerGraphicContext.parent.addChildAt(_video, 0);
		}
		else
		{
			containerGraphicContext.addChild(_video);
		}
		
		//for stage video attaching/detaching is done with the NetStream
		//as it is not a DisplayObject
		if (_stageVideo != null && _usesStageVideo == true)
		{
			_stageVideo.attachNetStream(_netStream);
		}
	}
	
	override public function detach(graphicsContext:GraphicsContext):Void
	{
		//prevent too much detach
		if (_isAttachedToStage == false)
		{
			return;
		}
		
		_isAttachedToStage = false;
		
		//detach software video
		_video.parent.removeChild(_video);
		
		//detach hardware video
		if (_stageVideo != null && _usesStageVideo == true)
		{
			_stageVideo.attachNetStream(null);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called each time StageVideo is determined to be available
	 * or unavailable, and might toggle between software and hardware 
	 * rendering
	 */
	private function toggleStageVideo():Void
	{
		//here, can use hardware rendering
		if (canUseStageVideo() == true)
		{
			_usesStageVideo = true;
			
			//get a ref to the first available stage video
			//if not referenced yet
			if (_stageVideo == null)
			{
				_stageVideo = Lib.current.stage.stageVideos[0];
				_stageVideo.viewPort = new Rectangle(viewport.x, viewport.y, viewport.width, viewport.height);
			}
			
			//attach netstream to it, automatically detaching it
			//from software video if needed
			_stageVideo.attachNetStream(_netStream);
			
			//hide software video if currently used, as
			//stage video always behind
			if (_usesSoftwareVideo == true)
			{
				_video.visible = false;
				_usesSoftwareVideo = false;
			}
		}
		//here uses software rendering
		else
		{
			//reset stage video reference, make softwre
			//visible
			if (_usesStageVideo == true)
			{
				_stageVideo = null;
				_usesStageVideo = false;
				_video.visible = true;
			}
			
			_usesSoftwareVideo = true;
			
			//attach netstream to software video, detaching
			//it from stage video if needed
			_video.attachNetStream(_netStream);
		}
	}
	
	/**
	 * Wether, under the current condition 
	 * StageVideo can be used instead of 
	 * software rendering
	 */
	private function canUseStageVideo():Bool
	{
		//can be disabled via config
		if (Config.getInstance().useStageVideoIfAvailable == false)
		{
			return false;
		}
		//not available because of hardware
		else if (_stageVideoAvailable == false)
		{
			return false;
		}
		//no alpha compositing allowed for StageVideo
		else if (alpha != 1.0)
		{
			return false;
		}
		//no transformations allowed for StageVideo
		else if (matrix.isIdentity() == false)
		{
			return false;
		}
		
		return true;
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
				
			case NET_STREAM_SEEK_NOTIFY:
				checkSeeking();
		}
	}
	
	/**
	 * This method is a hack to circumvent a notorious 
	 * flash NetStream bug : the NetStream.Seek.Notify
	 * event is dispatched before the NetStream time is
	 * actually set to the new seek time.
	 * 
	 * This method check that before the seeking flag
	 * is set to false, the current time on the NetStream
	 * was actually changed to the seek value
	 */
	private function checkSeeking():Void
	{
		if (_netStream.time - _currentTime > 0.2)
		{
			haxe.Timer.delay(checkSeeking, 5);
		}
		else
		{
			_seeking = false;
		}
	}
	
	/**
	 * init the net stream 
	 */
	private function connectStream():Void
	{
		initNetStream();
		
		_netStream.client = {
			onMetaData:onNetStreamMetaData
		}
		
		_netStream.addEventListener(NetStatusEvent.NET_STATUS, onNetStatus);
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
		//if a seek is currently in progress, returns
		//the seek time
		if (_seeking == true)
		{
			return _currentTime;
		}
		
		return _netStream.time;
	}
	
	override private function get_height():Null<Int>
	{
		//return null if metadata not yet loaded
		if (_metaData == null)
		{
			return null;
		}
		
		if (_usesStageVideo == true)
		{
			return _stageVideo.videoHeight;
		}
		else
		{
			return _video.videoHeight;
		}
	}
	
	override private function get_width():Null<Int>
	{
		if (_metaData == null)
		{
			return null;
		}
		
		if (_usesStageVideo == true)
		{
			return _stageVideo.videoWidth;
		}
		else
		{
			return _video.videoWidth;
		}
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
		
		//refresh video display if currently attached,
		//now that a src is set
		if (_isAttachedToStage == true)
		{
			toggleStageVideo();
		}
		return value;
	}
	
	/**
	 * Set the position of the native flash video object
	 * to match those of its viewport
	 */
	override private function set_viewport(value:RectangleVO):RectangleVO
	{
		//refresh hardware if necessary and software video
		if (_stageVideo != null)
		{
			_stageVideo.viewPort = new Rectangle(value.x, value.y, value.width, value.height);
		}
		
		if (_video != null)
		{
			_video.x = value.x;
			_video.y = value.y;
			_video.width = value.width;
			_video.height = value.height;
		}
		
		
		viewport = value;
		return value;
	}
	
	/**
	 * when transformation changes, check wether
	 * video rendering should switch to software, as 
	 * StageVideo doesn't support transformations
	 * 
	 * TODO 3 : apply transformations to software video
	 */
	override private function set_matrix(value:Matrix):Matrix
	{
		matrix = value;
		
		//check if new value enable/disable StageVideo
		if (_usesStageVideo != canUseStageVideo())
		{
			toggleStageVideo();
		}
		
		return matrix;
	}
	
	/**
	 * When alpha changes, apply to software video
	 * and check if video rendering should switch to
	 * software, as StageVideo doesn't support alpha
	 */
	override private function set_alpha(value:Float):Float
	{
		alpha = value;
		
		if (_video != null)
		{
			_video.alpha = value;
		}
		
		if (_usesStageVideo != canUseStageVideo())
		{
			toggleStageVideo();
		}
		
		return alpha;
	}
}
