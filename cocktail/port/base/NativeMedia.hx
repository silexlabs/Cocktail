/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.port.base;

import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.geom.Matrix;
import cocktail.core.graphics.GraphicsContext;
import cocktail.geom.GeomData;

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
	public var volume(null, set_volume):Float;
	
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
	public var onLoadedMetaData:Event->Void;
	
	/**
	 * The viewport represents the position and size of the
	 * displayed native video relative to the window
	 */
	@:isVar public var viewport(get_viewport, set_viewport):RectangleVO;
	
	/**
	 * Represents the 3x3 transformation matrix to 
	 * apply to the displayed native video 
	 */
	@:isVar public var matrix(get_matrix, set_matrix):Matrix;
	
	/**
	 * Represents the alpha, from 0(transparent) to 1.0
	 * (opaque) to apply to the displayed video
	 */
	@:isVar public var alpha(get_alpha, set_alpha):Float;
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		alpha = 1.0;
		matrix = new Matrix();
		viewport = new RectangleVO();
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
	
	/**
	 * Attach the native video using native APIs so
	 * that it is displayed at the dimension and position
	 * defined by its viewport
	 */
	public function attach(graphicsContext:GraphicsContext):Void
	{
		//abstract
	}
	
	/**
	 * Detach the native video using native APIs so
	 * that it is no longer displayed, however it continues
	 * to play if it is currently playing
	 */
	public function detach(graphicsContext:GraphicsContext):Void
	{
		
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
		if (onLoadedMetaData != null)
		{
			var loaddedMetadataEvent:Event = new Event();
			loaddedMetadataEvent.initEvent(EventConstants.LOADED_METADATA, false, false);
			onLoadedMetaData(loaddedMetadataEvent);
		}
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
	
	private function get_viewport():RectangleVO
	{
		return viewport;
	}
	
	private function set_viewport(value:RectangleVO):RectangleVO
	{
		return viewport = value;
	}
	
	private function get_matrix():Matrix
	{
		return matrix;
	}
	
	private function set_matrix(value:Matrix):Matrix
	{
		return matrix = value;
	}
	
	private function get_alpha():Float
	{
		return alpha;
	}
	
	private function set_alpha(value:Float):Float
	{
		return alpha = value;
	}
}
