/*
 * Cocktail, HTML rendering engine
 * http://haxe.org/com/libs/cocktail
 *
 * Copyright (c) Silex Labs
 * Cocktail is available under the MIT license
 * http://www.silexlabs.org/labs/cocktail-licensing/
*/
package cocktail.core.html;
import cocktail.event.Event;
import cocktail.event.EventConstants;
import cocktail.event.UIEvent;
import cocktail.core.renderer.VideoRenderer;
import cocktail.port.Bindings;
import cocktail.core.parser.ParserData;

/**
 * A video element is used for playing videos or movies.
 * 
 * @author Yannick DOMINGUEZ
 */
class HTMLVideoElement extends HTMLMediaElement
{	
	/**
	 * The default width of the video tag, if the video is not yet loaded 
	 */
	private static inline var HTML_VIDEO_DEFAULT_WIDTH:Int = 300;
	
	/**
	 * The default height of the video tag, if the video is not yet loaded 
	 */
	private static inline var HTML_VIDEO_DEFAULT_HEIGHT:Int = 150;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * The poster attribute gives the address of an image file that the user
	 * agent can show while no video data is available.
	 */
	public var poster(get_poster, set_poster):String;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// attributes
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Used to load the poster frame of the video
	 * if a poster url is provided.
	 * 
	 * Use an HTMLImageElement to prevent duplicating
	 * resource loading code from HTMLImageElement
	 */
	private var _posterImage:HTMLImageElement;
	
	/**
	 * Callback called when the poster image was successfuly loaded
	 */
	private var _onPosterLoadComplete:Event->Void;
	
	/**
	 * Called when there was an error while loading the poster
	 */
	private var _onPosterLoadError:Event->Void;
	
	/**
	 * Returns the intrinsic width of the video in CSS pixels
	 */
	public var videoWidth(get_videoWidth, never):Int;
	
	/**
	 * Returns the intrinsic height of the video in CSS pixels
	 */
	public var videoHeight(get_videoHeight, never):Int;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// CONSTRUCTOR & INIT
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * class constructor
	 */
	public function new() 
	{
		super(HTMLConstants.HTML_VIDEO_TAG_NAME);
		initPosterFrame();
	}
	
	/**
	 * Instantiate a video media manager
	 */
	override private function initNativeMedia():Void
	{
		nativeMedia = new NativeVideo();
	}
	
	/*
	 * Init the image HTMLElement for the poster image
	 */ 
	private function initPosterFrame():Void
	{
		_posterImage = new HTMLImageElement();
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN ATTRIBUTE METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	override public function setAttribute(name:String, value:String):Void
	{
		if (name == HTMLConstants.HTML_POSTER_ATTRIBUTE_NAME)
		{
			poster = value;
		}
		else
		{
			super.setAttribute(name, value);
		}
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// OVERRIDEN PRIVATE RENDERING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Instantiate a video renderer
	 */
	override private function createElementRenderer():Void
	{
		elementRenderer = new VideoRenderer(this, coreStyle);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PUBLIC HELPER METHOD
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Wheter the rendered frame for the video should
	 * be its poster or the current video frame
	 * @return true if the poster frame should be rendered
	 * instead of the video
	 */
	public function shouldRenderPosterFrame():Bool
	{
		//no poster frame is provided
		if (poster == "")
		{
			return false;
		}
		
		switch (readyState)
		{
			//if no video data is yet loaded, render the poster frame
			case HTMLMediaElement.HAVE_NOTHING, HTMLMediaElement.HAVE_METADATA:
				return true;
		}
		
		//if the video is not playing and the current playback position
		//is the beggining of the video, then the poster frame should be
		//rendered instead of the video's first frame
		if (paused == true && _currentPlaybackPosition == 0.0)
		{
			return true;
		}
		
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// PRIVATE POSTER LOADING METHODS
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Called when the poster image was successfuly loaded.
	 * Invalidate the rendering of the video element
	 */
	private function onPosterLoadComplete(e:Event):Void
	{
		removeListeners();
		invalidate();
	}
	
	/**
	 * Called when there was an error while loading
	 * the poster image
	 */
	private function onPosterLoadError(e:Event):Void
	{
		removeListeners();
	}
	
	/**
	 * Remove the poster image listeners
	 */
	private function removeListeners():Void
	{
		_posterImage.removeEventListener(EventConstants.LOAD, _onPosterLoadComplete);
		_posterImage.removeEventListener(EventConstants.ERROR, _onPosterLoadError);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////
	// IDL GETTER/SETTER
	//////////////////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Starts the loading of the poster frame of the video
	 */
	private function set_poster(value:String):String
	{
		super.setAttribute(HTMLConstants.HTML_POSTER_ATTRIBUTE_NAME, value);
		
		_onPosterLoadComplete = onPosterLoadComplete;
		_onPosterLoadError = onPosterLoadError;
		_posterImage.addEventListener(EventConstants.LOAD, _onPosterLoadComplete);
		_posterImage.addEventListener(EventConstants.ERROR, _onPosterLoadError);
		_posterImage.src = value;
		return value;
	}
	
	private function get_poster():String
	{
		return getAttributeAsDOMString(HTMLConstants.HTML_POSTER_ATTRIBUTE_NAME);
	}
	
	/////////////////////////////////
	// GETTER/SETTER
	////////////////////////////////
	
	/**
	 * Return the intrinsic width of the video
	 * if available, else return CSS default for
	 * video
	 */
	private function get_videoWidth():Int
	{
		if (nativeMedia.width != null)
		{
			return Math.round(nativeMedia.width);
		}
		else
		{
			return HTML_VIDEO_DEFAULT_WIDTH;
		}
	}
	
	/**
	 * Same as for width
	 */
	private function get_videoHeight():Int
	{
		if (nativeMedia.height != null)
		{
			return Math.round(nativeMedia.height);
		}
		else
		{
			return HTML_VIDEO_DEFAULT_HEIGHT;
		}
	}
}
