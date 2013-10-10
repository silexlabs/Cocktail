/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.platform.flash_player;
import cocktail.core.html.HTMLMediaElement;
import cocktail.core.floats.FloatsManager;
import cocktail.port.base.NativeMedia;
import flash.events.Event;
import flash.events.IOErrorEvent;
import flash.media.ID3Info;
import flash.media.Sound;
import flash.media.SoundChannel;
import flash.media.SoundTransform;
import flash.net.URLRequest;



/**
 * This is the flash as3 port of the native audio,
 * allowing playback of mp3 files
 * 
 * @author Yannick DOMINGUEZ
 */
class NativeAudio extends NativeMedia
{
	//supported flash audio types

	private static inline var MP3_EXTENSION:String = "mp3";

	/**
	 * The native flash sound object
	 */
	private var _sound:Sound;
	
	/**
	 * the sound channel used to play
	 * the sound
	 */
	private var _soundChannel:SoundChannel;
	
	/**
	 * Store the current playing time
	 * of the sound to now where to 
	 * re-start it after a pause
	 */
	private var _currentTime:Float;
	
	/**
	 * Flasg tracking wether the sound is currently
	 * playing
	 */
	private var _isPlaying:Bool;
	
	
	/**
	 * class constructor. Init sound
	 */
	public function new() 
	{
		super();
		_currentTime = 0.0;
		_isPlaying = false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PUBLIC METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * play/resume the sound
	 */
	override public function play():Void
	{
		_isPlaying = true;
		
		//playing/resuming is the same as
		//seeking to current time
		//seek method expect time in seconds
		seek(_currentTime / 1000);
	}
	
	/**
	 * call the native pause method
	 * on the NetStream object
	 */
	override public function pause():Void
	{
		_isPlaying = false;
		
		//thr sound channel might be null if pause
		//is called before the sound was played
		if (_soundChannel != null)
		{
			//store the current time to allow for resuming
			//playback
			_currentTime = _soundChannel.position;
			_soundChannel.stop();
		}
	}
	
	/**
	 * Seek to a given position in the sound.
	 * In flash there is no seek method for the
	 * sound, only play with position arguments
	 * 
	 * @param time seek time in seconds
	 */
	override public function seek(time:Float):Void 
	{
		//if the sound is currently playing, stop
		//it, else 2 sounds will be played at the
		//same time
		if (_soundChannel != null)
		{
			_soundChannel.stop();
		}
		
		//only play the sound if te sound is supposed
		//to be currently playing as there is no
		//way to seek to a position without playing
		if (_isPlaying == true)
		{
			//playing the flash sound returns
			//a sound channel object used to control
			//the sound
			//flash sound object expects time in milliseconds
			_soundChannel = _sound.play(time * 1000, 0, new SoundTransform(volume, 0));
		}
		//else store the seek position where the sound
		//will start playing, the next time the play
		//method is called
		else
		{
			_currentTime = time;
		}
	}
	
	/**
	 * Determine wether the given type can be played
	 * by the flash player
	 */
	override public function canPlayType(type:String):String
	{
		if (type.indexOf(MP3_EXTENSION) != -1)
		{
			return HTMLMediaElement.CAN_PLAY_TYPE_PROBABLY;
		}
		
		//not a supported audio format
		return HTMLMediaElement.CAN_PLAY_TYPE_MAYBE;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the id3 data of the sound are loaded,
	 * dispatch the metadata event
	 */
	private function onID3DataReceived(event:Event):Void
	{
		onNativeLoadedMetaData();
		_sound.removeEventListener(Event.ID3, onID3DataReceived);
		_sound.removeEventListener(Event.COMPLETE, onID3DataReceived);
	}
	
	/**
	 * Called when the source of the sound
	 * changes, the Sound object need to 
	 * be created or re-created
	 */
	private function initSound(src:String):Void
	{
		//if built with openfl the soune might
		//have been embedded at compile time
		#if openfl
		var asset:Sound = openfl.Assets.getSound(src);
		
		//here the sound file was embedded, use it
		if (asset != null)
		{
			_sound = asset;
			onNativeLoadedMetaData();
			return;
		}
		#end
		
		//in flash, Sound object can't be reused
		//for multiple sounds
		_sound = new Sound();
		
		//listen for metadata loading of sound 
		_sound.addEventListener(Event.ID3, onID3DataReceived);
		//the complete loading of the sound is also listened to as some
		//sound file might be encoded without ID3 tags
		_sound.addEventListener(Event.COMPLETE, onID3DataReceived);
		//listen for url loading error
		_sound.addEventListener(IOErrorEvent.IO_ERROR, onIOError);
		
		_sound.load(new URLRequest(src));
	}
	
	/**
	 * Called when there was an error while
	 * loading the sound
	 */
	private function onIOError(e:IOErrorEvent):Void
	{
		//TODO : implement fallback
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN SETTER/GETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override private function set_volume(value:Float):Float
	{
		volume = value;
		
		//shouldChannel is null if volume is set
		//before the sound is played.
		//
		//if the sound is playing, the volume is updated
		//instantly
		if (_soundChannel != null)
		{
			_soundChannel.soundTransform = new SoundTransform(value, 0);
		}
		
		return value;
	}
	
	override private function get_bytesTotal():Float
	{
		return _sound.bytesTotal;
	}
	
	override private function get_bytesLoaded():Float
	{
		return _sound.bytesLoaded;
	}
	
	/**
	 * Converted to seconds instead of 
	 * milliseconds
	 */
	override private function get_duration():Float
	{
		return _sound.length / 1000;
	}
	
	/**
	 * Converted to seconds instead of 
	 * milliseconds
	 */
	override private function get_currentTime():Float
	{
		return _soundChannel.position / 1000;
	}
	
	/**
	 * start the loading of the sound
	 */
	override private function set_src(value:String):String
	{
		//reset playbak time
		_currentTime = 0.0;
		initSound(value);
		return value;
	}
}
